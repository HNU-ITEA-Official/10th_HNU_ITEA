#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n ; cin >> n ; ll temp = n ;
    if(n < 4){
        cout << n << '=' << n;
        return 0 ;
    }
    vector<pair<ll , ll> > cnt ;
    for(ll i = 2 ; i * i <= n ; i ++){
        ll t = 0 ;
        while(temp % i == 0){
            tie(temp , t) = pair{temp / i , t + 1} ;
        }
        if(t > 0)
            cnt.push_back({i , t}) ;
    }
    cout << n << '=' ;
    for(ll i = 0 ; i < size(cnt) ; i ++){
        if(cnt[i].second == 1)
            cout << cnt[i].first ;
        else if(cnt[i].second > 1)
            cout << cnt[i].first << "^" << cnt[i].second ;
        if(i != size(cnt) - 1)
            cout << "*" ;
    } 
}