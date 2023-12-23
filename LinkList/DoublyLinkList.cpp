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

        void DeleteAtHead() {
            if(head == nullptr) {return;}

            if(head->next == nullptr) {
                delete head;
                head = nullptr;
                return;
            }
            
            Node* temp = head;
            head = head->next;
            head->prev = nullptr;

            temp->next = nullptr;
            temp->prev = nullptr;
            
            delete temp;
        }

        void DeleteAtTail() {
            if(head == nullptr) {return;}

            if(head->next == nullptr) {
                delete head;
                head = nullptr;
                return;
            }

            Node* temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }

            temp->prev->next = nullptr;
            temp->prev = nullptr;
            delete temp;
        }

        void DeleteData(int data) {
            if(head == nullptr) {return;}

            if(head->data == data && head->next == nullptr) {
                delete head;
                head == nullptr;
                return;
            }

            if(head->data == data) {
                Node* temp = head;
                head = head->next;
                
                head->prev = nullptr;
                temp->next = nullptr;

                delete temp;
                return;
            }

            Node* temp = head;
            while (temp != nullptr) 
            {
                if(temp->data == data && temp->next != nullptr) {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;

                    temp->next = nullptr;
                    temp->prev = nullptr;

                    delete temp;
                    break;
                }
                else if(temp->data == data && temp->next == nullptr) {
                    temp->prev->next = nullptr;
                    temp->prev = nullptr;
                    delete temp;
                    break;
                }
                temp = temp->next;
            }
        }

        void DeleteAt(int index) {
            if(head == nullptr) {return;}

            if(index == 0 && head->next == nullptr) {
                delete head;
                head = nullptr;
                return;
            }

            if(index == 0 && head->next != nullptr) {
                Node* temp = head;
                head = head->next;

                head->prev = nullptr;
                temp->next = nullptr;

                delete temp;
                return;
            }

            int count = -1;
            Node* temp = head;
            while (temp != nullptr)
            {
                count++;

                if(count == index) {
                    if(temp->next != nullptr) {
                        temp->prev->next = temp->next;
                        temp->next->prev = temp->prev;

                        temp->next = nullptr;
                        temp->prev = nullptr;

                        delete temp;
                        break;
                    }
                    else if(temp->next == nullptr) {
                        temp->prev->next = nullptr;
                        temp->prev = nullptr;
                        delete temp;
                        break;
                    }
                }

                temp = temp->next;
            }
             
        }

        void Reverse() {
            if(head == nullptr) {return;}

            Node* currentNode = head;
            Node* prevNode = nullptr;

            while (currentNode != nullptr)
            {
                currentNode->prev = currentNode->next;
                currentNode->next = prevNode;

                prevNode = currentNode;
                currentNode = currentNode->prev;
            }

            head = prevNode;
            
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

        ~DoublyLinkList() {
            Node* current = head;

            while (current != nullptr)
            {
                Node* temp = current;
                current = current->next;

                delete temp;
            }

            head = nullptr;
        }
};

int main() {

    DoublyLinkList list;

    list.InsertAtTail(1);
    list.InsertAtTail(2);
    list.InsertAtTail(3);

    list.Reverse();

    list.Print();
    list.PrintReverse();
    return 0;
}
