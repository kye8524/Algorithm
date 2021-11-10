#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> a;

int n,m;

int check(int mid) {
    int cur = 0;
    int cnt = 0;
    for(int i=0;i<n;i++){
        if(a[i]>mid) return 0;
        if(cur<a[i]){
            cur = mid;
            cnt += 1;
        }
        cur -= a[i];
    }
    return cnt<=m;
}

int main(){
    FAST;
    cin>>n>>m;
    a.resize(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int res = 1e9;
    int l = 0;
    int r = 0;
    for(int i=0;i<n;i++){
        r += a[i];
    }
    while (l<=r){
        int m = (l+r)/2;
        if (check(m)){
            r = m - 1;
            res = min(res, m);
        }else{
            l = m + 1;
        }
    }
    cout<<res<<'\n';
    return 0;
}