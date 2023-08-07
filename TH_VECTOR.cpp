//
// Created by Macbook Air 2020 of Quang on 13/07/2023.
//
#include<iostream>
#include<vector>
using namespace std;
typedef  int T;
struct Vector {
    int size;
    int capacity;
    T *array;
};
void vecInit( Vector & vec, int initCapacity = 16){ /// Khoi tao vector
    vec.size = 0;
    vec.capacity = initCapacity;
    vec.array = new T[vec.capacity];
}
void inputVec(Vector & vec){                /// Nhap Element cua Vector
    for(int i = 0; i<vec.size; i++){
        cout<<"V["<<i<<"] = ";
        cin>>vec.array[i];
    }
}
void printVec(Vector & vec){                /// In ra ca phan tu cua Vector
    for (int i = 0; i < vec.size; i++){
        cout<<"V["<<i<<"] = "<<vec.array[i]<<endl;

    }
}
void trimV(Vector &vec){                /// Loai bo Capacity du thua
    if (vec.capacity > vec.size)
        vec.capacity = vec.size;
    else return ;
}
int vecGetCap(Vector &vec){             /// Lay ra Capacity
    return vec.capacity;
}
void searchVec(Vector & vec, int a){        /// Tim kiem tuan tu trong Vector
    int check = 0;
    for (int i = 0; i<vec.size; i++){
        if (vec.array[i]==a){
            check = 1;
            cout<<"Index: "<<i<<endl;}
        }
    if (check == 0){
        cout<<"Not in vector";}
}
void delPos(Vector & vec, int start, int end){          /// Xoa cac Element tu posI den posJ
    int *old = vec.array;                               /// Lưu ví trí mảng cũ
    vec.array = new int[vec.size - (end - start + 1)];   /// Tảo mảng mới có độ lớn = mảng cũ trừ đi số phần tử muốn xoá
    for (int i = 0;  i < start; i++){                   /// Gán các phần từ từ ở vị trí 0 đến trước ví trí xoá sang mảng mới
        vec.array[i] = old[i];
    }
    for (int i = end + 1; i<vec.size; i++){
        vec.array[end-start+1] = old[i];            /// Gán các phần tử sau end sang arry mới
    }
    vec.size -= (end-start+1);                      /// Gán size của mảng mới cho mảng cũ
    delete[] old;                                   /// Xoá mảng cũ
}
int binarySearch(Vector &vec, int a){               /// Tiem kiem nhi phan
    int lower = 0, upper = vec.size-1, mid;
    while (lower <= upper){
        mid = (lower + upper) / 2;
        if (vec.array[mid] > a )    upper = mid - 1;
        else if (vec.array[mid] < a ) lower = mid + 1;
            else {
                cout <<"Index: "<< mid ;
                return mid;
            }
    }
    return -1;
}
int main(){
    Vector vec;             /// Khai bao
    vecInit(vec);       /// Khoi tao vector
    cout<<vecGetCap(vec)<<endl;  /// Lay ra capacity of vector
    cout<<"Enter the number of size:"; cin >>vec.size;
    trimV(vec);
    cout<<"New Capacity: "<<vecGetCap(vec)<<endl;
    inputVec(vec);
    cout<<"Print Elements of Vector:"<<endl;  printVec(vec);
    int a, b, c;
    cout<<"Enter the number of a (It is number want to search): "<<endl;
    cin>>a;
    cout<<"Linear search: "<<endl;   searchVec(vec,a);
    cout<<"Binary Search: "<<endl;   binarySearch(vec,a);
    cout<<"\n";
    cout<<"Enter the index you want to delete: "; cin >> b >>c;
    cout<<"Delete Element from posI to posJ: "<<endl;    delPos(vec,b,c);
    printVec(vec);
   return 0;
}


