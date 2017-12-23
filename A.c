#include "A.h"

#include <stdlib.h>
#include <stdio.h>

struct A_impl{
	int x;
	int y;
};

void A_set_int_int(A *pa, int x,int y)
{
	pa->x=x;
	pa->y=y;
}

A *A_new_Ap(A *pa)
{
	A *p=(A*)malloc(sizeof(A));
	if(p){
		*p=*pa;
	}
	return p;
}

A *A_new_int_int(int x, int y)
{
	A *p=(A*)malloc(sizeof(A));
	if(p){
		*p=(A){.x=x, .y=y};
	}
	return p;
}

void A_print(A *pa)
{
	printf("(%d, %d)\n",pa->x,pa->y);
}

A *A_new_void()
{
	A *p=(A*)malloc(sizeof(A));
	if(p){
		*p=(A){.x=0, .y=0};
	}
	return p;
}

void A_delete(A *pa)
{
	free(pa);
}

A *A_new_int(int i)
{
	A *p=(A*)malloc(sizeof(A));
	if(p){
		*p=(A){.x=i, .y=i};
	}
	return p;
}

void A_set_int(A *pa, int i)
{
	pa->x=pa->y=i;
}

void A_set_Ap(A *pa, A *rhs)
{
	*pa=*rhs;
}
