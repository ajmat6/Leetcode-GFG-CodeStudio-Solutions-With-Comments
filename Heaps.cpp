#include<iostream>
using namespace std;

class Heap
{
    public:
    int arr[100];
    int size;

    Heap()
    {
        arr[0] = -1;
        size = 0;
    }

    void insert(int data)
    {
        size = size + 1;
        int index = size;
        arr[index] = data;

        while(index > 1)
        {
            int parentIndex = index / 2;

            if(arr[parentIndex] < arr[index])
            {
                // swaping if Max Heap condition is violated:
                // int temp = arr[parentIndex];
                // arr[parentIndex] = arr[index];
                // arr[index] = temp;
                swap(arr[parentIndex], arr[index]);

                // after swaping we will check similarly like this for its parent so making index as parentIndex:
                index = parentIndex;
            }

            else
            {
                return; // as it is following the Max Heap condition
            }
        }
    }

    void printHeap()
    {
        cout << "Printing the Heap (Max Heap)" << endl;

        for(int i=1; i<=size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Heap h;
    h.insert(2);
    h.insert(56);
    h.insert(24);
    h.insert(87);
    h.insert(29);
    h.insert(5);

    h.printHeap();

    return 0;
}