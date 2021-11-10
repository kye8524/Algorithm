#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct Tree{
   int a;
   int b;
   int c;
}Tree;

bool compareTreeByC(Tree& a, Tree& b){
   return a.c < b.c;
}


int cruscal();

int v,e;
vector<Tree> t;

int main(){
   scanf("%d %d", &v, &e);
   
   
   for(int i = 0 ; i < e ; i ++){
      register int a,b,c;
      scanf("%d %d %d", &a, &b, &c);
      register Tree tempTree = {a,b,c};
      t.push_back(tempTree);
   }
   
   int n = cruscal();
   cout << n;
}

int findTree(int parent[], int n){
   if(parent[n] == n)return n;
   return findTree(parent,parent[n]);
   return n;
}
void mergeTree(int parent[], int rank[], int a, int b){// a,b는 최상위 노드 
   
   if(rank[a] < rank[b])swap(a,b);
   
   parent[b] = a; 
   if(rank[a] == rank[b])rank[a]++;
}



int cruscal(){
   sort(t.begin(), t.end(),compareTreeByC);
   
   
   int count  = 0;
   
   int mst = 0;
   
   int parent[v+1];
   int rank[v+1] = {0,};
   
   
   
   for(int i = 1; i<= v; i++){
      parent[i] = i;
   }
   
   vector<Tree>::iterator iter = t.begin();
   vector<Tree>::iterator end = t.end();
   while(iter != end){
      register Tree a = *(iter);
      
      int aParentNode = findTree(parent, a.a);
      int bParentNode = findTree(parent, a.b);
      if(aParentNode != bParentNode){
         mergeTree(parent, rank, aParentNode,bParentNode);
         count++;
         mst += a.c;
      }
      iter++;
   }
   

   return mst;
}