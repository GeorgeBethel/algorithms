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

    LinkList(){

      head = NULL;

    }

    void insert(int data){

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

void printList(){

    Node* temp = head;

    while (temp != NULL)
    {
        std::cout << "list "<<temp->data<<std::endl;
        
        temp = temp->next;
    }

}


};

int main(){

  LinkList llst;

  llst.insert(10);
  llst.insert(20);
   llst.insert(6);
  llst.insert(8);

  llst.printList();


}