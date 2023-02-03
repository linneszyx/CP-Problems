#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include<adshlp.h>
int main() {

    char s;
    int i;
    int arr[] = {0,0,0,0,0,0,0,0,0,0};
    while (scanf("%c",&s)==1)
    {
        if(s>='0' && s<='9')
        {
            arr[s-'0']+=1;
        }
    }
    for (int i = 0; i < 10; i++)
    {
        printf("%d ",arr[i]);
    }
    
    
    
    return 0;
}
