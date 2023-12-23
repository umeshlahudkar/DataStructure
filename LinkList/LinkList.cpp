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
       
        void ConstructFromArray(int arr[], int size) {
            head = nullptr;
            if(size <= 0) {return;}
            if(head == nullptr) {
                head = new Node(arr[0]);
            }
 
            Node* temp = head;
            for(int i = 1; i < size; i++) {
                Node* newNode = new Node(arr[i]);
                temp->next = newNode;
                temp = newNode;
            }
        }
        
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

        void Reverse() {
            if(head == nullptr || head->next == nullptr) {return;}

            Node* prev = nullptr;
            Node* current = head;
            Node* next = head->next;

            while (current != nullptr)
            {
                current->next = prev;

                prev = current;
                current = next;

                if(next != nullptr) {
                    next = current->next;
                }
            }
            head = prev;
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

         ~LinkList() {
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

    int arr[] = {1,2,3,4,5};
    int size = sizeof(arr)/sizeof(arr[0]);

    LinkList list;
   
    list.ConstructFromArray(arr, size);

    list.InsertAt(0,6);
    list.Reverse();

    list.Print();
    return 0;
}