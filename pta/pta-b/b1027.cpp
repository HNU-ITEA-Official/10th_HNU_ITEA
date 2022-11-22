#include <stdio.h>

int n ;
char a ;

int main()
{
    scanf("%d %c",&n,&a) ;
    int t = 1 ;
    while( !(n >= 2 * t * t - 1 && n < 2 * (t + 1) * (t + 1 ) - 1) ){
        t ++ ;
    }
    for(int i = 0 ; i < t - 1 ; i ++){
        for(int j = 0 ; j < i ; j ++)               printf(" ") ;
        for(int j = 0 ; j < 2 * t - 1 - 2 * i ; j ++)   printf("%c",a) ;
        printf("\n") ;
    }
    for(int i = 0 ; i < t ; i ++){
        for(int j = 0 ; j < t - 1 - i ; j ++)           printf(" ") ;
        for(int j = 0 ; j < 1 + 2 * i ; j ++)       printf("%c",a) ;
        printf("\n") ;
    }
    printf("%d",n - 2 * t* t + 1 ) ; 
}