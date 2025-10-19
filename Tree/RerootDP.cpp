#include <bits/stdc++.h>
using namespace std;

struct RerootDP{
    //dp配列で持つデータの型
    //コンストラクタを定義するべし
    struct Value{
        int d;
        Value(int _d):d(_d){}
    };
    //問題によって変更
    Value merge(Value dp_cum,Value c){
        return Value(max(dp_cum.d,c.d));
    }
    //問題によって変更
    Value add_root(Value dp_cum){
        return Value(dp_cum.d+1);
    }
    //辺の型、問題に応じて変更
    struct Edge{
        int to;  
        Edge(int _to):to(_to){}
    };
    //単位元
    //末端の値はadd_root(id)になるのでそれを考慮
    Value id=Value(-1);
    vector<vector<Value>> dp;
    vector<Value> ans;
    vector<vector<Edge>> graph;
    int siz;
    RerootDP(int n):siz(n),dp(n),ans(n,id),graph(n){
        //何か処理をしたい場合はここに追加
    }
    //辺の追加(Edgeの型によって調整)
    void add_edge(int u,int v){
        assert(0<=u);
        assert(u<siz);
        assert(0<=v);
        assert(v<siz);
        graph[u].push_back({v});
    }
    void build(int r=0){
        dfs(r);
        dfs2(r,id,-1);
    }
    Value dfs(int v,int p=-1){
        Value dp_cum=id;
        int deg=graph[v].size();
        dp[v]=vector<Value>(deg,id);
        for(int i=0;i<deg;i++){
            int u=graph[v][i].to;
            if(u==p)continue;
            dp[v][i]=dfs(u,v);
            dp_cum=merge(dp_cum,dp[v][i]);
        }
        return add_root(dp_cum);
    }
    void dfs2(int v,const Value dp_p,int p=-1){
        int deg=graph[v].size();
        for(int i=0;i<deg;i++){
            if(graph[v][i].to==p){
                dp[v][i]=dp_p;
            }
        }
        vector<Value> dp_l(deg+1,id),dp_r(deg+1,id);
        for(int i=0;i<deg;i++){
            dp_l[i+1]=merge(dp_l[i],dp[v][i]);
        }
        for(int i=deg-1;i>=0;i--){
            dp_r[i]=merge(dp_r[i+1],dp[v][i]);
        }
        ans[v]=add_root(dp_l[deg]);
        for(int i=0;i<deg;i++){
            int u=graph[v][i].to;
            if(u==p)continue;
            dfs2(u,add_root(merge(dp_l[i],dp_r[i+1])),v);
        }
    }
};
int main(){
    int N;
    cin >> N;
    RerootDP reroot(N);
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        reroot.add_edge(u, v);
        reroot.add_edge(v, u);
    }
    reroot.build();
    for (int i = 0; i < N; i++) {
        cout << "頂点" << i + 1 << ": " << reroot.ans[i].d << endl;
    }
}