#include <stdio.h>
#include <algorithm>
#define N 100010
using namespace std ;

int main()
{
    int n ; 
    scanf("%d",&n) ;
    int num[N] ;
    int max[N] = {0} , min[N] = {0} ;
    min[n - 1] = 999999999 ;
    for(int i = 0 ; i < n ; i ++){
        scanf("%d",&num[i]) ;
        if(num[i] > max[i]){
            max[i + 1] = num[i] ;
        }
        else
            max[i + 1] = max[i] ;
    }
    for(int i = n - 1 ; i >= 0 ; i --){
        if(num[i] < min[i]){
            min[i - 1] = num[i] ;
        }
        else
            min[i - 1] = min[i] ;
    }
    int put[N] , u = 0 ;
    for(int i = 0 ; i < n ; i ++){
        if(num[i] > max[i] && num[i] < min[i]){
            put[u ++] = num[i] ;
        }
    }
    sort(put , put + u ) ;
    printf("%d",u) ;
    if(u != 0)
        printf("\n") ;
    for(int i = 0 ; i < u ; i ++){
        printf("%d",put[i]) ;
        if(i != u - 1)
            printf(" ") ;
    }
}