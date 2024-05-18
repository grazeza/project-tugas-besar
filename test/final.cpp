#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <thread>
#include <chrono>

using namespace std;

const int tableIndex = 10;

class User
{
public:
    string username;
    string password;
    string role;

    User(string username, string password, string role)
    {
        this->username = username;
        this->password = password;
        this->role = role;
    }
};

class HashMap
{
private:
    vector<User *> table[tableIndex];

public:
    ~HashMap()
    {
        for (int i = 0; i < tableIndex; i++)
        {
            for (User *user : table[i])
            {
                delete user;
            }
        }
    }

    int simpleHash(string key)
    {
        int hashValue = 0;

        for (char c : key)
        {
            hashValue += c;
        }

        return hashValue % tableIndex;
    }

    bool Login(string username, string password)
    {
        int hashValue = simpleHash(username);

        for (User *user : table[hashValue])
        {
            if (user->username == username && user->password == password)
            {
                return true;
            }
        }

        return false;
    }

    void Register(string username, string password, string code)
    {
        int hashValue = simpleHash(username);
        string role = (code == "cihuy" ? "admin" : "user");

        for (User *user : table[hashValue])
        {
            if (user->username == username)
            {
                user->password = password;
                user->role = role;
                return;
            }
        }

        table[hashValue].push_back(new User(username, password, role));

        cout << "Berhasil Login" << endl;
    }

    void remove(string username)
    {
        int hashValue = simpleHash(username);

        for (auto it = table[hashValue].begin(); it != table[hashValue].end(); it++)
        {
            if ((*it)->username == username)
            {
                table[hashValue].erase(it);
                return;
            }
        }
    }

    void searchByUsername(string NIM)
    {
    }

    void print()
    {
        cout << "---------------------------------------------------------------" << endl;
        cout << "|   No   |              Username            |       Role      |" << endl;
        cout << "---------------------------------------------------------------" << endl;

        for (int i = 0; i < tableIndex; i++)
        {
            for (User *user : table[i])
            {
                if (user != nullptr)
                {
                    cout << "---------------------------------------------------------------" << endl;
                    cout << "| " << setw(6) << left << i << " | " << setw(28) << left << user->username << " | " << setw(20) << left << user->role << "|" << endl;
                    cout << "---------------------------------------------------------------" << endl;
                }
            }
        }
    }
};

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
    HashMap tabelUsers;
    RWBookStore rwbookstore;

    int choiceLoginMenu;
    int masuk;
    int pilih;
    int masuk2;
    string username, password, code;

    LinkedList *bukuPahlawan = (rwbookstore.buatLinkedList());
    LinkedList *bukuFiksi = (rwbookstore.buatLinkedList());
    LinkedList *bukuIlmiah = (rwbookstore.buatLinkedList());
    LinkedList *bukuSastra = (rwbookstore.buatLinkedList());

    rwbookstore.insertBelakang(bukuPahlawan, "Soekarno", 75, 180, "Buku Pahlawan");
    rwbookstore.insertBelakang(bukuPahlawan, "Moh Hatta", 65, 200, "Buku Pahlawan");
    rwbookstore.insertBelakang(bukuPahlawan, "Buya Hamka", 100, 400, "Buku Pahlawan");

    rwbookstore.insertBelakang(bukuPahlawan, "yaya", 75, 180, "Buku Fiksi");
    rwbookstore.insertBelakang(bukuPahlawan, "boneka", 65, 200, "Buku Fiksi");
    rwbookstore.insertBelakang(bukuFiksi, "Yang Terlupakan", 200, 80, "Buku Fiksi");

    cout << "-------------------------------------------- SELAMAT DATANG DI RWF Book Emporium ---------------------------------------" << endl;
    cout << "Silahkan Login Terlebih Dahulu" << endl
         << endl;

    while (true)
    {
        cout << "1. Login" << endl;
        cout << "2. Register" << endl;
        cout << "0. Exit" << endl;
        cout << "Pilih? ";
        cin >> choiceLoginMenu;

        switch (choiceLoginMenu)
        {
        case 1:
            cout << endl
                 << "Masukkan username: ";
            cin >> username;

            cout << "Masukkan password: ";
            cin >> password;

            if (tabelUsers.Login(username, password))
            {
                cout << "Login Berhasil" << endl;
                cout << endl
                     << endl;

                cout << "SELAMAT DATANG " << username << " DI RWF Book Emporium " << endl
                     << endl;
                cout << endl;

                for (int i = 0; i < 20; ++i)
                { // efek visual
                    std::cout << "\rLoading " << std::string(i, '=') << ">" << std::flush;
                    std::this_thread::sleep_for(std::chrono::milliseconds(300));
                    // crono Menyediakan fasilitas untuk mengukur waktu dan mengelola waktu dalam program.
                }

                std::cout << "\rLoading =========" << std::endl
                          << std::endl;
                cout << endl;

                rwbookstore.tampilanDaftarBuku(bukuPahlawan);
                rwbookstore.tampilanDaftarBuku(bukuFiksi);
            }
            else
            {
                cout << "Login Gagal" << endl;
            }

            break;

        case 2:
            cout << endl
                 << "Masukkan username: ";
            cin >> username;

            cout << "Masukkan password: ";
            cin >> password;

            cout << "Masukkan kode unik: ";
            cin >> code;

            tabelUsers.Register(username, password, code);
            break;

        case 0:
            return 0;
            break;

        default:
            cout << "Input yang anda masukkan tidak valid" << endl;
            break;
        }
    }
}
