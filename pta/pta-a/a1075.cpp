#include <stdio.h>
#include <algorithm>
#define N 100010
using namespace std ;

struct player
{
    int id ;
    int total ;
    int suc ;
    int cnt ;
    int sor[10] ;
    int rank ;
    bool ac[10] ;
}pla[N] ;
int ques[10] ;

void init(struct player *a , int n )
{
    for(int i = 1 ; i <= n ; i ++){
        a[i].total = 0 , a[i].suc = 0 , a[i].id = i , a[i].cnt = 0  ;
        for(int j = 0 ; j < 10 ; j ++){
            a[i].sor[j] = -1 ;  
            a[i].ac[j] = false ;
        }
    }
}
bool cmp(struct player a , struct player b)
{
    if(a.total != b.total)
        return a.total >b.total ;
    else if(a.suc != b.suc)
        return a.suc > b.suc ;
    else 
        return a.id < b.id ;
}

int main()
{
    int n , k , m ;
    scanf("%d %d %d",&n, &k , &m) ;
    init(pla , n) ;
    for(int i = 1 ; i <= k ; i ++){
        scanf("%d",&ques[i]) ;
    }
    for(int i = 0 ; i < m ; i ++){
        int id , num , sorce ;
        scanf("%d %d %d",&id , &num , &sorce) ;
        if(pla[id].sor[num] == -1 )
            pla[id].sor[num] = 0 ;
        if(sorce >= 0){
            pla[id].cnt ++ ;
            if(sorce == ques[num] && pla[id].ac[num] == false){
                pla[id].suc ++ ;
                pla[id].ac = true ;
            }
            if(sorce > pla[id].sor[num]){
                pla[id].total += sorce - pla[id].sor[num] ;
                pla[id].sor[num] = sorce ;
            }
        }
    }
    sort(pla + 1 , pla + n + 1 , cmp) ;
    pla[1].rank = 1 ;
    for(int i = 2 ; i <= n ; i ++){
        if(pla[i].total == pla[i - 1].total)
            pla[i].rank = pla[i - 1].rank ;
        else   
            pla[i].rank = i ;
    }
    for(int i = 1 ; i <= n ; i ++){
        if(pla[i].cnt > 0 ){
            printf("%d %05d %d ",pla[i].rank , pla[i].id , pla[i].total ) ;
            for(int j = 1 ; j <= k ; j ++){
                if(pla[i].sor[j] >= 0)
                    printf("%d",pla[i].sor[j]) ;
                else
                    printf("-") ;
                if(j != k )
                    printf(" ") ;
            }
            printf("\n") ;
        }
    }
}