/*
 * Author: Hakan Ceran
 * Date: 26.08.2017
 * Content: Kullan�c�n�n ka� tane say� girece�i al�nacak, sonra bu kadar say�da kullan�c�dan say� istenecek ve ekrana kullan�c�n�n girdi�i say�lar aras�ndan en b�y�k olan� yaz�lacakt�r.
 */

#include <iostream>

using namespace std;

int en_buyuk_sayi(int n);

int main(){
	
	int n;
	
	cout << "Kac sayi gireceksiniz: ";
	cin >> n;
	
	cout << "Girilen sayilar arasinda en buyugu: " << en_buyuk_sayi(n) << endl;

	system("PAUSE");
	return 0;
}

int en_buyuk_sayi(int n){
	int enBuyuk=0;
	int sayi;
	
	cout << "Sayilari giriniz: ";
	for(int i=0; i<n; ++i){
		cin>>sayi;
		if(sayi>enBuyuk)
			enBuyuk=sayi;
	}
	return enBuyuk;
}
