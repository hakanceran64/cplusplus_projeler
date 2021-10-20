/*
 * Author: Hakan Ceran
 * Date: 02.09.2017
 * Content: Bu soruda girdi olarak verilen bir karakter dizisi içerisindeki en sýk tekrar eden karakter ikilisini bulmanýz için bir program yazmanýz istenmektedir.
 *			Girdi bir satýrdan ve sadece küçük harflerden oluþmaktadýr ve maksimum  uzunluðu 10000 karakter olabilmektedir.
 *			Çýktý olarak ise dizi içerisinde en sýk tekrar eden karakter ikilisini ve kaç defa tekrar ettiðini ekrana yazdýrmasý beklenmektedir.
 */

#include <iostream>
#include <cstring>

using namespace std;

int main(){
	
	char karakterler[10000], c1, c2;
	int frekanslar[26][26]={0}, uzunluk, maksimum, x, y;
	
	cout << "Bir metin giriniz: ";
	cin >> karakterler;
	
	uzunluk=strlen(karakterler);
	for(int i=0; i<uzunluk-1; ++i){
		c1=karakterler[i];
		c2=karakterler[i+1];
		++frekanslar[c1-'a'][c2-'a'];
	}
	maksimum=-1;
	x=-1;
	y=-1;
	for(int i=0; i<26; ++i){
		for(int j=0; j<26; ++j){
			if(frekanslar[i][j]>maksimum){
				maksimum=frekanslar[i][j];
				x=i;
				y=j;
			}
		}
	}
	c1=x+'a';
	c2=y+'a';
	cout << c1 << c2 << " " << maksimum << endl;

	system("PAUSE");
	return 0;
}

