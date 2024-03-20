#include <iostream> 
#include <utility>
#include <ctime>

using namespace std;

int64_t counter = 0;

void sort(int array[], int left, int right){
    if(left>right) return;
    counter = counter + 1;
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


int main() {
    clock_t start = clock();
    srand(time(NULL));
        
    const int length = 10;
    int array[length];

    for (int i=0; i<length; i++){
        array[i] = rand() % 10+1;
    }

    for(int i=0; i<length; i++){
        cout << " " << array[i];
    }
    printf("\n");

    sort(array, 0, length - 1);

    for(int i=0; i<length; i++){
        cout << " " << array[i];
    }

    clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\ntime = %.3f sec\nreturns = %lli\n", seconds, counter);


    return 0;
}