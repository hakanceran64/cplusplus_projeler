/*
 * Author: Hakan Ceran
 * Date: 20.09.2017
 * Content: Hicri bir tarihi miladi tarihe �eviren ve miladi tarihi de hicri tarihe �eviren program kodlar�n� yaz�n�z.
 */

#include <iostream> // cin, cout vs.
#include <clocale> // T�rk�e karakterler
#include <windows.h> // Arkaplan ve yaz� rengi
#include <stdio.h> // Program ��kt�s�
#include <time.h> // Bu g�n�n tarihini almak
#include <stdlib.h> // Rastgele say� �retmek
#include <ctype.h> // Karakter tipini alg�lamak ve de�i�tirmek

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
	setlocale(LC_ALL, "turkish"); // T�rk�e Karakterleri Ekliyoruz
	system("color 0B"); // Arkaplan ve yaz� rengi
	
	float yil;
	char restart, islem, temp;
	char temp2[2]; // G�n ve ay kontrol� yapmak i�in
	int s;
	
	do{
		cout << "*********************************************" << endl;
		cout << "* 1) Miladi senenin hicri seneye �evrilmesi *" << endl;
		cout << "* 2) Hicri senenin miladi seneye �evrilmesi *" << endl;
		cout << "*********************************************" << endl << endl;
		
		cout << "L�tfen i�lem numaras�n� giriniz: ";
		cin >> islem;
		
		switch(islem){
			case '1':{ // Kullan�c� 1 de�erini girerse bunu yaps�n.
				const time_t current_time=time(NULL);
				tm* t=localtime(&current_time);
				int g=t->tm_mday, a=(t->tm_mon)+1, y=(t->tm_year)+1900;
				
				cout << "Bug�n: ";
				m_tarih_yazdir(g, a, y);
				// �stte yapt���m�z i�lem bu g�n�n tarihini hesaplay�p hicri takvime �evirmeyi ve ekrana yazd�rmay� sa�l�yor.
				
				do{
					cout << "Miladi ";
					
					do{ // G�n
						cout << endl << "G�n giriniz: ";
						cin >> temp2;
						
						if(!(g==45 && (g>=48 && g<=57)))
							g=atoi(temp2);
						if(g>31 || g<1)
							cout << "Ge�ersiz g�n." << endl;
					} while(g>31 || g<1); // Ge�ersizse g�n� tekrar istesin.
					
					do{ // Ay
						cout << "Ay giriniz: ";
						cin >> temp2;
						
						if(!(a==45) && (a>=48 && a<=57))
							a=atoi(temp2);
						if(a>12 || a<1)
							cout << "Ge�ersiz ay." << endl;
						if(g>29 && a==2)
							cout << "�ubat ay� en fazla 29 g�n olabilir." << endl;
					} while(a>12 || a<1 || g>29 && a==2);
					
					do{ // Y�l
						do{
							cout << "Y�l giriniz: ";
							cin >> temp2;
							
							if(!(y==45 || (y>=48 && y<=57)))
								y=atoi(temp2);
							if(!(y>0 || (y>=48 && y<=57)))
								cout << "Ge�ersiz tarih." << endl;
							if(g==29 && a==2 && y%4!=0)
								// Girilen y�l i�in �ubat ay�n�n 29 g�n olup olmad���na bakar
								cout << "Ge�ersiz tarih. " << y << " y�l�nda �ubat ay� 29 g�n �eker." << endl;
						} while(!(g==29 && a==2 && y%4!=0));
						// girilen y�lda �ubat ay� 29 g�n deilse y�l tekrar ister.
					} while(!(y>0 || (y>=48 && y<=57)));
					// Rakam d���nda bir �ey girerse tekrar sor.
					
					m_tarih_yazdir(g, a, y);

					cout << endl << "Yeni bir hicri takvim �evirmek istiyor musun? " << endl;
					cin >> restart;
				} while(restart=='e' || restart=='E');
				break;
			}
			case '2':{ // Kullan�c� 2 de�erini girerse bunu yaps�n.
				const time_t current_time=time(NULL);
				tm* t=localtime(&current_time);
				int g=t->tm_mday, a=(t->tm_mon)+1, y=(t->tm_year)+1900;
				
				cout << "Bug�n " << g << " " << miladi_ay_ismi(a) << " " << y << endl;
				
				// �stte yapt���m�z i�lem bu g�n�n tarihini hesaplay�p ekrana yazd�rmay� sa�l�yor.
				do{
					do{ // G�n
						cout << endl << "Hicri" ;
						cout << endl << "G�n giriniz: ";
						cin >> temp2;
						
						if(!(g==45 && (g>=48 && g<=57)))
							g=atoi(temp2);
						if(g>31 || g<1)
							cout << "Ge�ersiz g�n girdiniz." << endl;
					} while(g>31 || g<1);
					
					do{ // Ay
						cout << "Ay giriniz: ";
						cin >> temp2;
						
						if(!(a==45 && (a>=48 && a<=57)))
							a=atoi(temp2);
						if(a>12 || a<1)
							cout << "Ge�ersiz ay." << endl;
					} while(a>12 || a<1);
					
					do{ // Y�l
						cout << "Y�l giriniz: ";
						cin >> temp2;
						
						if(!(y==45 || (y>=48 && y<= 57)))
							y=atoi(temp2);
						if(!(y>0 ||(y>=48 && y<=57)))
							cout << "Ge�ersiz tarih." << endl;
					} while(!(y>0 || (y>=48 && y<= 57)));
					
					h_tarih_yazdir(g, a, y);
					
					cout << endl << "Yeni bir miladi takvim �evirmek istiyor musunuz?(E/H) ";
					cin >> restart;
				} while(restart=='e' || restart=='E');
				
				break;
			}
			default :{ // Kullan�c�n�n aksi bir say� girmesi durumunda...
				cout << "Ge�erli bir i�lem numaras� girmediniz." << endl;
				break;
			}
		}

		cout << "Men�ye geri d�nmek istiyor musunuz?(E/H): ";
		cin >> restart;
	} while (restart=='e' || restart=='E');
	
	cout << "Program kapat�lacak..." << endl;

	system("PAUSE");
	return 0;
}

int miladi_ayin_son_gunu(int ay, int yil){
	// Miladi takvim i�in ay�n son g�n�n� hesaplama
	switch(ay){
		case 2:
			if((((yil%4)==0) && ((yil%100)!=0)) || ((yil%400)==0))
				// E�er y�l�n 400'e b�l�m� 0'a e�itse veya 100'e b�l�m� ya da 4'e b�l�m� 0'sa �ubat ay�na 29 ata de�ilse 28 ata ve d�nd�r
				return 29;
			else
				return 28;
		case 4:
		case 6:
		case 9:
		case 11:
			return 30; // 4. 6. 9. ve 11. aylar i�in 30 girsin.
		default:
			return 31; // Di�er aylar i�in 31 girsin
	}
}

int miladi_takvim_hesaplamasi(int g, int a, int y){
	int N=g; // Bir n de�eri ata ve g�ne e�itle
	
	for(int i=a-1; i>0; i--)
		N+=miladi_ayin_son_gunu(i,y);
	
	return N+(y-1)*365+(y-1)/4-(y-1)/100+(y-1)/400;
}

bool artik_yil(int yil){
	// Hicri art�k yil ise do�ru de�ilse yanl�� d�nd�r.
	if((((11*yil)+14)%30)<11)
		return true;
	else
		return false;
}

int hicri_ayin_son_gunu(int ay, int yil){
	// Hicri takvim i�in son g�n�n� hesaplama
	if(((ay%2)==1) || ((ay==12) && artik_yil(yil)))
		return 30; // Hicri ay� 30 g�n yap.
	else
		return 29; // De�ilse 29 olsun.
}

const int hicri=227014; // Mutlak hicri takvimin ba�lang�� g�n�
const int miladi=0;

int hicri_tarih(int ay, int gun, int yil){
	// Miladi takvim hicri takvimden 11 g�n fazla
	return (gun+29*(ay-1) // Aya kadar olan g�nleri hesaplama
	+ay/2 // Girilen ay�n yar�s�
	+354*(yil-1) // �nceki y�llarda olmayan art�k g�nler
	+(3+(11*yil))/30 // �nceki y�llarda olan art�k g�nler
	+hicri); // Takvimin ba�lamas�ndan �nceli g�nler
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
			return "(8) �aban";
		case 9:
			return "(9) Ramazan";
		case 10:
			return "(10) �evval";
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
			return "(2) �ubat";
		case 3:
			return "(3) Mart";
		case 4:
			return "(4) Nisan";
		case 5:
			return "(5) May�s";
		case 6:
			return "(6) Haziran";
		case 7:
			return "(7) Temmuz";
		case 8:
			return "(8) A�ustos";
		case 9:
			return "(9) Eyl�l";
		case 10:
			return "(10) Ekim";
		case 11:
			return "(11) Kas�m";
		case 12:
			return "(12) Aral�k";
		return "";
	}
}

void m_tarih_yazdir(int g, int a, int y){
	g=miladi_takvim_hesaplamasi(g, a, y);
	int gun, ay, yil;
	
	// Tahmini y�ldan ileriye do�ru aranacak y�l
	yil=(g-hicri)/355;
	
	while(g>=hicri_tarih(1, 1, yil))
		yil++;
	
	yil--;
	
	// Muhrarem ay�ndan ileriye do�ru aranacak ay
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
