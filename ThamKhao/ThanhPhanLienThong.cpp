/*
Thu?t toán tìm s? thành ph?n liên thông c?a d? th? G
Mô t? bài toán: Cho d? th? vô hu?ng G=(V,E) hãy d?m s? thành ph?n liên thông c?a d? th? G.

Ý tu?ng thu?t toán:

Bu?c 0: Kh?i t?o s? thành ph?n liên thông b?ng 0.

Bu?c 1: Xu?t phát t? m?t d?nh chua du?c dánh d?u c?a d? th?. Ta dánh d?u d?nh xu?t phát, tang s? thành ph?n liên thông lên 1 và chuy?n sang bu?c 2.

Bu?c 2: T? m?t d?nh i dã dánh d?u, ta dánh d?u d?nh j n?u A[i,j] = 1 và j chua du?c dánh d?u và chuy?n sang Bu?c 3.

Bu?c 3: Th?c hi?n Bu?c 2 cho d?n khi không còn th?c hi?n du?c n?a chuy?n sang Bu?c 4.

Bu?c 4: N?u s? s? d?nh dánh d?u b?ng n k?t thúc thu?t toán, ngu?c l?i quay v? Bu?c 1.

Mô t? d? li?u d?u vào và d?u ra c?a bài toán:

D? li?u vào: cho trong t?p tin Bai1.inp
- Dòng d?u ghi s? n là s? d?nh c?a m?t d? th? (0<n<100).
- Dòng i+1 (1 < i < n ) ch?a n s? A[i,1],A[i,2]…A[i,n] m?i s? cách nhau b?i m?t kho?ng tr?ng.
D? li?u ra: xu?t ra màn hình s? thành ph?n liên thông c?a d? th?.
*/
#include < stdio.h > 
#include < conio.h > 
#include < iostream.h >
 
//doc du lieu tu tap tin
void Doc_File(int * * A, int & n) {
    FILE * f = fopen("Input.txt", "rb");
    fscanf(f, "%d", & n); * A = new int[n];
    cout << "Ma Tran Lien Ket Cua Do Thi";
    for (int i = 0; i < n; i++) {
        A[i] = new int[n];
        cout << endl;
        for (int j = 0; j < n; j++) {
            fscanf(f, "%d", & A[i][j]);
            cout << " " << A[i][j];
        }
    }
    fclose(f);
}
 
//ham tra ve so thanh phan lien thong cua do thi
int TPLien_Thong(int * * A, int n) {
    char * DanhDau = new char[n];
 
    char ThanhCong;
    int Dem = 0, i, j, MLT = 0;
    for (i = 0; i < n; i++) //khoi tao cac dinh chua danh dau
    DanhDau[i] = 0;
    do {
        j = 0;
        while (DanhDau[j] == 1) //tim 1 dinh chua duoc danh dau
        j++;
        DanhDau[j] = 1; //danh dau dinh tim duoc
        Dem++; //tang so dinh danh dau len 1
        MLT++; //tang so thanh phan lien thong len 1
        do {
            ThanhCong = 0;
            for (i = 0; i < n; i++)
            if (DanhDau[i] == 1) for (j = 0; j < n; j++)
            if (DanhDau[j] == 0 && A[i][j] > 0) {
                DanhDau[j] = 1;
                ThanhCong = 1;
                Dem++;
                if (Dem == n) return MLT;
            }
        } while (ThanhCong == 1);
    } while (Dem < n); //lap lai khi con dinh chua duoc danh dau
    return MLT;
}
 
//chuong trinh chinh
void main() {
    clrscr();
    int * * A, n;
    Doc_File(A, n);
    cout << "\nTHANH PHAN LIEN THONG: " << TPLien_Thong(A, n);
    delete * A;
    getch();
 
}
