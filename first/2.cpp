#include <stdio.h>

int main()
{
    int n ; scanf("%d",&n) ;
    int nums[1000000] ;
    for(int i = 0 ; i < n ; i ++)
        scanf("%d",&nums[i]) ;
    for(int i = 0 ; i < n / 2 ; i ++){
        int t = nums[i] ;
        nums[i] = nums[n - 1 - i] ;
        nums[n - 1 - i] = t ;
    }
    for(int i = 0 ; i < n ; i ++)
        printf("%d ",nums[i]) ;
}