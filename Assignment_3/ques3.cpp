#include <iostream>
using namespace std;

struct student {
    int rollno;
};

template <class T>
class GrowingStack {
    private:
        const int size = 3;
        int top = -1;
        int MaxSize;
        T *data;
    public:
        GrowingStack(){}
        GrowingStack(int MaxSize){
            this->MaxSize = MaxSize;
            this->data = new T[this->size];
        }

        GrowingStack(GrowingStack &stack){
            this->top = stack.top;
            this->MaxSize = stack.MaxSize;
            this->data = stack.data;
        }

        void operator = (GrowingStack &stack){
            this->top = stack.top;
            this->MaxSize = stack.MaxSize;
            this->data = stack.data;
        }
        void push(int number);
        int pop();
        int getMaxSize();
        int currentSize();
        int isEmpty();
        int isFull();
        void inflate();
        void printStack();
};

// Returns 1 if given stack is full, else 0
template <class T>
int GrowingStack<T>::isFull(){
    return (this->top + 1 == this->MaxSize) ? 1 : 0;
}

// Returns 1 if given stack is empty, else 0
template <class T>
int GrowingStack<T>::isEmpty(){
    return (this->top == -1) ? 1 : 0;
}

// Returns max size of given stack
template <class T>
int GrowingStack<T>::getMaxSize(){
    return this->MaxSize;
}

// Returns current size of given stack
template <class T>
int GrowingStack<T>::currentSize(){
    return this->top + 1;
}

// Increases size of stack by 1
template <class T>
void GrowingStack<T>::inflate(){
    this->data = (T *)realloc(this->data, this->currentSize() + 1);
    cout << "Stack inflated. ";
}

// Pushes element to given stack
template <class T>
void GrowingStack<T>::push(int number){
    if(!this->isFull()){
        if(this->currentSize() >= this->size)
           this->inflate();
        this->data[this->top + 1] = number;
        this->top++;
        cout << "Data Pushed" << endl;
    }
    else
        cout << "[ERROR]: Maximum limit reached. Stack not inflated." << endl;
}

// Pops an element from a given stack
template <class T>
int GrowingStack<T>::pop(){
    if(this->isEmpty())
        cout << "Stack is empty. No data is popped." << endl;
    else
        this->top -= 1;
        cout << "Data Popped" << endl;
        return this->data[this->top + 1];
}

// Merges 2 given stacks into a third stack
template <class T>
void mergeStacks(GrowingStack<T> &stack1, GrowingStack<T> &stack2, GrowingStack<T> &mergedStack){
    while(!stack1.isEmpty() || !stack2.isEmpty()){
        if(!stack1.isEmpty()){
            mergedStack.push(stack1.pop());
        }
        if(!stack2.isEmpty()){
            mergedStack.push(stack2.pop());
        }
    }
}

// Print the contents of a stack
template <class T>
void GrowingStack<T>::printStack(){
    int size = this->currentSize();
    for(int i=0; i<size; ++i)
        cout << this->data[i] << " ";
    cout << "\n";
}

int main(){
    struct student s1;
    const int MaxSize = 4;
    GrowingStack<float> stack1(MaxSize), stack2(MaxSize);
    // Operations on stack1
    cout << "//Stack 1" << endl;
    stack1.push(10);
    stack1.push(20);
    stack1.push(30);
    stack1.push(40);
    stack1.push(50);

    // Operations on stack 2
    cout << endl << "//Stack 2" << endl;
    stack2.push(60);
    stack2.push(70);
    stack2.push(80);

    // Merging 2 stacks
    cout << endl << "//Merging" << endl;
    GrowingStack<float> stack3(stack1.getMaxSize() + stack2.getMaxSize());
    mergeStacks(stack1, stack2, stack3);

    // Copy Constructor
    GrowingStack<float> stack4(stack3), stack5;

    GrowingStack<int> stack6;
    GrowingStack<short> stack7;
    GrowingStack<double> stack8;
    GrowingStack<struct student> stack9;

    // = operator
    stack5 = stack4;

    return 1;
}