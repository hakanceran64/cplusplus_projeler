/*
 * Author: Hakan Ceran
 * Date: 26.08.2017
 * Content: Kullan�c�n�n girece�i en x boy adetince y�ld�z kullanarak dikd�rtgen �iziniz.
 */

#include <iostream>

using namespace std;

int main(){
	int en, boy;
	
	cout << "Dikdortgenin enini giriniz: "; cin >> en;
	cout << "Dikdortgenin boyunu giriniz: "; cin >> boy;
	
	cout << "\n";
	for(int i=1; i<=boy; i++){
		for(int j=1; j<=en; j++){
			cout << "* ";
		}
		cout << "\n";
	}
	
	system("PAUSE");
	return 0;
}
