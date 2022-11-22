#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll calcual(vector<ll> &a , ll d)
{
    ll sum = 0 ;
    for(ll i = 0 ; i < size(a) ; i ++)
        sum = sum * d + a[i] ;
    return sum ;
}
bool is_prime(ll n)
{
    if(n < 2)   return false ;
    for(ll i = 2 ; i * i <= n ; ++i)
        if(n % i == 0)  return false ;
    return true ;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n , d ;
    while(cin >> n && n >= 0){
        cin >> d ;
        if(!is_prime(n)){
            cout << "No\n" ;
            continue ;
        }
        vector<ll> digit ;
        while(n > 0){
            digit.push_back(n % d) ;
            n /= d ;
        }
        if(is_prime(calcual(digit , d)))
            cout << "Yes\n" ;
        else
            cout << "No\n" ;
    }
}