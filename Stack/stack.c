#include <stdio.h>

#define MAX_STACK_SIZE 100
typedef struct {
    int key;  
    //other fields 
}element;

element stack[MAX_STACK_SIZE];
int n;
int top = -1;
int choice = 0;



//accessor methods

element peek();
bool isEmpty();
void show();


//Update Methods

void push(element,int);
element pop();






void main(){
        printf("Enter the number of elements in the stack ");   
    scanf("%d",&n);  
    printf("*********Stack operations using array*********");  
  
printf("\n----------------------------------------------\n");  

while(choice != 4)  
    {  
        printf("Chose one from the below options...\n");  
        printf("\n1.Push\n2.Pop\n3.Show\n4.Exit");  
        printf("\n Enter your choice \n");        
        scanf("%d",&choice);  
        switch(choice)  
        {  
            case 1:  
            {   
                printf("Entere the value to add\n")
                int
                push();  
                break;  
            }  
            case 2:  
            {  
                pop();  
                break;  
            }  
            case 3:  
            {  
                show();  
                    break;  
            }  
            case 4:   
            {  
                printf("Exiting....");  
                break;   
            }  
            default:  
            {  
                printf("Please Enter valid choice ");  
            }   
        };  
    }  
}   





















//accessor Methods
element peek(){
    if (top == -1){
        printf("Stack is Empty");
        return 0;
    }
    else{
        return stack[top];
    }
}


bool isEmpty(){
    if(top==-1){
        return true;
    }
    else{
        return false;
    }

}

void show(){
    if (top == -1){
        printf("Stack is Empty\n");
    }

    for(int i = top ;i>=0;i--){
        printf("%d\n",stack[i]);
    }

}



// Update Methods
void push(element val,int n ){
    if(top == n){
        printf("Overflow\n");
    }
    else{
        top = top+1;
        stack[top]= val;
    }
element pop(){
    if(top == -1){
        printf("Underflow\n");
        return 0;
    }
    else{
        return stack[top--];
    }
}

