#include "utils.h"

#define SIZE 20

int DAE(long int a[], long int n) {
   int i, j, count = 1;

    for (i = 1; i < n; i++) {
        for (j = 0; j < i; j++) {
            if (a[i] == a[j])
                break;
        }
      if (i == j)
         count++;
    }
   return count;
}

void methodOfCalculationCountingSort(long int lenght, long int arr[], long int helpArr[]) {
    for (size_t i = 0; i < lenght; i++) {
        helpArr[arr[i]]++;
        arr[i] = 0;
    }

    int NumberInArray = 0;
    for (size_t i = 0; i < lenght; i++) {
        int temp = i;
        while(helpArr[temp]) {
            arr[NumberInArray] = temp;
            NumberInArray++;
            helpArr[temp]--;
        }
    }
}

int countingSort(void) {
    long int *arr, *helpArr; //выделение памяти под массивы
    
    arr = (long int *)malloc(SIZE * sizeof(long int));
    
    for (long int i = 0; i < SIZE; i++) { // Заполнение массива случайными числами
        arr[i] = rand() % 200;
    }
    
    int lenght = DAE(arr, SIZE);
    helpArr = (long int *)calloc(lenght, sizeof(long int));

    methodOfCalculationCountingSort(SIZE, arr, helpArr); //сортировка методом подсчета
    
    // Вывод элементов массива после сортировки (использовать только для SIZE <20)
    // printf("\n\n");
    // for (int i = 0; i < SIZE; i++) {
    //     printf("%ld ", arr[i]);
    // }

    free(arr); //освобождение памяти
    free(helpArr);
    return 0;
}
