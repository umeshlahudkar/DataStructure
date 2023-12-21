#include <iostream>
using namespace std;


class Node{
    public:
       int data;
       Node* next;

       Node(int data) {
        this->data = data;
        next = nullptr;
       }
};


class LinkList{

    private: 
        Node* head;

    public : 
        LinkList() : head(nullptr) {}
        
        void InsertAtHead(int data) {
            if(head == nullptr) {
                head = new Node(data);
            }
            else {
                Node* temp = new Node(data);
                temp->next = head;
                head = temp;
            }
        }

        void InsertAtTail(int data) {
            if(head == nullptr) {
                 head = new Node(data);
                 return;
            }

            Node* temp = head;
            while (temp->next != nullptr) 
            {
                temp = temp->next;
            }
            
            temp->next = new Node(data);

        }

        void InsertAt(int index, int data) {

            if(head == nullptr && index > 0) {return;}
            if(head == nullptr && index == 0) {
                head = new Node(data);
                return;
            }

            if(index == 0) {
                Node* temp = new Node(data);
                temp->next = head;
                head = temp;
                return;
            }

            int count = -1;
            Node* currentNode = head;
            Node* prevNode = head;

            while(prevNode != nullptr) {
                count++;

                if(index == count) {
                    Node* temp = new Node(data);
                    temp->next = currentNode;
                    prevNode->next = temp;
                    break;
                }
                prevNode = currentNode;

                if(currentNode != nullptr) {
                    currentNode = currentNode->next;
                }
            }
        }

        void DeleteAtHead() {
            if(head == nullptr) {return;}

            Node* temp = head;
            head = head->next;
            delete temp;
        }

        void DeleteAtTail() {
            if(head == nullptr) {return;}
            
            if(head->next == nullptr) {
                delete head;
                head = nullptr;
                return;
            }

            Node* current = head;
            Node* prev = head;

            while(current->next != nullptr) {

                prev = current;
                current = current->next;
            }
            
            delete current;
            prev->next = nullptr;
        }

        void DeleteData(int data) {
            if(head == nullptr) {return;}

            if(head->data == data) {
                Node* temp = head;
                head = head->next;
                delete temp;
                return;
            }

            Node* current = head;
            Node* prev = head;

            while (current != nullptr)
            {
                if(current->data == data) {
                    prev->next = current->next;
                    delete current;
                    break;
                }

                prev = current;
                current = current->next;
            }
        }

        void DeleteAt(int index) {
            if(head == nullptr) { return;}

            if(index == 0) {
                Node* temp = head;
                head = head->next;
                delete temp;
                return;
            }

            int count = -1;
            Node* current = head;
            Node* prev = head;

            while(current != nullptr) {
                count++;

                if(count == index) {
                    prev->next = current->next;
                    delete current;
                    break;
                }

                prev = current;
                current = current->next;
            }
        }

        void Print() {
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
    LinkList list;
    list.InsertAtTail(5);
    list.InsertAtTail(10);
    list.InsertAtTail(15);

    // list.InsertAt(0,1);
   
    list.DeleteAt(3);

    list.Print();
    return 0;
}