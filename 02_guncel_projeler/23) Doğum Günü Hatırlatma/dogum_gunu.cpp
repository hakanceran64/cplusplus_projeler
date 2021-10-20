/*
 * Author: Hakan Ceran
 * Date: 22.09.2017
 * Content: Bir do�um g�n� hat�rlatma uygulamas� yazman�z istenmektedir. Ki�ilerin do�um g�n�ne 1 aydan daha az kald�ysa, uygulama do�um g�n�n� hat�rlatmal�d�r.
 */

#include <iostream> // cin, cout vs.
#include <clocale> // T�rk�e karakterler
#include <windows.h> // Arkaplan ve yaz� rengi
#include <time.h>
#include <cstdlib>
#include <iomanip>

using namespace std; // std::

int veri_tabani(int x);
int zaman(struct tm* z, int toplam_gun, int toplam_ay);
int hesapla(int d_gun, int d_ay, int b_gun, int b_ay);
int gun_tut(int i);

int main(){
	setlocale(LC_ALL, "turkish"); // T�rk�e Karakterleri Ekliyoruz
	system("color f9"); // Arkaplan ve yaz� rengi
	
	char kisi_sayisi[3];
	
	do{
		cout << "Hat�rlat�c�ya ka� ki�inin bilgilerini gireceksiniz: ";
		cin >> kisi_sayisi;
		
		if(kisi_sayisi[0]>'0' && kisi_sayisi[0]<'9'){
			veri_tabani(atoi(kisi_sayisi));
		} else if(kisi_sayisi[0] >= 'a' || kisi_sayisi[0] >= 'A'){
			cout << "Harf giremezsiniz..!" << endl;
		} else if(kisi_sayisi[0]<='0'){
			cout << "0, 0'dan k���k say�lar ve �zel karakterler giremezsiniz..!" << endl;
		}
	} while(kisi_sayisi[0]<='0' || kisi_sayisi[0]>='a' || kisi_sayisi[0]>='A');

	system("PAUSE");
	return 0;
}

int veri_tabani(int x){
	string bilgiler[x][3];
	char sec, gun[2], ay[2];
	int guntopla(0), aytopla(0), gun_tut[x];
	
	time_t yil;
	struct tm* zaman_bilgi;
	
	time(&yil);
	
	zaman_bilgi=localtime(&yil);
	
	for(int a=0; a<x, sec!='h'; a++){
		cout << endl << "Ki�inin ismini giriniz: ";
		cin >> bilgiler[a][0];
		
		cout << endl << "Ki�inin soyismini giriniz: ";
		cin >> bilgiler[a][1];
		
		cout << endl << "Ki�inin do�um tarihini giriniz [�rnek: 24.01.2016]: ";
		cin >> bilgiler[a][2];
		
		if(a+1<x){
			cout << "Yeni bir ki�i eklemek ister misiniz:(e/h) ";
			cin >> sec;
		} else{
			break;
		}
	}
	
	cout << left;
	
	cout << "Ad� - Soyad�\t" << "Do�um Tarihi\t" << "Bug�n�n Tarihi\t" << "Kalan G�n" << endl;
	
	for(int i=0; i<80; i++){
		cout << "-";
	}
	
	cout << endl;
	
	for(int i=0; i<x; i++){
		for(int j=0; j<2; j++){ // Ki�inin do�um g�n�n� int'e �evirmek i�in kulland�k
			if(bilgiler[i][2][0]!='0'){ // Do�um g�n� 03 ya da 09 olarak ba�lam�yorsa yani 12,25 gibi say�lar al�yorsa
				gun[j]=bilgiler[i][2][j];
				guntopla=atoi(gun);
			} else{ // Do�um g�n� 03 veya 09 olarak ba�l�yorsa
				gun[j]=bilgiler[i][2][1];
				guntopla=atoi(gun);
			}
		}
		
		for(int j=3; j<5; j++){ // Ki�inin hangi ay do�du�unu int'e �evirmek i�in kulland�k
			if(bilgiler[i][2][3]!='0'){
				ay[0]=bilgiler[i][2][j];
				aytopla=atoi(ay);
			} else {
				ay[0]=bilgiler[i][2][4];
				aytopla=atoi(ay);
			}
		}
		
		if(bilgiler[i][0]!="\0"){ // Ekrana yazd�rma
			cout << bilgiler[i][0] << " " << bilgiler[i][1] << "\t" << bilgiler[i][2];
			gun_tut[i]=zaman(zaman_bilgi, guntopla, aytopla);			
			cout << endl;
		}
	}
	
	cout << endl <<"Bir aydan az kalan do�um g�n� tarihleri: " << endl << endl;
	
	for(int i=0, j=1; i<x; i++){
		if(bilgiler[i][0]!="\0" && gun_tut[i]<30 && gun_tut[i]>0){
			cout << j << ") " << bilgiler[i][0] << " " << bilgiler[i][1] << " isimli ki�inin do�um g�n�ne " << gun_tut[i] << " g�n kalm��t�r..!" << endl << endl;
			j++;
		} else if(bilgiler[i][0]!="\0" && gun_tut[i]==0){
			cout << j << ") " << bilgiler[i][0] << " " << bilgiler[i][1] << " isimli ki�inin do�um g�n� bug�nd�r. Kutlamay� unutma..!" << endl << endl;
			j++;
		}
	}
}

int zaman(struct tm* z, int toplam_gun, int toplam_ay){
	int sonuc(0);
	int mon=z->tm_mon; // Ay bilgisini al�yoruz.
	char* aylar[12]={"Ocak","�ubat","Mart","Nisan","May�s","Haziran","Temmuz","A�ustos","Eyl�l","Ekim","Kas�m","Aral�k"};
	char* ay=aylar[mon];
	
	int yil=z->tm_year+1900; // Y�l bilgisini al�yoruz +1900 yaparak
	// Bulundu�umuz y�l� elde ediyoruz.
	int ayin_gunu=z->tm_mday; // Ay�n ka��nc� g�n� oldu�unu al�yoruz.
	sonuc=hesapla(toplam_gun, toplam_ay, ayin_gunu,mon+1);
	
	cout << ayin_gunu << " " << ay << " " << yil << sonuc << " G�n";
	
	return sonuc;
}

int hesapla(int d_gun, int d_ay, int b_gun, int b_ay){
	int sonuc(0);
	
	if(d_gun==b_gun){
		sonuc=(d_ay-b_ay)*30;
		
		if(d_ay<=b_ay && d_gun<b_gun){
			sonuc=365+sonuc;
		}
	} else if(d_gun<b_gun){
		sonuc=(d_ay-b_ay)*30-(b_gun-d_gun);
		
		if(d_ay<=b_ay && d_gun<b_gun){
			sonuc=365+sonuc;
		}
	} else if(d_gun>b_gun){
		sonuc=(d_ay-b_ay)*30+(d_gun-b_gun);
		
		if(d_ay<=b_ay && d_gun<b_gun){
			sonuc=365+sonuc;
		}
	}
	
	return sonuc;
}

