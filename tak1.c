#include <stdio.h>
#include <stdlib.h>

int count = 0;
int tak(int x, int y, int z) {
  printf("count = %d, tak(%d, %d %d)\n", count, x, y, z);
  count++;
  if (x <= y) {
    return z;
  }
  return tak(tak(x - 1, y, z), tak(y - 1, z, x), tak(z - 1, x, y));
}

int main() {
  int ans = tak(10, 5, 0);
  printf("ans = %d\n", ans);
  printf("count = %d\n", count);
  return 0;
}