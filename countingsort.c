#include "utils.h"

#define SIZE 100000

void methodOfCalculationCountingSortOfCalculation(long int n, long int arr[], long int sortedArr[]) {
    long int k;
    for (long int i = 0; i < n; i++) {
        k = 0;
        for (long int j = 0; j < n; j++) {
            if (arr[i] > arr[j]) {
                k++;
            }
        }
        sortedArr[k] = arr[i];
    }
}

int countingSort(void) {
    //выделение памяти под массивы
    long int *arr, *sortedArr;
    
    arr = (long int *)malloc(SIZE * sizeof(int));
    sortedArr = (long int *)malloc(SIZE * sizeof(int));
    
    // Заполнение массива случайными числами
    for (long int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 201 - 100;
    }
    
    //сортировка методом подсчета
    methodOfCalculationCountingSortOfCalculation(SIZE, arr, sortedArr);
    
    // Вывод элементов массива после сортировки (использовать только для SIZE <50)
    /*
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", sortedArr[i]);
    }
     */
    printf("\n");
    //освобождение памяти
    free(arr);
    free(sortedArr);
    return 0;
}
