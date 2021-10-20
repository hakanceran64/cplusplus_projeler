/*
 * Author: Hakan Ceran
 * Date: 27.08.2017
 * Content: Verilen bir say� taban�ndaki bir say�y� istenilen tabandaki kar��l���na d�n��t�ren bir fonksiyon yaz�n�z.
 */

#include <iostream>

using namespace std;

/* B�t�n tabanlar �nce 10luk tabana d�n��t�r�l�r. �stenilen tabana ise onluk tabandan d�n��t�r�l�r. */
void onluk_tabana_donustur(int verilen_taban, int sayi, int *sonuc);
void onluk_tabandan_donustur(int istenilen_taban, int sayi, int *sonuc);
void taban_degistir(int sayi_tabani, int sayi, int istenilen_taban, int *sonuc);

int main(){
	
	int sayi_tabani, sayi, istenilen_taban, sonuc;
	
	cout << "Sayi tabani\tSayi\tIstenilen Taban\n";
	cin >> sayi_tabani >> sayi >> istenilen_taban;
	
	taban_degistir(sayi_tabani, sayi, istenilen_taban, &sonuc);
	
	cout << sonuc << endl;

	system("PAUSE");
	return 0;
}

void onluk_tabana_donustur(int verilen_taban, int sayi, int *sonuc){
	int kalan, bolum, carpim=1;
	*sonuc=0;
	
	while(sayi!=0){
		kalan=sayi%10;
		*sonuc+=kalan*carpim;
		bolum=sayi/10;
		sayi=bolum;
		carpim*=verilen_taban;
	}
}

void onluk_tabandan_donustur(int istenilen_taban, int sayi, int *sonuc){
	int kalan, bolum, carpim=1;
	*sonuc=0;
	
	while(sayi!=0){
		kalan=sayi%istenilen_taban;
		*sonuc+=carpim*kalan;
		bolum=sayi/istenilen_taban;
		sayi=bolum;
		carpim*=10;
	}
}

void taban_degistir(int sayi_tabani, int sayi, int istenilen_taban, int *sonuc){
	int onluk;
	
	onluk_tabana_donustur(sayi_tabani,sayi,&onluk);
	onluk_tabandan_donustur(istenilen_taban,onluk,sonuc);
}
