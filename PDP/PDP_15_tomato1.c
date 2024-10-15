#include <stdio.h>

int read_number() {
    int number = 0;

    char c = getchar();

    while (!(c >= '0' && c <= '9')) {
        c = getchar();
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
    int M = read_number();
    int D = read_number();
    int tomates[202] = {0};

    for(int i=1; i<=N; i++){
        tomates[i] = 0;
    }

    for(int j=1; j<=M; j++){
        tomates[read_number()] = 1; 
    }

    for(int i=1; i<=D; i++){
        for(int j=1; j<=N; j++){
            if(tomates[j] == 1){
                if(tomates[j-1] != 1){
                    tomates[j-1] = 2;
                }
                if(tomates[j+1] != 1){
                    tomates[j+1] = 2;
                }
            }
        }
        for(int j=1; j<=N; j++){
            if(tomates[j] == 2){
                tomates[j] = 1;
            }
        }
    }

    int counter = 0;
    for(int i=1; i<=N; i++){
        if(tomates[i]==0){
            counter++;
        }
    }

    printf("%d\n", counter);

}
