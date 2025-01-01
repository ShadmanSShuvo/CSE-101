#include <stdio.h>

int main(){
	int i,j,k,l,x,y,n,c=0;
	scanf("%d", &n);
	int a[n], b[n];

	for(i=0; i<n; i++){
		scanf("%d", &a[i]);
	}

	for(j=0; j<n; j++){
		scanf("%d", &b[j]);
	}

	for(k=0; k<n; k++){
		for(l=k+1; l<n; l++){
			for(x=0; x<n; x++){
				for(y=x+1; y<n; y++){
					if(a[k]==b[x] && a[l]==b[y]) c++;
				}
			}

		}
	}

	printf("%d\n", c);

}