#include <iostream>
#include <vector>


using namespace std;
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m;
	cin >> n >> m;
	vector<vector<int>>li(n+1,vector<int>(n+1));
	for (int i=0; i<=n; i++){
		li[0][i]=0;
	}
	for (int i=0; i<=n; i++){
		li[i][0]=0;
	}
	// li 입력 (가장 왼쪽 위 : (1,1) 임
	for (int i=1; i<=n; i++){
		for (int j=1; j<=n; j++){
			cin >> li[i][j];
		}
	}
	

	// li2 입력 : li의 (1,1) 부터 현재 좌표(i,j)까지 네모친거의 합이 li2의(i,j)
	vector<vector<int>>li2(n+1,vector<int>(n+1));
	for (int i=0; i<=n; i++){
		li2[0][i]=0;
	}
	for (int i=0; i<=n; i++){
		li2[i][0]=0;
	}
	for (int i=1; i<=n; i++){
		for (int j=1; j<=n; j++){
			li2[i][j]=li2[i-1][j]+li2[i][j-1]-li2[i-1][j-1]+li[i][j];
		}
	}

	// 두 좌표 (x1,y1) , (x2,y2) 입력
	for (int i=0; i<m; i++){
		int x1,y1,x2,y2;
		cin >> x1 >> y1 >> x2 >> y2;
		int ans;
		ans=li2[x2][y2]-li2[x2][y1-1]-li2[x1-1][y2]+li2[x1-1][y1-1];

		cout << ans << '\n';


	}
	return 0;
}
