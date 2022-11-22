#include <stdio.h>

int main()
{
    long long n ; scanf("%d",&n) ;
    long long ans = 1 ;
    if(n == 0){
        printf("1\n") ;
        return 0 ;
    }
    for(int i = 1 ; i <= n ; i ++)
        ans *= i ;
    printf("%d\n",ans) ;
}