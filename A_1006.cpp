#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int sortX[1000000];
int sortY[1000000];

double min(double num1, double num2){
    if(num1 < num2) return num1;
    else return num2;
}

void sortXY(int X[], int Y[], long start, long end){
    int tmp;
    if(end-start < 2 ){
        if(X[start] > X[end]){
            tmp = X[start];
            X[start] = X[end];
            X[end] = tmp;

            tmp = Y[start];
            Y[start] = Y[end];
            Y[end] = tmp;
        }
        return;
    }
    long mid = (start + end) /2;
    sortXY(X, Y, start, mid);
    sortXY(X, Y, mid+1, end);
    long l = start, r = mid+1;

    for(long i=start; i<= end; i++){
        if((X[l] < X[r] && l < mid+1) || r > end){
            sortX[i] = X[l];
            sortY[i] = Y[l];
            l++;
        }else{
            sortX[i] = X[r];
            sortY[i] = Y[r];
            r++;
        }

    }
    for(long i=start; i<= end; i++){
        X[i] = sortX[i];
        Y[i] = sortY[i];
    }
}

int main(){
    int n;
    cin>>n;

    int X[n], Y[n];
    string text;
    string delimiter = ",";
    char pos =0 ;

    for(int i=0; i<n; i++){
        cin >> text >> Y[i];
        pos = text.find(delimiter);
        X[i] = stoi(text.substr(0, pos));
    }
    sortXY(X, Y, 0, n-1);
    
    double miner = 100000;
    double dist;
    for(int i=0; i<n; i++){
        for(int j=i+1;j<n;j++){
            dist = sqrt(pow(X[i]-X[j], 2) + pow( Y[i]-Y[j], 2) );
            miner = min(miner, dist);
        }
    }
    printf("%.6f", miner);
}