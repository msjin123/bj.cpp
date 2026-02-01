#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int t;
    cin >> t;
    for (int i=0; i<t; i++){
        int a,b;
        cin >> a >> b;
        a=a%10; // 중요
        if (a==5 or a==6){
            cout << a;
        }
        else if (a==2 or a==3 or a==7 or a==8){
            if (b%4==1){
                cout << a;
            }
            else if (b%4==2){
                if (a==2){
                    cout << 4;
                }
                else if (a==3){
                    cout << 9;
                }
                else if (a==7){
                    cout << 9;
                }
                else if (a==8){
                    cout << 4;
                }
            }
            else if (b%4==3){
                if (a==2){
                    cout << 8;
                }
                else if (a==3){
                    cout << 7;
                }
                else if (a==7){
                    cout << 3;
                }
                else if (a==8){
                    cout << 2;
                }
            }
            else if (b%4==0){
                if (a==2){
                    cout << 6;
                }
                else if (a==3){
                    cout << 1;
                }
                else if (a==7){
                    cout << 1;
                }
                else if (a==8){
                    cout << 6;
                }
            }
        }
        else if (a==4 or a==9){
            if (b%2==1){
                cout << a;
            }
            else if (b%2==0){
                if (a==4){
                    cout << 6;
                }
                else if (a==9){
                    cout << 1;
                }
            }
        }
        
        else if (a==1){
            cout << 1;
        }
        else if (a==0){
            cout << 10;
        }

        if (i!=t-1){
            cout << '\n';
        }

    }
    return 0;
}
