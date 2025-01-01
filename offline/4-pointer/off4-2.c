/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby,
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>


int main()
{
	int n;
	scanf("%d", &n);
	int *p;
	p=(int*)malloc(n*sizeof(int));
	for(int i=0; i<n; i++) {
		scanf("%d", (p+i));
	}
	/*
	 for(int i=0; i<n; i++){
	     printf("%d ", *(p+i));
	 }
	 */
	int *f;
	f=(int*)calloc(10001, sizeof(int));
	for(int i=0; i<n; i++) {
		(*(f+*(p+i)))++;
	}
	
	int max=0;
	for(int i=0; i<10001; i++){
	    if(max<(*(f+i))) 
	        max=*(f+i);
	}
	
	for(int i=0; i<10001; i++){
	    if(*(f+i)==max)
	    printf("%d ", i);
	}
	
	
	return 0;
}