// ####!!!!! BAZEN SAÇMALIYOR.

/*
 * Author: Hakan Ceran
 * Date: 16.09.2017
 * Content: Birdn fazla dosyada sýralý olarak sayýlar tutulmaktadýr.
 *			Bu projede, sýralý olarak tutulan ilgili sayýlarý dosyalardan okuyup sýraladýktan sonra tek bir dosyaya yazmanýz istenmektedir.
 *			Birden fazla dosya olabilir ve kullanýcý istediði aralýktaki dosyalarý birleþtirip sýralamak istiyor olabilir.
 *			Örneðin: File1, File2, File3 ve File4 olsun. Kullanýcýnýn sadece File1 ve File2'yi birleþtirmek istediði seneryoda aþaðýdaki þekilde bir iþlem yapýlmasý istenmektedir. (Dosyalar ardýþýk sýrada olmalýdýr.)
 *					 Dosya1: 1 5 7 8 8 9
 *					 Dosya2: 1 2 3 11 13
 *					 SonucDosyasý: 1 1 2 3 5 7 8 8 9 11 13
 */

#include <iostream>
#include <fstream>
#include <sstream>


using namespace std;

// !!! txt dosyalarýnýn isimleri file1 file2 file3 gibi olmalýdýr

void sirala(int sayi_dizisi[]);
void yazdir(int sayi_dizisi[]);

int main(){
	
	ifstream files;
	// stringstream Stream sýnýfýnýn bir objesidir. Sýralý karakter içerir
	stringstream filename;
	
	int sayi_dizisi[1000];
	
	// Okunacak dosya aralýðýný belirlemek için 
	int baslangic=0, bitis=0;
	
	cout << "Birlestirilecek dosya araligini giriniz:" << endl;
	cin >> baslangic >> bitis;
	
	// Dosyadan sayýlarý okuyup diziye atabilmek için
	int j=0;
	
	for(int i=baslangic; i<bitis; i++){
		// Okunacak dosyalarýn isminibelirliyoruz
		filename << "File" << i << ".txt";
		files.open(filename.str().c_str());
		
		// Dosya açýldýysa
		if(files.is_open()){
			while(!files.eof()){
				files >> sayi_dizisi[j];
				j++;
			}
			j--;
		} else {
			cout << filename.str().c_str() << " bulunamadi" << endl;
		}
		
		// Okunacak dosya adý her defasýnda eklenmesin (apend iþlemi) diye içeriði temizlenmektedir. Temizlenmeseydi ikinci dosya adý ile birinci dosya adý birleþtirilip bir dosya adýymýþ gibi kullanýlacaktý ve dosya olmadýðý içi de hata oluþacaktý.
		filename.str("");
		files.close();
	}
	
	// Dosyalardan okunan sayýlarý bir diziye alýp, orada tekrar sýralayan fonksiyondur.
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

