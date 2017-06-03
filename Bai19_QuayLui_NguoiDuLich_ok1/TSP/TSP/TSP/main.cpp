#include <iostream>
#include <fstream>
#include <string>
#define MAX 10000

using namespace std;
int C[25][25], Daxet[25], x[25], PATU[25];
int n, S, Tong, f;
string filename;

void ReadFile() {

	ifstream file;
	file.open(filename, ios::in);
	int i, j;
	string data;
	if (file.fail())
	{
		cout << "Khong mo duoc file!" << endl;
	}
	else {
		file >> n;
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= n; j++) {
				file >> C[i][j];
			}
		}
		
	}
	
	file.close();
}

void WriteFile() {
	ofstream file("output.txt", ios::out | ios::app);
	file << "File input: " << filename << endl;
	file << "Phuong an toi uu tim duoc la: " << endl;
	int i;
	for (i = 1; i <= n; i++) {
		file << PATU[i] << "\t";
	}
	file << endl;
	file << "Gia tri toi uu: "<< f << endl;
	file.close();
}
void Init() {
	int i;
	for (i = 1; i <= n; i++) {
		Daxet[i] = 0;
	}
	S = 0;
	Tong = 0;
	f = MAX;
	x[1] = 1;
}

void Print() {
	cout << "Phuong an toi uu: " << endl;
	int i;
	for (i = 1; i <= n; i++) {
		cout << PATU[i] << "\t";
	}
	cout << endl;
	cout << "Gia tri toi uu: " << f << endl;
}

void CopyArray() {
	int i;
	for (i = 1; i <= n; i++) {
		PATU[i] = x[i];
	}
}

void Try(int i) {
	int j;
	for (j = 2; j <= n; j++) {
		if (Daxet[j] == 0) {
			x[i] = j;
			Daxet[j] = 1;
			S = S + C[x[i - 1]][x[i]];
			if (i == n) {
				Tong = S + C[x[n]][x[1]];
				if (Tong < f) {
					CopyArray();
					f = Tong;
				}
			}
			else {
				Try(i + 1);
			}
			S = S - C[x[i - 1]][x[i]];
			Daxet[j] = 0;
		}
	}
}
int main() {	
	int choose;
	cout << "Danh sach cac file du lieu dau vao:" << endl;
	cout << "1. input1.txt" << endl;
	cout << "2. input2.txt" << endl;
	cout << "3. input3.txt" << endl;
	cout << "4. input4.txt" << endl;
	cout << "5. input5.txt" << endl;
	cout << "Nhap lua chon file du lieu dau vao: " ;
	cin >> choose;
	switch (choose)
	{
	case 1:
		filename = "input1.txt";
		break;
	case 2:
		filename = "input2.txt";
		break;
	case 3:
		filename = "input3.txt";
		break;
	case 4:
		filename = "input4.txt";
		break;
	case 5:
		filename = "input5.txt";
		break;
	default:
		filename = "input1.txt";
		break;
	}
	ReadFile();
	Init();
	Try(2);
	Print();
	WriteFile();

	system("pause");
	return 0;

}