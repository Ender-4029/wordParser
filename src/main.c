#include <ctype.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

struct keyedData {
  char key;
  uint32_t value;
};
// https://cplusplus.com/reference/cstdlib/qsort/
int compareMap(const void *a, const void *b) {
  const struct keyedData *x = (const struct keyedData *)a;
  const struct keyedData *y = (const struct keyedData *)b;
  return y->value - x->value;
}

int main() {
  struct keyedData data[26];
  for (int i = 0; i < sizeof(data) / sizeof(struct keyedData); i++) {
    data[i].key = i + 97;
    data[i].value = 0;
  }
  FILE *wordsFile;
  wordsFile = fopen("words_alpha.txt", "r");
  if (wordsFile != NULL) {
    int isRunning = 1;
    while (isRunning) {
      int curChar = tolower(fgetc(wordsFile));
      if (curChar >= 97 && curChar < 123) {
        data[curChar - 97].value += 1;
      }
      if (curChar == EOF) {
        break;
      }
    }

  } else {
    fprintf(stderr, "File failed to open");
    exit(-1);
  }
  qsort(data, sizeof(data) / sizeof(struct keyedData), sizeof(struct keyedData),
        compareMap);
  for (int i = 0; i < sizeof(data) / sizeof(struct keyedData); i++) {
    printf("%i: %c has %u occurances\n", i + 1, data[i].key, data[i].value);
  }
}