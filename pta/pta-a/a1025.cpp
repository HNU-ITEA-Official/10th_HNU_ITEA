#include <stdio.h>
#include <string.h>
#include <algorithm>
#define N 10010 
using namespace std ;

struct player
{
    char id[15] ;
    int sor ;
    int rank ;
    int arank ;
    int room ;
}player[N][N] , total[N] ;

bool cmp(struct player a , struct player b)
{
    if(a.sor != b.sor)
        return a.sor > b.sor ;
    else 
        return strcmp(a.id , b.id) < 0 ;
}

int main()
{
    int _  , to = 0 ;
    scanf("%d",&_) ;
    for(int i = 0 ; i < _ ; i ++){
        int n ; 
        scanf("%d",&n) ;
        for(int j = 0 ; j < n ; j ++){
            scanf("%s %d",player[i][j].id , &player[i][j].sor);
            player[i][j].room = i + 1 ;
        }
        sort(player[i] , player[i] + n , cmp) ;
        player[i][0].rank = 1 ;
        for(int j = 1 ; j < n ; j ++){
            if(player[i][j].sor == player[i][j - 1].sor)        player[i][j].rank = player[i][j - 1].rank ;
            else                                                
                player[i][j].rank = j + 1 ;
        }
        for(int j = 0 ; j < n ; j ++)
            total[to ++] = player[i][j] ;
    }
    sort(total , total + to , cmp);
    total[0].arank = 1 ;
    for(int j = 1 ; j < to ; j ++){
            if(total[j].sor == total[j - 1].sor)        total[j].arank = total[j - 1].arank ;
            else                                                
                total[j].arank = j + 1 ;
        }
    printf("%d\n",to) ;
    for(int i = 0 ; i < to ; i ++){
        printf("%s %d %d %d\n",total[i].id ,total[i].arank , total[i].room , total[i].rank) ;
    }
}   