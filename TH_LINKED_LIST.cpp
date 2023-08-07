#include<iostream>
#include<list>

using namespace std;
typedef int T;
struct Node {
    T elem;
    Node *next;
};
struct List {
    Node *head;
};
void listInit(List &list);                  /// Khởi tạo list
void listPopFront(List &list);              /// Xoá phần tử ở đầu list
void listPushFront(List &list, T element);  /// Thêm phần tử vào đầu list
void listDestroy(List &list);               /// Xoá list
void listInput(List &list, T element);      /// Nhập Element vào list
void listEnumerate(List & list);            /// In ra các phần tử trong list
bool listIsEmpty(List &list);
int main(){
    List list;
    listInit(list);
    int element;
    listInput(list, element);
    cout<<"Element of Linked List: "<<endl; /// In ra các phần tử trong linked list
    listEnumerate(list);
    cout<<endl;
    int newElement;
    cout<<"Enter the ELement that you want to insert: "; cin >> newElement;
    listPushFront(list,newElement);
    cout<<endl;
    cout<<"List is inserted:"<<endl;
    listEnumerate(list);
    cout<<endl<<"Remove the element at the beginning of the list:  "<<endl;
    listPopFront(list);
    cout<<"List is removed:"<<endl;
    listEnumerate(list);
    cout<<endl<<"Destroy list: ";
    listDestroy(list);
    if (list.head== NULL){
        cout<<endl<<"List is destroied successful!";
    }
    return 0;
}
void listInit(List &list){   /// Khai bao list
    list.head = NULL;
}
bool listIsEmpty(List & list){ /// Kiểm tra list rỗng
    return (list.head == NULL);
}
void listPopFront(List & list){
    Node *old = list.head;
    list.head = list.head->next;
    delete old;
}
void listDestroy(List & list){   /// Xoá list. Phải xoá lần lượt từ đầu đến cuối
    while(!listIsEmpty(list)){
        listPopFront(list);
    }
}
void listPushFront(List & list, T element){
    Node * v = new Node;
    v->elem = element;
    v->next = list.head;
    list.head = v;
}
void listInput(List & list, T element){  /// Nhập vào các element.
    cout<<"Enter the ELement of Linked List (Enter 0 to End ):";
    while (true){
        cin >> element;
        if (element == 0)
            break;
        else
            listPushFront(list, element);      /// Gọi nhờ hàm thêm Element vào đầu List
    }
}
void listEnumerate(List & list){ /// Dùng một con trỏ phụ để duyệt từ head đêns khi gặp NULL
    Node* current = list.head;
    while(current != NULL){
        cout << current->elem << " ";
        current = current->next;//
    }
}

