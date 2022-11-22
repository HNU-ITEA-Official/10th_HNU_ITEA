#include <stdio.h>
#include <string.h>

char num[20] = "0123456789JQK" ;
char a[200] , b[200] ;
char str[400] ;

int main()
{
    int u = 0 ;
    scanf("%s %s", a , b) ;
    int lena = strlen(a) , lenb = strlen(b) ;
    int len = (lena > lenb)? lena : lenb ;
    for(int i = 0 ; i < len ; i ++){ 
        if(i % 2 == 0){
            int sum = 0 ;
            if(lena - i - 1 >= 0)   sum += a[lena - 1 - i] - '0' ;
            if(lenb - i - 1 >= 0)   sum += b[lenb - 1 - i] - '0' ;
            sum %= 13 ;
            str[u ++] = num[sum] ;
        }
        else{
            int sum = 0 ;
            if(lena - i - 1 >= 0 )  sum -= a[lena - 1 - i] - '0' ;
            if(lenb - i - 1 >= 0 )  sum += b[lenb - 1 - i] - '0' ;
            if(sum < 0)             sum += 10 ;
            str[u ++] = num[sum] ;
        }
    }
    for(int i = strlen(str) - 1 ; i >= 0 ; i --)
        printf("%c",str[i]) ; 
}