#include <iostream>
#include <vector>
#include <algorithm>
#include <ranges>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<tuple<int,int,int>> ar(n);
    for (int i=0; i<n; i++){
        int a,b;
        cin >> a >> b;
        get<0>(ar[i]) = a;
        get<1>(ar[i]) = b;
    }
    int k;
    cin >> k;

    for (int i=0; i<n; i++){
        get<2>(ar[i]) = get<0>(ar[i]) * k + get<1>(ar[i]);
    }

    ranges::sort(ar,[](tuple<int,int,int> tu1, tuple<int,int,int> tu2){
        if (get<2>(tu1)!=get<2>(tu2)){
            return get<2>(tu1) < get<2>(tu2);
        }
        else if (get<0>(tu1)!=get<0>(tu2)){
            return get<0>(tu1) < get<0>(tu2);
        }
        return get<1>(tu1) < get<1>(tu2);
    });

    for (int i=0; i<n; i++){
        cout << get<0>(ar[i]) << " " << get<1>(ar[i]);
        cout << '\n';
    }
    return 0;
}