/*
 * Author: Hakan Ceran
 * Date: 25.08.2017
 * Content: Say� Tahmini
 */

#include <iostream>
#include <stdlib.h> // Random say� �retimi i�in gerekli olan k�t�phane

using namespace std;

int main(){
	int tahmin;
	char cevap = 'e';
	
	srand(time(NULL)); // Farkl� say�lar i�in zaman� s�f�rlama
	
	while ( cevap == 'e' ) {
		int sayi = rand() % 100;
		
		cout << "0-100 arasinda bir sayi tuttum." << endl;
		cout << "Hadi tahmin et: ";
		cin >> tahmin;
		
		while ( tahmin != sayi ) {
			if ( tahmin < sayi ) {
				cout << tahmin << " tuttugum sayidan kucuk.\n";
			} else {
				cout << tahmin << " tuttugum sayidan buyuk.\n";
			}
			
			cout << "tekrar tahmin et: ";
			cin >> tahmin;
		}
		cout << "Buldun tebrikler: " << sayi << endl;
		cout << "Yeniden oynamak ister misin?" << endl;
		cout << "(Evet: e, Hayir: h) ";
		cin >> cevap;
	}
	
	cout << "Gule gule yine bekleriz.*n";
	
	system("PAUSE");
	return 0;
}
