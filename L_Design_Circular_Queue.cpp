class MyCircularQueue {
    int *arr;
    int size;
    int front;
    int rear;
public:
    MyCircularQueue(int k) {
        size = k;
        arr = new int[size];
        front = -1;
        rear = -1;
    }
    
    bool enQueue(int value) {
        //check for full
        if((front == 0 && rear == size - 1) || (rear == (front - 1)))
        {
            return false;
        }
        else if(front == -1) front = rear = 0; //if value is first element to be inserted
        else if(rear == size -1 && front != 0) rear = 0; //rear is at last and making it circularly 0
        else rear++; //normal case

        arr[rear] = value;
        return true;
    }
    
    bool deQueue() {
        if(front == -1) return false; //empty condition

        int popped = arr[front];
        arr[front] = -1;

        if(front == rear) front = rear = -1; //if there was only single element
        else if(front == size-1) front = 0; //circular increament of front
        else front++; //normal case

        return true;
    }
    
    int Front() {
        if(front == -1) return -1;
        else return arr[front];
    }
    
    int Rear() {
        if(front == -1) return -1;
        else return arr[rear];
    }
    
    bool isEmpty() {
        //empty condition
        if(front == -1) return true;
        else return false;
    }
    
    bool isFull() {
        //full condition
        if((front == 0 && rear == size - 1) || (rear == (front - 1)))
        {
            return true;
        }
        else return false;
    }
};