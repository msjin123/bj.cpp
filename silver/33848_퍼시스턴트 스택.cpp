#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;


int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int q;
	cin >> q;
	stack<int> s;
	cin.ignore();
	int rep=0;
	int ssize=0;

	stack<pair<int,int>> storestack;

	while (rep<q){
		string line;
		getline(cin,line);
		stringstream ss(line);

		int a;
		ss >> a;
		
		if (a==1 or a==3){
			int b;
			ss >> b;
			
			if (a==1){
				s.push(b);
				ssize++;
				storestack.push({1,b});
			}
			else if (a==3){
				while (b>0){
					if (storestack.top().first==1){
						s.pop();
						ssize--;
						storestack.pop();
					}
					else if (storestack.top().first==2){
						int num2=storestack.top().second;
						s.push({num2});
						ssize++;
						storestack.pop();
					}
					b--;
				}
			}
			
		}
		
		else if (a==2){
			int num=s.top();
			s.pop();
			ssize--;
			storestack.push({2,num});
		}
		else if (a==4){
			cout << ssize << '\n';
			}
		else if (a==5){
			if (ssize==0){
				cout << -1 << '\n';
			}
			else{
				cout << s.top() << '\n';
			}
		}

		rep++;
		
  	}
	
	return 0;
	
}
