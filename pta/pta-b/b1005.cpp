#include <stdio.h>
#include <algorithm>
using namespace std ;

int Hash[10010] = {0} ;

bool cmp(int a , int b)
{
    return a > b ;
}

int main()
{
    int n , nums[110] ;
    scanf("%d",&n) ;
    for(int i = 0 ; i < n ; i ++){
        scanf("%d",&nums[i]) ;
        int t = nums[i] ;
        while(t != 1){
            if(t % 2 == 0){
                t = t / 2 ;
                Hash[t] ++ ;
            }
            else {
                t = (t * 3 + 1 ) / 2 ;
                Hash[t] ++ ;
            }
        }
    } 
    int u = 0 , num[110] = {0} ;
    for(int i = 0 ; i < n ; i ++){
        if(Hash[nums[i]] == 0){
            num[u ++] = nums[i] ;
        }
    }
    sort(num , num + u , cmp) ;
    for(int i = 0 ; i < u ; i ++){
        printf("%d",num[i]) ;
        if(i != u - 1)
            printf(" ") ;
    }
}