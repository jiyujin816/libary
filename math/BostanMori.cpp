#include<bits/stdc++.h>
#include<atcoder/convolution>
#include<atcoder/modint>
using namespace std;
using namespace atcoder;
using mint=modint998244353;
//P(x)/Q(x)のn次の係数を求める
mint BostanMori(long long n,vector<mint> P,vector<mint>Q){
    if(n==0){
        return P[0]/Q[0];
    }
    vector<mint> Q_neg=Q;
    for(int i=1;i<int(Q.size());i+=2){
        Q_neg[i]*=-1;
    }
    auto V2=convolution(Q,Q_neg);
    vector<mint> V;
    for(int i=0;i<int(V2.size());i+=2){
        V.push_back(V2[i]);
    }
    auto U=convolution(P,Q_neg);
    if(n&1){
        vector<mint> Uo;
        Uo.reserve(((U.size())>>1)+1);
        for(int i=1;i<int(U.size());i+=2){
            Uo.push_back(U[i]);
        }
        return BostanMori(n>>1,Uo,V);
    }else{
        vector<mint> Ue;
        Ue.reserve(((U.size())>>1)+1);
        for(int i=0;i<int(U.size());i+=2){
            Ue.push_back(U[i]);
        }
        return BostanMori(n>>1,Ue,V);
    }
}
//https://atcoder.jp/contests/abc360/tasks/abc360_e
int main(){
    //dp[i]=(N^2-2N)/N^2*dp[i-1]+2/N^2なので
    //dp[i]=(2N^2-2N)/N^2*dp[i-1]-(N^2-2N)/N^2*dp[i-2]とする
    long long N,K;
    cin>>N>>K;
    if(N==1){
        cout<<1;
        return 0;
    }
    vector<mint> Q(3);
    Q[0]=1;
    Q[1]=-1*mint(2*N*N-2*N)/mint(N*N);
    Q[2]=(mint(N*N)-2*N)/mint(N*N);
    vector<mint> a(2);
    a[0]=1;
    a[1]=mint(N*N-2*N+2)/mint(N*N);
    vector<mint> P=convolution(a,Q);
    while(P.size()>2){
        P.pop_back();
    }
    mint p=BostanMori(K,P,Q);
    mint ans=p;
    ans+=mint(1-p)*mint(N+2)*mint(N-1)/mint(2)/mint(N-1);
    cout<<ans.val();
}