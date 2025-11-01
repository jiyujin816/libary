#include <bits/stdc++.h>
using namespace std;
template<typename T> 
struct Matrix{
    //行数
    int h;
    //列数
    int w;
    vector<vector<T>> data;
    Matrix(int _h,int _w):h(_h),w(_w),data(_h,vector<T>(_w)){}
    Matrix(int _h,int _w,T init):h(_h),w(_w),data(_h,vector<T>(_w,init)){}
    Matrix(int n):h(n),w(n),data(n,vector<T>(n)){}
    Matrix(int n,T init):h(n),w(n),data(n,vector<T>(n,init)){}
    Matrix(const vector<vector<T>>& d):h(d.size()),w(d[0].size()),data(d){}
    Matrix(vector<vector<T>> d):h(d.size()),w(d[0].size()),data(d){}
    Matrix operator+(const Matrix& other){
        assert(h==other.h);
        assert(w==other.w);
        Matrix res(h,w);
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                res.data[i][j]=data[i][j]+other.data[i][j];
            }
        }
        return res;
    }
    Matrix operator-(const Matrix& other){
        assert(h==other.h);
        assert(w==other.w);
        Matrix res(h,w);
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                res.data[i][j]=data[i][j]-other.data[i][j];
            }
        }
        return res;
    }
    Matrix operator*(const Matrix& other){
        assert(w==other.h);
        Matrix res(h,other.w,0);
        for(int i=0;i<h;i++){
            for(int j=0;j<other.w;j++){
                for(int k=0;k<w;k++){
                    res.data[i][j]+=data[i][k]*other.data[k][j];
                }
            }
        }
        return res;
    }
    Matrix operator*(const T& prod){
        Matrix res(h,w);
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                res.data[i][j]=data[i][j]*prod;
            }
        }
        return res;
    }
    Matrix operator+=(const Matrix& other){
        *this=*this+other;
        return *this;
    }
    Matrix operator-=(const Matrix& other){
        *this=*this-other;
        return *this;
    }
    Matrix operator*=(const Matrix& other){
        *this=*this*other;
        return *this;
    }
    Matrix operator*=(const T& prod){
        *this=*this*prod;
        return *this;
    }
    //転置行列を返す
    Matrix transpose(){
        Matrix res(w,h);
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                res.data[j][i]=data[i][j];
            }
        }
        return res;
    }
    Matrix identity(int n){
        Matrix res(n,n,0);
        for(int i=0;i<n;i++){
            res.data[i][i]=1;
        }
        return res;
    }
    Matrix pow(long long exp){
        assert(h==w);
        Matrix res=identity(h);
        Matrix base=*this;
        while(exp){
            if(exp&1LL) res=res*base;
            base=base*base;
            exp>>=1LL;
        }
        return res;
    }
    vector<T>& operator[](int idx){
        assert(0<=idx);
        assert(idx<h);
        return data[idx];
    }
};
//ABC293E
#include <atcoder/modint>
using namespace atcoder;
using ll=long long;
int main(){
    ll A,X,M;
    cin>>A>>X>>M;
    modint::set_mod(M);
    Matrix<modint> ans(2,1);
    ans[0][0]=0;
    ans[1][0]=1;
    Matrix<modint> base(2,2);
    base[0][0]=A;
    base[0][1]=1;
    base[1][0]=0;
    base[1][1]=1;
    Matrix<modint> res=base.pow(X)*ans;
    cout<<res[0][0].val()<<endl;
}