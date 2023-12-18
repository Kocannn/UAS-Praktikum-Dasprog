#include <iostream>
#include <vector>
#include "fungsi.h"
#include <algorithm>
using namespace std;
int main()
{
	vector<dataPasien> dataPasien2;
	bool isContiniue = true;
	pendaftaran(dataPasien2);
	while(isContiniue){
	system("clear");
	cout << "Halo " << dataPasien2[0].nama << "!!!" << endl;
	int userInput = menu();
	switch (userInput){
	case 1: 
		rawatInap(dataPasien2);
		break;
	case 2:
		tindakanMedis(dataPasien2);
		break;
	case 3:
		pembelianObat(dataPasien2);
		break;
	case 4:
		informasiPasien(dataPasien2);
		break;
	case 5:
		isContiniue = false;
		break;
	default:
		cout << "input yang anda masukan tiak valid !!!" << endl;
		cin.get();
		cin.get();
		break;
	}
  }
	return 0;
}