/*
 * Author: Hakan Ceran
 * Date: 26.08.2017
 * Content: Kullan�c�dan bir say� isteyiniz kullan�c�n�n girdi�i say� adetince alt alta y�ld�z yaz�n�z.
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
