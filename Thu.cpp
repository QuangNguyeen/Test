#include<fstream>
#include<iostream>
using namespace std;
bool isPerfect(int n){
    int sum = 0;
    for(int i = 0; i < n ; i++){
        if(n % i == 0)
            sum += i;
    }
    return (sum == n);
}
int main(){
    ofstream myfile("soHC.txt");
    if(myfile.is_open()){
        for(int i = 0; i < 100000; i++){
            if(isPerfect(i))
                myfile << i <<"\n";
        }
        myfile.close();
    }
    return 0;
}