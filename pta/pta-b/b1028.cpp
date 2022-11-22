#include <stdio.h>
#include <stdbool.h>

struct people
{
    char name[20] ;
    int yy , mm , dd ;
}oldest , youngest , l , r , temp ;

bool lessequ(struct people a , struct people b)
{
    if(a.yy != b.yy)        return a.yy < b.yy ;
    else if(a.mm != b.mm)   return a.mm < b.mm ;
    else                    return a.dd <= b.dd ;
}
bool moreequ(struct people a , struct people b)
{
    if(a.yy != b.yy)        return a.yy > b.yy ;
    else if(a.mm != b.mm)   return a.mm > b.mm ;
    else                    return a.dd >= b.dd ;
}

int main()
{    
    oldest.yy = r.yy = 2014 ;
    youngest.yy = l.yy = 1814 ;
    oldest.mm = r.mm = youngest.mm = l.mm = 9 ;
    oldest.dd = r.dd = youngest.dd = l.dd = 6 ;
    int n , cnt = 0 ;
    scanf("%d",&n) ;
    for(int i = 0 ; i < n ; i ++){
        scanf("%s %d/%d/%d",temp.name , &temp.yy,&temp.mm,&temp.dd) ;
        if(moreequ(temp,l) && lessequ(temp,r)){
            cnt ++ ;
            if(lessequ(temp,oldest)){
                oldest = temp ;
            }
            if(moreequ(temp,youngest)){
                youngest = temp ;
            }
        }
    }
    printf("%d",cnt) ;
    if(cnt > 0 ){
        printf(" ") ;
        printf("%s %s",oldest.name , youngest.name) ;
    }
}