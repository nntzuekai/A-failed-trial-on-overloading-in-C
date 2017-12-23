#pragma once
#ifndef A_H
#define A_H

#include "Args_Cnt.h"

typedef struct A_impl A;

void A_set_int_int(A *pa, int x, int y);
void A_set_int(A *pa, int i);
void A_set_Ap(A *pa, A *rhs);

A *A_new_void(void);
A *A_new_Ap(A *pa);
A *A_new_int(int i);
A *A_new_int_int(int x, int y);

void A_delete(A *pa);

void A_print(A *pa);

#define A_new0_name(...) A_new_void
#define A_new0(...) A_new0_name(__VA_ARGS__)(__VA_ARGS__)

#define A_new1_name(arg) _Generic((arg), A*: A_new_Ap, int: A_new_int)
#define A_new1(arg) A_new1_name(arg) (arg)

#define A_new2_name(...) A_new_int_int
#define A_new2(...) A_new2_name(__VA_ARGS__)(__VA_ARGS__)

#define A_new_name(...) PASTE(PASTE(A_new,COUNT_ARGS(__VA_ARGS__)),_name)(__VA_ARGS__)
#define A_new(...) PASTE(A_new,COUNT_ARGS(__VA_ARGS__))(__VA_ARGS__)

#define A_set2_name(arg0, arg) _Generic((arg), A*: A_set_Ap, int: A_set_int)
#define A_set2(arg0, arg) A_set2_name(arg0, arg) (arg0, arg)

#define A_set3_name(...) A_set_int_int
#define A_set3(...) A_set3_name(__VA_ARGS__)(__VA_ARGS__)

#define A_set_name(...) PASTE(PASTE(A_set, COUNT_ARGS(__VA_ARGS__)),_name)(__VA_ARGS__)
#define A_set(...) PASTE(A_set, COUNT_ARGS(__VA_ARGS__))(__VA_ARGS__)

#define A_print_name(...) A_print

#define A_delete_name(...) A_delete

#endif // A_H
