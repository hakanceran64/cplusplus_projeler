/*
 * Author: Hakan Ceran
 * Date: 26.08.2017
 * Content: Ýþaretçi (pointer) kullanarak, bir dairenin alanýný ve çevresini hesaplayýnýz.
 */

#include <iostream>

using namespace std;

void hesapla(int r, float *cevre, float *alan){
	/* Elde edilen sonuclar cevre ve alan isimli deðiþken kanalý ile fonksiyonun çaðrýldýðý program blogunda kullanýlabilir. */
	*cevre = 2*3.14*r;
	*alan = 3.14*r*r;
}

int main(){
	
	int yaricap;
	float cevre, alan;
	
	cout << "Yaricap giriniz: ";
	cin >> yaricap;
	
	/* yaricap degiskenini ve cevre ve alan degiskenlerinin adresini parametre olarak gonder */
	hesapla(yaricap,&cevre,&alan);
	
	cout << "Dairenin cevresi: " << cevre << endl;
	cout << "Dairenin alani: " << alan << endl;

	system("PAUSE");
	return 0;
}

