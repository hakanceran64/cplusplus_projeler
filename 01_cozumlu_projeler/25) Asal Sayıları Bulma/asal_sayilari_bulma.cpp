/*
 * Author: Hakan Ceran
 * Date: 27.08.2017
 * Content: Kullan�c�n�n girdi�i de�ere kadar olan b�t�n asal say�lar� hesaplay�n�z.
 */

#include <iostream>

using namespace std;

/* int tipinde say� al ve bool(true/false) bir de�er d�nd�r. */
bool asal_mi(int x){
	for(int i=2; i<x/2; ++i){
		if(x%i==0){ // E�er tam b�leni varsa asal de�ildir.
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

