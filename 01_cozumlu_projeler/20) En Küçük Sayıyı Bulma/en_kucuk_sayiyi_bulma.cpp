/*
 * Author: Hakan Ceran
 * Date: 26.08.2017
 * Content: En küçük sayýyý bulma
 */

#include <iostream>

using namespace std;

int en_kucuk_sayi(int n);

int main(){
	
	int n;
	
	cout << "Kac sayi gireceksiniz: ";
	cin >> n;
	
	cout << "Girilen sayilar arasinda en kucugu: " << en_kucuk_sayi(n) << endl;

	system("PAUSE");
	return 0;
}

int en_kucuk_sayi(int n){
	int enKucuk=1000000;
	int sayi;
	
	cout << "Sayilari giriniz: ";
	for(int i=0; i<n; ++i){
		cin >> sayi;
		if(sayi<enKucuk)
			enKucuk=sayi;
	}
	return enKucuk;
}
