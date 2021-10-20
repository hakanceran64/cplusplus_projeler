/*
 * Author: Hakan Ceran
 * Date: 28.08.2017
 * Content: Kullanýcýdan bir paragraf ve bir karakter dizisi alan, daha sonra bu karakter dizisi içerisindeki karakterleri paragraf içerisinde arayan, onlarý silen ve daha sonra bu paragrafý en son haliyle ekrana yazan bir program yazýnýz.
 */

#include <iostream>

using namespace std;

int main(){
	
	char paragraf[1000000];
	char silinecek_karakterler[100];
	
	/* paragrafý gir */
	cout << "Paragrafi giriniz: ";
	cin.getline(paragraf,10000);
	
	/* Silinecek karakteri gir */
	cout << "Silinecek karakteri giriniz: ";
	cin.getline(silinecek_karakterler,100); // Boþluk karakteride dahil olmak üzere alýr.
	
	// karakter_sil(paragraf,silinecek_karakterler);
	int indis=0;
	
	for(int i=0; paragraf[i]!='\0'; ++i){
		paragraf[indis]=paragraf[i];
		bool sil=false;

		for(int j=0; silinecek_karakterler[j]!='\0'; ++j){
			char a=paragraf[i];
			char b=silinecek_karakterler[j];

			// Büyük harfleri küçük harfe çevir
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

