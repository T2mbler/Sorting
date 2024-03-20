#include <iostream>
#include <utility>
#include <ctime>

using namespace std;

int main(){

srand(time(NULL));
const int length = 100000;
int array [length];
int64_t counter = 0;

for (int i = 0; i<length; ++i){
   array[i] = rand()%50+1;
} // заполнения массива случайными числами от 0 до 50

//for(int i = 0; i<length; ++i){
//    cout << array[i] << " ";
//}
//cout << endl;

for(int i = 0; i<length-1; ++i){
    for(int j = 0; j<length-1-i; ++j){
        if(array[j]>array[j+1]){
            swap(array[j],array[j+1]);
            counter = counter + 1;
        }
    }
} 

//for (int i = 0; i<length; ++i){
//    cout << array[i] << " ";
//}
cout << endl << '\n' << clock()/1000.0 << '\n' << counter;
    return 0;
}


