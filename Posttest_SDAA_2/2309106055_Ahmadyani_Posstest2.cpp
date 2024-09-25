#include <iostream>
#include <string>
using namespace std;

struct Barang {
    string nama;
    int stok;
    double harga;
};

void tambahBarang(Barang* daftarBarang, int& jumlahBarang, string namaBarang, int stok, double harga) {
    daftarBarang[jumlahBarang].nama = namaBarang;
    daftarBarang[jumlahBarang].stok = stok;
    daftarBarang[jumlahBarang].harga = harga;
    jumlahBarang++;
}

void tampilkanBarang(Barang* daftarBarang, int jumlahBarang) {
    if (jumlahBarang == 0) {
        cout << "Tidak ada barang dalam daftar." << endl;
        return;
    }
    cout << "\nDaftar Barang Toko Sembakoku:" << endl;
    for (int i = 0; i < jumlahBarang; i++) {
        cout << "\nBarang ke-" << i + 1 << ":" << endl;
        cout << "Nama Barang  : " << daftarBarang[i].nama << endl;
        cout << "Stok         : " << daftarBarang[i].stok << endl;
        cout << "Harga        : Rp. " << daftarBarang[i].harga << endl;
    }
}

void hapusBarang(Barang* daftarBarang, int& jumlahBarang, string namaBarang) {
    for (int i = 0; i < jumlahBarang; i++) {
        if (daftarBarang[i].nama == namaBarang) {
            for (int j = i; j < jumlahBarang - 1; j++) {
                daftarBarang[j] = daftarBarang[j + 1];
            }
            jumlahBarang--;
            cout << "Barang " << namaBarang << " berhasil dihapus." << endl;
            return;
        }
    }
    cout << "Barang dengan nama " << namaBarang << " tidak ditemukan." << endl;
}

void ubahStok(Barang* daftarBarang, int jumlahBarang, string namaBarang, int stokBaru) {
    for (int i = 0; i < jumlahBarang; i++) {
        if (daftarBarang[i].nama == namaBarang) {
            daftarBarang[i].stok = stokBaru;
            cout << "Stok barang " << namaBarang << " berhasil diubah menjadi " << stokBaru << "." << endl;
            return;
        }
    }
    cout << "Barang dengan nama " << namaBarang << " tidak ditemukan." << endl;
}

int main() {
    const int kapasitasMaksimal = 100;
    Barang daftarBarang[kapasitasMaksimal];
    int jumlahBarang = 0;
    int pilihan;

    // Menambahkan data barang awal
    tambahBarang(daftarBarang, jumlahBarang, "Beras", 50, 10000);
    tambahBarang(daftarBarang, jumlahBarang, "Minyak Goreng", 30, 25000);
    tambahBarang(daftarBarang, jumlahBarang, "Gula Pasir", 20, 12000);
    tambahBarang(daftarBarang, jumlahBarang, "Mie Instan", 100, 2500);
    tambahBarang(daftarBarang, jumlahBarang, "Teh Celup", 40, 1500);
    tambahBarang(daftarBarang, jumlahBarang, "Kopi Sachet", 50, 2000);

    do {
        cout << "\n=== Menu Toko Sembako ===" << endl;
        cout << "1. Tambah Barang" << endl;
        cout << "2. Tampilkan Barang" << endl;
        cout << "3. Hapus Barang" << endl;
        cout << "4. Ubah Stok Barang" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        if (pilihan == 1) {
            string namaBarang;
            int stok;
            double harga;

            cout << "Masukkan nama barang: ";
            cin.ignore();
            getline(cin, namaBarang);
            cout << "Masukkan stok barang: ";
            cin >> stok;
            cout << "Masukkan harga barang: ";
            cin >> harga;

            tambahBarang(daftarBarang, jumlahBarang, namaBarang, stok, harga);
            cout << "Barang berhasil ditambahkan." << endl;

        } else if (pilihan == 2) {
            tampilkanBarang(daftarBarang, jumlahBarang);

        } else if (pilihan == 3) {
            string namaBarang;

            cout << "Masukkan nama barang yang ingin dihapus: ";
            cin.ignore();
            getline(cin, namaBarang);
            hapusBarang(daftarBarang, jumlahBarang, namaBarang);

        } else if (pilihan == 4) {
            string namaBarang;
            int stokBaru;

            cout << "Masukkan nama barang yang ingin diubah stoknya: ";
            cin.ignore();
            getline(cin, namaBarang);
            cout << "Masukkan stok baru: ";
            cin >> stokBaru;
            ubahStok(daftarBarang, jumlahBarang, namaBarang, stokBaru);

        } else if (pilihan == 5) {
            cout << "Terima kasih telah menggunakan program ini." << endl;
        } else {
            cout << "Pilihan tidak valid, silakan coba lagi." << endl;
        }

    } while (pilihan != 5);

    return 0;
}
