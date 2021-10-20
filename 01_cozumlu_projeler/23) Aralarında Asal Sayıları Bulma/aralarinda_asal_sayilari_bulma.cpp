/*
 * Author: Hakan Ceran
 * Date: 27.08.2017
 * Content: Girilen iki sayýnýn aralarýnda asal olup olmadýðýný bulan program.
 */

#include <iostream>

using namespace std;

void aralarinda_asal_mi(int sayi_1, int sayi_2, bool *sonuc);

int main(){
	
	int a,b;
	bool cevap;
	
	cin >> a >> b;
	
	aralarinda_asal_mi(a,b,&cevap);
	
	/* Cevap true ise aralarýnda asal deðil ise aralarýnda asal degil ifadesini ekrana yazar. */
	cout << (cevap ? "Aralarinda asal\n" : "Aralarinda asal degil.\n");

	system("PAUSE");
	return 0;
}

void aralarinda_asal_mi(int sayi_1, int sayi_2, bool *sonuc){
	// Küçük sayýyý bul
	int kucuk_sayi=sayi_1;
	
	if(sayi_2<kucuk_sayi)
		kucuk_sayi=sayi_2;
	
	/* sayi_1 ve sayi_2 aralarinda asala kabul edelim */
	*sonuc=1;
	
	// Küçük sayýya kadar olan sayýlarý kalansýz bölme için dene...
	for(int i=2; i<=kucuk_sayi; ++i){
		// Bir tane ortak bölen olmasý o iki sayýnýn aralarýnda asal olmadýðýný gösterir.
		if(sayi_1%i==0 && sayi_2%i==0){
			*sonuc=0;
			return;
		}
	}
}
