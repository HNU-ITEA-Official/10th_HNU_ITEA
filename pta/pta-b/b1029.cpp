#include <stdio.h>
#include <string.h>
#include <iostream>
#include <stdbool.h>
#define N 1010 
using namespace std ;

char str[N] ;
char str1[N] ;
int Hash[256] = {0} ;
bool flag[256] ;

int main()
{
    memset(flag , true , 256) ;
    cin.getline(str , N) ;
    int len = strlen(str) ;
    for(int i = 0 ; i < len ; i ++){
        if(str[i] >= 'a' && str[i] <= 'z'){
            str[i] = str[i] - 'a' + 'A' ;
        }
        Hash[str[i]] ++ ;
    }
    cin.getline(str1 , N) ;
    int len1 = strlen(str1) ;
    for(int i = 0 ; i < len1 ; i ++){
        if(str1[i] >= 'a' && str1[i] <= 'z'){
            str1[i] = str1[i] - 'a' + 'A' ;
        }
        Hash[str1[i]] -- ;
    }
    for(int i = 0 ; i < len ; i ++){
        if(Hash[str[i]] > 0 && flag[str[i]] == true){
            flag[str[i]] = false ;            
            printf("%c",str[i]) ;

        } 
    }
}