#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n ; cin >> n ;
    string str;
    for(ll i = 0 ; i < n ; i ++){
        cin >> str;
        bool flag = true ;
        ll l = - 1 , r = - 1 ;
        for(ll i = 0 ; i < size(str) ; i ++){
            if(str[i] == 'P' && l == -1)
                l = i ;
            else if(str[i] == 'P' && l != -1){
                cout << "NO" << '\n' ;
                flag = false ;
                break ;
            }
        }
        for(ll i = 0 ; i < size(str) ; i ++){
            if(str[i] == 'T' && r == -1)
                r = i ;
            else if(str[i] == 'T' && r != -1){
                cout << "NO" << '\n' ;
                flag = false ;
                break ;
            }
        }
        if(!flag)
            continue ;
        if(r - l <= 1){
            cout << "NO" << '\n' ;
            continue ;
        }
        ll len = r - l - 1 ;
        for(ll i = l + 1 ; i < r ; i ++){
            if(str[i] != 'A'){
                flag = false ;
                cout << "NO" << '\n' ;
                break ;
            }
        }
        if(!flag)
            continue ;
        if(len * l != (size(str) - 1 - r)){
            cout << "NO" << '\n' ;
            continue ;
        }
        for(ll i = 0 ; i < l ; i ++){
            if(str[i] != 'A'){
                cout << "NO" << '\n';
                flag = false ;
                break ;
            }
        }
        if(!flag){
            continue ;
        }
        for(ll i = r + 1 ; i < size(str) ; i ++){
            if(str[i] != 'A'){
                cout << "NO" << '\n' ;
                flag = false ;
                break ;
            }
        }
        if(!flag){
            continue ;
        }
        cout << "YES" << '\n' ;
    } 
}
