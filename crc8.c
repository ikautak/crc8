#include <stdio.h>
#include <stdlib.h>
#include <string.h>


unsigned char crc8_lsb(unsigned char poly, unsigned char* data, int size)
{
	unsigned char crc = 0x00;
	int bit;

	while (size--) {
		crc ^= *data++;
		for (bit = 0; bit < 8; bit++) {
			if (crc & 0x01) {
				crc = (crc >> 1) ^ poly;
			} else {
				crc >>= 1;
			}
		}
	}

	return crc;
}

unsigned char crc8_msb(unsigned char poly, unsigned char* data, int size)
{
	unsigned char crc = 0x00;
	int bit;

	while (size--) {
		crc ^= *data++;
		for (bit = 0; bit < 8; bit++) {
			if (crc & 0x80) {
				crc = (crc << 1) ^ poly;
			} else {
				crc <<= 1;
			}
		}
	}

	return crc;
}

int main(void)
{
	char* data = "Hello World!!!";
	unsigned char poly;

	// x8 + x4 + x3 + x2 + 1 -> 0x1D
	poly = 0x1D;
	printf("%02x\n", crc8_lsb(poly, data, strlen(data)));
	printf("%02x\n", crc8_msb(poly, data, strlen(data)));

	// x8 + x5 + x4 + 1 -> 0x31
	poly = 0x31;
	printf("%02x\n", crc8_lsb(poly, data, strlen(data)));
	printf("%02x\n", crc8_msb(poly, data, strlen(data)));

	return EXIT_SUCCESS;
}

