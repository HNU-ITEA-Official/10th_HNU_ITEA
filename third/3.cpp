#include <bits/stdc++.h> 
using namespace std; 
int main()
 { 
		int n , m ; cin >> n >> m ; 
		int nums[100010] ;
		int s[100010] ;
		for(int i = 0 ; i < n ; i ++){
				cin >> nums[i] ;
 				s[i + 1] = s[i] + nums[i] ;
		 } 
		for(int i = 0 ; i < m ; i ++){ 
				int l , r ; cin >> l >> r ; 
				cout << s[r] - s[l - 1] << '\n' ; 
		} 
}