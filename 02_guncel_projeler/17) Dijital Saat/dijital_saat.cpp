// !!!!! Bu program yaz�lmam��t�r.


/*
 * Author: Hakan Ceran
 * Date: 19.09.2017
 * Content: Bir dijital saat uygulamas� yap�n�z. Uygulama a��l�r a��lmaz tarhi ve saat ekrana yazd�r�ls�n.
 *			��erisinde saliseyi de hesaplayan kronometre olsun.
 *			istendi�i zaman tarih ve saat tekrar ekrana yaz�ls�n.
 */

#include <iostream> // cin, cout vs.
#include <clocale> // T�rk�e karakterler
#include <windows.h> // Arkaplan ve yaz� rengi

using namespace std; // std::

int main(){
	setlocale(LC_ALL, "turkish"); // T�rk�e Karakterleri Ekliyoruz
	system("color f9"); // Arkaplan ve yaz� rengi

	system("PAUSE");
	return 0;
}


