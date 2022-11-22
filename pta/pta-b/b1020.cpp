#include <stdio.h>

struct mooncake
{
    double sto ;
    double price ;
    double pri ;
}cake[1010] ;

void sort(struct mooncake a[] , int l , int r)
{
    if(l == r)      return ; 
    int i = l - 1 , j = r + 1 ;
    double x = a[(l + r) / 2].pri ;
    while(i < j){
        do ++ i ; while(a[i].pri < x) ;
        do -- j ; while(a[j].pri > x) ;
        if(i < j){
            struct mooncake t = a[i] ;
            a[i] = a[j] ;
            a[j] = t ;
        }
    }
    sort(a , l , j) , sort(a , j + 1 , r) ;
}

int main()
{
    int n , need ;
    scanf("%d %d",&n , &need) ; 
    for(int i = 0 ; i < n ; i ++)
        scanf("%lf",&cake[i].sto) ;
    for(int i = 0 ; i < n ; i ++){
        scanf("%lf",&cake[i].price) ;
        cake[i].pri = cake[i].price / cake[i].sto ;
    }  
    sort(cake , 0 , n - 1 ) ;
    double total = 0 , t = 0 ;
    for(int i = n - 1 ; i >= 0 ; i --){
        if(t + cake[i].sto >= need){
            total += (need - t) * cake[i].pri ;
            break ;
        }
        else{
            t += cake[i].sto ;
            total += cake[i].price ;
        }
    }
    printf("%.2lf",total) ;
}
