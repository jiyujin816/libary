#include <bits/stdc++.h>
using namespace std;
struct TrieNode{
    char ch;
    map<char,TrieNode *> chi;
    int cnt=0;
    int isend=0;
    int during=0;
    TrieNode(char c){
        ch=c;
    }
};
using pn=TrieNode *;
struct TrieTree{
    map<char,pn> root;
    void insert(const string &s){
        int N=(int)s.size();
        if(s.empty()){
            return;
        }
        pn now;
        if(root.contains(s[0])){
            now=root[s[0]];
        }else{
            root[s[0]]=new TrieNode(s[0]);
            now=root[s[0]];
        }
        for(int i=0;i<N-1;i++){
            now->cnt++;
            now->during++;
            if(now->chi.contains(s[i+1])){
                now=now->chi[s[i+1]];
            }else{
                now->chi[s[i+1]]=new TrieNode(s[i+1]);
                now=now->chi[s[i+1]];
            }
        }
        now->cnt++;
        now->isend++;
        return;
    }
    bool find(const string &s){
        if(s.empty()){
            return false;
        }
        int N=(int)s.size();
        pn now;
        if(root.contains(s[0])){
            now=root[s[0]];
        }else{
            return false;
        }
        for(int i=0;i<N-1;i++){
            if(!(now->during)){
                return false;
            }
            if(now->chi.contains(s[i+1])){
                now=now->chi[s[i+1]];
            }else{
                return false;
            }
        }
        if(now->isend){
            return true;
        }else{
            return false;
        }
    }
    bool prefix_find(const string &s){
        if(s.empty()){
            return false;
        }
        int N=(int)s.size();
        pn now;
        if(root.contains(s[0])){
            now=root[s[0]];
        }else{
            return false;
        }
        for(int i=0;i<N-1;i++){
            if(now->chi.contains(s[i+1])){
                now=now->chi[s[i+1]];
            }else{
                return false;
            }
        }
        return true;
    }
    int prefix_count(const string &s){
        if(s.empty()){
            return 0;
        }
        int N=(int)s.size();
        pn now;
        if(root.contains(s[0])){
            now=root[s[0]];
        }else{
            return 0;
        }
        for(int i=0;i<N-1;i++){
            if(now->chi.contains(s[i+1])){
                now=now->chi[s[i+1]];
            }else{
                return 0;
            }
        }
        return now->cnt;
    }
    bool erase(const string &s){
        if (!find(s)) {
            return false; // 存在しない単語は削除できない
        }   

        int N = s.size();
        vector<pn> path; // たどったノードを保存
        pn now = root[s[0]];

        path.push_back(now);
        for (int i = 1; i < N; i++) {
            now = now->chi[s[i]];
            path.push_back(now);
        }
        // 逆順に削除処理を行う
        for (int i = N - 1; i >= 0; i--) {
            now = path[i];
            now->cnt--;  // cntを減算
            if (now->cnt <= 0) { // もう使われていなければ削除
                if (i > 0) {
                    path[i - 1]->chi.erase(s[i]);
                    delete now;
                } else {
                    root.erase(s[0]);
                    delete now;
                }
            }
        }
 
        return true;
    } 
    
};
//ABC353E
int main(){
    int N;
    cin>>N;
    vector<string> S(N);
    rep(i,N){
        cin>>S[i];
    }
    ll ans=0;
    TrieTree Ttree;
    for(int i=1;i<N;i++){
        Ttree.insert(S[i]);
    }
    for(int i=0;i<N-1;i++){
        ans+=Ttree.solve(S[i]);
        Ttree.erase(S[i+1]);
    }
    cout<<ans;
}