# include <stdio.h>
# include <stdbool.h>
int len1(char arr[]){
    int num=0;
    while (arr[num]!='\0'){
        num++;
    }

    return num;
}

bool ispalindrome(char arr[],int start,int end){
    int a,b;
    a=start;
    b=end;

    while (a<b){
        if (arr[a]!=arr[b]){
            return false;
        }
        a++;
        b--;
    }

    return true;

}

int main(){
    char s[51];
    scanf("%s",s);
    

    int len2=len1(s);

    int end=len2-1;
    int start=0;
    int ans;
    while (start>=0){
        if (ispalindrome(s,start,end)){
            break;
        }
        start++;
    }
    ans=len2+start;

    printf("%d",ans);




    return 0;


}
