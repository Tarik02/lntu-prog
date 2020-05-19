#!/usr/bin/env python3

from pathlib import Path
from itertools import chain
from os import getenv
import re
import uuid
import codecs
import asyncio
from asyncio import subprocess


TARGET = getenv('TARGET')

cwd = Path('.').resolve()
extensions_c = [
	'.c',
]
extensions_cpp = [
	'.cpp',
]
extensions = [
	*extensions_c,
	*extensions_cpp,
]

files = sorted([*chain(*[
	[*cwd.rglob('*' + ext)]
		for ext in extensions
])])

files = [
	source
		for source in files
		if not str(source.relative_to(cwd)).startswith('.')
]

encoding = 'cp1251' if TARGET == 'win' else 'utf8'

for file in files:
	directory = cwd / ('.' + TARGET) / file.parent.relative_to(cwd)
	name = file.stem
	suffix = file.suffix

	out_file = directory / f'{name}{suffix}'
	pr_file = directory /  f'pr_{name}.cbproj'
	out_file.parent.mkdir(parents=True, exist_ok=True)

	had_include = False
	is_main = False
	skip = False

	with file.open('r') as inf, out_file.open('wb') as outf:
		for line in inf.readlines():
			if line[:3] == codecs.BOM_UTF8:
				line = line[3:]

			if line == '#include <graphics.h>\n':
				skip = True

			if TARGET == 'win':
				if not had_include and line.startswith('#include'):
					outf.write('#include <windows.h>\n'.encode(encoding))
					had_include = True

				if is_main and 'return' in line:
					tabs = re.match(r'^([\t ]*)return.*$', line).group(1)
					outf.write((tabs + 'system("pause");\n').encode(encoding))

				try:
					outf.write(line.encode(encoding, 'ignore'))
				except Exception as e:
					print(file)
					print(line)
					print(e)

				if not is_main and line.startswith('int main'):
					outf.write('\tSetConsoleCP(1251);\n'.encode(encoding))
					outf.write('\tSetConsoleOutputCP(1251);\n'.encode(encoding))
					outf.write('\n'.encode(encoding))
					is_main = True

				if is_main and line.startswith('}'):
					is_main = False
			else:
				try:
					outf.write(line.encode(encoding, 'ignore'))
				except Exception as e:
					print(file)
					print(line)
					print(e)

	if skip:
		(directory / '.skip').touch()
		continue

	if TARGET == 'win':
		with pr_file.open('wb') as outf:
			outf.write(
	('\t' + f'''
		<Project xmlns="http://schemas.microsoft.com/developer/msbuild/2003">
			<PropertyGroup>
				<ProjectGuid>{{{uuid.uuid4()}}}</ProjectGuid>
				<ProjectVersion>12.0</ProjectVersion>
				<Config Condition="'$(Config)'==''">Debug</Config>
			</PropertyGroup>
			<PropertyGroup Condition="'$(Config)'=='Base' or '$(Base)'!=''">
				<Base>true</Base>
			</PropertyGroup>
			<PropertyGroup Condition="'$(Config)'=='Debug' or '$(Cfg_1)'!=''">
				<Cfg_1>true</Cfg_1>
				<CfgParent>Base</CfgParent>
				<Base>true</Base>
			</PropertyGroup>
			<PropertyGroup Condition="'$(Config)'=='Release' or '$(Cfg_2)'!=''">
				<Cfg_2>true</Cfg_2>
				<CfgParent>Base</CfgParent>
				<Base>true</Base>
			</PropertyGroup>
			<PropertyGroup Condition="'$(Base)'!=''">
				<NoVCL>true</NoVCL>
				<PackageImports>vcl.bpi;rtl.bpi;bcbie.bpi;vclx.bpi;vclactnband.bpi;xmlrtl.bpi;bcbsmp.bpi;dbrtl.bpi;vcldb.bpi;vcldbx.bpi;bdertl.bpi;dsnap.bpi;dsnapcon.bpi;TeeUI.bpi;TeeDB.bpi;Tee.bpi;adortl.bpi;IndyCore.bpi;IndySystem.bpi;IndyProtocols.bpi;vclribbon.bpi;dbexpress.bpi;DbxCommonDriver.bpi;DataSnapIndy10ServerTransport.bpi;DataSnapProviderClient.bpi;DataSnapServer.bpi;DbxClientDriver.bpi;DBXInterBaseDriver.bpi;DBXMySQLDriver.bpi;dbxcds.bpi;DBXSybaseASEDriver.bpi;DBXSybaseASADriver.bpi;DBXOracleDriver.bpi;DBXMSSQLDriver.bpi;DBXInformixDriver.bpi;DBXDb2Driver.bpi</PackageImports>
				<ProjectType>CppConsoleApplication</ProjectType>
				<DCC_CBuilderOutput>JPHNE</DCC_CBuilderOutput>
				<Defines>NO_STRICT;$(Defines)</Defines>
				<DynamicRTL>true</DynamicRTL>
				<IncludePath>..\\{name};$(CG_BOOST_ROOT)\\boost\\tr1\\tr1;$(BDS)\\include;$(BDS)\\include\\dinkumware;$(BDS)\\include\\vcl;$(CG_BOOST_ROOT);$(IncludePath)</IncludePath>
				<ILINK_LibraryPath>..\\{name};$(BDS)\\lib;$(BDS)\\lib\\obj;$(BDS)\\lib\\psdk;$(ILINK_LibraryPath)</ILINK_LibraryPath>
				<BCC_wpar>false</BCC_wpar>
				<BCC_OptimizeForSpeed>true</BCC_OptimizeForSpeed>
			</PropertyGroup>
			<PropertyGroup Condition="'$(Cfg_1)'!=''">
				<BCC_OptimizeForSpeed>false</BCC_OptimizeForSpeed>
				<BCC_DisableOptimizations>true</BCC_DisableOptimizations>
				<DCC_Optimize>false</DCC_Optimize>
				<DCC_DebugInfoInExe>true</DCC_DebugInfoInExe>
				<Defines>_DEBUG;$(Defines)</Defines>
				<BCC_InlineFunctionExpansion>false</BCC_InlineFunctionExpansion>
				<IntermediateOutputDir>Debug</IntermediateOutputDir>
				<ILINK_DisableIncrementalLinking>true</ILINK_DisableIncrementalLinking>
				<BCC_UseRegisterVariables>None</BCC_UseRegisterVariables>
				<DCC_Define>DEBUG</DCC_Define>
				<BCC_DebugLineNumbers>true</BCC_DebugLineNumbers>
				<TASM_DisplaySourceLines>true</TASM_DisplaySourceLines>
				<BCC_StackFrames>true</BCC_StackFrames>
				<ILINK_LibraryPath>$(BDS)\\lib\\debug;$(ILINK_LibraryPath)</ILINK_LibraryPath>
				<ILINK_FullDebugInfo>true</ILINK_FullDebugInfo>
				<TASM_Debugging>Full</TASM_Debugging>
				<BCC_SourceDebuggingOn>true</BCC_SourceDebuggingOn>
			</PropertyGroup>
			<PropertyGroup Condition="'$(Cfg_2)'!=''">
				<Defines>NDEBUG;$(Defines)</Defines>
				<IntermediateOutputDir>Release</IntermediateOutputDir>
				<ILINK_LibraryPath>$(BDS)\\lib\\release;$(ILINK_LibraryPath)</ILINK_LibraryPath>
				<TASM_Debugging>None</TASM_Debugging>
			</PropertyGroup>
			<ItemGroup>
				<CppCompile Include="{name}{suffix}">
					<BuildOrder>0</BuildOrder>
				</CppCompile>
				<BuildConfiguration Include="Base">
					<Key>Base</Key>
				</BuildConfiguration>
				<BuildConfiguration Include="Release">
					<Key>Cfg_2</Key>
					<CfgParent>Base</CfgParent>
				</BuildConfiguration>
				<BuildConfiguration Include="Debug">
					<Key>Cfg_1</Key>
					<CfgParent>Base</CfgParent>
				</BuildConfiguration>
			</ItemGroup>
			<Import Project="$(BDS)\\Bin\\CodeGear.Cpp.Targets" Condition="Exists('$(BDS)\\Bin\\CodeGear.Cpp.Targets')"/>
			<ProjectExtensions>
				<Borland.Personality>CPlusPlusBuilder.Personality.12</Borland.Personality>
				<Borland.ProjectType>CppConsoleApplication</Borland.ProjectType>
				<BorlandProject>
					<CPlusPlusBuilder.Personality>
						<VersionInfo>
							<VersionInfo Name="IncludeVerInfo">False</VersionInfo>
							<VersionInfo Name="AutoIncBuild">False</VersionInfo>
							<VersionInfo Name="MajorVer">1</VersionInfo>
							<VersionInfo Name="MinorVer">0</VersionInfo>
							<VersionInfo Name="Release">0</VersionInfo>
							<VersionInfo Name="Build">0</VersionInfo>
							<VersionInfo Name="Debug">False</VersionInfo>
							<VersionInfo Name="PreRelease">False</VersionInfo>
							<VersionInfo Name="Special">False</VersionInfo>
							<VersionInfo Name="Private">False</VersionInfo>
							<VersionInfo Name="DLL">False</VersionInfo>
							<VersionInfo Name="Locale">1058</VersionInfo>
							<VersionInfo Name="CodePage">1251</VersionInfo>
						</VersionInfo>
						<VersionInfoKeys>
							<VersionInfoKeys Name="CompanyName"/>
							<VersionInfoKeys Name="FileDescription"/>
							<VersionInfoKeys Name="FileVersion">1.0.0.0</VersionInfoKeys>
							<VersionInfoKeys Name="InternalName"/>
							<VersionInfoKeys Name="LegalCopyright"/>
							<VersionInfoKeys Name="LegalTrademarks"/>
							<VersionInfoKeys Name="OriginalFilename"/>
							<VersionInfoKeys Name="ProductName"/>
							<VersionInfoKeys Name="ProductVersion">1.0.0.0</VersionInfoKeys>
							<VersionInfoKeys Name="Comments"/>
						</VersionInfoKeys>
						<Debugging>
							<Debugging Name="DebugSourceDirs"/>
						</Debugging>
						<Parameters>
							<Parameters Name="RunParams"/>
							<Parameters Name="Launcher"/>
							<Parameters Name="UseLauncher">False</Parameters>
							<Parameters Name="DebugCWD"/>
							<Parameters Name="HostApplication"/>
							<Parameters Name="RemoteHost"/>
							<Parameters Name="RemotePath"/>
							<Parameters Name="RemoteParams"/>
							<Parameters Name="RemoteLauncher"/>
							<Parameters Name="UseRemoteLauncher">False</Parameters>
							<Parameters Name="RemoteCWD"/>
							<Parameters Name="RemoteDebug">False</Parameters>
							<Parameters Name="Debug Symbols Search Path"/>
							<Parameters Name="LoadAllSymbols">True</Parameters>
							<Parameters Name="LoadUnspecifiedSymbols">False</Parameters>
						</Parameters>
						<ProjectProperties>
							<ProjectProperties Name="AutoShowDeps">False</ProjectProperties>
							<ProjectProperties Name="ManagePaths">True</ProjectProperties>
							<ProjectProperties Name="VerifyPackages">True</ProjectProperties>
						</ProjectProperties>
					</CPlusPlusBuilder.Personality>
				</BorlandProject>
				<ProjectFileVersion>12</ProjectFileVersion>
			</ProjectExtensions>
		</Project>
	'''.strip() + '\n').encode(encoding)
			)
