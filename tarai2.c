
#include <stdio.h>
#include "lazy.h"
int count = 0;

Lazy tarai(Lazy x, Lazy y, Lazy z);

Lazy _tarai(Lazy x, Lazy y, Lazy z)
{
    printf("count = %d\n", count);
    count++;
    if (calc(lz_cmp_le(x, y)))
    {
        return y;
    }
    return tarai(tarai(lz_sub(x, lz_num(1)), y, z), tarai(lz_sub(y, lz_num(1)), z, x), tarai(lz_sub(z, lz_num(1)), x, y));
}
Lazy tarai(Lazy x, Lazy y, Lazy z)
{
    return expr3(_tarai, x, y, z);
}

int main()
{
    int ans = calc(tarai(lz_num(10), lz_num(5), lz_num(0)));
    printf("ans = %d\n", ans);
    return 0;
}
