/*
 * Author: Hakan Ceran
 * Date: 26.08.2017
 * Content: Kullan�c�n�n girdi�i say�ya g�re ters simetrik ��gen �izme
 */

#include <iostream>

using namespace std;

int main(){
	int sayi;
	
	cout << "Bir sayi giriniz: "; cin >> sayi;
	
	for(int i=0; i<sayi; i++){
		for(int k=sayi; k>i; k--){ // Y�ld�z b�rakmak i�in
			cout << "  ";
		}
		for(int l=0; l<i; l++ ){ // Bo�luk b�rakmak i�in
			cout << "* ";
		}
		cout << "\n";
	}
	
	system("PAUSE");
	return 0;
}
