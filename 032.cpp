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
    
    string tipeKartu;
    if (checksum%10==0){
        if (nomorKartu>=5100000000000000 && nomorKartu<=5599999999999999){
            tipeKartu = "MASTERCARD";
        }
        else if((nomorKartu/1000000000000000==4) || (nomorKartu/1000000000000==4))
        {
            tipeKartu = "VISA";
        }
        else {tipeKartu="TIDAK DIKETAHUI";}
    }
    else 
    {
        tipeKartu="TIDAK VALID";
    }

    cout<<"Nomor Kartu anda : "<<nomorKartu<<endl;
    cout<<"Tipe kartu anda : "<<tipeKartu<<endl;
    cout<<"Checksum : "<<checksum;
    /*if (nomorKartu>=5100000000000000 && nomorKartu<=5599999999999999) {
        if (checksum%10==0) {
            tipeKartu = "MASTERCARD";
        }
        else {
            tipeKartu = "TIDAK VALID";
        }
    }
    else if((nomorKartu/1000000000000000==4) || (nomorKartu/1000000000000==4)) {
        if (checksum%10==0) {
            tipeKartu = "VISA";
        }
    }
    else {tipeKartu="TIDAK DIKETAHUI";}

    */
    return 0;
}