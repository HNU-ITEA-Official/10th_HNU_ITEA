#include <stdio.h>
#include <algorithm>

int num[10] = {0} ;

int main()
{
    for(int i = 0 ; i < 10 ; i ++){
        scanf("%d",&num[i]) ;
    }
    for(int i = 1 ; i < 10 ; i ++){
        if(num[i] > 0){
            printf("%d",i) ;
            num[i] -- ;
            break ;
        }
    }
    for(int i = 0 ; i < 10 ; i ++){
        if(num[i] > 0){
            for(int j = 0 ; j < num[i] ; j ++){
                printf("%d",i) ;
            }
        }
    }
}