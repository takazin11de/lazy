
#include <stdio.h>

#include "lazy.h"
int count = 0;

LZ_FN3(tak, x, y, z) {
  int cnt = ++count;
  int tmp = calc(lz_le(x, y));
  printf("count = %d ", cnt);
  LZ_FN3_PRINT(tak, x, y, z);
  if (tmp) {
    return z;
  }
  return tak(tak(lz_sub(x, lzn(1)), y, z), tak(lz_sub(y, lzn(1)), z, x),
             tak(lz_sub(z, lzn(1)), x, y));
}

int main() {
  // no_lazy();
  // no_memorize();
  int ans = calc(tak(lzn(10), lzn(5), lzn(0)));
  printf("ans = %d\n", ans);
  printf("count = %d\n", count);
  return 0;
}
