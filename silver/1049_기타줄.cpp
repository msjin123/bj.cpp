#include <iostream>
#include <memory>
using namespace std;

void sort(int *&arr,int len1){
	for (int i=len1-1; i>0; i--){
		for (int j=0; j<i; j++){
			if (arr[j]>arr[j+1]){
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}


int main(){
	int n,m;
	cin >> n >> m;

	int *packages=new int[m];
	int *per=new int[m];

	for (int i=0; i<m; i++){
		cin >> packages[i] >> per[i];
	}

	sort(packages,m);
	sort(per,m);

	int best_packages=packages[0];
	int best_per=per[0];

	int answer;

	if (best_per*6<best_packages){
		answer=best_per*n;
	}
	 
	else if (best_per*(n%6)<best_packages){
		answer=best_packages * (n/6) + best_per * (n%6);
	}
	else{
		answer=best_packages*((n/6) + 1);
	}


	cout << answer;
	delete[] packages;
	delete[] per;

	return 0;

}
