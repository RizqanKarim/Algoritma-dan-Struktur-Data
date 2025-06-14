#include <iostream>
using namespace std;

struct Kendaraan {
    string platNomor;
    string jenis;
    string namaPemilik;
    string alamat;
    string kota;
};

int main() {
    Kendaraan mobil = {"DA1234MK", "RUSH", "Andika Hartanto", "Jl. Kayu Tangi 1", "Banjarmasin"};

    cout << "Plat Nomor Kendaraan : " << mobil.platNomor << endl;
    cout << "Jenis Kendaraan      : " << mobil.jenis << endl;
    cout << "Nama Pemilik         : " << mobil.namaPemilik << endl;
    cout << "Alamat               : " << mobil.alamat << endl;
    cout << "Kota                 : " << mobil.kota << endl;

    return 0;
}
