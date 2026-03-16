#include <iostream>
#include <vector>

using namespace std;
void swap1(int &x,int &y){
	int temp1=x;
	x=y;
	y=temp1;
}

// 참조
void sort1(vector<int>&ar,int n){
	for (int i=n-1; i>0; i--){
		for (int j=0; j<i; j++){
			if (ar[j]>ar[j+1]){
				// swap
				swap1(ar[j],ar[j+1]);
			}
		}
	}
}


int main(){
	int n,k;
	cin >> n >> k;
	vector<int>ar(n);
	for (int i=0; i<n; i++){
		cin >> ar[i];
	}

	// vector sort (increasing)
	sort1(ar,n);

	

	cout << ar[n-k];
	
}
