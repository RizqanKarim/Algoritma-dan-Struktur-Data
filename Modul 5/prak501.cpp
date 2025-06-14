#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Prototipe fungsi
void insertionSort(string &arr);
void mergeSort(string &arr);
void shellSort(string &arr);
void merge(string &arr, int l, int m, int r);
void mergeSortHelper(string &arr, int l, int r);

void quickSort(vector<int> &arr);
void quickSortHelper(vector<int> &arr, int low, int high);
int partition(vector<int> &arr, int low, int high);
void bubbleSort(vector<int> &arr);
void selectionSort(vector<int> &arr);

int main() {
    string name;
    string nimStr;

    cout << "Masukkan nama Anda: ";
    getline(cin, name);
    cout << "Masukkan NIM Anda: ";
    cin >> nimStr;

    // Konversi NIM ke digit
    vector<int> nimDigits;
    for (char c : nimStr) {
        if (isdigit(c)) {
            nimDigits.push_back(c - '0');
        } else {
            cout << "NIM tidak valid. Harap masukkan angka saja." << endl;
            return 1;
        }
    }

    int pilihan;
    do {
        // Tampilan menu
        cout << "\n\t\t==============================\n";
        cout << "\t\t|           SORTING          |\n";
        cout << "\t\t==============================\n";
        cout << "\t\t| 1. Insertion Sort          |\n";
        cout << "\t\t| 2. Merge Sort              |\n";
        cout << "\t\t| 3. Shell Sort              |\n";
        cout << "\t\t| 4. Quick Sort              |\n";
        cout << "\t\t| 5. Bubble Sort             |\n";
        cout << "\t\t| 6. Selection Sort          |\n";
        cout << "\t\t| 7. Exit                    |\n";
        cout << "\t\t==============================\n";
        cout << "\t\tMasukkan Pilihan : ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                string temp = name;
                insertionSort(temp);
                cout << "Hasil Insertion Sort pada nama: " << temp << endl;
                break;
            }
            case 2: {
                string temp = name;
                mergeSort(temp);
                cout << "Hasil Merge Sort pada nama: " << temp << endl;
                break;
            }
            case 3: {
                string temp = name;
                shellSort(temp);
                cout << "Hasil Shell Sort pada nama: " << temp << endl;
                break;
            }
            case 4: {
                vector<int> temp = nimDigits;
                quickSort(temp);
                cout << "Hasil Quick Sort pada NIM: ";
                for (int d : temp) cout << d << " ";
                cout << endl;
                break;
            }
            case 5: {
                vector<int> temp = nimDigits;
                bubbleSort(temp);
                cout << "Hasil Bubble Sort pada NIM: ";
                for (int d : temp) cout << d << " ";
                cout << endl;
                break;
            }
            case 6: {
                vector<int> temp = nimDigits;
                selectionSort(temp);
                cout << "Hasil Selection Sort pada NIM: ";
                for (int d : temp) cout << d << " ";
                cout << endl;
                break;
            }
            case 7:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 7);

    return 0;
}

// === Fungsi Sorting Nama ===
void insertionSort(string &arr) {
    int n = arr.length();
    for (int i = 1; i < n; i++) {
        char key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void merge(string &arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    string L(n1, ' '), R(n2, ' ');
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSortHelper(string &arr, int l, int r) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    mergeSortHelper(arr, l, m);
    mergeSortHelper(arr, m + 1, r);
    merge(arr, l, m, r);
}

void mergeSort(string &arr) {
    mergeSortHelper(arr, 0, arr.length() - 1);
}

void shellSort(string &arr) {
    int n = arr.length();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            char temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
}

// === Fungsi Sorting NIM ===
int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSortHelper(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSortHelper(arr, low, pi - 1);
        quickSortHelper(arr, pi + 1, high);
    }
}

void quickSort(vector<int> &arr) {
    quickSortHelper(arr, 0, arr.size() - 1);
}

void bubbleSort(vector<int> &arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

void selectionSort(vector<int> &arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        swap(arr[min_idx], arr[i]);
    }
}
