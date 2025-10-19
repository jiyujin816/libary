#include <bits/stdc++.h>
using namespace std;

struct GridUnionFind{
    int h,w;
    vector<int> par,rank,siz;
    private:
    int root(int p){
        if(par[p]==-1){
            return p;
        }else{
            return par[p]=root(par[p]);
        }
    }
    int pos_id(pair<int,int> p){
        return p.first*w+p.second;
    }
    pair<int,int> id_pos(int p){
        return make_pair(p/w,p%w);
    }
    public:
    GridUnionFind(int x,int y){
        h=x,w=y;
        par.resize(h*w,-1);
        rank.resize(h*w,1);
        siz.resize(h*w,1);
    }  
    pair<int,int> leader(pair<int,int> x){
        return id_pos(root(pos_id(x)));
    }
    bool same(pair<int,int> x,pair<int,int> y){
        return leader(x)==leader(y);
    }
    pair<int,int> merge(pair<int,int> x,pair<int,int> y){
        if(same(x,y)){
            return leader(x);
        }
        int rx=root(pos_id(x)),ry=root(pos_id(y));
        if(rank[rx]<rank[ry]){
            swap(rx,ry);
        }
        if(rank[rx]==rank[ry]){
            rank[rx]++;
        }
        par[ry]=rx;
        siz[rx]+=siz[ry];
        return leader(id_pos(rx));
    }
};