#include<iostream>
using namespace std;

void Menara (int JumlahPiringan, char MenaraAsal, char MenaraTujuan, char MenaraSementara){
if(JumlahPiringan == 1){
    cout << "Pindahkan Piringan" << JumlahPiringan << "dari" << MenaraAsal << "Ke" << MenaraTujuan << endl;
    }else{
    Menara (JumlahPiringan - 1, MenaraAsal, MenaraSementara, MenaraTujuan);
    cout << "Pindahkan Piringan" << JumlahPiringan << "Dari" << MenaraAsal << "Ke" << MenaraTujuan << endl;
    Menara (JumlahPiringan -1, MenaraAsal, MenaraSementara, MenaraTujuan);
    }

}

int main(){
    int JumlahPiringan;
    cout << "Masukkan Jumlah Piringan :";
    cin >> JumlahPiringan;
    cout << "\nLangkah Langkahnya Adalah Sebagai Berikut: ";
    Menara(JumlahPiringan, 'A', 'C', 'B');
    cout << "\nKeterangan : \n A = Menara Asal \n B = Menara Sementara \n C = Menara Tujuan";
    return 0;
}