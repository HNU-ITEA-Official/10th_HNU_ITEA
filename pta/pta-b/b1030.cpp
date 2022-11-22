#include <stdio.h>
#include <algorithm>
#define N 100010
using namespace std ;

int search(long long *num , int n , long long x)
{
    int l = 0 , r = n - 1 ;
    while(l < r){
        int mid = l - (l - r) / 2 ;
        if(num[mid] <= x && num[mid + 1] > x)
            return mid ;
        else if(num[mid] <= x && num[mid + 1] <= x)
            l = mid + 1 ;
        else if(num[mid] > x && num[mid + 1] > x)
            r = mid ;
    }
    return l ;
}

int main()
{
    long long n , p ; 
    scanf("%lld %lld",&n , &p) ;
    long long num[N] ;
    for(int i = 0 ; i < n ; i ++){
        scanf("%lld",&num[i]) ;
    }
    sort(num , num + n ) ;
    int len = 0 ;
    for(int i = 0 ; i < n ; i ++){
        if(search(num , n , num[i] * p) - i + 1 > len)
            len = search(num , n , num[i] * p) - i + 1 ;
    }
    printf("%d",len) ;
}