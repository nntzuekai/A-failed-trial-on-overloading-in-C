#include "B.h"

#include <stdio.h>
#include <stdlib.h>

struct B_impl{
	double x;
	double y;
};

void B_set_double_double(B *pb, double x, double y){
	pb->x=x;
	pb->y=y;
}

B *B_new_void()
{
	B *ret_p=(B*)malloc(sizeof(B));
	if(ret_p){
		*ret_p=(B){.x=0, .y=0};
	}
	return ret_p;
}

B *B_new_Bp(B *pb)
{
	B *ret=(B*)malloc(sizeof(B));
	if(ret){
		*ret=*pb;
	}
	return ret;
}

B *B_new_double_double(double x, double y)
{
	B *ret=(B*)malloc(sizeof(B));
	if(ret){
		*ret=(B){.x=x, .y=y};
	}
	return ret;
}

void B_delete(B *pb)
{
	free(pb);
}

void B_print(B *pb)
{
	printf("(%f, %f)\n",pb->x, pb->y);
}

B *B_new_double(double d)
{
	B *ret=(B*)malloc(sizeof(B));
	if(ret){
		*ret=(B){.x=d, .y=d};
	}
	return ret;
}

void B_set_double(B *pb, double d)
{
	pb->x=pb->y=d;
}

void B_set_Bp(B *pb, B *rhs)
{
	*pb=*rhs;
}
