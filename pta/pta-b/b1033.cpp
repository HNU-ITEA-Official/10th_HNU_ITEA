#include <stdio.h>
#include <string.h>
#define N 100010
using namespace std ;

int main()
{
    bool hash[256] ;
    char str[N] ;
    gets(str) ;
    memset(hash , true , sizeof(hash)) ;
    int len = strlen(str) ;
    for(int i = 0 ; i < len ; i ++){
        if(str[i] >= 'A' && str[i] <= 'Z'){
            str[i] = str[i] + 'a' - 'A' ;
        }
        hash[str[i]] = false ;
    } 
    gets(str) ;
    len = strlen(str) ;
    for(int i = 0 ; i < len ; i ++){
        if(str[i] >= 'A' && str[i] <= 'Z'){
            int t = str[i] - 'A' + 'a' ;
            if(hash['+'] == true && hash[t] == true ){
                printf("%c",str[i]) ;
            }
        }
        else if(hash[str[i]] == true){
            printf("%c",str[i]) ;
        }
    }
    printf("\n") ;
}