 CC = gcc
 CFLAGS = -O3 -fPIC -shared
 SRC = mySort.c
 HEADER = mySort.h
 LIBRARY = libmysort.so

all: $(LIBRARY)

$(LIBRARY): $(SRC) $(HEADER)
	$(CC) $(CFLAGS) -o $@ $<


clean:
	rm -f $(LIBRARY)