#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>
#include <unordered_map>
#include <set>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    
    for (int i=0; i<n; i++){
        cin >> v[i];
    }
    // 좌표압축을 위한 중복제거 정렬된 벡터 만들기
    vector<int> v2(n);
    for (int i=0; i<n; i++){
        v2[i]=v[i];
    }
    ranges::sort(v2);
    v2.erase(unique(v2.begin(),v2.end()),v2.end());
    // for (int i=0; i<v2.size(); i++){
    //     cout << v2[i] << " ";
    // }
    // cout << '\n';
    unordered_map<int,int>um;
    for (int i=0; i<v2.size(); i++){
        um[v2[i]] = i;
    }
    // um[숫자] = 이 숫자가 v에서 몇번쨰로 작은 숫자인지

    // v3 = v의 좌표압축 벡터
    vector<int>v3(n);
    for(int i=0; i<n; i++){
        v3[i]=um[v[i]];
    }
    // for (int i=0; i<n; i++){
    //     cout << v3[i] << " ";
    // }
    // cout << '\n';
    vector<pair<int,int>>intervals;
    set<int> s;
    // s.insert(v[0]);
    for (int i=0; i<n; i++){
        s.insert(v3[i]);
        auto it = s.upper_bound(v3[i]); 
        
        if (it!=s.end()){ // v3[i] 값이 최댓값이면 여기서 걸러짐
            int a = *it;
            intervals.push_back({v3[i],a-1});
        }
    }
    // for (auto c : intervals){
    //     cout << c.first << " " << c.second << '\n';
    // }
    sort(intervals.begin(),intervals.end(), [](const pair<int,int> a, const pair<int,int> b){
        return a.second<b.second;
    });
    

    int idx = 0;
    int num = -1;
    int cnt = 0;
    while (idx<intervals.size()){
        if (num>=intervals[idx].first && num<=intervals[idx].second){
            idx++;
            continue;
        }
        num = intervals[idx].second;
        idx++;
        cnt++;
    }
    cout << cnt;
    return 0;

}