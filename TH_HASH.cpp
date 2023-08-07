#include<iostream>
#include<string>
using namespace std;
struct Word{                                            // Khoi tao cau truc kieu Word
    string English;
    string Vietnamese;
};
struct Dictionary{                                      // Khoi tao cau truc kieu tu dien
    int table_size;                                     // Kich thuoc cua tu dien
    bool * blank;                                       // Con tro kieu bool de kiem tra xem vi tri trong bang bam co trong hay khong
    Word * table;                                       // Con tro kieu word de tro den bang bam
};
int Hash(string word, int table_size){                  // Ham bam
    int hash_value = 0;
    for(int i = 0; i < word.size(); i++){               // 1. Tinh tong gia tri cac chu cai trong tu (ACSII)
        hash_value += word[i];
    }
    return (hash_value % table_size);                   // 2. Sau do chia cho kich thuoc cua bang bam
}
void Create_Dict(Dictionary &dict, int size = 101){     // Khoi bao bang bam
    dict.table_size = size;                             // Size mac dinh la 101
    dict.table = new Word[size];                        // Tao 1 mang chua cac phan tu kieu Word, sau do gan dia chi cho con tro table
    dict.blank = new bool[size];                        // Tao 1 mang chua cac phan tu kieu bool, sau do gan dia chi cho con tro blank
    for(int i = 0; i < size; i++){
        dict.blank[i] = true;                           // Gan tat ca cac phan tu trong mang blank la true
    }                                                   // Tuc la tat ca cac vi tri trong bang bam deu rong
}
void Destroy_Dict(Dictionary & dict){                           // Huy bang bam
    delete[] dict.table;
    delete[] dict.blank;
}
void Insert_Word(Dictionary &dict, Word word){              // Ham them tu vao tu dien
    int index = Hash(word.English,dict.table_size);     // Bam ra de tim vi tri cua tu muon chen
    while (!dict.blank[index]){                               // Tim vi tri rong de chen
        index++;
        index = index % dict.table_size;
    }
    dict.table[index] = word;                                 // Chen tu
    dict.blank[index] = false;                                // Thong bao vi tri nay da co word
}
string Vietmaese_Meaning(Dictionary &dict, string word){       // Ham tra ve nghia Tieng Viet
    int index = Hash(word,dict.table_size);                    // Bam ra de tim vi tri cua tu muon dich
    while(!dict.blank[index]){
        if(dict.table[index].English == word){                 // Neu tim thay
            return dict.table[index].Vietnamese;                // Tra ve nghia Tieng Viet
        }
        index++;
        index = index % dict.table_size;
    }
    return "";
}
void Delete_Word(Dictionary & dict, string word){               // Xoa tu co trong tu dien
    int index = Hash(word,dict.table_size);                     // Bam ra de tim vi tri cuar tu muon xoa
    while (!dict.blank[index]) {
        if (dict.table[index].English == word) {                // Neu tim thay
            dict.table[index].English = "";                     // Gan nghia tieng Anh va tieng Viet = rong
            dict.table[index].Vietnamese = "";
            cout<<"\nDeleted successfully";
            dict.blank[index] = true;                           // Thong bao vi tri nay  rong
            return;                                             // Thoat vong lap
        }
        index++;
        index = index % dict.table_size;                        // Tim kiem o vi tri tiep theo
    }
}
void Update_Meaning_Word(Dictionary &dict, string word, string new_meaning){        // Cap nhap nghia moi cua word
    int index = Hash(word,dict.table_size);                 // Bam ra de tim vi tri cua word
    while(!dict.blank[index]){
        if(dict.table[index].English == word){              // Neu tim thay
            dict.table[index].Vietnamese = new_meaning;     // Thay doi nghia
            cout<<"Updated successfully";
        }
        index++;
        index = index % dict.table_size;                    // Tim o vi tri tiep theo
    }

}
int Count_Word(Dictionary &dict){                           // Dem so word co trong tu dien
    int count = 0;
    for(int i = 0; i < dict.table_size; i++){
        if(!dict.blank[i])
            count++;
    }
    return count;
}
void input_Dict(Dictionary &dict){                          // Nhap tu dien
    Word word;
    while(true){
        cout<<"Enter English word: "; cin >> word.English;
        if(word.English == "NGU")       /// NGU = Never Give Up
            break;
        cin.ignore();
        cout<<"Enter Vietnamese word: "; getline(cin,word.Vietnamese);
        Insert_Word(dict,word);
    }
}
int main(){
    Dictionary dict;
    Create_Dict(dict);
    input_Dict(dict);
    cout<<"\nNumber of words in dictionary: "<<Count_Word(dict);
    string English, Vietnamese;
    cout<<"\nEnter English word you want to trans: "; cin >> English;
    Vietnamese = Vietmaese_Meaning(dict,English);
    if(Vietnamese != ""){
        cout<<"Vietnamese meaning is : "<<Vietnamese;
    } else{
        cout<<"Not found. Unable trans";
    }
    string word_delete, word_update, new_meaning;
    cout<<"\nEnter word you want to delete: "; cin >> word_delete;
    Delete_Word(dict,word_delete);
    cout<<"\nEnter word to update: "; cin >> word_update;
    cout<<"\nEnter new meaning of word: "; cin >> new_meaning;
    Update_Meaning_Word(dict,word_update,new_meaning);
    Destroy_Dict(dict);
    return 0;
}