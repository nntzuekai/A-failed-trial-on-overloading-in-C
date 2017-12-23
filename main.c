#include <stdio.h>
#include <stdlib.h>

#include "A.h"
#include "B.h"
#include "Args_Cnt.h"
#include "Overload.h"

int main(void){
	A *pa=new(A,114,514);
	print(pa);
	set(pa,1);
	print(pa);

	A *pa2=new(A);
	set(pa,114,514);
	set(pa2,pa);
	print(pa);
	print(pa2);
	delete(pa);
	delete(pa2);

	pa=new(A,114,514);
	print(pa);
	set(pa,100);
	pa2=new(A,314159);
	delete(pa2);
	pa2=new(A,pa);
	print(pa);
	delete(pa);

	B *b=new(B,114,514);
	print(b);
	delete(b);

	b=new(B,114);
	print(b);
	delete(b);

	b=new(B);
	print(b);
	delete(b);

	b=new(B,3.14159);
	B *b2=new(B,b);
	print(b);
	print(b2);

	set(b,114,514);
	set(b2,b);
	print(b);
	print(b2);

	set(b,0,0);
	print(b);

	delete(b);
	delete(b2);
}

