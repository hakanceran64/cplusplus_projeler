/*
 * Author: Hakan Ceran
 * Date: 26.08.2017
 * Content: Kullanýcýnýn girdiði sayýya göre üçgen çizme
 */

#include <iostream>

using namespace std;

int main(){
	int sayi,bellek;
	
	cout << "Bir sayi giriniz: "; cin >> sayi;
	
	cout << "\n";
	for(int i=0; i<sayi; i++){
		for(int j=0; j<=i; j++){
			cout << "* ";
		}
		cout << "\n";
	}
	
	system("PAUSE");
	return 0;
}
