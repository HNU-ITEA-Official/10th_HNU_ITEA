#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string str ; ll n ; cin >> str >> n ;
    vector<ll> nums ;
    for(ll i = 0 ; i < size(str) ; i ++)
        nums.push_back(str[i] - '0') ;
    ll rem = 0 ;
    for(ll i = 0 ; i < size(nums) ; i ++){
        if(i == size(nums) - 1){
            tie(nums[i] , rem) = pair{nums[i] / n , nums[i] % n} ;
        }
        else
            tie(nums[i] , nums[i + 1]) = pair{nums[i] / n , nums[i + 1] + 10 * (nums[i] % n)} ;
    }
    if(nums[0] || size(nums) == 1)
        cout << nums[0] ;
    for(ll i = 1 ; i < size(nums) ; i ++){
        cout << nums[i] ;
    }
    cout << " "  << rem ;
}