#include <stdio.h>
#include <string.h>
#define N 100010

int cntP[N] = {0} , cntT[N] = {0} ;
char word[N] ;

int main()
{
    scanf("%s",word) ;
    int len = strlen(word) ;
    int t = 0 ; 
    for(int i = 0 ; i < len ; i ++){
        if(word[i] == 'P')
            cntP[i + 1] = cntP[i] + 1 ;
        else
            cntP[i + 1] = cntP[i] ;
    }
    for(int i = len - 1 ; i >= 0 ; i --){
        if(word[i] == 'T')
            cntT[i - 1] = cntT[i] + 1 ;
        else    
            cntT[i - 1] = cntT[i] ;
    }
    for(int i = 1 ; i < len - 1 ; i ++){
        if(word[i] == 'A'){
            t += cntP[i] * cntT[i] ;
            t %= 1000000007 ;
        }
    }
    printf("%d",t ) ;
}