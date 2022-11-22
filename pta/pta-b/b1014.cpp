#include <stdio.h>
#include <string.h>

char day[7][5] = {"MON" , "TUE" , "WED" , "THU" , "FRI" , "SAT" , "SUN"} ;
char str1[100] ,str2[100] ,str3[100] , str4[100] ; 

int main()
{
    scanf("%s",str1) , scanf("%s",str2) ,scanf("%s",str3) ,scanf("%s",str4) ;
    int len = ( (strlen(str1) > strlen(str2) ) ? strlen(str2) : strlen(str1) ) ;
    int flag ;
    for(int i = 0 ; i < len ; i ++){
        if(str1[i] == str2[i] && (str1[i] >= 'A' && str1[i] <= 'Z')){
            int t = str1[i] - 'A' ;
            printf("%s ",day[t % 7]) ;
            flag = i ;
            break ;
        }
    }
    for(int i = flag + 1 ; i < len ; i ++){
        if(str1[i] == str2[i] && (str1[i] >= '0' && str1[i] <= '9')){
            int t = str1[i] - '0' ;
            printf("%02d:",t % 24) ;
            break ;
        }
        if(str1[i] == str2[i] && (str1[i] >= 'A' && str1[i] <= 'Z')){
            int t = str1[i] - 'A' + 10 ;
            printf("%02d:",t % 24) ;
            break ;
        }
    }
    for(int i = 0 ; i < strlen(str3) ; i ++){
        if(str3[i] == str4[i] && ( (str3[i] >= 'A' && str3[i] <= 'Z') || (str3[i] >= 'a' && str3[i] <= 'z') )){
            printf("%02d",i ) ;
            break ;
        }
    }
}