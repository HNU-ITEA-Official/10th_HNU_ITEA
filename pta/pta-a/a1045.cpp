#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int max_ ; cin >> max_ ;
    int n ; cin >> n ; vector<int> seq(max_ + 1 , 0) ;
    for(int i = 0 ; i < n ; i ++){
        int x ; cin >> x ;
        seq[x] = i + 1 ;  
    }
    int m ; cin >> m ; vector<int> nums ;
    for(int i = 0 ; i < m ; i ++){
        int x ; cin >> x ;
        if(seq[x] > 0){
            nums.push_back(seq[x]) ;   
        }
    }
    int ans = 1 ;
    vector<int> dp(size(nums) , 1) ;
    for(int i = 1 ; i < size(nums) ; i ++){
        for(int j = 0 ; j < i ; j ++){
            if(nums[i] >= nums[j] && dp[j] + 1 > dp[i]){
                dp[i] = dp[j] + 1 ;
            }
        }
        ans = max(ans , dp[i]) ;
    }
    cout << ans ;
}