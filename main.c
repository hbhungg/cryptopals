#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char base64_char(int val) {
  switch (val) {
    case  0 ... 25: return (val -  0) + 'A';
    case 26 ... 51: return (val - 26) + 'a';
    case 52 ... 61: return (val - 52) + '0';
    case 62:        return '+';
    case 63:        return '/';
  }
  return '?';
}

char input[] = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
char result[] = "SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t";

void hex_to_base64(char* base64, char *hex) {
  for (int i=0;i<strlen(input);i+=3) {
    // input[i:i+3]
    char slice[4];
    strncpy(slice, input+i, 3);
    slice[3] = '\0';

    int buffer = strtol(slice, NULL, 16);

    int b1 = buffer >> 6;
    int b2 = buffer & (1 << 6)-1;
    char c1 = base64_char(b1);
    char c2 = base64_char(b2);
    base64[(i/3)*2] = c1;
    base64[(i/3)*2+1] = c2;
  }
}

int main() {
  printf("%s\n", input);
  char *retval = (char*)malloc(64);
  hex_to_base64(retval, input);
  printf("%s\n", retval);
  printf("%s\n", result);
  free(retval);
}
