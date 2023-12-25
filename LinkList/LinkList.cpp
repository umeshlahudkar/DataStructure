#include <iostream>
#include <unordered_set>
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

        Node*& GetHead() {return head;}

        void SetHead(Node*& node) {
            head = node;
        }
       
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
        
        void MaKeCircular() {
            if(head == nullptr) {return;}

            Node* temp = head;

            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            
            temp->next = head->next;
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


void RemoveNthNodeFromEnd(Node*& head , int n) {
    if(head == nullptr) {return;}
 
    Node* slow = head;
    Node* fast = head;

    while (n > 0)
    {
        fast = fast->next;
        n--;
    }
    
    if(fast == nullptr) {
        if(head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }

        Node* removeNode = head;
        head = head->next;

        removeNode->next = nullptr;
        delete removeNode;
        return;
    }
    
    while (fast != nullptr && fast->next != nullptr)
    {
        fast = fast->next;
        slow = slow->next;
    }
    
    Node* temp = slow->next;
    slow->next = slow->next->next;

    delete temp;
}

Node* GetMiddleNode(Node*& head) {

    if(head == nullptr) {return nullptr;}
    
    Node* slow = head;
    Node* fast = head;

    while(fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow;
}

void RemoveDuplicatesFromSorted(Node*& head) {
    if(head == nullptr || head->next == nullptr) {return;}

    Node* current = head->next;
    Node* prev = head;

    while (current != nullptr)
    {
        if(current->data == prev->data) {
            Node* temp = current;
            current = current->next;

            prev->next = current;
            temp->next = nullptr;
            delete temp;
        }
        else {
            prev = prev->next;
            current = current->next;
        }
    }
}

void RemoveDuplicatesFromUnsorted(Node*& head) {

    if(head == nullptr || head->next == nullptr) {return;}

    unordered_set<int> seen;
    seen.insert(head->data);

    Node* current = head->next;
    Node* prev = head;

    while (current != nullptr) {
        if (seen.find(current->data) != seen.end()) {
            Node* temp = current;
            prev->next = current->next;
            current = current->next;
            delete temp;
        } else {
            seen.insert(current->data);
            prev = prev->next;
            current = current->next;
        }
    }
}

Node* MergeTwoList(Node* head1, Node* head2) {

    Node* head = new Node(0);
    Node* current = head;

    while (head1 != nullptr && head2 != nullptr)
    {
        if(head1->data <= head2->data) {
            current->next = head1;
            head1 = head1->next;

            current = current->next;
        }
        else {
            current->next = head2;
            head2 = head2->next;

            current = current->next;
        }
    }

    if(head1 == nullptr) {
        current->next = head2;
    }

    if(head2 == nullptr) {
        current->next = head1;
    }

    return head->next;
}

bool IsLoopPresent(Node* head) {
    if(head == nullptr || head->next == nullptr) {return false;}
    
    Node* slow = head;
    Node* fast = head;

    while(fast != nullptr && fast->next != nullptr) {

        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) {
            return true;
        }

    }
    return false;
}

int GetLengthOfLoop(Node* head) {
    if(head == nullptr || head->next == nullptr) {return 0;}

    Node* slow = head;
    Node* fast = head;

    bool isLoopFound = false;

    while(fast != nullptr && fast->next != nullptr) {

        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) {
           isLoopFound = true;
           break;
        }
    }
    
    if(!isLoopFound) {return 0;}

    int count = 1;
    fast = fast->next;

    while (slow != fast)
    {
        count++;
        fast = fast->next;
    }
    return count;
}

Node* GetStartingNodeOfLoop(Node* head) {
     if(head == nullptr || head->next == nullptr) {return nullptr;}
    
    Node* slow = head;
    Node* fast = head;

    bool isLoopPresent = false;

    while(fast != nullptr && fast->next != nullptr) {

        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) {
            isLoopPresent = true;
            break;
        }

    }
    
    if(!isLoopPresent) {return nullptr;}

    slow = head;

    while (fast->next != slow->next)
    {
        slow = slow->next;
        fast = fast->next;
    }

    return slow->next;
}

int main() {

    int arr1[] = {1,3,5,7};
    int size1 = sizeof(arr1)/sizeof(arr1[0]);

    LinkList list1;
    list1.ConstructFromArray(arr1, size1);

    list1.Print();

    list1.MaKeCircular();

    Node* loopNode = GetStartingNodeOfLoop(list1.GetHead());

    cout<< "length of loop : "<< loopNode->data << endl;

    return 0;
}