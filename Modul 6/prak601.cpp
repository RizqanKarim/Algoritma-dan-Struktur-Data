#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <time.h>

using namespace std;

// ==== Bagian dari Sequential Searching ====
int random(int bil) {
    int jumlah = rand() % bil;
    return jumlah;
}

void randomize() {
    srand(time(NULL));
}

void clrscr() {
    system("cls");
}

// ==== MAIN FUNCTION ====
int main() {
    int pilihan;
    do {
        cout << "Pilih menu\n";
        cout << "1. Sequential Searching\n";
        cout << "2. Binary Searching\n";
        cout << "3. Jelaskan Perbedaan Sequential Searching dan Binary Searching!\n";
        cout << "4. Exit\n";
        cout << "Pilih : ";
        cin >> pilihan;

        switch (pilihan) {
        case 1: {
            // ========== Sequential Searching ==========
            clrscr();
            randomize();
            int data[100];
            int cari = 20;
            int counter = 0;
            int flag = 0;
            int save = 0;

            cout << "generating 100 number ...\n";
            for (int i = 0; i < 100; i++) {
                data[i] = random(100) + 1;
                printf(" %d", data[i]);
            }

            printf("\n\nDone.\n");

            for (int i = 0; i < 100; i++) {
                if (data[i] == cari) {
                    counter++;
                    flag = 1;
                    save = i;
                }
            }

            if (flag == 1) {
                printf("Data ada, sebanyak %d\n", counter);
                printf("pada indeks ke-%d\n", save);
            }
            else {
                printf("Data tidak ada!\n");
            }

            break;
        }

        case 2: {
            // ========== Binary Searching ==========
            int n, kiri, kanan, tengah, temp, key;
            bool ketemu = false;

            cout << "Masukan jumlah data: ";
            cin >> n;
            int angka[100];
            for (int i = 0; i < n; i++) {
                cout << "Angka ke-[" << i << "] : ";
                cin >> angka[i];
            }

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n - 1; j++) {
                    if (angka[j] > angka[j + 1]) {
                        temp = angka[j];
                        angka[j] = angka[j + 1];
                        angka[j + 1] = temp;
                    }
                }
            }

            cout << "\nData yang telah diurutkan adalah:\n";
            for (int i = 0; i < n; i++) {
                cout << angka[i] << " ";
            }

            cout << "\n\nMasukan angka yang dicari: ";
            cin >> key;

            kiri = 0;
            kanan = n;
            while (kiri <= kanan) {
                tengah = (kiri + kanan) / 2;
                if (key == angka[tengah]) {
                    ketemu = true;
                    break;
                }
                else if (key < angka[tengah]) {
                    kanan = tengah - 1;
                }
                else {
                    kiri = tengah + 1;
                }
            }

            if (ketemu == true)
                cout << "Angka ditemukan!\n";
            else
                cout << "Angka tidak ditemukan!\n";

            break;
        }

        case 3: {
            // Penjelasan perbedaan
            cout << "\n=== Perbedaan Sequential dan Binary Searching ===\n\n";

            cout << "1. Sequential Searching:\n";
            cout << "- Mencari data satu per satu dari awal.\n";
            cout << "- Tidak memerlukan data yang terurut.\n";
            cout << "- Kompleksitas waktu: O(n).\n";
            cout << "- Kelebihan: Sederhana, tidak butuh sorting.\n";
            cout << "- Kekurangan: Tidak efisien untuk data besar.\n\n";

            cout << "2. Binary Searching:\n";
            cout << "- Membagi data menjadi dua dan mencari secara logaritmik.\n";
            cout << "- Membutuhkan data yang sudah terurut.\n";
            cout << "- Kompleksitas waktu: O(log n).\n";
            cout << "- Kelebihan: Cepat pada data besar yang terurut.\n";
            cout << "- Kekurangan: Harus sorting dulu sebelum mencari.\n";

            break;
        }

        case 4:
            cout << "Terima kasih!\n";
            break;

        default:
            cout << "Pilihan tidak valid.\n";
        }

        cout << "\n-----------------------------\n";
    } while (pilihan != 4);

    return 0;
}
