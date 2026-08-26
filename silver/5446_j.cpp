#include <iostream>
#include <vector>
using namespace std;
bool is_same1(vector<pair<int,int>> lr1, vector<pair<int,int>> lr2){
    
    int lr1idx=0;
    // lr1 마지막 부분이랑 lr1 첫 부분도 비교에 포함하기!!!
    // lr1.size()=n-1 임. n-1이랑 lr1.size()-1 이랑 햇갈렸음 (추가로)
    for (int a=0; a<lr1.size(); a++){
        bool ans = true;
        for (int t=0; t<lr1.size(); t++){
            if (lr1[lr1idx].first==lr2[t].first && lr1[lr1idx].second==lr2[t].second){
                // lr1idx 변경하고 계속 진행
            }
            else{
                ans=false;
            }
            if (lr1idx==lr1.size()-1) lr1idx=0;
            else lr1idx++;
        }
        if (ans) return true; // 전부 같을경우 true 반환
        lr1idx++;
    }

    return false;
}
int main(){
    int n;
    cin >> n;
    vector<pair<int,int>> diagram1(n);
    vector<pair<int,int>> length_rotate1(n);
    for (int i=0; i<n; i++){
        int x,y;
        cin >> x >> y;
        diagram1[i].first = x;
        diagram1[i].second = y;
    }
    for (int i=0; i<n; i++){
        int tp1,tp2;
        tp1=i;
        tp2=i+1;
        if (i==n-1){
            tp1=i;
            tp2=0;
        }
        int x1 = diagram1[tp1].first;
        int x2 = diagram1[tp2].first;
        int y1 = diagram1[tp1].second;
        int y2 = diagram1[tp2].second;
        if (y1==y2){
            length_rotate1[i].first = abs(x2-x1);
            if (x1<x2){ // right
                length_rotate1[i].second = 1;
            }
            else if (x1>x2){ // left
                length_rotate1[i].second = 2;
            }
        }
        else if (x1==x2){
            length_rotate1[i].first = abs(y2-y1);
            if (y1<y2){ // up
                length_rotate1[i].second = 3;
            }
            else if (y1>y2){ // down
                length_rotate1[i].second = 4;
            }
        }
    }

    vector<pair<int,int>> diagram2(n);
    vector<pair<int,int>> length_rotate2(n);
    for (int i=0; i<n; i++){
        int x,y;
        cin >> x >> y;
        diagram2[i].first = x;
        diagram2[i].second = y;
    }
    for (int i=0; i<n; i++){
        int tp1,tp2;
        tp1=i;
        tp2=i+1;
        if (i==n-1){
            tp1=i;
            tp2=0;
        }
        int x1 = diagram2[tp1].first;
        int x2 = diagram2[tp2].first;
        int y1 = diagram2[tp1].second;
        int y2 = diagram2[tp2].second;
        if (y1==y2){
            length_rotate2[i].first = abs(x2-x1);
            if (x1<x2){ // right
                length_rotate2[i].second = 1;
            }
            else if (x1>x2){ // left
                length_rotate2[i].second = 2;
            }
        }
        else if (x1==x2){
            length_rotate2[i].first = abs(y2-y1);
            if (y1<y2){ // up
                length_rotate2[i].second = 3;
            }
            else if (y1>y2){ // down
                length_rotate2[i].second = 4;
            }
        }
    }
    //--
    // cout << '\n';
    // for (int b=0; b<n; b++){
    //     cout << length_rotate1[b].first << " " << length_rotate1[b].second << '\n';
    // }
    // cout << '\n';
    // for (int b=0; b<n; b++){
    //     cout << length_rotate2[b].first << " " << length_rotate2[b].second << '\n';
    // }
    //--

    // compare length_rotate1, length_rotate2
    int ans = 0;
    for (int t=0; t<4; t++){
        if (is_same1(length_rotate1,length_rotate2)){
            ans=1;
            break;
        }
        for (int i=0; i<n; i++){
            if (length_rotate1[i].second==1) length_rotate1[i].second=4;
            else if (length_rotate1[i].second==2) length_rotate1[i].second=3;
            else if (length_rotate1[i].second==3) length_rotate1[i].second=1;
            else if (length_rotate1[i].second==4) length_rotate1[i].second=2;
        }

    }
    cout << ans;
    return 0;
    

}

