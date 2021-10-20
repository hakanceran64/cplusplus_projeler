/*
 * Author: Hakan Ceran
 * Date: 25.08.2017
 * Content: Bir yolda seyir halinde olan otomobiller, kamyonetler ve otob�sler vard�r. Bir bilgisayar yard�m�yla bu ara�lar�n h�z limitlerine uyulup uyulmad��� kontrol edilmek isteniyor. H�z limitleri ��yledir: Otomobil:82, Otob�s:70, Kamyonet: 50. Kullan�c�dan arac�n t�r�n� ve h�z�n� al�n�z. Arac�n kurallara uygun olup olmad���n� kontrol ediniz.
 */

#include <iostream>

using namespace std;

int main(){
	
	int hiz;
	char tur;
	
	/*******************
		AZAM� HIZ
			Otomobil: 82
			Otob�s: 70
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

