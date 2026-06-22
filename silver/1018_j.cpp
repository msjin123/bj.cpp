#include <iostream>
#include <vector>
using namespace std;
int make_num(int a, int b, int c, int d){
    return 1000*a+100*b+10*c+d;
}

// return 값 = num 이면 clknum임
int is_clknum(int num){
    int n1 = num/1000;
    int n2 = (num%1000)/100;
    int n3 = ((num%1000)%100)/10;
    int n4 = ((num%1000)%100)%10;

    int num2 = 1000*n2+100*n3+10*n4+n1;
    int num3 = 1000*n3+100*n4+10*n1+n2;
    int num4 = 1000*n4+100*n1+10*n2+n3;

    if (num<=num2 && num<=num3 && num<=num4) return num;
    if (num2<=num3 && num2<=num4) return num2;
    if (num3<=num4) return num3;
    return num4;
}
bool is_card(int num){
    int n1 = num/1000;
    int n2 = (num%1000)/100;
    int n3 = ((num%1000)%100)/10;
    int n4 = ((num%1000)%100)%10;

    if (n1==0 || n2==0 || n3==0 || n4==0) return false;
    return true;

}


int main(){
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    int num = make_num(a,b,c,d);
    int num1 = is_clknum(num);
    int ans=0;
    for (int i=1000; i<=num1; i++){
        if (is_card(i) && is_clknum(i)==i) ans++;
    }
    cout << ans;
    return 0;
}