#include <stdio.h>
#include <algorithm>
#define N 1000010
using namespace std ;

int num[N] ;

int main()
{
    int n , m ;
    scanf("%d",&n) ;
    for(int i = 0 ; i < n ; i ++){
        scanf("%d",&num[i]) ;
    }
    scanf("%d",&m) ;
    for(int i = 0 ; i < m ; i ++){
        scanf("%d",&num[i + n]) ;
    }
    sort(num , num + n + m ) ;
    int mid = (n + m + 1) / 2 ;
    printf("%d",num[mid - 1]) ;
}