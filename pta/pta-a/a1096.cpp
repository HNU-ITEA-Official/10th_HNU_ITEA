#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n , max_len = 0 , l , r ; cin >> n ;
    for(ll i = 2 ; i * i <= n ; i ++){
        ll t = 1 , j = i ;
        while(n % (t * j) == 0){
            tie(t , j) = pair{t * j , j + 1} ;
        }
        if(j - i > max_len)
            tie(l , r , max_len) = tuple{i , j - 1 , j - i} ;
    }
    if(max_len == 0){
        cout << 1 << '\n' << n ;
        return 0 ; 
    }
    cout << max_len << "\n" ;
    for(ll i = l ; i <= r ; i ++){
        cout << i ;
        if(i != r)  cout << "*" ;
    }
}