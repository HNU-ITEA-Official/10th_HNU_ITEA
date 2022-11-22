#include <stdio.h>
#include <string.h>

char account[1010][20] ;
char password[1010][20] ;
char t[1010][20] ;

int main()
{
    int n , cnt = 0 ;
    scanf("%d",&n) ; 
    for(int i = 0 ; i < n ; i ++){
        scanf("%s %s",account[i] , password[i]) ;
        strcpy(t[i] , password[i]) ;
        for(int u = 0 ; u < strlen(password[i]) ; u ++){
            if(password[i][u] == '1')
                password[i][u] = '@' ;
            if(password[i][u] == '0')
                password[i][u] = '%' ;
            if(password[i][u] == 'l')
                password[i][u] = 'L' ;
            if(password[i][u] == 'O')
                password[i][u] = 'o' ;
        }
        if(strcmp(t[i] , password[i]) != 0 ){
            cnt ++ ;
        }
    }
    if(cnt == 0){
        if(n == 1)
            printf("There is 1 account and no account is modified") ;
        else
            printf("There are %d accounts and no account is modified",n) ; 
    }
    else{
        printf("%d\n",cnt) ;
        for(int i = 0 ; i < n ; i ++){
            if(strcmp(t[i] , password[i]) != 0)
                printf("%s %s\n",account[i] , password[i]) ;
        }
    }
}