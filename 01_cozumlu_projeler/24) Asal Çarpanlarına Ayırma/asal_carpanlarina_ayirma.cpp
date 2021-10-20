/*
 * Author: Hakan Ceran
 * Date: 27.08.2017
 * Content: Girilen bir sayýyý asal çarpanlarýna ayýrýnýz.
 */

#include <iostream>

using namespace std;

int main(){
	
	int sayi, carpan=2;
	
	cin >> sayi;
	
	cout << "Sayinin asal carpanlari: ";
	
	while(sayi>1){
		/* Bir sayinin ayni carpana birden fazla bolunmesi durumu. Örneðin: 8 */
		while(sayi%carpan==0){
			cout << carpan << " ";
			sayi/=carpan;
		}
		++carpan;
	}
	
	cout << endl;

	system("PAUSE");
	return 0;
}

