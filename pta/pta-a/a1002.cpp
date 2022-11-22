#include <stdio.h>
#define N 1010

int n , ind ;
double coe , pol[N] = {0} ; 

int main()
{
    int cnt = 0 ;
    for(int i = 0 ; i < 2 ; i ++){
        scanf("%d",&n );
        for(int j = 0 ; j < n ; j ++){
            scanf("%d %lf",&ind,&coe) ;
            if(pol[ind] == 0){
                if(pol[ind] + coe != 0)
                    cnt ++ ;
            }
            else
                if(pol[ind] + coe == 0)
                    cnt -- ;
            pol[ind] += coe ;
        }
    }
    printf("%d",cnt) ;
    if(cnt > 0)
        printf(" ") ;
    for(int i = 1000 ; i >= 0 ; i --){
        if(pol[i] != 0){
            printf("%d %.1lf", i , pol[i] );
            cnt -- ;
            if(cnt > 0)
                printf(" ");
        }
    }
    printf("\n") ;
}