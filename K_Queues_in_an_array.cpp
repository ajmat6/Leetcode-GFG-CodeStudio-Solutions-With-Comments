#include<iostream>
using namespace std;

class KQueue
{
    public:
    int *arr;
    int *front;
    int *rear;
    int *next;
    int freespot;

    KQueue(int n, int k)
    {
        arr = new int[n];
        next = new int[n];
        front = new int[k];
        rear = new int[k];
        freespot = 0;

        //making all values in front and rear arrays to -1
        for(int i=0; i<k; i++)
        {
            front[i] = -1;
            rear[i] = -1;
        }

        //storing next free space in the next array
        for(int i=0; i<n; i++)
        {
            next[i] = i+1;
        }
        next[n-1] = -1;
    }

    void Enqueue(int qn, int data)
    {
        //full condition
        if(freespot == -1)
        {
            cout << "Full" << endl;
            return;
        }

        //index where element will be pushed in arr array
        int index = freespot;

        //updating freespot
        freespot = next[index];

        //pushing into arr array
        arr[index] = data;

        // conditions for push: first time or else:
        if(front[qn - 1] == -1)
        {
            front[qn - 1] = index;
            rear[qn - 1] = index;
        }
        else
        {
            next[rear[qn -  1]] = index;
            rear[qn - 1] = index;
        }

        //updating next arrary at the push position
        next[index] = -1;
    }

    int Dequeue(int qn)
    {
        //empty condition
        if(front[qn - 1] == -1)
        {
            cout << "Empty" << endl;
            return -1;
        }

        //finding front element position
        int index = front[qn - 1];

        //updating front array
        front[qn - 1] = next[index];

        //updating freespot in next array
        next[index] = freespot;
        freespot = index;

        return arr[index];
    }
};

int main()
{
    KQueue ajmat(6,3);
    ajmat.Enqueue(1,5);
    ajmat.Enqueue(1,10);
    ajmat.Enqueue(2,6);
    ajmat.Enqueue(1,15);

    cout << ajmat.Dequeue(1) << endl;
    cout << ajmat.Dequeue(2) << endl;
    cout << ajmat.Dequeue(1) << endl;
    cout << ajmat.Dequeue(1) << endl;
    cout << ajmat.Dequeue(1) << endl;
    cout << ajmat.Dequeue(2) << endl;

    return 0;
}