#include<iostream>
#include<string>
#include<cmath>
using namespace std;
struct Node{
    int maSV;
    string HoTen;
    Node *left;
    Node *right;
};
struct Student{
    Node *root;
};
void treeInit(Student & tree);               /// Khởi tạo cây            /// t la root
void treedestroy(Student &tree);             /// Hhuỷ cây
bool treeIsEmpty(Student & tree);            /// Kiểm tra cây  rỗng
void treeMakeEmpty(Student & tree);          /// Làm cho cây rỗng
void treeMakeEmpty(Node * & t);
void treeInsert(int maSV, string HoTen, Node * & t);                    /// Thêm nút mới
void treeInsert(Student &tree, int maSV, string HoTen);
void inputData(Student &tree, int number_of_student, Node * & t);           /// Nhập element của nút
void outputData(Node * & t);                                                /// In ra giá trị của nút
Node *treesearch(Student &tree, int maSV);
Node *treesearch(int maSV, Node * & t);                                 /// Tìm nút

int countNode(Node * & t);
int countLeafNode(Node * & t);
int countTwoChildren(Node * & t);
void NLR(Node * & t);                           /// Duyet truoc Node - Left - Right
void LNR(Node * & t);                           /// Duyet giua Left - Node - Right
void LRN(Node * & t);                            /// Duyet sau Left  - Right - Node
int heightTree(Node * & t);
int main(){
    Student tree;
    treeInit(tree);
    int number_of_student;
    cout<<"Enter number of students you want to insert: "; cin >> number_of_student;
    inputData(tree,number_of_student,tree.root);
    cout<<"ID\t\tHo Va Ten"<<endl;
    cout<<"-------------------------"<<endl;
    outputData(tree.root); cout << endl;
    int id;
    cout<<"Enter ID of Student you want to find: "; cin >> id;
    Node * temp = treesearch(id,tree.root);
    if (temp != nullptr){
        cout<<"ID\t\tHo Va Ten"<<endl;
        cout<<"-------------------------"<<endl;
        cout<<temp->maSV<<"\t\t"<<temp->HoTen<<endl;
    }
    else cout<<"Not found id of Student"<<endl; cout <<"\n";
    cout<<"Node - Left - Right: ";
    NLR(tree.root);
    cout<<"\nLeft- Right - Node: ";
    LRN(tree.root);
    cout<<"\nLeft - Node - Right: ";
    LNR(tree.root); cout<<'\n';
    cout<<"Heigh of Tree: "<<heightTree(tree.root)<<"\n";
    cout<<"\nNumber of Node in Binary Search Tree: "<<countNode(tree.root);
    cout<<"\nNumber of Leaf Node in Binary Search Tree: "<<countLeafNode(tree.root);
    cout<<"\nNumber of Node with 2 childrens in Binary Search Tree: "<<countTwoChildren(tree.root);
    treedestroy(tree);
    cout<<endl;
    if(treeIsEmpty(tree))
        cout<<"Tree is Empty";
    else cout<<"Tree isn't Empty";
    return 0;
}
void treeInit(Student &tree){
    tree.root = nullptr;
}
void treedestroy(Student &tree){
    treeMakeEmpty(tree);
}
void treeMakeEmpty(Student & tree){
    treeMakeEmpty(tree.root);
}
void treeMakeEmpty(Node * & t)
{
    if (t == nullptr)
        return;

    treeMakeEmpty(t->left);
    treeMakeEmpty(t->right);
    delete t;
    t = nullptr;
}
bool treeIsEmpty(Student & tree){
    return(tree.root== NULL);
}
void treeInsert(int maSV, string HoTen, Node * & t) {
    if (t == nullptr) {
        t = new Node;
        t->maSV = maSV;
        t->HoTen = HoTen;
        t->left = nullptr;
        t->right = nullptr;
    } else if (maSV < t->maSV) {
        treeInsert(maSV, HoTen, t->left);
    } else if (maSV > t->maSV) {
        treeInsert(maSV, HoTen, t->right);
    } else ;
}
void inputData(Student& tree, int number_of_student, Node * & t){
    int maSV;
    string HoTen;
    for(int i = 0; i < number_of_student; i++){
        cout<<"Enter maSV: "; cin >> maSV;
        cout<<"Enter HoTen: ";
        fflush(stdin); getline(cin, HoTen);
        treeInsert(maSV, HoTen, t);
    }
}
void outputData(Node * & t) {
    if (t == nullptr) return;
    outputData(t->left);
    cout << t->maSV << "\t\t" << t->HoTen<<endl;
    outputData(t->right);
}
int countNode(Node * & t){
    if (t == nullptr)
        return 0;
    else
        return 1 + countNode(t->left) + countNode(t->right);
}
int countLeafNode(Node * & t){
    if(t == nullptr)
        return 0;
    if (t->left== NULL && t->right == NULL)
        return 1;
    else return (countLeafNode(t->left) + countLeafNode(t->right));
}
int countTwoChildren(Node * & t){
    if (t == nullptr)
        return 0;
    if (t->left != nullptr && t->right != nullptr)
        return 1 + countTwoChildren(t->left) + countTwoChildren(t->right);
    else return countTwoChildren(t->left) + countTwoChildren(t->right);
}
Node *treesearch(int maSV, Node * & t){
    if(t == nullptr)
        return nullptr;
    if(maSV < t->maSV)
        return treesearch(maSV,t->left);
    else if ( maSV > t->maSV)
        return treesearch(maSV, t->right);
    else
            return t;
}
Node *treesearch(Student& tree, int maSV){
    return treesearch(maSV,tree.root);
}
void NLR(Node * & t){
    if(t != nullptr){
        cout<<t->maSV<<" ";
        NLR(t->left);
        NLR(t->right);

    }
}
void LNR(Node * & t){
    if (t != nullptr){
        LNR(t->left);
        cout<<t->maSV<<" ";
        LNR(t->right);
    }
}
void LRN(Node * & t){
    if(t != nullptr){
        LRN(t->left);
        LRN(t->right);
        cout<<t->maSV<<" ";
    }
}
int heightTree(Node * & t){
    if (t == nullptr)
        return -1;
    else
    if (t->left == nullptr && t->right == nullptr)
        return 0;
    else
        return max(heightTree(t->left), heightTree(t->right)) ;
}

