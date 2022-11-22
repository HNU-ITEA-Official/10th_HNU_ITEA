#include <stdio.h>
#include <string.h>
#define N 1010 

char str[N] ;
int hash[30] = {0} ;

int main()
{
    scanf("%[^\n]",str) ;
    int len = strlen(str) ;
    for(int i = 0 ; i < len ; i ++){
        if(str[i] >= 'a' && str[i] <= 'z') {
            hash[str[i] - 'a'] ++ ;
        }
        if(str[i] >= 'A' && str[i] <= 'Z'){
            hash[str[i] - 'A'] ++ ;
        }
    }
    int t = 0 ;
    for(int i = 0 ; i < 26 ; i ++){
        if(hash[i] > hash[t]){
            t = i ;
        }
    }
    printf("%c %d",'a' + t , hash[t]) ;
}