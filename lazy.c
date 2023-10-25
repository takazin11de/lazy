
#include <stdlib.h>
#include "lazy.h"

#define LAZY_ARG_MAX 5

typedef struct _tag_Lazy _Lazy;

struct _tag_Lazy
{
    lz_func0 func;
    int value;
    int f_value;
    int num_arg;
    Lazy arg[LAZY_ARG_MAX];
};

Lazy expr0(int v)
{
    Lazy x = (Lazy)malloc(sizeof(_Lazy));
    x->num_arg = 0;
    x->value = v;
    x->f_value = 1;
    return x;
}
Lazy lz_num(int v)
{
    return expr0(v);
}
Lazy expr1(lz_func1 func, Lazy a)
{
    Lazy x = (Lazy)malloc(sizeof(_Lazy));
    x->func = (lz_func0)func;
    x->num_arg = 1;
    x->value = 0;
    x->f_value = 0;
    x->arg[0] = a;
    return x;
}
Lazy expr2(lz_func2 func, Lazy a, Lazy b)
{
    Lazy x = (Lazy)malloc(sizeof(_Lazy));
    x->func = (lz_func0)func;
    x->num_arg = 2;
    x->value = 0;
    x->f_value = 0;
    x->arg[0] = a;
    x->arg[1] = b;
    return x;
}
Lazy expr3(lz_func3 func, Lazy a, Lazy b, Lazy c)
{
    Lazy x = (Lazy)malloc(sizeof(_Lazy));
    x->func = (lz_func0)func;
    x->num_arg = 3;
    x->value = 0;
    x->f_value = 0;
    x->arg[0] = a;
    x->arg[1] = b;
    x->arg[2] = c;
    return x;
}
Lazy expr4(lz_func4 func, Lazy a, Lazy b, Lazy c, Lazy d)
{
    Lazy x = (Lazy)malloc(sizeof(_Lazy));
    x->func = (lz_func0)func;
    x->num_arg = 4;
    x->value = 0;
    x->f_value = 0;
    x->arg[0] = a;
    x->arg[1] = b;
    x->arg[2] = c;
    x->arg[3] = d;
    return x;
}

Lazy expr5(lz_func5 func, Lazy a, Lazy b, Lazy c, Lazy d, Lazy e)
{
    Lazy x = (Lazy)malloc(sizeof(_Lazy));
    x->func = (lz_func0)func;
    x->num_arg = 5;
    x->value = 0;
    x->f_value = 0;
    x->arg[0] = a;
    x->arg[1] = b;
    x->arg[2] = c;
    x->arg[3] = d;
    x->arg[4] = e;
    return x;
}
int calc(Lazy x)
{

    if (x->f_value)
    {
        return x->value;
    }
    if (x->num_arg == 1)
    {
        return calc(((lz_func1)(x->func))(x->arg[0]));
    }
    if (x->num_arg == 2)
    {
        return calc(((lz_func2)(x->func))(x->arg[0], x->arg[1]));
    }
    if (x->num_arg == 3)
    {
        return calc(((lz_func3)(x->func))(x->arg[0], x->arg[1], x->arg[2]));
    }
    if (x->num_arg == 4)
    {
        return calc(((lz_func4)(x->func))(x->arg[0], x->arg[1], x->arg[2], x->arg[3]));
    }
    if (x->num_arg == 5)
    {
        return calc(((lz_func5)(x->func))(x->arg[0], x->arg[1], x->arg[2], x->arg[3], x->arg[4]));
    }
}
Lazy _lz_add(Lazy a, Lazy b)
{
    return lz_num(calc(a) + calc(b));
}
Lazy lz_add(Lazy a, Lazy b)
{
    return expr2(_lz_add, a, b);
}

Lazy _lz_sub(Lazy a, Lazy b)
{
    return lz_num(calc(a) - calc(b));
}
Lazy lz_sub(Lazy a, Lazy b)
{
    return expr2(_lz_sub, a, b);
}
Lazy _lz_mul(Lazy a, Lazy b)
{
    return lz_num(calc(a) * calc(b));
}
Lazy lz_mul(Lazy a, Lazy b)
{
    return expr2(_lz_mul, a, b);
}
Lazy _lz_div(Lazy a, Lazy b)
{
    return lz_num(calc(a) / calc(b));
}
Lazy lz_div(Lazy a, Lazy b)
{
    return expr2(_lz_div, a, b);
}
Lazy _lz_mod(Lazy a, Lazy b)
{
    return lz_num(calc(a) % calc(b));
}
Lazy lz_mod(Lazy a, Lazy b)
{
    return expr2(_lz_mod, a, b);
}

Lazy _lz_inv(Lazy a)
{
    return lz_num(-calc(a));
}
Lazy lz_inv(Lazy a)
{
    return expr1(_lz_inv, a);
}

Lazy _lz_abs(Lazy a)
{
    return lz_num(abs(calc(a)));
}
Lazy lz_abs(Lazy a)
{
    return expr1(_lz_abs, a);
}

/////

Lazy _lz_cmp_ge(Lazy a, Lazy b)
{
    return lz_num(calc(a) >= calc(b));
}
Lazy lz_cmp_ge(Lazy a, Lazy b)
{
    return expr2(_lz_cmp_ge, a, b);
}

Lazy _lz_cmp_le(Lazy a, Lazy b)
{
    return lz_num(calc(a) <= calc(b));
}
Lazy lz_cmp_le(Lazy a, Lazy b)
{
    return expr2(_lz_cmp_le, a, b);
}

Lazy _lz_cmp_gt(Lazy a, Lazy b)
{
    return lz_num(calc(a) > calc(b));
}
Lazy lz_cmp_gt(Lazy a, Lazy b)
{
    return expr2(_lz_cmp_gt, a, b);
}

Lazy _lz_cmp_lt(Lazy a, Lazy b)
{
    return lz_num(calc(a) < calc(b));
}
Lazy lz_cmp_lt(Lazy a, Lazy b)
{
    return expr2(_lz_cmp_lt, a, b);
}

Lazy _lz_cmp_eq(Lazy a, Lazy b)
{
    return lz_num(calc(a) == calc(b));
}
Lazy lz_cmp_eq(Lazy a, Lazy b)
{
    return expr2(_lz_cmp_eq, a, b);
}

Lazy _lz_cmp_ne(Lazy a, Lazy b)
{
    return lz_num(calc(a) != calc(b));
}
Lazy lz_cmp_ne(Lazy a, Lazy b)
{
    return expr2(_lz_cmp_ne, a, b);
}
////

Lazy _lz_bit_and(Lazy a, Lazy b)
{
    return lz_num(calc(a) & calc(b));
}
Lazy lz_bit_and(Lazy a, Lazy b)
{
    return expr2(_lz_bit_and, a, b);
}

Lazy _lz_bit_or(Lazy a, Lazy b)
{
    return lz_num(calc(a) | calc(b));
}
Lazy lz_bit_or(Lazy a, Lazy b)
{
    return expr2(_lz_bit_or, a, b);
}

Lazy _lz_bit_xor(Lazy a, Lazy b)
{
    return lz_num(calc(a) ^ calc(b));
}
Lazy lz_bit_xor(Lazy a, Lazy b)
{
    return expr2(_lz_bit_xor, a, b);
}

Lazy _lz_bit_not(Lazy a)
{
    return lz_num(~calc(a));
}
Lazy lz_bit_not(Lazy a)
{
    return expr1(_lz_bit_not, a);
}
//

Lazy _lz_logic_and(Lazy a, Lazy b)
{
    return lz_num(calc(a) && calc(b));
}
Lazy lz_logic_and(Lazy a, Lazy b)
{
    return expr2(_lz_logic_and, a, b);
}

Lazy _lz_logic_or(Lazy a, Lazy b)
{
    return lz_num(calc(a) || calc(b));
}
Lazy lz_logic_or(Lazy a, Lazy b)
{
    return expr2(_lz_logic_or, a, b);
}

Lazy _lz_logic_not(Lazy a)
{
    return lz_num(!calc(a));
}
Lazy lz_logic_not(Lazy a)
{
    return expr1(_lz_logic_not, a);
}
