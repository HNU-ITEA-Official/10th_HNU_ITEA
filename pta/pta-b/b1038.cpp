#include <stdio.h>
#define N 100010

int sor[200] = {0} ;

int main()
{
    int n ; 
    scanf("%d",&n) ;
    for(int i = 0 ; i < n ; i ++){
        int t ;
        scanf("%d",&t) ;
        sor[t] ++ ;
    }
    scanf("%d",&n) ;
    int search[N] ;
    for(int i = 0 ; i < n ; i ++){
        scanf("%d",search[i]) ;
    }
    for(int i = 0 ; i < n ; i ++){
        printf("%d ",sor[search[i]]) ;
    }
}