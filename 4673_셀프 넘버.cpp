int sum_digits(int n){
    int answer=0;
    int num=n;
    while (num>0){
        answer+=num%10;
        num=num/10;
    }
    return answer;
}



#include <stdio.h>
int main(){
    int arr1[10101];
    for (int i=0; i<10100; i++){
        arr1[i]=-1;
    }
    for (int num=1; num<10000; num++){
        int a=num;
        while (a<=10000){
            a=a+sum_digits(a);
            arr1[a]=1;
            
        }
    }

    for (int i=1; i<=10000; i++){
        if (arr1[i]==-1){ // 생성자 x
            printf("%d\n",i);
        }
    }

    
    
    return 0;
}
