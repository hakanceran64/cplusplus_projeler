/*
 * Author: Hakan Ceran
 * Date: 22.09.2017
 * Content: Elimizde birden fazla kelime içeren bir text dosyasý olduðu varsayýlsýn.
 *			Bu text dosyasýnda bulunan kelimeler ile kullanýcýnýn girdiði kelimenin benzerlik oranýný bulan program kodlarýný yazýnýz.
 *			Örnek: Dosyada kalem ve alem kelimesi olsun, kullanýcý kalem kelimelerini girsin.
 *			kelam - kalem %100 benzerlik
 *			kelam - alem %80 benzerlik
 *			NOT: Bir harfin birden fazla geçmesi durumunda benzerlik %100'den fazla çýkabilir bu durumu göz ardý ediniz.
 */

#include <iostream> // cin, cout vs.
#include <clocale> // Türkçe karakterler
#include <windows.h> // Arkaplan ve yazý rengi
#include <fstream>
#include <string>

using namespace std; // std::

int main(){
	setlocale(LC_ALL, "turkish"); // Türkçe Karakterleri Ekliyoruz
	system("color f9"); // Arkaplan ve yazý rengi
	
	// Dosyada bulunan kelimeleri al oku ve harf harf kontrol et
	string line;
	
	ifstream dosya("kelimeler.txt");
	char kelime[100];
	
	cout << "Kelime giriniz: ";
	// Uzunluðu maksimum 100 olan bir satýr al
	cin.get(kelime,100);
	
	// Eðer kelimenin içerisinde bir harf birden fazla tekrar ediyorsa sonuç hatalý çýkacaktýr bu problemin çözümü okuyucuya býraklýmýþtýr.
	
	// Dosya var ise
	if(dosya.is_open()){
		// Satýr boþ deðilse
		while(getline(dosya, line)){
			// Yüzde hesaplanmasý için karþýlaþtýrma yapýlan kelimelerden uzun olanýna göre karþýlaþtýrma yapýlýr.
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
			
			cout << kelime << " - " << line << " arasýndaki benzerlik oraný: %" << (benzer_harf*100)/(en_uzun_kelimenin_harf_sayisi) << endl;
		}
		
		dosya.close();		
	} else{
		cout << "Dosya bulunamadý!" << endl;
	}

	system("PAUSE");
	return 0;
}


