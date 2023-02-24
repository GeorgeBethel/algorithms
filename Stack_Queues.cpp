#include<iostream>

using namespace std;


class Stack

{


public:
    // int const size = 10;
    int items[10];
    Stack(){}
    int top = -1;
    // stack(int size);
    void push(int item);
    int pop();
    bool isEmpty();
    int peak();
    void printStack();

};



void Stack::push(int item){

    if(top > 10 -1){

        cout<<"stack is full"<<endl;

    }

    else{

        items[++top] = item;

    }

}


int Stack::pop(){

    if(top < 0){

        cout<<"stack is empty"<<endl;

        return 0;
    }

    else{

        int FirstItem = items[--top];

        return FirstItem;

    }

}

bool Stack::isEmpty(){

    return (top < 0);

}


int Stack::peak(){

    if (top < 0){return 0;}
    
    else{ 
        
        return items[top];       

}

}

void Stack::printStack(){

    for(int i = 0; i <= 6; i++){

        cout<<"item at index ["<<i<<"] :"<<pop()<<endl;

    }

}



int main(int argc, const char** argv) {

    Stack stackItems;

    stackItems.push(1);
    stackItems.push(2);
    stackItems.push(3);
    stackItems.push(4);
    stackItems.push(5);
    stackItems.push(6);

    stackItems.printStack();

    return 0;
}