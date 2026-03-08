#include <iostream>
#include <vector>
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
		// 2n개의 스티커
		vector<int> ar1(n);
		vector<int> ar2(n);
		for (int a=0; a<n; a++){
			cin >> ar1[a];
		}
		for (int a=0; a<n; a++){
			cin >> ar2[a];
		}
		vector<int> dp1(n); // 현재 : 위에 스티커 제거
		vector<int> dp2(n);	// 현재 : 아래 스티커 제거
		vector<int> dp3(n); // 현재 : 스티커 제거 x

		dp1[0]=ar1[0];
		dp2[0]=ar2[0];
		dp3[0]=0;
		for (int a=1; a<n; a++){
			dp1[a]=max(dp2[a-1]+ar1[a],dp3[a-1]+ar1[a]);
			dp2[a]=max(dp1[a-1]+ar2[a],dp3[a-1]+ar2[a]);
			dp3[a]=max(dp1[a-1],max(dp2[a-1],dp3[a-1])); // 이건 현재 스티커는 안떼기 떄문에 이전까지 스티커 점수의 합만 계산
			// 3번쨰줄 보완할 점: dp3[a-1] 도 포함해야 한다. 
			// 포함 안해도 틀릴 수 있는 반례는 없는거 같긴 하지만, 포함하는게 깔끔하긴 하다. 
		}

		int ans=max(dp1[n-1],max(dp2[n-1],dp3[n-1]));
		cout << ans << '\n';

	}
	return 0;
}
