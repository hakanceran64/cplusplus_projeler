/*
 * Author: Hakan Ceran
 * Date: 27.08.2017
 * Content: Girilen iki sayýnýn EBOB ve EKOK deðerlerini bulunuz.
 */

#include <iostream>

using namespace std;

void ebobHesapla(int a, int b, int *pEbob);
void ekokHesapla(int a, int b, int *pEkok);
void hesapla(int a, int b, int *pEbob, int *pEkok);

int main(){
	
	int a, b, ebob, ekok;
	
	cin >> a >> b;
	
	hesapla(a,b,&ebob,&ekok);
	
	cout << "Sayilarin ebobu: " << ebob << endl;
	cout << "Sayilarin ekoku: " << ekok << endl;

	system("PAUSE");
	return 0;
}

void ebobHesapla(int a, int b, int *pEbob){
	*pEbob=1;
	int ortakBolen=2;
	
	while(a!=1 && b!=1){
		while(a%ortakBolen==0 && b%ortakBolen==0){
			*pEbob*=ortakBolen;
			a/=ortakBolen;
			b/=ortakBolen;
		}
		while(a%ortakBolen==0){
			a/=ortakBolen;
		}
		while(b%ortakBolen==0){
			b/=ortakBolen;
		}
		++ortakBolen;
	}
}

/*
	1. yol, ekok iki sayýnýn çarpýmýnýn ebob'a bölümüne eþittir.
	2. yol, iki sayýyý da bölenler bulunur ve birbirleriyle çarpýlýr.
*/

void ekokHesapla(int a, int b, int *pEkok){
	// Birinci yol kolay yol
	/*
	int ebob;
	ebobHesapla(a,b,&ebob);
	*pEkok=a*b/ebob;
	*/
	
	// Ýkinci yol zor yol
	*pEkok=1;
	int bolen=2;
	while(a!=1 && b!=1){
		while(a%bolen==0 || b%bolen==0){
			*pEkok*=bolen;
			if(a%bolen==0)
				a/=bolen;
			if(b%bolen==0)
				b/=bolen;
		}
		++bolen;
	}
}

void hesapla(int a, int b, int *pEbob, int *pEkok){
	ebobHesapla(a,b,pEbob);
	ekokHesapla(a,b,pEkok);
}

// EKOK yanlýþ  hesaplanýyor. 1. yoldan sonuca ulaþýrýz ama þuanlýk böylece býrakýyorum.
