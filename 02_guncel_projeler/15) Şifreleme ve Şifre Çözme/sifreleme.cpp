/*
 * Author: Hakan Ceran
 * Date: 17.09.2017
 * Content: Bu projede Cesar �ifrelemeye benzer bir bi�imde �ifreleme yapan bir uygulama yazman�z istenmektedir.
 *			Fakat her bir harf i�in farkl� say�da kayd�rma yap�lmal�d�r, bunun i�in pi say�s� kullan�lmal�d�r.
 *			Bir ba�ka ifade ile virg�lden sonraki ilk basamak ilk harfi �ifrelemek i�in, ikinci basamak 2. harfi �ifrelemek i�in vb. kullan�lmaktad�r.
 *			�rne�in: 3.141... �eklinde devam eden pi say�s�na g�re abc kelimesini �ifreleyelim. �ifrelenmi� kelime be� olacakt�r.
 */

#include <iostream>
#include <iomanip>
#include <clocale> // T�rk�e karakterler i�in
#include <windows.h> // Konsol ekran� renkleri

using namespace std;

// Bu fonksiyon karakteri say�ya �evirmek i�in kullan�lmaktad�r.
int donustur(char a){
	switch(a){
		case '0':
			return 0;
		case '1':
			return 1;
		case '2':
			return 2;
		case '3':
			return 3;
		case '4':
			return 4;
		case '5':
			return 5;
		case '6':
			return 6;
		case '7':
			return 7;
		case '8':
			return 8;
		case '9':
			return 9;
	}
}
int main(){
	setlocale(LC_ALL, "turkish"); // T�rk�e Karakterleri Ekliyoruz
	system("color f9");
	
	// pi say�s�n�n virg�lden sonraki k�sm�
	char pi[135]="14159265358979323846264338327950288419716939937510582097494459230781640628620899862803482534211706798214808651328230664709384460955058";
	char kelime[135]; // Alaca��m�z karakterler
	int secim;
	
	cout << "Kelimeyi giriniz: ";
	// cin bo�luga kadar girdi al�rken cin.getlinesat�r� tamamen al�r.
	cin.getline(kelime,135);
	
	a: // Yanl�� giri�te buraya geri d�nmeni istedik
	cout << "�ifrelemek i�in 1'e �ifre ��zmek i�in 2'ye bas�n�z: ";
	cin >> secim;
	
	if(secim==1){
		for(int i=0; kelime[i]!='\0'; i++){
			kelime[i]=kelime[i]+donustur(pi[i]);
		}
		cout << "�ifrelenmi� veri: ";
	} else if(secim==2){
		for(int i=0; kelime[i]!='\0'; i++){
			kelime[i]=kelime[i]-donustur(pi[i]);
		}
		cout << "�ifresi ��z�lm�� veri: ";
	} else {
		cout << "Hatal� giri� yapt�n�z." << endl;
		goto a;
	}
	
	cout << kelime << endl;
	
	system("PAUSE");
	return 0;
}

