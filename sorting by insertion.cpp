#include <iostream>
#include <utility>
using namespace std;

int main(){
int array[] = { 7, 5, 6, 4};
const int length = sizeof(array)/sizeof(array[0]);
int counter = 0;

for (int i = 0; i<length-1; ++i){
    while(i>=0 && array[i+1]<array[i]){
        swap(array[i],array[i+1]);
        i=i-1;
        counter = counter + 1;
    }
}


for (int i = 0; i<length; ++i){
    cout << array[i] << " ";
} 

cout << "\n" <<counter;
    return 0;
}