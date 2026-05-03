#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n,p;
    cin >> n >> p;
    vector<int> arr(10000000,0);

    int ansnum;
    
    int num=n;
    int step=1;
    arr[num]=step;
    
    while (1){
        num=(num*n)%p;
        step++;
        if (arr[num]!=0){
            ansnum = arr[num];
            break;
        }
        arr[num]=step;
        
    }
    int ans = step-ansnum;
    cout << ans;
}