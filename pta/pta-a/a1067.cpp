#include <bits/stdc++.h>
using namespace std ;
using ll = long long ;

void swap(vector<ll> &num , ll a ){
    ll t = num[0] ; num[0] = num[a] ; num[a] = t ;
}

int main()
{
    ios::sync_with_stdio(false) ;
    cin.tie(nullptr) ;
    ll n ; cin >> n ;
    vector<ll> num(n) ;
    for(ll i = 0 ; i < n ; i ++){
        ll t ; cin >> t ; num[t] = i ;
    }
    ll cnt = n - 1 , suc = 0 ;
    for(ll i = 1 ; i < n ; i ++){
        if(num[i] == i) {
            cnt -- ; suc ++ ; 
        }
    }
    ll t = 1 ;
    while(suc < n - 1){
        if(num[0] != 0){
            swap(num , num[0]) ;
            suc ++ ;
        } 
        else{
            while(num[t] == t){
                t ++ ;
            }
            swap(num , t) ;
            cnt ++ ;
        }
    }
    cout << cnt ;
}