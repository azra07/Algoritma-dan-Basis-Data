#include <iostream>
using namespace std;

struct sim
{
    char nomor_plat[20], jenis_kendaraan[20], nama_pemilik[20], alamat[20], kota[20];
};

int main(){
    struct sim andi = {"DA1234MK", "RUSH", " Andika Hartanto", " Jl. Kayu Tangi 1", "Banjarmasin"};

    cout<<"Plat Nomor Kendaraan : " << andi.nomor_plat;
    cout<<"\nJenis Kendaraan : " << andi.jenis_kendaraan;
    cout<<"\nNama Pemilik : " << andi.nama_pemilik;
    cout<<"\nAlamat : " << andi.alamat;
    cout<<"\nKota : " <<andi.kota;

    return 0;
}