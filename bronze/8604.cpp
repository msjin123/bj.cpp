#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<bool>arr(250001,false);
    int last=0;
    for (int i=0; i<n; i++){
        int a;
        cin >> a;
        arr[a]=true; // 장애물있음
        last=a;
    }
    int ans=0;
    int locate=0;
    while (locate<=last){
        if (arr[locate+2]==false){
            locate=locate+2;
            ans+=1;
        }
        else if (arr[locate+1]==false){
            locate=locate+1;
            ans+=1;
        }
        else{
            ans=-1;
            break;
        }
    }
    cout << ans;
    return 0;
}