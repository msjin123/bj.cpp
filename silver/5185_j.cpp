#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;

    for (int t=1; t<=2*n-1; t++){
        cout << '*';
    }
    cout << '\n';

    int l,r;
    l=1;
    r=2*n-1;
    for (int a=1; a<=n-1; a++){ // a<=n-2+1
        for (int t=1; t<=2*n-1; t++){
            if (t==l || t==r) cout << '*';
            else cout << ' ';
        }
        l++;
        r--;
        cout << '\n';
    }
    l-=2;
    r+=2;
    for (int a=1; a<=n-2; a++){ // a<=n-2
        for (int t=1; t<=2*n-1; t++){
            if (t==l || t==r) cout << '*';
            else cout << ' ';
        }
        l--;
        r++;
        cout << '\n';
    }
    for (int t=1; t<=2*n-1; t++){
        cout << '*';
    }
    
}