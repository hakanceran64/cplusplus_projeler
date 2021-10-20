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
	
	for(int i=0; i<sayi; i++){
		for(int k=sayi; k>i; k--){ // Yýldýz býrakmak için
			cout << "  ";
		}
		for(int l=0; l<i; l++ ){ // Boþluk býrakmak için
			cout << "* ";
		}
		cout << "\n";
	}
	
	system("PAUSE");
	return 0;
}
