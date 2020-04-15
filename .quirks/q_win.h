#pragma once

#define main(...) real_main(int argc, char **argv)

int real_main(int, char **) __attribute__((weak));
