#include<bits/stdc++.h> 
using namespace std; 
bool slove(int x){
    int a,b,c,d; 
    a=x/1000;
    b=x/100%10;
    c=x/10%10;
    d=x%10; 
    if(a!=b&&a!=c&&a!=d&&b!=c&&b!=d&&c!=d) 
        return true; 
    else 
        return false; 
} 
int main(){ 
    int a;cin>>a; 
    while(1){ 
        if(slove(++a)){ 
            cout<<a; return 0; 
        }
    }
    return 0; 
}