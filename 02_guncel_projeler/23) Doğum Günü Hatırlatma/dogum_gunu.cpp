/*
 * Author: Hakan Ceran
 * Date: 22.09.2017
 * Content: Bir doðum günü hatýrlatma uygulamasý yazmanýz istenmektedir. Kiþilerin doðum gününe 1 aydan daha az kaldýysa, uygulama doðum gününü hatýrlatmalýdýr.
 */

#include <iostream> // cin, cout vs.
#include <clocale> // Türkçe karakterler
#include <windows.h> // Arkaplan ve yazý rengi
#include <time.h>
#include <cstdlib>
#include <iomanip>

using namespace std; // std::

int veri_tabani(int x);
int zaman(struct tm* z, int toplam_gun, int toplam_ay);
int hesapla(int d_gun, int d_ay, int b_gun, int b_ay);
int gun_tut(int i);

int main(){
	setlocale(LC_ALL, "turkish"); // Türkçe Karakterleri Ekliyoruz
	system("color f9"); // Arkaplan ve yazý rengi
	
	char kisi_sayisi[3];
	
	do{
		cout << "Hatýrlatýcýya kaç kiþinin bilgilerini gireceksiniz: ";
		cin >> kisi_sayisi;
		
		if(kisi_sayisi[0]>'0' && kisi_sayisi[0]<'9'){
			veri_tabani(atoi(kisi_sayisi));
		} else if(kisi_sayisi[0] >= 'a' || kisi_sayisi[0] >= 'A'){
			cout << "Harf giremezsiniz..!" << endl;
		} else if(kisi_sayisi[0]<='0'){
			cout << "0, 0'dan küçük sayýlar ve özel karakterler giremezsiniz..!" << endl;
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
		cout << endl << "Kiþinin ismini giriniz: ";
		cin >> bilgiler[a][0];
		
		cout << endl << "Kiþinin soyismini giriniz: ";
		cin >> bilgiler[a][1];
		
		cout << endl << "Kiþinin doðum tarihini giriniz [örnek: 24.01.2016]: ";
		cin >> bilgiler[a][2];
		
		if(a+1<x){
			cout << "Yeni bir kiþi eklemek ister misiniz:(e/h) ";
			cin >> sec;
		} else{
			break;
		}
	}
	
	cout << left;
	
	cout << "Adý - Soyadý\t" << "Doðum Tarihi\t" << "Bugünün Tarihi\t" << "Kalan Gün" << endl;
	
	for(int i=0; i<80; i++){
		cout << "-";
	}
	
	cout << endl;
	
	for(int i=0; i<x; i++){
		for(int j=0; j<2; j++){ // Kiþinin doðum gününü int'e çevirmek için kullandýk
			if(bilgiler[i][2][0]!='0'){ // Doðum günü 03 ya da 09 olarak baþlamýyorsa yani 12,25 gibi sayýlar alýyorsa
				gun[j]=bilgiler[i][2][j];
				guntopla=atoi(gun);
			} else{ // Doðum günü 03 veya 09 olarak baþlýyorsa
				gun[j]=bilgiler[i][2][1];
				guntopla=atoi(gun);
			}
		}
		
		for(int j=3; j<5; j++){ // Kiþinin hangi ay doðduðunu int'e çevirmek için kullandýk
			if(bilgiler[i][2][3]!='0'){
				ay[0]=bilgiler[i][2][j];
				aytopla=atoi(ay);
			} else {
				ay[0]=bilgiler[i][2][4];
				aytopla=atoi(ay);
			}
		}
		
		if(bilgiler[i][0]!="\0"){ // Ekrana yazdýrma
			cout << bilgiler[i][0] << " " << bilgiler[i][1] << "\t" << bilgiler[i][2];
			gun_tut[i]=zaman(zaman_bilgi, guntopla, aytopla);			
			cout << endl;
		}
	}
	
	cout << endl <<"Bir aydan az kalan doðum günü tarihleri: " << endl << endl;
	
	for(int i=0, j=1; i<x; i++){
		if(bilgiler[i][0]!="\0" && gun_tut[i]<30 && gun_tut[i]>0){
			cout << j << ") " << bilgiler[i][0] << " " << bilgiler[i][1] << " isimli kiþinin doðum gününe " << gun_tut[i] << " gün kalmýþtýr..!" << endl << endl;
			j++;
		} else if(bilgiler[i][0]!="\0" && gun_tut[i]==0){
			cout << j << ") " << bilgiler[i][0] << " " << bilgiler[i][1] << " isimli kiþinin doðum günü bugündür. Kutlamayý unutma..!" << endl << endl;
			j++;
		}
	}
}

int zaman(struct tm* z, int toplam_gun, int toplam_ay){
	int sonuc(0);
	int mon=z->tm_mon; // Ay bilgisini alýyoruz.
	char* aylar[12]={"Ocak","Þubat","Mart","Nisan","Mayýs","Haziran","Temmuz","Aðustos","Eylül","Ekim","Kasým","Aralýk"};
	char* ay=aylar[mon];
	
	int yil=z->tm_year+1900; // Yýl bilgisini alýyoruz +1900 yaparak
	// Bulunduðumuz yýlý elde ediyoruz.
	int ayin_gunu=z->tm_mday; // Ayýn kaçýncý günü olduðunu alýyoruz.
	sonuc=hesapla(toplam_gun, toplam_ay, ayin_gunu,mon+1);
	
	cout << ayin_gunu << " " << ay << " " << yil << sonuc << " Gün";
	
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

