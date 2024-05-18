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
    LinkedList *bukuAgamaIslam = (rwbookstore.buatLinkedList());
    LinkedList *bukuBahasa = (rwbookstore.buatLinkedList());
    LinkedList *bukuSeniDanOlahraga = (rwbookstore.buatLinkedList());
    LinkedList *bukuMajalah = (rwbookstore.buatLinkedList());
    LinkedList *bukuAkademik = (rwbookstore.buatLinkedList());

    rwbookstore.insertBelakang(bukuPahlawan, "Soekarno", 75, 180, "Buku Pahlawan");
    rwbookstore.insertBelakang(bukuPahlawan, "Moh Hatta", 65, 200, "Buku Pahlawan");
    rwbookstore.insertBelakang(bukuPahlawan, "Moh Hatta", 65, 200, "Buku Pahlawan");
    rwbookstore.insertBelakang(bukuPahlawan, "Kartini", 75, 180, "Buku Pahlawan");
    rwbookstore.tampilanDaftarBuku(bukuPahlawan);

    rwbookstore.insertBelakang(bukuFiksi, "Katarsis", 75, 180, "Buku Fiksi");
    rwbookstore.insertBelakang(bukuFiksi, "Yang Terlupakan", 200, 80, "Buku Fiksi");
    rwbookstore.tampilanDaftarBuku(bukuFiksi);

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

}
