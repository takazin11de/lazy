#ifndef LAZY_H
#define LAZY_H

typedef struct _tag_Lazy *Lazy;

typedef Lazy (*lz_func0)();
typedef Lazy (*lz_func1)(Lazy);
typedef Lazy (*lz_func2)(Lazy, Lazy);
typedef Lazy (*lz_func3)(Lazy, Lazy, Lazy);
typedef Lazy (*lz_func4)(Lazy, Lazy, Lazy, Lazy);
typedef Lazy (*lz_func5)(Lazy, Lazy, Lazy, Lazy, Lazy);

Lazy lzn(int v);
Lazy expr0(int v);
Lazy expr1(lz_func1 func, Lazy a);
Lazy expr2(lz_func2 func, Lazy a, Lazy b);
Lazy expr3(lz_func3 func, Lazy a, Lazy b, Lazy c);
Lazy expr4(lz_func4 func, Lazy a, Lazy b, Lazy c, Lazy d);
Lazy expr5(lz_func5 func, Lazy a, Lazy b, Lazy c, Lazy d, Lazy e);
int calc(Lazy x);
int get_f_value(Lazy x);
int get_value(Lazy x);

Lazy lz_add(Lazy a, Lazy b);    // a + b
Lazy lz_sub(Lazy a, Lazy b);    // a - b
Lazy lz_mul(Lazy a, Lazy b);    // a * b
Lazy lz_div(Lazy a, Lazy b);    // a / b
Lazy lz_mod(Lazy a, Lazy b);    // a % b
Lazy lz_inv(Lazy a);            // -a
Lazy lz_abs(Lazy a);            // abs(a)
Lazy lz_ge(Lazy a, Lazy b);     // a >= b
Lazy lz_le(Lazy a, Lazy b);     // a <= b
Lazy lz_gt(Lazy a, Lazy b);     // a > b
Lazy lz_lt(Lazy a, Lazy b);     // a < b
Lazy lz_eq(Lazy a, Lazy b);     // a == b
Lazy lz_ne(Lazy a, Lazy b);     // a != b
Lazy lz_b_and(Lazy a, Lazy b);  // a & b
Lazy lz_b_or(Lazy a, Lazy b);   // a | b
Lazy lz_b_xor(Lazy a, Lazy b);  // a ^ b
Lazy lz_b_not(Lazy a);          // ~a
Lazy lz_and(Lazy a, Lazy b);    // a && b
Lazy lz_or(Lazy a, Lazy b);     // a || b
Lazy lz_not(Lazy a);            // !a

void no_lazy();
void no_memorize();

#define LZ_FN1(name, a)                           \
  Lazy _##name(Lazy a);                           \
  Lazy name(Lazy a) { return expr1(_##name, a); } \
  Lazy _##name(Lazy a)

#define LZ_FN2(name, a, b)                                   \
  Lazy _##name(Lazy a, Lazy b);                              \
  Lazy name(Lazy a, Lazy b) { return expr2(_##name, a, b); } \
  Lazy _##name(Lazy a, Lazy b)

#define LZ_FN3(name, a, b, c)                                           \
  Lazy _##name(Lazy a, Lazy b, Lazy c);                                 \
  Lazy name(Lazy a, Lazy b, Lazy c) { return expr3(_##name, a, b, c); } \
  Lazy _##name(Lazy a, Lazy b, Lazy c)

#define LZ_FN4(name, a, b, c, d)                \
  Lazy _##name(Lazy a, Lazy b, Lazy c, Lazy d); \
  Lazy name(Lazy a, Lazy b, Lazy c, Lazy d) {   \
    return expr4(_##name, a, b, c, d);          \
  }                                             \
  Lazy _##name(Lazy a, Lazy b, Lazy c, Lazy d)

#define LZ_FN5(name, a, b, c, d, e)                     \
  Lazy _##name(Lazy a, Lazy b, Lazy c, Lazy d, Lazy e); \
  Lazy name(Lazy a, Lazy b, Lazy c, Lazy d, Lazy e) {   \
    return expr5(_##name, a, b, c, d, e);               \
  }                                                     \
  Lazy _##name(Lazy a, Lazy b, Lazy c, Lazy d, Lazy e)

#define LZ_FN1_PRINT(name, a)                                \
  printf("%s(", #name);                                      \
  get_f_value(a) ? printf("%d", get_value(a)) : printf("?"); \
  printf(")\n");

#define LZ_FN2_PRINT(name, a, b)                                 \
  printf("%s(", #name);                                          \
  get_f_value(a) ? printf("%d, ", get_value(a)) : printf("?, "); \
  get_f_value(b) ? printf("%d", get_value(b)) : printf("?");     \
  printf(")\n");

#define LZ_FN3_PRINT(name, a, b, c)                              \
  printf("%s(", #name);                                          \
  get_f_value(a) ? printf("%d, ", get_value(a)) : printf("?, "); \
  get_f_value(b) ? printf("%d, ", get_value(b)) : printf("?, "); \
  get_f_value(c) ? printf("%d", get_value(c)) : printf("?");     \
  printf(")\n");

#define LZ_FN4_PRINT(name, a, b, c, d)                           \
  printf("%s(", #name);                                          \
  get_f_value(a) ? printf("%d, ", get_value(a)) : printf("?, "); \
  get_f_value(b) ? printf("%d, ", get_value(b)) : printf("?, "); \
  get_f_value(c) ? printf("%d, ", get_value(c)) : printf("?, "); \
  get_f_value(d) ? printf("%d", get_value(d)) : printf("?");     \
  printf(")\n");

#define LZ_FN5_PRINT(name, a, b, c, d, e)                        \
  printf("%s(", #name);                                          \
  get_f_value(a) ? printf("%d, ", get_value(a)) : printf("?, "); \
  get_f_value(b) ? printf("%d, ", get_value(b)) : printf("?, "); \
  get_f_value(c) ? printf("%d, ", get_value(c)) : printf("?, "); \
  get_f_value(d) ? printf("%d, ", get_value(d)) : printf("?, "); \
  get_f_value(e) ? printf("%d", get_value(e)) : printf("?");     \
  printf(")\n");

#endif