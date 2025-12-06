//https://github.com/jiyujin816/libary
//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <atcoder/all>
//多倍長整数
/*
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>
namespace mp = boost::multiprecision;

// 任意長整数型
using Bint = mp::cpp_int;
 //仮数部が10進数で1024桁の浮動小数点数型(TLEしたら小さくする)
using Real = mp::number<mp::cpp_dec_float<1024>>;
*/
using namespace std;
using namespace atcoder;
using ll=long long;
using ull=unsigned long long;
using ld=long double;
using mint=modint998244353;
using mint2=modint1000000007;
//任意modint
using mint3=static_modint<1000000000>;
//using P=pair<ll,ll>;
using pll=pair<ll,ll>;
constexpr ll INF=1e17; 
const vector<ll> dx={0,0,1,-1,1,1,-1,-1};
const vector<ll> dy={1,-1,0,0,1,-1,-1,1};
const vector<char> dirs={'>','<','v','^'};
#define rep1(a)          for(ll i = 0; i < a; ++i)
#define rep2(i, a)       for(ll i = 0; i < a; ++i)
#define rep3(i, a, b)    for(ll i = a; i < b; ++i)
#define rep4(i, a, b, c) for(ll i = a; i < b; i += c)
#define overload4(a, b, c, d, e, ...) e
#define rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
template <typename T1,typename T2>
ostream& operator<<(ostream &os,pair<T1,T2> &pai){
    return os<<"("<<pai.first<<","<<pai.second<<") ";
}
template<typename T>
ostream& operator<<(ostream &os,vector<T> vec){
    for(auto val:vec){
        os<<val<<" ";
    }
    return os<<"\n";
}
template<typename T,typename T2>
istream& operator>>(istream &is,pair<T,T2> &pai){
    is>>pai.first>>pai.second;
    return is;
}
template<typename T>
istream& operator>>(istream &is,vector<T> &vec){
    for(int i=0;i<(int)vec.size();i++){
        is>>vec[i];
    }
    return is;
}

void set_cout(int d=15){
    cout<<fixed<<setprecision(d);
}
template <typename T> void print(const T &vec){
    int i=0;
    for(auto val:vec){
        cout<<i<<":"<<val<<",";
        i++;
    }
    cout<<'\n';
}
template<typename T> void print2(const vector<vector<T>> &vec){
    int i=0;
    for(auto v:vec){
        cout<<i<<": ";
        for(auto a:v){
            cout<<a<<" ";
        }
        i++;
        cout<<'\n';
    }
}
template<class T> void chmin(T &a,T b){
    if(a>b){
        a=b;
    }
    return;
}
template<class T> void chmax(T &a,T b){
    if(a<b){
        a=b;
    }
    return;
}
template<typename T,typename S>
T floor_div(T a,S b){
    if(b<0){a=-a;b=-b;}
    if(a>=0)return a/b;
    return(a-b+1)/b;
}

template<typename T,typename S>
T ceil_div(T a,S b){
    if(b<0){a=-a;b=-b;}
    if(a>=0)return(a+b-1)/b;
    return -floor_div(-a,b);
}
ll ll_pow(ll a,ll b){
    ll ret=1;
    while(b>0){
        if(b&1){
            ret*=a;
        }
        a*=a;
        b>>=1;
    }
    return ret;
}
ll ll_sqrt(ll a){
    ll ok=0;
    ll ng=3e9;
    while(abs(ok-ng)>1){
        ll mid=(ok+ng)/2;
        if(mid*mid<=a){
            ok=mid;
        }else{
            ng=mid;
        }
    }
    return ok;
}
ll ceil_log2(ll a){
    ll ret=0;
    while((1LL<<ret)<a){
        ret++;
    }
    return ret;
}

bool is_in(ll x,ll y,ll h,ll w){
    return 0<=x && x<h && 0<=y && y<w;
}
struct ob3{
    ll a,b,c;
    auto operator<=>(const ob3&) const = default;
};
struct ob4{
    ll a,b,c,d;
    friend auto operator<=>(const ob4&,const ob4&)=default;
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
}
