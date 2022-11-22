#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct num
{
    bool flag ;
    ll nu[2] ;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n ; cin >> n ;
    vector<num> nums(n) ;
    ll all_lcm = 1 , sum = 0 ;
    for(ll i = 0 ; i < n ;  i ++){
        string t ; cin >> t ;
        ll q = 0 ;
        if(t[q] == '-'){
            nums[i].flag = false ;
            q ++ ;
        }
        else
            nums[i].flag = true ;
        for(ll j = 0 ; j < 2 ; j ++ , q ++){
            ll num = 0 ;
            while(q < size(t) && t[q] != '/'){
                num = num * 10 + t[q] - '0' ;
                q ++ ;
            }
            nums[i].nu[j] = num ;
            if(j == 1)  all_lcm = lcm(all_lcm , num) ;
        }
    }
    for(ll i = 0 ; i < n ; i ++){
        if(nums[i].flag == true)
            sum += nums[i].nu[0] * (all_lcm / nums[i].nu[1]) ;
        else
            sum -= nums[i].nu[0] * (all_lcm / nums[i].nu[1]) ;
    }
    if(sum == 0)
        cout << 0 ;
    bool flag = false ;
    if(labs(sum) >= all_lcm){
        cout << sum / all_lcm ;
        flag = true ;
    }
    if(labs(sum - sum / all_lcm * all_lcm) > 0){
        if(flag == true)
            cout << " " ;
        ll ans = sum - sum / all_lcm * all_lcm ;
        cout << ans / gcd(ans , all_lcm) << "/" << all_lcm / gcd(ans , all_lcm) ;
    }
}