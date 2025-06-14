#include <iostream>
using namespace std;

const int maxStack = 100;

struct Stack {
    int data[maxStack];
    int atas;
};

Stack Tumpuk;

bool kosong() {
    return Tumpuk.atas == -1;
}

bool penuh() {
    return Tumpuk.atas == maxStack - 1;
}

void input(int data) {
    if (!penuh()) {
        Tumpuk.atas++;
        Tumpuk.data[Tumpuk.atas] = data;
        cout << "Data " << data << " masuk ke stack.\n";
    } else {
        cout << "Tumpukan penuh!\n";
    }
}

void hapus() {
    if (!kosong()) {
        cout << "Data teratas sudah terambil: " << Tumpuk.data[Tumpuk.atas] << "\n";
        Tumpuk.atas--;
    } else {
        cout << "Stack kosong!\n";
    }
}

void tampil() {
    if (!kosong()) {
        cout << "Isi stack:\n";
        for (int i = Tumpuk.atas; i >= 0; i--) {
            cout << "Tumpukan ke-" << i << ": " << Tumpuk.data[i] << "\n";
        }
    } else {
        cout << "Tumpukan kosong!\n";
    }
}

void bersih() {
    Tumpuk.atas = -1;
    cout << "Tumpukan dikosongkan!\n";
}

int main() {
    Tumpuk.atas = -1; // inisialisasi stack kosong

    input(10);
    input(20);
    tampil();
    hapus();
    tampil();
    bersih();
    tampil();

    return 0;
}