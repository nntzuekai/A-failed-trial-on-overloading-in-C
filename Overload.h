#pragma once
#ifndef OVERLOAD_H
#define OVERLOAD_H

#include "Args_Cnt.h"
#include "Overload_type.h"

#ifdef A_H
#define _TYPE_OF_A A
#else
#define _TYPE_OF_A _empty_type_A
#define A_set_name(...) _empty_function
#define A_print_name(...) _empty_function
#define A_delete_name(...) _empty_function
#define A_new_name(...) _empty_function
#endif

#ifdef B_H
#define _TYPE_OF_B B
#else
#define _TYPE_OF_B _empty_type_B
#define B_set_name(...) _empty_function
#define B_print_name(...) _empty_function
#define B_delete_name(...) _empty_function
#define B_new_name(...) _empty_function
#endif

#define print(arg0,...) _Generic((arg0), _TYPE_OF_A* : A_print_name(arg0,##__VA_ARGS__), _TYPE_OF_B* : B_print_name(arg0,##__VA_ARGS__))(arg0,##__VA_ARGS__)

//#define set(arg0,...) _Generic((arg0), _TYPE_OF_A* : A_set_name(arg0,##__VA_ARGS__), _TYPE_OF_B * : B_set_name(arg0,##__VA_ARGS__))(arg0,##__VA_ARGS__)

#define set(arg0,...) _Generic((arg0), _TYPE_OF_A* : A_set_name(arg0,##__VA_ARGS__), _TYPE_OF_B * : B_set_name(arg0,##__VA_ARGS__))(arg0,##__VA_ARGS__)

#define delete(arg0,...) _Generic((arg0), _TYPE_OF_A* :A_delete_name(arg0,##__VA_ARGS__), _TYPE_OF_B* :B_delete_name(arg0,##__VA_ARGS__)) (arg0,##__VA_ARGS__)

#define new(type,...) (PASTE(type,_new_name)(__VA_ARGS__))(__VA_ARGS__)

#endif // OVERLOAD_H
