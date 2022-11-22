#include <stdio.h>

char word[100][100] ;

int main()
{
    int i = 0 ;
    while(scanf("%s",word[i]) != EOF){
        i ++ ;
    }
    for(int j = i - 1 ; j >= 0 ; j --){
        printf("%s",word[j]) ;
        if(j != 0)
            printf(" ") ;
    }
}
