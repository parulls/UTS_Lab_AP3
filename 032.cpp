#include <iostream> //header 
using namespace std; //supaya tidak perlu menggunakan ::std

int hitungChecksumTidakKaliDua(long long nomorKartu) { //deklarasi fungsi untuk mencari checksum dari angka-angka yang tidak dikali dua
    long long angkaKartu = nomorKartu; //inisialisasi nomorKKartu sebagai angkaKartu
    int checksum = 0, digitAkhir; //inisialisasi variabel checksum sebagai 0, digunakan untuk menghitung jumlah seluruh digit akhir dan inisialisasi digit akhir untuk menyimpan digit akhir disetiap looping
    while (angkaKartu > 0) { //memulai looping dan program dijalankan selama angkaKartu>0
        digitAkhir = angkaKartu % 10; //untuk mendapatkan digit akhir kartu yang tidak dikali dua
        checksum += digitAkhir; //menambahkan digit akhir ke checksum
        angkaKartu /= 100; //Untuk menghapus dua digit terakhir dari angkaKartu
    }
    return checksum; //mengembalikan hasil checksum dari fungsi
}

int hitungChecksumKaliDua(long long nomorKartu) {//deklarasi fungsi untuk meghitung checksum dari angka-angka yang dikali dua
    long long noKartu = nomorKartu / 10;//inisialisasi noKatu sebagai nomorKartu/10. untuk menghapus digit terakhir dari nomorKartu
    int checksum = 0, digitAkhir;//inisialisasi variabel checksum sebagai 0, digunakan untuk menghitung jumlah seluruh digit akhir dan inisialisasi digit akhir untuk menyimpan digit akhir disetiap looping
    while (noKartu > 0) {//memulai looping dan program dijalankan selama noKartu lebih dari 0
        digitAkhir = noKartu % 10;//menghitung digit akhir dari noKartu
        int kaliDua = digitAkhir * 2;//inisialisasi variabel dengan nilai digit akhir yang dikalikan dua
        checksum += ((kaliDua % 10) + (kaliDua / 10)); //menambahkan jumlah digit akhir yang sudah dikali dua ke checksum
        noKartu /= 100;//Untuk menghapus dua digit terakhir dari noKartu
    }
    return checksum; //mengembalikan nilai checksum dari fungsi
}

string cekTipeKartu(long long nomorKartu, int checksum) {//deklarasi fungsi untuk mengecek tipe kartu berdasarkan nomorKartu dan checksum
    string tipeKartu;//deklarasi variabell untuk menyimpan tipe kartu
    if (checksum % 10 == 0) {//memeriksa jika checksum kelipatan 10 atau tidak, jika ya, maka tipe kartu akan diperiksa
        if (nomorKartu >= 5100000000000000 && nomorKartu <= 5599999999999999) {//memeriksa rentang kartu, jika rentangnya sesuai, maka tipe kartu adalah Mastercard
            tipeKartu = "MASTERCARD";//inisialisasi tipe kartu sebagai Mastercard
        } else if (nomorKartu / 1000000000000000 == 4 || nomorKartu / 1000000000000 == 4) {//memeriksa apakah digit pertama atau kedua dari nomorKartu adalah 4 
            tipeKartu = "VISA";//jika ya, maka tipe kartu adalah visa
        } else tipeKartu = "TIDAK DIKETAHUI";//jika checksum adalah kelipatan 10, tetapi tidak memenuhi kriteria mastercard dan visa, maka tipe kartu tidak diketahui
    } else tipeKartu = "TIDAK VALID";//jika checksum bukan kelipatan 10, maka tipe kartu tidak valid
    return tipeKartu;//mengembalikan nilai tipekartu
}

void hasilCekKartu(long long nomorKartu, string tipeKartu, int checksum) {//deklarasi fungsi untuk print hasil dari cek kartu diatas
    cout << "Nomor Kartu anda : " << nomorKartu << endl;//print output dan nilai dari nomorKartu
    cout << "Tipe kartu anda : " << tipeKartu << endl;//print output dan nilai dari tipeKartu
    cout << "Checksum : " << checksum;//print output dan nilai dari checksum
}

main() {//deklarasi fungsi utama
    system("cls");//membersihkan layar 
    long long nomorKartu;//deklarasi variabel nomorKartu dengan tipe data long long
    do {//looping yang dilakukan terlebih dahulu sebelum memeriksa syarat
        cout << "Masukkan nomor kartu : ";//meminta user menginput nomor kartu
        cin >> nomorKartu;//input nomor kartu 
    } while (nomorKartu <= 0);//syarat looping, Jika pengguna memasukkan nomor yang kurang dari atau sama dengan 0, program akan terus meminta pengguna untuk memasukkan nomor kartu yang valid.
    int checksum = hitungChecksumTidakKaliDua(nomorKartu);//deklarasi variabbel checksum dan inisialisasi dengan nilai yang kembalian dari fungsi hitungChecksumTidakKaliDua
    checksum += hitungChecksumKaliDua(nomorKartu);//menambahkan nilai dari fungsi hitungChecksumKaliDua ke variabel checksum yang baru saja diinisialisasi
    string tipeKartu = cekTipeKartu(nomorKartu, checksum);//deklarasi variabel tipeKartu dan inisialisasi dengan nilai kembalian dari fungsi cekTipeKartu
    hasilCekKartu(nomorKartu, tipeKartu, checksum);//memanggil fungsi hasilCekKartu
    return 0;//fungsi utama mengembalikan nilai 0
}//akhir program
