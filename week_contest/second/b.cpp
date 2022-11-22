#include <stdio.h>

int main()
{
    int num[20] ;
    int n ; scanf("%d",&n) ;
    int cnt = 0 ;
    while(n > 0){
        num[cnt ++] = n % 10 ;
        n /= 10 ;
    }
    int left = 0 ;
    while(num[left] == 0)    left ++ ;
    for(int i = left ; i < cnt ; i ++)
        printf("%d",num[i]) ;
}