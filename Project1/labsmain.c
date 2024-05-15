
#include ‹stdio.h>
#include "labs.h"
int main() {
    
    int variant;

    printf("Введите номер лаб: \n");
    scanf ("%d", &variant);
    if (variant == 1) {
        lab1();
    }
    else if (variant == 2){
    
        lab2();
    }
    else if (variant == 3)
    {
        lab3();
    }
    else
    {
        printf("Такого варианта нет ");
    }
    return 0;
}