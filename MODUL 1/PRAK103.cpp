#include <iostream>
using namespace std;

struct program
{
    char huruf;
    string kata;
    int angka;
};

int main(){
    struct program tulis;

    cout<<"Masukkan sebuah huruf = "; cin>>tulis.huruf;
    cout<<"Masukan sebuah kata = "; cin>>tulis.kata;
    cout<<"Masukkan Angka = "; cin>>tulis.angka;
    cout<<"\nHuruf yang Anda masukkan adalah " << tulis.huruf;
    cout<<"\nKata yang Anda masukkan adalah " << tulis.kata;
    cout<<"\nAngka yang Anda masukkan adalah " << tulis.angka;

    return 0;
}