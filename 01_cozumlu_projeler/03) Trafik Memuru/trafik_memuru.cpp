/*
 * Author: Hakan Ceran
 * Date: 25.08.2017
 * Content: Bir yolda seyir halinde olan otomobiller, kamyonetler ve otobüsler vardýr. Bir bilgisayar yardýmýyla bu araçlarýn hýz limitlerine uyulup uyulmadýðý kontrol edilmek isteniyor. Hýz limitleri þöyledir: Otomobil:82, Otobüs:70, Kamyonet: 50. Kullanýcýdan aracýn türünü ve hýzýný alýnýz. Aracýn kurallara uygun olup olmadýðýný kontrol ediniz.
 */

#include <iostream>

using namespace std;

int main(){
	
	int hiz;
	char tur;
	
	/*******************
		AZAMÝ HIZ
			Otomobil: 82
			Otobüs: 70
			Kamyonet: 50
	 ******************/
	
	cout << "Aracin turunu giriniz: (Otomobil:o, otobus:t, kamyonet:k) ";
	cin >> tur;
	
	cout << "Aracin hizini giriniz: ";
	cin >> hiz;
	
	if(tur=='o'){
		cout << "Arac otomobildir." << endl;
		if(hiz>82)
			cout << "Arac cezalidir." << endl;
		else
			cout << "Kurallara uygundur." << endl;
	} else if(tur=='t'){
		cout << "Arac otobustur." << endl;
		if(hiz>70)
			cout << "Arac cezalidir." << endl;
		else
			cout << "Kurallara uygundur." << endl;
	} else if(tur=='k'){
		cout << "Arac kamyonettir." << endl;
		if(hiz>50)
			cout << "Arac cezalidir." << endl;
		else
			cout << "Kurallara uygundur." << endl;
	} else
		cout << "Arac turunu yanlis girildi!" << endl;
		
	system("PAUSE");
	return 0;
}

