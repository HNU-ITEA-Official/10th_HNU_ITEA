#include <stdio.h>
#include <string.h>

char str[10000] ;

int main()
{
    int i = 0 ; 
    scanf("%s",str) ;
    if(str[0] == '-')   printf("-") ;
    while(str[i] != 'E') {
        i ++ ;
    }
    int len = i - 3 ;
    int t = 0 ;
    for(int j = i + 2; j < strlen(str) ; j ++){
        t = t * 10 + str[j] - '0'; 
    }
    if(str[i + 1] == '+'){
        if(t >= len){
            printf("%c",str[1]) ;
            for(i = 0 ; i < len ; i ++){
                printf("%c", str[i + 3]) ;
            }
            for(i = 0 ; i < t - len ; i ++){
                printf("0") ;
            }
        }
        else{
            printf("%c",str[1]) ;
            for(i = 0 ; i < t ; i ++){
                printf("%c",str[i + 3]) ;
            }
            printf(".") ;
            for(i ; i < len ; i ++){
                printf("%c",str[i + 3]) ;
            }
        }
    }
    else{
        printf("0.") ;
        for(i = 0 ; i < t - 1 ; i ++){
            printf("0") ;
        }
        printf("%c",str[1]) ;
        for(i = 0 ; i < len ; i ++){
            printf("%c",str[i + 3]) ;
        }
    }
}