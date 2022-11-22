#include <stdio.h>
#include <stdbool.h>

int n ;
struct persen 
{
    char id[20] ; 
    int unl_hh , unl_mm , unl_ss ;
    int l_hh , l_mm , l_ss ;
}earliest , lastest , temp ;

bool earlier(struct persen a , struct persen b )
{
    if(a.unl_hh != b.unl_hh)            return a.unl_hh < b.unl_hh ;
    else if(a.unl_mm != b.unl_mm)       return a.unl_mm < b.unl_mm ;
    else                                return a.unl_ss < b.unl_ss ;
}
bool later(struct persen a , struct persen b )
{
    if(a.l_hh != b.l_hh)                return a.l_hh > b.l_hh ;
    else if(a.l_mm != b.l_mm)           return a.l_mm > b.l_mm ;
    else                                return a.l_ss > b.l_ss ;
}

int main()
{
    earliest.unl_hh = earliest.unl_mm = earliest.unl_ss = 24 ;
    lastest.l_hh = lastest.l_mm = lastest.l_ss = 0 ;
    scanf("%d",&n) ; 
    for(int i = 0 ; i < n ; i ++){
        scanf("%s %d:%d:%d %d:%d:%d",temp.id , &temp.unl_hh,&temp.unl_mm , &temp.unl_ss , &temp.l_hh , &temp.l_mm , &temp.l_ss ) ; 
        if( earlier(temp,earliest) ){
            earliest = temp ;
        }
        if( later(temp,lastest) ){
            lastest = temp ;
        }
    }
    printf("%s %s",earliest.id , lastest.id ) ; 
}