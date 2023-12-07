#include<iostream>
using namespace std;

void merge(int arr[], int  leftIndex,int midIndex , int rightIndex){   //conquer
    int LeftarraySize = (midIndex - leftIndex) +1;
    int RightarraySize = (rightIndex - midIndex);

    int leftArray[LeftarraySize];
    int rightArray[RightarraySize];
    int index = 0;
    for(int i = 0 ; i < LeftarraySize  ; i++){
        leftArray[i] = arr[leftIndex + i];
       
    }
    for(int i = 0 ; i < RightarraySize; i++ ){
        rightArray[i] = arr[(midIndex + 1) + i];
        // index++;
    }
    // int arr_size = rightIndex+1;
    index = leftIndex;
    int il = 0;
    int ir = 0;
    
    while( il < LeftarraySize && ir < RightarraySize){
        if(leftArray[il] <= rightArray[ir]){
            arr[index] = leftArray[il];
            index++;
            il++;
        }
        else{
            arr[index] = rightArray[ir];
            index++;
            ir++;
        }
    }
    while(il < LeftarraySize){
        arr[index] = leftArray[il];
        index++;
        il++;
    }
    while(ir < RightarraySize){
        arr[index] = rightArray[ir];
        index++;
        ir++;
    }

}
void mergeSort(int array[], int leftIndex, int rightIndex){   // Divide
    if(leftIndex >= rightIndex) return;
    int midIndex = leftIndex + (rightIndex - leftIndex)/2;
    // cout << midIndex<<endl;
    // cout << array[midIndex]<<endl;
    mergeSort(array, leftIndex , midIndex);
    mergeSort(array, midIndex + 1 , rightIndex);
    
    merge(array,leftIndex,midIndex,rightIndex);
}
/*
    "The error is in the assignment midIndex = leftIndex + (rightIndex - leftIndex)/2; 
        which can lead to overflow and should be replaced by 
    "midIndex = leftIndex + (rightIndex - leftIndex)/2 " .
*/

/*

BLOG ›
Extra, Extra - Read All About It: Nearly All Binary Searches and Mergesorts are Broken
FRIDAY, JUNE 02, 2006
Posted by Joshua Bloch, Software Engineer



I remember vividly Jon Bentley's first Algorithms lecture at CMU, where he asked all of us incoming Ph.D. students to write a binary search, and then dissected one of our implementations in front of the class. Of course it was broken, as were most of our implementations. This made a real impression on me, as did the treatment of this material in his wonderful Programming Pearls (Addison-Wesley, 1986; Second Edition, 2000). The key lesson was to carefully consider the invariants in your programs.

Fast forward to 2006. I was shocked to learn that the binary search program that Bentley proved correct and subsequently tested in Chapter 5 of Programming Pearls contains a bug. Once I tell you what it is, you will understand why it escaped detection for two decades. Lest you think I'm picking on Bentley, let me tell you how I discovered the bug: The version of binary search that I wrote for the JDK contained the same bug. It was reported to Sun recently when it broke someone's program, after lying in wait for nine years or so.

So what's the bug? Here's a standard binary search, in Java. (It's one that I wrote for the java.util.Arrays):

1:     public static int binarySearch(int[] a, int key) {
2:         int low = 0;
3:         int high = a.length - 1;
4:
5:         while (low <= high) {
6:             int mid = (low + high) / 2;
7:             int midVal = a[mid];
8:
9:             if (midVal < key)
10:                 low = mid + 1
11:             else if (midVal > key)
12:                 high = mid - 1;
13:             else
14:                 return mid; // key found
15:         }
16:         return -(low + 1);  // key not found.
17:     }

The bug is in this line:
 6:             int mid =(low + high) / 2;

In Programming Pearls Bentley says that the analogous line "sets m to the average of l and u, truncated down to the nearest integer." On the face of it, this assertion might appear correct, but it fails for large values of the int variables low and high. Specifically, it fails if the sum of low and high is greater than the maximum positive int value (231 - 1). The sum overflows to a negative value, and the value stays negative when divided by two. In C this causes an array index out of bounds with unpredictable results. In Java, it throws ArrayIndexOutOfBoundsException.

This bug can manifest itself for arrays whose length (in elements) is 230 or greater (roughly a billion elements). This was inconceivable back in the '80s, when Programming Pearls was written, but it is common these days at Google and other places. In Programming Pearls, Bentley says "While the first binary search was published in 1946, the first binary search that works correctly for all values of n did not appear until 1962." The truth is, very few correct versions have ever been published, at least in mainstream programming languages.

So what's the best way to fix the bug? Here's one way:
 6:             int mid = low + ((high - low) / 2);

Probably faster, and arguably as clear is:
 6:             int mid = (low + high) >>> 1;

In C and C++ (where you don't have the >>> operator), you can do this:
 6:             mid = ((unsigned int)low + (unsigned int)high)) >> 1;

And now we know the binary search is bug-free, right? Well, we strongly suspect so, but we don't know. It is not sufficient merely to prove a program correct; you have to test it too. Moreover, to be really certain that a program is correct, you have to test it for all possible input values, but this is seldom feasible. With concurrent programs, it's even worse: You have to test for all internal states, which is, for all practical purposes, impossible.

The binary-search bug applies equally to mergesort, and to other divide-and-conquer algorithms. If you have any code that implements one of these algorithms, fix it now before it blows up. The general lesson that I take away from this bug is humility: It is hard to write even the smallest piece of code correctly, and our whole world runs on big, complex pieces of code.

We programmers need all the help we can get, and we should never assume otherwise. Careful design is great. Testing is great. Formal methods are great. Code reviews are great. Static analysis is great. But none of these things alone are sufficient to eliminate bugs: They will always be with us. A bug can exist for half a century despite our best efforts to exterminate it. We must program carefully, defensively, and remain ever vigilant.*/


/*


#include <iostream>
using namespace std;

int main ()
{
  unsigned int  low = 33,  
                high = 4294967290, 
                mid;

  cout << "The value of low is " << low << endl;
  cout << "The value of high is " << high << endl;

  mid = (low + high) / 2;

  cout << "The value of mid is " << mid << endl;
  
  return 0;
}
If you run it on a Mac:

$ g++ try.cpp && ./a.out
The value of low is 33
The value of high is 4294967290
The value of mid is 13
The value of mid might be expected to be 2147483661, but low + high overflowed because a 32-bit unsigned integer cannot contain the proper value, and give back 27, and so mid becomes 13.

When the calculation of mid is changed to

mid = low + (high - low) / 2;
Then it will show

The value of mid is 2147483661
The simple answer is, the addition l + u can overflow, and has undefined behavior in some languages, as described in a blog post by Joshua Bloch, about a bug in the Java library for the implementation of binary search.

Some readers may not understand what it is about:

l + (u - l) / 2
Note that in some code, the variable names are different, and it is

low + (high - low) / 2
The answer is: let's say if you have two numbers: 200 and 210, and now you want the "middle number". And let's say if you add any two numbers and the result is greater than 255, then it can overflow and the behavior is undefined, then what can you do? A simple way is just to add the difference between them, but just half of it, to the smaller value: look at what the difference is between 200 and 210. It is 10. (You can consider it the "difference" or "length", between them). So you just need to add 10 / 2 = 5 to 200, and get 205. You don't need to add 200 and 210 together first -- and that's how we can reach the calculation: (u - l) is the difference. (u - l) / 2 is half of it. Add that to l and we have l + (u - l) / 2.

It is like, if we are looking at two trees, one is 200 feet tall and one is 210 feet tall, what is the "midpoint" or the "mean"? We don't have to add them together first. We can just tell the difference is 10 feet, and we can add half of that, which is 5, to 200, and we know it is 205 feet.

To put this into history perspectives, Robert Sedgewick mentioned that the first binary search was stated in 1946, and it wasn't correct until 1964. Jon Bentley described in his book Programming Pearls in 1988 that more that 90% of the professional programmers could not write it correctly given a couple of hours. But even Jon Bentley himself had that overflow bug for 20 years. A study that was published in 1988 showed that accurate code for binary search was only found in 5 out of 20 textbooks. In 2006, Joshua Bloch wrote that blog post about the bug about calculating the mid value. So it took 60 years for this code to be correct. But now, next time in the job interview, remember to write it correctly within that 5 minutes.

*/

/*

The problem is that (l+u) is evaluated first, and could overflow int, so (l+u)/2 would return the wrong value.

*/