/*
 * Author: Hakan Ceran
 * Date: 25.08.2017
 * Content: Kullan�c�dan tam say�(int) tipinde iki say� al�n�z ve bu iki say�y� �arp�n�z.
 */

/* Bir k�t�phane #include komutu ile programa dahil edilir. A�a��da iostream k�t�phanesi projeye eklenmi�tir. iostream k�t�phanesi temel giri�/��k�� (input/output) k�t�phanesidir.
   cin, cout, cerr, komutlar� bu k�t�phane eklenmeden �al��t�r�lamaz.
   #include <iostream> sat�r�n� silerek hatay� kontrol edebilirsiniz. */

#include <iostream>

using namespace std;

int main(){
	
	int sayi_1;
	int sayi_2;
	int carpim;
	
	cout << "Bir sayi giriniz: " << endl;
	cin >> sayi_1;
	
	cout << "Bir sayi daha giriniz: " << endl;
	cin >> sayi_2;
	
	carpim=sayi_1*sayi_2;
	
	cout << "Girilen iki sayinin carpimi: " << carpim << endl;
	
	system("PAUSE");
	return 0;
}
 
