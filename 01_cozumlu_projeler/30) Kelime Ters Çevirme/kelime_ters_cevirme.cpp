/*
 * Author: Hakan Ceran
 * Date: 27.08.2017
 * Content: Kullan�c�n�n girdi�i kelimeyi ters �evirerek ekrana yaz�n�z.
 */

#include <iostream>

using namespace std;

int main(){
	
	char kelime[100], tmp;
	
	cout << "Bir kelime giriniz: ";
	cin >> kelime;
	
	int uzunluk;
	
	for(uzunluk=0; kelime[uzunluk]!='\0'; ++uzunluk);
	
	/* Kelimenin ortas�n� belirle ve yer de�i�tir. */
	for(int i=0; i<(uzunluk/2); ++i){
		tmp=kelime[i];
		kelime[i]=kelime[uzunluk-i-1];
		kelime[uzunluk-i-1]=tmp;
	}
	
	cout << kelime << endl;

	system("PAUSE");
	return 0;
}

