#include <bits/stdc++.h>
#define N 1000010
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n , m ; cin >> n >> m ;
    vector<bool> p(N , false) ;
    vector<ll> prime(m + 1 , 0) ; ll q = 0 ; 
    for(ll i = 2 ; q <= m ; i ++){
        if(p[i] == false){
            prime[q ++] = i ;
            for(ll j = i + i ; j < N ; j += i){
                p[j] = true ;
            }
        }
    }
    ll cnt = 0 ;
    for(ll i = n - 1 ; i < m ; i ++){
        cout << prime[i] ;
        cnt ++ ;
        if(cnt % 10 == 0)
            cout << '\n' ;
        else if(i != m - 1)  
            cout << ' ' ;
    }
}