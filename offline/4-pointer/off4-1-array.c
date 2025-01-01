#include <stdio.h>
#include <string.h>

int main()
{
	char s[100];
	char t[100];
	scanf("%[^\n]s", s);
	int i, j=0, k, cntr;
	i=cntr=strlen(s);



	while(i>1) {
		int c=0; //length of the word
		while(s[i-1]!=' ' && i>0) {
		    printf("i: %d\n",i);
			i--;
			c++;
		}
		printf("c: %d\n",c);

		//shadman shahriyar shuvo

		for(k=i; k<i+c; k++) {
			t[j]=s[k];
			j++;
		}
		t[j]=' ';
		j++;
		
		i--;
		cntr -= (c+1) ;
	}
	t[j]='\n';
	printf("%s\n", t);
	for(int x=0; x<strlen(s); x++) printf("%c",t[x]);
	return 0;
}