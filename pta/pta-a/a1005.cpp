#include <stdio.h>
#include <string.h>

char eng[10][10] = {"zero","one","two","three","four","five","six","seven","eight","nine"} ;
char n[200] ;
int Sum[200] ;

int main()
{
    scanf("%s",n) ;
    int sum = 0 ;
    for(int i = 0 ; i < strlen(n) ; i ++){
        sum += n[i] - '0' ;
    } 
    if(sum == 0)
        printf("zero") ;
    else{
        int u = 0 ;
        while(sum > 0){
            Sum[u ++] = sum % 10 ;
            sum /= 10 ;
        }
        for(int i = u - 1 ; i >= 0 ; i --){
            printf("%s",eng[Sum[i]]) ;
            if(i != 0)
                printf(" ") ;
        }
    }
}