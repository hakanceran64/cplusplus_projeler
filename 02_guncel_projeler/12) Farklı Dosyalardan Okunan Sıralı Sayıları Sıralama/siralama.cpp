// ####!!!!! BAZEN SA�MALIYOR.

/*
 * Author: Hakan Ceran
 * Date: 16.09.2017
 * Content: Birdn fazla dosyada s�ral� olarak say�lar tutulmaktad�r.
 *			Bu projede, s�ral� olarak tutulan ilgili say�lar� dosyalardan okuyup s�ralad�ktan sonra tek bir dosyaya yazman�z istenmektedir.
 *			Birden fazla dosya olabilir ve kullan�c� istedi�i aral�ktaki dosyalar� birle�tirip s�ralamak istiyor olabilir.
 *			�rne�in: File1, File2, File3 ve File4 olsun. Kullan�c�n�n sadece File1 ve File2'yi birle�tirmek istedi�i seneryoda a�a��daki �ekilde bir i�lem yap�lmas� istenmektedir. (Dosyalar ard���k s�rada olmal�d�r.)
 *					 Dosya1: 1 5 7 8 8 9
 *					 Dosya2: 1 2 3 11 13
 *					 SonucDosyas�: 1 1 2 3 5 7 8 8 9 11 13
 */

#include <iostream>
#include <fstream>
#include <sstream>


using namespace std;

// !!! txt dosyalar�n�n isimleri file1 file2 file3 gibi olmal�d�r

void sirala(int sayi_dizisi[]);
void yazdir(int sayi_dizisi[]);

int main(){
	
	ifstream files;
	// stringstream Stream s�n�f�n�n bir objesidir. S�ral� karakter i�erir
	stringstream filename;
	
	int sayi_dizisi[1000];
	
	// Okunacak dosya aral���n� belirlemek i�in 
	int baslangic=0, bitis=0;
	
	cout << "Birlestirilecek dosya araligini giriniz:" << endl;
	cin >> baslangic >> bitis;
	
	// Dosyadan say�lar� okuyup diziye atabilmek i�in
	int j=0;
	
	for(int i=baslangic; i<bitis; i++){
		// Okunacak dosyalar�n isminibelirliyoruz
		filename << "File" << i << ".txt";
		files.open(filename.str().c_str());
		
		// Dosya a��ld�ysa
		if(files.is_open()){
			while(!files.eof()){
				files >> sayi_dizisi[j];
				j++;
			}
			j--;
		} else {
			cout << filename.str().c_str() << " bulunamadi" << endl;
		}
		
		// Okunacak dosya ad� her defas�nda eklenmesin (apend i�lemi) diye i�eri�i temizlenmektedir. Temizlenmeseydi ikinci dosya ad� ile birinci dosya ad� birle�tirilip bir dosya ad�ym�� gibi kullan�lacakt� ve dosya olmad��� i�i de hata olu�acakt�.
		filename.str("");
		files.close();
	}
	
	// Dosyalardan okunan say�lar� bir diziye al�p, orada tekrar s�ralayan fonksiyondur.
	sirala(sayi_dizisi);
	
	// Siralanmis sayilar ekrana yazdiran fonksiyondur.
	yazdir(sayi_dizisi);

	system("PAUSE");
	return 0;
}

void sirala(int sayi_dizisi[]){
	int temp;
	
	for(int i=0; sayi_dizisi[i]!='\0'; i++){
		for(int j=0; j<i; j++){
			if(sayi_dizisi[i]<sayi_dizisi[j]){
				temp=sayi_dizisi[i];
				sayi_dizisi[i]=sayi_dizisi[j];
				sayi_dizisi[j]=temp;
			}
		}
	}
}

void yazdir(int sayi_dizisi[]){
	ofstream yaz;
	yaz.open("siralanmis_dizi.txt");
	cout << "Sayilarin siralanmis hali: " << endl;
	
	for(int i=0; sayi_dizisi[i]!='\0'; i++){
		cout << sayi_dizisi[i] << "\t";
		yaz << sayi_dizisi[i] << "\t";
	}
	
	cout << endl << endl;
	
	yaz.close();
}

