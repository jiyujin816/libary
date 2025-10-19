#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep1(a)          for(ll i = 0; i < a; ++i)
#define rep2(i, a)       for(ll i = 0; i < a; ++i)
#define rep3(i, a, b)    for(ll i = a; i < b; ++i)
#define rep4(i, a, b, c) for(ll i = a; i < b; i += c)
#define overload4(a, b, c, d, e, ...) e
#define rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)
ll BSGS(ll x,ll y,ll mod){
    ll m=sqrt(mod);
    x%=mod;
    y%=mod;
    set<int> S;
    vector<int> vecS(m);
    ll iv=1;
    {
        ll k=mod-2;
        ll po=x;
        while(k>0){
            if(k&1){
                iv*=po;
                iv%=mod;
            }
            po*=po;
            po%=mod;
            k>>=1;
        }
    }
    ll yxi=y;
    ll xm=1;
    rep(i,m){
        S.insert(y);
        vecS[i]=y;
        y*=iv;
        y%=mod;
        xm*=x;
        xm%=mod;
    }
    ll xim=1;
    rep(i,mod/m+1){
        if(S.contains(xim)){
            rep(j,m){
                if(vecS[j]==xim){
                    return i*m+j;
                }
            }
        }
        xim*=xm;
    }
    return -1;
}
