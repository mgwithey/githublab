//Recitaiton quiz 2
//Matthew Withey

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

int combinations(int n,int k) {
    int long factN = 1;
    int long factK = 1;
    int long factNK = 1;
    int long total = 0;
    for (int i = 1; i <= n; i++) {
        factN *= i;
    }
     for (int i = 1; i <= k; i++) {
        factK *= i;
    }
    for (int i = 1; i <= (n-k); i++) {
        factNK *= i;
    }
    total = (factN) / ((factNK)*(factK));
    return total;
}
int sumsTo(int x[], int n, int k, int v) {
    if (v==0 && k==0) {return 1;}
    if (v!=0 && k==0) {return 0;}
    if (n==0) {return 0;}
    int res1 = 0;
    if (v >= x[0]) {
        res1 = sumsTo(x+1, n-1, k-1, v - x[0]);
    }
    int res2 = sumsTo(x+1, n-1, k, v);
    return res1 + res2 > 0; 
}
int main (void) {
    int x[] = {1,2,3,4,5};  //can change array here

    int n = sizeof(x)/sizeof(int);

    printf("\nGiven array\n{ ");
    for (int i = 0; i < n; i++) {
        printf("%d ", x[i]);
    }
    printf("}\nThere are %d numbers in the array\n", n);

    int k = 3;  //number of allowed terms 
    printf("There are %d allowed terms\n", k);

    int v = 10;  //desired number
    printf("%d is the desired number\n", v);

    int total = combinations(n,k);
    printf("There are %d total combinations \n", total);
    if (sumsTo(x, n, k, v) == 1) {
        printf ("Subset exists\n\n");
    } else {
        printf ("Impossible combination\n\n");
    }
    return 0;
}