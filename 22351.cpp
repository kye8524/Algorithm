#include <iostream>
#include <string>

using namespace std;


int main(){
    string p="";
    
    cin>>p;
    for(int i=0;i<1000;i++){
        string t="";
        for(int j=i;j<1000;j++){
            t+=to_string(j);
            if(t==p){
                cout<<i<<" "<<j<<endl;
                goto EXIT;
            }
        }
    }
    EXIT:
    return 0;
}