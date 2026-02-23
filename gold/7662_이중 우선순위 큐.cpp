#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int k;
		cin >> k;
		priority_queue<int> pq;							  // 원래 queue
		priority_queue<int,vector<int>,greater<int>> pq2; // 내림차순 저장 queue
		int ins = 0;
		int del = 0;
		map<int, int> cnt;
		cnt.clear();
		for (int j = 0; j < k; j++) {
			char choice;
			int num;
			cin >> choice;
			cin >> num;
			
			if (choice == 'I') {
				pq.push(num);
				pq2.push(num);
				ins++;
				cnt[num] += 1;
			}
			// 삭제 횟수 >= 삽입 횟수이면 queue 가 비어있다는 뜻이기 때문에 시행 x
			else if (choice == 'D') {
				if (del < ins) {
					if (num == 1) { // 최댓값 삭제
						cnt[pq.top()] -= 1;
						pq.pop();
						del++;
					}
					else if (num == -1) { // 최솟값 삭제

						cnt[pq2.top()] -= 1;
						pq2.pop();
						del++;
						
					}
				}
				while (!pq.empty() && cnt[pq.top()] == 0) pq.pop();
				while (!pq2.empty() && cnt[pq2.top()] == 0) pq2.pop();
			}

		}
		while (!pq.empty() && cnt[pq.top()] == 0) pq.pop();
		while (!pq2.empty() && cnt[pq2.top()] == 0) pq2.pop();
		
		if (del >= ins) {
			cout << "EMPTY";
		}
		else if (del < ins) {   // pq,pq2, 각각에 원소가 최소 하나 이상 있음
			cout << pq.top() << " " << pq2.top();
		}
		cout << '\n';
	}
	return 0;
}
// 
