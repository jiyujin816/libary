#include <bits/stdc++.h>
//MIPとかのソルバー
#include "ortools/linear_solver/linear_solver.h"
//CP-SAT
#include "ortools/sat/cp_model.h"
using ll=long long;
#define rep1(a)          for(ll i = 0; i < a; ++i)
#define rep2(i, a)       for(ll i = 0; i < a; ++i)
#define rep3(i, a, b)    for(ll i = a; i < b; ++i)
#define rep4(i, a, b, c) for(ll i = a; i < b; i += c)
#define overload4(a, b, c, d, e, ...) e
#define rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
using namespace std;
//using namespace operations_research;
//SAT(LPとかMIPの時は消しとく)
using namespace operations_research::sat;
using ll=long long;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    
}
