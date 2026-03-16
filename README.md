Program yang harus dibuat adalah sistem manajemen toko roti berbasis C++ yang memiliki dua jenis pengguna, yaitu karyawan dan pembeli, serta menggunakan file sebagai penyimpanan data roti.
1. Menu Utama
Program harus menampilkan menu utama yang memungkinkan pengguna memilih:
Masuk sebagai karyawan
Masuk sebagai pembeli
2. Login Karyawan
Karyawan harus melakukan login terlebih dahulu dengan username dan password sebelum dapat mengakses fitur pengelolaan data roti.
3. Menu Karyawan
Karyawan dapat mengelola data roti melalui beberapa fitur berikut:
Tambah menu roti
Lihat daftar roti
Edit menu roti
Logout
4. Tambah Menu Roti
Karyawan dapat menambahkan data roti yang berisi:
Nama roti
Harga roti
Stok roti
Data disimpan menggunakan struct dan kemudian ditulis ke dalam file roti.txt.
5. Lihat Menu Roti
Sistem harus dapat menampilkan daftar roti dengan dua metode pengurutan:
Ascending (harga termurah → termahal) menggunakan Bubble Sort
Descending (harga termahal → termurah) menggunakan Quick Sort
6. Edit Menu Roti
Karyawan dapat mengubah data roti dengan cara:
Memasukkan ID roti
Sistem menampilkan data lama
Karyawan memasukkan data baru
7. Menu Pembeli
Menu ini digunakan oleh pelanggan untuk melakukan transaksi pembelian roti.
Fitur yang tersedia:
Cari roti
Beli roti
Invoice roti
Logout
8. Cari Roti
Pelanggan dapat mencari roti berdasarkan nama roti dengan dua metode pencarian:
Sequential Search
Binary Search
9. Beli Roti
Pembeli dapat membeli roti dengan langkah berikut:
Sistem menampilkan daftar roti
Pengguna memilih metode pengurutan (Ascending / Descending)
Pembeli memilih ID roti
Memasukkan jumlah roti
Sistem menghitung total pembayaran dan mengurangi stok
10. Invoice Roti
Sistem menampilkan struk pembelian yang berisi:
Nama roti
Harga roti
Jumlah pembelian
Total pembayaran
11. Logout Pembeli
Fitur ini digunakan untuk keluar dari menu pembeli dan kembali ke menu utama.
Ketentuan Program
Program wajib menggunakan:
Bahasa C++
Pointer
Sorting
Bubble Sort
Quick Sort
Searching
Sequential Search
Binary Search
File Handling
fopen
fclose
fscanf
fprintf
Data roti harus disimpan dalam file roti.txt
