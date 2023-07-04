CC = clang
CFLAGS = -Wall -Wextra -Wpedantic -Werror  -O2
LDFLAGS = -lm

OBJECTS = $(patsubst %.c, %.o, $(SOURCES))
HFILE = $(wildcard *.h)

all: sorting

%.o: %.c $(HFILE)
	$(CC) $(CFLAGS) -c $<

sorting: $(OBJECTS) sorting.o
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

tidy:
	rm -rf $(wildcard *.o)
clean: tidy
	rm -rf sorting
format:
	clang-format -i -style=file *.[c,h]
