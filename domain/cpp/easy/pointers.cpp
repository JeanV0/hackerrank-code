    #include <stdio.h>

    void update(int *a,int *b) {
        int a_copy = *a;
        int b_copy = *b;
        *a = a_copy + b_copy;
        *b = a_copy - b_copy;
        if (*b < 0){
            *b = (*b) * -1;
        }
    }

    int main() {
        int a, b;
        int *pa = &a, *pb = &b;
        
        scanf("%d %d", &a, &b);
        update(pa, pb);
        printf("%d\n%d", a, b);

        return 0;
    }