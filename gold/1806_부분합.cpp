#include <iostream>
#include <vector>
#include <string>

using namespace std;
int main(){

	int n,s;
	cin >> n >> s;
	vector<int>ar(n+1);
	for (int i=1; i<=n; i++){
		cin >> ar[i];
	}

	int minlength=100001;

	int front,back;
	front=1;
	back=1;
	int sum1=ar[front];
	while (1){
		if (front>back){
			if (front>n) break;
			back=front;
			sum1=ar[front];
		}
		
		if (sum1>=s){
			sum1-=ar[front];
			minlength=min(minlength,back-front+1);
			front++;
		}
		else if (sum1<s){
			if (back==n) break;
			back++;
			sum1+=ar[back];
		}
		// cout << front << " " << back << " " << sum1 << '\n';
	}
	if (minlength==100001) cout << 0;
	else cout << minlength;


	return 0;
}



	
