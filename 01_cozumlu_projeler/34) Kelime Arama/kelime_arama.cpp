/*
 * Author: Hakan Ceran
 * Date: 29.08.2017
 * Content: Kullan�c�dan bir c�mle ve bir kelima alan ve bu c�mle i�erisinde bu kelimeyi aray�p bulundu�u indisi ekrana yazan bir program yaz�n�z. E�er kelime c�mle i�erisinde bulunmad�ysa -1 yazmal�d�r. Yaz�lan program b�y�k k���k harfe duyarl� de�ildir. Yani hem girilen c�mle hem de kelime i�erisinde b�y�k ve k���k karakter olabilir ve bulma i�lemi bu b�y�k k���k harften ba��ms�zd�r.
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
			/* B�t�n harfleri b�y�k harfe �evirerek kontrol et */
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
		/* Bulundu ise hangi indiste bulundu�unu yaz. */
		if(bulundu){
			cout << i << endl;
			return 0;
		}
	}
	
	cout << -1 << endl;

	system("PAUSE");
	return 0;
}

