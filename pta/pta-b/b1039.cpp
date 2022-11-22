#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char str[10010] ;
int hash[10010] = {0} ;
bool flag = true ; 

int main()
{
    scanf("%s",str) ;
    int len = strlen(str) ;
    int more = len , few = 0 ;
    for(int i = 0 ; i < len ; i ++){
        hash[str[i]] ++ ;
    }
    scanf("%s",str) ;
    len = strlen(str) ;
    for(int i = 0 ; i < len ; i ++){
        if(hash[str[i]] > 0){
            more -- ;
            hash[str[i]] -- ;
        }
        else{
            few ++ ;
            flag = false ;
        }
    }
    if(flag == false){
        printf("No %d",few) ;
    }
    else{
        printf("Yes %d",more) ;
    }
}