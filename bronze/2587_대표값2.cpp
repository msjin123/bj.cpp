#include <iostream>
#include <vector>

using namespace std;
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	// new = 동적 '메모리' 생성
	int *arr=new int[5];
	int *p=arr; // arr 1번째 주소
	for (int i=0; i<5; i++){
		cin >> *p;
		p++;
	}

	int sum=0;
	int avg=0;
	int *q=arr;
	for (int i=0; i<5; i++){
		sum=sum+*q;
		q++;
		
	}
	avg=sum/5;
	cout << avg << '\n';

	for (int i=4; i>0; i--){
		for (int j=0; j<i; j++){
			if (arr[j]>arr[j+1]){
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	cout << arr[2];

	delete[] arr;
	return 0;

}
