#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<long long int> dp(91,-1);
    dp[1]=1;
    dp[2]=1;
    for (int i=2; i<=89; i++){
        dp[i+1]=dp[i]+dp[i-1];
    }
    
    cout << dp[n];

}
