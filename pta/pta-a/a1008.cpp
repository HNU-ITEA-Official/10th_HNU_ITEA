#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n ; cin >> n ;
    ll beg = 0 , ti = 0 ;
    for(ll i = 0 ; i < n ; i ++){
        ll x ; cin >> x ;
        if(x > beg){
            ti += (x - beg) * 6 + 5 ;
            beg = x ;
        }
        else{
            ti += (beg - x) * 4 + 5 ;
            beg = x ;
        }
    }
    cout << ti ;
}