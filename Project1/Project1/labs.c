#include <stdio.h>
#include "labs.h"
#include <malloc.h>
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
    static double power(double base, int exponent) {
    double  result = 1;
    while(exponent > 0) {
    result *= base;
    exponent--;
    }
    return result;
}

int labs1(){
    #define pi 3.14
    #define X 0.33

    double H, r, R, V;
    double result;
    // Ввод данных
    printf("Введите радиус меньшего основания r: ");
    result = scanf_s("%lf", &r);

    printf("Введите высоту усечённого конуса H: ");
    result = scanf_s("%lf", &H);

    printf("Введите радиус боьшего основания R: ");
    result = scanf_s("%lf", &R);

    // Расчет объема усеченного конуса
    V = X * pi * H * ((r * r) + r + R + (R * R));

    // Вывод результата
    printf("Объем оставшейся фигуры: %lf\n", V);
    #undef X
    return 0;
    
}
int labs2(){
    double summ = 1.0; // сумма ряда
    double x; // входной параметр ряда
    int n; // число элементов ряда
    int sign = -1; // знак очередного элемента ряда
    int result;
    // ввод параметров ряда
    printf("Введите положительное целое число n: ");
    result = scanf_s("%d", &n);

    printf("Введите значение x: ");
    result = scanf_s("%lf", &x);

    // вычисление суммы ряда
    for (int i = 1; i <= n; ++i) {
    summ += (double)(sign * power(x, 2 * i)) / factorial(2 * i);
    sign *= -1;
    }

    // вывод результата
    printf("Сумма ряда для x = %.2f с %d элементами равна %.6lf\n", x, n, summ);

    return 0;
}

int labs3()
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
int labs4() {
    char slovo[MAX_WORD_LEN + 1] = "";
    int index = 0;


    char c;

    char predSymvol = 0;

    int kolichestvoSivolovPovtor = 0;





    printf("Vvediye text: \n");



    while ((c = getchar()) != EOF) {

        if (c == ' ' || c == '.' || c == '\n' || c == ',') {

            if (kolichestvoSivolovPovtor > 0) {

                printf("%s\n", slovo);

            }

            kolichestvoSivolovPovtor = 0;
            index = 0;

        }
        else {

            if (index < MAX_WORD_LEN) {

                slovo[index++] = c;
                slovo[index] = 0;
            }

            if (c == predSymvol) {
                kolichestvoSivolovPovtor++;
            }

            predSymvol = c;


        }
    }



    return 0;

}
int Doplabs4() {


    // определение символических констант
#define YES 1
#define NO 0
#define MAXLINE 1000
    char buffer[MAXLINE + 1];
    char c = 0;// текущий символ
    int prev_c;// предыдущий символ
    int flag;// признак слова
    int found; // индикатор того, что искомый признак в слове обнаружен
    int i;  // позиция текущего символа исходной cтроки
    int pos; // позиция текущего символа результирующей строки
    int start; // позиция начала слова 
    int j;// начальные присваивания (инициализация)
    flag = NO;
    found = NO;
    prev_c = ' ';
    start = 0;
    i = 0;
    pos = 0;
    // цикл чтения символов из строки
    while ((c = getchar()) != EOF)
    {
        buffer[i] = c;
        if (c == ' ' || c == '.' || c == ',' || c == '\n' || c == '\0') {
            if (flag == YES) {
                if (found == YES) {
                    for (j = start; j < i; j++) {
                        printf("%c", buffer[j]);
                    }
                    printf(" ");
                }
            }
            flag = NO;
            found = NO;
        }
        else {
            if (flag == NO) {
                start = i;
            }
            if (prev_c == c) {
                found = YES;
            }

            flag = YES;
        }
        prev_c = c;
        i++;
    } 
};


int labs5(){
    int array[10];
    // Ввод массива
    printf("Vvedite 10 chisel:\n");
    for (int i = 0; i < 10; i++) {
        printf("Vvedite chislo: ");
        scanf_s("%d", &array[i]);
    }
    int max_summa = array[0] + array[1];
    int max_index = 0;
    int min_summa = array[0] + array[1];
    int min_index = 0;
    for (int i = 1; i < 9; i++) {
        int sum = array[i] + array[i + 1];
        if (sum > max_summa) {
            max_summa = sum;
            max_index = i;
        }
    }
    for (int i = 1; i < 9; i++) {
        int sum = array[i] + array[i + 1];
        if (sum < min_summa) {
            min_summa = sum;
            min_index = i;
        }
    }
    printf(" Nover pari c max summ i min summ: %d - %d ; %d - %d\n", max_index, max_index + 1, min_index, min_index + 1);

    return 0;
}
int Doplabs5() {
    int array[10] = { 5, 8, 12, 6, 3, 9, 15, 7, 10, 4 };
    int min_summa = array[0] + array[1];
    int min_index = 0;

    for (int i = 1; i < 9; i++) {
        int sum = array[i] + array[i + 1];
        if (sum < min_summa) {
            min_summa = sum;
            min_index = i;
        }
    }

    printf(" Nomer pari c min summ: %d и %d\n", min_index, min_index + 1);

    return 0;
}

int labs6() {
#define K 3
#define N 4
    int x[K][N];
    int i, j;

    // Ввод массива
    for (i = 0; i < K; i++) {
        for (j = 0; j < N; j++) {
            printf("VVedite chislo: ");
            scanf_s("%d", &x[i][j]);
        }
    }
    printf("Vivod bez obnul:\n");
    for (i = 0; i < K; i++) {
        for (j = 0; j < N; j++) {
            printf("%d ", x[i][j]);
        }
        printf("\n");
    }

    // Подсчёт чётных и нечётных элементов в столбцах
    int chet[K] = { 0 }; // Счётчики чётных элементов в столбцах
    int nechet[K] = { 0 }; // Счётчики нечётных элементов в столбцах
    for (i = 0; i < K; i++) {
        for (j = 0; j < N; j++) {
            if (x[i][j] % 2 == 0) {
                chet[i]++;
            }
            else {
                nechet[i]++;
            }
        }
    }


    // Обнуление столбцов чётных элементов
    for (i = 0; i < K; i++) {
        for (j = 0; j < N; j++) {
            if (chet[i] > nechet[i]) {

                x[i][j] = 0;
            }
        }
    }
    // Вывод массива
    printf("Vivod:\n");
    for (i = 0; i < K; i++) {
        for (j = 0; j < N; j++) {
            printf("%d ", x[i][j]);
        }
        printf("\n");
    }
    return 0;

}
int labs7(){
#define K 3
#define N 4

    
        int x[K][N];
        int i, j;

        // Ввод массива
        for (i = 0; i < K; i++) {
            for (j = 0; j < N; j++) {
                printf("VVedite chislo: ");
                scanf_s("%d", &x[i][j]);
            }
        }

        printf("Vivod bez puzur:\n");
        for (i = 0; i < K; i++) {
            for (j = 0; j < N; j++) {
                printf("%d ", x[i][j]);
            }
            printf("\n");
        }

        // Преобразование массива в строку
        int stroka[K * N];
        int k = 0;
        for (i = 0; i < K; i++) {
            for (j = 0; j < N; j++) {
                stroka[k++] = x[i][j];
            }
        }

        // Сортировка строки методом пузырька
        for (i = 0; i < K * N - 1; i++) {
            for (j = 0; j < K * N - i - 1; j++) {
                if (stroka[j] > stroka[j + 1]) {
                    int temp = stroka[j];
                    stroka[j] = stroka[j + 1];
                    stroka[j + 1] = temp;
                }
            }
        }

        // Обратное преобразование строки в двумерный массив
        k = 0;
        for (i = 0; i < K; i++) {
            for (j = 0; j < N; j++) {
                x[i][j] = stroka[k++];
            }
        }

        // Вывод массива
        printf("Vivod:\n");
        for (i = 0; i < K; i++) {
            for (j = 0; j < N; j++) {
                printf("%d ", x[i][j]);
            }
            printf("\n");
        }
        
        return 0;
    }

 int labs8(void) {
     unsigned long long shislo;

     // Ввод числа
     printf("Vvedite celoe chislo: ");
     scanf_s("%llu", &shislo);

     // Вывод исходных байтов
     printf("Ishodn bait chisla: ");
     for (int i = 0; i < sizeof(shislo); i++) {
         printf("%02X ", (unsigned char)(shislo >>(i * 8)));
     }
     printf("\n");

     // Функция для обмена байтов местами
     unsigned long long swapped = 0;
     for (int i = 0; i < sizeof(shislo); i++) {
         swapped = (swapped << 8) | ((shislo >>(i * 8)) & 0xFF);
     }

     // Вывод результата
     printf("Perestavlennye baita chisla: ");
     for (int i = 0; i < sizeof(swapped); i++) {
         printf("%02X ", (unsigned char)(swapped >>(i * 8)));
     }
     printf("\n");

     return 0;
 }

