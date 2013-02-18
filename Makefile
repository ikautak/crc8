CC = gcc
SRC = crc8.c
TARGET = crc8
BIN = $(SRC:%.c=%)

$(BIN):	$(SRC)
	$(CC) $^ -o $@

clean:
	-rm -f $(BIN) *~

