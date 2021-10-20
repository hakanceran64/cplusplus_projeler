// A��kcas� pek begenmedim ayn� kelimeden iki farkl� dosyada varsa en son buldugunu s�yl�yor ve bulunmad��� zaman uyar� falan vermekde yok.

/*
 * Author: Hakan Ceran
 * Date: 17.09.2017
 * Content: Bir elektronik k�t�phane sorumlusunun b�y�k boyutlarda text dosyalar� vard�r. Text dosyalar� File0, File1, File2... gibi d�zenli bir �ekilde olu�turulmu�tur.
 *			K�t�phane sorumlusunun zaman zaman baz� anahtar kelimelerin hangi dosyalarda ge�ti�ini bulmas� gerekmektedir.
 *			K�t�phane sorumlusunun i�ini kolayla�t�ran bu projeyi kodlay�n�z.
 *			NOT: K�t�phane sorumlusu hangi aral�kta dosyalarda arama yapabilece�ini bir �nceki projede oldu�u gibi belirleyebilmelidir.
 */

#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

void dosyada_ara(string dosya_adi, string aranacak_kelime);

int main(){
	
	string aranacak_kelime="";
	
	// stringstream Stream s�n�f�n�n bir objesidir. S�ral� karakterler i�erir.
	stringstream dosya_adi;
	int sayi_dizisi[1000];
	
	// Okunacak dosya aral���n� belirlemek i�in
	int baslangic=0, bitis=0;
	
	cout << "Dosyalarda arayacaginiz kelimeyi giriniz: ";
	cin >> aranacak_kelime;
	
	cout << "Kelime hangi dosya araliginda aratilacak: ";
	cin >> baslangic >> bitis;
	
	for(int i=baslangic; i<bitis; i++){
		// Okunacak dosyalr�n isimlerini belirliyoruz
		dosya_adi << "File" << i << ".txt";
		
		// dosyada_ara fonksiyonuna parametrelerini g�nderiyoruz
		dosyada_ara(dosya_adi.str().c_str(),aranacak_kelime);
		
		dosya_adi.str("");
	}

	system("PAUSE");
	return 0;
}

void dosyada_ara(string dosya_adi, string aranacak_kelime){
	// Dosyadan okuma yapmak i�in
	ifstream in;
	
	// Dosyadan okunan kelimedir
	string kelime;
	
	in.open(dosya_adi.c_str());
	
	// E�er dosya a��lamad�ysa
	if(!in.is_open()){
		cout << dosya_adi.c_str() << " dosyasina erisilemedi." << endl;
	} else{
		while(!in.eof()){
			in >> kelime;
			if(kelime==aranacak_kelime){
				cout << "Kelime " << dosya_adi << "'de bulundu." << endl;
			}
		}
	}
	in.close();
}

