/*
 * Author: Hakan Ceran
 * Date: 26.08.2017
 * Content: Kullan�c�dan ka� tane say� girece�i al�nacak, sonra bu kadar say� kullan�c�dan istenecek ve ekrana kullan�c�n�n girdi�i say�lar�n ortalamas� hesaplanarak virg�lden sonra iki basamak olacak �ekilde ekrana yaz�lacakt�r.
 */

#include <iostream>
#include <iomanip>

using namespace std;

float ortalama_hesapla(int n);

int main(){
	
	int n;
	
	cout << "Kac sayi gireceksiniz: ";
	cin >> n;
	
	cout << fixed << setprecision(2) << "Girilen sayilarin ortalamasi: " << ortalama_hesapla(n) << endl;
	
	system("PAUSE");
	return 0;
}

float ortalama_hesapla(int n){
	int sayi;
	float toplam=0;
	
	cout << "Sayilari giriniz: " << endl;
	for(int i=0; i<n; ++i){
		cin >> sayi;
		toplam+=sayi;
	}
	return toplam/n;
}
