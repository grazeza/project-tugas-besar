#include <iostream> // input-output == cout dan cin
#include <iomanip>  // manipulasi input output = setprecision
#include <string>   // manipulasi dan menyimpan data teks
#include <thread>   // diguanakan untuk efek visual
#include <chrono>   //library untuk waktu efek visual milidetik
#include <map>      // digunakan untuk informasi buku dan kategori buku

using namespace std;

// Struktur data untuk menyimpan informasi buku
struct buku
{
    string nama; // nama buku
    double harga;
    int banyak;
    string item; // kategori
};

void tampilanDaftarBuku(const buku penyimpananBuku[], int Maksimalbuku, const string &kategori)
{
    cout << "\n---------===DAFTAR BUKU " << kategori << "===---------:" << endl;
    cout << endl;
    for (int i = 0; i < Maksimalbuku; i++)
    {
        if (penyimpananBuku[i].item == kategori)
        {
            cout << setiosflags(ios::fixed);
            cout << "--------------------------------------------" << endl;
            cout << "|" << penyimpananBuku[i].nama << "| Harga: Rp." << setprecision(3) << penyimpananBuku[i].harga << "| Stok: " << penyimpananBuku[i].banyak << " |" << endl;
            cout << "--------------------------------------------";
            cout << endl
                 << endl;
        }
    }
}

void kurangistokbuku(buku penyimpananBuku[], int Maksimalbuku, const string &namabaramg, int jumlah)
{ //& refresnsi kategori terhadap string
    for (int i = 0; i < Maksimalbuku; i++)
    {
        if (penyimpananBuku[i].nama == namabaramg)
        {
            penyimpananBuku[i].banyak -= jumlah; // dikurangi stok buku
            break;
        }
    }
}

int main()
{

    const int Maksimalbuku = 60; // const digunakan untuk jaminan agar nilai tidak ada perubahan
    buku penyimpananBuku[Maksimalbuku];
    // BUKU PAHLAWAN
    penyimpananBuku[0] = {"Soekarno", 75, 180, "Buku Pahlawan"}; // memodifikasi struktur membagi setiap kategori menjadi kelas agar bisa menyimpan data yang berbeda
    penyimpananBuku[1] = {"Moh Hatta", 65, 200, "Buku Pahlawan"};
    penyimpananBuku[2] = {"Buya Hamka", 100, 400, "Buku Pahlawan"};
    penyimpananBuku[3] = {"Kartini", 75, 180, "Buku Pahlawan"};
    penyimpananBuku[4] = {"Kalinyamat", 65, 200, "Buku Pahlawan"};
    penyimpananBuku[5] = {"Soedirman", 100, 400, "Buku Pahlawan"};
    // BUKU FIKSI
    penyimpananBuku[6] = {"yaya", 75, 180, "Buku Fiksi"};
    penyimpananBuku[7] = {"boneka", 65, 200, "Buku Fiksi"};
    penyimpananBuku[8] = {"kudanil", 100, 400, "Buku Fiksi"};
    penyimpananBuku[9] = {"Katarsis", 75, 180, "Buku Fiksi"};
    penyimpananBuku[10] = {"Orang Biasa", 65, 200, "Buku Fiksi"};
    penyimpananBuku[11] = {"Man Boy", 100, 400, "Buku Fiksi"};
    // BUKU ILMIAH
    penyimpananBuku[12] = {"Fisika", 75, 180, "Buku Ilmiah"};
    penyimpananBuku[13] = {"Kimia", 65, 200, "Buku Ilmiah"};
    penyimpananBuku[14] = {"Matematika", 100, 400, "Buku Ilmiah"};
    penyimpananBuku[15] = {"Geologi", 75, 180, "Buku Ilmiah"};
    penyimpananBuku[16] = {"Biologi", 65, 200, "Buku Ilmiah"};
    penyimpananBuku[17] = {"Astronomi", 100, 400, "Buku Ilmiah"};
    // BUKU SASTRA
    penyimpananBuku[18] = {"Pantun", 75, 180, "Buku Sastra"};
    penyimpananBuku[19] = {"Puisi", 65, 200, "Buku Sastra"};
    penyimpananBuku[20] = {"Hikayat", 100, 400, "Buku Sastra"};
    penyimpananBuku[21] = {"Bumi Manusia", 75, 180, "Buku Sastra"};
    penyimpananBuku[21] = {"Orang Bloomington", 65, 200, "Buku Sastra"};
    penyimpananBuku[22] = {"Ronggeng Dukuh", 100, 400, "Buku Sastra"};
    // BUKU KESEHATAN
    penyimpananBuku[23] = {"Cara Bernapas", 75, 180, "Buku Kesehatan"};
    penyimpananBuku[24] = {"Tentang Tubuhmu", 65, 200, "Buku Kesehatan"};
    penyimpananBuku[25] = {"BREATH", 100, 400, "Buku Kesehatan"};
    penyimpananBuku[26] = {"Andai Sel Bicara", 75, 180, "Buku Kesehatan"};
    penyimpananBuku[27] = {"Mengelola Sayur", 65, 200, "Buku Kesehatan"};
    penyimpananBuku[28] = {"Pentingya Makan Buah", 100, 400, "Buku Kesehatan"};
    // BUKU AGAMA ISLAM
    penyimpananBuku[29] = {"Hadist", 75, 180, "Buku Agama Islam"};
    penyimpananBuku[30] = {"Fikih", 65, 200, "Buku Agama Islam"};
    penyimpananBuku[31] = {"Tafsir", 100, 400, "Buku Agama Islam"};
    penyimpananBuku[32] = {"NALAR TASAWUF", 75, 180, "Buku Agama Islam"};
    penyimpananBuku[33] = {"Maaf Tuhan", 65, 200, "Buku Agama Islam"};
    penyimpananBuku[34] = {"Islam Santai", 100, 400, "Buku Agama Islam"};
    // BUKU BAHASA
    penyimpananBuku[35] = {"Bahasa Korea", 75, 180, "Buku Bahasa"};
    penyimpananBuku[36] = {"Bahasa Inggris", 65, 200, "Buku Bahasa"};
    penyimpananBuku[37] = {"Bahasa Indonesia", 100, 400, "Buku Bahasa"};
    penyimpananBuku[38] = {"Bahasa Mandarin", 75, 180, "Buku Bahasa"};
    penyimpananBuku[39] = {"Bahasa Russia", 65, 200, "Buku Bahasa"};
    penyimpananBuku[40] = {"Bahasa Jepang", 100, 400, "Buku Bahasa"};
    // BUKU SENI DAN OLAHRAGA
    penyimpananBuku[41] = {"Seni Tinju", 75, 180, "Buku Seni dan Olahraga"};
    penyimpananBuku[42] = {"Tubuh Seni Olahraga", 65, 200, "Buku Seni dan Olahraga"};
    penyimpananBuku[43] = {"Jago Beladiri", 100, 400, "Buku Seni dan Olahraga"};
    penyimpananBuku[44] = {"PRANA", 75, 180, "Buku Seni dan Olahraga"};
    penyimpananBuku[45] = {"TAEKWONDO", 65, 200, "Buku Seni dan Olahraga"};
    penyimpananBuku[46] = {"Seni Pencak Silat", 100, 400, "Buku Seni dan Olahraga"};
    // BUKU MAJAlAH
    penyimpananBuku[47] = {"My Trip", 75, 180, "Buku Majalah"};
    penyimpananBuku[48] = {"Bobo", 65, 200, "Buku Majalah"};
    penyimpananBuku[49] = {"Prenting", 100, 400, "Buku Majalah"};
    penyimpananBuku[50] = {"Bilal", 75, 180, "Buku Majalah"};
    penyimpananBuku[51] = {"Gatra", 65, 200, "Buku Majalah"};
    penyimpananBuku[52] = {"Kreatif", 100, 400, "Buku Majalah"};
    // BUKU AKADEMIK
    penyimpananBuku[53] = {"TOEFL", 75, 180, "Buku Akademik"};
    penyimpananBuku[54] = {"CPNS", 65, 200, "Buku Akademik"};
    penyimpananBuku[55] = {"Pejuang Kedinasan", 100, 400, "Buku Akademik"};
    penyimpananBuku[56] = {"TNI POLRI", 75, 180, "Buku Akademik"};
    penyimpananBuku[56] = {"UTBK", 65, 200, "Buku Akademik"};
    penyimpananBuku[57] = {"SKD", 100, 400, "Buku Akademik"};

    int masuk;
    int pilih;
    int masuk2;
    string orang;
    string nim;

    // Tampilan menu Login
    cout << "-------------------------------------------- SELAMAT DATANG DI R&W Book Emporium ---------------------------------------" << endl;
    cout << "ISI BIODATA BERIKUT : " << endl
         << endl;
    cout << "NAMA : ";
    getline(cin, orang); // digunakan mengambil seluruh baris sebagai input
    cout << "NIM  : ";
    cin >> nim;
    cout << endl;
    cout << "SELAMAT DATANG " << orang << " NIM " << nim << " DI R&W Book Emporium " << endl
         << endl;
    cout << "Ketik 10 Untuk Masuk : ";
    cin >> masuk;
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

    do
    { // melakukan transaki lagi setelah while masuk2 ==1
        if (masuk == 10)
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
            cout << "|8.| BUKU S & O       |" << endl;
            cout << "-----------------------" << endl;
            cout << "|9.| BUKU MAJALAH     |" << endl;
            cout << "-----------------------" << endl;
            cout << "|10.| BUKU AKADEMIK   |" << endl;
            cout << "-----------------------";

            cout << "\n\nPilihan Anda [1-10] Pilih 11 untuk keluar..: ";
            cin >> pilih;
        }
        else
        {
            cout << "Masukkan 10 untuk masuk ke daftar item." << endl;
            return 0;
        }

        switch (pilih)
        {
        case 1:
            tampilanDaftarBuku(penyimpananBuku, Maksimalbuku, "Buku Pahlawan");
            break;
        case 2:
            tampilanDaftarBuku(penyimpananBuku, Maksimalbuku, "Buku Fiksi");
            break;
        case 3:
            tampilanDaftarBuku(penyimpananBuku, Maksimalbuku, "Buku Ilmiah");
            break;
        case 4:
            tampilanDaftarBuku(penyimpananBuku, Maksimalbuku, "Buku Sastra");
            break;
        case 5:
            tampilanDaftarBuku(penyimpananBuku, Maksimalbuku, "Buku Kesehatan");
            break;
        case 6:
            tampilanDaftarBuku(penyimpananBuku, Maksimalbuku, "Buku Agama Islam");
            break;
        case 7:
            tampilanDaftarBuku(penyimpananBuku, Maksimalbuku, "Buku Bahasa");
            break;
        case 8:
            tampilanDaftarBuku(penyimpananBuku, Maksimalbuku, "Buku Seni dan Olahraga");
            break;
        case 9:
            tampilanDaftarBuku(penyimpananBuku, Maksimalbuku, "Buku Majalah");
            break;
        case 10:
            tampilanDaftarBuku(penyimpananBuku, Maksimalbuku, "Buku Akademik");
            break;
        case 11:
            cout << endl
                 << endl;
            cout << "Tekan Enter Untuk Keluar..";
            cout << endl
                 << endl;
            return 0;
        default:
            cout << "\nAnda Salah Input.....";
            return 0;
        }

        double total = 0.0; // nilai awal belanja
        double diskon;
        string namabarang;

        while (true)
        { // loop nama buku dan jumlah buku
            int banyak;
            cout << "Masukkan Nama Buku (ketik 'selesai' untuk menyelesaikan pembelian) : ";
            cin.ignore();
            getline(cin, namabarang);

            if (namabarang == "selesai")
            {
                break;
            }

            buku item;
            bool itemDitemukan = false; // tipe data true dan faalse untuk pencarian buku
            for (auto &buku : penyimpananBuku)
            { // refrensi otomatis dari elemen array ditentukan oleh kompilator
                if (buku.nama == namabarang)
                {
                    item = buku;
                    itemDitemukan = true;
                    break;
                }
            }

            if (!itemDitemukan)
            {
                cout << "Barang tidak ditemukan." << endl;
                continue;
            }

            cout << "Masukkan jumlah yang ingin dibeli                                  : ";
            cin >> banyak;

            if (banyak > item.banyak)
            {
                cout << "Stok tidak mencukupi." << endl;
                continue;
            }

            item.banyak -= banyak;
            double subtotal = item.harga * banyak;
            total += subtotal;
            cout << "Harga Awal untuk Buku " << item.nama << "                                     : Rp." << setprecision(3) << subtotal << endl;

            kurangistokbuku(penyimpananBuku, Maksimalbuku, namabarang, banyak);

            if (item.banyak >= 50.000)
            {
                diskon = 0.24 * subtotal;
                subtotal = item.harga * banyak - diskon;
                cout << "Promo New Year Mendapatkan diskon 24%                              : Rp." << setprecision(3) << diskon << endl;
                cout << "Subtotal untuk Buku " << item.nama << "                                       : Rp." << setprecision(3) << subtotal << endl
                     << endl;
                total -= diskon;
            }
            else
            {
                cout << "Subtotal untuk Buku " << item.nama << "        Rp." << setprecision(3) << subtotal << endl
                     << endl;
            }
        }

        // Hitung kembalian
        double uang;
        cout << endl;
        cout << "Total Belanja : Rp." << setprecision(3) << total << endl; // untuk megatur jumlah desimal pada output
        cout << "Jumlah Uang   : Rp.";
        cin >> uang;
        double pembayaran = uang - total;
        cout << "Kembalian     : Rp." << setprecision(3) << pembayaran << endl
             << endl;

        cout << "TERIMA KASIH TELAH BERBELANJA DI R&W Book Emporium" << endl
             << endl;

        cout << "Apakah Anda ingin melakukan transaksi lain? (1: Ya, 0: Tidak):";
        cin >> masuk2;
        cout << endl;

        if (masuk2 == 1)
        {
            cout << "Ketik 10 Untuk Masuk Ke Daftar Buku : ";
            cin >> masuk;
            cout << endl;
        }
    } while (masuk2 == 1);

    return 0;
}
