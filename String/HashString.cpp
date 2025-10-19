#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct HashString{
    int N;
    string s;
    vector<ll> p1,p2,ip1,ip2;
    vector<pair<ll,ll>> h,rh;
    constexpr ll mod1=998244353;
    constexpr ll mod2=79020979;
    constexpr ll R1=2092427;
    constexpr ll R2=870083;
    ll modpow(ll x, int n, ll M){
        ll res = 1;
        while(n){
            if(n & 1) res=res*x%M;
            x=x*x%M;
            n>>=1;
        }
        return res;
    }
    HashString(const string& str)
        : N(str.size()), s(str),
          p1(N+1),p2(N+1),ip1(N+1),ip2(N+1),
          h(N+1,{0,0}), rh(N+1,{0,0})
    {
        ll inv1 = modpow(R1, mod1-2, mod1);
        ll inv2 = modpow(R2, mod2-2, mod2);
        p1[0]=1;p2[0]=1;
        ip1[0]=1;ip2[0]=1;
        for(int i=0;i<N;i++){
            p1[i+1]=p1[i]*R1%mod1;
            p2[i+1]=p2[i]*R2%mod2;
            ip1[i+1]=ip1[i]*inv1%mod1;
            ip2[i+1]=ip2[i]*inv2%mod2;
        }
        for(int i=0;i<N;i++){
            h[i+1].first=(h[i].first+(ll)s[i]*p1[i])%mod1;
            h[i+1].second=(h[i].second+(ll)s[i]*p2[i])%mod2;
        }
        for(int i=0;i<N;i++){
            char c=s[N-1-i];
            rh[i+1].first=(rh[i].first+(ll)c*p1[i])%mod1;
            rh[i+1].second=(rh[i].second+(ll)c*p2[i])%mod2;
        }
    }
    pair<ll,ll> substr_hash(int l,int r){
        ll x = (h[r].first-h[l].first+mod1)%mod1;
        ll y = (h[r].second-h[l].second+mod2)%mod2;
        x=x*ip1[l]%mod1;
        y=y*ip2[l]%mod2;
        return {x,y};
    }
    pair<ll,ll> substr_rev(int l,int r){
        int L=N-r;
        int R=N-l;
        ll x=(rh[R].first-rh[L].first+mod1) % mod1;
        ll y=(rh[R].second-rh[L].second+mod2) % mod2;
        x=x*ip1[L]%mod1;
        y=y*ip2[L]%mod2;
        return {x,y};
    }
    bool is_palindrome(int l,int r){
        return substr_hash(l,r)==substr_rev(l,r);
    }
    friend istream& operator>>(istream& is, HashString& hs){
        string tmp;
        is>>tmp;
        hs = HashString(tmp);
        return is;
    }
};

//鉄則演習問題集B56
int main(){
    int N,Q;
    cin>>N>>Q;
    string S;
    cin>>S;
    HashString HS(S);
    for(int i=0;i<Q;i++){
        int l,r;
        cin>>l>>r;
        l--;r--;
        if(HS.is_palindrome(l,r+1)){
            cout<<"Yes";
        }else{
            cout<<"No";
        }
        cout<<'\n';
    }
}