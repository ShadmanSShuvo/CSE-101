#include<stdio.h>

int main(int argc, char const *argv[])
{
    int n, count=0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if((j%2)) {printf("%d",j%2);}
            else {printf("%d", !(j%2));}
        }
        printf("\n");
        
    }
    
    return 0;
}
