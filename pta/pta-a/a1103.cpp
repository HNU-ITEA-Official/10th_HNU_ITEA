#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll power(ll a , ll b){
    if(b == 0)
        return 1 ;
    else if(b % 2)
        return a * power(a , b - 1 ) ;
    else
        return power(a * a , b / 2) ;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n , k , p ; cin >> n >> k >> p ;
    vector<ll> ans , temp ;
    ll ind = 1 , max_in = 0 ;
    while(power(ind , p) <= n)
        ind ++ ;
    auto dfs = [&](auto dfs , ll index , ll cnt , ll sum , ll sum_in)->void{
        if(index <= 0)
            return ;
        if(sum >= n || cnt == k){
            if(sum != n || cnt != k)    
                return ; 
            if(sum_in > max_in)
                tie(ans , max_in) = pair{temp , sum_in} ;
            return ; 
        }
        temp.push_back(index) ;
        dfs(dfs , index , cnt + 1 , sum + power(index , p) , sum_in + index) ;
        temp.pop_back() ;
        dfs(dfs , index - 1 , cnt , sum , sum_in) ;
    };
    dfs(dfs , ind - 1 , 0 , 0 , 0) ;
    if (ans.empty())
        cout << "Impossible" << '\n';
    else {
        cout << n << " = ";
        for (int i = 0; i < k; ++i)
            cout << ans[i] << '^' << p << (i + 1 < k ? " + " : "\n");
    }
}