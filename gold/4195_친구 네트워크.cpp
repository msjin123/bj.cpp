#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
using namespace std;

string find(string s, unordered_map<string,string> &parents){
	if (s!=parents[s]){
		parents[s] = find(parents[s], parents);
	}

	return parents[s];

}


int union1(string p1,string p2,unordered_map<string,string> &parents){
	p1=find(p1,parents);
	p2=find(p2,parents);

	if (p1==p2){
		return 0;
	}

	else if (p1<p2){
		parents[p2]=p1;
		return 1;
	}
	else if (p1>p2){
		parents[p1]=p2;
		return 2;
	}
	
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	for (int i=0; i<t; i++){
		int f;
		cin >> f;
		unordered_map<string,string>parents;
		unordered_map<string,int>friends;
		for (int j=0; j<f; j++){
			string p1,p2;
			cin >> p1 >> p2;
			
			if (parents.find(p1)==parents.end()){
				parents[p1]=p1;
				friends[p1]=1;
			}
			if (parents.find(p2)==parents.end()){
				parents[p2]=p2;
				friends[p2]=1;
			}
			
			// 두 사람 p1,p2 각각의 친구 네트워크의 부모 node 의 친구 수 구해놓기
			// sum_two = 두 친구 네트워크의 친구 수를 합친 것
			string parent1=find(p1,parents);
			string parent2=find(p2,parents);
			int sum_two=friends[parent1]+friends[parent2];

			int r=union1(p1,p2,parents);
			
			// 전체의 부모 하나에만 sum_two 갱신하기
			// p1,p2 를 비롯한 나머지는 갱신 안해도됨 차피 부모에 접근해서 구할 수 있어서
			// p1,p2의 친구 네트워크 수 = p1,p2 의 부모의 친구 네트워크 수
			if (r==1){ // 전체 부모노드 = p1
				friends[parent1]=sum_two;
				cout << friends[parent1];
			}
			else if (r==2){ // 전체 부모노드 = p2
				friends[parent2]=sum_two;
				cout << friends[parent2];
			}
			else if (r==0){
				cout << friends[parent1]; // 아무거나 출력해도됨
			}
			cout << '\n';

		}
		

	}
	return 0;

}
	
