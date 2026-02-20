#include <iostream>

using namespace std;

int main(){
    int t;
    cin >> t;
    for (int i=0; i<t; i++){
        int n,m;
        cin >> n >> m;
        // vector<vector<int>>ar(n+1);
        for (int j=0; j<m; j++){
            int a,b;
            cin >> a >> b;
            // ar[a].push_back(b);
            // ar[b].push_back(a);
        }
        cout << n-1 << endl;
        
    
    }
}
