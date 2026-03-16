#include <iostream>
#include <vector>

using namespace std;
int main(){
	int n,l;
	cin >> n >> l;
	// num=l
	
	for (int num=l; num<=100; num++){
		if (num%2==0){
			if (n%num==num/2){
				int n1=n/num;
				int start=n1-(num/2-1);
				if (start<0){
					cout << -1;
					break;
				}
				for (int i=start; i<start+num; i++){
					cout << i << " ";
				}
				break;
			}
		}
		else if (num%2!=0){
			if (n%num==0){
				int n1=n/num;
				int start=n1-(num/2);
				if (start<0){
					cout << -1;
					break;
				}
			
				for (int i=start; i<start+num; i++){
					cout << i << " ";
				}
				break;
			}
		}
		if (num==100){
			cout << -1;
		}
	}
	
	return 0;

}
