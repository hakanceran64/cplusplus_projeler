/*
 * Author: Hakan Ceran
 * Date: 28.08.2017
 * Content: Kullan�c�dan bir paragraf ve bir karakter dizisi alan, daha sonra bu karakter dizisi i�erisindeki karakterleri paragraf i�erisinde arayan, onlar� silen ve daha sonra bu paragraf� en son haliyle ekrana yazan bir program yaz�n�z.
 */

#include <iostream>

using namespace std;

int main(){
	
	char paragraf[1000000];
	char silinecek_karakterler[100];
	
	/* paragraf� gir */
	cout << "Paragrafi giriniz: ";
	cin.getline(paragraf,10000);
	
	/* Silinecek karakteri gir */
	cout << "Silinecek karakteri giriniz: ";
	cin.getline(silinecek_karakterler,100); // Bo�luk karakteride dahil olmak �zere al�r.
	
	// karakter_sil(paragraf,silinecek_karakterler);
	int indis=0;
	
	for(int i=0; paragraf[i]!='\0'; ++i){
		paragraf[indis]=paragraf[i];
		bool sil=false;

		for(int j=0; silinecek_karakterler[j]!='\0'; ++j){
			char a=paragraf[i];
			char b=silinecek_karakterler[j];

			// B�y�k harfleri k���k harfe �evir
			if(a>90)
				a-=32;
			if(b>90)
				b-=32;
			if(a==b){
				sil=true;
				break;
			}
		}
		if(!sil)
			++indis;
	}
	
	paragraf[indis]='\0';
	
	cout << paragraf << endl;

	system("PAUSE");
	return 0;
}

