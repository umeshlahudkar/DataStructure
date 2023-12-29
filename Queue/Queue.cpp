#include <iostream>
#include <stack>
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

class QueueBy2Stack {
    private :
        stack<int> st1, st2;

    public :
        void Enqueue(int data) {
            if(st1.empty()) {
                st1.push(data);
                return;
            }

            while (!st1.empty())
            {
                st2.push(st1.top());
                st1.pop();
            }

            st1.push(data);

            while (!st2.empty())
            {
                st1.push(st2.top());
                st2.pop();
            }
            
        }

        void Dequeue() {
            if(!st1.empty()) {
                st1.pop();
            }
        }

        int Front() {
             if(!st1.empty()) {
                return st1.top();
            }
            return -1;
        }

        bool IsEmpty() {
            return st1.empty();
        }
        
};

int main() {
    QueueBy2Stack que;
    que.Enqueue(10);
    que.Enqueue(20);
    que.Enqueue(30);
    que.Enqueue(40);
    que.Enqueue(50);

   

    que.Dequeue();

    while(!que.IsEmpty()) {
        cout<< que.Front() << " ";
        que.Dequeue();
    }
    cout<<endl;
    
    return 0;
}