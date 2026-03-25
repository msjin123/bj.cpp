#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t;
	cin >> t;
	for (int i=0; i<t; i++){
		int n;
		cin >> n;
		// ar[1] ~ ar[n]
		
		// 범위 벗어날때를 대비해 n+2
		vector<int> ar(n+2,0);
		// (길이,초기값)
		for (int z=1; z<=n; z++){
			cin >> ar[z];
		}
		vector<vector<int>>dp(n+2,vector<int>(n+2,0)); 
		
		for (int a=1; a<=n; a++){
			dp[a][a]=ar[a];
		}
		for (int len=1; len<=n-1; len++){
		 
			for (int a=1; a<=n-len; a++){
				int s=accumulate(ar.begin()+a,ar.begin()+a+len+1,0);
				dp[a][a+len]=max(s-dp[a][a+len-1],s-dp[a+1][a+len]);

			}
		}
		cout << dp[1][n] << '\n';
		
	
	

	}
	return 0;
}
