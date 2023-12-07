#include<iostream>
using namespace std;

void InsertionSort(int array[],int size){ 
    for(int i = 1 ; i < size ; i++){ // here index start with 1 to assign previous address to previous array index 
        int temp = array[i]; 
        int j = i - 1; // here previous index is being assigned
        while ( j> -1 && temp < array[j])
        {
            /* code */
            array[j+1] = array[j];
            array[j] = temp;

            j--;
        }
        
    }
}

int main(){
    int myArray[] = {6,4,2,5,1,3};
    int size = sizeof(myArray)/sizeof(myArray[0]);

    InsertionSort(myArray,size);
    for(auto value: myArray){
        cout << value << " ";
    }
}