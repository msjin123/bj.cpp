#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void type1(int d,vector<int>arr,int n){
    if (d==n){
        for (auto a : arr){
            cout << a << " ";
        }
        cout << '\n';
        return;
    }

    for (int i=1; i<=6; i++){
        arr[d]=i;
        type1(d+1,arr,n);
        // 원소변경 굳이 필요 x
    }
}
void type2(int d,vector<int>arr,int n){
    
    if (d==n){
        for (auto a : arr){
            cout << a << " ";
        }
        cout << '\n';
        return;
    }

    for (int i=1; i<=6; i++){
        
        arr[d]=i;
        if (d!=0 && arr[d-1]>arr[d]){
            continue;
        }
        type2(d+1,arr,n);
        arr[d]=0;
    }
}
void type3(int d,vector<int>arr,int n){
    if (d==n){
        for (auto a : arr){
            cout << a << " ";
        }
        cout << '\n';
        return;
    }

    for (int i=1; i<=6; i++){
        if (ranges::find(arr,i)!=arr.end()){
            continue;
        }
        arr[d]=i;
        type3(d+1,arr,n);
        arr[d]=0; // 중복방지를위해
        
    }
}

int main(){
    int n,type;
    cin >> n >> type;
    vector<int>arr(n);
    if (type==1){
        type1(0,arr,n);
    }
    else if (type==2){
        type2(0,arr,n);
    }
    else if (type==3){
        type3(0,arr,n);
    }
    return 0;
}