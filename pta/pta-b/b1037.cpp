#include <stdio.h>

int g , s , k ;
int gtk(int g , int s , int k)
{
    return (g * 17 + s) * 29 + k ;
}

int main()
{
    scanf("%d.%d.%d",&g,&s,&k) ;
    int mon = gtk(g , s , k ) ;
    scanf("%d.%d.%d",&g,&s,&k) ;
    int t = gtk(g , s , k ) - mon ;
    int nums[5] , divisor[5] = {29 , 17} ;
    for(int i = 0 ; i < 2 ; i ++){
        nums[i] = t % divisor[i] ;
        t /= divisor[i] ;
    }
    nums[2] = t ;
    for(int i = 2 ; i >= 0 ; i --){
        if(nums[i] < 0 && i != 2)     nums[i] *= -1 ;
        printf("%d",nums[i]) ;
        if(i != 0)
            printf(".") ;
    }
}