#include <stdio.h>
#include <algorithm>
#define N 100010
using namespace std ;

int main()
{
    int n , m ; 
    scanf("%d %d",&n , &m) ;
    int coin[N] ;
    for(int i = 0 ; i < n ; i ++){
        scanf("%d",&coin[i]) ;
    }
    sort(coin , coin + n ) ;
    int l = 0 , r = n - 1 ;
    while(l < r){
        if(coin[l] + coin[r] > m)
            r -- ;
        else if(coin[l] + coin[r] == m)
            break ;
        else
            l ++ ;
    }
    if(l == r)
        printf("No Solution") ;
    else
        printf("%d %d",coin[l] , coin[r] ) ;
} 