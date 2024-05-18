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