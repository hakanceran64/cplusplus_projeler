/*
 * Author: Hakan Ceran
 * Date: 24.09.2017
 * Content: �n Bilgiler:
 *			- Vekt�r uzunlu�u olmayan bir dizi gibi �al���r.
 *			- Vect�r'e yeni eleman eklemek i�in push_back() metodu kullan�l�r.
 *			- Vect�r'�n i�erisinde o anda ka� eleman oldu�unu size() metodu ile ��renilebilir.
 *			- Vect�r'�n her bir eleman�na, bir dizinin her bir eleman�na eri�iyor gibi, [] parantezleri kullan�larak eri�ilir.
 *			- Ayr�nt�l� bilgi i�in: http://www.cplusplus.com/reference/vector/vector/ adresini ziyaret edebilirsiniz.
 *
 *			Bu projede istenen vect�r kullanarak, kullan�c�n�n istedi�i kadar say� almas�n� ve vekt�re al�nan say�lar�n ekrana yaz�lmas�d�r.
 *			Kullan�c� istedi�i kadar say� girebilir. -1 numaras�n�n girildi�i ekrana vekt�r i�erisindeki say�lar�n yaz�lmas�n� sa�lay�n�z.
 */

#include <iostream> // cin, cout vs.
#include <clocale> // T�rk�e karakterler
#include <windows.h> // Arkaplan ve yaz� rengi
#include <vector>

using namespace std; // std::

int main(){
	setlocale(LC_ALL, "turkish"); // T�rk�e Karakterleri Ekliyoruz
	system("color f9"); // Arkaplan ve yaz� rengi
	
	vector<int> v;
	int sayi=0;
	
	cout << "Vekt�r'e say� giriniz ��kmak i�in -1 giriniz: ";
	
	// Say�lar vekt�re bu �ekilde at�l�r. Vekt�r uzunlu�u olmayan bir dizi gibi d���n�lebilir.
	while(sayi!=-1){
		cin >> sayi;
		
		if(sayi==-1) // -1'i vekt�re kaydetmesin.
			break;
		
		v.push_back(sayi);
	}
	
	// Vekt�r�n ba�lang�c�ndan sonuna kadar t�m elemanlar� yazd�rmay� sa�layan d�ng�
	for(vector<int>::iterator ite=v.begin(); ite!=v.end(); ite++){
		cout << *ite << "\t";
	}
	
	cout << endl;

	system("PAUSE");
	return 0;
}


