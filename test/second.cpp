#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

typedef struct Node
{
    string nama;
    double harga;
    int banyak;
    string kategori;
    Node *next;
} Node;

typedef struct LinkedList
{
    Node *head, *tail;
} LinkedList;

class RWBookStore
{
public:
    Node *head, *tail, *newNode, *current;

    LinkedList *buatLinkedList()
    {
        LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
        list->head = nullptr;
        list->tail = nullptr;
        return list;
    }

    bool isEmpty(LinkedList *list)
    {
        return list->head == nullptr;
    }

    void makeNewNode(string nama, double harga, int banyak, string kategori)
    {
        newNode = new Node;
        newNode->nama = nama;
        newNode->harga = harga;
        newNode->banyak = banyak;
        newNode->kategori = kategori;
        newNode->next = nullptr;
    }

    void insertBelakang(LinkedList *list, string nama, double harga, int banyak, string kategori)
    {
        makeNewNode(nama, harga, banyak, kategori);

        if (isEmpty(list))
        {
            list->head = newNode;
            list->tail = newNode;
        }
        else
        {
            list->tail->next = newNode;
            list->tail = newNode;
        }
    }

    void deleteByNamaBuku()
    {
    }

    void tampilanDaftarBuku(LinkedList *list)
    {
        cout << "\n---------=== DAFTAR BUKU " << list->head->kategori << " ===---------:" << endl;
        cout << endl;

        current = list->head;

        while (current != nullptr)
        {
            cout << setiosflags(ios::fixed);
            cout << "--------------------------------------------" << endl;
            cout << "|" << current->nama << "| Harga: Rp." << setprecision(3) << current->harga << "| Stok: " << current->banyak << " |" << endl;
            cout << "--------------------------------------------";
            cout << endl
                 << endl;

            current = current->next;
        }
    }

    void kurangiStokBuku(LinkedList *list, const string &namaBuku, int jumlah)
    { //& refresnsi kategori terhadap string
        current = list->head;

        while (current != nullptr)
        {
            if (current->nama == namaBuku)
            {
                current->banyak -= jumlah;
                break;
            }
            else
            {
                current = current->next;
            }
        }
    }

};

int main()
{
    RWBookStore rwbookstore;

    LinkedList *bukuPahlawan = (rwbookstore.buatLinkedList());
    LinkedList *bukuFiksi = (rwbookstore.buatLinkedList());
    LinkedList *bukuIlmiah = (rwbookstore.buatLinkedList());
    LinkedList *bukuSastra = (rwbookstore.buatLinkedList());
    LinkedList *bukuKesehatan = (rwbookstore.buatLinkedList());
    LinkedList *bukuAgamaIslam = (rwbookstore.buatLinkedList());
    LinkedList *bukuBahasa = (rwbookstore.buatLinkedList());
    LinkedList *bukuSeniDanOlahraga = (rwbookstore.buatLinkedList());
    LinkedList *bukuMajalah = (rwbookstore.buatLinkedList());
    LinkedList *bukuAkademik = (rwbookstore.buatLinkedList());

    LinkedList *bukuPahlawan = (rwbookstore.buatLinkedList());
    LinkedList *bukuFiksi = (rwbookstore.buatLinkedList());
    LinkedList *bukuIlmiah = (rwbookstore.buatLinkedList());
    LinkedList *bukuSastra = (rwbookstore.buatLinkedList());
    LinkedList *bukuKesehatan = (rwbookstore.buatLinkedList());

    rwbookstore.insertBelakang(bukuPahlawan, "Soekarno", 75, 180, "Buku Pahlawan");
    rwbookstore.insertBelakang(bukuPahlawan, "Moh Hatta", 65, 200, "Buku Pahlawan");
    rwbookstore.insertBelakang(bukuPahlawan, "Moh Hatta", 65, 200, "Buku Pahlawan");
    rwbookstore.insertBelakang(bukuPahlawan, "Kartini", 75, 180, "Buku Pahlawan");
    rwbookstore.tampilanDaftarBuku(bukuPahlawan);

    rwbookstore.insertBelakang(bukuFiksi, "Boneka", 65, 200, "Buku Fiksi");
    rwbookstore.insertBelakang(bukuFiksi, "Yaya", 75, 180, "Buku Fiksi");
    rwbookstore.insertBelakang(bukuFiksi, "Kurdanil", 100, 400, "Buku Fiksi");
    rwbookstore.insertBelakang(bukuFiksi, "Katarsis", 75, 180, "Buku Fiksi");
    rwbookstore.insertBelakang(bukuFiksi, "Orang Biasa", 65, 280, "Buku Fiksi");
    rwbookstore.insertBelakang(bukuFiksi, "Man Boy", 100, 400, "Buku Fiksi");
    rwbookstore.tampilanDaftarBuku(bukuFiksi);

    rwbookstore.insertBelakang(bukuIlmiah, "Fisika", 65, 200, "Buku Ilmiah");
    rwbookstore.insertBelakang(bukuIlmiah, "Ilmiah", 75, 180, "Buku Ilmiah");
    rwbookstore.insertBelakang(bukuIlmiah, "Kalkulus", 100, 400, "Buku Ilmiah");
    rwbookstore.insertBelakang(bukuIlmiah, "Geografi", 75, 180, "Buku Ilmiah");
    rwbookstore.insertBelakang(bukuIlmiah, "Biologi", 65, 280, "Buku Ilmiah");
    rwbookstore.insertBelakang(bukuIlmiah, "Astronomi", 100, 400, "Buku Ilmiah");
    rwbookstore.tampilanDaftarBuku(bukuIlmiah);

    rwbookstore.insertBelakang(bukuSastra, "Pantun", 65, 200, "Buku Sastra");
    rwbookstore.insertBelakang(bukuSastra, "Puisi", 75, 180, "Buku Sastra");
    rwbookstore.insertBelakang(bukuSastra, "Hikkayat", 100, 400, "Buku Sastra");
    rwbookstore.insertBelakang(bukuSastra, "Buumi manusia", 75, 180, "Buku Sastra");
    rwbookstore.insertBelakang(bukuSastra, "Orang Blomington", 65, 280, "Buku Sastra");
    rwbookstore.insertBelakang(bukuSastra, "Ronggeh Dukuh", 100, 400, "Buku Sastra");
    rwbookstore.tampilanDaftarBuku(bukuSastra);

    rwbookstore.insertBelakang(bukuKesehatan, "Jantung Sehat", 65, 200, "Buku Kesehatan");
    rwbookstore.insertBelakang(bukuKesehatan, "Cara bernapas", 75, 180, "Buku Kesehatan");
    rwbookstore.insertBelakang(bukuKesehatan, "Breath", 100, 400, "Buku Kesehatan");
    rwbookstore.insertBelakang(bukuKesehatan, "Sel Yang Berbicara", 75, 180, "Buku Kesehatan");
    rwbookstore.insertBelakang(bukuKesehatan, "Mengelola Sayur", 65, 280, "Buku Kesehatan");
    rwbookstore.insertBelakang(bukuKesehatan, "Pentingnya Buah", 100, 400, "Buku Kesehatan");
    rwbookstore.tampilanDaftarBuku(bukuKesehatan);

    rwbookstore.insertBelakang(bukuAgamaIslam, "Hadist", 75, 180, "Buku Agama Islam");
    rwbookstore.insertBelakang(bukuAgamaIslam, "Fikih", 65, 200, "Buku Agama Islam");
    rwbookstore.insertBelakang(bukuAgamaIslam, "Tafsir", 100, 400, "Buku Agama Islam");
    rwbookstore.insertBelakang(bukuAgamaIslam, "NALAR TASAWUF", 75, 180, "Buku Agama Islam");
    rwbookstore.insertBelakang(bukuAgamaIslam, "Maaf Tuhan", 65, 200, "Buku Agama Islam");
    rwbookstore.insertBelakang(bukuAgamaIslam, "Islam Santai", 100, 400, "Buku Agama Islam");
    rwbookstore.tampilanDaftarBuku(bukuAgamaIslam);

    rwbookstore.insertBelakang(bukuBahasa, "Bahasa Korea", 75, 180, "Buku Bahasa");
    rwbookstore.insertBelakang(bukuBahasa, "Bahasa Inggris", 65, 200, "Buku Bahasa");
    rwbookstore.insertBelakang(bukuBahasa, "Bahasa Indonesia", 100, 400, "Buku Bahasa");
    rwbookstore.insertBelakang(bukuBahasa, "Bahasa Mandarin", 75, 180, "Buku Bahasa");
    rwbookstore.insertBelakang(bukuBahasa, "Bahasa Russia", 65, 200, "Buku Bahasa");
    rwbookstore.insertBelakang(bukuBahasa, "Bahasa Jepang", 100, 400, "Buku Bahasa");
    rwbookstore.tampilanDaftarBuku(bukuBahasa);

    rwbookstore.insertBelakang(bukuSeniDanOlahraga, "Seni Tinju", 75, 180, "Buku Seni dan Olahraga");
    rwbookstore.insertBelakang(bukuSeniDanOlahraga, "Tubuh Seni Olahraga", 65, 200, "Buku Seni dan Olahraga");
    rwbookstore.insertBelakang(bukuSeniDanOlahraga, "Jago Beladiri", 100, 400, "Buku Seni dan Olahraga");
    rwbookstore.insertBelakang(bukuSeniDanOlahraga, "PRANA", 75, 180, "Buku Seni dan Olahraga");
    rwbookstore.insertBelakang(bukuSeniDanOlahraga, "TAEKWONDO", 65, 200, "Buku Seni dan Olahraga");
    rwbookstore.insertBelakang(bukuSeniDanOlahraga, "Seni Pencak Silat", 100, 400, "Buku Seni dan Olahraga");
    rwbookstore.tampilanDaftarBuku(bukuSeniDanOlahraga);

    rwbookstore.insertBelakang(bukuMajalah, "My Trip", 75, 180, "Buku Majalah");
    rwbookstore.insertBelakang(bukuMajalah, "Bobo", 65, 200, "Buku Majalah");
    rwbookstore.insertBelakang(bukuMajalah, "Prenting", 100, 400, "Buku Majalah");
    rwbookstore.insertBelakang(bukuMajalah, "Bilal", 75, 180, "Buku Majalah");
    rwbookstore.insertBelakang(bukuMajalah, "Gatra", 65, 200, "Buku Majalah");
    rwbookstore.insertBelakang(bukuMajalah, "Kreatif", 100, 400, "Buku Majalah");
    rwbookstore.tampilanDaftarBuku(bukuMajalah);

    rwbookstore.insertBelakang(bukuAkademik, "TOEFL", 75, 180, "Buku Akademik");
    rwbookstore.insertBelakang(bukuAkademik, "CPNS", 65, 200, "Buku Akademik");
    rwbookstore.insertBelakang(bukuAkademik, "Pejuang Kedinasan", 100, 400, "Buku Akademik");
    rwbookstore.insertBelakang(bukuAkademik, "TNI POLRI", 75, 180, "Buku Akademik");
    rwbookstore.insertBelakang(bukuAkademik, "UTBK", 65, 200, "Buku Akademik");
    rwbookstore.insertBelakang(bukuAkademik, "SKD", 100, 400, "Buku Akademik");
    rwbookstore.tampilanDaftarBuku(bukuAkademik);

    int pilih;
    string judul;

    while (true) {
        cout << "-----==MENU UTAMA==----" << endl;
        cout << "-----------------------" << endl;
        cout << "|1.| DAFTAR BUKU       |" << endl;
        cout << "-----------------------" << endl;
        cout << "|2.| SEARCH BUKU       |" << endl;
        cout << "-----------------------" << endl;
        cout << "|3.| LOGOUT            |" << endl;
        cout << "-----------------------" << endl;
        cout << "|4.| EXIT              |" << endl;
        cout << "-----------------------" << endl;

        cout << "\n\nPilihan Anda [1-4]: ";
        cin >> pilih;

        switch (pilih) {
            case 1: {
                cout << "-----==DAFTAR BUKU==----" << endl;
                cout << "-----------------------" << endl;
                cout << "|1.| BUKU PAHLAWAN    |" << endl;
                cout << "-----------------------" << endl;
                cout << "|2.| BUKU FIKSI       |" << endl;
                cout << "-----------------------" << endl;
                cout << "|3.| BUKU ILMIAH      |" << endl;
                cout << "-----------------------" << endl;
                cout << "|4.| BUKU SASTRA      |" << endl;
                cout << "-----------------------" << endl;
                cout << "|5.| BUKU KESEHATAN   |" << endl;
                cout << "-----------------------" << endl;
                cout << "|6.| BUKU AGAMA ISLAM |" << endl;
                cout << "-----------------------" << endl;
                cout << "|7.| BUKU BAHASA      |" << endl;
                cout << "-----------------------" << endl;
                cout << "|8.| BUKU SENI DAN OLAHRAGA |" << endl;
                cout << "-----------------------" << endl;
                cout << "|9.| MAJALAH          |" << endl;
                cout << "-----------------------" << endl;
                cout << "|10.| BUKU AKADEMIK   |" << endl;
                cout << "-----------------------" << endl;
                cout << "|11.| KEMBALI         |" << endl;
                cout << "-----------------------" << endl;

                int kategoriPilihan;
                cout << "Pilih kategori [1-11]: ";
                cin >> kategoriPilihan;

                switch (kategoriPilihan) {
                    case 1:
                        rwbookstore.tampilanDaftarBuku(bukuPahlawan);
                        break;
                    case 2:
                        rwbookstore.tampilanDaftarBuku(bukuFiksi);
                        break;
                    case 3:
                        rwbookstore.tampilanDaftarBuku(bukuIlmiah);
                        break;
                    case 4:
                        rwbookstore.tampilanDaftarBuku(bukuSastra);
                        break;
                    case 5:
                        rwbookstore.tampilanDaftarBuku(bukuKesehatan);
                        break;
                    case 6:
                        rwbookstore.tampilanDaftarBuku(bukuAgamaIslam);
                        break;
                    case 7:
                        rwbookstore.tampilanDaftarBuku(bukuBahasa);
                        break;
                    case 8:
                        rwbookstore.tampilanDaftarBuku(bukuSeniDanOlahraga);
                        break;
                    case 9:
                        rwbookstore.tampilanDaftarBuku(bukuMajalah);
                        break;
                    case 10:
                        rwbookstore.tampilanDaftarBuku(bukuAkademik);
                        break;
                    case 11:
                        break;
                    default:
                        cout << "Pilihan tidak valid!" << endl;
                        break;
                }
                break;
            }
            case 2: {
                cout << "Masukkan judul buku yang ingin dicari: ";
                cin.ignore();
                getline(cin, judul);

                rwbookstore.searchBuku(bukuPahlawan, judul);
                rwbookstore.searchBuku(bukuFiksi, judul);
                rwbookstore.searchBuku(bukuIlmiah, judul);
                rwbookstore.searchBuku(bukuSastra, judul);
                rwbookstore.searchBuku(bukuKesehatan, judul);
                rwbookstore.searchBuku(bukuAgamaIslam, judul);
                rwbookstore.searchBuku(bukuBahasa, judul);
                rwbookstore.searchBuku(bukuSeniDanOlahraga, judul);
                rwbookstore.searchBuku(bukuMajalah, judul);
                rwbookstore.searchBuku(bukuAkademik, judul);
                break;
            }
            case 3:
                logout();
                break;
            case 4:
                cout << "Terima kasih! Program selesai." << endl;
                return 0;
            default:
                cout << "Pilihan tidak valid!" << endl;
                break;
        }
    }


}
