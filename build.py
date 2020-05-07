#!/usr/bin/env python3

from pathlib import Path
from itertools import chain
from os import getenv
import asyncio
from asyncio import subprocess


CC = getenv('CC', 'gcc')
CPP = getenv('CPP', 'g++')
CFLAGS = getenv('CFLAGS', '-std=c99 -static')
CPPFLAGS = getenv('CPPFLAGS', '-std=c++11 -static')
OUT_SUFFIX = getenv('OUT_SUFFIX', '.out')
QUIRK = getenv('QUIRK', '')

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


async def task_fn(task_id):
	while len(files) > 0:
		source: Path = files.pop()
		try:
			name = source.stem
			ext = source.suffix
			directory = source.parent
			
			out_file: Path = directory / (name + OUT_SUFFIX)
			log_file: Path = directory / (name + '.log')

			compiler, flags = None, None
			if ext in extensions_c:
				compiler = CC
				flags = CFLAGS.split(' ')
			elif ext in extensions_cpp:
				compiler = CPP
				flags = CPPFLAGS.split(' ')

			if compiler is None:
				continue

			sources = [
				source,
			]

			command = [
				compiler,
				*flags,
				*sources,
				'-o',
				out_file,
				'-lm',
			]

			command = ' '.join(str(i) for i in command)

			proc = await asyncio.create_subprocess_shell(
				command,
				stdout=subprocess.PIPE,
				stderr=subprocess.PIPE,
			)

			(stdout, stderr) = await proc.communicate()

			if proc.returncode != 0:
				print(f'Failed to compile file "{source}"')
			else:
				print(f'Done "{source}"')

			stdout = stdout.strip()
			stderr = stderr.strip()

			if stdout != b'' or stderr != b'':
				with log_file.open('ab+') as f:
					if stdout != b'':
						f.write('STDOUT:\n'.encode('utf-8'))
						f.write(stdout)
						f.write('\n\n'.encode('utf-8'))
					if stderr != b'':
						f.write('STDERR:\n'.encode('utf-8'))
						f.write(stderr)
						f.write('\n\n'.encode('utf-8'))
		except Exception as e:
			print(e)


async def main():
	tasks_count = 4
	for task in [asyncio.create_task(task_fn(i)) for i in range(tasks_count)]:
		await task


asyncio.run(main())
