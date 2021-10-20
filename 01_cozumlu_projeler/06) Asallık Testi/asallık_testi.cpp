/*
 * Author: Hakan Ceran
 * Date: 25.08.2017
 * Content: Asallýk Testi
 */

#include <iostream>

using namespace std;

int main(){
	int sayi = 0, sayac = 1;
	char secim = 'e';
	
	while ( secim == 'e' ) {
		cout << "Bir sayi giriniz: ";
		cin >> sayi;
		
		if ( sayi > 2 ) {
			while ( sayac < sayi - 1 ) {
				sayac++;
				/* Sayý sayac'a tam bolunuyor mu? */
				if ( sayi % sayac == 0 ) {
					cout << "Sayi asal degildir!\n";
					break;
				} else if ( sayac + 1 == sayi ) {
					cout << "Sayi asaldir.\n";
				}
			}
		} else if ( sayi == 2 ) {
			cout << "Girilen sayi en kucuk asal sayidir.\n";
		} else {
			cout << "Asallik pozitif tam sayilarda aranir.\n";
		}
		
		cout << "e-devam, h-cikis" << endl;
		cin >> secim;
		
		sayac = 1;
	}
	
	system("PAUSE");
	return 0;
}
