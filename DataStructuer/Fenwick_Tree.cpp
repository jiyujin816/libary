#include <bits/stdc++.h>
using namespace std;

template <typename T>struct fenwick_tree{
    vector<T> data;
    int N=0;
    fenwick_tree(){
        data.resize(0,0);
    }
    fenwick_tree(int n){
        N=n;
        data.resize(n,0);
    }
    void add(int i,T x){
        assert(0<=i && 0<N);
        i++;
        while(i<=N){
            data[i-1]+=x;
            i+= i& -i;
        }
        return;
    }
    T sum(int r){
        assert(0<=r && r<=N);
        T s=0;
        while(r>0){
            s+=data[r-1];
            r-= r& -r;
        }
        return s;
    }
    T sum(int l,int r){
        assert(0<=l && l<=r && r<=N);
        return sum(r)-sum(l);
    }
    T get(int i){
        return sum(i+1)-sum(i);
    }
    void set(int i,T x){
        add(i,x-get(i));
    }
    T operator[](int i){
        return get(i);
    }
    void operator=(const fenwick_tree<T> &ft){
        N=ft.N;
        data=ft.data;
    }
};

int main(){
    fenwick_tree<int> ft(14);
    ft.add(4,3);
    ft.set(4,6);
    cout<<ft.sum(6);
}