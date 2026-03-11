#include <stdio.h>
int main(){
    int n;
    scanf("%d",&n);

    int answer=32;
    while (n>0){
        if (n%2==0) answer--; // 맨 끝비트 숫자부터 차례대로 확인..
        if (n%2==1) break;    // 2진수를 반전한 후, 끝에서부터 1이 끊길떄까지 세야하니 원래 수에서 0이 끊길때까지 세기
        n=n/2;

    }

    
    printf("%d",answer-1); // 추가적으로 1을 더 뺴줌 원래 수 기준 맨 끝자리부터 1일떄도 다 포함임
    }
