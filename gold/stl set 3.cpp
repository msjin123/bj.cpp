#include <iostream>
#include <set>
using namespace std;
int main(){
    int q;
    cin >> q;
    set<int> s;
    for (int i=0; i<q; i++){
        char alp;
        int val;
        cin >> alp >> val;
        if (alp=='i') s.insert(val);
        if (alp=='r'){
            if (s.find(val)!=s.end()) s.erase(val);
        }
        if (alp=='f'){
            if (s.find(val)==s.end()){
                cout << "NOPE" << '\n';
            }
            else{
                auto it1 = s.find(val);
                auto it2 = s.find(val);
                auto it3 = s.find(val);
                // *it2 = val-12312;
                // *it3 = val-12312;
                if (it2!=s.begin()) it2--;
                if (it3!=s.end()) it3++;
                // if (it2==s.begin()--) *it2=val-1;
                // if (it3==s.end()) *it3==val-1;
                // 집합안에 들어있는 모든 원소의 갯수가 1
                if (it2==s.begin() && it3==s.end()){
                    cout << "UNIQUE" << '\n';
                }
                else{
                    int ans1,ans2;
                    while (it2!=s.begin()){
                        if (*it2!=*it1) break;
                        
                        it2--;
                    }
                    ans1=*it2;
                    

                    while (it3!=s.end()){
                        if (*it3!=*it1) break;
                        it3++;
                    }
                    if (it3==s.end()) it3--;
                    ans2=*it3;
                    

                    if (val-ans1<=ans2-val){
                        if (ans1==val) cout << ans2 ;
                        else cout << ans1;
                    }
                    else if (val-ans1>ans2-val){
                        if (ans2==val) cout << ans1;
                        else cout << ans2;
                        
                    }
                    cout << '\n';
                }

            }
        }
    }
    return 0;
}