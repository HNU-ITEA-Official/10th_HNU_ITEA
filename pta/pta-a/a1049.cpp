#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n ; cin >> n ;
    ll cnt = 0 , q = 0 , p = n ;
    while(p > 0){
        q ++ ;
        p /= 10 ;
    }
    for(ll i = 1 ; i <= q ; i ++){
        ll t = pow(10 , i) ;
        cnt += n / t * (t / 10) ;
        if(n / (t / 10) % 10 == 1){
            cnt += n - n / (t / 10) * (t / 10) + 1 ;
        }
        else if(n / (t / 10) % 10 > 1){
            cnt += t / 10 ;
        }
    }
    cout << cnt ;
}