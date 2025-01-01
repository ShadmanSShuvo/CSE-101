#include<stdio.h>


int main(int argc, char const *argv[])
{
    int a, n, max=-2147483648, min=2147483647, even=0, odd=0, sum=0;
    float avg;

    printf("How many numbers do you want to enter? ");
    scanf("%d", &n);
    printf("Enter %d numbers: ", n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a);
        if (i==1)
        {
            max = min = sum = a ;
        }

        if (a>max) max = a;
        if (a<min) min = a;
        if (i>1) sum = sum + a;
        if(a%2==0) even++;
        else odd++;

        
        
    }

    printf("Minimum Number : %d \nMaximum Number : %d \nSum of all numbers : %d \nAverage : %g \nEven number count : %d \nOdd number count : %d\n", min, max, sum, 1.0*sum/n, even, odd);
    
    return 0;
}
