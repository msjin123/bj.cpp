#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
	int n;
	cin >> n;
	cin.ignore();
	for (int i = 1; i <= n; i++) {
		
		string li;
		getline(cin, li);
		
		/*vector<vector<char>> ar;
		vector<char> a;*/
		vector <string> ar;
		string a;
		for (int j = 0; j < li.length(); j++) {
			if (li[j] == ' ') {
				ar.push_back(a);
				a.clear();
				
			}
			else {
				a.push_back(li[j]);
			}
		}
		if (!a.empty()) { //
			ar.push_back(a);
		}
		
		cout << "Case #" << i << ": ";
		for (int k = ar.size() - 1; k >= 0; k--) {  //
			//for (int j = 0; j < ar[k].size(); j++) { //
			//	cout << ar[k][j];
			//}
			cout << ar[k];


			if (k) cout << ' '; //
			
		}
		cout << '\n';  //
	}
	

	return 0;
	
}
