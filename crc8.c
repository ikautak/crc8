#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

uint8_t crc8_lsb(uint8_t poly, uint8_t *data, size_t size) {
  uint8_t crc = 0x00;

  while (size--) {
    crc ^= *data++;
    for (int bit = 0; bit < 8; bit++) {
      if (crc & 0x01) {
        crc = (crc >> 1) ^ poly;
      } else {
        crc >>= 1;
      }
    }
  }

  return crc;
}

uint8_t crc8_msb(uint8_t poly, uint8_t *data, size_t size) {
  uint8_t crc = 0x00;

  while (size--) {
    crc ^= *data++;
    for (int bit = 0; bit < 8; bit++) {
      if (crc & 0x80) {
        crc = (crc << 1) ^ poly;
      } else {
        crc <<= 1;
      }
    }
  }

  return crc;
}

int main(void) {
  char *data = "Hello World!!!";
  uint8_t poly;

  // x8 + x4 + x3 + x2 + 1 -> 0x1D
  poly = 0x1D;
  printf("%02x\n", crc8_lsb(poly, (uint8_t *)data, strlen(data)));
  printf("%02x\n", crc8_msb(poly, (uint8_t *)data, strlen(data)));

  // x8 + x5 + x4 + 1 -> 0x31
  poly = 0x31;
  printf("%02x\n", crc8_lsb(poly, (uint8_t *)data, strlen(data)));
  printf("%02x\n", crc8_msb(poly, (uint8_t *)data, strlen(data)));

  return EXIT_SUCCESS;
}
