#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


char* takeArray(int size) {
	char *a;
	a=(char*)malloc(size*sizeof(char));
	return a;
}

void reverseWords(char *a, char *t) {
	int i = strlen(a) - 1;
	int j = 0;
	int c;

	while (i >= 0 && (isspace(*(a+i)))){
		i--;
	}


	while (i >= 0) {
		c = 0;
		while (i >= 0 && !isspace(*(a+i))) {
			i--;
			c++;
		}


		for (int k = i + 1; k <= i + c; k++) {
			*(t+j) = *(a+k);
			j++;
		}


		while (i >= 0 && isspace(*(a+i))) {
			i--;
		}


		if (i >= 0) {
			*(t+j) = ' ';
			j++;
		}
	}


	*(t+j) = '\0';


	printf("\"%s\"\n", t);
}

int main() {
	char *a, *t;
	a = takeArray(1000);
	t = takeArray(1000);
	scanf(" %[^\n]s", a);
    reverseWords(a,t);
	
    free(a);
    free(t);
	return 0;
}
