#include <bits/stdc++.h>
using namespace std;
using ll=long long;
struct Eratosthenes{
    ll r;
    vector<ll> min_divi;
    vector<bool> is_p;
    Eratosthenes(ll N){
        r=N;
        min_divi.resize(r+1,-1);
        is_p.resize(r+1,true);
        min_divi[0]=0;
        min_divi[1]=1;
        is_p[0]=false;
        is_p[1]=false;
        for(ll i=2;i*i<=r;i++){
            if(is_p[i]){
                for(ll j=2;i*j<=r;j++){
                    if(is_p[i*j]){
                        is_p[i*j]=false;
                        min_divi[i*j]=min(i,j);
                    }
                }
            }
        }

    }
    bool is_prime(ll n){
        assert(0<=n && n<=r);
        return is_p[n];
    }
    vector<ll> prime_fact(ll n){
        vector<ll> ret;
        while(n!=1){
            if(is_p[n]){
                ret.push_back(n);
                n/=n;
                break;
            }
            ret.push_back(min_divi[n]);
            n/=min_divi[n];
        }
        return ret;
    }
    
};

int main(){
    Eratosthenes et(1e6);
    for(int i=1;i<100;i++){
        cout<<i<<" isprime"<<et.is_prime(i)<<"\n";
    }
}