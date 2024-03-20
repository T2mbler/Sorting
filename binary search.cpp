#include <iostream> 
#include <utility>
#include <ctime>

using namespace std;

int64_t counter = 0;

void arr(int array[], int length){
    for (int i=0; i<length; i++){
        array[i] = i + 1;
    }

    //for(int i=0; i<length; i++){
    //    cout << " " << array[i];
    //}
    printf("\n");



}

void sort(int array[], int left, int right){
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

void binary_search (int array[], int length, int key){
    bool flag = false;
    int mid;
    int left = 0;
    int right = length-1;
    //for(int i=0; i<right+1; i++){
    //    cout << " " << array[i];
    //}

    
    
    while((left <= right) && (flag!=true)){
        counter = counter + 1;
        mid = (left+right)/2;
        if(array[mid]==key){
            flag =true;
        }
        if(array[mid]>key){
            right = mid - 1;
        } else{
            left = mid + 1;
        }
    }

    if(flag){
        printf("\nindex key=%i",mid);
    }else{
        printf("\nthere is no sucn key");
    }
}

int main() {
    clock_t start = clock();
    srand(time(NULL));
        
    const int length = 1000000;
    int array[length];
    

    arr(array, length);
    int key = array[length-1];
    sort(array, 0, length - 1);
    binary_search(array, length, key);
    


    clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\ntime = %.3f sec\nreturns = %lli\n", seconds, counter);


    return 0;
}