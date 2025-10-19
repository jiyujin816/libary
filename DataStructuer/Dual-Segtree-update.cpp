#include <bits/stdc++.h>
using namespace std;
// It's correct code.
template<typename T> struct DualSegtree{
    using ll=long long;
    int siz;
    int N;
    int log;
    ll cnt=1;
    vector<pair<T,ll>> data;
    int ceil_pow2(int n) {
        int x = 0;
        while ((1U << x) < (unsigned int)(n)) x++;
        return x;
    }
    DualSegtree(){}
    DualSegtree(int n){
        N=n;
        log=ceil_pow2(n);
        siz=1<<log;
        data.resize(siz*2+1,{0,0});
    }
    DualSegtree(int n,T x){
        N=n;
        log=ceil_pow2(n);
        siz=1<<log;
        data.resize(siz*2+1,{x,0});
    }
    DualSegtree(const vector<T> &vec){
        N=(int)vec.size();
        log=ceil_pow2(N);
        siz=1<<log;
        data.resize(siz*2+1);
        for(int i=0;i<N;i++){
            data[i+siz].first=vec[i];
            data[i+siz].second=0;
        }
    }
    void set(int p,T x){
        assert(0<=p && p<N);
        data[p+siz].first=x;
        data[p+siz].second=cnt;
        cnt++;
    }
    void set(int l,int r,T x){
        assert(0<=l && l<=r && r<=N);
        l+=siz;
        r+=siz;
        while(l<r){
            if(l&1){
                data[l].first=x;
                data[l].second=cnt;
                l++;
            }
            if((r&1)){
                data[r-1].first=x;
                data[r-1].second=cnt;
                r--;
            }
            l>>=1;
            r>>=1;
        }
        cnt++;
        return;
    }
    T get(int p){
        assert(0<=p && p<N);
        T ret=data[p+siz].first;
        ll when=data[p+siz].second;
        int idx=p+siz;
        while(idx!=1){
            idx/=2;
            if(data[idx].second>when){
                ret=data[idx].first;
                when=data[idx].second;
            }
        }
        return ret;
    }
};
//AOJ Range Update Query
using ll=long long;
int main(){
    ll N,Q;
    cin>>N>>Q;
    DualSegtree<ll> A(N,2147483647);
    for(int i=0;i<Q;i++){
        int t;
        cin>>t;
        if(t==0){
            int s,t;
            ll x;
            cin>>s>>t>>x;
            A.set(s,t+1,x);
        }else{
            int p;
            cin>>p;
            cout<<A.get(p)<<'\n';
        }
    }
}