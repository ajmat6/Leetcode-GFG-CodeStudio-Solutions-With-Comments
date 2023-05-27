#include<iostream>
#include<queue>
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

    // TC = O(logn)
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

    // TC = O(logn)
    void DeleteFromHeap()
    {
        // B0aseCase: if there is no node in the heap to be deleted:
        if(size == 0)
        {
            cout << "Nothing to delete" << endl;
            return;
        }

        else
        {
            // swaping last and first element:
            swap(arr[1], arr[size]);

            // Deleting the last element:
            size = size - 1;

            // Finding right position for the current root node:
            int index = 1;

            while(index <= size)
            {
                int leftChild = 2 * index;
                int rightChild = 2 * index + 1;

                if(leftChild < size && arr[index] < arr[leftChild])
                {
                    swap(arr[index], arr[2*index]);
                    index = leftChild;
                }

                else if(rightChild < size && arr[index] < arr[rightChild])
                {
                    swap(arr[index], arr[2*index]);
                    index = rightChild;
                }

                else
                {
                    return;
                }
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

// TC = O(logn)
void Heapify(int arr[], int size, int index)
{
    // int NodeIndex = index;
    // int leftChild = 2 * index;
    // int rightChild = 2 * index + 1;


    // while(NodeIndex <= size)
    // {
    //     if(leftChild < size && arr[NodeIndex] < arr[leftChild])
    //     {
    //         swap(arr[NodeIndex], arr[leftChild]);
    //         NodeIndex = leftChild;
    //     }

    //     else if(rightChild < size && arr[NodeIndex] < arr[rightChild])
    //     {
    //         swap(arr[NodeIndex], arr[rightChild]);
    //         NodeIndex = rightChild;
    //     }

    //     else 
    //     {
    //         return;
    //     }
    // }


    // Recursive solution
    int largest = index;
    int leftChild = 2 * index;
    int rightChild = 2 * index + 1;


    if(leftChild <= size && arr[largest] < arr[leftChild])
    {
        largest = leftChild;
    }

    if(rightChild <= size && arr[largest] < arr[rightChild])
    {
        largest = rightChild;
    }

    if(largest != index) // means MAX HEAP conditions violation was there:
    {
        swap(arr[largest], arr[index]); // So swap with their child
        Heapify(arr, size, largest); // now check recursively again for its child
    }
}

void HeapSort(int A[], int n)
{
    while (n > 1)
    {
        // swap first and last element:
        swap(A[1], A[n]);

        // Decrease the size:
        n--;
        
        // Now take first element in the heap to its correct position:
        Heapify(A, n, 1);
    }  
}

int main()
{
    // Heap h;
    // h.insert(55);
    // h.insert(54);
    // h.insert(53);
    // h.insert(50);
    // h.insert(52);

    // h.printHeap();

    // h.DeleteFromHeap();
    // h.printHeap();

    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;

    // heap creation:
    for(int i=n/2; i>0; i--)
    {
        Heapify(arr, n, i);
    }

    cout << "Printing the array after heapify" << endl;
    for(int i=1; i<=n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    HeapSort(arr, n);
    cout << "Printing after heap sort" << endl;
    for(int i=1; i<=n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Max heap Using STL
    priority_queue<int> MaxHeap;
    
    MaxHeap.push(5);
    MaxHeap.push(2);
    MaxHeap.push(1);
    MaxHeap.push(9);
    MaxHeap.push(4);

    cout << "Element at top " << MaxHeap.top() << endl;
    MaxHeap.pop();
    cout << "Element at top " << MaxHeap.top() << endl;

    cout << "Size is " << MaxHeap.size() << endl;

    if(MaxHeap.empty()) cout << "Empty" << endl;
    else cout << "Not empty" << endl;

    // Min heap Using STL
    priority_queue<int, vector<int>, greater<int> > MinHeap;
    
    MinHeap.push(5);
    MinHeap.push(2);
    MinHeap.push(1);
    MinHeap.push(9);
    MinHeap.push(4);

    cout << "Element at top " << MinHeap.top() << endl;
    MinHeap.pop();
    cout << "Element at top " << MinHeap.top() << endl;

    cout << "Size is " << MinHeap.size() << endl;

    if(MinHeap.empty()) cout << "Empty" << endl;
    else cout << "Not empty" << endl;

    return 0;
}