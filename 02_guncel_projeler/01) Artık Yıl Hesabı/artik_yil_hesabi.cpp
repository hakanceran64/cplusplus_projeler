/*
 * Author: Hakan Ceran
 * Date: 12.09.2017
 * Content: Artýk yýllarý bulan bir program yazmanýz istenmektedir. Bu kapsamda, gelecekteki ve geçmiþteki artýk yýllarý bulan bir program.
 *			Temel kural: Bir yýl 4'ün tam katý ise bu yýl artýk yýldýr.
 *			Ýstisna: 100'ün tam katý olan yýllardan sadece 400'ün tam karý olan yýllar artýk yýldýr.
 */

#include <iostream>
#include <time.h>

using namespace std;

void gelecek_artik_yillar(int year);
void gecmis_artik_yillar(int year);

int main(){
	time_t now=time(0);
	
	// Local time alýnýyor tm kütüphanenin struct'ýdýr.
	tm *ltm=localtime(&now);
	
	// Bu yýlý sistemden aldýðýmýz bilgilere göre buluyoruz.
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
