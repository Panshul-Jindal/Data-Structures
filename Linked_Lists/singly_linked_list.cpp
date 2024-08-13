#include <iostream>

class Chain;

class ChainNode{
    friend class Chain;

    public:
        ChainNode(int element = 0,ChainNode * next = NULL){
            data = element;
            this->next = next;
        }
    
    private:
    int  data;
    ChainNode * next;



};
class Chain{
    public:
    void InsertAtPosition(int data, int element);
    void InsertAtHead(int element);
    void InsertAtTail(int data);
    void Delete(int element);
    int Length() const;
    void Print();

    private:

    ChainNode * head=NULL;
};


void Chain::InsertAtPosition(int element,int data){
    ChainNode * temp = head;
    while(temp->data !=  element){
        temp= temp->next;
    }
    if(temp != NULL){
    ChainNode * node_to_insert = new ChainNode(data,temp->next);
    temp->next = node_to_insert;
    }

    
    
    
   
}

void Chain::InsertAtHead(int element){
    
    ChainNode * node_to_insert = new ChainNode(element,head);
    head = node_to_insert;
    


}
void Chain::Print(){
    ChainNode*temp = head;
    while(temp != NULL){
        std::cout << temp->data << " ";
        temp=temp->next;
    }
    std::cout << std::endl;
}

void Chain::Delete(int element){
    ChainNode * curr = head;
    ChainNode * prev = NULL;
    while(curr->data !=  element){
        prev = curr;
        curr= curr->next;   
    }
    if (curr == head){
        head = curr->next;

    }
    else{
    prev->next = curr->next;
    }
    delete curr;


    
}
int Chain::Length() const {
    if (head == 0 ){
        return 1;
    }
    else{
        int count = 0;
        ChainNode * temp = head;
        while(temp != NULL){
            count+=1;
            temp = temp->next;
         }
    return count;        
}

}



int main(){
    
    Chain  myChain = Chain();
    myChain.InsertAtHead(5);
    myChain.InsertAtHead(6);
    myChain.InsertAtHead(7);

    myChain.InsertAtPosition(5,1);
    
    myChain.Print();


    myChain.Delete(7);
     
    myChain.Print();
 



}