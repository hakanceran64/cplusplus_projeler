/*
 * Author: Hakan Ceran
 * Date: 12.09.2017
 * Content: Art�k y�llar� bulan bir program yazman�z istenmektedir. Bu kapsamda, gelecekteki ve ge�mi�teki art�k y�llar� bulan bir program.
 *			Temel kural: Bir y�l 4'�n tam kat� ise bu y�l art�k y�ld�r.
 *			�stisna: 100'�n tam kat� olan y�llardan sadece 400'�n tam kar� olan y�llar art�k y�ld�r.
 */

#include <iostream>
#include <time.h>

using namespace std;

void gelecek_artik_yillar(int year);
void gecmis_artik_yillar(int year);

int main(){
	time_t now=time(0);
	
	// Local time al�n�yor tm k�t�phanenin struct'�d�r.
	tm *ltm=localtime(&now);
	
	// Bu y�l� sistemden ald���m�z bilgilere g�re buluyoruz.
	int year = 1900+ltm->tm_year;
	
	cout << "Bu yil: " << year << endl;
	gecmis_artik_yillar(year);
	gelecek_artik_yillar(year);

	system("PAUSE");
	return 0;
}

void gelecek_artik_yillar(int year){
	cout << "\nGelecek artik yillar" << endl;
	for(int i=year; i<year+1000; i++){
		if(i%4==0 && i%100!=0 || i%400==0){
			cout << i << "\t";
		}
	}
}

void gecmis_artik_yillar(int year){
	cout << "\nGecmis artik yillar" << endl;
	for(int i=year; i>0; --i)
		if(i%4==0 && i%100!=0 || i%400==0)
			cout << i << "\t";
}
