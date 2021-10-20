// Açýkcasý pek begenmedim ayný kelimeden iki farklý dosyada varsa en son buldugunu söylüyor ve bulunmadýðý zaman uyarý falan vermekde yok.

/*
 * Author: Hakan Ceran
 * Date: 17.09.2017
 * Content: Bir elektronik kütüphane sorumlusunun bðyðk boyutlarda text dosyalarý vardýr. Text dosyalarý File0, File1, File2... gibi düzenli bir þekilde oluþturulmuþtur.
 *			Kütüphane sorumlusunun zaman zaman bazý anahtar kelimelerin hangi dosyalarda geçtiðini bulmasý gerekmektedir.
 *			Kütüphane sorumlusunun iþini kolaylaþtýran bu projeyi kodlayýnýz.
 *			NOT: Kütüphane sorumlusu hangi aralýkta dosyalarda arama yapabileceðini bir önceki projede olduðu gibi belirleyebilmelidir.
 */

#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

void dosyada_ara(string dosya_adi, string aranacak_kelime);

int main(){
	
	string aranacak_kelime="";
	
	// stringstream Stream sýnýfýnýn bir objesidir. Sýralý karakterler içerir.
	stringstream dosya_adi;
	int sayi_dizisi[1000];
	
	// Okunacak dosya aralýðýný belirlemek için
	int baslangic=0, bitis=0;
	
	cout << "Dosyalarda arayacaginiz kelimeyi giriniz: ";
	cin >> aranacak_kelime;
	
	cout << "Kelime hangi dosya araliginda aratilacak: ";
	cin >> baslangic >> bitis;
	
	for(int i=baslangic; i<bitis; i++){
		// Okunacak dosyalrýn isimlerini belirliyoruz
		dosya_adi << "File" << i << ".txt";
		
		// dosyada_ara fonksiyonuna parametrelerini gönderiyoruz
		dosyada_ara(dosya_adi.str().c_str(),aranacak_kelime);
		
		dosya_adi.str("");
	}

	system("PAUSE");
	return 0;
}

void dosyada_ara(string dosya_adi, string aranacak_kelime){
	// Dosyadan okuma yapmak için
	ifstream in;
	
	// Dosyadan okunan kelimedir
	string kelime;
	
	in.open(dosya_adi.c_str());
	
	// Eðer dosya açýlamadýysa
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

