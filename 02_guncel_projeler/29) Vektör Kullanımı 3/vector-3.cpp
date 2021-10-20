/*
 * Author: Hakan Ceran
 * Date: 24.09.2017
 * Content: Bir Kisi ad�nda yap�(struct) olu�turunuz. De�i�kenleri int tipinde id ve string tipinde ad olmal�d�r.
 *			Sonsuz say�da ki�i yap�s�n�n olu�turulabilece�i bir kod yazman�z istenmektedir.
 *			(Vekt�r kullan�m� ile i�lemi ger�ekle�tirebilirsiniz.)
 */

#include <iostream> // cin, cout vs.
#include <clocale> // T�rk�e karakterler
#include <windows.h> // Arkaplan ve yaz� rengi
#include <vector>

using namespace std; // std::

struct Kisi{
	int id;
	string ad;
};

int main(){
	setlocale(LC_ALL, "turkish"); // T�rk�e Karakterleri Ekliyoruz
	system("color f9"); // Arkaplan ve yaz� rengi
	
	Kisi k;
	k.id=0;
	
	vector<Kisi> v;
	
	cout << "Vekt�re id ve isim giriniz. ��kmak i�in -1 giriniz: ";
	while(k.id!=-1){
		cin >> k.id;
		
		if(k.id!=-1){
			cin >> k.ad;
			v.push_back(k);
		}
	}
	
	// size komutunu kullanarak vector boyutunu ��renebilirsiniz.
	for(vector<Kisi>::iterator ite=v.begin(); ite!=v.end(); ite++){
		cout << (*ite).ad << "\t";
	}
	
	cout << endl;

	system("PAUSE");
	return 0;
}


