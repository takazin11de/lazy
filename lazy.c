#include "lazy.h"

#include <stdio.h>
#include <stdlib.h>

int no_lazy_ = 0;
int no_memorize_ = 0;

void no_lazy() { no_lazy_ = 1; }
void no_memorize() { no_memorize_ = 1; }

Lazy _lz_add(Lazy a, Lazy b);    // a + b
Lazy _lz_sub(Lazy a, Lazy b);    // a - b
Lazy _lz_mul(Lazy a, Lazy b);    // a * b
Lazy _lz_div(Lazy a, Lazy b);    // a / b
Lazy _lz_mod(Lazy a, Lazy b);    // a % b
Lazy _lz_inv(Lazy a);            // -a
Lazy _lz_abs(Lazy a);            // abs(a)
Lazy _lz_ge(Lazy a, Lazy b);     // a >= b
Lazy _lz_le(Lazy a, Lazy b);     // a <= b
Lazy _lz_gt(Lazy a, Lazy b);     // a > b
Lazy _lz_lt(Lazy a, Lazy b);     // a < b
Lazy _lz_eq(Lazy a, Lazy b);     // a == b
Lazy _lz_ne(Lazy a, Lazy b);     // a != b
Lazy _lz_b_and(Lazy a, Lazy b);  // a & b
Lazy _lz_b_or(Lazy a, Lazy b);   // a | b
Lazy _lz_b_xor(Lazy a, Lazy b);  // a ^ b
Lazy _lz_b_not(Lazy a);          // ~a
Lazy _lz_and(Lazy a, Lazy b);    // a && b
Lazy _lz_or(Lazy a, Lazy b);     // a || b
Lazy _lz_not(Lazy a);            // !a

int hash_lazy(Lazy x);

#define LAZY_ARG_MAX 5

typedef struct _tag_Lazy _Lazy;

struct _tag_Lazy {
  lz_func0 func;
  int value;
  int f_value;
  int num_arg;
  Lazy arg[LAZY_ARG_MAX];
};

Lazy expr0(int v) {
  Lazy x = (Lazy)malloc(sizeof(_Lazy));
  x->func = NULL;
  x->num_arg = 0;
  x->value = v;
  x->f_value = 1;
  return x;
}
Lazy lzn(int v) { return expr0(v); }
Lazy expr1(lz_func1 func, Lazy a) {
  Lazy x = (Lazy)malloc(sizeof(_Lazy));
  x->func = (lz_func0)func;
  x->num_arg = 1;
  x->value = 0;
  x->f_value = 0;
  x->arg[0] = a;
  if (!no_lazy_)
    return x;
  else {
    return lzn(calc(x));
  }
}
Lazy expr2(lz_func2 func, Lazy a, Lazy b) {
  Lazy x = (Lazy)malloc(sizeof(_Lazy));
  x->func = (lz_func0)func;
  x->num_arg = 2;
  x->value = 0;
  x->f_value = 0;
  x->arg[0] = a;
  x->arg[1] = b;
  if (!no_lazy_)
    return x;
  else {
    return lzn(calc(x));
  }
}
Lazy expr3(lz_func3 func, Lazy a, Lazy b, Lazy c) {
  Lazy x = (Lazy)malloc(sizeof(_Lazy));
  x->func = (lz_func0)func;
  x->num_arg = 3;
  x->value = 0;
  x->f_value = 0;
  x->arg[0] = a;
  x->arg[1] = b;
  x->arg[2] = c;
  if (!no_lazy_)
    return x;
  else {
    return lzn(calc(x));
  }
}
Lazy expr4(lz_func4 func, Lazy a, Lazy b, Lazy c, Lazy d) {
  Lazy x = (Lazy)malloc(sizeof(_Lazy));
  x->func = (lz_func0)func;
  x->num_arg = 4;
  x->value = 0;
  x->f_value = 0;
  x->arg[0] = a;
  x->arg[1] = b;
  x->arg[2] = c;
  x->arg[3] = d;
  if (!no_lazy_)
    return x;
  else {
    return lzn(calc(x));
  }
}

Lazy expr5(lz_func5 func, Lazy a, Lazy b, Lazy c, Lazy d, Lazy e) {
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
  if (!no_lazy_)
    return x;
  else {
    return lzn(calc(x));
  }
}
typedef struct _tag_Element_List *Element_List;

Lazy is_memorized(Lazy x);
void memorize(Lazy x);

int calc(Lazy x) {
  Lazy tmp;
  int ans;
  if (x->f_value) {
    return x->value;
  }
  if (!no_memorize_) {
    tmp = is_memorized(x);
    if (tmp) {
      ans = tmp->value;
      x->value = ans;
      x->f_value = 1;
      return ans;
    }
  }
  if (x->num_arg == 1) {
    tmp = ((lz_func1)(x->func))(x->arg[0]);
    ans = calc(tmp);
    x->value = ans;
    x->f_value = 1;
    if (!no_memorize_) {
      memorize(x);
    }
    return ans;
  }
  if (x->num_arg == 2) {
    tmp = ((lz_func2)(x->func))(x->arg[0], x->arg[1]);
    ans = calc(tmp);
    x->value = ans;
    x->f_value = 1;
    if (!no_memorize_) {
      memorize(x);
    }
    return ans;
  }
  if (x->num_arg == 3) {
    tmp = ((lz_func3)(x->func))(x->arg[0], x->arg[1], x->arg[2]);
    ans = calc(tmp);
    x->value = ans;
    x->f_value = 1;
    if (!no_memorize_) {
      memorize(x);
    }
    return ans;
  }
  if (x->num_arg == 4) {
    tmp = ((lz_func4)(x->func))(x->arg[0], x->arg[1], x->arg[2], x->arg[3]);
    ans = calc(tmp);
    x->value = ans;
    x->f_value = 1;
    if (!no_memorize_) {
      memorize(x);
    }
    return ans;
  }
  if (x->num_arg == 5) {
    tmp = ((lz_func5)(x->func))(x->arg[0], x->arg[1], x->arg[2], x->arg[3],
                                x->arg[4]);
    ans = calc(tmp);
    x->value = ans;
    x->f_value = 1;
    if (!no_memorize_) {
      memorize(x);
    }
    return ans;
  }
}

int get_f_value(Lazy x) { return x->f_value; }
int get_value(Lazy x) { return x->value; }

LZ_FN2(lz_add, a, b) { return lzn(calc(a) + calc(b)); }

LZ_FN2(lz_sub, a, b) { return lzn(calc(a) - calc(b)); }
LZ_FN2(lz_mul, a, b) { return lzn(calc(a) * calc(b)); }
LZ_FN2(lz_div, a, b) { return lzn(calc(a) / calc(b)); }
LZ_FN2(lz_mod, a, b) { return lzn(calc(a) % calc(b)); }

LZ_FN1(lz_inv, a) { return lzn(-calc(a)); }

LZ_FN1(lz_abs, a) { return lzn(abs(calc(a))); }

/////

LZ_FN2(lz_ge, a, b) { return lzn(calc(a) >= calc(b)); }

LZ_FN2(lz_le, a, b) { return lzn(calc(a) <= calc(b)); }

LZ_FN2(lz_gt, a, b) { return lzn(calc(a) > calc(b)); }

LZ_FN2(lz_lt, a, b) { return lzn(calc(a) < calc(b)); }

LZ_FN2(lz_eq, a, b) { return lzn(calc(a) == calc(b)); }

LZ_FN2(lz_ne, a, b) { return lzn(calc(a) != calc(b)); }
////

LZ_FN2(lz_b_and, a, b) { return lzn(calc(a) & calc(b)); }

LZ_FN2(lz_b_or, a, b) { return lzn(calc(a) | calc(b)); }

LZ_FN2(lz_b_xor, a, b) { return lzn(calc(a) ^ calc(b)); }

LZ_FN1(lz_b_not, a) { return lzn(~calc(a)); }
//

LZ_FN2(lz_and, a, b) { return lzn(calc(a) && calc(b)); }

LZ_FN2(lz_or, a, b) { return lzn(calc(a) || calc(b)); }

LZ_FN1(lz_not, a) { return lzn(!calc(a)); }

////////////////////////////////////////////

typedef struct _tag_Hash *Hash;
typedef struct _tag_Hash {
  unsigned int data;
} Hash_Raw;

void Hash_Init(Hash self);
int ShuffleBijection(int x);
void Hash_Add(Hash self, unsigned int x);
int Hash_Value(Hash self);

void Hash_Init(Hash self) { self->data = 0; }

int ShuffleBijection(int x) {
  int a;
  a = x * 0x4C957F2D + 0xF767814F;
  a ^= a >> 5;
  a ^= a >> 11;
  a ^= a >> 17;
  return a;
}

void Hash_Add(Hash self, unsigned int x) {
  self->data += x;
  self->data = ShuffleBijection(self->data);
}

int Hash_Value(Hash self) { return self->data & 0xFFFF; }

///////////////////////////////////////

#define HASH_TABLE_SIZE 0x10000

typedef struct _tag_Element_List {
  Lazy lz;
  Element_List next;
} Element_List_Raw;

Element_List Hash_Table[HASH_TABLE_SIZE];

int LzMemoCmp(Lazy a, Lazy b);

int hash_lazy(Lazy x) {
  Hash_Raw hash;
  Hash_Init(&hash);
  Hash_Add(&hash, (unsigned int)x->func);
  int i;

  for (i = 0; i < x->num_arg; i++) {
    if (x->arg[i]->f_value) {
      Hash_Add(&hash, 1);
      Hash_Add(&hash, x->arg[i]->value);
    } else {
      Hash_Add(&hash, 0);
      Hash_Add(&hash, 0);
    }
  }
  return Hash_Value(&hash);
}
int LzPrint(Lazy a);

Lazy is_memorized(Lazy x) {
  Lazy lz;
  Element_List list, list_prev;
  int i;
  int hash_value = hash_lazy(x);
  list = Hash_Table[hash_value];

  if (list) {
    list_prev = list;
    while (list) {
      lz = list->lz;
      if (LzMemoCmp(lz, x)) {
        return lz;
      }
      list_prev = list;
      list = list->next;
    }
    return 0;
  }
  return 0;
}

int LzMemoCmp(Lazy a, Lazy b) {
  int i;
  int num_arg = a->num_arg;

  if (num_arg != b->num_arg) {
    return 0;
  }
  if (a->func != b->func) {
    return 0;
  }
  for (i = 0; i < num_arg; i++) {
    if (a->arg[i]->f_value && b->arg[i]->f_value) {
      if (a->arg[i]->value != b->arg[i]->value) {
        return 0;
      }
    } else if (a->arg[i]->f_value == 0 && b->arg[i]->f_value == 0) {
    } else {
      return 0;
    }
  }
  return 1;
}

int LzPrint(Lazy a) {
  int i;
  int num_arg = a->num_arg;
  printf("-------------\n");
  printf("func %ld\n", a->func);
  printf("num_arg %ld\n", a->num_arg);
  printf("f_value %ld\n", a->f_value);
  printf("value %ld\n", a->value);
  for (i = 0; i < num_arg; i++) {
    if (a->arg[i]->f_value) {
      printf("  [%ld]->value %ld\n", i, a->arg[i]->value);
    } else {
      printf("  [%ld]->value ?\n", i);
    }
  }
  printf("-------------\n");
  return 1;
}

void memorize(Lazy x) {
  Lazy lz;
  Element_List list, list_prev;
  int i;
  int hash_value = hash_lazy(x);
  list = Hash_Table[hash_value];

  if (list) {
    list_prev = list;
    while (list) {
      lz = list->lz;
      if (LzMemoCmp(lz, x)) {
        return;
      }
      list_prev = list;
      list = list->next;
    }
    list_prev->next = malloc(sizeof(Element_List_Raw));
    list_prev->next->lz = x;
    list_prev->next->next = NULL;
    return;
  }

  Hash_Table[hash_value] = malloc(sizeof(Element_List_Raw));
  Hash_Table[hash_value]->lz = x;
  Hash_Table[hash_value]->next = NULL;
  return;
}