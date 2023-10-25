
#ifndef LAZY_H
#define LAZY_H

typedef struct _tag_Lazy *Lazy;

typedef Lazy (*lz_func0)();
typedef Lazy (*lz_func1)(Lazy);
typedef Lazy (*lz_func2)(Lazy, Lazy);
typedef Lazy (*lz_func3)(Lazy, Lazy, Lazy);
typedef Lazy (*lz_func4)(Lazy, Lazy, Lazy, Lazy);
typedef Lazy (*lz_func5)(Lazy, Lazy, Lazy, Lazy, Lazy);

Lazy lz_num(int v);
Lazy expr0(int v);
Lazy expr1(lz_func1 func, Lazy a);
Lazy expr2(lz_func2 func, Lazy a, Lazy b);
Lazy expr3(lz_func3 func, Lazy a, Lazy b, Lazy c);
Lazy expr4(lz_func4 func, Lazy a, Lazy b, Lazy c, Lazy d);
Lazy expr5(lz_func5 func, Lazy a, Lazy b, Lazy c, Lazy d, Lazy e);
int calc(Lazy x);

Lazy lz_add(Lazy a, Lazy b);       // a + b
Lazy lz_sub(Lazy a, Lazy b);       // a - b
Lazy lz_mul(Lazy a, Lazy b);       // a * b
Lazy lz_div(Lazy a, Lazy b);       // a / b
Lazy lz_mod(Lazy a, Lazy b);       // a % b
Lazy lz_inv(Lazy a);               // -a
Lazy lz_abs(Lazy a);               // abs(a)
Lazy lz_cmp_ge(Lazy a, Lazy b);    // a >= b
Lazy lz_cmp_le(Lazy a, Lazy b);    // a <= b
Lazy lz_cmp_gt(Lazy a, Lazy b);    // a > b
Lazy lz_cmp_lt(Lazy a, Lazy b);    // a < b
Lazy lz_cmp_eq(Lazy a, Lazy b);    // a == b
Lazy lz_cmp_ne(Lazy a, Lazy b);    // a != b
Lazy lz_bit_and(Lazy a, Lazy b);   // a & b
Lazy lz_bit_or(Lazy a, Lazy b);    // a | b
Lazy lz_bit_xor(Lazy a, Lazy b);   // a ^ b
Lazy lz_bit_not(Lazy a);           // ~a
Lazy lz_logic_and(Lazy a, Lazy b); // a && b
Lazy lz_logic_or(Lazy a, Lazy b);  // a || b
Lazy lz_logic_not(Lazy a);         // !a

#endif