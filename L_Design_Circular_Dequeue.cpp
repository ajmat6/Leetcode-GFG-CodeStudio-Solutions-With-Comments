class MyCircularDeque {
    int *arr;
    int size;
    int front;
    int rear;
public:
    MyCircularDeque(int k) {
        size = k;
        arr = new int[size];
        front = -1;
        rear = -1;
    }
    
    bool insertFront(int value) {
        if((front == 0 && rear == size - 1) || (rear == front -1)) return false;
        else if(front == -1) front = rear = 0;
        else if(front == 0) front = size - 1;
        else front--;

        arr[front] = value;
        return true;
    }
    
    bool insertLast(int value) {
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
    
    bool deleteFront() {
        if(front == -1) return false; //empty condition

        int popped = arr[front];
        arr[front] = -1;

        if(front == rear) front = rear = -1; //if there was only single element
        else if(front == size-1) front = 0; //circular increament of front
        else front++; //normal case

        return true;
    }
    
    bool deleteLast() {
        if(front == -1) return false; //empty condition

        int popped = arr[rear];
        arr[rear] = -1;

        if(front == rear) front = rear = -1; //if there was only single element
        else if(rear == 0) rear = size - 1; //circular increament of front
        else rear--; //normal case

        return true;
    }
    
    int getFront() {
        if(front == -1) return -1;
        else return arr[front];
    }
    
    int getRear() {
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