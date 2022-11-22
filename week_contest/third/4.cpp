#include<bits/stdc++.h>
using namespace std;

int pow(int a , int b){
    int res = 1 ; 
    for(int i = 0 ; i < b ; i ++){
        res *= a ;
    }
    return res ;
}


int main(){
    for(int i=100;i<1000;i++){
        int a=i/100;
        int b=i/10%10;
        int c=i%10;
        if(pow(a,3)+pow(b,3)+pow(c,3)==i) cout<<i<<endl;
    }
    return 0;
}