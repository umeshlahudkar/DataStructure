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

        void PrintReverse() {
            cout<< "Reverse Print :";
            Node* temp = head;

            while (temp->next != nullptr)
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

    list.InsertAtTail(1);
    list.InsertAtTail(2);
    list.InsertAtTail(3);

    list.InsertAtHead(10);

    list.Print();
    list.PrintReverse();
    return 0;
}
