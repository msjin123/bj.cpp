#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    // n = 가방의 수 k = 김기범이 훔쳐가야 할 가방의 수 c = 상훈이가 가방에 물건 담을수있는 물건들의 최대무게
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,k,c;
    cin >> n >> k >> c; 
    vector<int>ar(n+1); // 가방들의 무게
    for (int i=1; i<=n; i++){
        cin >> ar[i];
    }
    sort(ar.begin(),ar.end());
    vector<long long>ar2(n+1); // prefix sum vector
    
    for (int i=1; i<=n; i++){
        ar2[i]=ar2[i-1]+ar[i]; 
    }

    int idx=0;
    for (int c1=1; c1<=c; c1++){
        if (idx+1>n) idx=n-1;

        if (c1==ar2[idx+1]){ // c가 1씩 증가하므로 최대 1번
            idx++;
        }
        
        if (idx+k>n){
            int gap = (idx+k)-n;

            if (idx-gap<0) cout << ar2[n]-ar2[0] << '\n';
            else cout << ar2[n]-ar2[idx-gap] << '\n';
        }
        else cout << ar2[idx+k]-ar2[idx] << '\n';

    }
    return 0;
}