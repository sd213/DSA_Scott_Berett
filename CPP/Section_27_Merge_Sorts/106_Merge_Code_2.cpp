#include <iostream>
using namespace std;

void merge( int array[] , int leftIndex, int midIndex,int rightIndex){
   

    int leftArraySize = midIndex - leftIndex + 1;
    int rightArraySize = rightIndex - midIndex;

    int leftArray[leftArraySize];
    int rightArray[rightArraySize];

    for(int i = 0; i < leftArraySize ; i++){
        leftArray[i] = array[leftIndex + i];
    }
    for(int j = 0; j < rightArraySize ; j++){
        rightArray[j] = array[midIndex + 1 + j];
    }

    int index = leftIndex;
    int i = 0;
    int j = 0;

    while( i < leftArraySize && j < rightArraySize){
        if(leftArray[i] <= rightArray[j]){
            array[index] = leftArray[i];
            index++ ;
            i++ ;
        }
        else{
            array[index] = rightArray[j];
            index++;
            j++;
        }
    }
    while( i < leftArraySize){
        array[index] = leftArray[i];
        index++ ;
        i++;
    }

    while(j < rightArraySize){
        array[index] = rightArray[j];
        index++;
        j++;
    }
}

int main(){
    // here those array suppose not to work that is why merge sort function is needed to sort both "left" and "right" side "recursively";
    // int myArray[]= {1,3,7,8,2,4,5,6,45,56,12,13};
    // int myArray[] = { 1, 3 ,7 ,8 ,2 ,3 ,90,1,12,-5,2342 ,34, 324234, 41, 12 ,54 ,667, 9, 83,2, 1 ,4353 ,454,4 , 5, 6};
    
    int myArray[] = { 1,3,7,8,2,4,5,6 }; // this array will be sort in only pass. as it contains SORTED LEFT SUB ARRAY AND RIGHT SUB ARRAY
    int size = sizeof(myArray) / sizeof(myArray[0]);

    int leftIndex = 0;
    int rightIndex = size - 1;
    int midIndex = (size / 2) - 1;

    merge(myArray , leftIndex , midIndex , rightIndex);

    for(auto value : myArray){
        cout << value << " ";
    }    
}