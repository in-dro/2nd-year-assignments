#include <iostream>
using namespace std;

class GrowingStack {
    private:
        const int size = 3;
        int top = -1;
        int MaxSize;
        int *data;
    public:
        GrowingStack(){}
        GrowingStack(int MaxSize){
            this->MaxSize = MaxSize;
            this->data = new int[this->size];
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
int GrowingStack::isFull(){
    return (this->top + 1 == this->MaxSize) ? 1 : 0;
}

// Returns 1 if given stack is empty, else 0
int GrowingStack::isEmpty(){
    return (this->top == -1) ? 1 : 0;
}

// Returns max size of given stack
int GrowingStack::getMaxSize(){
    return this->MaxSize;
}

// Returns current size of given stack
int GrowingStack::currentSize(){
    return this->top + 1;
}

// Increases size of stack by 1
void GrowingStack::inflate(){
    this->data = (int *)realloc(this->data, this->currentSize() + 1);
    cout << "Stack inflated. ";
}

// Pushes element to given stack
void GrowingStack::push(int number){
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
int GrowingStack::pop(){
    if(this->isEmpty())
        cout << "Stack is empty. No data is popped." << endl;
    else
        this->top -= 1;
        cout << "Data Popped" << endl;
        return this->data[this->top + 1];
}

// Merges 2 given stacks into a third stack
void mergeStacks(GrowingStack &stack1, GrowingStack &stack2, GrowingStack &mergedStack){
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
void GrowingStack::printStack(){
    int size = this->currentSize();
    for(int i=0; i<size; ++i)
        cout << this->data[i] << " ";
    cout << "\n";
}

int main(){
    const int MaxSize = 4;
    GrowingStack stack1(MaxSize), stack2(MaxSize);
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
    GrowingStack stack3(stack1.getMaxSize() + stack2.getMaxSize());
    mergeStacks(stack1, stack2, stack3);

    // Copy Constructor
    GrowingStack stack4(stack3), stack5;

    // = operator
    stack5 = stack4;

    stack1.printStack();
    stack2.printStack();
    stack3.printStack();
    stack4.printStack();
    stack5.printStack();
    return 1;
}