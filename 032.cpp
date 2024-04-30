#include <iostream>
using namespace std;

int hitungChecksum(long long nomorKartu) {
    long long angkaKartu = nomorKartu;
    int checksum = 0, digitAkhir;
    while (angkaKartu > 0) {
        digitAkhir = angkaKartu % 10;
        checksum += digitAkhir;
        angkaKartu /= 100;
    }
    return checksum;
}

int hitungKaliDua(long long nomorKartu) {
    long long noKartu = nomorKartu / 10;
    int checksum = 0, digitAkhir;
    while (noKartu > 0) {
        digitAkhir = noKartu % 10;
        int kaliDua = digitAkhir * 2;
        checksum += ((kaliDua % 10) + (kaliDua / 10)); 
        noKartu /= 100;
    }
    return checksum; 
}

string cekTipeKartu(long long nomorKartu, int checksum) {
    string tipeKartu;
    if (checksum % 10 == 0) {
        if (nomorKartu >= 5100000000000000 && nomorKartu <= 5599999999999999) {
            tipeKartu = "MASTERCARD";
        } else if (nomorKartu / 1000000000000000 == 4 || nomorKartu / 1000000000000 == 4) { 
            tipeKartu = "VISA";
        } else tipeKartu = "TIDAK DIKETAHUI";
    } else tipeKartu = "TIDAK VALID";
    return tipeKartu;
}

void hasilCekKartu(long long nomorKartu, string tipeKartu, int checksum) {
    cout << "Nomor Kartu anda : " << nomorKartu << endl;
    cout << "Tipe kartu anda : " << tipeKartu << endl;
    cout << "Checksum : " << checksum;
}

main() {
    system("cls");
    long long nomorKartu;
    do {
        cout << "Masukkan nomor kartu : ";
        cin >> nomorKartu;
    } while (nomorKartu <= 0);
    int checksum = hitungChecksum(nomorKartu);
    checksum += hitungKaliDua(nomorKartu);
    string tipeKartu = cekTipeKartu(nomorKartu, checksum);
    hasilCekKartu(nomorKartu, tipeKartu, checksum);
    return 0;
}
