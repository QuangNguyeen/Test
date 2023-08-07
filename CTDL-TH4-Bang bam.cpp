// Thuc hanh bang bam (danh cho giang vien)

#include <iostream>
#include <string>

using namespace std;

// Muc tu trong tu dien
struct MucTu
{
    string tuTiengAnh;
    string nghiaTiengViet;
};

struct TuDien
{
	MucTu * table; // Con tro toi bang bam
	int tableSize; // Kich thuoc bang bam        
	bool * trong;  // Neu trong[i] == true thi vi tri i trong bang bam dang trong
};
	
// Ham bam anh xa tu tieng Anh sang mot vi tri trong bang bam:
//   1. Cong cac ky tu
//   2. Chia cho kich thuoc bang bam va lay phan du
int hamBam(string tuTiengAnh, int tableSize)
{
    int hashVal = 0;
	for (int i = 0; i < tuTiengAnh.size(); i++)
		hashVal += tuTiengAnh[i];

	return hashVal % tableSize;
}

// Ham khoi tao tu dien
void khoiTaoTD(TuDien & td, int size = 101) // Kich thuoc bang bam ngam dinh la 101
{
	td.tableSize = size;        // Khoi tao kich thuoc bang bam
    td.table = new MucTu[size]; // Cap phat bo nho cho bang bam
    
    // Tat ca cac o trong bang bam deu trong
	td.trong = new bool[size];
	for (int i = 0; i < size; i++)
		td.trong[i] = true;            
}

// Ham huy tu dien
void huyTD(TuDien & td)
{
	delete[] td.table; // Giai phong bang bam
	delete[] td.trong; // Xoa mang trong
}

// Chen muc tu vao tu dien
void chenMucTu(TuDien & td, MucTu mt)
{
	// Thuc hien phep bam de xac dinh vi tri trong bang bam
	int index = hamBam(mt.tuTiengAnh, td.tableSize);
	
	// Neu co dung do thi xet vi tri ke tiep
	while (!td.trong[index])
	{
		index++;
		index = index % td.tableSize;
	}
	
	// Het dung do thi dat muc tu vao bang bam
	td.table[index] = mt;
	td.trong[index] = false;
}

// Lay nghia tieng Viet
string nghiaTiengViet(TuDien & td, string tuTiengAnh)
{
	// Thuc hien phep bam de xac dinh vi tri trong bang bam
	int index = hamBam(tuTiengAnh, td.tableSize);
	
	// Neu co muc tu thi kiem tra tu tieng Anh co dung la tu dang tim hay khong
	while (!td.trong[index])
	{
		if (td.table[index].tuTiengAnh == tuTiengAnh)
			return td.table[index].nghiaTiengViet;
		
		index++;
		index = index % td.tableSize;
	}
	
	// Den day nghia la khong tim duoc, tra ve xau rong
	return "";
}

int main()
{
	TuDien td;
	khoiTaoTD(td);
	
	// Tao mot vai muc tu
	MucTu mt1, mt2, mt3;
	mt1.tuTiengAnh     = "computer";
	mt1.nghiaTiengViet = "may tinh";
	mt2.tuTiengAnh     = "memory";
	mt2.nghiaTiengViet = "bo nho";
	mt3.tuTiengAnh     = "hard disk";
	mt3.nghiaTiengViet = "dia cung";
		
	// Chen cac muc tu vao tu dien
	chenMucTu(td, mt1);
	chenMucTu(td, mt2);
	chenMucTu(td, mt3);
	
	string tuTA, nghiaTV;
	
	// Yeu cau nhap tu tieng Anh de tra cuu tu dien
	cout << "Nhap tu tieng Anh: ";
	getline(cin, tuTA);
	
	// Tim nghia tieng Viet
	nghiaTV = nghiaTiengViet(td, tuTA);
	
	// In ket qua tra cuu
	if (nghiaTV == "")		
		cout << "Tu vua nhap khong co trong tu dien" << endl;
	else		
		cout << "Nghia cua tu vua nhap la: " << nghiaTV << endl;
		
	huyTD(td);
	
	return 0;
}
