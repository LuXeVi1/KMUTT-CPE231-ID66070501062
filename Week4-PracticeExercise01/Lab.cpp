//#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef struct height{
    int a;
    int b;
}Height;

float efficient(Height x , Height y){
    return ((float)(abs(x.a-y.a))/(float)(abs(x.a)+abs(y.a))) + ((float)(abs(x.b-y.b))/(float)(abs(x.b)+abs(y.b)));
}

float cmpMin(float a , float b){
    return (a>b)? b:a;
}

int main() {
    int n , min;
    cin >> n;
    vector <Height> antenna(n);
    vector <float> eff(n);
    for(int i = 0 ; i < n ; i++){
        cin >> antenna[i].a >> antenna[i].b;
        // cout << i << " : " << antenna[i].a << " " << antenna[i].b << "\n";
    }
    for(int i = 0 ; i < n ; i++){
        float sum = 0;
        // cout << i << "\n";
        for(int j = 0 ; j < n ; j++){
            if(i == j){
                continue;
            }
            sum += efficient(antenna[i], antenna[j]);
            // cout << j << " || " << sum << "\n";
        }
        eff[i] = sum;
        // cout << "_________________\n";
        // cout << i << " : " << eff[i] << "\n";
    }
    for(int i = 0 ; i < n-1 ; i++){
        if(cmpMin(eff[i] , eff[i+1]) == eff[i]){
            min = i;
        }else if(cmpMin(eff[i] , eff[i+1]) == eff[i+1]){
            min = i+1;
        }
    }
    cout << antenna[min].a << " " << antenna[min].b;

    return 0;
}