#include <stdio.h>
#include <algorithm>
#define N 100010
using namespace std ;

struct student
{
    int id ;
    int sor[4] ;
}stu[N] ;

char obj[5] = "ACME" ;
int now ;
int Rank[10000000][4] = {0} ;

bool cmp(struct student a , struct student b)
{
    return a.sor[now] > b.sor[now] ;
}

int main()
{
    int n , m ; 
    scanf("%d %d",&n,&m) ;
    for(int i = 0 ; i < n ; i ++){
        stu[i].sor[0] = 0 ;
        scanf("%d",&stu[i].id) ;
        for(int j = 1 ; j < 4 ; j ++){
            scanf("%d",&stu[i].sor[j]) ;
            stu[i].sor[0] += stu[i].sor[j] ;
        }
        stu[i].sor[0] = (int)(stu[i].sor[0] / 3.0 + 0.5) ;
    }
    for(now = 0 ; now < 4 ; now ++){
        sort(stu , stu + n , cmp) ;
        Rank[stu[0].id][now] = 1 ;
        for(int i = 1 ; i < n ; i ++){
            if(stu[i].sor[now] == stu[i - 1].sor[now]){
                Rank[stu[i].id][now] = Rank[stu[i - 1].id][now] ;
            }
            else{
                Rank[stu[i].id][now] = i + 1 ;
            }
        }
    }
    for(int i = 0 ; i < m ; i ++){
        int t ;
        scanf("%d",&t);
        if(Rank[t][0] == 0)     printf("N/A\n") ;
        else{
            int q = 0 ;
            for(int j = 1 ; j < 4 ; j ++){
                if(Rank[t][j] < Rank[t][q]){
                    q = j ;
                }
            }
            printf("%d %c\n",Rank[t][q], obj[q]) ;
        }
    }
}