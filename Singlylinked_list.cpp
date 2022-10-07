#include<iostream>

class Node{

public:
    int data;

    Node* next;

    Node(){

    this->data = 0;
    
    this->next = NULL;
    
    }

    Node(int data){

    this->data = data;
    this->next = NULL;

    }

};


class LinkList{

public:
    Node* head;

    LinkList(){head = NULL;}

    void append(int);

    void insert(int);

    void sort();

    void Del();

    void prepend();

    void printList();

};

void LinkList::append(int data){

    Node* newNode = new Node(data);

      while (head == NULL)
      {
        head = newNode;

        return;

      }

    Node* temp = head;

    while(temp->next != NULL){

        temp = temp->next;

    } 

    temp->next = newNode;

    }

void LinkList::printList(){

    Node* temp = head;

    std::cout<<"items linked"<<std::endl;

    while (temp != NULL){
        
        std::cout<<temp->data<<std::endl;
        
        temp = temp->next;
    }

}


int main(){

  LinkList llst;

  llst.append(10);
  llst.append(20);
  llst.append(6);
  llst.append(8);

  llst.printList();


}