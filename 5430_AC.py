#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <queue>
using namespace std;



int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    for (int i=0; i<t; i++){
        string p;
        cin >> p;
        int n;
        cin >> n;
        string ar; 
        cin >> ar;
        deque<int>dq; // 길이 = n , ar에서 숫자만 파싱해서 넣기
        int num=0;
        bool reading=false;
        for (char b : ar){
            if (isdigit(b)){
                num=10*num+(b-'0');
                reading=true;
            }
            else{
                if (reading){ // 숫자 끝나고 나서 바로 뒤만
                    dq.push_back(num);
                    num=0;
                    reading=false;
                }
            }
        }


        bool error=false;
        bool reverse=false;
        int s1=n; // arr.size();
        
        for (int k=0; k<p.length(); k++){
            if (p[k]=='R'){
                reverse=!reverse;
            }
            else if (p[k]=='D'){ // 첫 원소를 지움
                if (s1==0){
                    cout << "error";
                    error=true;
                    break;
                }
                if (!reverse) dq.pop_front();
                else if (reverse) dq.pop_back();
                s1--;
            }
        }

        // int s=arr.size(); // error 나면 s=0이라 아래꺼 출력 안함
        
        if (!error){
            cout << '[';
            if (!reverse){
                for (int m=1; m<2*s1; m++){
                    if (m%2!=0){
                        cout << dq.front();
                        dq.pop_front();
                    }
                    else if (m%2==0){
                        cout << ',';
                    }
                }
            }
            else{
                for (int m=1; m<2*s1; m++){
                    if (m%2!=0){
                        cout << dq.back();
                        dq.pop_back();
                    }
                    else if (m%2==0){
                        cout << ',';
                    }
                }
            }
            cout << ']';
        }
        cout << '\n';
    
    }
    return 0;
}
