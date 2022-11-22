#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll a , b ; cin >> a >> b ;
    ll sum = a + b ;
    if(sum < 0){
        cout << " " ;
        sum *= -1 ;
    }
    vector<ll> t ;
    if(sum == 0){
        cout << "0" ;
    }
    while(sum > 0){
        t.push_back(sum % 10) ;
        sum /= 10 ;
    }
    ll j = 0 ;
    for(j = 0 ; j < t.size() % 3 ; j ++){
        cout << t[t.size() - 1 - j] ;
    }
    ll cnt = 0 ;
    for(ll i = j ; i < t.size() ; i ++){
        if(cnt % 3 == 0 && i != 0)
            cout << "," << t[t.size() - 1 - i] ;
        cnt ++ ;
    }
}