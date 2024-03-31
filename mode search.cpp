#include <iostream>
#include <ctime>
#include <utility>
#include <stdlib.h>
#include "print.h"

using namespace std;

//функция поиска моды
void mode_search(int *array, int length){
    int num = 0; // число, которое повторяется
    int index = 0; // индекс первого элемента в моде
    int count = 1; // кол-во повторнений 
    int max_count = 1; 

    for (int i=1; i<length; ++i){
        if (array[i] == array[i-1]) {
            count++;
        } else {
            count = 1;
        }

        if (count > max_count) {
            max_count = count;
            index = i - max_count + 1;
            num = array[index];
            
        }
    }

    if (max_count == 1) {
        printf("no mode");
    } else {
        printf("mode = %i\nlength = %i\nnum = %i",index,max_count,num);
    }
}

//функция быстрой сортировки
void sort(int* array, int left, int right){
    if(left>right) return;
    int pivot = array[(left+right)/2];
    int i = left;
    int j = right;
    while(i<=j){
        while (array[i]< pivot) ++i;
        while (array[j]> pivot) --j;
        if(i<=j){
            swap(array[i],array[j]);
            ++i;
            --j;
        }
    }   
    sort(array, left, j);
    sort(array, i, right);
}


int main(){
    clock_t start = clock();

    srand(time(NULL));
    const int length = 10;

    int *arr = new int[length];
    for (int i=0; i<length; i++) {
        arr[i] = rand() % 51;
    }
    
    sort(arr, 0, length - 1);
    mode_search(arr, length);

    delete[] arr;

    clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\ntime = %.5f sec\n", seconds);

    return 0;
}