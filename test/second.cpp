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

    rwbookstore.insertBelakang(bukuPahlawan, "Soekarno", 75, 180, "Buku Pahlawan");
    rwbookstore.insertBelakang(bukuPahlawan, "Moh Hatta", 65, 200, "Buku Pahlawan");
    rwbookstore.insertBelakang(bukuPahlawan, "Moh Hatta", 65, 200, "Buku Pahlawan");
    rwbookstore.insertBelakang(bukuPahlawan, "Kartini", 75, 180, "Buku Pahlawan");
    rwbookstore.tampilanDaftarBuku(bukuPahlawan);

    rwbookstore.insertBelakang(bukuFiksi, "Katarsis", 75, 180, "Buku Fiksi");
    rwbookstore.insertBelakang(bukuFiksi, "Yang Terlupakan", 200, 80, "Buku Fiksi");
    rwbookstore.tampilanDaftarBuku(bukuFiksi);
}
