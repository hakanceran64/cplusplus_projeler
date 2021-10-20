/*
 * Author: Hakan Ceran
 * Date: 26.08.2017
 * Content: Kullanýcýnýn girdiði sayýya göre ters simetrik üçgen çizme
 */

#include <iostream>

using namespace std;

int main(){
	int sayi;
	
	cout << "Bir sayi giriniz: "; cin >> sayi;
	
	cout << "\n";
	for(int i=0; i<sayi; i++){
		for(int k=0; k<i; k++ ){ // Boþluk býrakmak için
			cout << "  ";
		}
		for(int l=sayi; l>i; l--){ // Yýldýz býrakmak için
			cout << "* ";
		}
		cout << "\n";
	}
	
	system("PAUSE");
	return 0;
}
