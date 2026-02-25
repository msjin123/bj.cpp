#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	int n;
	cin >> n;
	vector<vector<int>>li(n+1,vector<int>(3,0));
	for (int i=1; i<=n; i++){
		cin >> li[i][0];     // r - 0
		cin >> li[i][1];	 // g - 1
		cin >> li[i][2];	 // b - 2
	}
	
	vector<vector<int>>dp(n+1,vector<int>(3,0));
	dp[1][0]=li[1][0];
	dp[1][1]=li[1][1];
	dp[1][2]=li[1][2];
	for (int homenum=2; homenum<=n; homenum++){
		dp[homenum][0]=min(dp[homenum-1][1],dp[homenum-1][2])+li[homenum][0];
		dp[homenum][1]=min(dp[homenum-1][2],dp[homenum-1][0])+li[homenum][1];
		dp[homenum][2]=min(dp[homenum-1][0],dp[homenum-1][1])+li[homenum][2];
	}



	int answer=min({dp[n][0],dp[n][1],dp[n][2]});
	cout << answer;

	return 0;
	
}
