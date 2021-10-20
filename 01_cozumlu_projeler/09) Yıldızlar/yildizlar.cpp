/*
 * Author: Hakan Ceran
 * Date: 26.08.2017
 * Content: Kullanýcýdan bir sayý isteyiniz kullanýcýnýn girdiði sayý adetince alt alta yýldýz yazýnýz.
 */

#include <iostream>

using namespace std;

int main(){
	int sayi;
	
	cout << "bir sayi giriniz: ";
	cin >> sayi;
	
	for(int i=1; i<=sayi; i++){
		cout << "*\n";
	}
	
	system("PAUSE");
	return 0;
}
