#include<bits/stdc++.h>
#include<atcoder/convolution>
#include<atcoder/modint>
using namespace std;
using namespace atcoder;
using mint=modint998244353;
//Pの逆元Gの先頭n項目までを計算する
vector<mint> InvFPS(const vector<mint>& P,int n){
    int siz=P.size();
    vector<mint> G(1);
    G[0]=P[0].inv();
    G.reserve(n*2);
    for(int m=1;m<n;m<<=1){
        vector<mint> F(min(siz,2*m));
        for(int i=0;i<(int)F.size();i++){
            F[i]=P[i];
        }
        vector<mint> H=convolution(F,G);
        if(H.size()>2*m)H.resize(2*m);
        vector<mint> err(m);
        for(int i=0;i<m;i++){
            if(m+i<(int)H.size()){
                err[i]=H[i+m];
            }
        }
        vector<mint> corr=convolution(err,G);
        for(int i=0;i<m;i++){
            if(i<(int)corr.size()){
                G.emplace_back(-corr[i]);
            }
        }
    }
    G.resize(n);
    return G;
}
int main(){
    int N;
    cin>>N;
    vector<mint> A(N);
    for(int i=0;i<N;i++){
        int a;
        cin>>a;
        A[i]=a;
    }
    auto ans=InvFPS(A,N);
    for(int i=0;i<N;i++){
        cout<<ans[i].val()<<" ";
    }
}