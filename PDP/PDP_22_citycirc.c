#include <stdio.h>

int read_number() {
    int number = 0;

    char c = getchar();

    while ((c < '0' || c > '9') && c != '-') {
        c = getchar();
    }
    
    int flag=0;
    if(c=='-'){
        flag=1;
        c=getchar();
    }

    while (c >= '0' && c <= '9') {
        int digit = c - '0';
        number = number * 10 + digit;
        c = getchar();
    }
    
    if(flag==1){
        number= number * (-1);
    }

    return number;
}

int main(){
    int N = read_number();
    int table[2000001] = {0};
    for(int i=1; i<=N; i++){
        table[i] = read_number();
    }
    
    int max = 0;
    int sum = 0;
    int flag1 = 0;
    
    for(int i=1; i<=N; i++){
        sum = sum + table[i];
        if(flag1==0 && sum>=0){
            max = i;
            flag1 = 1;
        }
        if(sum<0){
            max = 0;
            sum = 0;
            flag1=0;
        }
    }
    
    for(int i=1; i<=max; i++){
        sum = sum + table[i];
        if(sum<0){
            max=0;
            break;
        }
    }
    
    printf("%d", max);
    
}
