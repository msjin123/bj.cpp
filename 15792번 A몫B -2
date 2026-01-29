#include <iostream>
#include <vector>
using namespace std;
int main(){
    int a,b;
    cin >> a >> b;
    // a/b

    int n;
    vector <int> arr;
    n=a/b;
    arr.push_back(n);
    a=a%b;

    // 초등학교 나눗셈 계산과 완전 똑같은 로직
    for (int i=0; i<1000; i++){
        a=a*10;  
        n=a/b; 
        arr.push_back(n);
        a=a%b; 
    }

    cout << arr[0] << ".";
    for (int i=1; i<arr.size(); i++){ // size=1001
        cout << arr[i];
    }
    
    return 0;
}
