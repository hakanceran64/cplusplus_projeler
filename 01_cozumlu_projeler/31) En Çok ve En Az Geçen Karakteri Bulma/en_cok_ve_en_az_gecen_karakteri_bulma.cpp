/*
 * Author: Hakan Ceran
 * Date: 28.08.2017
 * Content: Kullanıcının girdiği n tane karakter içerisinden en fazla ve en az tekrar eden karakteri ve bunların kaçar tane tekrar edildiklerini ekrana yazan programı yazınız.
 */

#include <iostream>

using namespace std;

int main(){
	
	char karakterler[1000000];
	
	cout << "Bir metin giriniz: ";
	cin >> karakterler;
	
	/* İngilizce alfebede 26 karakter vardır. */
	int karakter_sayilari[26];
	
	for(int i=0; i<26; ++i){
		karakter_sayilari[i]=0;
	}
	
	for(int i=0; karakterler[i]!='\0'; ++i){
		char karakter=karakterler[i];
		int indis;
		
		/* indis karakterin alfabenin kaçıncı sırada olduğunu gösterir. Karakterin a olduğunu varsayalım. 'a'-'a' sonucu 0 olacaktır. 0 ise a harfinin alfabedeki sırasını göstermektedir. */
		if(karakter>='a'){
			indis=karakter-'a';
		} else {
			indis=karakter-'A';
		}
		karakter_sayilari[indis]++;
	}
	
	/* indis numarası ve 'A' harfini toplar isek indesteki sayının hangi harfin sayısı olduğunu buluruz. Örneğin, max_char=i+'A' */
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

