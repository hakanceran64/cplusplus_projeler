/*
 * Author: Hakan Ceran
 * Date: 22.09.2017
 * Content: Elimizde birden fazla kelime i�eren bir text dosyas� oldu�u varsay�ls�n.
 *			Bu text dosyas�nda bulunan kelimeler ile kullan�c�n�n girdi�i kelimenin benzerlik oran�n� bulan program kodlar�n� yaz�n�z.
 *			�rnek: Dosyada kalem ve alem kelimesi olsun, kullan�c� kalem kelimelerini girsin.
 *			kelam - kalem %100 benzerlik
 *			kelam - alem %80 benzerlik
 *			NOT: Bir harfin birden fazla ge�mesi durumunda benzerlik %100'den fazla ��kabilir bu durumu g�z ard� ediniz.
 */

#include <iostream> // cin, cout vs.
#include <clocale> // T�rk�e karakterler
#include <windows.h> // Arkaplan ve yaz� rengi
#include <fstream>
#include <string>

using namespace std; // std::

int main(){
	setlocale(LC_ALL, "turkish"); // T�rk�e Karakterleri Ekliyoruz
	system("color f9"); // Arkaplan ve yaz� rengi
	
	// Dosyada bulunan kelimeleri al oku ve harf harf kontrol et
	string line;
	
	ifstream dosya("kelimeler.txt");
	char kelime[100];
	
	cout << "Kelime giriniz: ";
	// Uzunlu�u maksimum 100 olan bir sat�r al
	cin.get(kelime,100);
	
	// E�er kelimenin i�erisinde bir harf birden fazla tekrar ediyorsa sonu� hatal� ��kacakt�r bu problemin ��z�m� okuyucuya b�rakl�m��t�r.
	
	// Dosya var ise
	if(dosya.is_open()){
		// Sat�r bo� de�ilse
		while(getline(dosya, line)){
			// Y�zde hesaplanmas� i�in kar��la�t�rma yap�lan kelimelerden uzun olan�na g�re kar��la�t�rma yap�l�r.
			int benzer_harf=0;
			int en_uzun_kelimenin_harf_sayisi=0;
			
			for(int i=0; kelime[i]!='\0'; i++){
				for(int j=0; line[j]!='\0'; j++){
					if(line[j]==kelime[i]){
						benzer_harf++;
					}
					
					if(j<i){
						en_uzun_kelimenin_harf_sayisi=i+1;
					}
					
					if(i<j){
						en_uzun_kelimenin_harf_sayisi=j+1;
					}
				}
			}
			
			cout << kelime << " - " << line << " aras�ndaki benzerlik oran�: %" << (benzer_harf*100)/(en_uzun_kelimenin_harf_sayisi) << endl;
		}
		
		dosya.close();		
	} else{
		cout << "Dosya bulunamad�!" << endl;
	}

	system("PAUSE");
	return 0;
}


