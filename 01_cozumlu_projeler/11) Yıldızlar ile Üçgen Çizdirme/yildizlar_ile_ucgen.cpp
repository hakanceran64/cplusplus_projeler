/*
 * Author: Hakan Ceran
 * Date: 26.08.2017
 * Content: Kullan�c�n�n girdi�i say�ya g�re ters ��gen �izme
 */

#include <iostream>

using namespace std;

int main(){
	int sayi;
	
	cout << "Bir sayi giriniz: "; cin >> sayi;
	
	cout << "\n";
	for(int i=sayi; i>=1; i--){
		for(int j=1; j<=i; j++){
			cout << "* ";
		}
		cout << "\n";
	}
	
	system("PAUSE");
	return 0;
}
