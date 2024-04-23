#include <iostream>
using namespace std;
main (){
    system("cls");
    long long nomorKartu;
    int digitAkhir;
    do 
    {
        cout<<"Masukkan nomor kartu : ";
        cin>>nomorKartu;
    }
    while(nomorKartu<=0);
    cout<<"Nomor Kartu anda : "<<nomorKartu<<endl;
    
    long long angkaKartu=nomorKartu;
    int checksum=0;
    while(angkaKartu>0)
    {
        digitAkhir=angkaKartu%10;
        checksum+=digitAkhir;
        angkaKartu/=100;
        cout<<digitAkhir<<endl;
    }
    
}