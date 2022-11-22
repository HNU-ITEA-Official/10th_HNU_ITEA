#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string str ; cin >> str ;
    vector<ll> nums , cnt(10 , 0) ;
    for(ll i = 0 ; i < size(str) ; i ++){
        nums.push_back(str[i] - '0') ;
        cnt[str[i] - '0'] ++ ;
    }
    for(ll i = 0 ; i < size(nums) ; i ++)
        nums[i] *= 2 ;
    for(ll i = size(nums) - 1 ; i > 0 ; i --)
        tie(nums[i] , nums[i - 1]) = pair{nums[i] % 10 , nums[i] / 10 + nums[i - 1]} ;
    ll first = 0 ;
    tie(nums[0] , first) = pair{nums[0] % 10 , nums[0] / 10} ;
    if(first > 0)
        cnt[first] -- ;
    for(ll i = 0 ; i < size(nums) ; i ++)
        cnt[nums[i]] -- ;
    for(ll i = 0 ; i < 10 ; i ++){
        if(cnt[i] != 0){
            cout << "No\n" ;
             break ;
        }
        if(i == 9)
            cout << "Yes\n" ;
    }
    if(first > 0)
        cout << first ;
    for(ll i = 0 ; i < size(nums) ; i ++)
        cout << nums[i] ;
}