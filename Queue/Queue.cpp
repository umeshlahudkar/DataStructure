#include <iostream>
using namespace std;

class Queue {
    private :
        int* arr;
        int size;
        int front;
        int rear;

    public :
        Queue(int size) {
            this->size = size;
            arr = new int[size];
            front = -1;
            rear = -1;
        }

        void Enqueue(int data) {

            if(rear == size-1) {
                cout<< "Queue is full. can't push "<< data <<endl;
                return;
            }

            if(front == -1) {
                front = 0;
            }

            rear++;
            arr[rear] = data;
        }

        void Dequeue() {
            if(front < 0) {
                cout<<"Queue is empty. can't delete it"<<endl;
                return;
            }
           
            if(front == rear ) {
                front = rear = -1;
            }
            else {
                front++;
            }
        }

        int Front() {
            if(front > -1 ) {
                return arr[front];
            }
        }

        bool IsFull() {return rear == size-1;}
        bool IsEmpty() {return (front == -1 && rear == -1) ;}
};

class CircularQueue {
    private :
        int* arr;
        int size;
        int front;
        int rear;

    public :
        CircularQueue(int size) {
            this->size = size;
            arr = new int[size];
            front = -1;
            rear = -1;
        }

        void Enqueue(int data) {

            if(IsFull()) {
                cout<< "Queue is full. can't push "<< data <<endl;
                return;
            }

            if(front == -1) {
                front = 0;
            }

            rear = (rear+1)%size;
            arr[rear] = data;
        }

        void Dequeue() {
            if(front < 0) {
                cout<<"Queue is empty. can't delete it"<<endl;
                return;
            }
           
            if(front == rear ) {
                front = rear = -1;
            }
            else {
                front = (front + 1)%size;
            }
        }

        int Front() {
            if(front > -1 ) {
                return arr[front];
            }
        }

        bool IsFull() {return (rear+1) % size == front;}
        bool IsEmpty() {return (front == -1 && rear == -1) ;}
};

class Node {
    public :
        int data;
        Node* next;

        Node(int data) {
            this->data = data;
            next = nullptr;
        }
};

class QueueUsingLL {
    private :
        Node* head;
        Node* tail;

    public :
        QueueUsingLL() : head(nullptr), tail(nullptr) {}

        void Enqueue(int data) {
            if(IsEmpty()) {
                head = tail = new Node(data);
            }
            else {
                Node* temp = new Node(data);
                tail->next = temp;
                tail = temp;
            }
        }

        void Dequeue() {
            if(IsEmpty()) {return;}

            Node* temp = head;
            head = head->next;

            if(head == nullptr) {
                tail = nullptr;
            }

            delete temp;
        }

        int Front() {
            if(IsEmpty()) {return -1;}

            return head->data;
        }

        bool IsEmpty() {return (head==nullptr && tail == nullptr);}
};


int main() {
    QueueUsingLL que;
    que.Enqueue(1);
    que.Enqueue(2);
    que.Enqueue(3);
    que.Enqueue(4);
    que.Enqueue(5);

    que.Dequeue();

    que.Enqueue(6);


    while (!que.IsEmpty())
    {
        cout<< que.Front() << " ";
        que.Dequeue();
    }
    
    return 0;
}