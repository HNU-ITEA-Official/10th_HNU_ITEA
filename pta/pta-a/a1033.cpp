#include <bits/stdc++.h>
using namespace std ;
using ll = long long ;

bool cmp(pair<double , double> a , pair<double , double> b)
{
    return a.second < b.second ;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    double cmax , d , davg , n ; cin >> cmax >> d >> davg >> n ;
    vector<pair<double , double> > sta(n) ;
    for(auto &[p , d] : sta)
        cin >> p >> d ;
    sta.push_back({0 , d}) ;
    sort(begin(sta) , end(sta) , cmp) ;
    double money = 0 , now = 0 , len = cmax * davg ;
    ll t = 0 ; 
    while(sta[t].second < d){
        ll w = t + 1 , q = t + 1 ;
        bool flag = false ;
        while(q <= n && sta[q].second <= sta[t].second + len){
            if(sta[q].first < sta[w].first){
                w = q ;
            }
            flag = true ;
            if(sta[q].first < sta[t].first)
                break ;
            q ++ ;
            flag = true ;
        }
        if(flag == false){
            if(sta[0].second == 0)
                printf("The maximum travel distance = %.2f",sta[t].second + len) ;
            else
                printf("The maximum travel distance = 0.00") ;
            return 0 ;
        }
        else if(w == q){
            money += (sta[w].second - sta[t].second - now) / davg * sta[t].first ;
            now = 0 ;
            t = w ;
        }
        else{
            money += (len - now) / davg * sta[t].first ;
            now = len - (sta[w].second - sta[t].second) ;
            t = w ;
        }
    }
    printf("%.2f",money) ;
}
 