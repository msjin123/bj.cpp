#include <stdio.h>
int main(){
    int t;
    scanf("%d",&t);
    for (int i=0; i<t; i++){
        char s[101];
        scanf("%s",s);
        int count_a=0;
        int count_b=0;
        int j=0;
        while (s[j]!='\0'){
            if (s[j]=='a'){
                count_a++;
                
            }
            else if (s[j]=='b'){
                count_b++;
            }
            j++;
        }
        if (count_a<count_b){
            printf("%d\n",count_a);
        }
        else{
            printf("%d\n",count_b);
        }


    }
    return 0;
}
