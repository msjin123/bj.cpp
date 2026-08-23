#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main(){
    unsigned int n;
    cin >> n;

    vector<int> num1(8,0);

    for (int i=0; i<8; i++){
        int q = n/16;
        int r = n%16;
        num1[i] = r;
        n=n/16;
    }


    swap(num1[0],num1[1]);
    swap(num1[2],num1[3]);
    swap(num1[4],num1[5]);
    swap(num1[6],num1[7]);

    unsigned int ans=0;
    unsigned int mul = pow(16,7);
    for (int num2 : num1){
        ans+=num2*mul;
        mul=mul/16;
    }
    cout << ans;
    return 0;

}
