#include <bits/stdc++.h>
using namespace std;
#define all(a) (a).begin(),(a).end()
template<typename S,typename T>
struct RangeTree{
    vector<vector<T>> data;
    vector<S> compr_x;
    int N;
    int log;
    int size;
    //log計算
    int ceil_pow2(int n) {
        int x = 0;
        while ((1U << x) < (unsigned int)(n)) x++;
        return x;
    }
    void update(int p){
        data[p].clear();
        data[p].reserve(data[2*p].size()+data[2*p+1].size());
        auto &left=data[2*p];
        auto &right=data[2*p+1];
        int a=0;
        int b=0;
        for(int i=0;i<(int)left.size()+(int)right.size();i++){
            if(a<(int)left.size() && b<(int)right.size()){
                if(left[a]<right[b]){
                    data[p].push_back(left[a]);
                    a++;
                }else{
                    data[p].push_back(right[b]);
                    b++;
                }
            }else{
                if(a<left.size()){
                    data[p].push_back(left[a]);
                    a++;
                }else{
                    data[p].push_back(right[b]);
                    b++;
                }
            }
        }
        return;
    }
    RangeTree(vector<pair<S,T>> &vec){
        N=vec.size();
        log=ceil_pow2(N);
        size=1<<log;
        data.resize(size*2+1);
        auto &cx=compr_x;
        for(int i=0;i<N;i++){
            cx.push_back(vec[i].first);
        }
        sort(all(cx));
        cx.erase(unique(all(cx)),cx.end());
        for(auto [x,y]:vec){
            x=lower_bound(all(cx),x)-cx.begin();
            data[size+x].push_back(y);
        }
        for(int i=0;i<size;i++){
            sort(all(data[size+i]));
        }
        for(int i=size-1;i>0;i--){
            update(i);
        }
    }
    //xが[l,r)かつyが[l2,r2)のもの（座標圧縮後）
    int compr_count(int l,int r,T l2,T r2){
        l+=size;
        r+=size;
        int sml=0;
        int smr=0;
        while(l<r){
            if(l&1){
                sml+=lower_bound(all(data[l]),r2)-lower_bound(all(data[l]),l2);
                l++;
            }
            if(r&1){
                smr+=lower_bound(all(data[r-1]),r2)-lower_bound(all(data[r-1]),l2);
                r--;
            }
            l>>=1;
            r>>=1;
        }
        return sml+smr;
    }
    //xが[l,r)でyが[l2,r2)
    int count(S l,S r,T l2,T r2){
        assert(l<=r);
        int nl=lower_bound(all(compr_x),l)-compr_x.begin();
        int nr=(lower_bound(all(compr_x),r))-compr_x.begin();
        assert(l2<=r2);
        return compr_count(nl,nr,l2,r2);
    }
};
//ABC405F 545ms
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N,M;
    cin>>N>>M;
    vector<pair<int,int>> edges(M);
    for(int i=0;i<M;i++){
        int a,b;
        cin>>a>>b;
        a--;b--;
        
        edges.push_back(make_pair(min(a,b),max(a,b)));
    }
    int Q;
    cin>>Q;
    RangeTree<int,int> RT(edges);
    while(Q--){
        int c,d;
        cin>>c>>d;
        c--;d--;
        if(c>d){
            swap(c,d);
        }
        cout<<RT.count(0,c,c+1,d)+RT.count(c+1,d,d+1,2*N)<<"\n";
    }
}