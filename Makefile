-include config.mk

CATCH ?= .

all: test run-test Makefile

run-test: test Makefile
	./$<

test: test.cpp Makefile
	g++ $< -std=c++11 -Wall -Wextra -Werror -MD -O0 -g -I $(CATCH) -I ../ -o $@

-include test.d

clean:
	rm -f test.d test.o test
