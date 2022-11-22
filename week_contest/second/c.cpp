#include <stdio.h>
#include <string.h>

int main(){
    char pla[25][25];
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 0 ; i < n ; i ++){
        for(int j = 0 ; j < n ; j ++)
            pla[i][j] = ' ' ;
    }
    int jg=(n-2-m)/(m+1);
    for(int i=0;i<n;i+=(jg+1)){
        for(int j=0;j<n;j++){
            pla[i][j]='*';
            pla[j][i]='*';
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%c",pla[i][j]);
        }
        printf("\n");
    }
    return 0;
}