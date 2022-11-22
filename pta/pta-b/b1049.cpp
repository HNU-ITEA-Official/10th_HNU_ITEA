#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n ; cin >> n ;
    long double sum = 0 ;
    for(int i = 0 ; i < n ; i ++){
        double x ; cin >> x ;
        sum += x * (i + 1) * (n - i) ;
    }
    printf("%.2Lf",sum);
}