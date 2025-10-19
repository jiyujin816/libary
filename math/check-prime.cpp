#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
template<typename T> 
T pow_mod(T a,T b,T m){
    T ret=1%m;
    a%=m;
    while(b){
        if(b & 1){
            ret=(ret*a)%m;
        }
        a=(a*a)%m;
        b>>=1;
    }
    return ret;
}
bool MillerRabin(ll N,ll a){
    ll s=0,d=N-1;
    while(d%2==0){
        ++s;
        d>>=1;
    }
    if(N<=a){
        return true;
    }
    ll t,x=pow_mod<__int128_t>(a,d,N);
    if(x!=1){
        for(t=0;t<s;++t){
            if(x==N-1){
                break;
            }
            x=__int128_t(x)*x%N;
        }
        if(t==s){
            return false;
        }
    }
    return true;
}
bool isprime(ll num){
    if(num<=1){
        return false;
    }
    if(num==2){
        return true;
    }
    if(num%2==0){
        return false;
    }
    vector<ll> ex_a={2, 7, 61};
    vector<ll> ex_a2={2, 325, 9375, 28178, 450775, 9780504, 1795265022};
    if(num<4759123141LL){
        for(ll a:ex_a){
            if(!MillerRabin(num,a)) return false;
        }
    }else{
        for(ll a:ex_a2){
            if(!MillerRabin(num,a)) return false;
        }
    }
    return true;
}
//YosupoOnlineJudge PrimalityTest
int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll Q;
    cin>>Q;
    for(int i=0;i<Q;i++){
        ll N;
        cin>>N;
        if(isprime(N)){
            cout<<"Yes"<<'\n';
        }else{
            cout<<"No"<<"\n";
        }
    }
}