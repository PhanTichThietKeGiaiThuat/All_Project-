#include <fstream>
#include<iostream>
using namespace std;
struct topType {
    int stt ;
    int bac ;
    int mau ;
  
};
topType myTop[100] ;
  
void init(int n) {
    /**< Ham khoi tao cac gia tri ban dau */
    for(int i = 1 ; i <=n ; i++) {
        myTop[i].stt = i;
        myTop[i].bac = 0 ;
        myTop[i].mau = 0 ;
    }
  
}
  
void readFile(char * name , int a[100][100] , int & n ) {
    /**< Ham dung de lay thong tin tu file */
    ifstream myFile(name) ;
    if(!myFile) {
        cout<<"tap tin "<<name<<" khong ton tai, hay tao ngay! " ;
        return  ;
    }
    myFile>>n ;
    for(int i= 1 ; i <= n; i++)
        for(int j = 1 ; j <=n ; j++)
            myFile>>a[i][j] ;
}
  
void printMatrix(int a[100][100] , int n) {
    /**< Ham dung de in ra ma tran  */
    for(int i = 1 ; i <=n ; i++) {
        for(int j = 1 ;j <=n ; j++) {
            cout<<a[i][j] <<" " ;
        }
        cout<<endl ;
    }
  
}
  
void tinhBac(int a[100][100], int n) {
    /**< tinh bac cac dinh  */
    for(int i =  1; i <=n ; i++) {
         for(int j= 1 ; j<=n ;j++) {
            myTop[i].bac += a[i][j] ;
        }
    }
}
void sapXep(int a[100][100] , int n ) {
    /**< sap xep giam dan bac theo kieu selection short */
    for(int i = 1 ; i<= n-1 ;i++) {
            int t = i;
        for(int j = i+1 ; j<=n ;j ++) {
            if( myTop[t].bac < myTop[j].bac) {
                t = j;
            }
        }
       topType temp =  myTop[t] ;
       myTop[t] = myTop[i] ;
       myTop[i] =  temp ;
  
    }
}
bool thoaDieuKien(int a[100][100] , int n , int dinh , int m) {
    /**< luu y khi truyen ham vao nay, ta truyen vao dinh , tuc la myTop[].stt */
    for(int i = 1 ; i <=n ;i++) { /**< xet tat cac cac dinh con lai  */
      if ( a[dinh][i]==1 ) /**< neu dinh ke nhau  */
        for(int j = 1 ; j<=n ;j++ )
            if(myTop[j].stt == i) /**< tinh dinh co stt bang i  */
                if(myTop[j].mau==m)
                /**< neu mau cua dinh j co mau trung voi mau hien tai la m thi
                    tra ve false vi 2 dinh ke khong duoc cung mau */
                    return false ;
    }
    return true ;
}
void printResult(int soMau ,int n) {
    /**< in ket qua */
    for(int i =1 ; i <=soMau ;i++) {
        cout<<"Mau "<<i<<" : "  ;
        for(int j = 1 ; j<= n ;j++) {
            if(myTop[j].mau==i)
                cout<<j<<" " ;
        }
        cout<<endl ;
    }
  
}
void toMau(int a[100][100], int n, int &soMau) {
    /**< Ham dung to to mau ^^ */
    int i =1;
    int soDinhDaTo = 0 ;
     soMau=1;
    while(soDinhDaTo<n) {
        for(int j = 1 ; j<=n ;j++) {
            if( myTop[j].mau==0  && thoaDieuKien(a,n,myTop[j].stt,soMau)==true) {
                /**< neu dinh chua co mau va  thoa dieu kien de to thi... */
                myTop[j].mau = soMau ;
               // cout<<"Dinh "<<myTop[j].stt<<" mau "<<myTop[j].mau<<endl;
                i = j; /**< tiep tuc xet cac dinh ke voi j  */
                soDinhDaTo++ ;
                break;
            }
           if(j>=n) {
            /**<  khong con dinh mau thoa mau m
            thi ta chon mau khac va xet duyet dinh khac*/
  
                soMau++ ;
                /**<  tim vi tri to mau tiep theo tinh tu trai qua phai*/
                for(int k = 1 ; k<=n ;k++) {
                    if(myTop[k].mau==0)  {
                        i = k;
                        break;
                    }
                }
  
            }
        }
    }
  
}
  
int main()
{
    int a[100][100] , n ,soMau ;
    readFile("input.txt" , a , n) ;
    printMatrix(a,n) ;
    init(n) ;
    tinhBac(a,n) ;
    sapXep(a,n) ;
    toMau(a,n,soMau) ;
    cout<<"So mau : " <<soMau<<endl ;
    printResult(soMau,n) ;
  
    return 0;
}
