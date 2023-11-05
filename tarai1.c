#include <stdio.h>
#include <stdlib.h>

int count = 0;
int tarai(int x, int y, int z) {
  printf("count = %d, tarai(%d, %d %d)\n", count, x, y, z);
  count++;
  if (x <= y) {
    return y;
  }
  return tarai(tarai(x - 1, y, z), tarai(y - 1, z, x), tarai(z - 1, x, y));
}

int main() {
  int ans = tarai(6, 3, 0);
  printf("ans = %d\n", ans);
  printf("count = %d\n", count);
  return 0;
}