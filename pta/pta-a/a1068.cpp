#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n , m ; cin >> n >> m ;
    vector<int> price(n ) ;
    for(auto &x : price)    cin >> x ;
    sort(begin(price) , end(price)) ;
    vector<int> dp(m + 1 , -1) ;
    dp[0] = 0 ;
    vector<vector<int> > ans(m + 1) , cnt(m + 1 , vector<int>(110 , 0)) ;
    for(int i = 0 ; i < size(price) ; i ++) cnt[0][price[i]] ++ ; 
    for(int i = 1 ; i < m + 1 ;  i ++) cnt[i] = cnt[0] ; 
    for(int i = 1 ; i <= m ; i ++){
        for(int j = 0 ; j < n ; j ++){
            if(price[j] > i)    break ;
            if(cnt[i - price[j]][price[j]] == 0)    continue ;
            if(dp[i - price[j]] + 1 >= dp[i] && dp[i - price[j]] > -1){
                dp[i] = dp[i - price[j]] + 1 ;
                vector<int> temp = ans[i - price[j]] ; temp.push_back(price[j]) ;
                if(empty(ans[i])){
                    tie(ans[i] , cnt[i]) = pair{temp , cnt[i - price[j]]} ;
                    cnt[i][price[j]] -- ;
                }
                else if(size(temp) > size(ans[i])){
                    tie(ans[i] , cnt[i]) = pair{temp , cnt[i - price[j]]} ;
                    cnt[i][price[j]] -- ;
                }
                else if(temp < ans[i]){
                    tie(ans[i] , cnt[i]) = pair{temp , cnt[i - price[j]]} ;
                    cnt[i][price[j]] -- ;
                }
            }
        }
    }
    if(empty(ans[m]))   
        cout << "No Solution" ;
    else
        for(int i = 0 ; i < size(ans[m]) ; i ++){
            cout << ans[m][i] ;
            if(i != size(ans[m]) - 1)   cout << " " ;
        }

}