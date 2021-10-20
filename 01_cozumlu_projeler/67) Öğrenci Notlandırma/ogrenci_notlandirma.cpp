/*
 * Author: Hakan Ceran
 * Date: 07.09.2017
 * Content: Girdi olarak verilen n (maks.1000) tane ��rencinin bilgilerinden ��rencinin ortalamas�n�, harf notunu hesaplayan ve ��rencileri ortalamas�na g�re b�y�kten k����e do�ru s�ralayan program�, istenilen yap� ve fonksiyonlar� kodlayarak ��z�n�z.
 *			��renci yap�s�: Bir ��rencinin ad�n�, soyad�n�, quiz, vize, ve final notunu, ortalamas�n� ve harf notunu saklayabilen bir yap�d�r (Ad ve soyad maksimum 10 karakterdir.)
 *			ortalama_hesapla(): Parametre olarak gelen ogrenciler dizisini ve bu dizinin uzunlu�unu kullanarak her bir ��rencinin ortalamas�n� hesaplayan fonksiyondur.
 *								Ortalama �u �ekilde hesaplan�r: ortlama=%20quiz + %30vize + %50final
 *			harf_notu_hesapla(): Parametre olarak gelen ogrenciler dizisini ve bu dizinin uzunlu�unu kullanarak her bir ��rencinin harf notunu hesaplayan fonksiyondur.
 *
 *
 *			Ortalama		Harf Notu
 *			>=90			AA
 *			>=80			BA
 *			>=70			BB
 *			>=60			CB
 *			>=50			CC
 *			>=40			DC
 *			>=30			DD
 *			<30				FF
 *
 *
 *			ortalamaya_gore_sirala(): Parametre olarak gelen ogrenciler dizisini ve bu dizinin uzunlugunu kullanarak, diziyi ��rencilerin ortalamalar�na g�re b�y�kten k����e do�ru s�ralayan bir fonksiyondur.
 *			NOT: S�ralama yaparken ayn� de�erleri yer de�i�tirmeyiniz.
 */

#include <iostream>
#include <iomanip>
#include <cstring>

#define MAX 100

using namespace std;

struct ogrenci{
	char ad[10];
	char soyad[10];
	double quiz_notu;
	double vize_notu;
	double final_notu;
	double ortalama;
	char harf_notu[3];
};

void ortalama_hesapla(struct ogrenci *ogrenciler, int n){
	for(int i=0; i<n; ++i)
		ogrenciler[i].ortalama=ogrenciler[i].quiz_notu*0.2+ogrenciler[i].vize_notu*0.3+ogrenciler[i].final_notu*0.5;
}

void harf_notu_hesapla(struct ogrenci *ogrenciler, int n){
	for(int i=0; i<n; ++i)
		if(ogrenciler[i].ortalama>=90)
			strncpy(ogrenciler[i].harf_notu,"AA",3);
		else if(ogrenciler[i].ortalama>=80)
			strncpy(ogrenciler[i].harf_notu,"BA",3);
		else if(ogrenciler[i].ortalama>=70)
			strncpy(ogrenciler[i].harf_notu,"BB",3);
		else if(ogrenciler[i].ortalama>=60)
			strncpy(ogrenciler[i].harf_notu,"CB",3);
		else if(ogrenciler[i].ortalama>=50)
			strncpy(ogrenciler[i].harf_notu,"CC",3);
		else if(ogrenciler[i].ortalama>=40)
			strncpy(ogrenciler[i].harf_notu,"DC",3);
		else if(ogrenciler[i].ortalama>=30)
			strncpy(ogrenciler[i].harf_notu,"DD",3);
		else
			strncpy(ogrenciler[i].harf_notu,"FF",3);
}

void ortalamaya_gore_sirala(struct ogrenci *ogrenciler, int n){
	struct ogrenci tmp;
	int ort1, ort2;
	for(int i=n-1; i>0; --i)
		for(int j=0; j<i; ++j){
			ort1=ogrenciler[j].ortalama*100;
			ort2=ogrenciler[j+1].ortalama*100;
			if(ort1<ort2){
				tmp=ogrenciler[j];
				ogrenciler[j]=ogrenciler[j+1];
				ogrenciler[j+1]=tmp;
			}
		}
}

int main(){
	
	struct ogrenci ogrenciler[MAX];
	int n;
	
	cout << "Bir n degeri giriniz: ";
	cin >> n;
	
	cout << endl << "Ad\tSoyad\tQuiz Notu\tVize Notu\tFinal Notu" << endl;
	for(int i=0; i<n; ++i)
		cin >> ogrenciler[i].ad >> ogrenciler[i].soyad >> ogrenciler[i].quiz_notu >> ogrenciler[i].vize_notu >> ogrenciler[i].final_notu;
	
	ortalama_hesapla(ogrenciler,n);
	harf_notu_hesapla(ogrenciler,n);
	ortalamaya_gore_sirala(ogrenciler,n);
	
	cout << endl << "Ogrenciler: " << endl;
	cout << fixed << setprecision(2);
	for(int i=0; i<n; ++i)
		cout << ogrenciler[i].ad << " " << ogrenciler[i].soyad << " " << ogrenciler[i].ortalama << " " << ogrenciler[i].harf_notu << endl;
	
	system("PAUSE");
	return 0;
}

