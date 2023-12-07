

void merge( int array[] , int leftIndex, int midIndex,int rightIndex){
   

// Declaration with Initialization of Size of Arrays  
    int leftArraySize = midIndex - leftIndex + 1;
    int rightArraySize = rightIndex - midIndex;

// child Arrays Declaration
    int leftArray[leftArraySize];
    int rightArray[rightArraySize];

// Assigning/Storing values of parent aray elements in Child Arrays
    for(int i = 0; i < leftArraySize ; i++){
        leftArray[i] = array[leftIndex + i];
    }
    for(int j = 0; j < rightArraySize ; j++){
        rightArray[j] = array[midIndex + 1 + j];
    }

    
}

















