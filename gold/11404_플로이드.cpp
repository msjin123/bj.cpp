#include <iostream>
#include <vector>
#define INF 100000001
using namespace std;
int main(){
	int n,m;
	cin >> n >> m; // 도시개수 , 버스개수

	vector<vector<int>>li(n+1,vector<int>(n+1,INF));

	for (int z=0; z<m; z++){
		int a,b,c;
		cin >> a >> b >> c;
		li[a][b]=min(li[a][b],c);
	}

	for (int z=1; z<=n; z++){
		li[z][z]=0;
	}


	for (int k=1; k<=n; k++){
		for (int i=1; i<=n; i++){
			for (int j=1; j<=n; j++){
				li[i][j]=min(li[i][j],li[i][k]+li[k][j]);
			}
		}
	}

	for (int i=1; i<=n; i++){
		for (int j=1; j<=n; j++){
			if (li[i][j]==INF){
				cout << 0 << " ";
			}
			else{
				cout << li[i][j] << " ";
			}
		}
		cout << '\n';
	}

	return 0;

}
