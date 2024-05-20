#include <iostream>
#include <iomanip>
#include <string>
#include <limits>

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
private:
    LinkedList *bukuPahlawan;
    LinkedList *bukuFiksi;
    LinkedList *bukuIlmiah;
    LinkedList *bukuSastra;
    LinkedList *bukuKesehatan;
    LinkedList *bukuAgamaIslam;
    LinkedList *bukuBahasa;
    LinkedList *bukuSeniDanOlahraga;
    LinkedList *bukuMajalah;
    LinkedList *bukuAkademik;

public:
    double totalHarga, diskon, uang;
    string namaBuku;
    int banyakBuku, pilihanMenu;

    Node *head, *tail, *newNode, *current;

    RWBookStore()
    {
        bukuPahlawan = buatLinkedList();
        bukuFiksi = buatLinkedList();
        bukuIlmiah = buatLinkedList();
        bukuSastra = buatLinkedList();
        bukuKesehatan = buatLinkedList();
        bukuAgamaIslam = buatLinkedList();
        bukuBahasa = buatLinkedList();
        bukuSeniDanOlahraga = buatLinkedList();
        bukuMajalah = buatLinkedList();
        bukuAkademik = buatLinkedList();

        insertBelakang(bukuPahlawan, "Soekarno", 75, 180, "Buku Pahlawan");
        insertBelakang(bukuPahlawan, "Moh Hatta", 65, 200, "Buku Pahlawan");
        insertBelakang(bukuPahlawan, "Moh Hatta", 65, 200, "Buku Pahlawan");
        insertBelakang(bukuPahlawan, "Kartini", 75, 180, "Buku Pahlawan");

        insertBelakang(bukuFiksi, "Boneka", 65, 200, "Buku Fiksi");
        insertBelakang(bukuFiksi, "Yaya", 75, 180, "Buku Fiksi");
        insertBelakang(bukuFiksi, "Kurdanil", 100, 400, "Buku Fiksi");
        insertBelakang(bukuFiksi, "Katarsis", 75, 180, "Buku Fiksi");
        insertBelakang(bukuFiksi, "Orang Biasa", 65, 280, "Buku Fiksi");
        insertBelakang(bukuFiksi, "Man Boy", 100, 400, "Buku Fiksi");

        insertBelakang(bukuIlmiah, "Fisika", 65, 200, "Buku Ilmiah");
        insertBelakang(bukuIlmiah, "Ilmiah", 75, 180, "Buku Ilmiah");
        insertBelakang(bukuIlmiah, "Kalkulus", 100, 400, "Buku Ilmiah");
        insertBelakang(bukuIlmiah, "Geografi", 75, 180, "Buku Ilmiah");
        insertBelakang(bukuIlmiah, "Biologi", 65, 280, "Buku Ilmiah");
        insertBelakang(bukuIlmiah, "Astronomi", 100, 400, "Buku Ilmiah");

        insertBelakang(bukuSastra, "Pantun", 65, 200, "Buku Sastra");
        insertBelakang(bukuSastra, "Puisi", 75, 180, "Buku Sastra");
        insertBelakang(bukuSastra, "Hikkayat", 100, 400, "Buku Sastra");
        insertBelakang(bukuSastra, "Buumi manusia", 75, 180, "Buku Sastra");
        insertBelakang(bukuSastra, "Orang Blomington", 65, 280, "Buku Sastra");
        insertBelakang(bukuSastra, "Ronggeh Dukuh", 100, 400, "Buku Sastra");

        insertBelakang(bukuKesehatan, "Jantung Sehat", 65, 200, "Buku Kesehatan");
        insertBelakang(bukuKesehatan, "Cara bernapas", 75, 180, "Buku Kesehatan");
        insertBelakang(bukuKesehatan, "Breath", 100, 400, "Buku Kesehatan");
        insertBelakang(bukuKesehatan, "Sel Yang Berbicara", 75, 180, "Buku Kesehatan");
        insertBelakang(bukuKesehatan, "Mengelola Sayur", 65, 280, "Buku Kesehatan");
        insertBelakang(bukuKesehatan, "Pentingnya Buah", 100, 400, "Buku Kesehatan");

        insertBelakang(bukuAgamaIslam, "Hadist", 75, 180, "Buku Agama Islam");
        insertBelakang(bukuAgamaIslam, "Fikih", 65, 200, "Buku Agama Islam");
        insertBelakang(bukuAgamaIslam, "Tafsir", 100, 400, "Buku Agama Islam");
        insertBelakang(bukuAgamaIslam, "NALAR TASAWUF", 75, 180, "Buku Agama Islam");
        insertBelakang(bukuAgamaIslam, "Maaf Tuhan", 65, 200, "Buku Agama Islam");
        insertBelakang(bukuAgamaIslam, "Islam Santai", 100, 400, "Buku Agama Islam");

        insertBelakang(bukuBahasa, "Bahasa Korea", 75, 180, "Buku Bahasa");
        insertBelakang(bukuBahasa, "Bahasa Inggris", 65, 200, "Buku Bahasa");
        insertBelakang(bukuBahasa, "Bahasa Indonesia", 100, 400, "Buku Bahasa");
        insertBelakang(bukuBahasa, "Bahasa Mandarin", 75, 180, "Buku Bahasa");
        insertBelakang(bukuBahasa, "Bahasa Russia", 65, 200, "Buku Bahasa");
        insertBelakang(bukuBahasa, "Bahasa Jepang", 100, 400, "Buku Bahasa");

        insertBelakang(bukuSeniDanOlahraga, "Seni Tinju", 75, 180, "Buku Seni dan Olahraga");
        insertBelakang(bukuSeniDanOlahraga, "Tubuh Seni Olahraga", 65, 200, "Buku Seni dan Olahraga");
        insertBelakang(bukuSeniDanOlahraga, "Jago Beladiri", 100, 400, "Buku Seni dan Olahraga");
        insertBelakang(bukuSeniDanOlahraga, "PRANA", 75, 180, "Buku Seni dan Olahraga");
        insertBelakang(bukuSeniDanOlahraga, "TAEKWONDO", 65, 200, "Buku Seni dan Olahraga");
        insertBelakang(bukuSeniDanOlahraga, "Seni Pencak Silat", 100, 400, "Buku Seni dan Olahraga");

        insertBelakang(bukuMajalah, "My Trip", 75, 180, "Buku Majalah");
        insertBelakang(bukuMajalah, "Bobo", 65, 200, "Buku Majalah");
        insertBelakang(bukuMajalah, "Prenting", 100, 400, "Buku Majalah");
        insertBelakang(bukuMajalah, "Bilal", 75, 180, "Buku Majalah");
        insertBelakang(bukuMajalah, "Gatra", 65, 200, "Buku Majalah");
        insertBelakang(bukuMajalah, "Kreatif", 100, 400, "Buku Majalah");

        insertBelakang(bukuAkademik, "TOEFL", 75, 180, "Buku Akademik");
        insertBelakang(bukuAkademik, "CPNS", 65, 200, "Buku Akademik");
        insertBelakang(bukuAkademik, "Pejuang Kedinasan", 100, 400, "Buku Akademik");
        insertBelakang(bukuAkademik, "TNI POLRI", 75, 180, "Buku Akademik");
        insertBelakang(bukuAkademik, "UTBK", 65, 200, "Buku Akademik");
        insertBelakang(bukuAkademik, "SKD", 100, 400, "Buku Akademik");
    }

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

    void updateBuku()
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
            cout << "|" << current->nama << "| Harga: Rp." << setprecision(2) << current->harga << "| Stok: " << current->banyak << " |" << endl;
            cout << "--------------------------------------------";
            cout << endl
                 << endl;

            current = current->next;
        }

        prosesTransaksi(list);
    }

    void prosesTransaksi(LinkedList *list)
    {
        cin.ignore();

        while (true)
        {
            current = list->head;
            bool bookFound = false;

            cout << "Masukkan Nama Buku (ketik 'selesai' untuk menyelesaikan pembelian) : ";
            getline(cin, namaBuku);

            if (namaBuku == "selesai")
            {
                break;
            }

            while (current != nullptr)
            {
                if (current->nama == namaBuku)
                {
                    bookFound = true;
                    break;
                }

                current = current->next;
            }

            if (!bookFound)
            {
                cout << endl
                     << "Barang tiak ditemukan" << endl;
                system("pause");

                continue;
            }

            current->banyak;
            cout << "Masukkan jumlah yang ingin dibeli: ";
            cin >> banyakBuku;

            if (banyakBuku > current->banyak)
            {
                cout << "Stok tidak mencukupi." << endl;
                continue;
            }

            current->banyak -= banyakBuku;
            double subTotal = current->harga * banyakBuku;
            totalHarga += subTotal;
            cout << endl;
            cout << "Harga Awal untuk Buku " << current->nama << "                                     : Rp." << setprecision(3) << subTotal << endl;

            kurangiStokBuku(list, namaBuku, banyakBuku);

            if (totalHarga >= 50.000)
            {
                diskon = 0.24 * subTotal;
                subTotal -= diskon;
                cout << "Promo akhir bulan Mendapatkan diskon 24%                              : Rp." << setprecision(3) << diskon << endl;
                cout << "Subtotal untuk Buku " << current->nama << "                                       : Rp." << setprecision(3) << subTotal << endl
                     << endl;
                totalHarga -= diskon;
            }
            else
            {
                cout << "Subtotal untuk Buku " << current->nama << "        Rp." << setprecision(3) << subTotal << endl
                     << endl;
            }

            cout << endl;
            cout << "Total Belanja : Rp." << setprecision(3) << totalHarga << endl; // untuk megatur jumlah desimal pada output
            cout << "Jumlah Uang   : Rp.";
            cin >> uang;
            double pembayaran = uang - totalHarga;
            cout << "Kembalian     : Rp." << setprecision(3) << pembayaran << endl
                 << endl;

            cout << "TERIMA KASIH TELAH BERBELANJA DI R&W Book Emporium" << endl
                 << endl;

            cout << "Apakah Anda ingin melakukan transaksi lain? (1: Ya, 0: Tidak):";
            cin >> pilihanMenu;
            cout << endl;

            if (pilihanMenu == 1)
            {
                return;
                break;
            }
            else
            {
                displayMenu();
            }
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

            current = current->next;
        }
    }

    void searchBuku(LinkedList *list, const string &judul)
    {
        current = list->head;
        bool found = false;

        while (current != nullptr)
        {
            if (current->nama.find(judul) != string::npos)
            {
                cout << "Buku ditemukan: " << current->nama << " | Harga: Rp." << current->harga << " | Stok: " << current->banyak << " | Kategori: " << current->kategori << endl;
                found = true;
            }
            current = current->next;
        }

        if (!found)
        {
            cout << "Buku dengan judul \"" << judul << "\" tidak ditemukan dalam kategori " << list->head->kategori << "." << endl;
        }
    }

    void displayMenu()
    {
        int pilih;
        string judul;

        while (true)
        {
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

            switch (pilih)
            {
            case 1:
            {
                int kategoriPilihan;

                do
                {
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

                    cout << "Pilih kategori [1-11]: ";
                    cin >> kategoriPilihan;

                    switch (kategoriPilihan)
                    {
                    case 1:
                        tampilanDaftarBuku(bukuPahlawan);
                        break;
                    case 2:
                        tampilanDaftarBuku(bukuFiksi);
                        break;
                    case 3:
                        tampilanDaftarBuku(bukuIlmiah);
                        break;
                    case 4:
                        tampilanDaftarBuku(bukuSastra);
                        break;
                    case 5:
                        tampilanDaftarBuku(bukuKesehatan);
                        break;
                    case 6:
                        tampilanDaftarBuku(bukuAgamaIslam);
                        break;
                    case 7:
                        tampilanDaftarBuku(bukuBahasa);
                        break;
                    case 8:
                        tampilanDaftarBuku(bukuSeniDanOlahraga);
                        break;
                    case 9:
                        tampilanDaftarBuku(bukuMajalah);
                        break;
                    case 10:
                        tampilanDaftarBuku(bukuAkademik);
                        break;
                    case 11:
                        return;
                        break;
                    default:
                        cout << "Pilihan tidak valid!" << endl;
                        break;
                    }
                } while (kategoriPilihan != 11);

                break;
            }
            case 2:
            {
                cout << "Masukkan judul buku yang ingin dicari: ";
                cin.ignore();
                getline(cin, judul);

                // searchBuku(bukuPahlawan, judul);
                // searchBuku(bukuFiksi, judul);
                // searchBuku(bukuIlmiah, judul);
                // searchBuku(bukuSastra, judul);
                // searchBuku(bukuKesehatan, judul);
                // searchBuku(bukuAgamaIslam, judul);
                // searchBuku(bukuBahasa, judul);
                // searchBuku(bukuSeniDanOlahraga, judul);
                // searchBuku(bukuMajalah, judul);
                // searchBuku(bukuAkademik, judul);
                break;
            }
            case 3:
                // logout();
                break;
            case 4:
                cout << "Terima kasih! Program selesai." << endl;
                return;
            default:
                cout << "Pilihan tidak valid!" << endl;
                break;
            }
        }
    }
};

void logout()
{
    cout << "Logout berhasil.\n";
}

int main()
{
    RWBookStore rwbookstore;

    rwbookstore.displayMenu();
}
