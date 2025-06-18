#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

void insertion();
void marge();
void shell();
void quick();
void bubble();
void selection();

int pil;
string pilihan;

int main(){
    do {
        cout<<"-------------------"<<endl;
        cout<<"|     SORTING     |"<<endl;
        cout<<"-------------------"<<endl;
        cout<<"1. Insertion Sort"<<endl;
        cout<<"2. Marge Sort"<<endl;
        cout<<"3. Shell Sort"<<endl;
        cout<<"4. Quick Sort"<<endl;
        cout<<"5. Bubble Sort"<<endl;
        cout<<"6. Selection Sort"<<endl;
        cout<<"7. Exit"<<endl;
        cout<<"-------------------"<<endl;
        cout<<"Masukkan Pilihan: ";
        cin>>pilihan;
        pil=stoi(pilihan);

        switch(pil) {
            case 1:
                insertion();
                break;
            case 2:
                marge();
                break;
            case 3:
                shell();
                break;
            case 4:
                quick();
                break;
            case 5:
                bubble();
                break;
            case 6:
                selection();
                break;
            default:
            break;
        }
        cout<<"\nPress any ke to continue!"<<endl;
        getch();
        system("cls");

    } while(pil<7);
}

void Array(char arr[], int n) {
    for (int i = 0; i < n; i++) cout << arr[i];
    cout << endl;
}

void insertion() {
    string dataStr;
    cout << "Masukkan Nama: ";
    cin.ignore();
    getline(cin, dataStr);

    int n = dataStr.length();
    char data[n];
    for (int i = 0; i < n; i++) data[i] = dataStr[i];

    for (int i = 1; i < n; i++) {
        char key = data[i];
        int j = i - 1;
        while (j >= 0 && data[j] > key) {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = key;
    }

    cout << "Hasil Insertion Sort: ";
    Array(data, n);
}

void penggabungan(char arr[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    char* L = new char[n1], *R = new char[n2];
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
    delete[] L; delete[] R;
}

void mergeSort(char arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        penggabungan(arr, l, m, r);
    }
}

void marge() {
    string dataStr;
    cout << "Masukkan Nama: ";
    cin.ignore();
    getline(cin, dataStr);

    int n = dataStr.length();
    char data[n];
    for (int i = 0; i < n; i++) data[i] = dataStr[i];

    mergeSort(data, 0, n - 1);

    cout << "Hasil Merge Sort: ";
    Array(data, n);
}

void shell() {
    string dataStr;
    cout << "Masukkan Nama: ";
    cin.ignore();
    getline(cin, dataStr);

    int n = dataStr.length();
    char data[n];
    for (int i = 0; i < n; i++) data[i] = dataStr[i];

    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            char temp = data[i];
            int j;
            for (j = i; j >= gap && data[j - gap] > temp; j -= gap)
                data[j] = data[j - gap];
            data[j] = temp;
        }
    }

    cout << "Hasil Shell Sort: ";
    Array(data, n);
}

int partition(char arr[], int low, int high) {
    char pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(char arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void quick() {
    string dataStr;
    cout << "Masukkan NIM: ";
    cin >> dataStr;

    int n = dataStr.length();
    char data[n];
    for (int i = 0; i < n; i++) data[i] = dataStr[i];

    quickSort(data, 0, n - 1);

    cout << "Hasil Quick Sort: ";
    Array(data, n);
}

void bubble() {
    string dataStr;
    cout << "Masukkan NIM: ";
    cin >> dataStr;

    int n = dataStr.length();
    char data[n];
    for (int i = 0; i < n; i++) data[i] = dataStr[i];

    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (data[j] > data[j + 1])
                swap(data[j], data[j + 1]);

    cout << "Hasil Bubble Sort: ";
    Array(data, n);
}

void selection() {
    string dataStr;
    cout << "Masukkan NIM: ";
    cin >> dataStr;

    int n = dataStr.length();
    char data[n];
    for (int i = 0; i < n; i++) data[i] = dataStr[i];

    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
            if (data[j] < data[min_idx])
                min_idx = j;
        swap(data[min_idx], data[i]);
    }

    cout << "Hasil Selection Sort: ";
    Array(data, n);
}