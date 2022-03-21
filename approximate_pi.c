#include <stdio.h>

int main() {
  float pi = 1;
  for (int i = 0; i < 280000; i++) {
    int den = i * 2 + 3;
    if (i % 2 == 0) {
      pi -= (1.0f / (float)den);
    } else {
      pi += (1.0f / (float)den);
    }
  }

  pi *= 4.0;

  printf("%f\n", pi);
}
