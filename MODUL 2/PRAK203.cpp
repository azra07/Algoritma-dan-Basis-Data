#include <iostream>
#include <conio.h>
#include <stdlib.h>
#define n 10
using namespace std;

struct Queue {
    int front, rear;
    char Q[n];
};

struct Queue antrian;

void RESET() {
    antrian.front = -1;
    antrian.rear = -1;
}

void Inisialisasi() {
    RESET();
}

void INSERT() {
    char huruf;
    if (antrian.rear == n - 1) {
        cout << "Queue penuh" << endl;
    } else {
        cout << "Masukkan huruf: ";
        cin >> huruf;
        if (antrian.front == -1) {
            antrian.front = 0;
        }
        antrian.rear++;
        antrian.Q[antrian.rear] = huruf;
    }
}

void DELETE() {
    if (antrian.front == -1 || antrian.front > antrian.rear) {
        cout << "Queue kosong" << endl;
        RESET();
    } else {
        cout << "Hapus Q: " << antrian.Q[antrian.front] << endl;
        antrian.front++;
        if (antrian.front > antrian.rear) {
            RESET();
        }
    }
}

void CETAKLAYAR() {
    if (antrian.front == -1 || antrian.front > antrian.rear) {
        cout << "Queue kosong" << endl;
    } else {
        cout << "Isi queue: ";
        for (int i = antrian.front; i <= antrian.rear; i++) {
            cout << antrian.Q[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    char pilihan[1];
    int pil;

    Inisialisasi();
    do {
        cout << "QUEUE" << endl;
        cout << "==============" << endl;
        cout << "1. INSERT" << endl;
        cout << "2. DELETE" << endl;
        cout << "3. CETAK QUEUE" << endl;
        cout << "4. QUIT" << endl;
        cout << "PILIHAN: ";
        cin >> pilihan;
        pil = atoi(pilihan);

        switch (pil) {
            case 1:
                INSERT();
                break;
            case 2:
                DELETE();
                break;
            case 3:
                CETAKLAYAR();
                break;
            default:
                cout << "TERIMA KASIH" << endl;
                break;
        }
            cout << "Press any key to continue " << endl;
            getch();
            system("cls");
    } while (pil < 4);

    return 0;
}