#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int max_ ; cin >> max_ ;
    int n ; cin >> n ; vector<int> nums1(n) ;
    for(auto &x : nums1)
        cin >> x ;
    int m ; cin >> m ; vector<int> nums2(m) ;
    for(auto &x : nums2)
        cin >> x ;
    vector<vector<int> > dp(n + 1 , vector<int>(m + 1 , 0)) ;
    for(int i = 0 ; i < n ; i ++){
        for(int j = 0 ; j < m ; j ++){
            if(nums1[i] == nums2[j]){
                dp[i + 1][j + 1] = dp[i + 1][j] + 1 ;
            }
            else
                dp[i + 1][j + 1] = max(dp[i][j + 1] , dp[i + 1][j]) ;
        }
    }
    cout << dp[n][m] ;
}