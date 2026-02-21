#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector <int> ar(n + 1,0);
	
	
	vector <int> nums(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> nums[i];
	}
	
	// 0 1 1 3 2
	for (int i = 1; i <= n; i++) {

		ar.insert(ar.begin() + i - nums[i], i);
	}

	for (int i = 1; i <= n; i++) {
		cout << ar[i] << " ";
	}

	return 0;

}
