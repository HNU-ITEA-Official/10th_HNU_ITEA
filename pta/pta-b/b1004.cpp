#include <stdio.h>
#define N 100010

int n ;
struct student 
{
    char name[20] ;
    char id[20] ;
    int sor ;
}stu[N] ,max , min ;

int main()
{
    scanf("%d",&n) ;
    scanf("%s %s %d",stu[0].name , stu[0].id , &stu[0].sor) ;
    max = stu[0] , min = stu[0] ; 
    for(int i = 1 ; i < n ; i ++){
        scanf("%s %s %d",stu[i].name , stu[i].id , &stu[i].sor) ;
        if(stu[i].sor > max.sor)
            max = stu[i] ;
        if(stu[i].sor < min.sor)
            min = stu[i] ; 
    }
    printf("%s %s\n",max.name,max.id) ;
    printf("%s %s\n",min.name,min.id) ;
}
