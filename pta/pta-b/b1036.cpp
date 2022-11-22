#include <stdio.h>

int n ;
char a ; 

int main()
{
    scanf("%d %c",&n,&a) ;
    int l ; 
    if(n % 2 == 1)      l = n / 2 + 1 ;
    else                l = n / 2 ; 
    for(int i = 0 ; i < l ; i ++){
        if( i == 0 || i == l - 1 ){
            for(int j = 0 ; j < n ; j ++){
                printf("%c",a) ;
            }
        }
        else{
            for(int j = 0 ; j < n ; j ++){
                printf("%c",(j == 0 || j == n - 1) ? a : ' ') ;
            }
        }
        printf("\n") ; 
    }
}