#include<stdio.h>
#include<string.h>
#define N 1010

char nums[N] ;
int cnt[10] = {0} ;

int main()
{
    scanf("%s",nums) ;
    for(int i = 0 ; i < strlen(nums) ; i ++){
        cnt[nums[i] - '0'] ++ ;
    }
    for(int i = 0 ; i < 10 ; i ++){
        if(cnt[i] > 0){
            printf("%d:%d\n",i , cnt[i]) ;
        }
    }
}
