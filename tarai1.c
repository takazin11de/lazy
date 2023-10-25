#include <stdio.h>
#include <stdlib.h>

int count = 0;
int tarai(int x, int y, int z)
{
    printf("count = %d, tarai(%d, %d %d)\n", count, x, y, z);
    count++;
    if (x <= y)
    {
        return y;
    }
    return tarai(tarai(x - 1, y, z), tarai(y - 1, z, x), tarai(z - 1, x, y));
}

int main()
{
    int ans = tarai(10, 5, 0);
    printf("ans = %d\n", ans);
    return 0;
}