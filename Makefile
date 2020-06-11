# Travis example for Modern C++ by Rafał Pocztarski
# For more languages and info see:
# https://github.com/rsp/travis-hello#readme

ifeq ($(OS),Windows_NT)
  ifeq ($(shell uname -s),) # not in a bash-like shell
	CLEANUP = del /F /Q
	MKDIR = mkdir
  else # in a bash-like shell, like msys
	CLEANUP = rm -f
	MKDIR = mkdir -p
  endif
	TARGET_EXTENSION=.exe
else
	CLEANUP = rm -f
	MKDIR = mkdir -p
	TARGET_EXTENSION=.out
endif

C_COMPILER=gcc
ifeq ($(shell uname -s), Darwin)
C_COMPILER=clang
endif

UNITY_ROOT=../../

CFLAGS=-std=c99
#CFLAGS=-std=c89
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -Wpointer-arith
CFLAGS += -Wcast-align
CFLAGS += -Wwrite-strings
CFLAGS += -Wswitch-default
CFLAGS += -Wunreachable-code
CFLAGS += -Winit-self
CFLAGS += -Wmissing-field-initializers
CFLAGS += -Wno-unknown-pragmas
CFLAGS += -Wstrict-prototypes
CFLAGS += -Wundef
CFLAGS += -Wold-style-definition

TARGET_BASE1=test_identifier
TARGET1 = $(TARGET_BASE1)$(TARGET_EXTENSION)
SRC_FILES1= tools/Unity/src/unity.c identifier.c  test/test_identifier.c  test/test_runners/TestIdentifier_Runner.c
INC_DIRS=-Isrc -Itools/Unity/src
SYMBOLS=

all: clean default

default: $(SRC_FILES1)
	$(C_COMPILER) $(CFLAGS) $(INC_DIRS) $(SYMBOLS) $(SRC_FILES1) -fprofile-arcs -ftest-coverage -o $(TARGET1)
#	- ./$(TARGET_BASE1)
	- ./$(TARGET1)

test/test_runners/TestIdentifier_Runner.c: test/test_identifier.c
	ruby tools/Unity/auto/generate_test_runner.rb test/test_identifier.c test/test_runners/TestIdentifier_Runner.c

clean:
	$(CLEANUP) $(TARGET1)

ci: CFLAGS += -Werror
ci: default


