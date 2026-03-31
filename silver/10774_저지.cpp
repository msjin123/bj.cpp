#include <iostream>
#include <vector>

using namespace std;
int main(){
	int j,a;
	cin >> j;
	cin >> a;
	vector<char>judges(j+1);
	vector<pair<char,int>>pros(a+1);
	for (int i=1; i<=j; i++){
		cin >> judges[i];
	}
	for (int i=1; i<=a; i++){
		cin >> pros[i].first >> pros[i].second;
	}

	vector<bool>ck(j+1,false);
	int ans=0;
	for (int i=1; i<=a; i++){
		char size=pros[i].first;
		int number=pros[i].second;

		if (ck[number]==false){
			if (size=='S'){
				ans++;
				ck[number]=true;
			}
			
			else if (size=='M'){
				if (judges[number]!='S'){
					ans++;
					ck[number]=true;
				}
			}
			
			else if (size=='L'){
				if (judges[number]=='L'){
					ans++;
					ck[number]=true;
				}
			}
	}
}
	
	cout << ans;
	return 0;

}


	
