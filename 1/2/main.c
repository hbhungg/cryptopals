#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const char input1[] = "1c0111001f010100061a024b53535009181c";
const char input2[] = "686974207468652062756c6c277320657965";
const char output[] = "746865206b696420646f6e277420706c6179";

void tallymarker_hextobin(const char * str, uint8_t * bytes, size_t blen) {
  uint8_t  pos;
  uint8_t  idx0;
  uint8_t  idx1;

  // mapping of ASCII characters to hex values
  const uint8_t hashmap[] =
  {
   0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, // 01234567
   0x08, 0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 89:;<=>?
   0x00, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0x00, // @ABCDEFG
   0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // HIJKLMNO
  };

  memset(bytes, 0, blen);
  for (pos = 0; ((pos < (blen*2)) && (pos < strlen(str))); pos += 2)
  {
    idx0 = ((uint8_t)str[pos+0] & 0x1F) ^ 0x10;
    idx1 = ((uint8_t)str[pos+1] & 0x1F) ^ 0x10;
    bytes[pos/2] = (uint8_t)(hashmap[idx0] << 4) | hashmap[idx1];
  };
}

void xor(const uint8_t *buffer1, const uint8_t *buffer2, uint8_t *retval, size_t size) {
  for (int i=0;i<size;i++) {
    retval[i] = buffer1[i] ^ buffer2[i];
  }
}

void print_bytes_array(const uint8_t *array, size_t size) {
  for (size_t i = 0; i < size; i++) {
    printf("%02X ", array[i]);
  }
  printf("\n");
}

int main() {
  uint8_t *buffer1 = (uint8_t*)malloc(18);
  uint8_t *buffer2 = (uint8_t*)malloc(18);
  uint8_t *output = (uint8_t*)malloc(18);

  tallymarker_hextobin(input1, buffer1, strlen(input1));
  tallymarker_hextobin(input2, buffer2, strlen(input2));

  printf("%s\n", input1);
  printf("%s\n", input2);
  print_bytes_array(buffer1, 18);
  print_bytes_array(buffer2, 18);

  xor(buffer1, buffer2, output, 18);
  print_bytes_array(output, 18);

  free(buffer1);
  free(buffer2);
  free(output);
}
