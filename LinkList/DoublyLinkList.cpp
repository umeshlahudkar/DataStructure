#include <iostream>
using namespace std;


class Node{
    public:
        int data;
        Node* next;
        Node* prev;

        Node(int value) : data(value), next(nullptr), prev(nullptr){}
};

class DoublyLinkList {

    private:
        Node* head;

    public:
        DoublyLinkList() : head(nullptr) {}

        void InsertAtHead(int data) {
            if(head == nullptr) {
                head = new Node(data);
            }
            else {
                Node* newNode = new Node(data);
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
        }

        void InsertAtTail(int data) {
            if(head == nullptr) {
                head = new Node(data);
            }
            else {
                Node* newNode = new Node(data);

                Node* temp = head;
                while (temp->next != nullptr)
                {
                    temp = temp->next;
                }
                
                temp->next = newNode;
                newNode->prev = temp;
            }
        }

        void InsertAtIndex(int index, int data) {
            if(head == nullptr && index > 0) {return;}
            if(head == nullptr && index == 0) {
                head = new Node(data);
                return;
            }

            if(index == 0) {
                Node* newNode = new Node(data);
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
                return;
            }

            int count = -1;
            Node* temp = head;

            while (temp != nullptr)
            {
                count++;
                if(index == count) {
                    Node* newNode = new Node(data);
                    newNode->next = temp;
                    newNode->prev = temp->prev;
                    temp->prev->next = newNode;
                    temp->prev = newNode;
                    break;
                }
                temp = temp->next;
            }
        }

        void PrintReverse() {
            cout<< "Reverse Print :";
            Node* temp = head;

            while (temp != nullptr && temp->next != nullptr)
            {
                temp = temp->next;
            }

            while (temp != nullptr)
            {
                cout<< temp->data << " ";
                temp = temp->prev;
            }
            cout<<endl;
        }

        void Print() {
            cout<< "Forward Print :";
            Node* temp = head;

            while (temp != nullptr) 
            {
                cout<< temp->data << " ";
                temp = temp->next;
            }
            cout<<endl;
        }

};

int main() {

    DoublyLinkList list;

    //list.InsertAtTail(1);
    //list.InsertAtTail(2);
    //list.InsertAtTail(3);

    list.InsertAtIndex(0, 4);
    list.InsertAtIndex(0, 3);
    list.InsertAtIndex(1, 5);

    list.Print();
    list.PrintReverse();
    return 0;
}
