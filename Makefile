# Travis example for Modern C++ by Rafał Pocztarski
# For more languages and info see:
# https://github.com/rsp/travis-hello#readme

GCCFLAGS = -g -Wall -Wfatal-errors 
ALL = identifier

all: $(ALL)

hello: identifier.c
	$(GCC) $(GCCFLAGS) -o $@ $@.c

clean:
	$(RM) $(ALL) *.o

test: all
	bash test
