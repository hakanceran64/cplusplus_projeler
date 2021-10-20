/*
 * Author: Hakan Ceran
 * Date: 29.08.2017
 * Content: Kullanýcýdan bir cümle ve bir kelima alan ve bu cümle içerisinde bu kelimeyi arayýp bulunduðu indisi ekrana yazan bir program yazýnýz. Eðer kelime cümle içerisinde bulunmadýysa -1 yazmalýdýr. Yazýlan program büyük küçük harfe duyarlý deðildir. Yani hem girilen cümle hem de kelime içerisinde büyük ve küçük karakter olabilir ve bulma iþlemi bu büyük küçük harften baðýmsýzdýr.
 */

#include <iostream>

using namespace std;

int main(){
	
	char paragraf[10000];
	char aranan[100];
	
	cout << "Paragrafi giriniz: ";
	cin.getline(paragraf,10000);
	
	cout << "Aranan kelimeyi giriniz: ";
	cin >> aranan;
	
	int paragraf_uzunluk,aranan_uzunluk;
	/* Paragaf ve aranan kelimenin uzunlugunu bul */
	for(paragraf_uzunluk=0; paragraf[paragraf_uzunluk]!='\0'; ++paragraf_uzunluk);
	for(aranan_uzunluk=0; aranan[aranan_uzunluk]!='\0'; ++aranan_uzunluk);
	
	for(int i=0; i<=(paragraf_uzunluk-aranan_uzunluk); ++i){
		bool bulundu=true;
		
		for(int j=0; j<aranan_uzunluk; ++j){
			/* Bütün harfleri büyük harfe çevirerek kontrol et */
			char a=paragraf[i+j];
			char b=aranan[j];
			if(a<=90)
				a+=32;
			if(b<=90)
				b+=32;
			if(a!=b){
				bulundu=false;
				break;
			}
		}
		/* Bulundu ise hangi indiste bulunduðunu yaz. */
		if(bulundu){
			cout << i << endl;
			return 0;
		}
	}
	
	cout << -1 << endl;

	system("PAUSE");
	return 0;
}

