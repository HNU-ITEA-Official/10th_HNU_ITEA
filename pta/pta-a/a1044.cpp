#include <stdio.h>
#define N 100010

int search(long long *a , int l , int r , int x)
{
    while(l < r){
        int mid = l - (l - r) / 2 ;
        if(a[mid] < x)
            l = mid + 1 ;
        else
            r = mid ;
    }
    return l ;
}

int main()
{
    int n , x ;
    scanf("%d %d",&n , &x) ;
    long long num[N] , sum[N] = {0} ;
    for(int i = 0 ; i < n ; i ++){
        scanf("%lld",&num[i]) ;
        sum[i + 1] = sum[i] + num[i] ;
    }
    long long late = sum[n] ;
    for(int i = 0 ; i < n ; i ++){
        int j = search(sum , i , n , sum[i] + x) ;
        if(sum[j] - sum[i] == x){
            late = x ;
            break ;
        }
        else if(sum[j] - sum[i] < late + x && sum[j] - sum[i] > x) {
            late = sum[j] - sum[i] ;
        }
    }
    for(int i = 0 ; i < n ; i ++){
        int j = search(sum , i , n , sum[i] + late) ;
        if(sum[j] - sum[i] == late){
            printf("%d-%d\n",i + 1 , j );
        }
    }
}