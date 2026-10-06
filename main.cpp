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

int cariIndeksBarang(int ID){
    for (int i = 0; i < totalItem; i++) {
            if (idItem[i] == ID) {
                return i;
                break;
            }
    }
    return -1;
}



// Fungsi member 3 (Bubble sort)
void urutkanHarga(bool ascending){
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
void tambahKeKeranjang(){
    char lanjut = 'y';
    
    while (lanjut == 'y' || lanjut == 'Y') {
        int targetID, jumlahBeli;
        
        cout << "\n--- Tambah ke Keranjang ---\n";
        cout << "Masukkan ID Barang yang ingin dibeli: ";
        cin >> targetID;
        
        // cari indeks barang berdasarkan ID
        int indeksDitemukan = cariIndeksBarang(targetID);
        
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
// Fungsi member 6
void CatatPenjualan2D(int catatHari, int catatKategori, int catatHarga){
    if(catatHari >= 0 && catatHari <= 2 && catatKategori >= 0 && catatKategori <= 2){
        salesMatrix[catatHari][catatKategori] += catatHarga;
    }else{
        cout<<"Error: Index hari tidak valid! Index berada pada interval 0<=index<=2";
    }
}
// Fungsi member 7
void tampilkanLaporan2D(){
    cout << "\n===============================================================\n"
         << "         MATRIKS REKAP PENJUALAN 2D (3 HARI X 3 KATEGORI         \n"
         << "\n===============================================================\n"
         << "Hari\t\tMinuman\t\tMakanan\t\tLainnya\t\tTotal\n"
         << "----------------------------------------------------------------\n";
         
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
int hitungPoinRekursif(int totalBelanja, int tier) {
    if (totalBelanja < 10000 || tier <= 0) {
        return 0;
    }
    return 50 + (tier * 10) + hitungPoinRekursif(totalBelanja - 10000, tier - 1);
}

//fungsi member 5 
void prosesPenjualan(int idkeranjang[], int jumlahkeranjang[], int jmljeniskeranjang, int iditem[], string namaitem[], int hargaitem[], int stokitem[], int totaldata, int hari){
    if (jmljeniskeranjang==0){
        cout<<"\n keranjang masih kosong";
        return;
    }
    int subtotal=0;
    cout<<"\n=================== STRUK BELANJA ===================\n";
    for (int i = 0; i < jmljeniskeranjang;i++){
        int id = idkeranjang[i];
        int qty = jumlahkeranjang[i];
        int idx = cariIndeksBarang(id);
        
        if (idx!=-1){
            int totalhargaitem = hargaitem[idx] * qty;
            subtotal += totalhargaitem;
            int kategori = idx % 3;
            CatatPenjualan2D(hari, kategori, totalhargaitem);
            cout<<namaItem[idx]<<" x"<<qty<<" = Rp."<<totalhargaitem<<endl;
        }
    }
    double persendiskon = 0.0;
    if (subtotal>=100000){
        persendiskon=0.15;
    }else if(subtotal>=50000){
        persendiskon=0.10;
    }else{
        persendiskon=0.0;
    }
    int diskon = subtotal*persendiskon;
    int total = subtotal - diskon;
    int poinBonus = hitungPoinRekursif(total, 3);
    cout << "-----------------------------------------------\n";
    cout << "Subtotal     : Rp" << subtotal << endl;
    cout << "Diskon (" << (int)(persendiskon * 100) << "%)  : Rp" << diskon << endl;
    cout << "Total Bayar  : Rp" << total << endl;
    cout << "Poin Bonus (Rekursif): " << poinBonus << " pts\n";
    cout << "===============================================\n";
    int uangBayar = 0;
    do {
        cout << "Masukkan Uang Pembayaran: Rp";
        cin >> uangBayar;
        if (uangBayar < total) {
            cout << "[Gagal] Uang pembayaran kurang! Silakan masukkan jumlah yang cukup.\n";
        }
    } while (uangBayar < total);
    int kembalian = uangBayar - total;
    cout << "Kembalian    : Rp" << kembalian << endl;
    for (int i = 0; i < jmljeniskeranjang; i++) {
        int id = idkeranjang[i];
        int qty = jumlahkeranjang[i];

        int idx = cariIndeksBarang(id);
            if (idx != -1) {
                stokItem[idx] -= qty; 
                break;
            }
        
    }
    jmljeniskeranjang=0;

    cout << "[Sukses] Transaksi Selesai & Stok Diperbarui!\n";

}
// Fungsi member 9
int main(){
    int pilihan;
    char ulang;
    do {
        cout << "======================================================\n";
        cout << "SISTEM MANAJEMEN RETAIL & ANALYTICS TOSERBA HIGHFIVE5\n";
        cout << "======================================================\n";
        cout << "1. Lihat Inventaris Barang\n";
        cout << "2. Proses Transaksi Kasir\n";
        cout << "3. Urutkan Barang\n";
        cout << "4. Lihat Laporan Penjualan\n";
        cout << "5. Hitung Simulasi Poin Loyalty\n";
        cout << "6. Keluar System\n";
        cout << "======================================================\n";
        cout << "Piih Menu (1-6): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tampilkanInventaris();
                break;
        
            case 2:
                tambahKeKeranjang();
                prosesPenjualan(idKeranjang, qtyKeranjang, jumlahJenisKeranjang, idItem, namaItem, hargaItem, stokItem, totalItem);
                break;
        
            case 3: {
                int opsi;
                cout << "Pilih Urutan Harga:\n";
                cout << "1. Termurah ke Termahal (Ascending)\n";
                cout << "2. Termahal ke Termurah (Descending)\n";
                cout << "Pilihan: ";
                cin >> opsi;
                
                if (opsi == 1){
                    urutkanHarga(true);
                    cout << "\n[Sukses] Barang berhasil diurutkan dari termurah ke termahal\n";
                    tampilkanInventaris();
                }
                else if (opsi == 2){
                    urutkanHarga(false);
                    cout << "\n[Sukses] Barang berhasil diurutkan dari termahal ke termurah\n";
                    tampilkanInventaris();
                }
                else {
                    cout << "\nPilihan Tidak Valid!\n";
                }
                break;
            }
                
            case 4:
                tampilkanLaporan2D();
                break;
        
            case 5: {
                int totalBelanja, tier = 3;
                cout << "--- SIMULASI POIN LOYALTY ---\n";
                cout << "Masukkan nominal simulasi belanja (Rp): ";
                cin >> totalBelanja; 

                int totalPoin = hitungPoinRekursif(totalBelanja, tier);
                cout << "Hasil Perhitungan Simulasi Poin Loyalty: " << totalPoin << " Poin Loyalty\n";
                break;
            }

            case 6:
                cout << "\nTerima kasih telah menggunakan Sistem Manajemen Toserba HIGHFIVE5!\n";
                break;

            default:
                cout << "Pilihan menu tidak valid! Silahkan coba lagi.\n";
                break;
        }
        
        if (pilihan == 6){
            break;
        }
        
        cout << "\nKembali ke menu utama? (y/n): ";
        cin >> ulang;
        cout << endl;
    }
    
    while (ulang == 'Y' || ulang == 'y');
    cout << "Program Selesai.\n";

}
