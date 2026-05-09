// dp 도전!

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n,w;
    cin >> n >> w;
    vector<pair<int,int>>jewels(n+1);
    // arr[0] = {0,0}
    for (int i=1; i<=n; i++){
        cin >> jewels[i].first >> jewels[i].second;
    }

    vector<vector<int>>dp2(n+1,vector<int>(w+1)); // 초깃값은 자동으로 0
    int max_value=0;
    for (int a=1; a<=n; a++){ // a = a번쨰 가방까지
        for (int b=1; b<=w; b++){ // b = 무게가 b일떄 (최대무게 = w)
            if (b<jewels[a].first){
                dp2[a][b]=dp2[a-1][b];
                
            }
            else{
                dp2[a][b]=max(dp2[a-1][b] , jewels[a].second*(b/jewels[a].first)+dp2[a-1][b%jewels[a].first]);
            }
            max_value=max(max_value,dp2[a][b]);
        }
    }
    cout << max_value << endl;
    
    // for (int a=1; a<=n; a++){ // a = a번쨰 가방까지
    //     for (int b=1; b<=w; b++){ // b = 무게가 b일떄 (최대무게 = w)
    //         cout << dp2[a][b] << " ";
    //     }
    //     cout << '\n';
    // }
}