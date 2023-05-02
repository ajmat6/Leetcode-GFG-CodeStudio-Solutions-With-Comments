#include <bits/stdc++.h> 
class Queue {
    int *arr;
    int size = 100001;
    int rear;
    int frnt;
public:
    Queue() {
        arr = new int[size];
        frnt = 0;
        rear = 0;
    }

    bool isEmpty() {
        if(frnt == rear) return true;
        else return false;
    }

    void enqueue(int data) {
        if(rear == size-1)
        {
            cout << "Queue is full" << endl;
        }

        else
        {
            arr[rear] = data;
            rear++;
        }
    }

    int dequeue() {
        if(rear == frnt) return -1;

        int ans = arr[frnt];
        arr[frnt] = -1;
        frnt++;

        if(frnt == rear)
        {
            frnt = 0;
            rear = 0;
        }
        return ans;
    }

    int front() {
        if(frnt == rear) return -1;
        else return arr[frnt];
    }
};