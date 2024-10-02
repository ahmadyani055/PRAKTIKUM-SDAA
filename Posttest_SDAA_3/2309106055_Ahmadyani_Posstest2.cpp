#include <iostream>
#include <string>
using namespace std;

struct Barang {
    string nama;
    int stok;
    double harga;
    Barang* next;
};

void tambahBarang(Barang*& head, string namaBarang, int stok, double harga) {
    Barang* newBarang = new Barang;
    newBarang->nama = namaBarang;
    newBarang->stok = stok;
    newBarang->harga = harga;
    newBarang->next = nullptr;

    if (head == nullptr) {
        head = newBarang;
    } else {
        Barang* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newBarang;
    }
}

void tampilkanBarang(Barang* head) {
    if (head == nullptr) {
        cout << "Tidak ada barang dalam daftar." << endl;
        return;
    }
    cout << "\nDaftar Barang Toko Sembakoku:" << endl;
    Barang* temp = head;
    int index = 1;
    while (temp != nullptr) {
        cout << "\nBarang ke-" << index << ":" << endl;
        cout << "Nama Barang  : " << temp->nama << endl;
        cout << "Stok         : " << temp->stok << endl;
        cout << "Harga        : Rp. " << temp->harga << endl;
        temp = temp->next;
        index++;
    }
}

void hapusBarang(Barang*& head, string namaBarang) {
    if (head == nullptr) {
        cout << "Daftar barang kosong." << endl;
        return;
    }

    if (head->nama == namaBarang) {
        Barang* temp = head;
        head = head->next;
        delete temp;
        cout << "Barang " << namaBarang << " berhasil dihapus." << endl;
        return;
    }

    Barang* temp = head;
    while (temp->next != nullptr && temp->next->nama != namaBarang) {
        temp = temp->next;
    }

    if (temp->next == nullptr) {
        cout << "Barang dengan nama " << namaBarang << " tidak ditemukan." << endl;
    } else {
        Barang* del = temp->next;
        temp->next = temp->next->next;
        delete del;
        cout << "Barang " << namaBarang << " berhasil dihapus." << endl;
    }
}

void ubahStok(Barang* head, string namaBarang, int stokBaru) {
    Barang* temp = head;
    while (temp != nullptr) {
        if (temp->nama == namaBarang) {
            temp->stok = stokBaru;
            cout << "Stok barang " << namaBarang << " berhasil diubah menjadi " << stokBaru << "." << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Barang dengan nama " << namaBarang << " tidak ditemukan." << endl;
}

int main() {
    Barang* head = nullptr;
    int pilihan;

    tambahBarang(head, "Beras", 50, 10000);
    tambahBarang(head, "Minyak Goreng", 30, 25000);
    tambahBarang(head, "Gula Pasir", 20, 12000);
    tambahBarang(head, "Mie Instan", 100, 2500);
    tambahBarang(head, "Teh Celup", 40, 1500);
    tambahBarang(head, "Kopi Sachet", 50, 2000);

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

            tambahBarang(head, namaBarang, stok, harga);
            cout << "Barang berhasil ditambahkan." << endl;

        } else if (pilihan == 2) {
            tampilkanBarang(head);

        } else if (pilihan == 3) {
            string namaBarang;

            cout << "Masukkan nama barang yang ingin dihapus: ";
            cin.ignore();
            getline(cin, namaBarang);
            hapusBarang(head, namaBarang);

        } else if (pilihan == 4) {
            string namaBarang;
            int stokBaru;

            cout << "Masukkan nama barang yang ingin diubah stoknya: ";
            cin.ignore();
            getline(cin, namaBarang);
            cout << "Masukkan stok baru: ";
            cin >> stokBaru;
            ubahStok(head, namaBarang, stokBaru);

        } else if (pilihan == 5) {
            cout << "Terima kasih telah menggunakan program ini." << endl;
        } else {
            cout << "Pilihan tidak valid, silakan coba lagi." << endl;
        }

    } while (pilihan != 5);

    return 0;
}
