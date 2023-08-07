#include<iostream>
using namespace  std;
typedef int T;
struct Node {
    T element ;
    Node *next;
};
struct Queue{
    Node *front;         /// Con tro tro toi vi tri dau cua danh sach
    Node *back;         /// Con tro tro toi vi tri cuoi cua danh sach
    int size;           /// Kich thuoc cua danh sach
};
void queueInit(Queue &queue){ /// Khoi tao danh sach hang doi
    queue.front = NULL;;
    queue.back = NULL;
    queue.size = 0;
}
void enqueue(Queue &queue, T element){ /// Insert Element in queue
    Node *v = new Node;             /// Tao mot not moi
    v->element = element;           /// Gan gia tri element vao nut vua tao
    v->next = NULL;                 /// Con con cho den vi tri tiep theo la NULL
    if (queue.size == 0){
        queue.front = queue.back = v;           /// neu rong thi gan dong thoi front vaf back cho con tro v
    }else{
        queue.back -> next = v;     /// nút mới được liên kết với mặt sau của hàng đợi và con trỏ phía sau của hàng đợi được cập nhật để trỏ đến nút mới.
        queue.back = v;
    }
    queue.size ++;          /// tang size len 1
}
bool queueIsEmpty(Queue &queue){
    return (queue.size == 0);
}
void queueOutput(Queue &queue){
    Node *current = queue.front;
    while (current != NULL){
        cout<<current->element<<" ";
        current = current->next;
    }
}
int queueGetSize(Queue &queue){
    return queue.size;
}
void queueFind(Queue &queue, T element){
    int count = 0;
    Node *find = queue.front;
    while(find != NULL){
        if (find->element == element){
            count ++;
        }
        find = find->next;
    }
    if (count != 0){
        cout<<"Number is in Queue";
    } else cout<<"Number is not in Queue";
}
T dequeue(Queue & queue)
{
    T element = queue.front->element;       /// Tạo biến element kiểu T chứa giá trị đầu tiên của hàng đợi
    Node * v = queue.front;
    if (queue.size == 1)
        queue.front = queue.back = NULL;
    else
        queue.front = queue.front->next;
    delete v;
    queue.size--;
    return element;
}
void queueDestroy(Queue &queue){
    while(!queueIsEmpty(queue))             /// Neu chua rong thi tiep tuc rut element ra den khi rong
        dequeue(queue);
}
int main(){
    Queue queue;
    int element, number;
    queueInit(queue);
    cout<<"Size of Queue before: "<<queueGetSize(queue)<<endl;
    if (queueIsEmpty(queue)) cout<<"Queue is empty"<<endl;
    else cout<<"Queue is not empty"<<endl;
    cout<<"Enter the element of Queue ( Enter 0 to end ): ";
    while(true){
        cin>>element;
        if (element == 0){
            break;
        }
        else
        enqueue(queue,element);
    }
    cout<<"Element of Queue: ";
    queueOutput(queue);
    cout<<endl;
    cout<<"Front is : "<<queue.front->element<<endl;
    cout<<"Size of Queue after: "<<queueGetSize(queue)<<endl;
    cout<<"Enter the number that you want to find : ";  cin >> number;
    queueFind(queue,number);
    cout<<endl;
    cout<<"Remove all element until queue is empty: "<<endl;
    while (true){
        cout << dequeue(queue)<< " ";
        if (queue.size == 0)
            break;
    }
    cout<<endl;
    cout<<"Size if Queue after remove: "<<queueGetSize(queue);
    cout<<endl;
    queueDestroy(queue);
    if (queueIsEmpty(queue))
        cout<<" Successfull  removed";
    else cout<<" Remove failed!";
    return 0;
}
/// Ve hinh va giai thich cac buoc cua ham dequeue