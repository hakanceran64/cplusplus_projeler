/*
 * Author: Hakan Ceran
 * Date: 26.08.2017
 * Content: Kullanýcýnýn kaç tane sayý gireceði alýnacak, sonra bu kadar sayýda kullanýcýdan sayý istenecek ve ekrana kullanýcýnýn girdiði sayýlar arasýndan en büyük olaný yazýlacaktýr.
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
