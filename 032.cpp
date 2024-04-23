#include <iostream>
using namespace std;
main (){
    system("cls");
    long long nomorKartu;
    do 
    {
        cout<<"Masukkan nomor kartu : ";
        cin>>nomorKartu;
    }
    while(nomorKartu<=0);
    cout<<"Nomor Kartu anda : "<<nomorKartu<<endl;
    
    long long angkaKartu=nomorKartu;
    int checksum=0;
    int digitAkhir;
    while(angkaKartu>0)
    {
        digitAkhir=angkaKartu%10;
        checksum+=digitAkhir;
        angkaKartu/=100;
    }

    long long noKartu=nomorKartu/10;
    int kaliDua;
    while(noKartu>0)
    {
        digitAkhir=noKartu%10;
        kaliDua=digitAkhir*2;
        checksum+=((kaliDua%10)+(kaliDua/10));
        noKartu/=100;
    }
    
    
}