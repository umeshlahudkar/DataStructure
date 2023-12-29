#include<iostream>
#include <stack>
#include <queue>
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

class StackBy2Queue {
    private :
        queue<int> q1, q2;

    public :

        void Push(int data) {
            if(q1.empty()) {
                q1.push(data);
                return;
            }

            while(!q1.empty()) {
                q2.push(q1.front());
                q1.pop();
            }

            q1.push(data);

             while(!q2.empty()) {
                q1.push(q2.front());
                q2.pop();
            }

        }

        void Pop() {
            q1.pop();
        }

        int Top() {
            return q1.front();
        }

        bool IsEmpty() {return q1.empty();}
};

void Print(StackBy2Queue st) {
    while (!st.IsEmpty())
    {
        cout<< st.Top() << " ";
        st.Pop();
    }
    cout<<endl;
}

int main() {

   StackBy2Queue st;
   st.Push(10);
   st.Push(20);
   st.Push(30);
   st.Push(40);
   st.Push(50);

   Print(st);

   st.Pop();

   Print(st);
   
    return 0;
}