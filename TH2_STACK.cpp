#include<iostream>
using namespace std;
typedef int T;
struct  Stack
{
    T *theArray;
    int topOfStack;
};
void stackInit(Stack &stack, int capacity = 100);   /// Init stack
bool stackIsEmpty(Stack &stack);                    /// Check for empty stack
int stackGetSize(Stack &stack);                     /// Return the number of elements currently on stack
void stackPush(Stack &stack, T element);            /// Insert element at the top of stack
void stackPop(Stack &stack);                        /// Delete element at the top of stack
int stackFind(Stack &stack, T number);              /// Find number in stack
T stackTop(Stack &stack);                           /// Return element at the top, but don't delete
bool stackPushAtTop(Stack& stack, T element);
void stackDestroy(Stack & stack);
void stackRemove(Stack &stack);
void stackInput(Stack &stack, T nume);                      /// Enter the value of element in stack
void stackOutput(Stack &stack);                     /// Print value of element in stack
int main(){
    int number, nume , x;
    Stack s;
    stackInit(s);
    /// YEU CAU THUC HANH
    ///   1. Viet code kiem tra ngan xep co dang rong hay khong
    ///   2. Viet code chen vao ngan xep mot so phan tu
    ///   3. Viet code in tat ca cac phan tu trong ngan xep len man hinh
    ///   4. Viet code nhap vao x roi kiem tra x co trong ngan xep hay khong
    ///   5. Viet code rut tung phan tu ra khoi ngan xep cho den khi ngan xep rong
    ///   6. Viet code kiem tra xem ngan xep da rong hay chua
    if (stackIsEmpty(s))
        cout<<"Stack is empty"<<endl;
    else cout<<"Stack is not empty"<<endl;
    cout<<"Enter the number of elements : "; cin >> nume;
    stackInput(s,nume);
    cout<<"Elements in stack is: "<<endl;
    stackOutput(s);
    cout<<endl;
    cout<<"Enter the number that you want to find: "; cin >> number;
    stackFind(s,number);
    cout<<"Enter the number that you want to insert in stack: "; cin >> x;
    stackPushAtTop(s,x);
    cout<<"Stack after insert: "<<endl;
    stackOutput(s);
    cout<<endl;
    cout<<"Remove each element from the stack until the stack is empty"<<endl;
    stackRemove(s);
    cout<<endl;
    cout<<"Check size of stack after remove element: "<<stackGetSize(s)<<endl;
    stackDestroy(s);
    return 0;
}
void stackInit(Stack &stack, int capacity ){
    stack.theArray = new T[capacity];   /// Init a array has size = capacity
    stack.topOfStack = -1;      /// "-1" meaning stack is empty
}
bool stackIsEmpty(Stack &stack){
    return (stack.topOfStack == -1);
}
void stackPush(Stack &stack, T element){
    stack.topOfStack ++;      /// Increase array by 1
    stack.theArray[stack.topOfStack] = element;
}
int stackGetSize(Stack & stack)
{
    return (stack.topOfStack + 1);
}
void stackPop(Stack &stack){
    stack.topOfStack --;
}
int stackFind(Stack &stack, T number){
    int count = 0, i;
    if (!stackIsEmpty(stack)) {
        for ( i = 0; i < stack.topOfStack; i++) {
            if (number == stack.theArray[i]){
                count++;
                cout<<"Number "<<number<< " is in stack  at ["<< i <<"]"<<endl;
            }

        }
    }
    if (count ==0)
     cout << "Number "<<number<<" is not in stack !"<<endl;
}
T stackTop(Stack &stack){
    return stack.theArray[stack.topOfStack];
}
bool stackPushAtTop(Stack& stack, T element) {
    for (int i = stack.topOfStack + 1; i > 0; i--) {
        stack.theArray[i] = stack.theArray[i - 1];
    }
    stack.theArray[0] = element;
    stack.topOfStack++;
    return true;
}
void stackDestroy(Stack & stack)
{
    delete[] stack.theArray;
}
void stackRemove(Stack &stack){
    for (int i = stack.topOfStack; i >=0; i--){
        cout << stackTop(stack) <<" ";
        stackPop(stack);
    }
}
void stackInput(Stack &stack, T nume){
    if (nume > 0){
        int element;
        cout<<"Enter value of element: ";
        for (int i = 0; i < nume; i++){
            cin >> element;
            stackPush(stack,element);
        }
    } else
        cout<<"Invalid value";
}
void stackOutput(Stack &stack){
    for (int i = stack.topOfStack; i>=0; i--){
        cout<<stack.theArray[i]<<" ";
    }
}
