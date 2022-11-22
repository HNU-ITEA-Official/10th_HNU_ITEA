#include <stdio.h>
#define N 100010

int n , Low , High ;
struct student
{
    int id ;
    int ds ;
    int cs ;
    int total ;
}stu1[N] , temp , stu2[N] , stu3[N] , stu4[N] ;

void sort(struct student a[] , int l , int r)
{
    if(l == r)      return ;
    int x = a[(l + r) / 2 ].total , i = l - 1 , j = r + 1 ;
    while(i < j){
        do ++ i ; while(a[i].total > x) ;
        do -- j ; while(a[j].total < x) ; 
        if(i < j){
            struct student t = a[i] ;
            a[i] = a[j] ;
            a[j] = t ;
        }
    }
    sort(a , l , j ) , sort(a , j + 1 , r ) ;
}
void sort1(struct student a[] , int l , int r)                   //总分排序后进行德分的排序
{
    if(l == r)      return ;
    int x = a[(l + r) / 2 ].ds , i = l - 1 , j = r + 1 ;
    while(i < j){
        do ++ i ; while(a[i].ds > x) ; 
        do -- j ; while(a[j].ds < x) ; 
        if(i < j){
            struct student t = a[i] ;
            a[i] = a[j] ;
            a[j] = t ;
        }
    }
    sort1(a , l , j ) , sort1(a , j + 1 , r ) ;
}
void sort2(struct student a[] , int l , int r)                   //德分排序后对准考证号的排序
{
    if(l == r)      return ;
    int x = a[(l + r) / 2 ].id , i = l - 1 , j = r + 1 ;
    while(i < j){
        do ++ i ; while(a[i].id < x) ; 
        do -- j ; while(a[j].id > x) ; 
        if(i < j){
            struct student t = a[i] ;
            a[i] = a[j] ;
            a[j] = t ;
        }
    }
    sort1(a , l , j ) , sort1(a , j + 1 , r ) ;
}
void Sort(struct student a[] , int n)                            //找到每个总分相同的部分
{
    int l = 0 ;
    while(l < n){
        if(a[l].total == a[l + 1].total){                       
            int left = l ;                                      
            while(a[l].total == a[l + 1].total){                
                l ++ ;
            }
            sort1(a , left , l ) ;
            while(left < l){
                if(a[left].ds == a[left + 1].ds){
                    int le = left ;
                    while(a[left].ds == a[left + 1].ds){
                        left ++ ;
                    }
                    sort2(a , le , left) ;
                }
                left ++ ;
            }
        }
        l ++ ; 
    }
}

int main()
{
    int q = 0 , w = 0 , e = 0 , s = 0 ;
    scanf("%d %d %d",&n , &Low , &High) ;
    for(int i = 0 ; i < n ; i ++){
        scanf("%d %d %d",&temp.id , &temp.ds , &temp.cs) ;
        temp.total = temp.ds + temp.cs ;
        if(temp.ds >= High && temp.cs >= High ){
            stu1[q ++] = temp ;
        }
        else if(temp.ds >= High && temp.cs < High && temp.cs >= Low){
            stu2[w ++] = temp ;
        }
        else if(temp.ds < High && temp.cs < High && temp.ds >= temp.cs && (temp.ds >= Low && temp.cs >= Low)){
            stu3[e ++] = temp ;
        }
        else if(temp.ds >= Low && temp.cs >= Low){
            stu4[s ++] = temp ;
        }
    }
    if(q > 0){
        sort(stu1 , 0 , q - 1 ) , Sort(stu1 , q - 1 ) ;
    }
    if(w > 0){
        sort(stu2 , 0 , w - 1 ) , Sort(stu2 , w - 1 ) ;
    }
    if(e > 0){
        sort(stu3 , 0 , e - 1 ) , Sort(stu3 , e - 1 ) ;
    }
    if(s > 0){
        sort(stu4 , 0 , s - 1 ) , Sort(stu4 , s - 1 );
    }

    printf("%d\n",q + w + e + s) ;
    for(int i = 0 ; i < q ; i ++)
        printf("%d %d %d\n",stu1[i].id , stu1[i].ds , stu1[i].cs) ;
    for(int i = 0 ; i < w ; i ++)
        printf("%d %d %d\n",stu2[i].id , stu2[i].ds , stu2[i].cs) ;
    for(int i = 0 ; i < e ; i ++)
        printf("%d %d %d\n",stu3[i].id , stu3[i].ds , stu3[i].cs) ;
    for(int i = 0 ; i < s ; i ++)
        printf("%d %d %d\n",stu4[i].id , stu4[i].ds , stu4[i].cs) ;
}