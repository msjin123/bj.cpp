#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#define MOD 1234567891
using namespace std;

int main(){
	int l;
	cin >> l;
	string alps;
	cin >> alps;
	long long hash=0;
	long long ri=1;
	for (int i=0; i<alps.length(); i++){
		hash=hash+(((alps[i]-'a'+1)*ri)%MOD);
		ri=(ri*31)%MOD;

	}
	hash=hash%MOD;
	cout << hash;
	return 0;
}
	
