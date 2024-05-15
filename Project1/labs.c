#include ‹stdio.h>
#include "labs.h"
// Функция для вычисления факториала
    static int factorial(int n) {
    int result = 1;
    while(n > 1) {
    result *= n;
    n--;
    }
    return result;
}

// Функция для вычисления степени числа
    static int power(int base, int exponent) {
    int result = 1;
    while(exponent > 0) {
    result *= base;
    exponent--;
    }
    return result;
}

int lab1(){
    #define pi 3.14
    #define X 0.33

    int H, r, R, V;

    // Ввод данных
    printf("Введите радиус меньшего основания r: ");
    scanf("%d", &r);

    printf("Введите высоту усечённого конуса H: ");
    scanf("%d", &H);

    printf("Введите радиус боьшего основания R: ");
    scanf("%d", &R);

    // Расчет объема усеченного конуса
    V = X * pi * H * ((r * r) + r + R + (R * R));

    // Вывод результата
    printf("Объем оставшейся фигуры: %d\n", V);
    #undef X
    return 0;
    
}
int lab2(){
    double summ = 1.0; // сумма ряда
    double x; // входной параметр ряда
    int n; // число элементов ряда
    int sign = -1; // знак очередного элемента ряда

    // ввод параметров ряда
    printf("Введите положительное целое число n: ");
    scanf("%d", &n);

    printf("Введите значение x: ");
    scanf("%lf", &x);

    // вычисление суммы ряда
    for (int i = 1; i <= n; ++i) {
    summ += (double)(sign * power(x, 2 * i)) / factorial(2 * i);
    sign *= -1;
    }

    // вывод результата
    printf("Сумма ряда для x = %.2f с %d элементами равна %.6lf\n", x, n, summ);

    return 0;
}

int lab3()
{
    char c;
    char predSymvol = 0;
    int kolichestvoSivolovPovtor = 0;
    int kolichSlov = 0;
    printf("Введите текст: \n");
// цикл чтения символов из потока, связанного с клавиатурой
    while( (c = getchar()) != EOF )
    {
        if( c == ' ' || c == '.' || c == '\n' || c == ',' )
        {
            if (kolichestvoSivolovPovtor > 0) 
                ++kolichSlov;
            
            kolichestvoSivolovPovtor = 0;
        }
        else
        {
            if (c == predSymvol)
                ++kolichestvoSivolovPovtor;
            predSymvol = c;
        }

     }
     printf("Колличество слов: %d\n", kolichSlov );
     return 0;
}