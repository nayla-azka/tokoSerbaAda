#include <iostream>
#include <string>
#include <utility>
#include <iomanip>
using namespace std;


//Global Variables
const int totalItem = 3;
const int hari = 3;
const int kategori = 3;

int idItem[totalItem] = {101, 102, 103};
string namaItem[totalItem] = {"Kopi Susu", "Roti Bakar", "Teh Manis"};
int hargaItem[totalItem] = {18000, 15000, 6000};
int stokItem[totalItem] = {20, 15, 30};
int indexKategoriItem[totalItem] = {0, 1, 0};

int salesMatrix[hari][kategori] = {
    {120000, 180000, 45000},
    {150000, 210000, 60000},
    {200000, 250000, 80000}
};

// Fungsi member 1

void tampilkanInventaris() {
    cout << "=======================================================\n";
    
    cout << left << setw(8) << "ID" 
         << setw(18) << "Nama Barang" 
         << setw(16) << "Harga (Rp)" 
         << "Stok\n";
    cout << "=======================================================\n";

    
    for (int i = 0; i < totalItem; i++) {
        cout << left << setw(8) << idItem[i] 
             << setw(18) << namaItem[i] 
             << setw(16) << hargaItem[i] 
             << stokItem[i] << "\n";
    }
    
    cout << "=======================================================\n";
}

// Fungsi member 2


// Fungsi member 3 (Bubble sort)
void urutkanHarga(bool ascending) {
    for(int i = 0; i < totalItem - 1; i++) {
        for(int j = 0; j < totalItem - i - 1; j++) {
            if(ascending && hargaItem[j] > hargaItem[j + 1]) {
                swap(idItem[j], idItem[j + 1]);
                swap(namaItem[j], namaItem[j + 1]);
                swap(hargaItem[j], hargaItem[j + 1]);
                swap(stokItem[j], stokItem[j + 1]);
            } else if(!ascending && hargaItem[j] < hargaItem[j + 1]) {
                swap(idItem[j], idItem[j + 1]);
                swap(namaItem[j], namaItem[j + 1]);
                swap(hargaItem[j], hargaItem[j + 1]);
                swap(stokItem[j], stokItem[j + 1]);
            }
        }
    }
}


// variabel globalnya
int idKeranjang[100];
int qtyKeranjang[100];
int jumlahJenisKeranjang = 0;

// Fungsi member 4
void tambahKeKeranjang() {
    char lanjut = 'y';

    while (lanjut == 'y' || lanjut == 'Y') {
        int targetID, jumlahBeli;
        int indeksDitemukan = -1;

        cout << "\n--- Tambah ke Keranjang ---\n";
        cout << "Masukkan ID Barang yang ingin dibeli: ";
        cin >> targetID;

        // cari indeks barang berdasarkan ID
        for (int i = 0; i < totalItem; i++) {
            if (idItem[i] == targetID) {
                indeksDitemukan = i;
                break;
            }
        }

        // validasi Keberadaan Barang & Stok
        if (indeksDitemukan == -1) {
            cout << "[404 not found] Barang dengan ID " << targetID << " tidak ditemukan!\n";
        } else {
            cout << "Barang dipilih : " << namaItem[indeksDitemukan] << endl;
            cout << "Stok tersedia  : " << stokItem[indeksDitemukan] << endl;
            cout << "Masukkan Jumlah Beli: ";
            cin >> jumlahBeli;

            // validasi stok (syarat kondisi)
            if (jumlahBeli <= 0) {
                cout << "[ERROR] Jumlah beli harus lebih besar dari 0!\n";
            } else if (jumlahBeli > stokItem[indeksDitemukan]) {
                cout << "[ERROR] Stok tidak mencukupi! Stok tersedia: " 
                     << stokItem[indeksDitemukan] << endl;
            } else {

                // simpan ke keranjang
                idKeranjang[jumlahJenisKeranjang] = targetID;
                qtyKeranjang[jumlahJenisKeranjang] = jumlahBeli;
                jumlahJenisKeranjang++;

                // potong stok barang di inventaris utama
                stokItem[indeksDitemukan] -= jumlahBeli;

                cout << "[SUKSES] " << jumlahBeli << " " << namaItem[indeksDitemukan] 
                     << " berhasil ditambahkan ke keranjang.\n";
            }
        }

        cout << "\nApakah ingin menambah barang lain? (y/n): ";
        cin >> lanjut;
    }
}


// Fungsi member, padilganteng

// Fungsi member 6


// Fungsi member 7
void tampilkanLaporan2D(){
    cout << "\n===============================================================\n"
         << "         MATRIKS REKAP PENJUALAN 2D (3 HARI X 3 KATEGORI         \n"
         << "\n===============================================================\n"
         << "Hari\t\tMinuman\t\tMakanan\t\tLainnya\t\tTotal\n"
         << "----------------------------------------------------------------";
         
        int totalFinal = 0;
        for(int h = 0; h < hari; h++){

            int totalHarian = 0;

            cout << "Hari " << (h + 1) << "\t\t";

            for(int k = 0; k < kategori; k++){
                    cout << "Rp " << salesMatrix[h][k] << "\t";

                    totalHarian += salesMatrix[h][k];
                }

            cout << "Rp " << totalHarian << endl;

            totalFinal += totalHarian;
        }
            
        cout << "----------------------------------------------------------------\n"
             << "TOTAL KESELURUHAN REVENUE : " << totalFinal << endl
             << "\n===============================================================\n";
}


// Fungsi member 8


// Fungsi member 9

