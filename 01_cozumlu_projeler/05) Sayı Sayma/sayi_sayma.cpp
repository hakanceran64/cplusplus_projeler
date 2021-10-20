/*
 * Author: Hakan Ceran
 * Date: 25.08.2017
 * Content: Kullanýcýdan alýnan sayýya kadar ekranda sayýlarý yazan programý yazýnýz. while döngüsü kullanýlacaktýr.
 */

#include <iostream>

using namespace std;

int main(){
	
	int sayi;
	
	cout << "Kaca kadar saymami istersin: ";
	cin >> sayi;
	
	int i=1;
	
	while(i<=sayi){
		cout << i << "\t";
		++i;
	}
	
	cout << endl;

	system("PAUSE");
	return 0;
}

