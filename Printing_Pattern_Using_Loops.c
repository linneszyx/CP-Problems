#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

    int n;
    scanf("%d", &n);
    int l = n*2-1;
  	// Complete the code to print the pattern.
    int i,j;
    for (i=0;i<l;i++)
    {
        for ( j=0;j<l;j++)
        {
            int k = i<j ? i : j;
            k = k<l-i?k:l-i-1;
            k = k<l-j-1?k:l-j-1;
            printf("%d ",n-k);
        }
        printf("\n");
        
    }
    
    return 0;
}