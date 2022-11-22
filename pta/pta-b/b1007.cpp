#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n ; cin >> n ;
    vector<ll> prime(n , 0) ; ll q = 0 ;
    vector<bool> p(n + 1 , false) ;
    for(ll i = 2 ; i <= n ; i ++){
        if(p[i] == false){
            prime[q ++] = i ;
            for(ll j = i + i ; j <= n ; j += i){
                p[j] = true ;
            }
        }
    }
    ll ans = 0 ;
    for(ll i = 0 ; i < q ; i ++){
        if(i == 0 && prime[1] > 0){
            ans ++ ;
            i ++ ;
        } 
        else if((prime[i + 1] - prime[i]) == 2){
            ans ++ ;
            i ++ ;
        }
    } 
    cout << ans ;
}