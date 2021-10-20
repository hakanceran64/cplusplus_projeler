/*
 * Author: Hakan Ceran
 * Date: 24.09.2017
 * Content: Bir �nceki soruda oldu�u gibi bir vekt�r kullanarak, sonsuz bir dizi olu�turmaya m�sait bir yap� kurunuz.
 *			Kullan�c�n�n vekt�rden istedi�i indeksteki eleman� silebilmesini sa�lay�n�z.
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
	int sayi=0, index=0;
	
	cout << "Vekt�re say� giriniz ��kmak i�in -1 giriniz: ";
	while(sayi!=-1){
		cin >> sayi;
		
		if(sayi!=-1)
			v.push_back(sayi);
	}
	
	for(vector<int>::iterator ite=v.begin(); ite!=v.end(); ite++){
		cout << *ite << "\t";
	}
	cout << endl;
	
	cout << "Silmek istedi�iniz index'i giriniz. Silmeyi tamamlamak i�in -1 giriniz: ";
	while(index!=-1){
		cout << endl;
		cin >> index;
		
		if(index!=-1)
			v.erase(v.begin()+index); // Silme i�lemi yap�l�yor.
		
		for(vector<int>::iterator ite=v.begin(); ite!=v.end(); ite++){
			cout << *ite << "\t";
		}
		cout << endl;
	}	
	cout << endl;

	system("PAUSE");
	return 0;
}


