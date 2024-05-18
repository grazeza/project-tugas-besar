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

                tabelUsers.print();
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