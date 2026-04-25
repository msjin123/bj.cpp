#include <iostream>
#include <vector>
using namespace std;
int main(){
	int n;
	cin >> n;
	vector<vector<int>>li;
	for (int i=0; i<=n; i++){
		vector<int> ar;
		for (int j=0; j<=n; j++){
			ar.push_back(0);
		}
		li.push_back(ar);
	}

	int i=1;
	int j=1;
	int num=1;
	int dist=1; // = step
	
	while (dist<=n){
		if (dist%2!=0){
			i=1;
			j=dist;
			for (int a=0; a<dist; a++){
				li[i][j]=num;
				// cout << "odd " << i << " " << j << " " << num << '\n';
				num++;
				
				if (a!=dist-1){ // index 범위 초과 방지
					i+=1;
					j-=1;
				}
			}
		}
		else if (dist%2==0){
			i=dist;
			j=1;
			for (int a=0; a<dist; a++){
				li[i][j]=num;
				// cout << "even " << i << " " << j << " " << num << '\n';
				num++;
				if (a!=dist-1){
					i-=1;
					j+=1;
				}
			}
		}
		dist++;
		
	}
	dist=n-1;
	while (dist>=1){
		if (dist%2!=0){
			i=n-dist+1;
			j=n;
			for (int a=0; a<dist; a++){
				li[i][j]=num;
				// cout << "odd " << i << " " << j << " " << num << '\n';
				num++;
				if (a!=dist-1){
					i+=1;
					j-=1;
				}
			}
		}
		else if (dist%2==0){
			i=n;
			j=n-dist+1;
			for (int a=0; a<dist; a++){
				li[i][j]=num;
				// cout << "even " << i << " " << j << " " << num << '\n';
				num++;
				if (a!=dist-1){
					i-=1;
					j+=1;
				}
			}
		}
		dist--;
	}
	for (int b=1; b<=n; b++){
		for (int c=1; c<=n; c++){
			cout << li[b][c] << " ";
		}
		cout << '\n';
	}
	return 0;

}
	

