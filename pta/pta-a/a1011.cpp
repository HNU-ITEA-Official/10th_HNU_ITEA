#include <stdio.h>

char vd[5] = "WTL" ; 

int main()
{
    double nums[5] ;
    double max[5] = {0} ;
    int sub[5] ; 
    for(int i = 0 ; i < 3 ; i ++ ){
        scanf("%lf %lf %lf",&nums[0],&nums[1],&nums[2]) ; 
        for(int j = 0 ; j < 3 ; j ++){
            if(nums[j] > max[i]){
                max[i] = nums[j] ; 
                sub[i] = j ;
            }
        }
    }
    for(int i = 0 ; i < 3 ; i ++){
        printf("%c ",vd[sub[i]]) ;
    }
    double a = 1 ;
    for(int i = 0 ; i < 3 ; i ++){
        a *= max[i] ;
    }
    printf("%.2lf",(a * 0.65 - 1 ) * 2 ) ;
}