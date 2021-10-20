/*
 * Author: Hakan Ceran
 * Date: 20.09.2017
 * Content: Hicri bir tarihi miladi tarihe çeviren ve miladi tarihi de hicri tarihe çeviren program kodlarýný yazýnýz.
 */

#include <iostream> // cin, cout vs.
#include <clocale> // Türkçe karakterler
#include <windows.h> // Arkaplan ve yazý rengi
#include <stdio.h> // Program çýktýsý
#include <time.h> // Bu günün tarihini almak
#include <stdlib.h> // Rastgele sayý üretmek
#include <ctype.h> // Karakter tipini algýlamak ve deðiþtirmek

using namespace std; // std::

// Fonksiyon prototipleri
void m_tarih_yazdir(int g, int a, int y);
void h_tarih_yazdir(int g, int a, int y);

int hicri_tarih(int ay, int gun, int yil);
int hicri_ayin_son_gunu(int ay, int yil);
int miladi_ayin_son_gunu(int ay, int yil);
int miladi_takvim_hesapla(int g, int a, int y);

bool artik_yil(int yil);

char* hicri_ay_ismi(int ay);
char* miladi_ay_ismi(int ay);

int main(){
	setlocale(LC_ALL, "turkish"); // Türkçe Karakterleri Ekliyoruz
	system("color 0B"); // Arkaplan ve yazý rengi
	
	float yil;
	char restart, islem, temp;
	char temp2[2]; // Gün ve ay kontrolü yapmak için
	int s;
	
	do{
		cout << "*********************************************" << endl;
		cout << "* 1) Miladi senenin hicri seneye çevrilmesi *" << endl;
		cout << "* 2) Hicri senenin miladi seneye çevrilmesi *" << endl;
		cout << "*********************************************" << endl << endl;
		
		cout << "Lütfen iþlem numarasýný giriniz: ";
		cin >> islem;
		
		switch(islem){
			case '1':{ // Kullanýcý 1 deðerini girerse bunu yapsýn.
				const time_t current_time=time(NULL);
				tm* t=localtime(&current_time);
				int g=t->tm_mday, a=(t->tm_mon)+1, y=(t->tm_year)+1900;
				
				cout << "Bugün: ";
				m_tarih_yazdir(g, a, y);
				// Üstte yaptýðýmýz iþlem bu günün tarihini hesaplayýp hicri takvime çevirmeyi ve ekrana yazdýrmayý saðlýyor.
				
				do{
					cout << "Miladi ";
					
					do{ // Gün
						cout << endl << "Gün giriniz: ";
						cin >> temp2;
						
						if(!(g==45 && (g>=48 && g<=57)))
							g=atoi(temp2);
						if(g>31 || g<1)
							cout << "Geçersiz gün." << endl;
					} while(g>31 || g<1); // Geçersizse günü tekrar istesin.
					
					do{ // Ay
						cout << "Ay giriniz: ";
						cin >> temp2;
						
						if(!(a==45) && (a>=48 && a<=57))
							a=atoi(temp2);
						if(a>12 || a<1)
							cout << "Geçersiz ay." << endl;
						if(g>29 && a==2)
							cout << "Þubat ayý en fazla 29 gün olabilir." << endl;
					} while(a>12 || a<1 || g>29 && a==2);
					
					do{ // Yýl
						do{
							cout << "Yýl giriniz: ";
							cin >> temp2;
							
							if(!(y==45 || (y>=48 && y<=57)))
								y=atoi(temp2);
							if(!(y>0 || (y>=48 && y<=57)))
								cout << "Geçersiz tarih." << endl;
							if(g==29 && a==2 && y%4!=0)
								// Girilen yýl için þubat ayýnýn 29 gün olup olmadýðýna bakar
								cout << "Geçersiz tarih. " << y << " yýlýnda þubat ayý 29 gün çeker." << endl;
						} while(!(g==29 && a==2 && y%4!=0));
						// girilen yýlda þubat ayý 29 gün deilse yýl tekrar ister.
					} while(!(y>0 || (y>=48 && y<=57)));
					// Rakam dýþýnda bir þey girerse tekrar sor.
					
					m_tarih_yazdir(g, a, y);

					cout << endl << "Yeni bir hicri takvim çevirmek istiyor musun? " << endl;
					cin >> restart;
				} while(restart=='e' || restart=='E');
				break;
			}
			case '2':{ // Kullanýcý 2 deðerini girerse bunu yapsýn.
				const time_t current_time=time(NULL);
				tm* t=localtime(&current_time);
				int g=t->tm_mday, a=(t->tm_mon)+1, y=(t->tm_year)+1900;
				
				cout << "Bugün " << g << " " << miladi_ay_ismi(a) << " " << y << endl;
				
				// Üstte yaptýðýmýz iþlem bu günün tarihini hesaplayýp ekrana yazdýrmayý saðlýyor.
				do{
					do{ // Gün
						cout << endl << "Hicri" ;
						cout << endl << "Gün giriniz: ";
						cin >> temp2;
						
						if(!(g==45 && (g>=48 && g<=57)))
							g=atoi(temp2);
						if(g>31 || g<1)
							cout << "Geçersiz gün girdiniz." << endl;
					} while(g>31 || g<1);
					
					do{ // Ay
						cout << "Ay giriniz: ";
						cin >> temp2;
						
						if(!(a==45 && (a>=48 && a<=57)))
							a=atoi(temp2);
						if(a>12 || a<1)
							cout << "Geçersiz ay." << endl;
					} while(a>12 || a<1);
					
					do{ // Yýl
						cout << "Yýl giriniz: ";
						cin >> temp2;
						
						if(!(y==45 || (y>=48 && y<= 57)))
							y=atoi(temp2);
						if(!(y>0 ||(y>=48 && y<=57)))
							cout << "Geçersiz tarih." << endl;
					} while(!(y>0 || (y>=48 && y<= 57)));
					
					h_tarih_yazdir(g, a, y);
					
					cout << endl << "Yeni bir miladi takvim çevirmek istiyor musunuz?(E/H) ";
					cin >> restart;
				} while(restart=='e' || restart=='E');
				
				break;
			}
			default :{ // Kullanýcýnýn aksi bir sayý girmesi durumunda...
				cout << "Geçerli bir iþlem numarasý girmediniz." << endl;
				break;
			}
		}

		cout << "Menüye geri dönmek istiyor musunuz?(E/H): ";
		cin >> restart;
	} while (restart=='e' || restart=='E');
	
	cout << "Program kapatýlacak..." << endl;

	system("PAUSE");
	return 0;
}

int miladi_ayin_son_gunu(int ay, int yil){
	// Miladi takvim için ayýn son gününü hesaplama
	switch(ay){
		case 2:
			if((((yil%4)==0) && ((yil%100)!=0)) || ((yil%400)==0))
				// Eðer yýlýn 400'e bölümü 0'a eþitse veya 100'e bölümü ya da 4'e bölümü 0'sa þubat ayýna 29 ata deðilse 28 ata ve döndür
				return 29;
			else
				return 28;
		case 4:
		case 6:
		case 9:
		case 11:
			return 30; // 4. 6. 9. ve 11. aylar için 30 girsin.
		default:
			return 31; // Diðer aylar için 31 girsin
	}
}

int miladi_takvim_hesaplamasi(int g, int a, int y){
	int N=g; // Bir n deðeri ata ve güne eþitle
	
	for(int i=a-1; i>0; i--)
		N+=miladi_ayin_son_gunu(i,y);
	
	return N+(y-1)*365+(y-1)/4-(y-1)/100+(y-1)/400;
}

bool artik_yil(int yil){
	// Hicri artýk yil ise doðru deðilse yanlýþ döndür.
	if((((11*yil)+14)%30)<11)
		return true;
	else
		return false;
}

int hicri_ayin_son_gunu(int ay, int yil){
	// Hicri takvim için son gününü hesaplama
	if(((ay%2)==1) || ((ay==12) && artik_yil(yil)))
		return 30; // Hicri ayý 30 gün yap.
	else
		return 29; // Deðilse 29 olsun.
}

const int hicri=227014; // Mutlak hicri takvimin baþlangýç günü
const int miladi=0;

int hicri_tarih(int ay, int gun, int yil){
	// Miladi takvim hicri takvimden 11 gün fazla
	return (gun+29*(ay-1) // Aya kadar olan günleri hesaplama
	+ay/2 // Girilen ayýn yarýsý
	+354*(yil-1) // önceki yýllarda olmayan artýk günler
	+(3+(11*yil))/30 // önceki yýllarda olan artýk günler
	+hicri); // Takvimin baþlamasýndan önceli günler
}

char* hicri_ay_ismi(int ay){
	switch(ay){
		case 1:
			return "(1) Muharrem";
		case 2:
			return "(2) Safer";
		case 3:
			return "(3) Rebiulevvel";
		case 4:
			return "(4) Rebiulahir";
		case 5:
			return "(5) Cemaziyelevvel";
		case 6:
			return "(6) Cemaziyelahir";
		case 7:
			return "(7) Recep";
		case 8:
			return "(8) Þaban";
		case 9:
			return "(9) Ramazan";
		case 10:
			return "(10) Þevval";
		case 11:
			return "(11) Zilkade";
		case 12:
			return "(12) Zilhicce";
		return "";
	}
}

char* miladi_ay_ismi(int ay){
	switch(ay){
		case 1:
			return "(1) Ocak";
		case 2:
			return "(2) Þubat";
		case 3:
			return "(3) Mart";
		case 4:
			return "(4) Nisan";
		case 5:
			return "(5) Mayýs";
		case 6:
			return "(6) Haziran";
		case 7:
			return "(7) Temmuz";
		case 8:
			return "(8) Aðustos";
		case 9:
			return "(9) Eylül";
		case 10:
			return "(10) Ekim";
		case 11:
			return "(11) Kasým";
		case 12:
			return "(12) Aralýk";
		return "";
	}
}

void m_tarih_yazdir(int g, int a, int y){
	g=miladi_takvim_hesaplamasi(g, a, y);
	int gun, ay, yil;
	
	// Tahmini yýldan ileriye doðru aranacak yýl
	yil=(g-hicri)/355;
	
	while(g>=hicri_tarih(1, 1, yil))
		yil++;
	
	yil--;
	
	// Muhrarem ayýndan ileriye doðru aranacak ay
	ay=1;
	
	while(g>hicri_tarih(ay, hicri_ayin_son_gunu(ay, yil), yil))
		ay++;
	
	gun=g-hicri_tarih(ay, 1, yil)+1;
	
	cout << gun+1 << " " << hicri_ay_ismi(ay) << " " << yil << endl; 
}

void h_tarih_yazdir(int gun, int ay, int yil){
	int gecici1=(11*yil+3)/30.0;
	int gecici2=(ay-1)/2.0;
	int gecici=gecici1+354*yil+30*ay-gecici2+gun+1948440-385;
	
	int l=gecici+68569;
	int n=(4*l)/146097.0;
	l=l-(146097*n+3)/4.0;
	int i=(4000 *(l+1))/1461001.0;
	l=l-(1461*i)/4.0+31;
	int j=(80*l)/2447.0;
	int g=l-(2447*j)/80.0;
	l=j/11.0;
	int a=j+2-12*l;
	int y=100*(n-49)+i+l;
	
	cout << g+1 << " " << miladi_ay_ismi(a) << " " << y << endl;
}
