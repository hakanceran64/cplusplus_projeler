/*
 * Author: Hakan Ceran
 * Date: 06.09.2017
 * Content: Girdi olarak girilen bir zamana yine girilen kadar saat, dakika ve saniye ekleyen ve son zamanı ekrana yazan program kodlarını, aşağıda detayları verilen yapılar ve fonksiyonları kullanarak çözünüz.
 *			- dijital_saat yapisi: Bir saatin saat, dakika ve saniye bilgilerini saklayabilen bir yapı.
 *			- saat_yaz(): Parametre olarak verilen bir dijital_saat yapısı işaretçisini istenilen formatta ekrana yazan fonksiyondur. Format:HH:DD:SS
 *			- saat_ekle(): Parametre olarak gelen bir dijital_saat yapısı işaretçisine yine parametre olarak gelen saat kadar saat ekleyen fonksiyondur.
 *			- dakika_ekle(): Parametre olarak gelen bir dijital_saat yapısı işaretçisine yine parametre olarak gelen dakika kadar dakika ekleyen fonksiyondur.
 *			- saniye_ekle(): Parametre olarak gelen bir dijital_saat yapısı işaretçisine yine parametre olarak gelen saniye kadar saniye ekleyen fonksiyondur.
 */

#include <iostream>
#include <cmath>

using namespace std;

struct dijital_saat{
	int saat;
	int dakika;
	int saniye;
};

void saat_yaz(struct dijital_saat *diji){
	cout << (diji->saat < 10 ? "0":"");
	cout << diji->saat << ":";

	cout << (diji->dakika < 10 ? "0":"");
	cout << diji->dakika << ":";

	cout << (diji->saniye < 10 ? "0":"");
	cout << diji->saniye << endl;
}

void saat_ekle(struct dijital_saat *diji, int saat){
	diji->saat+=saat;
	diji->saat%=24;
}

void dakika_ekle(struct dijital_saat *diji, int dakika){
	diji->dakika+=dakika;
	int saat=diji->dakika/60;
	diji->dakika%=60;
	saat_ekle(diji,saat);
}

void saniye_ekle(struct dijital_saat *diji, int saniye){
	diji->saniye+=saniye;
	int dakika=diji->saniye/60;
	diji->saniye%=60;
	dakika_ekle(diji,dakika);
}

int main(){
	
	struct dijital_saat d;
	
	int saat, dakika, saniye;
	char x;

	cout << "Saati giriniz: ";
	cin >> d.saat >> x >> d.dakika >> x >> d.saniye;
	
	cout << "Eklenecek zamani giriniz: ";
	cin >> saat >> dakika >> saniye;
	
	saat_ekle(&d,saat);
	dakika_ekle(&d,dakika);
	saniye_ekle(&d,saniye);
	
	saat_yaz(&d);

	system("PAUSE");
	return 0;
}

