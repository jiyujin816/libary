#include <bits/stdc++.h>
using namespace std;

template <typename T,T (*op)(T,T),T(*e)(),T(*inv)(T,T)>
struct abstract_fenwick_tree{
    vector<T> data;
    int N=0;
    abstract_fenwick_tree(){
        data.resize(0,e());
    }
    abstract_fenwick_tree(int n){
        N=n;
        data.resize(n,e());
    }
    void add(int i,T x){
        assert(0<=i && 0<N);
        i++;
        while(i<=N){
            data[i-1]=op(data[i-1],x);
            //data[i-1]+=x;
            i+= i& -i;
        }
        return;
    }
    T sum(int r){
        assert(0<=r && r<=N);
        T s=0;
        while(r>0){
            s=op(s,data[r-1]);
            //s+=data[r-1];
            r-= r& -r;
        }
        return s;
    }
    T sum(int l,int r){
        assert(0<=l && l<=r && r<=N);
        return inv(sum(r),sum(l));
        //return sum(r)-sum(l);
    }
    T get(int i){
        return inv(sum(i+1),sum(i));
        //return sum(i+1)-sum(i);
    }
    void set(int i,T x){
        return add(i,inv(x,get(i)));
        add(i,x-get(i));
    }
    T operator[](int i){
        return get(i);
    }
    void operator=(const abstract_fenwick_tree &ft){
        N=ft.N;
        data=ft.data;
    }
};
using ll=long long;
ll op(ll a,ll b){
    return a+b;
}
ll e(){
    return 0;
}
ll inv(ll a, ll b){
    return a-b;
}
int main(){
    int N,Q;
    cin>>N>>Q;
    abstract_fenwick_tree<ll,op,e,inv> a(N);
    for(int i=0;i<N;i++){
        ll ai;
        cin>>ai;
        a.add(i,ai);
    }
    while(Q--){
        ll t,p,x,l,r;
        cin>>t;
        if(t){
            cin>>l>>r;
            cout<<a.sum(l,r)<<"\n";
        }else{
            cin>>p>>x;
            a.add(p,x);
        }
    }
}