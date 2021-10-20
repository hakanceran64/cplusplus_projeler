/*
 * Author: Hakan Ceran
 * Date: 14.09.2017
 * Content: Bir hastane otomasayon yazýlýmý yapmanýz istenilmektedir.
 *			Bu otomasyon sayesinde, yeni hastalarýn eklenmesi, hastanede olan hastalarýn listelenmesi ve taburcu olan hastalarýn listesinin tutulmasý hedeflenmektedir. Bu iþlemleri yapan kodu yazýnýz.
 *			NOT: Listeler dosya halinde tutulmalýdýr.
 */

#include <iostream>
#include <cstring>
#include <fstream> // File input/output
#include <iomanip> // setw fonk
#include <stdlib.h> // srand fonk
#include <time.h> // srand(time(0)) fonk

using namespace std;

// Girilen bilgileri sahip hastayý direk kaydeder.
void hasta_ekle();

// Girilen hasta numarasýna sahip hastayý taburcu ederken kaydedilsin mi diye sorar.
void hasta_taburcu();

// hastaliste adlý text'ten okuyup cout ile ekrana yazar.
void ekrana_yazdir(short, char[], char[], short, char[]);

// Hasta listesini ekrana yazdýrý ayrýca hasta taburcunun içinde de çalýþýr, hasta no girmeye yardýmcý olur.
void liste_yazdir();

// temp dosyasýný ana dosyaya yazdýrýr.
void liste_guncelle();

// temp dosyasýna çýktý alýr.
void taburcu_olan_hasta(short, char[], char[], short, char[]);


int main(){
	
	int islem=0;
	string secim;
	
	do{
		do{
			cout << "islem seciniz: " << endl;
			cout << "1) Hasta ekleme" << endl;
			cout << "2) Hasta taburcu" << endl;
			cout << "3) Hasta listeleme" << endl << endl;
			
			cout << "Seciminiz: ";
			cin >> islem;
		} while(islem!=1 && islem!=2 && islem!=3); // kullanýcýyý kýsýtlamak lazým.
		
		cout << endl;
		
		switch(islem){
			case 1:
				hasta_ekle();
				break;
			case 2:
				hasta_taburcu();
				break;
			case 3:
				liste_yazdir();
		}
		
		cin.clear(); // cin ile ilgili yaþanan sorunlarý çözer.
		
		cout << endl << "Baska bir islem yapacak misiniz: ";
		cin >> secim;
		
		cout << endl;
	} while(secim=="Evet" || secim=="evet" || secim=="E" || secim=="e" || secim=="Yes" || secim=="yes" || secim=="Y" || secim=="y");

	system("PAUSE");
	return 0;
}

void hasta_ekle(void){
	// ios::app sona eklemek için
	// ios::out sýfýrdan yazmak için
	ofstream hasta_cikti("hasta_liste.txt",ios::app);
	
	cout << "Hasta girisi yapiniz: (cikiz yapmak icin CTRL+Z)" << endl;
	cout << "Gerekenler: AdSoyad, kan, yas, telNo" << endl;
	cout << "Ornek giris: HakanCeran AB+ 21 5340224669" << endl;
	
	srand(time(0));
	
	char ad_soyad[15], kan[5], tel_no[10];
	short yas, hasta_no=rand()%1000;
	
	cout << endl << hasta_no << " ";
	cin >> ad_soyad >> kan >> yas >> tel_no;
	
	hasta_cikti << endl << hasta_no << " " << ad_soyad << " " << kan << " " << yas << " " << tel_no;
	
	hasta_cikti.close();
}

void hasta_taburcu(void){
	char ad_soyad[15], kan[5], tel_no[10];
	short yas, hasta_no, sorgu;
	bool kontrol=0;
	
	liste_yazdir();
	
	ifstream hasta_girdi("hasta_liste.txt",ios::in);
	ofstream taburcu_cikti("temp.txt",ios::trunc); // tempi boþaltýr.
	
	cout << endl << "Taburcu edilecek hasta_no'yu giriniz: ";
	cin >> sorgu;
	
	cout << endl;
	
	while(hasta_girdi >> hasta_no >> ad_soyad >> kan >> yas >> tel_no){
		if(hasta_no==sorgu){
			cout << ad_soyad << " isimli hasta bulundu!" << endl;
			kontrol=1;
		} else
			taburcu_olan_hasta(hasta_no,ad_soyad,kan,yas,tel_no);
	}
	
	if(!kontrol)
		cout << "\a" << "Taburcu edilmek istenen hasta bulunmadi!" << endl;
	else
		liste_guncelle();
	
	hasta_girdi.close();
}

void ekrana_yazdir(short h, char a[], char k[], short y, char t[]){
	cout << setw(3) << h << setw(15) << a << setw(6) << k << setw(6) << y << setw(15) << t << endl;
}

void liste_yazdir(void){
	char ad_soyad[15], kan[5], tel_no[10];
	short yas, hasta_no, sorgu;
	
	ifstream hasta_girdi("hasta_liste.txt",ios::in);
	
	while(!hasta_girdi.eof()){
		hasta_girdi >> hasta_no >> ad_soyad >> kan >> yas >> tel_no;
		ekrana_yazdir(hasta_no,ad_soyad,kan,yas,tel_no);
	}
	hasta_girdi.close();
}

void liste_guncelle(void){
	string kaydet;
	
	cout << "Hasta taburcu edilsin mi: ";
	cin >> kaydet;
	
	if(kaydet=="Evet" || kaydet=="evet" || kaydet=="E" || kaydet=="e" || kaydet=="Yes" || kaydet=="yes" || kaydet=="Y" || kaydet=="y"){
		ifstream stream1("temp.txt"); // Kaynak Dosya
		ofstream stream2("hasta_liste.txt"); // Hedef Dosya
		
		stream2 << stream1.rdbuf(); // Kaynaðý hedefe kopyaladý
	}
	cout << "Hasta basariyla taburcu edildi!" << endl;
}

void taburcu_olan_hasta(short h, char a[], char k[], short y, char t[]){
	ofstream taburcu_cikti("temp.txt",ios::app);
	taburcu_cikti << endl << h << " " << a << " " << k << " " << y << " " << t << endl;
	taburcu_cikti.close();
}
