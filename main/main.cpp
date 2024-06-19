#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <limits>
#include <chrono>
#include <thread>

using namespace std;

const int tableIndex = 10; // indeks vector, untuk jumalah maksimal User

// Struktur untuk menampung Node Linked List
typedef struct Node
{
    string nama;
    double harga;
    int banyak;
    string kategori;
    Node *next;
} Node;

// Struktur untuk menyumpan setiap Linked List
typedef struct LinkedList
{
    Node *head, *tail;
} LinkedList;

//
// Linked List untuk Bookstore
// Rangga & Wahyu
//

class RWBookStore
{
public:
    // Deklarasi Linked List setiap kategori
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

    // Variabel global
    double totalHarga, diskon, uang;
    string namaBuku;
    int banyakBuku, pilihanMenu;
    bool notfoundInAllCategories, found;

    Node *head, *tail, *newNode, *current, *temp, *prev;

    // Konstruktor untuk mengisi data Linked List setiap kategori
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

    // Fungsi untuk membuat Linked List
    LinkedList *buatLinkedList()
    {
        // Penambahan Linked List baru yang akan di simpan di Linked List utama
        LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
        list->head = nullptr;
        list->tail = nullptr;
        return list;
    }

    //  Pengecekan kosongnya Linked List
    bool isEmpty(LinkedList *list)
    {
        return list->head == nullptr;
    }

    //  Fungsi untuk membuat Node baru
    void makeNewNode(string nama, double harga, int banyak, string kategori)
    {
        newNode = new Node;
        newNode->nama = nama;
        newNode->harga = harga;
        newNode->banyak = banyak;
        newNode->kategori = kategori;
        newNode->next = nullptr;
    }

    // Fugnsi untuk menambahkan Node baru ke Linked List pada bagian akhir
    // Kenapa insertBelakang? agar data menjadi urut sesuai urutan penambahanya
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

    // Fungsi untuk menghapus suatu Node di dalam Linked List berdasarkan nama buku
    void deleteByNamaBuku(LinkedList *list, string namaBuku)
    {
        temp = list->head;
        prev = nullptr;

        if (temp != nullptr && temp->nama == namaBuku)
        {
            list->head = temp->next;
            delete temp;
            return;
        }

        while (temp != nullptr && temp->nama != namaBuku)
        {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr)
        {
            cout << "!! Buku dengan nama '" << namaBuku << "' tidak ditemukan !!" << endl;
            return;
        }

        if (prev == nullptr)
        {
            list->head = temp->next;
        }
        else
        {
            prev->next = temp->next;
        }

        delete temp;
        cout << "!! Buku dengan nama '" << namaBuku << "' telah dihapus !!" << endl;
    }

    // Fungsi untuk mengupdate sebuah Node dalam Linked List berdasarkan nama buku
    void updateBuku(LinkedList *list)
    {
        cout << "Masukkan nama buku yang ingin DI EDIT  : ";
        getline(cin, namaBuku);

        current = list->head;
        bool bookFound = false;

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
            cout << "!! Buku dengan nama \"" << namaBuku << "\" tidak ditemukan !!" << endl;
            return;
        }

        cout << endl;
        cout << "Masukkan detail baru untuk buku \"" << namaBuku << "\" :" << endl;

        cout << "Nama baru  : ";
        getline(cin, current->nama);

        cout << "Harga baru : ";
        cin >> current->harga;

        cout << "Stok baru  : ";
        cin >> current->banyak;

        cout << "!! Detail buku telah berhasil diperbarui !!" << endl;
    }

    // Fungsi untuk menampilkan Linked List berdasarkan Kategori dan Role User
    void tampilanDaftarBuku(LinkedList *list, string role = "user")
    {
        cout << "\n---------------=== DAFTAR BUKU " << list->head->kategori << " ===---------------" << endl;
        cout << endl;

        current = list->head;

        while (current != nullptr)
        {
            cout << setiosflags(ios::fixed);
            cout << "-----------------------------------------------------------" << endl;
            cout << "| " << setw(18) << left << current->nama
                 << " | Harga: Rp." << setw(10) << right << fixed << setprecision(3) << current->harga
                 << " | Stok: " << setw(5) << current->banyak << " |" << endl;
            cout << "-----------------------------------------------------------";
            cout << endl
                 << endl;

            current = current->next;
        }

        // Pengecekan role untuk proses olah buku yang berbeda
        if (role == "user")
        {
            if (!prosesTransaksi(list))
            {
                return;
            }
        }
        else
        {
            int pilih, choice;
            string namaBukuTemp;
            double harga;
            int banyak;

            do
            {
                cout << endl;
                cout << "--------------------------------------" << endl;
                cout << "| 1. | TAMBAH BUKU                   |" << endl;
                cout << "--------------------------------------" << endl;
                cout << "| 2. | EDIT BUKU                     |" << endl;
                cout << "--------------------------------------" << endl;
                cout << "| 3. | HAPUS BUKU                    |" << endl;
                cout << "--------------------------------------" << endl;
                cout << "| 4. | KEMBALI                       |" << endl;
                cout << "--------------------------------------" << endl;

                cout << "\nPilihan Anda [1-4]: ";
                cin >> pilih;
                cin.ignore();
                cout << endl;

                switch (pilih)
                {
                case 1:
                    cout << "Masukkan Nama Buku     : ";
                    getline(cin, namaBukuTemp);
                    cout << "Masukkan Harga Buku    : ";
                    cin >> harga;
                    cout << "Masukkan Banyak Buku   : ";
                    cin >> banyak;
                    cin.ignore();

                    insertBelakang(list, namaBukuTemp, harga, banyak, list->head->kategori);

                    break;

                case 2:
                    updateBuku(list);
                    break;
                case 3:
                    cout << "Masukkan Nama Buku yang ingin DI HAPUS : ";
                    getline(cin, namaBukuTemp);

                    deleteByNamaBuku(list, namaBukuTemp);

                    break;

                case 4:
                    return;
                    break;

                default:
                    cout << "Pilihan tidak valid, silakan coba lagi" << endl;
                    break;
                }
            } while (pilih != 4);
        }
    }

    // Fungsi untuk memproses transaksi dari user, dengan mengembalikan nilai true atau false sebagai penanda
    bool prosesTransaksi(LinkedList *list)
    {
        cin.ignore();

        while (true)
        {
            current = list->head;
            bool bookFound = false;
            totalHarga = 0;

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
                cout << "Promo akhir bulan Mendapatkan diskon 24%                         : Rp." << setprecision(3) << diskon << endl;
                cout << "Subtotal untuk Buku " << current->nama << "                                       : Rp." << setprecision(3) << subTotal << endl
                     << endl;
                totalHarga -= diskon;
            }
            else
            {
                cout << "Subtotal untuk Buku " << current->nama << "                                       : Rp." << setprecision(3) << subTotal << endl
                     << endl;
            }

            cout << endl;
            cout << "Total Belanja : Rp." << setprecision(3) << totalHarga << endl; // untuk megatur jumlah desimal pada output
            cout << "Jumlah Uang   : Rp.";
            cin >> uang;
            double pembayaran = uang - totalHarga;

            cout << "Kembalian     : Rp." << setprecision(3) << pembayaran << endl
                 << endl;

            cout << "!! TERIMA KASIH TELAH BERBELANJA DI RWF Book Emporium !!" << endl
                 << endl;

            cout << "Apakah Anda ingin melakukan transaksi lain? (1: Ya, 0: Tidak):";
            cin >> pilihanMenu;
            cout << endl;

            if (pilihanMenu == 1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        return false;
    }

    // Fungsi untuk mengurangi stok buku yang digunakan dalam proses transaksi
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

    // Fungsi untuk melakukan searching pada Linked List berdasarkan nama buku, dengan parameter tambahan boolean untuk penanda
    void searchBuku(LinkedList *list, string judulBuku, bool searchAllCategories = false)
    {
        current = list->head;

        if (current == nullptr)
        {
            cout << "!! Data buku kosong !!" << endl;
            return;
        }

        while (current != nullptr)
        {
            if (current->nama == judulBuku)
            {
                cout << setiosflags(ios::fixed);
                cout << "\n----------------=== KATEGORI " << current->kategori << " ===----------------" << endl;
                cout << "-----------------------------------------------------------" << endl;
                cout << "| " << setw(18) << left << current->nama
                     << " | Harga: Rp." << setw(10) << right << fixed << setprecision(2) << current->harga
                     << " | Stok: " << setw(5) << current->banyak << " |" << endl;
                cout << "-----------------------------------------------------------";
                cout << endl
                     << endl;

                found = true;

                if (!searchAllCategories)
                {
                    return;
                }
            }
            current = current->next;
        }

        // Penanda tadi digunakan disini untuk membedakan ketika fungsi di panggil hanya untuk search di dalam satu kategori atau semua kategori
        if (!found && !searchAllCategories)
        {
            cout << "!! Buku dengan judul \"" << judulBuku << "\" tidak ditemukan dalam kategori " << list->head->kategori << " !!" << endl;
        }
        else if (!found && searchAllCategories)
        {
            // Penanda tambahan untuk fungsi search dalam semua kategori
            notfoundInAllCategories = true;
        }
    }

    // Fungsi search dalam semua Kategori atau Linked List
    void searchBukuDiSemuaKategori(string judulBuku)
    {
        cout << "\n------------------=== PENCARIAN BUKU ===-----------------" << endl
             << endl;

        searchBuku(bukuPahlawan, judulBuku, true);
        searchBuku(bukuFiksi, judulBuku, true);
        searchBuku(bukuIlmiah, judulBuku, true);
        searchBuku(bukuSastra, judulBuku, true);
        searchBuku(bukuKesehatan, judulBuku, true);
        searchBuku(bukuAgamaIslam, judulBuku, true);
        searchBuku(bukuBahasa, judulBuku, true);
        searchBuku(bukuSeniDanOlahraga, judulBuku, true);
        searchBuku(bukuMajalah, judulBuku, true);
        searchBuku(bukuAkademik, judulBuku, true);

        // Akan memunculkan pesan jika di semua kategori tidak ditemukan dengan mengecek penanda tambahan
        if (!found && notfoundInAllCategories)
        {
            cout << "!! Buku dengan judul \"" << judulBuku << "\" tidak ditemukan dalam semua kategori !!" << endl;
            cout << endl;
        }
    }
};

//
// HashMap untuk Data User
// Fahreza
//

// Kelas untuk menyimpan Data User
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

// Kelas HashMap, untuk mengolah Data User
class HashMap
{
private:
    // Deklarasi vector User berdasarkan table indeks sebelumnya
    vector<User *> table[tableIndex];

public:
    // Variabel Global
    int pilih;

    // Destruktor untuk penghapusan HashMap ketika program selesai
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

    // Fungsi simple hash untuk menentukan key
    int simpleHash(string key)
    {
        int hashValue = 0;

        for (char c : key)
        {
            hashValue += c;
        }

        return hashValue % tableIndex;
    }

    // Fungsi login yang akan mengecek inputan User, apakah terdaftar dalam HashTable atau tidak menggunakan searching
    string Login(string username, string password)
    {
        int hashValue = simpleHash(username);

        for (User *user : table[hashValue])
        {
            if (user->username == username && user->password == password)
            {
                // Akan mengembalikan role user untuk pengecekan lebih lanjut
                return user->role;
            }
        }

        // Untuk penanda error
        return "error";
    }

    // Fungsi untuk registrasi, penambahan data user kedalam HashMap
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

        cout << "!! Berhasil Register !!" << endl;
    }

    // Fungsi untuk menghapus Data User berdasarkan nama user
    void removeByUsername(string username)
    {
        int hashValue = simpleHash(username);
        string usernameData;

        for (auto it = table[hashValue].begin(); it != table[hashValue].end(); it++)
        {
            if ((*it)->username == username)
            {
                usernameData = (*it)->username;
                table[hashValue].erase(it);
                return;
            }
        }

        cout << endl
             << "!! User " << usernameData << " berhasil di hapus !!" << endl;
    }

    // Fungsi untuk mencari Data User berdasarkan nama user menggunakan Sequential Search
    void searchByUsername(string username)
    {
        int hashValue = simpleHash(username);

        cout << "---------------------------------------------------------------" << endl;
        cout << "|   No   |              Username         |        Role        |" << endl;
        cout << "---------------------------------------------------------------" << endl;

        for (auto it = table[hashValue].begin(); it != table[hashValue].end(); it++)
        {
            if ((*it)->username == username)
            {
                cout << "---------------------------------------------------------------" << endl;
                cout << "| " << setw(6) << left << "1" << " | " << setw(28) << left << (*it)->username << " | " << setw(20) << left << (*it)->role << "|" << endl;
                cout << "---------------------------------------------------------------" << endl
                     << endl;
            }
        }
    }

    // Fungsi untuk menampilkan Data User
    void printUsers()
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
                    cout << "| " << setw(6) << left << i + 1 << " | " << setw(28) << left << user->username << " | " << setw(20) << left << user->role << "|" << endl;
                    cout << "---------------------------------------------------------------" << endl;
                }
            }
        }

        // Pemanggilan fungsi untuk mengolah user lebih lanjut
        prosesOlahUser();
    }

    // Fungsi untuk mengolah user termasuk Delete Data User
    void prosesOlahUser()
    {
        int pilih, choice;
        string username;

        do
        {
            cout << endl
                 << endl;
            cout << "--------------------------------------" << endl;
            cout << "| 1. | SELECT USERS                  |" << endl;
            cout << "--------------------------------------" << endl;
            cout << "| 2. | KEMBALI                       |" << endl;
            cout << "--------------------------------------" << endl;

            cout << "\nPilihan Anda [1-2]: ";
            cin >> pilih;
            cout << endl;

            switch (pilih)
            {
            case 1:
                cout << "Masukkan Username                                      : " << setprecision(3);
                cin >> username;

                searchByUsername(username);

                cout << "Apakah anda yakin ingin menghapus user ini? (1: Ya, 0: Tidak):";
                cin >> choice;

                if (choice == 1)
                {
                    removeByUsername(username);
                    return;
                }
                else
                {
                    continue;
                }

                break;
            case 2:
                return;
                break;

            default:
                cout << "Pilihan tidak valid, silakan coba lagi" << endl;
                break;
            }
        } while (pilih != 2);
    }
};

// Fungsi tambahan untuk menambahkan loading effect pada program 😄
void displayLoadingEffect()
{
    for (int i = 0; i < 20; ++i)
    {
        cout << "\rLoading " << string(i, '=') << ">" << flush;
        this_thread::sleep_for(chrono::milliseconds(300));
    }
    cout << "\rLoading ===================>" << endl
         << endl;
}

// Kelas Inheritance, untuk menggabungkan dua buah kelas dengan menggunakan konsep pewarisan
class Aplication : public RWBookStore, public HashMap
{
public:
    // Menu Admin
    void displayMenuAdmin()
    {
        displayLoadingEffect();
        do
        {
            cout << "-----== MENU UTAMA ==-----" << endl;
            cout << "--------------------------" << endl;
            cout << "| 1. | DAFTAR BUKU       |" << endl;
            cout << "--------------------------" << endl;
            cout << "| 2. | USERS             |" << endl;
            cout << "--------------------------" << endl;
            cout << "| 3. | LOGOUT            |" << endl;
            cout << "--------------------------" << endl;
            cout << "| 4. | EXIT              |" << endl;
            cout << "--------------------------" << endl;

            cout << "\nPilihan Anda [1-4]: ";
            cin >> pilih;
            cout << endl;

            switch (pilih)
            {
            case 1:
                int kategoriPilihan;

                do
                {
                    cout << "-------== DAFTAR BUKU ==------" << endl;
                    cout << "------------------------------" << endl;
                    cout << "|1.| BUKU PAHLAWAN            |" << endl;
                    cout << "------------------------------" << endl;
                    cout << "|2.| BUKU FIKSI               |" << endl;
                    cout << "------------------------------" << endl;
                    cout << "|3.| BUKU ILMIAH              |" << endl;
                    cout << "------------------------------" << endl;
                    cout << "|4.| BUKU SASTRA              |" << endl;
                    cout << "------------------------------" << endl;
                    cout << "|5.| BUKU KESEHATAN           |" << endl;
                    cout << "------------------------------" << endl;
                    cout << "|6.| BUKU AGAMA ISLAM         |" << endl;
                    cout << "------------------------------" << endl;
                    cout << "|7.| BUKU BAHASA              |" << endl;
                    cout << "------------------------------" << endl;
                    cout << "|8.| BUKU SENI DAN OLAHRAGA   |" << endl;
                    cout << "------------------------------" << endl;
                    cout << "|9.| MAJALAH                  |" << endl;
                    cout << "------------------------------" << endl;
                    cout << "|10.| BUKU AKADEMIK           |" << endl;
                    cout << "------------------------------" << endl;
                    cout << "|11.| KEMBALI                 |" << endl;
                    cout << "------------------------------" << endl;

                    cout << "Pilih kategori [1-11]: ";
                    cin >> kategoriPilihan;

                    switch (kategoriPilihan)
                    {
                    case 1:
                        RWBookStore::tampilanDaftarBuku(bukuPahlawan, "admin");
                        break;
                    case 2:
                        RWBookStore::tampilanDaftarBuku(bukuFiksi, "admin");
                        break;
                    case 3:
                        RWBookStore::tampilanDaftarBuku(bukuIlmiah, "admin");
                        break;
                    case 4:
                        RWBookStore::tampilanDaftarBuku(bukuSastra, "admin");
                        break;
                    case 5:
                        RWBookStore::tampilanDaftarBuku(bukuKesehatan, "admin");
                        break;
                    case 6:
                        RWBookStore::tampilanDaftarBuku(bukuAgamaIslam, "admin");
                        break;
                    case 7:
                        RWBookStore::tampilanDaftarBuku(bukuBahasa, "admin");
                        break;
                    case 8:
                        RWBookStore::tampilanDaftarBuku(bukuSeniDanOlahraga, "admin");
                        break;
                    case 9:
                        RWBookStore::tampilanDaftarBuku(bukuMajalah, "admin");
                        break;
                    case 10:
                        RWBookStore::tampilanDaftarBuku(bukuAkademik, "admin");
                        break;
                    case 11:
                        cout << endl;
                        break;
                    default:
                        cout << "Pilihan tidak valid, silakan coba lagi" << endl;
                        break;
                    }
                } while (kategoriPilihan != 11);

                break;

            case 2:
                printUsers();
                break;

            case 3:
                mainMenu();
                break;

            case 4:
                exit(0);
                break;

            default:
                cout << "Pilihan tidak valid, silakan coba lagi" << endl;
                break;
            }
        } while (pilih != 4);
    }

    // Menu User
    void displayMenuUser()
    {
        displayLoadingEffect();
        int pilih;
        string judulBuku;

        while (true)
        {
            // system("cls");

            cout << "-----== MENU UTAMA ==-----" << endl;
            cout << "--------------------------" << endl;
            cout << "| 1. | DAFTAR BUKU       |" << endl;
            cout << "--------------------------" << endl;
            cout << "| 2. | SEARCH BUKU       |" << endl;
            cout << "--------------------------" << endl;
            cout << "| 3. | LOGOUT            |" << endl;
            cout << "--------------------------" << endl;
            cout << "| 4. | EXIT              |" << endl;
            cout << "--------------------------" << endl;

            cout << "\nPilihan Anda [1-4]: ";
            cin >> pilih;
            cout << endl;

            switch (pilih)
            {
            case 1:
            {
                int kategoriPilihan;

                cout << endl;

                do
                {
                    cout << "-------== DAFTAR BUKU ==------" << endl;
                    cout << "------------------------------" << endl;
                    cout << "|1.| BUKU PAHLAWAN            |" << endl;
                    cout << "------------------------------" << endl;
                    cout << "|2.| BUKU FIKSI               |" << endl;
                    cout << "------------------------------" << endl;
                    cout << "|3.| BUKU ILMIAH              |" << endl;
                    cout << "------------------------------" << endl;
                    cout << "|4.| BUKU SASTRA              |" << endl;
                    cout << "------------------------------" << endl;
                    cout << "|5.| BUKU KESEHATAN           |" << endl;
                    cout << "------------------------------" << endl;
                    cout << "|6.| BUKU AGAMA ISLAM         |" << endl;
                    cout << "------------------------------" << endl;
                    cout << "|7.| BUKU BAHASA              |" << endl;
                    cout << "------------------------------" << endl;
                    cout << "|8.| BUKU SENI DAN OLAHRAGA   |" << endl;
                    cout << "------------------------------" << endl;
                    cout << "|9.| MAJALAH                  |" << endl;
                    cout << "------------------------------" << endl;
                    cout << "|10.| BUKU AKADEMIK           |" << endl;
                    cout << "------------------------------" << endl;
                    cout << "|11.| KEMBALI                 |" << endl;
                    cout << "------------------------------" << endl;

                    cout << "Pilih kategori [1-11]: ";
                    cin >> kategoriPilihan;

                    switch (kategoriPilihan)
                    {
                    case 1:
                        RWBookStore::tampilanDaftarBuku(bukuPahlawan);
                        break;
                    case 2:
                        RWBookStore::tampilanDaftarBuku(bukuFiksi);
                        break;
                    case 3:
                        RWBookStore::tampilanDaftarBuku(bukuIlmiah);
                        break;
                    case 4:
                        RWBookStore::tampilanDaftarBuku(bukuSastra);
                        break;
                    case 5:
                        RWBookStore::tampilanDaftarBuku(bukuKesehatan);
                        break;
                    case 6:
                        RWBookStore::tampilanDaftarBuku(bukuAgamaIslam);
                        break;
                    case 7:
                        RWBookStore::tampilanDaftarBuku(bukuBahasa);
                        break;
                    case 8:
                        RWBookStore::tampilanDaftarBuku(bukuSeniDanOlahraga);
                        break;
                    case 9:
                        RWBookStore::tampilanDaftarBuku(bukuMajalah);
                        break;
                    case 10:
                        RWBookStore::tampilanDaftarBuku(bukuAkademik);
                        break;
                    case 11:
                        break;
                    default:
                        cout << "Pilihan tidak valid, silakan coba lagi" << endl;
                        break;
                    }
                } while (kategoriPilihan != 11);

                break;
            }
            case 2:
            {
                cout << "Masukkan judul buku yang ingin dicari  : ";
                cin.ignore();
                getline(cin, judulBuku);

                RWBookStore::searchBukuDiSemuaKategori(judulBuku);
                break;
            }
            case 3:
                return;
                break;
            case 4:
                cout << "!! Terima kasih !!" << endl;
                exit(0);

                break;
            default:
                cout << "Pilihan tidak valid, silakan coba lagi" << endl;
                break;
            }
        }
    }

    // Menu Utama
    void mainMenu()
    {
        // system("cls");

        int input, pilih;
        string username, password, code, role;

        do
        {
            cout << "-----== RWF Book Store ==----" << endl;
            cout << "-----------------------------" << endl;
            cout << "|1. Login                   |" << endl;
            cout << "-----------------------------" << endl;
            cout << "|2. Register                |" << endl;
            cout << "-----------------------------" << endl;
            cout << "|3. Exit                    |" << endl;
            cout << "-----------------------------" << endl;

            cout << "Masukkan pilihan Anda: ";
            cin >> pilih;

            switch (pilih)
            {
            case 1: // buat login
                cout << endl
                     << "Masukkan Username  : ";
                cin >> username;
                cout << "Masukkan Password  : ";
                cin >> password;

                role = HashMap::Login(username, password);

                if (role == "admin")
                {
                    cout << "!! Login Berhasil !!" << endl;
                    cout << endl;

                    displayMenuAdmin();
                }
                else if (role == "user")
                {
                    cout << "!! Login Berhasil !!" << endl;
                    cout << endl;

                    displayMenuUser();
                }
                else
                {
                    cout << "!! Login Gagal !!" << endl;
                }

                break;
                break;
            case 2: // buat registernya
                cout << endl
                     << "Masukkan Username  : ";
                cin >> username;

                cout << "Masukkan Password  : ";
                cin >> password;

                cout << "Masukkan Kode Unik : ";
                cin >> code;

                HashMap::Register(username, password, code);

                cout << endl;
                break;
            case 3:
                cout << "!! Terima kasih !!" << endl;
                exit(0);
                break;
            default:
                cout << "Pilihan tidak valid, silakan coba lagi" << endl;
                break;
            }
        } while (pilih != 3);
    }
};

int main()
{
    Aplication app;
    app.mainMenu();

    return 0;
}