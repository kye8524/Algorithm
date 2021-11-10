#include <iostream>
//#include <cstdlib>
//#include <ctime>

using namespace std;

int main(){
    int n;
    cin>>n;
    int data[n];
    //srand((unsigned int)time(NULL));
    for(int i=0;i<n;i++){
        cin>>data[i];
    }
    int temp=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i;j++){
            if(data[j]>data[j+1]){
                temp=data[j];
                data[j]=data[j+1];
                data[j+1]=temp;
            }
        }
    }
    for(int i =0;i<n;i++){
        cout<<data[i]<<endl;

    }
    return 0;
}