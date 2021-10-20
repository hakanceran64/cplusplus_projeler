/*
 * Author: Hakan Ceran
 * Date: 28.08.2017
 * Content: Kullan�c�n�n girdi�i n tane karakter i�erisinden en fazla ve en az tekrar eden karakteri ve bunlar�n ka�ar tane tekrar edildiklerini ekrana yazan program� yaz�n�z.
 */

#include <iostream>

using namespace std;

int main(){
	
	char karakterler[1000000];
	
	cout << "Bir metin giriniz: ";
	cin >> karakterler;
	
	/* �ngilizce alfebede 26 karakter vard�r. */
	int karakter_sayilari[26];
	
	for(int i=0; i<26; ++i){
		karakter_sayilari[i]=0;
	}
	
	for(int i=0; karakterler[i]!='\0'; ++i){
		char karakter=karakterler[i];
		int indis;
		
		/* indis karakterin alfabenin ka��nc� s�rada oldu�unu g�sterir. Karakterin a oldu�unu varsayal�m. 'a'-'a' sonucu 0 olacakt�r. 0 ise a harfinin alfabedeki s�ras�n� g�stermektedir. */
		if(karakter>='a'){
			indis=karakter-'a';
		} else {
			indis=karakter-'A';
		}
		karakter_sayilari[indis]++;
	}
	
	/* indis numaras� ve 'A' harfini toplar isek indesteki say�n�n hangi harfin say�s� oldu�unu buluruz. �rne�in, max_char=i+'A' */
	int max_sayi=-1, min_sayi=10001;
	char max_char, min_char;
	for(int i=0; i<26; ++i){
		if(karakter_sayilari[i]==0){
			continue;
		}
		if(karakter_sayilari[i]>max_sayi){
			max_sayi=karakter_sayilari[i];
			max_char=i+'A';
		}
		if(karakter_sayilari[i]<min_sayi){
			min_sayi=karakter_sayilari[i];
			min_char=i+'A';
		}
	}
	
	cout << "En fazla: " << max_char << " " << max_sayi << endl;
	cout << "En az: " << min_char << " " << min_sayi << endl;

	system("PAUSE");
	return 0;
}

