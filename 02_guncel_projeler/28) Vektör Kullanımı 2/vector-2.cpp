/*
 * Author: Hakan Ceran
 * Date: 24.09.2017
 * Content: Bir önceki soruda olduðu gibi bir vektör kullanarak, sonsuz bir dizi oluþturmaya müsait bir yapý kurunuz.
 *			Kullanýcýnýn vektörden istediði indeksteki elemaný silebilmesini saðlayýnýz.
 */

#include <iostream> // cin, cout vs.
#include <clocale> // Türkçe karakterler
#include <windows.h> // Arkaplan ve yazý rengi
#include <vector>

using namespace std; // std::

int main(){
	setlocale(LC_ALL, "turkish"); // Türkçe Karakterleri Ekliyoruz
	system("color f9"); // Arkaplan ve yazý rengi
	
	vector<int> v;
	int sayi=0, index=0;
	
	cout << "Vektöre sayý giriniz çýkmak için -1 giriniz: ";
	while(sayi!=-1){
		cin >> sayi;
		
		if(sayi!=-1)
			v.push_back(sayi);
	}
	
	for(vector<int>::iterator ite=v.begin(); ite!=v.end(); ite++){
		cout << *ite << "\t";
	}
	cout << endl;
	
	cout << "Silmek istediðiniz index'i giriniz. Silmeyi tamamlamak için -1 giriniz: ";
	while(index!=-1){
		cout << endl;
		cin >> index;
		
		if(index!=-1)
			v.erase(v.begin()+index); // Silme iþlemi yapýlýyor.
		
		for(vector<int>::iterator ite=v.begin(); ite!=v.end(); ite++){
			cout << *ite << "\t";
		}
		cout << endl;
	}	
	cout << endl;

	system("PAUSE");
	return 0;
}


