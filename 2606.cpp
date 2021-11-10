#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#include<iostream>
#include<vector>

#define MAX 101

using namespace std;

vector<vector<int>> a;
int v[MAX];
int n, m;

int dfs(int cur) {
    int res = 1;
    v[cur] = 1;
    for(int i=0;i<a[cur].size();i++){
        int next = a[cur][i];
        if(v[next]) continue;
        res += dfs(next);
    }
    return res;
}

int solve(){
    cout<<dfs(1)-1<<'\n';
    return 0;
}

int main(){
    FAST;    
    cin>>n>>m;
    a.resize(n+1);
    for(int i=0;i<m;i++){
        int cur, next;
        cin>>cur>>next;
        a[cur].push_back(next);
        a[next].push_back(cur);
    }
    solve();
    return 0;
}