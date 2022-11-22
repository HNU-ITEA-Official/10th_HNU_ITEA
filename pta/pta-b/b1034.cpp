#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct num
{
    bool flag = true ;
    ll nu[2] ;
};
void sim(struct num &a)
{
    if(a.nu[0] && a.nu[1]){
        ll t = gcd(a.nu[0] , a.nu[1]) ;
        a.nu[0] /= t , a.nu[1] /= t ;
    }
}
void opera(vector<num> &a)
{
    string seq = "+-*/" ;
    for(ll i = 0 ; i < 4 ; i ++){
        for(ll j = 0 ; j < 2 ; j ++){
            if(a[j].nu[0] == 0) cout << 0 ;
            else{
                if(!a[j].flag)  cout << "(-" ;
                if(a[j].nu[0] >= a[j].nu[1]){
                    cout << a[j].nu[0] / a[j].nu[1] ;
                    if(a[j].nu[0] % a[j].nu[1]) cout << " " << a[j].nu[0] % a[j].nu[1] << "/" << a[j].nu[1] ;
                }
                else    cout << a[j].nu[0] << "/" << a[j].nu[1] ;
                if(!a[j].flag)  cout << ")" ;
            }
            if(j != 1)  cout << " " << seq[i] << " " ;
            else        cout << " = " ;
        }
        for(ll j = 0 ; j < 2 ; j ++)
            if(a[j].flag == false)   a[j].nu[0] *= -1 ;
        struct num t ;
        if(seq[i] == '+')   {t.nu[0] = a[0].nu[0] * a[1].nu[1] + a[0].nu[1] * a[1].nu[0] ; t.nu[1] = a[0].nu[1] * a[1].nu[1] ;}
        if(seq[i] == '-')   {t.nu[0] = a[0].nu[0] * a[1].nu[1] - a[0].nu[1] * a[1].nu[0] ; t.nu[1] = a[0].nu[1] * a[1].nu[1] ;}
        if(seq[i] == '*')   {t.nu[0] = a[0].nu[0] * a[1].nu[0] ; t.nu[1] = a[0].nu[1] * a[1].nu[1] ;}
        if(seq[i] == '/')   {t.nu[0] = a[0].nu[0] * a[1].nu[1] ; t.nu[1] = a[0].nu[1] * a[1].nu[0] ;}
        if(t.nu[0] * t.nu[1] < 0){
            t.flag = false ;
            if(t.nu[0] < 0) t.nu[0] *= -1 ;
            else            t.nu[1] *= -1 ; 
        }
        t.nu[0] = labs(t.nu[0]) ; t.nu[1] = labs(t.nu[1]) ;
        if(seq[i] == '/' && a[1].nu[0] == 0){
            cout << "Inf" ;
            return ; 
        }
        if(t.nu[0] == 0){
            cout << 0 << '\n' ;
        }
        else{
            sim(t) ;
            if(!t.flag)     cout << "(-" ;
            if(t.nu[0] >= t.nu[1]){
                cout << t.nu[0] / t.nu[1] ;
                if(t.nu[0] % t.nu[1]) cout << " " << t.nu[0] % t.nu[1] << "/" << t.nu[1] ;
            }
            else    cout << t.nu[0] << "/" << t.nu[1] ;
            if(!t.flag)  cout << ")" ;
            cout << '\n' ;
        }
        for(ll j = 0 ; j < 2 ; j ++)
            if(a[j].flag == false)   a[j].nu[0] *= -1 ;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    char temp ;
    vector<num> nums(2) ;
    cin >> nums[0].nu[0] >> temp >> nums[0].nu[1] >> nums[1].nu[0] >> temp >> nums[1].nu[1] ;
    for(ll i = 0 ; i < 2 ; i ++)
        if(nums[i].nu[0] < 0)   {nums[i].flag = false ; nums[i].nu[0] *= -1 ;}
    sim(nums[0]) , sim(nums[1]) ;
    opera(nums) ;
}