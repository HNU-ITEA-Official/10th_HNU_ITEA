#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n , x ; cin >> n >> x ;
    vector<ll> sum(n + 1 , 0);
    for(ll i = 0 ; i < n ; i ++){
        ll t ; cin >> t ;
        sum[i + 1] = sum[i] + t ;
    }
    ll min_x = 100000010 ;
    for(ll i = 0 ; i < n ; i ++){
        ll t = lower_bound(begin(sum) + i + 1 , end(sum), x + sum[i]) - begin(sum);
        if(t <= n && sum[t] - sum[i] == x){
            min_x = x ;
            break ;
        }
        else if(t <= n){
            min_x = min(min_x , sum[t] - sum[i]) ;
        }
    }
    for(ll i = 0 ; i < n ; i ++){
        ll t = lower_bound(begin(sum) + i + 1 , end(sum) , min_x + sum[i]) - begin(sum) ;
        if(sum[t] - sum[i] == min_x){
            printf("%lld-%lld\n",i + 1 , t ) ;
        }
    }
}