// !!!!! Bu program yazýlmamýþtýr.


/*
 * Author: Hakan Ceran
 * Date: 19.09.2017
 * Content: Bir dijital saat uygulamasý yapýnýz. Uygulama açýlýr açýlmaz tarhi ve saat ekrana yazdýrýlsýn.
 *			Ýçerisinde saliseyi de hesaplayan kronometre olsun.
 *			istendiði zaman tarih ve saat tekrar ekrana yazýlsýn.
 */

#include <iostream> // cin, cout vs.
#include <clocale> // Türkçe karakterler
#include <windows.h> // Arkaplan ve yazý rengi

using namespace std; // std::

int main(){
	setlocale(LC_ALL, "turkish"); // Türkçe Karakterleri Ekliyoruz
	system("color f9"); // Arkaplan ve yazý rengi

	system("PAUSE");
	return 0;
}


