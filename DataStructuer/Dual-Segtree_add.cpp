#include <bits/stdc++.h>
using namespace std;
//It's correct code
template<typename T> struct DualSegtree{
    int siz;
    int N;
    int log;
    vector<T> data;
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
        data.resize(siz*2+1,0);
    }
    DualSegtree(const vector<T> &vec){
        N=(int)vec.size();
        log=ceil_pow2(N);
        siz=1<<log;
        data.resize(siz*2+1);
        for(int i=0;i<N;i++){
            data[i+siz]=vec[i];
        }
    }
    void add(int p,T x){
        assert(0<=p && p<N);
        data[p+siz]+=x;
    }
    void add(int l,int r,T x){
        assert(0<=l && l<=r && r<=N);
        l+=siz;
        r+=siz;
        while(l<r){
            if(l&1){
                data[l]+=x;
                l++;
            }
            if(r&1){
                data[r-1]+=x;
                r--;
            }
            l>>=1;
            r>>=1;
        }
        return;
    }
    T get(int p){
        assert(0<=p && p<N);
        T ret=data[p+siz];
        int idx=p+siz;
        while(idx!=1){
            idx/=2;
            ret+=data[idx];
        }
        return ret;
    }
    void set(int p,T x){
        assert(0<=p && p<N);
        add(p,x-get(p));
        return;
    }
};
using ll=long long;
#define rep(i,N) for(int i=0;i<N;i++)
// ABC388D
int main(){
    ll N;
    cin>>N;
    DualSegtree<ll> A(N);
    rep(i,N){
        ll Ai;
        cin>>Ai;
        A.set(i,Ai);
    }
    rep(i,N){
        A.add(i+1,min(i+1+A.get(i),N),1);
        A.set(i,max((ll)0,A.get(i)-(N-i-1)));
    }
    rep(i,N){
        cout<<A.get(i)<<" ";
    }
}