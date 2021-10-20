/*
 * Author: Hakan Ceran
 * Date: 27.08.2017
 * Content: Kullanýcýnýn girdiði kelimeyi ters çevirerek ekrana yazýnýz.
 */

#include <iostream>

using namespace std;

int main(){
	
	char kelime[100], tmp;
	
	cout << "Bir kelime giriniz: ";
	cin >> kelime;
	
	int uzunluk;
	
	for(uzunluk=0; kelime[uzunluk]!='\0'; ++uzunluk);
	
	/* Kelimenin ortasýný belirle ve yer deðiþtir. */
	for(int i=0; i<(uzunluk/2); ++i){
		tmp=kelime[i];
		kelime[i]=kelime[uzunluk-i-1];
		kelime[uzunluk-i-1]=tmp;
	}
	
	cout << kelime << endl;

	system("PAUSE");
	return 0;
}

