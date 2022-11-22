#include <stdio.h>
#include <algorithm>
#define N 100010
using namespace std ;

bool cmp(int a , int b)
{
    return a > b ;
}

int main()
{
    int n ; 
    scanf("%d",&n) ;
    int num1[N] , unum1[N] , u1 = 0 , un1 = 0 ;
    for(int i = 0 ; i < n ; i ++){
        int t ;
        scanf("%d",&t) ;
        if(t < 0){
            unum1[un1 ++] = t ;
        }
        else{
            num1[u1 ++] = t ;
        }
    }
    sort(num1 , num1 + u1 , cmp) , sort(unum1 , unum1 + un1) ;
    scanf("%d",&n) ;
    int num2[N] , unum2[N] , u2 = 0 , un2 = 0 ;
    for(int i = 0 ; i < n ; i ++){
        int t ;
        scanf("%d",&t) ;
        if(t < 0){
            unum2[un2 ++] = t ;
        }
        else{
            num2[u2 ++] = t ;
        }
    } 
    sort(num2 , num2 + u2 , cmp) , sort(unum2 , unum2 + un2) ;
    int sum = 0 ;
    int len = (u1 < u2) ? u1 : u2 ;
    for(int i = 0 ; i < len ; i ++){
        sum += num1[i] * num2[i] ;
    }
    len = (un1 < un2) ? un1 : un2 ;
    for(int i = 0 ; i < len ; i ++){
        sum += unum1[i] * unum2[i] ;
    }
    printf("%d",sum) ;
}
