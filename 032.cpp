#include <iostream>
using namespace std;
main (){
    long long nomorKartu;
    do 
    {
        cout<<"Masukkan nomor kartu : ";
        cin>>nomorKartu;
    }
    while(nomorKartu<=0);
    cout<<"Nomor Kartu anda : "<<nomorKartu<<endl;
}