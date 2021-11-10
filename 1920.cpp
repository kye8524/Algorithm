#define FAST ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];
void Check(int n, int key){
 
    int start = 0;
    int end = n-1;
    int mid;
 
    while(end - start >= 0){
        mid = (start + end)/2;
 
        if(arr[mid] == key){   //key 값이 배열의 중앙 값과 같을때
            printf("1\n");
            return ;
 
        }else if(arr[mid] > key) { //key 값이 배열의 중앙 값보다 작을때 (왼쪽으로)
            end = mid - 1;
 
        }else{  //key 값이 배열의 중앙 값보다 클때 (오른쪽으로)
            start = mid + 1;
        }
    }
 
    printf("0\n");
    return ;
}
int main(){
    int n,m,c;
    
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];    
    }
    sort(arr,arr+n);
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>c;
        Check(n,c);
    }

    return 0;
}