#include <iostream>
#include <vector>
#include <iomanip>

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
    int pilih;

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

        cout << "Berhasil Register" << endl;
    }

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

        cout << endl << "User " << usernameData << " berhasil di hapus." << endl;
    }

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
                    cout << "| " << setw(6) << left << i << " | " << setw(28) << left << user->username << " | " << setw(20) << left << user->role << "|" << endl;
                    cout << "---------------------------------------------------------------" << endl;
                }
            }
        }

        prosesOlahUser();
    }

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

            cout << "\n\nPilihan Anda [1-2]: ";
            cin >> pilih;

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
                cout << "Pilihan tidak valid!" << endl;
                break;
            }
        } while (pilih != 2);
    }

    void displayMenu()
    {
        do
        {
            cout << "-----== MENU UTAMA ==-----" << endl;
            cout << "--------------------------" << endl;
            cout << "| 1. | DAFTAR BUKU        |" << endl;
            cout << "--------------------------" << endl;
            cout << "| 2. | USERS              |" << endl;
            cout << "--------------------------" << endl;
            cout << "| 3. | LOGOUT             |" << endl;
            cout << "--------------------------" << endl;
            cout << "| 4. | EXIT               |" << endl;
            cout << "--------------------------" << endl;

            cout << "\n\nPilihan Anda [1-4]: ";
            cin >> pilih;

            switch (pilih)
            {
            case 1:
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
                        // tampilanDaftarBuku(bukuPahlawan);
                        break;
                    case 2:
                        // tampilanDaftarBuku(bukuFiksi);
                        break;
                    case 3:
                        // tampilanDaftarBuku(bukuIlmiah);
                        break;
                    case 4:
                        // tampilanDaftarBuku(bukuSastra);
                        break;
                    case 5:
                        // tampilanDaftarBuku(bukuKesehatan);
                        break;
                    case 6:
                        // tampilanDaftarBuku(bukuAgamaIslam);
                        break;
                    case 7:
                        // tampilanDaftarBuku(bukuBahasa);
                        break;
                    case 8:
                        // tampilanDaftarBuku(bukuSeniDanOlahraga);
                        break;
                    case 9:
                        // tampilanDaftarBuku(bukuMajalah);
                        break;
                    case 10:
                        // tampilanDaftarBuku(bukuAkademik);
                        break;
                    case 11:
                        break;
                    default:
                        cout << "Pilihan tidak valid!" << endl;
                        break;
                    }
                } while (kategoriPilihan != 11);

                break;

            case 2:
                printUsers();
                break;

            case 3:
                // logout();
                break;

            case 4:
                return;
                break;

            default:
                cout << "Pilihan tidak valid!" << endl;
                break;
            }
        } while (pilih != 4);
    }
};

int main()
{
    HashMap tabelUsers;

    int choice;
    string username, password, code;

    while (true)
    {
        cout << "BookStore" << endl;
        cout << "1. Login" << endl;
        cout << "2. Register" << endl;
        cout << "0. Exit" << endl;
        cout << "Pilih? ";
        cin >> choice;

        switch (choice)
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
                cout << endl;

                tabelUsers.displayMenu();
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