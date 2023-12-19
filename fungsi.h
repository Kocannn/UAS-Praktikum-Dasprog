#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
struct obat{
	string namaObat;
	double harga;
};
struct listObat{
	vector<obat> tablet;
	vector<obat> sirup;
	vector<obat> kapsul;
};
listObat listobat1 = {
    {
    	{"Paracetamol", 5},
     	{"Ibuprofen", 8},
     	{"Metformin", 10},
     	{"Simvastatin", 12}
     },
    {
    	{"Cetirizine", 6},
     	{"Antitusif", 7}
     },

    {
    	{"Amoxicillin", 7},
     	{"Omeprazole", 15},
     	{"Probiotik", 20}
     }
};
void listObatTablet(){
	system("clear");
	cout << "\n\t\t\tTablet\n" << endl;
	for (auto& tablet : listobat1.tablet){
		cout << "nama : " <<tablet.namaObat << "\t\t Harga : $" << tablet.harga <<  endl;
	};
};
void listObatSirup(){
	system("clear");
	cout << "\n\t\t\tSirup\n" << endl;
	for (auto& sirup : listobat1.sirup){
		cout << "nama : " << sirup.namaObat << "\t\t Harga : $" << sirup.harga << endl;
	}
};
void listObatKapsul(){
	system("clear");
	cout << "\n\t\t\tKapsul\n" << endl;
	for (auto& kapsul : listobat1.kapsul){
	cout << "nama : " << kapsul.namaObat << "\t\t Harga : $" << kapsul.harga << endl;
	}
};
struct dataPasien
{
	string nama;
	string nomorTelfon;
	string jenis_kelamin;
	int umur;
	string noRek;
	string pin;
	bool bpjs = false;
	string nomorBPJS;
	int tingkatBPJS;
};
vector<dataPasien> pendaftaran(vector<dataPasien>& dataPasien1){
	dataPasien temp;
	char input;
	system("clear");
	cout << "Mendaftar" << endl;
	cout << "masukan nama : ";
	getline(cin, temp.nama);
	cout << "masukan jenis kelamin : ";
	getline(cin, temp.jenis_kelamin);
	cout << "masukan nomor telfon : ";
	cin >> temp.nomorTelfon;
	cout << "masukan umur : ";
	cin >> temp.umur;
	cout << "apakah anda mempunyai nomor rekening? (y/n) : ";
	cin >> input;
	tolower(input);
	if(input == 'y'){
		cout << "masukan nomor rekening : ";
		cin >> temp.noRek;
		cout << "masukan pin : ";
		cin >> temp.pin;
	}
	cout << "apakah anda memiliki bpjs ? (y/n) : ";
	cin >> input;
	tolower(input);
	if(input == 'y'){
		temp.bpjs = true;
		cout << "masukan nomor kartu bpjs anda : ";
		cin >> temp.nomorBPJS;
		cout << "masukan tingkat bpjs anda : ";
		cin >> temp.tingkatBPJS;
	};
	dataPasien1.push_back(temp); 
	return dataPasien1;
}
void informasiPasien(vector<dataPasien>& dataPasien1){
	system("clear");
	cout << "Informasi Pasien " << endl ;
	for (int i = 0; i < dataPasien1.size(); i++){
		cout << "Nama : " << dataPasien1[i].nama << endl;
		cout << "Umur : " << dataPasien1[i].umur << " tahun " << endl;
		cout << "Jeis Kelamin : " << dataPasien1[i].jenis_kelamin << endl;
		cout << "Nomor Telfon : " << dataPasien1[i].nomorTelfon << endl;
		if (!dataPasien1[i].noRek.empty()){
			cout << "Nomor Rekening " << dataPasien1[i].noRek << endl;
		}
		if (dataPasien1[i].bpjs == 1){
			cout << "Memiliki BPJS" << endl;
			cout << "Nomor BPJS : " << dataPasien1[i].nomorBPJS << endl;
		}
		else if (dataPasien1[i].bpjs == 0){
			cout << "Tidak memiliki BPJS" << endl;
		}
	}
	cin.get();
	cin.get();
};
int menu(){
	int userInput;
	cout << "Selamat datang di Hospital Care" << endl;
	cout << "1. Rawat Inap " << endl;
	cout << "2. Tindakan medis" << endl;
	cout << "3. Pembelian obat" << endl;
	cout << "4. Informasi Pasien" << endl;
	cout << "5. Exit" << endl;
	cout << ">> ";
	cin >> userInput;
	return userInput;
}
int listRuangan(){
	int userInput;
	system("clear");
	cout << "Pilih tipe ruangan yang anda inginkan " << endl;
	cout << "1. Tipe VVIP ($425/hari)" << endl;
	cout << "2. Tipe VIP ($240/hari)" << endl;
	cout << "3. Tipe Kelas 1 ($140/hari)" << endl;
	cout << "4. Tipe Kelas 2 ($80/hari)" << endl;
	cout << "5. Tipe Kelas 3 ($55/hari)" << endl;
	cout << ">> ";
	cin >> userInput;
	return userInput;
}
void tampilkanHarga(bool butuhDiskon ,double& harga, double& diskon, vector<dataPasien>& dataPasien1){
	if (butuhDiskon == true){
		if (dataPasien1[0].bpjs == true){
			harga = harga - (diskon * harga);
		}
	}
	cout << "harga yang harus dibayar : $" << harga << endl;
}

double diskonBpjsRuangRawatInap(vector<dataPasien>& dataPasien1){
	double diskon;
	if (dataPasien1[0].tingkatBPJS == 1){
		diskon = 0.5;
	}
	else if(dataPasien1[0].tingkatBPJS == 2){
		diskon = 0.4;
	}
	else if(dataPasien1[0].tingkatBPJS == 3){
		diskon = 0.2;
	}
	return diskon;
};
double diskonBpjsTindakanMedis(int input, vector<dataPasien>& dataPasien1){
	double diskon;
	if(dataPasien1[0].tingkatBPJS == 1){
		switch(input){
		case 1:
			diskon = 0.3; break;
		case 2:
			diskon = 0.5; break;
		case 3:
			diskon = 0.2; break;
		}
	}
	else if(dataPasien1[0].tingkatBPJS == 2){
		switch(input){
		case 1:
			diskon = 0.2; break;
		case 2:
			diskon = 0.3; break;
		case 3:
			diskon = 0.2; break;
		}
	}
	else if(dataPasien1[0].tingkatBPJS == 3){
		switch(input){
		case 1:
			diskon = 0.1; break;
		case 2:
			diskon = 0.2; break;
		case 3:
			diskon = 0.2; break;
		}
	}
	return diskon;
}
void kalkulasiPembayaran(double saldo, double totalPembayaran){
	if (saldo >= totalPembayaran){
		cout << "Pembayaran berhasil!!!!" << endl;
		saldo = saldo - totalPembayaran;
		cout << "Sisa saldo anda adalah : $ " << saldo << endl;
	}
	else if (saldo < totalPembayaran){
		cout << "Maaf uang anda kurang !!!" << endl;
		cout << "Pembayaran akan otomatis dibatalkan!" << endl;
	}
}
void pembayaran(double saldo,double totalPembayaran ,vector<dataPasien>& dataPasien1){
	int input;
	cout << "Silahkan pilih metode pembayaran!!!" << endl;
	cout << "1. Tunai" << endl;
	cout << "2. Non Tunai" << endl;	
	cout << ">> ";
	cin >> input;
	if (input == 2){
		if(dataPasien1[0].noRek.empty()){
			cout << "Anda tidak mempunyai nomor rekening !!!" << endl;
		}
		else if(!dataPasien1[0].noRek.empty()){
		string norek;
		trynorek:
		cout << "Silahkan masukan nomor rekening anda : ";
		cin >> norek;
		if (dataPasien1[0].noRek == norek){
			string pin;
			trypin:
			cout << "masukan pin anda : ";
			cin >> pin;
			if (dataPasien1[0].pin == pin){
				cout << "masukan nominal pembayaran!!! " << endl;
				cout << ">> ";
				cin >> saldo;
				kalkulasiPembayaran(saldo,totalPembayaran);
			}
			else if (dataPasien1[0].pin != pin){
				cout << "pin yang anda masukan salah!!!" << endl;
				goto trypin;
			}
		}
		else if (dataPasien1[0].noRek != norek){
			cout << "nomor rekening yang anda masukan salah!!!" << endl;
			goto trynorek;
		}
		}
	}
	else if(input == 1){
		cout << "silahkan masukan nominal pembayaran!!!" << endl;
		cout << ">> ";
		cin >> saldo;
		kalkulasiPembayaran(saldo,totalPembayaran);
	}
	cin.get();
	cin.get();
}
void rawatInap(vector<dataPasien>& datapasien1){
	double saldo;
	int inputListRuangan = listRuangan();
	double diskon = diskonBpjsRuangRawatInap(datapasien1);
	double harga;
	if (datapasien1[0].bpjs == true){
		switch(inputListRuangan){
			case 1:
				harga = 425;
				tampilkanHarga(false,harga,diskon,datapasien1); 
				pembayaran(saldo, harga ,datapasien1);
				break;
			case 2:
				harga = 240;
				tampilkanHarga(false, harga,diskon,datapasien1); 
				pembayaran(saldo, harga ,datapasien1);
				break;
			case 3:
				harga = 140;
				tampilkanHarga(true, harga,diskon,datapasien1); 
				pembayaran(saldo, harga ,datapasien1);
				break;
			case 4:
				harga = 80;
				tampilkanHarga(true, harga,diskon,datapasien1);
				pembayaran(saldo, harga ,datapasien1);
				break;
			case 5:
				harga = 55;
				tampilkanHarga(true, harga,diskon,datapasien1); 
				pembayaran(saldo, harga ,datapasien1);
				break;
			default:
				cout << "input yang anda masukan tiak valid !!!" << endl;
				cin.get();
				cin.get();
				break;
			}
		}
	else if(datapasien1[0].bpjs == false){
		switch(inputListRuangan){
			case 1:
				harga = 425;
				tampilkanHarga(false, harga,diskon,datapasien1); 
				pembayaran(saldo, harga ,datapasien1);
				break;
			case 2:
				harga = 240;
				tampilkanHarga(false, harga,diskon,datapasien1); 
				pembayaran(saldo, harga ,datapasien1);
				break;
			case 3:
				harga = 145;
				tampilkanHarga(false, harga,diskon,datapasien1); 
				pembayaran(saldo, harga ,datapasien1);
				break;
			case 4:
				harga = 80;
				tampilkanHarga(false, harga,diskon,datapasien1); 
				pembayaran(saldo, harga ,datapasien1);
				break;
			case 5:
				harga = 55;
				tampilkanHarga(false, harga,diskon,datapasien1); 
				pembayaran(saldo, harga ,datapasien1);
				break;
			default:
				cout << "input yang anda masukan tiak valid !!!" << endl;
				cin.get();
				cin.get();
				break;
			}
	}
};
int listTindakanMedis(){
	system("clear");
	int input;
	cout << "Tindakan medis" << endl;
	cout << "1. Pemeriksaan Kesehatan Umum $200" << endl;
	cout << "2. Operasi $5000" << endl;
	cout << "3. Tes Laboratorium $300" << endl;
	cout << ">> ";
	cin >> input;
	return input;	
}
void tindakanMedis(vector<dataPasien>& dataPasien1){
	system("clear");
	double harga, saldo;
	int inputListTindakanMedis = listTindakanMedis();
	double diskon = diskonBpjsTindakanMedis(inputListTindakanMedis, dataPasien1);
	if (dataPasien1[0].bpjs == true){
		switch(inputListTindakanMedis){
			case 1:
				harga = 200;
				tampilkanHarga(true, harga,diskon,dataPasien1); break;
				pembayaran(saldo, harga, dataPasien1); break;
			case 2:
				harga = 5000;
				tampilkanHarga(true, harga,diskon,dataPasien1); break;
				pembayaran(saldo, harga, dataPasien1); break;
			case 3:
				harga = 300;
				tampilkanHarga(true, harga,diskon,dataPasien1); break;
				pembayaran(saldo, harga, dataPasien1); break;
			default:
				cout << "input yang anda masukan tiak valid !!!" << endl;
				cin.get();
				cin.get();
				break;
		}
	}
	else if(dataPasien1[0].bpjs == false){
		switch(inputListTindakanMedis){
			case 1:
				harga = 200;
				tampilkanHarga(false, harga,diskon,dataPasien1); break;
				pembayaran(saldo, harga, dataPasien1); break;
			case 2:
				harga = 5000;
				tampilkanHarga(false, harga,diskon,dataPasien1); break;
				pembayaran(saldo, harga, dataPasien1); break;
			case 3:
				harga = 300;
				tampilkanHarga(false, harga,diskon,dataPasien1); break;
				pembayaran(saldo, harga, dataPasien1); break;
			default:
				cout << "input yang anda masukan tiak valid !!!" << endl;
				cin.get();
				cin.get();
				break;
		}
	}
};
int inputanObat(){
	int input;
	cout << "silahkan pilih jenis obat yang akan dibeli!!" << endl;
	cout << "1. Tablet" << endl;
	cout << "2. Sirup" << endl;
	cout << "3. Kapsul" << endl;
	cout << ">> ";
	cin >> input;
	return input;
}
string cariObat(){
	string input;
	cout << "silahkan masukan nama obat yang ingin dibeli!!!" << endl;
	cout << ">> ";
	cin >> input;
	transform(input.begin(), input.end(), input.begin(), ::tolower);
	return input;
}
void pembelianObat(vector<dataPasien>& dataPasien1){
	system("clear");
	double harga, saldo;
	bool obatDitemukan = false;
	int input = inputanObat();
	if (input == 1){
	listObatTablet();
	tryInputObatTablet:
	string inputObat = cariObat();
		for (auto& tablet : listobat1.tablet){
		transform(tablet.namaObat.begin(), tablet.namaObat.end(), tablet.namaObat.begin(), ::tolower);
		if(tablet.namaObat == inputObat){
			obatDitemukan = true;
			harga = tablet.harga;
			cout << "harga yang harus anda bayar adalah : $" << tablet.harga << endl;
			pembayaran(saldo, harga, dataPasien1);
		}
	}	
		if(!obatDitemukan){
				cout << "nama obat tidak ditemukan!!!";
				cin.get();
				cin.get();
				goto tryInputObatTablet;
			}
	}else if (input == 2){
		listObatSirup();
		tryInputObatSirup:
		string inputObat = cariObat();
		for(auto& sirup : listobat1.sirup){
			transform(sirup.namaObat.begin(), sirup.namaObat.end(), sirup.namaObat.begin(), ::tolower);
			if(sirup.namaObat == inputObat){
				obatDitemukan = true;
				harga = sirup.harga;
				cout << "harga yang harus anda bayar adalah : $" << sirup.harga << endl;
				pembayaran(saldo, harga, dataPasien1);
			}
		}
		if(!obatDitemukan){
			cout << "nama obat tidak ditemukan!!!" << endl;
			cin.get();
			cin.get();
			goto tryInputObatSirup;
		}
	}else if (input == 3){
		listObatKapsul();
		tryInputObatKapsul:
		string inputObat = cariObat();
		for(auto& kapsul : listobat1.kapsul){
			transform(kapsul.namaObat.begin(), kapsul.namaObat.end(), kapsul.namaObat.begin(), ::tolower);
			if(kapsul.namaObat == inputObat){
				obatDitemukan = true;
				harga = kapsul.harga;
				cout << "harga yang harus anda bayar adalah : $" << kapsul.harga << endl;
				pembayaran(saldo, harga, dataPasien1);
			}
		}
			if(!obatDitemukan){
				cout << "nama obat tidak ditemukan!!!" << endl;
				cin.get();
				cin.get();
				goto tryInputObatKapsul;
			}
	}
	else {
	cout << "input yang anda masukan tiak valid !!!" << endl;
			cin.get();
			cin.get();
	}
};