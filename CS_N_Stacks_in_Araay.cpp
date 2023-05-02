#include <bits/stdc++.h> 
class NStack
{
    //arr array for push and pop operation:
    int *arr;
    //top array for stroring the index of the top element of that stack in the arr array
    int *top;
    //stores next free space or next element after the stack top:
    int *next;
    //n for top array size and s for arr array size:
    int n,s;

    int freespot;
public:
    // Initialize your data structure.
    NStack(int N, int S)
    {
        n = N;
        s = S;

        arr = new int[S];
        top = new int[N];
        next = new int[S];

        //initializing top array:
        for(int i=0; i<n; i++) top[i] = -1;

        //Initializing next array:
        for(int i=0; i<s; i++) next[i] = i + 1;

        //updating last index:
        next[s-1] = -1;

        //initialize free spot:
        freespot = 0;
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        //checking for the overflow condition:
        //when freespot has already reached the last index of the arr arry:
        if(freespot == -1) return false;

        //index where the element will be pushed:
        int index = freespot;

        //updating freespot:
        freespot = next[index];

        //Inserting the element in the arr array:
        arr[index] = x;

        //updating the next array at the index where element is pushed:
        next[index] = top[m-1];

        //updating the top array:
        top[m-1] = index;

        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        //check for the underflow condition:
        if(top[m-1] == -1) return -1;

        int index = top[m-1];

        top[m-1] = next[index];

        next[index] = freespot;

        freespot = index;

        return arr[index];
    }
};