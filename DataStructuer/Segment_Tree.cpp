#include <bits/stdc++.h>
using namespace std;
template <class S, S(*op)(S,S), S(*e)()> struct segtree{
    vector<S> d;
    int size;
    int N;
    int log;
    //log計算
    int ceil_pow2(int n) {
        int x = 0;
        while ((1U << x) < (unsigned int)(n)) x++;
        return x;
    }
    void update(int p){
        d[p]=op(d[p*2],d[p*2+1]);
    }
    segtree(int n){
        log = ceil_pow2(n);
        size = 1 << log;
        d.resize(size*2+1,e());
        N=n;
    }
    void set(int p,S x){
        assert(0<=p && p<N);
        p+=size;
        d[p]=x;
        for(int i=1;i<=log;i++){
            update(p>>i);
        }
        return;
    }
    S get(int p){
        assert(0<=p && p<N);
        return d[p+size];
    }
    S prod(int l,int r){
        assert(0<=l && l<=r && r<=N);
        S sml=e();
        S smr=e();
        l+=size;
        r+=size;
        while(l<r){
            if(l & 1){
                sml=op(sml,d[l++]);
            }
            if(r & 1){
                smr = op(d[--r], smr);
            }
            l >>=1;
            r >>=1;
        }
        return op(sml,smr);
    }
    S all_prod(){
        return d[1];
    }
    void print(){
        for(int i=0;i<N;i++){
            cout<<d[size+i]<<" ";
        }
        cout<<'\n';
    }
};
using ll=long long;
ll op(ll a,ll b){
    return max(a,b);
}
ll e(){
    return 0;
}
int main(){
  int N,Q;
  cin>>N>>Q;
  segtree<ll,op,e> a(N);
  for(int i=0;i<N;i++){
    ll ai;
    cin>>ai;
    a.set(i,ai);
  }
  for(int i=0;i<Q;i++){
    int t,p,x;
    cin>>t>>p>>x;
    if(t==0){
      a.set(p,a.get(p)+x);
    }else{
      cout<<a.prod(p,x)<<'\n';
    }
  }
}