#include <stdio.h>
#include <math.h>

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

    int x1 = read_number();
    int y1 = read_number();
    int z1 = read_number();
    int x2;
    int y2;
    int z2;

    double min = 11.000;
    double d = 5;
    int p1 = 0;
    int p2 = 0;


    for(int i=2; i<=N; i++){
        
        x2 = read_number();
        y2 = read_number();
        z2 = read_number();
        
        d = pow(pow(x2-x1, 2) + pow(y2-y1, 2) + pow(z2-z1, 2), 0.5);

        if(d<min){
            min = d;
            p1 = i -1;
            p2 = i;
        }

        x1 = x2;
        y1 = y2;
        z1 = z2;

    }

    if(p1!=p2){
        printf("%d %d\n", p1, p2);
    }

    return 0;
}
