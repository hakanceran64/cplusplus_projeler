/*
 * Author: Hakan Ceran
 * Date: 27.08.2017
 * Content: Girilen iki say�n�n aralar�nda asal olup olmad���n� bulan program.
 */

#include <iostream>

using namespace std;

void aralarinda_asal_mi(int sayi_1, int sayi_2, bool *sonuc);

int main(){
	
	int a,b;
	bool cevap;
	
	cin >> a >> b;
	
	aralarinda_asal_mi(a,b,&cevap);
	
	/* Cevap true ise aralar�nda asal de�il ise aralar�nda asal degil ifadesini ekrana yazar. */
	cout << (cevap ? "Aralarinda asal\n" : "Aralarinda asal degil.\n");

	system("PAUSE");
	return 0;
}

void aralarinda_asal_mi(int sayi_1, int sayi_2, bool *sonuc){
	// K���k say�y� bul
	int kucuk_sayi=sayi_1;
	
	if(sayi_2<kucuk_sayi)
		kucuk_sayi=sayi_2;
	
	/* sayi_1 ve sayi_2 aralarinda asala kabul edelim */
	*sonuc=1;
	
	// K���k say�ya kadar olan say�lar� kalans�z b�lme i�in dene...
	for(int i=2; i<=kucuk_sayi; ++i){
		// Bir tane ortak b�len olmas� o iki say�n�n aralar�nda asal olmad���n� g�sterir.
		if(sayi_1%i==0 && sayi_2%i==0){
			*sonuc=0;
			return;
		}
	}
}
