#include <stdio.h>

char digit[5] = "BS" ;
int n ; 

int main()
{
    int nums[10] , q = 0 ;
    scanf("%d",&n) ;
    while(n > 0){
        nums[q ++] = n % 10 ;
        n /= 10 ;
    }
    for(int i = q - 1 ; i >= 1 ; i --){
        for(int j = 0 ; j < nums[i] ; j ++){
            printf("%c",digit[2 - i]) ;
        }
    }
    for(int i = 1 ; i <= nums[0] ; i ++){
        printf("%d",i) ;
    }
}