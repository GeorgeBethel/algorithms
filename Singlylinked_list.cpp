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

                Node* search(int);

                void Delete(int);

                void prepend();

                void printList();

            };

void LinkList::Delete(int data){

      if(head == NULL){

        std::cout << "list is empty" << std::endl;

        return;

      }

      else{

         Node* temp = head;
         Node* prev;

         while(temp->next != NULL && temp->data != data){

            prev = temp;

            temp = temp->next;

         }

         std::cout<<"data prev: "<<prev->data<<", pointer: "<<prev->next<<std::endl;

         prev->next = temp->next;

         delete temp;

         temp = NULL;


      }

}

Node* LinkList::search(int data){

      Node* location;

      if(head == NULL){

       std::cout<<"List is empty"<<std::endl;

       return NULL;

      }

      else{


       Node* temp = head;

       while(temp != NULL && temp ->data != data){

          temp = temp->next;

       }

       location = temp->next;

       return location;

      }


}

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
        
        std::cout<<"data: "<<temp->data<<", pointer: "<<temp->next<<std::endl;
        
        temp = temp->next;
    }



}


int main(){

  LinkList llst;

  llst.append(10);
  llst.append(20);
  llst.append(6);
  llst.append(8);
   llst.append(7);
  llst.append(40);
  llst.append(5);
  llst.append(30);
  

  llst.printList();

  llst.Delete(12);

  llst.printList();

  Node* location = llst.search(6);

  std::cout<<"pointer location of data 6: "<< location <<std::endl;


}