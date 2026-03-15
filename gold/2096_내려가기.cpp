#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;
	// vector<vector<int>>li(n+1,vector<int>(3));

	int cnt=0;
	int s1,s2,s3;
	cin >> s1 >> s2 >> s3;
	int total_max1,total_max2,total_max3;
	int total_min1,total_min2,total_min3;
	total_max1=s1;
	total_min1=s1;
	total_max2=s2;
	total_min2=s2;
	total_max3=s3;
	total_min3=s3;
	cnt++;
	// cnt=1
	
	while (cnt<n){
		int a,b,c;
		cin >> a >> b >> c;
		int m1,m2,m3;
		m1=max(total_max1,total_max2);
		m2=max({total_max1,total_max2,total_max3});
		m3=max(total_max2,total_max3);

		total_max1=m1+a;
		total_max2=m2+b;
		total_max3=m3+c;

		int m4,m5,m6;
		m4=min(total_min1,total_min2);
		m5=min({total_min1,total_min2,total_min3});
		m6=min(total_min2,total_min3);
		total_min1=m4+a;
		total_min2=m5+b;
		total_min3=m6+c;
		
		cnt++;
	}

	int max1=max({total_max1,total_max2,total_max3});
	int min1=min({total_min1,total_min2,total_min3});
	cout << max1 << " " << min1;
	


	return 0;

}
