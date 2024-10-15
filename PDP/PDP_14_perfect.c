#include <stdio.h>

int read_number() {
    int number = 0;
    int flag = 0;

    char c = getchar();

    while (!(c >= '0' && c <= '9')) {
        c = getchar();
        if(flag==0){
            flag=1;
        }
        else{
            number = -1;
            break;
        }
    }

    while (c >= '0' && c <= '9') {
        int digit = c - '0';
        number = number * 10 + digit;
        c = getchar();
    }

    return number;
}

int main(){

    int N = read_number();
    int counter = 0;
    int sum = 0;
    int table[10001] = {0};
    int pos = 1;
    int temp = 0;
    int metr = 0;

    while(N != -1){
        
        for(int i=1; i<=pos; i++){
            table[i] = 0;
        }
        
        counter=2;
        sum=0;
        table[1] = 1;
        pos=2;

        while(counter<=N / 2){
            if(N % counter ==0){
                table[pos] = N / counter;
                pos++;
                table[pos] = counter;
                pos++;
            }
            counter++;
        }

        pos--;
        for(int i=1; i<=pos; i++){
            temp = table[i];
            metr = 0;
            for(int j=i; j<=pos; j++){
                if(temp == table[j]){
                    metr++;
                }
            }
            if(metr==1){
                sum = sum + temp;
            }
        }


        if(sum!=N || N==1){
            printf("0\n");
        }
        else{
            printf("1\n");
        }

        N = read_number();
    }
}
