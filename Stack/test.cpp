#include "stack.h"
using namespace std;
int main(){
    
    Stack<int> my_stack= Stack<int>(5);
    my_stack.Push(5);
    cout << my_stack.Top() << endl;
}