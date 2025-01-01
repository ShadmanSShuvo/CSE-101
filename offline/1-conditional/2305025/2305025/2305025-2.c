#include<stdio.h>

int main()
{
    int n, c;
    scanf("%d", &n);
    c=n%2;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("%d", c);
            c=!c;
        }
        if(!(i%2)) c=!c;
        printf("\n");
        
        
    }
    
    return 0;
}
