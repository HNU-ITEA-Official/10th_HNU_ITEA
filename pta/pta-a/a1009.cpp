#include <stdio.h>
#define N 2010

int n , ind[N] ;
double pol[N] = {0} , coe[N] ;

int main()
{
    scanf("%d", &n) ;
    for(int i = 0 ; i < n ; i ++){
        scanf("%d %lf", &ind[i] , &coe[i] ) ;
    }
    int a ;
    double b ;
    int m ; 
    scanf("%d",&m) ;
    for(int i = 0 ; i < m ; i ++ ){
        scanf("%d %lf", &a , &b) ;
        for(int j = n ; j >= 0 ; j --){
            pol[ a + ind[j] ] += b * coe[j] ; 
        }
    }
    int cnt = 0 ;
    for(int i = 2000 ; i >= 0 ; i --){
        if(pol[i] != 0)
            cnt ++ ;
    }
    printf("%d",cnt) ;
    if(cnt > 0 )    printf(" ") ;
    for(int i = 2000 ; i >= 0 ; i --){
        if(pol[i] != 0 ){
            printf("%d %.1lf", i , pol[i] ) ;
            cnt -- ;
            if(cnt > 0 )
                printf(" ") ; 
        }
    }
}