/*
 * Author: Hakan Ceran
 * Date: 26.08.2017
 * Content: Kullanýcýnýn gireceði en x boy adetince yýldýz kullanarak dikdörtgen çiziniz.
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
