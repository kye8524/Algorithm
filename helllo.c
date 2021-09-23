#include <iostream>
#include <string>

using namespace std;

int main(){
   string p="";
   string c="";
   int k;
   cin >> p >> k;
   k= k%26;
   
   for(int i = 0 ; i < p.length(); i++){
      char ch = ((p[i]-'a')+26-k)%26+'a';
      c+=ch;
   }
   cout << c;
}