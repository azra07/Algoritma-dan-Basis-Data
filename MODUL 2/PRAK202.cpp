#include <iostream>
#include <conio.h>
#define max 5
using namespace std;

struct stack {
    int atas = -1;
    int data[max];
};
struct stack Tumpuk;

int penuh(){
    if (Tumpuk.atas == max-1) {
        return 1;
    }
    else {
        return 0;
    }
}

int kosong(){
    if (Tumpuk.atas == -1) {
        return 1;
    }
    else {
        return 0;
    }
}

void input (int data) {
    if (kosong () == 1) {
        Tumpuk.atas++;
        Tumpuk.data[Tumpuk.atas]=data;
        cout << "Data " << Tumpuk.data[Tumpuk.atas] << " Masuk ke stack" << endl;
    }
    else if (penuh() == 0) {
        Tumpuk.atas++;
        Tumpuk.data[Tumpuk.atas]=data;
        cout << "Data" << Tumpuk.data[Tumpuk.atas] << "Masuk ke stack" << endl;
    }
    else {
        cout << "Tumpukan penuh" << endl;
    }

}

void hapus(){
    if (kosong() == 0) {
        cout << "Data Teratas sudah Terambil" << endl;
        Tumpuk.atas--;
    }
    else {
        cout << "Data Kosong" << endl;
    }
}

void tampil(){
    if (kosong() == 0) {
        for (int i = Tumpuk.atas; i >= 0; i--) {
            cout << "Tumpukan Ke " << i << " = " << Tumpuk.data[i] << endl;
        }
    }
    else {
        cout << "Tumpukan Kosong" << endl;
    }
}

void bersih(){
    Tumpuk.atas = -1;
    cout << "Tumpukan Kosong !" << endl;
}

int main(){
    int pilih, nilai;
    do
    {
        cout << "\nStack" << endl;
        cout << "=========" << endl;
        cout << "1. Input" <<endl;
        cout << "2. Hapus" <<endl;
        cout << "3. Tampilkan Stack" <<endl;
        cout << "4. Kosongkan Stack" <<endl;
        cout << "5. Quit" <<endl;
        cout << "Pilihan: "; cin >> pilih;

        switch (pilih)
        {
        case 1:
            cout << "Masukkan angka: "; cin >> nilai;
            input(nilai);
            break;

        case 2:
            hapus();
            break;
            
        case 3:
            tampil();
            break;

        case 4:
            bersih();
            break;

        default:
            cout << "TERIMA KASIH" << endl;
            break;
        }
        cout << "Press any key to continue " << endl;
        getch();
    } while (pilih<5);
    
}