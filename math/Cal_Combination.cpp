#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
template<typename T>
struct Combination {
    vector<T> fact, ifact;
    int max_n;
    // max_n までの階乗を前計算！
    Combination(int _max_n) {
        max_n=_max_n;
        fact.resize(max_n+1);
        ifact.resize(max_n+1);
        fact[0]=1;
        for(int i=0;i<max_n;i++) fact[i+1]=fact[i]*(i+1);
        ifact[max_n]=fact[max_n].inv();
        for(int i=max_n;i>0;--i) ifact[i-1]=ifact[i]*i;
    }

    // nCk を返す（ただし 0<=k<=n<=max_n の範囲で！）
    T nCk(int n,int k)const {
        assert(0<=k);
        assert(k<=n);
        assert(n<=max_n);
        return fact[n]*ifact[k]*ifact[n-k];
    }
    T nHk(int n,int k){
        return nCk(n+1-k,n-1);
    }
    T nPk(int n,int k){
        return fact[n]*ifact[n-k];
    }
};
// ABC145D 
using mint2=modint1000000007;
int main(){
    Combination<mint2> Cbn(200000);
    int H,W;
    cin>>H>>W;
    mint2 ans=0;
    for(int i=0;i<=H;i++){
        if((H-i)%2!=0 || i>H || i*2>W || (W-2*i)!=(H-i)/2)continue;
        int n=(H-i)/2+i;
        ans+=Cbn.nCk(n,i);
    }
    cout<<ans.val();
}