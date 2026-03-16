#include <iostream>
#include <cstdio>
using namespace std;

struct MenuRoti{
    int IDroti;
    int stok;
    int HargaRoti;
    char namaroti[50];
};

MenuRoti Roti[100];
int jumlahRoti;

//VARIABEL TRANSAKSI
int idBeli=0;
int jumlahBeli;
int totalBayar;

//UNTUK MEMBACA FILE ROTI
void bacaFile(){

    FILE *arch = fopen("roti.txt","r");

    if(arch == NULL){
        return;
    }

    jumlahRoti = 0;

    while(fscanf(arch,"%d %s %d %d",
        &Roti[jumlahRoti].IDroti,
        Roti[jumlahRoti].namaroti,
        &Roti[jumlahRoti].HargaRoti,
        &Roti[jumlahRoti].stok) != EOF){

        jumlahRoti++;
    }

    fclose(arch);
}
// SEARCH FUNCTION
int sequentialSearch(string cari){

    for(int i=0;i<jumlahRoti;i++){

        if(cari == Roti[i].namaroti){
            return i;
        }

    }

    return -1;
}
int binarySearch(string cari){

    int kiri = 0;
    int kanan = jumlahRoti - 1;

    while(kiri <= kanan){

        int tengah = (kiri + kanan) / 2;

        if(cari == Roti[tengah].namaroti){
            return tengah;
        }

        else if(cari < Roti[tengah].namaroti){
            kanan = tengah - 1;
        }

        else{
            kiri = tengah + 1;
        }

    }

    return -1;
}

//MENU UTAMA
int menuUtama(){
	int pilih; 
    cout << "================================" << endl;
    cout << "   WELCOME TO WARM LOAF BAKERY" << endl;
    cout << "================================" << endl;
    cout << "1. Masuk sebagai karyawan" << endl;
    cout << "2. Masuk sebagai pembeli" << endl;
    cout << "   Masukkan pilihan: "; cin >> pilih;
    cout << endl;
    return pilih;
    
}

void loginKaryawan(){
//Hanya karyawan yang bisa mengakses
    int pass;
    string usn;
	bool loginsukses = false;
	
	while (loginsukses == false){
    cout << "================================" << endl;
    cout << "       Syallom Karyawan!        " << endl;
    cout << "Silahkan login untuk melanjutkan" << endl;
    cout << "================================" << endl;

    cout << "1. Masukkan Username: ";
    cin >> usn;

    cout << "2. Masukkan Password: ";
    cin >> pass;

    if (usn == "admin" && pass == 505){

        cout << "Login berhasil!" << endl;
        cout << "Hiy bess (my etmin gehh) " <<endl;
        loginsukses = true;
}
    
    else{

        cout << "anda bukan etmin yh" << endl;
}
}
}
// SORT
void ascending(){

    for(int i=0;i<jumlahRoti-1;i++){

        for(int j=0;j<jumlahRoti-i-1;j++){

            if(Roti[j].HargaRoti > Roti[j+1].HargaRoti){

                MenuRoti temp = Roti[j];
                Roti[j] = Roti[j+1];
                Roti[j+1] = temp;

            }

        }

    }

    cout << endl;
    cout << "Data roti.." << endl;

}
void descending(int low, int high){

    int i = low;
    int j = high;
    int pivot = Roti[(low+high)/2].HargaRoti;

    while(i<=j){

        while(Roti[i].HargaRoti > pivot) i++;
        while(Roti[j].HargaRoti < pivot) j--;

        if(i<=j){

            MenuRoti temp = Roti[i];
            Roti[i] = Roti[j];
            Roti[j] = temp;

            i++;
            j--;

        }

    }

    if(low < j) descending(low,j);
    if(i < high) descending(i,high);

}	
// IZIN TAMPIL
void tampilRoti() {
    for(int i=0;i<jumlahRoti;i++){

        cout << "ID roti : " << Roti[i].IDroti << endl;
        cout << "Nama Roti  : " << Roti[i].namaroti << endl;
        cout << "Harga Roti : " << Roti[i].HargaRoti << endl;
        cout << "Stok Roti  : " << Roti[i].stok << endl;
        cout << endl;
      }
    }
// EDIT ROTI    
void editRoti(){

    int id;

    tampilRoti();

    cout << "Masukkan ID roti yang ingin diedit: ";
    cin >> id;

    cout << "Nama Roti  : ";
    cin >> Roti[id-1].namaroti;

    cout << "Harga Roti : ";
    cin >> Roti[id-1].HargaRoti;

    cout << "Stok Roti  : ";
    cin >> Roti[id-1].stok;

    cout << "Data berhasil diedit" << endl;

}
void cariRoti(){

    string cari;
    int metode;

    cout << "Masukkan nama roti yang dicari: ";
    cin >> cari;

    cout << "1. Sequential Search" << endl;
    cout << "2. Binary Search" << endl;
    cout << "Pilih metode: ";
    cin >> metode;

    int index=-1;

    if(metode==1){

        index=sequentialSearch(cari);

    }
    else{

        ascending();
        index=binarySearch(cari);

    }

    if(index!=-1){

        cout << "ID roti : " << Roti[index].IDroti << endl;
        cout << "Nama Roti  : " << Roti[index].namaroti << endl;
        cout << "Harga Roti : " << Roti[index].HargaRoti << endl;
        cout << "Stok Roti  : " << Roti[index].stok << endl;

    }
    else{

        cout << "Roti tidak ditemukan" << endl;

    }

}
//BELI roti
void beliRoti(){
	int metode;
	
	cout << "Pilih metode lihat : " <<endl;
	cout << "1. Ascending" <<endl;
	cout << "2. Descending" <<endl;
	cout << "Pilih Metode : "; cin >> metode;
		if(metode == 1) ascending();
        else 
        descending(0, jumlahRoti-1);
	
		tampilRoti();
           
		cout <<endl;
		

    cout << "Masukkan ID roti yang ingin dibeli: ";
    cin >> idBeli;

    if(idBeli <= jumlahRoti && idBeli > 0){

        cout << "Masukkan jumlah roti yang dibeli: ";
        cin >> jumlahBeli;

        if(jumlahBeli <= Roti[idBeli-1].stok){

            totalBayar = jumlahBeli * Roti[idBeli-1].HargaRoti;

            Roti[idBeli-1].stok -= jumlahBeli;

            cout << "Roti berhasil dibeli!" << endl;

        }
        else{
            cout << "Stok tidak cukup!" << endl;
        }

    }
    else{
        cout << "ID roti tidak ditemukan!" << endl;
    }

}
//INVOICE
void invoice(){
	if(idBeli <= 0 || idBeli > jumlahRoti){
        cout << "Belum ada transaksi pembelian!" << endl;
        return;
	}
    cout << endl;
    cout << "============================" << endl;
    cout << "=      STRUK PEMBELIAN     =       " << endl;
    cout << "=      WARM LOAF BAKERY    =" << endl;
    cout << "============================" << endl;

    cout << "ID Roti   : " << Roti[idBeli-1].IDroti << endl;
    cout << "Nama Roti : " << Roti[idBeli-1].namaroti << endl;
    cout << "Harga     : " << Roti[idBeli-1].HargaRoti << endl;
    cout << "Jumlah    : " << jumlahBeli << endl;

    cout << "-------------------------" << endl;
    cout << "TOTAL BAYAR : " << totalBayar << endl;
    cout << "=========================" << endl;
    cout << "Terima kasih telah membeli!" << endl;
    cout << endl;

}
void MenuKaryawan(){
    int pilih;
    char ulang='y';
    do{
	cout << endl;
	cout << endl;
    cout << "=================" << endl;
    cout << " 'SSUP MY TWIN" << endl;
    cout << "=================" << endl;
    cout << "1. Tambah menu roti" << endl;
    cout << "2. Lihat menu roti" << endl;
    cout << "3. Edit menu roti" << endl;
    cout << "4. Logout" << endl;
    cout << "Masukkan pilihan: ";
    cin >> pilih;

    if (pilih == 1){
        cout << "Masukkan jumlah data roti: ";
        cin >> jumlahRoti;
        FILE *arch =fopen("roti.txt", "w");
	

        for(int i = 0; i < jumlahRoti; i++){
            cout << "ID roti : " << i+1 << endl;
            Roti[i].IDroti = i+1;

            cout << "Nama Roti  : ";
            cin >> Roti[i].namaroti;

            cout << "Harga Roti : ";
            cin >> Roti[i].HargaRoti;

            cout << "Stok Roti  : ";
            cin >> Roti[i].stok;
            
            fprintf(arch,"%d %s %d %d\n",
            Roti[i].IDroti,
            Roti[i].namaroti,
            Roti[i].HargaRoti,
            Roti[i].stok);
        }
        fclose (arch);
        cout << endl;
        cout << "Data telah disimpan sebagai roti.txt " << endl;
        cout << "Kembali ke menu utama? yay or nay (y/n) : " ; cin >> ulang;
        cout << endl;
    }
      
    if (pilih == 2){
		int metode;
		cout << endl;
		cout << "Jumlah data roti : " ; cin >> jumlahRoti;
		cout << endl;
		cout << "Pilih metode lihat : " <<endl;
		cout << "1. Ascending" <<endl;
		cout << "2. Descending" <<endl;
		cout << "Pilih Metode : "; cin >> metode;
		if(metode == 1) ascending();
        else 
        descending(0, jumlahRoti-1);
	
		tampilRoti();
           
		cout <<endl;
		}
		else if (pilih == 3){

    int id;

    cout << endl;
    cout << "===== DATA ROTI LAMA =====" << endl;

    tampilRoti();

    cout << "Masukkan ID roti yang ingin diedit : ";
    cin >> id;

    if(id <= jumlahRoti && id > 0){

        cout << endl;
        cout << "===== DATA LAMA =====" << endl;
        cout << "ID roti : " << Roti[id-1].IDroti << endl;
        cout << "Nama Roti  : " << Roti[id-1].namaroti << endl;
        cout << "Harga Roti : " << Roti[id-1].HargaRoti << endl;
        cout << "Stok Roti  : " << Roti[id-1].stok << endl;

        cout << endl;
        cout << "===== MASUKKAN DATA BARU =====" << endl;

        cout << "Nama Roti  : ";
        cin >> Roti[id-1].namaroti;

        cout << "Harga Roti : ";
        cin >> Roti[id-1].HargaRoti;

        cout << "Stok Roti  : ";
        cin >> Roti[id-1].stok;

        cout << endl;
        cout << "Data roti berhasil diupdate!" << endl;

    }

    else{
        cout << "ID roti tidak ditemukan!" << endl;
    }

}
		
		else if(pilih == 4){
			cout << "Thank you, Sehat sehat ya" << endl;
		break;
	}
	} while(ulang == 'y' || ulang =='Y');

}

void MenuPembeli(){
	bacaFile();
	int menu;
	char ulang='y';
	do {
	cout << "============================"<<endl;
	cout << "WELCOME BUYER, HV A GUD ONE!" <<endl;
	cout << "============================"<<endl;
	cout << "1. Cari roti "<<endl;
	cout << "2. Beli roti "<<endl;
	cout << "3. Invoice roti "<<endl;
	cout << "4. Logout"<<endl;
	cout << "Masukkan Pilihan : "; cin >> menu;
	cout <<endl;
	if(menu == 1){
		cariRoti();
		}
	else if(menu == 2){
        beliRoti();
}

	else if(menu == 3){
    invoice();
} else if(menu == 4){
    break;
}
	}while(ulang == 'y' || ulang =='Y');

	}

int main(){
	bacaFile();
    int pilih;
    do{
	pilih = menuUtama();
    if(pilih == 1){
    loginKaryawan();
    MenuKaryawan(); //MenuKaryawan() memanggil fungsi
   }
    else if(pilih == 2){
    MenuPembeli();
}
}while(pilih != 0);
}
  
