#include<iostream>

#ifndef CONSTANT
#define CONSTANT 5
#endif

#ifndef UPPER_BOUND
#define UPPER_BOUND 50
#endif

namespace Growing_Stack{

    struct GrowingStack
    {
        int top;
        int length;
        int *key;
    };
    typedef GrowingStack gstack;

    void initialize(gstack &x){

        x.top = -1;
        x.length = 0;
    }
    
    int* inflate(gstack &x){

        int *new_key = new int[x.length + CONSTANT];

        for(int i=0; i<x.length; i++)
            new_key[i] = x.key[i];
        
        x.length += CONSTANT;

        std::cout<<".../"<<std::endl;
        return new_key;
    }

    int* push(gstack &x, int value){

        if(x.top == UPPER_BOUND){
            std::cout<<"Stack Overflows"<<std::endl;
            return x.key;
        }

        if(x.top == x.length-1)
            x.key = inflate(x);

        x.key[++x.top] = value;
        return x.key;
    }

    int pop(gstack &x){

       return x.key[x.top--];
    }

    int  getMaxSize(gstack &x){
        
        return x.length;
    }

    int currentSize(gstack &x){

        return x.top + 1;
    }

    int isEmpty(gstack &x){
        
        if(x.top == -1){
            return 1;
        }
        else
            return 0;
    }

    void display(gstack x){

        if(isEmpty(x))
            std::cout<<"Stack is Empty"<<std::endl;

        else{

            std::cout<<"Stack : ";
            for(int i = 0; i<=x.top; i++)
                std::cout<<x.key[i]<<" ";

            std::cout<<std::endl;
            
        }
    }
}

using namespace Growing_Stack;
gstack alt_merge(gstack &x, gstack &y){

    gstack z;
    initialize(z);

    while(!isEmpty(x) && !isEmpty(y)){

        int t1 = pop(x);
        z.key  = push(z, t1);
        int t2 = pop(y);
        z.key  = push(z, t2);
    }

    if(isEmpty(x) && isEmpty(y))
        return z;

    if(isEmpty(x)){

        while(!isEmpty(y)){
            
            int temp1 = pop(y);
                z.key = push(y, temp1);
        }
        if(isEmpty(x) && isEmpty(y))
            return z;
    }

    else if(isEmpty(y)){

        while(!isEmpty(x)){

            int temp1 = pop(x);
                z.key = push(z, temp1);
        }
        if(isEmpty(x) && isEmpty(y))
            return z;
    }
    return z;
}

int main()
{
    gstack test1,test2,final;
    initialize(test1);
    initialize(test2);
    initialize(final);

    test1.key = push(test1, 1);
    test1.key = push(test1, 2);
    test1.key = push(test1, 3);
    test1.key = push(test1, 4);
    test1.key = push(test1, 6);
    test1.key = push(test1, 21);
    std::cout<<"Test 01 ";
    display(test1);

    int x = getMaxSize(test1);
    std::cout<<x<<std::endl;

    int y = currentSize(test1);
    std::cout<<y<<std::endl;

    test2.key = push(test2, 2);
    test2.key = push(test2,6);
    test2.key = push(test2,21);
    std::cout<<"Test 02 ";
    display(test2);

    final = alt_merge(test1 ,test2);

    std::cout<<"Final Test ";
    display(final);
}