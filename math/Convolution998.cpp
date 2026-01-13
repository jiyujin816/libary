#include<bits/stdc++.h>
#include<atcoder/modint>
using namespace std;
using namespace atcoder;
using mint=modint998244353;
constexpr int base_root=3;
constexpr int mod=998244353;
vector<mint> DFT(vector<mint> A){
    int N=A.size();
    if(N==1){
        return A;
    }else if(N<=16){
        vector<mint> B(N);
        mint g=mint(base_root).pow((mod-1)/N);
        mint p=1;
        for(int i=0;i<N;i++){
            mint cur=1;
            for(int j=0;j<N;j++){
                B[i]+=A[j]*cur;
                cur*=p;
            }
            p*=g;
        }
        return B;
    }
    //N/2でいいらしい
    vector<mint> root(N/2+1);
    root[0]=1;
    root[1]=mint(base_root).pow((mod-1)/N);
    for(int i=2;i<N/2+1;i++){
        root[i]=root[i-1]*root[1];
    }
    vector<mint> B(N);
    vector<mint> even(N/2);
    vector<mint> odd(N/2);
    for(int i=0;i<N;i++){
        if(i&1){
            odd[i>>1]=A[i];
        }else{
            even[i>>1]=A[i];
        }
    }
    even=DFT(even);
    odd=DFT(odd);
    for(int i=0;i<N/2;i++){
        B[i]=even[i]+odd[i]*root[i];
        B[i+N/2]=even[i]-odd[i]*root[i];
    }
    return B;
}
vector<mint> IDFT(vector<mint> B){
    int N=B.size();
    if(N==1){
        return B;
    }else if(N<=16){
        vector<mint> A(N);
        mint g=mint(base_root).pow((mod-1)/N);
        g=g.inv();
        mint p=1;
        for(int i=0;i<N;i++){
            mint cur=1;
            for(int j=0;j<N;j++){
                A[i]+=B[j]*cur;
                cur*=p;
            }
            p*=g;
        }
        mint in=mint(N).inv();
        for(int i=0;i<N;i++){
            A[i]*=in;
        }
        return A;
    }
    vector<mint> root(N/2+1);
    root[0]=1;
    root[1]=mint(base_root).pow((mod-1)/N);
    root[1]=root[1].inv();
    for(int i=2;i<N/2+1;i++){
        root[i]=root[i-1]*root[1];
    }
    vector<mint> A(N);
    vector<mint> even(N/2);
    vector<mint> odd(N/2);
    for(int i=0;i<N;i++){
        if(i&1){
            odd[i>>1]=B[i];
        }else{
            even[i>>1]=B[i];
        }
    }
    even=IDFT(even);
    odd=IDFT(odd);
    mint in=mint(2).inv();
    for(int i=0;i<N/2;i++){
        A[i]=(even[i]+odd[i]*root[i])*in;
        A[i+N/2]=(even[i]-odd[i]*root[i])*in;
    }
    return A;
}
vector<mint> convolution(vector<mint> A,vector<mint> B){
    int N=A.size()+B.size();
    int a=A.size(),b=B.size();
    N--;
    while((N&(N-1))!=0){
        N++;
    }
    while(A.size()!=N){
        A.push_back(0);
    }
    while(B.size()!=N){
        B.push_back(0);
    }
    A=DFT(A);
    B=DFT(B);
    vector<mint> C(N);
    for(int i=0;i<N;i++){
        C[i]=A[i]*B[i];
    }
    C=IDFT(C);
    vector<mint> res(a+b-1);
    for(int i=0;i<a+b-1;i++){
        res[i]=C[i];
    }
    return res;
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N,M;
    cin>>N>>M;
    vector<mint> a(N),b(M);
    for(int i=0;i<N;i++){
        int ai;
        cin>>ai;
        a[i]=ai;
    }
    for(int i=0;i<M;i++){
        int bi;
        cin>>bi;
        b[i]=bi;
    }
    auto c=convolution(a,b);
    for(int i=0;i<N+M-1;i++){
        cout<<c[i].val()<<" ";
    }
}
