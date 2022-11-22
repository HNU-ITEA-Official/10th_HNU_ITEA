#include <stdio.h>
#include <algorithm>
#define N 100010
using namespace std ;

int main()
{
    long long n , p ;
    scanf("%lld %lld",&n , &p) ;
    long long num[N] ;
    for(int i = 0 ; i < n ; i ++)
        scanf("%lld",&num[i]) ;
    sort(num , num + n ) ;
    long long l = 0 , r = 0 , len = 1 ;
    for(int l = 0 ; l < n ; l ++){
        while(num[r] <= p * num[l]){    
            r ++ ;
            if(r == n)
                break ;
        }
        if(r - l > len)
            len = r - l ;
        if(r == n)
            break ;
    }
    printf("%d",len) ;
}