#include <stdio.h>

int main()
{
    int n ; scanf("%d",&n) ;
    int cnt = 0 , num = 2 , ans = 0 ;
    while(cnt < n){
        for(int i = 2 ; i <= num ; i ++){
            if(num % i == 0){
                if(i == num){
                    cnt ++ ;
                    ans += num ;                    
                }    
                else{
                    break ;
                }
            }
        }
        num ++ ;
    }
    printf("%d",ans) ;
}