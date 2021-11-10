#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    FAST;
    int n,m;
    cin>>n>>m;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];

    }
    int res=0;
    for(int s=0;s<=n;s++){
        int e=s;
        int sum=0;
        sum+=arr[s];
        if(sum>m){
            break;
        }
        else if(sum==m){
            res++;            
        }
        else if(sum<m){
            for(e=s+1;e<=n;e++){
                sum+=arr[e];
                if(sum==m){
                    res++;
                    break;
                }else if(sum>m){
                    break;
                }
            }

        }
    }
    cout<<res;
    
    return 0;
}