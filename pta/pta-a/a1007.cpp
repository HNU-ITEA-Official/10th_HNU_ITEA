#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n ; cin >> n ;
    bool flag = false ;
    vector<ll> get_max(n + 1 , 0) , get_i(n + 1 , 1) , nums(n + 1 , 0);
    for(ll i = 1 ; i <= n ; i ++){
        cin >> nums[i] ;
        if(nums[i] >= 0)    flag = true ;
        if(get_max[i - 1] >= 0){
            get_max[i] = get_max[i - 1] + nums[i] ;
            get_i[i] = get_i[i - 1] ;
        }
        else{
            get_max[i] = nums[i] ;
            get_i[i] = i ;
        }
    }
    if(!flag){
        cout << 0 << " " << nums[1] << " " << nums[size(nums) - 1] ;
        return 0 ; 
    }
    ll t = 1 ; 
    for(ll i = 2 ; i <= n ; i ++){
        if(get_max[i] > get_max[t]){
            t = i ; 
        } 
    }
    cout << get_max[t] << " " << nums[get_i[t]] << " " << nums[t] ;
}