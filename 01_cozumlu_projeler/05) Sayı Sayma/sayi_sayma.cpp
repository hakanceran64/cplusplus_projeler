/*
 * Author: Hakan Ceran
 * Date: 25.08.2017
 * Content: Kullan�c�dan al�nan say�ya kadar ekranda say�lar� yazan program� yaz�n�z. while d�ng�s� kullan�lacakt�r.
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

