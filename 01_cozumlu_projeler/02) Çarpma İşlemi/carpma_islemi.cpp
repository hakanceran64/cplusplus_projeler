/*
 * Author: Hakan Ceran
 * Date: 25.08.2017
 * Content: Kullanýcýdan tam sayý(int) tipinde iki sayý alýnýz ve bu iki sayýyý çarpýnýz.
 */

/* Bir kütüphane #include komutu ile programa dahil edilir. Aþaðýda iostream kütüphanesi projeye eklenmiþtir. iostream kütüphanesi temel giriþ/çýkýþ (input/output) kütüphanesidir.
   cin, cout, cerr, komutlarý bu kütüphane eklenmeden çalýþtýrýlamaz.
   #include <iostream> satýrýný silerek hatayý kontrol edebilirsiniz. */

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
 
