#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n,s;
    cin >> n >> s; // n주동안, 1주당 우유 보관비용 = s
    vector<vector<int>>ar(n,vector<int>(2));
    for (int i=0; i<n; i++){
        int c,y; 
        cin >> c >> y;
        ar[i][0]=c;
        ar[i][1]=y;
        
        // 그 주의  c=1리터당우유가격, y=그주에 몇리터 사야하는지, week=몇번쨰주인지
    }

    long long ans = 0;
    int mincost = ar[0][0];
    ans+=mincost*ar[0][1];
    for (int i=1; i<n; i++){
        
        if (mincost+s<ar[i][0]){
            mincost = mincost+s;
        }
        else{
            mincost = ar[i][0];
        }
        ans+=mincost*ar[i][1];
    }
    
    
    cout << ans;
}