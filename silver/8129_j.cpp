#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int ans = 0;
int recur(int n, int k, vector<int> &store, int step, vector<int> &A){
    
    if (step==k){
        ans++;
        for (int i=0; i<k; i++){
            if (store[i]!=A[i]) return 0;
        }
        
        
        return 1;
    }

    for (int i=1; i<=n; i++){
        // int mx = *max_element(store.begin(),store.end()); // null 포인터 역참조하면 에러남 if !store.empty()
        // if (i<=mx) continue;
        if (step!=0){
            int mx = store[step-1]; // store.back() 과 같음
            if (i<=mx) continue;
        }

        store.push_back(i);
        int case1 = recur(n,k,store,step+1,A);
        if (case1==1) return 1;
        store.pop_back();
    }

    return -1;
}


int main(){
    int n,k;
    cin >> n >> k;
    vector<int> A(k);
    for (int i=0; i<k; i++){
        cin >> A[i];
    }

    vector<int> store;
    
    int ret = recur(n,k,store,0,A);
    if (ret==1) cout << ans;
    else cout << "None";

    return 0;
}