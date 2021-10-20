/*
 * Author: Hakan Ceran
 * Date: 27.08.2017
 * Content: Kullanýcýnýn girdiði deðere kadar olan bütün asal sayýlarý hesaplayýnýz.
 */

#include <iostream>

using namespace std;

/* int tipinde sayý al ve bool(true/false) bir deðer döndür. */
bool asal_mi(int x){
	for(int i=2; i<x/2; ++i){
		if(x%i==0){ // Eðer tam böleni varsa asal deðildir.
			return false;
		}
	}
	return true;
}

int main(){
	
	int n;
	
	cin >> n;
	
	cout << "Asallar: ";
	for(int i=2; i<=n; ++i){
		if(asal_mi(i))
			cout << i << " ";
	}
	
	cout << endl;

	system("PAUSE");
	return 0;
}

