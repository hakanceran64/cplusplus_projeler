/*
 * Author: Hakan Ceran
 * Date: 16.09.2016
 * Content: Bu soruda bilimsel heseplamalar yapan bir kod yazmanýz beklenmektedir. Yazýlacak program kodlarýnýn;
 *
 *			- Dört iþlem
 *			- Üstel iþlemler
 *			- Logaritma Hesabý
 *			- Trigonometrik iþlemler
 *
 *			gibi iþlemleri yapýyor olabilmesi gerekmektedir.
 */

#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

// Bekletme Fonksiyonu
void bekleme(int time){
	for(int i=0; i<time; i++){
		for(int j=0; j<100000000; j++){
		}
	}
}

int main(){
	
	const double pi=3.141592653; // Sabit pi sayýsý tanýmlandý.
	double sayi1, sayi2, radyan, derece, sonuc;
	int sec, trch;
	char tercih, secim;
	
	system("color f1");
	
	cout << "| ---------------- HOS GELDINIZ ---------------- |" << endl;
	
	bekleme(3);
	
	do{
		system("cls"); // Ekraný temizler
		
		do{
			system("cls"); // Ekraný temizler
			
			cout << "| ---------------- MENU ---------------- |" << endl;
			cout << "| 1) Toplama islemi                      |" << endl;
			cout << "| 2) Cikarma islemi                      |" << endl;
			cout << "| 3) Carpma islemi                       |" << endl;
			cout << "| 4) Bolme islemi                        |" << endl;
			cout << "| 5) Ustel islem                         |" << endl;
			cout << "| 6) Logaritmik islem                    |" << endl;
			cout << "| 7) Ln islemi                           |" << endl;
			cout << "| 8) Koklu islem                         |" << endl;
			cout << "| 9) Trigonometrik islem                 |" << endl;
			cout << "| 10) Cikis                              |" << endl;
			cout << "| -------------------------------------- |" << endl;
			
			cout << endl << "Seciminiz: ";
			cin >> trch;
			
			if(trch<1 || trch>10){
				cout << "Yanlis secim yaptiniz! Yeniden denemeniz icin yonlendiriliyorsunuz..." << endl;
				
				bekleme(7);
			}
			
		} while(trch<1 || trch >10);
		
		switch(trch){
			case 1:{
				system("cls"); // Ekraný temizler
				
				cout << "Toplama islemi secildi, sayilari giriniz: ";
				cin >> sayi1 >> sayi2;
				
				cout << "Sonuc: " << sayi1 << "+" << sayi2 << "=" << sayi1+sayi2 << endl;
				break;
			}
			case 2:{
				system("cls"); // Ekraný temizler
				
				cout << "Cikarma islemi secildi, sayilari giriniz: ";
				cin >> sayi1 >> sayi2;
				
				cout << "Sonuc: " << sayi1 << "-" << sayi2 << "=" << sayi1-sayi2 << endl;
				
				break;
			}
			case 3:{
				system("cls"); // Ekraný temizler
				
				cout << "Carpma islemi secildi, sayilari giriniz: ";
				cin >> sayi1 >> sayi2;
				
				cout << "Sonuc: " << sayi1 << "*" << sayi2 << "=" << sayi1*sayi2 << endl;
				
				break;
			}
			case 4:{
				system("cls"); // Ekraný temizler
				
				cout << "Bolme islemi secildi, sayilari giriniz: ";
				cin >> sayi1 >> sayi2;
				
				if(sayi1==0 && sayi2== 0){
					cout << "Belirsiz" << endl;
				} else if(sayi2==0){
					cout << "Tanimsiz" << endl;
				} else{
					cout << "Sonuc: " << sayi1 << "/" << sayi2 << "=" << sayi1/sayi2 << endl;
				}
				
				break;
			}
			case 5:{
				system("cls"); // Ekraný temizler
				
				cout << "Ustel secim secildi;" << endl;
				
				cout << "Tabani giriniz: ";
				cin >> sayi1;
				
				cout << "Ussu giriniz: ";
				cin >> sayi2;
				
				cout << "Sonuc: " << pow(sayi1,sayi2) << endl;
				
				break;
			}
			case 6:{
				system("cls"); // Ekraný temizler
				
				cout << "Hangi sayinin logaritmasinin alinmasini istersiniz: ";
				cin >> sayi1;
				
				cout << "Sonuc: " << log10(sayi1) << endl;
				
				break;
			}
			case 7:{
				system("cls"); // Ekraný temizler
				
				cout << "Hangi sayinin Ln'ini almak istersiniz: ";
				cin >> sayi1;
				
				cout << "Sonuc: " << log(sayi1) << endl;
				
				break;
			}
			case 8:{
				system("cls"); // Ekraný temizler
				
				cout << "Hangi sayinin kokunu almak istersiniz: ";
				cin >> sayi1;
				
				cout << "Sonuc: " << sqrt(sayi1) << endl;
				
				break;
			}
			case 9:{
				system("cls"); // Ekraný temizler
				
				cout << "Trigonometrik islem secildi, simdi yapmak istediginiz islemi seciniz: " << endl << endl;
				
				cout << "| ---------------- |" << endl;
				cout << "| 1) Sinus         |" << endl;
				cout << "| 2) Arcsin        |" << endl;
				cout << "| 3) Kosekant      |" << endl;
				cout << "| 4) Arccosec      |" << endl;
				cout << "| 5) Kosinus       |" << endl;
				cout << "| 6) Arccos        |" << endl;
				cout << "| 7) Sekant        |" << endl;
				cout << "| 8) Arcsec        |" << endl;
				cout << "| 9) Tanjant       |" << endl;
				cout << "| 10) Arctan       |" << endl;
				cout << "| 11) Kotanjant    |" << endl;
				cout << "| 12) Arccot       |" << endl;
				cout << "| 13) Cikis        |" << endl;
				cout << "| ---------------- |" << endl;
				
				cout << endl << "Seciminizi yapiniz: ";
				cin >> sec;
				
				switch(sec){
					case 1:{
						system("cls"); // Ekraný temizler
						
						cout << "Sinus'unu hesaplamak istediginiz aciyi giriniz: ";
						cin >> sayi1;
						
						radyan=(sayi1*pi)/180;
						
						cout << "Sayinin radyan degeri: " << radyan << endl;
						cout << "sinus(" << sayi1 << ")=" << sin(radyan) << endl;
						
						break;
					}
					case 2:{
						system("cls"); // Ekraný temizler
						
						do{
							cout << "Arcsinus'unu hesaplamak istediginiz degeri giriniz: ";
							cin >> sayi1;
							
							cout << "Acinin radyan degeri: " << asin(sayi1) << endl;
							cout << "arcsin(" << sayi1 << ")=" << asin(sayi1)*57.2957795 << endl << endl;
						} while(sayi1<-1 || sayi1>1);
						
						break;
					}
					case 3:{
						system("cls"); // Ekraný temizler
						
						cout << "Kosekant'i hesaplamak istediginiz aciyi giriniz: ";
						cin >> sayi1;
						
						radyan=(sayi1*pi)/180;
						
						cout << "Radyan cinsinden deger: " << 1/sin(radyan)*57.2957795 << endl;
						cout << "cosec(" << sayi1 << ")=" << 1/sin(radyan) << endl;
						
						break;
					}
					case 4:{
						system("cls"); // Ekraný temizler
						
						do{
							cout << "Arckosekant'ini hesaplamak istediginiz degeri giriniz: ";
							cin >> sayi1;
							
							sonuc= asin(1/sayi1);
						} while(sayi1>-1 && 1>sayi1);
						
						cout << "Radyan cinsinden arccos(" << sayi1 << ")=" << sonuc << endl;
						cout << "arccos(" << sayi1 << ")=" << sonuc*57.2957795 << endl;
						
						break;
					}
					case 5:{
						system("cls"); // Ekraný temizler
						
						cout << "Kosinus'unu hesaplamak istediginiz aciyi giriniz: ";
						cin >> sayi1;
						
						radyan=(sayi1*pi)/180;
						
						cout << "Acinin radyan degeri: " << radyan << endl;
						cout << "cos(" << sayi1 << ")=" << cos(radyan) << endl;
						
						break;
					}
					case 6:{
						system("cls"); // Ekraný temizler
						
						do{
							cout << "Arckosinus'unu hesaplamak istediginiz degeri giriniz: ";
							cin >> sayi1;
							
							cout << "Acinin radyan degeri: " << acos(sayi1) << endl;
							cout << "arccos(" << sayi1 << ")=" << acos(sayi1)*57.2957795 << endl;
						} while(sayi1<-1 || sayi1>1);
							
						break;
					}
					case 7:{
						system("cls"); // Ekraný temizler
						
						cout << "Sekant'ini hesaplamak istediginiz aciyi giriniz: ";
						cin >> sayi1;
						
						radyan=(sayi1*pi)/180;
						
						cout << "Radyan cinsinden deger: " << 1/cos(radyan) << endl;
						cout << "sec(" << sayi1 << ")=" << 1/cos(radyan)*57.2957795 << endl;
						
						break;
					}
					case 8:{
						system("cls"); // Ekraný temizler
						
						do{
							cout << "Arcsekant'ini hesaplamak istediginiz degeri giriniz: ";
							cin >> sayi1;
							
							sonuc=acos(1/sayi1);
						} while(sayi1>-1 && sayi1>1);
						
						cout << "Radyan cinsinden arcsec(" << sayi1 << ")=" << sonuc << endl;
						cout << "arcsec(" << sayi1 << ")=" << sonuc*57.2957795 << endl;
						
						break;
					}
					case 9:{
						system("cls"); // Ekraný temizler
						
						cout << "Tanjant'ini hesaplamak istediginiz aciyi giriniz: ";
						cin >> sayi1;
						
						radyan=(sayi1*pi)/180;
						
						cout << "Acinin radyan cinsinden degeri: " << radyan << endl;
						cout << "tanjant(" << sayi1 << ")=" << tan(radyan) << endl;
						
						break;
					}
					case 10:{
						system("cls"); // Ekraný temizler
						
						cout << "arctanjant'ini hesaplamak istediginiz degeri giriniz: ";
						cin >> sayi1;
						
						sonuc=atan(sayi1);
						
						cout << "Radyan cinsinden arctan(" << sayi1 << ")=" << sonuc << endl;
						cout << "arctan(" << sayi1 << ")=" << sonuc*57.2957795 << endl;
						
						break;
					}
					case 11:{
						system("cls"); // Ekraný temizler
						
						cout << "Kotanjant'ini hesaplamak istediginiz aciyi giriniz: ";
						cin >> sayi1;
						
						radyan=(sayi1*pi)/180;
						
						cout << "Acinin radyan cinsinden degeri: " << radyan << endl;
						cout << "kotanjant(" << sayi1 << ")=" << cos(radyan)/sin(radyan) << endl;
						
						break;
					}
					case 12:{
						system("cls"); // Ekraný temizler
						
						cout << "Arckotanjant'ini hesaplamak istediginiz degeri giriniz: ";
						cin >> sayi1;
						
						sonuc=atan(1/sayi1);
						
						cout << "Radyan cinsinden arccot(" << sayi1 << ")=" << sonuc << endl;
						cout << "arccot(" << sayi1 << ")=" << sonuc*57.2957795 << endl;
						
						break;
					}
					case 13:{
						system("cls"); // Ekraný temizler
						
						cout << "Program kapatiliyor..." << endl;
						bekleme(6);
						
						return 0;
					}
					default:{
						system("cls"); // Ekraný temizler
						
						cout << "Yanlis secim yaptiniz." << endl;
						break;
					}
				}
				
				break;
			}
			case 10:{
				system("cls"); // Ekraný temizler
				
				cout << "Programdan cikis yapiliyor..." << endl;
				
				bekleme(6);
				
				return 0;
			}
			default: {
				system("cls"); // Ekraný temizler
				
				cout << "Yanlis secim yaptiniz: " << endl;
				break;
			}
		}
		
		cout << endl << "Tekrar islem yapmak icin [e] veya [E] tusuna cikmak icin herhangi bir tusa basiniz: " ;
		cin >> tercih;
	} while(tercih=='e' || tercih=='E');

	system("PAUSE");
	return 0;
}

