#include <bits/stdc++.h>
using namespace std;
using ll=long long;

struct BaseN{
    ll num;
    string snum;
    int base=10;
    BaseN(){
        num=0;
        snum="0";
    }
    BaseN(int bas){
        num=0;
        base=bas;
        snum="0";
    }
    string to_base(ll num){
        string ret="";
        ll divi=base;
        while(num!=0){
            ret.push_back('0'+num%base);
            num-=num%divi;
            num/=base;
        }
        reverse(ret.begin(),ret.end());
        return ret;
    }
    BaseN(int bas,ll n){
        base=bas;
        num=n;
        snum=to_base(n);
    }
    bool operator==(const BaseN &other){
        return num==other.num;
    }
    bool operator!=(const BaseN &other){
        return num!=other.num;
    }
    BaseN operator+(const BaseN &other){
        BaseN ret(base,num+other.num);
        return ret;
    }
    BaseN operator+(const int &other){
        BaseN ret(base,num+other);
        return ret;
    }
    BaseN operator-(const BaseN &other){
        BaseN ret(base,num-other.num);
        return ret;
    }
    BaseN operator-(const int &other){
        BaseN ret(base,num+other);
        return ret;
    }
    void operator++(){
        num++;
        snum=to_base(num);
        return;
    }
    void operator--(){
        num--;
        snum=to_base(num);
        return;
    }

};

int main(){
    BaseN binary(4,30);
    cout<<binary.snum;
}