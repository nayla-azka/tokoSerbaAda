#include <iostream>
#include <string>
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


// Fungsi member 2


// Fungsi member 3


// Fungsi member 4


// Fungsi member 5


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

