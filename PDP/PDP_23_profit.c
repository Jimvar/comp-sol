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
    int tab[1000001] = {0};
    
    for(int i=1; i<=N; i++){
        tab[i] = read_number();
    }
    
    int min = 1001;
    float max = -1;
    
    for(int i=1; i<=N-1; i++){
        if(tab[i] < min){
            min=tab[i];
        }
        if( (float)tab[i+1]/min > max){
            max = (float)tab[i+1]/min;
        }
    }
    
    printf("%.3f", max);
}
