#include<iostream>
#include <stack>
using namespace std;

class StackUsingArray{
    private:
        int* arr;
        int stackSize;
        int currentSize;
        int index;

    public :
        StackUsingArray(int size) {
            index = -1;
            stackSize = size;
            currentSize = 0;
            arr = new int[stackSize];
        }

        void Push(int data) {
           if(currentSize < stackSize) {
                index++;
                arr[index] = data;
                currentSize++;
           }
           else {
            cout<< "Can't push. stack full"<<endl;
           }
        }

        int Pop() {
            if(index > -1) {
                int temp = arr[index];
                index--;
                currentSize--;
                return temp;
            }
            else {
                cout<< "size is zero, can't delete" << endl;
            }
            return -1;
        }

        int Top() {
            if(index > -1) {
                return arr[index];
            }
            return -1;
        }

        int Size() {
            return currentSize;
        }

        bool IsEmpty() {
            return currentSize == 0;
        }

        ~StackUsingArray() {
            delete[] arr;
        }
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

class StackUsingLL {
    private :
        Node* head;
        int size;

    public :
        StackUsingLL() : head(nullptr), size(0) {}
        ~StackUsingLL() {
            delete head;
            head = nullptr;
        }

        void Push(int data) {
            if(head == nullptr) {
                head = new Node(data);
            }
            else {
                Node* newNode = new Node(data);
                newNode->next = head;
                head = newNode;
            }
            size++;
        }

        int Pop() {
            if(head == nullptr) {return -1;}

            Node* temp = head;
            head = head->next;

            int data = temp->data;
            delete temp;
            return data;
        }

        int Top() {
            if(head == nullptr) {return -1;}

            return head->data;
        }

        bool IsEmpty() {
            return head == nullptr;
        }

        int Size() {return size;}

};

void PushAtBottom(stack<int>& st, int number) {
    if(st.empty()) {
        st.push(number);
        return;
    }

    int num = st.top();
    st.pop();

    PushAtBottom(st, number);

    st.push(num);
}

void ReverseStack(stack<int>& st) {
    stack<int> temp;

    while(!st.empty()) {
        temp.push(st.top());
        st.pop();
    }

    swap(st, temp);
}

void ReverseStackByRecursion(stack<int>& st) {

    if(st.empty()) {return;}

    int top = st.top();
    st.pop();

    ReverseStackByRecursion(st);

    PushAtBottom(st, top);

}

bool IsBalancedParanthesis(string str) {

    stack<char> st;
    for(int i = 0; i < str.length(); i++) {
        if(str[i] == '[' || str[i] == '{' ||str[i] == '(') {
            st.push(str[i]);
        }
        else {
            if(st.empty()) {return false;}

            char c = st.top();
            st.pop();
            if((str[i] == ']' && c != '[') ||
             (str[i] == '}' && c != '{') ||
             (str[i] == ')' && c != '('))
            {
                return false;
            }
        }
    }

    return st.empty();
}

void Print(stack<int> st) {
    while (!st.empty())
    {
        cout<< st.top() << " ";
        st.pop();
    }
    cout<<endl;
}

int main() {

   cout<< "Is balanced : " << IsBalancedParanthesis("([]{}");

   
   
    return 0;
}