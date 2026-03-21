#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;




int main(){
    int t;
    cin >> t;
    for (int i=0; i<t; i++){
        int k1;
        cin >> k1;
        vector<int> ar(k1+1);
        for (int j=1; j<=k1; j++){
            cin >> ar[j];
        }
        vector<vector<int>>dp(k1+1,vector<int>(k1+1));
        
        //dp[1][1]=0
        //dp[2][2]=0
        //dp[1][2]=ar[1]+ar[2]
        //dp[2][3]=ar[2]+ar[3] ..
        //dp[a][b] = a번째부터 b번째까지 합칠때의 최소? 비용
        for (int i=1; i<=k1; i++){
            dp[i][i]=0;
        }
        
        for (int i=1; i<=k1; i++){
            for (int j=i-1; j>=1; j--){

                int min1=100000009;
                int ac=accumulate(ar.begin()+j,ar.begin()+i+1,0);   // [first,last)
                // int ac=0;
                // for (int z=j; z<=i; z++){
                //     ac+=ar[z];
                // }
                for (int k=j; k<i; k++){
                    min1=min(min1,dp[j][k]+dp[k+1][i]+ac);
                }
                dp[j][i]=min1;
            }

        }
        

        cout << dp[1][k1] << '\n';
        
    }

    
    return 0;

}
