#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool cmp (string a , string b)
{
    return a + b < b + a ;
}

int main()
{
    ll n ; cin >> n ;
    string str[n] ;
    for(ll i = 0 ; i < n ; i ++)
        cin >> str[i] ;
    sort(str , str + n , cmp) ;
    while(str[0][0] == '0'){
        str[0].erase(begin(str[0])) ;
    }
    for(ll i = 0 ; i < n ; i ++)
        cout << str[i] ;
}