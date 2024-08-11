#include <iostream>
using namespace std;

// template<typename T>
// T min(T a,T b){
//     return (a<b) ? a:b;
// // }

// template<typename T>
// void copy(T * array,int size,T * newArray){
//     for(int i  = 0;i<size;i++){
//         newArray[i]=array[i];
//     }

// }

template<class T>
class Stack{
    public:
    Stack(int stackCapacity=10);

    bool IsEmpty()const;

    T Top()const;

    void Push (const T& item);

    void Pop();

    private:
    T*stack;
    int top;
    int capacity;
};
template<typename T>
void ChangeSize1D(T*&a,const int oldSize,const int newSize){
    T * new_array = new T[newSize];
    int  number = min(oldSize,newSize); 
    copy(a,a+number ,new_array);
    
    delete []a;
    a = new_array;
}

//constructors
template <class T>
Stack<T>::Stack(int stackCapacity): capacity(stackCapacity){
    if(capacity < 1) throw "Stack capacity must be >0";
    stack = new T[capacity];
    top = -1;
}

//Accessor Methods
template<class T>
inline bool Stack<T>::IsEmpty()const {return top ==-1; }

template<class T>
inline T Stack<T>:: Top()const{
    if (IsEmpty())throw std::runtime_error("Stack is Empty");
return stack[top];}


//Manipulation Methods

template<class T>
void Stack<T>::Push(const T& item){
    if (top == (capacity-1)){
        ChangeSize1D(stack,capacity,capacity*2);
        capacity *=2;
    }
    stack[++top]=item;
}



template<class T>
void Stack<T> ::  Pop(){
    if (IsEmpty())throw std::runtime_error("Stack is Empty,Can't Delete");
    stack[top--].~T();


}

int main(){
    Stack<int> my_stack = Stack<int>(10);
    
    my_stack.Push(5);
    my_stack.Push(6);
    cout << my_stack.Top();

    my_stack.Pop();
    cout << my_stack.Top();

}





