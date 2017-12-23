#pragma once
#ifndef B_H
#define B_H

#include "Args_Cnt.h"

typedef struct B_impl B;

void B_set_double_double(B *pb, double x, double y);
void B_set_double(B *pb, double d);
void B_set_Bp(B *pb, B *rhs);

B *B_new_void(void);
B *B_new_Bp(B *pb);
B *B_new_double(double d);
B *B_new_double_double(double x, double y);

void B_delete(B *pb);

void B_print(B *pb);

#define B_new0_name(...) B_new_void
#define B_new0(...) B_new0_name(__VA_ARGS__)(__VA_ARGS__)

#define B_new1_name(arg) _Generic((arg), B*: B_new_Bp, double: B_new_double, int: B_new_double)
#define B_new1(arg) B_new1_name(arg) (arg)

#define B_new2_name(...) B_new_double_double
#define B_new2(...) B_new2_name(__VA_ARGS__)(__VA_ARGS__)

#define B_new_name(...) PASTE(PASTE(B_new,COUNT_ARGS(__VA_ARGS__)),_name)(__VA_ARGS__)
#define B_new(...) PASTE(B_new,COUNT_ARGS(__VA_ARGS__))(__VA_ARGS__)

#define B_set2_name(arg0,arg) _Generic((arg), B*:B_set_Bp, double: B_set_double, int: B_set_double)
#define B_set2(...) B_set2_name(__VA_ARGS__)(__VA_ARGS__)

#define B_set3_name(...) B_set_double_double
#define B_set3(...) B_set3_name(__VA_ARGS__)(__VA_ARGS__)

#define B_set(...) PASTE(B_set, COUNT_ARGS(__VA_ARGS__))(__VA_ARGS__)

#define B_set_name(...) PASTE(PASTE(B_set, COUNT_ARGS(__VA_ARGS__)), _name) (__VA_ARGS__)

#define B_print_name(...) B_print

#define B_delete_name(...) B_delete

#endif // B_H
