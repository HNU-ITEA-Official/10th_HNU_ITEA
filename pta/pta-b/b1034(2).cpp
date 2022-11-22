#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void simplify(vector<ll> &a)
{
    ll t = gcd(labs(a[0]) , a[1]) ;
    a[0] /= t , a[1] /= t ;
}

void Operator(vector<vector<ll> > &a)
{
    string seq = "+-*/" ;
    for(ll i = 0 ; i < 4 ; i ++){
        if(seq[i] == '+')   {a[2][0] = a[0][0] * a[1][1] + a[0][1] * a[1][0] ; a[2][1] = a[0][1] * a[1][1] ;}
        if(seq[i] == '-')   {a[2][0] = a[0][0] * a[1][1] - a[0][1] * a[1][0] ; a[2][1] = a[0][1] * a[1][1] ;}
        if(seq[i] == '*')   {a[2][0] = a[0][0] * a[1][0] ; a[2][1] = a[0][1] * a[1][1] ;}
        if(seq[i] == '/')   {a[2][0] = a[0][0] * a[1][1] ; a[2][1] = a[0][1] * a[1][0] ;}
        simplify(a[2]) ;
        if(a[2][1] < 0)     {a[2][0] *= -1 ; a[2][1] *= -1 ;}
        for(ll j = 0 ; j < 3 ; j ++){
            if(seq[i] == '/' && j == 2 && a[j][1] == 0 ){
                cout << "Inf" ;
            }
            else if(a[j][0] == 0)    cout << 0 ;
            else{
                if(a[j][0] < 0) cout << "(" ;
                if(labs(a[j][0]) >= a[j][1]){
                    cout << a[j][0] / a[j][1] ;
                    if(labs(a[j][0]) % a[j][1])
                        cout << " " << labs(a[j][0]) % a[j][1] << "/" << a[j][1] ;
                }
                else
                    cout << a[j][0] << "/" << a[j][1] ;
                if(a[j][0] < 0) cout << ")" ;
            }
            if(j == 0)  cout << " " << seq[i] << " " ;
            if(j == 1)  cout << " = " ;
            if(j == 2)  cout << '\n' ;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<vector<ll> > nums(3 , vector<ll>(2)) ;
    char temp ; cin >> nums[0][0] >> temp >> nums[0][1] >> nums[1][0] >> temp >> nums[1][1] ;
    simplify(nums[0]) , simplify(nums[1]) ;
    Operator(nums) ;
}