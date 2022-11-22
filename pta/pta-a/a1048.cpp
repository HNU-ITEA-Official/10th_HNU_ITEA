#include <stdio.h>
#include <algorithm>
#include <stdbool.h>
#define N 100010
using namespace std ;

bool flag = false ;

int search(int *a , int l , int r , int x)
{
    while(l < r){
        int mid = l - (l - r) / 2 ;
        if(a[mid] < x)
            l = mid + 1 ;
        else
            r = mid ;
    }
    if(a[l] == x)
        return l ;
    return -1 ;
}

int main()
{
    int n , m ;
    scanf("%d %d",&n, &m) ;
    int coin[N] ;
    for(int i = 0 ; i < n ; i ++)
        scanf("%d",&coin[i]) ;
    sort(coin , coin + n ) ;
    for(int i = 0 ; coin[i] <= m / 2 ; i ++){
        int t = search(coin , i + 1 , n - 1 , m - coin[i]) ;
        if(t >= 0){
            flag = true ;
            printf("%d %d\n",coin[i] , coin[t]) ;
            break ;
        }
    }
    if(flag == false)
        printf("No Solution") ;
}