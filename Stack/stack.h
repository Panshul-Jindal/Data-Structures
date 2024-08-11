#ifndef STACK_H
#define STACK_H
using namespace std;
#include <iostream>
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

#endif