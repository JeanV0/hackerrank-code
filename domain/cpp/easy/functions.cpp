#include <iostream>
#include <cstdio>
using namespace std;

int max_of_four(int a, int b, int c, int d) {
    bool run = true;

    int max = 0;

    while(run){
        if(a > max){
            max = a;
        } else if(b > max){
            max = b;
        } else if(c > max){
            max = c;
        } else if(d > max){
            max = d;
        } else {
            break;
        }
    }

    return max;
}

int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int ans = max_of_four(a, b, c, d);
    printf("%d", ans);
    
    return 0;
}