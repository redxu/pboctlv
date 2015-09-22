CC 		= gcc
CFLAGS 	= -O -g -Wall
SRC		= tlvparse.c testtlv.c

all : tlvparse

tlvparse : $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o tlvparse

clean:
	$(RM) tlvparse

