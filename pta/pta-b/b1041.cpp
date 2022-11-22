#include <stdio.h>
#define N 1010 

int n , m ;
struct stude
{
    char num[20] ;
    int id1 ;
    int id2 ;
}stu[N] ;

int main()
{
    scanf("%d",&n ) ;
    for(int i = 0 ; i < n ; i ++){
        scanf("%s %d %d",stu[i].num,&stu[i].id1,&stu[i].id2 ) ;
    }
    int nu ;
    scanf("%d",&m) ; 
    for(int i = 0 ; i < m ; i ++ ){
        scanf("%d",&nu) ;
        for(int j = 0 ; j < n ; j ++){
            if(nu == stu[j].id1){
                printf("%s %d\n",stu[j].num,stu[j].id2) ;
            }
        }
    }
}