/*
 * Author: Hakan Ceran
 * Date: 24.09.2017
 * Content: Bir Kisi adýnda yapý(struct) oluþturunuz. Deðiþkenleri int tipinde id ve string tipinde ad olmalýdýr.
 *			Sonsuz sayýda kiþi yapýsýnýn oluþturulabileceði bir kod yazmanýz istenmektedir.
 *			(Vektör kullanýmý ile iþlemi gerçekleþtirebilirsiniz.)
 */

#include <iostream> // cin, cout vs.
#include <clocale> // Türkçe karakterler
#include <windows.h> // Arkaplan ve yazý rengi
#include <vector>

using namespace std; // std::

struct Kisi{
	int id;
	string ad;
};

int main(){
	setlocale(LC_ALL, "turkish"); // Türkçe Karakterleri Ekliyoruz
	system("color f9"); // Arkaplan ve yazý rengi
	
	Kisi k;
	k.id=0;
	
	vector<Kisi> v;
	
	cout << "Vektöre id ve isim giriniz. Çýkmak için -1 giriniz: ";
	while(k.id!=-1){
		cin >> k.id;
		
		if(k.id!=-1){
			cin >> k.ad;
			v.push_back(k);
		}
	}
	
	// size komutunu kullanarak vector boyutunu öðrenebilirsiniz.
	for(vector<Kisi>::iterator ite=v.begin(); ite!=v.end(); ite++){
		cout << (*ite).ad << "\t";
	}
	
	cout << endl;

	system("PAUSE");
	return 0;
}


