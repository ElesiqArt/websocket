-include config.mk

CATCH ?= .

all: test printer run-test Makefile

run-test: test Makefile
	./$<

test: test.cpp Makefile
	g++ $< -std=c++11 -Wall -Wextra -Werror -MD -O0 -g -I $(CATCH) -I ../ -o $@

printer: printer.cpp Makefile
	g++ $< -std=c++11 -Wall -Wextra -Werror -MD -O0 -g -I $(CATCH) -I ../ -o $@

-include test.d printer.d

clean:
	rm -f test.d test.o test
