#include <iostream>
#include <cmath>


using namespace std;
int main(){
	long long a,x;
	cin >> a >> x;
	const long long MOD = 1000000007LL;
	// cout << pow(a,x); // O(x)
	
	long long x1=x;
	long long ans=1;
	

	while (x1>0){
		long long c=1;
		__int128 temp=a;
		while (c<=x1/2){
			c=(c*2);
			temp=(temp*temp)%MOD;
		}
		ans=(ans*temp)%MOD;
		x1=x1-c;
		
	}
	

	cout << ans;


}
