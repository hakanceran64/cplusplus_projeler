/*
 * Author: Hakan Ceran
 * Date: 15.09.2017
 * Content: Kelimelerin türçe olup olmadýðýný test eden bir uygulama yazmanýz istenmektedir.
 *			Kelimenin türkçe olup olmadýðýný analiz etmek için kontrol etmeniz gereken kriterler ise þu þekildedir:
 *			1) Kalýnlýk incelik uyumu olmalýdýr. (Büyük ünlü uyumu)
 *			2) Düzlük-yuvarlaklýk uyumu olmalýdýr. (Küçük ünlü uyumu)
 *			3) Türkçe dilinde iki ünlü yan yana gelemez.
 *			4) f,j,h harfleri türkçe kelimelerde yoktur.
 *			5) c,ð,l,m,n,r,v,z harfleri kelimenin baþýnda bulunamaz.
 *			6) Baþta çift sessiz harf bulunmaz.
 */

#include <iostream>

using namespace std;

int main(){
	
	char unsuz[21]={'b','c','ç','d','f','g','ð','h','j','k','l','m','n','p','r','s','þ','t','v','y','z'};
	char unlu[8]={'a','e','ý','i','o','ö','u','ü'};
	
	// Max 20 karakterli bir kelime olsun
	char kelime[20];
	int uzunluk=0;
	bool kelime_turkce_mi=true;
	
	cout << "Turcke olup olmadigi kontrol edilecek kelimeyi giriniz: ";
	cin >> kelime;
	
	// Kelimenin kaç karakterden oluþtuðunu hesapla ve bütün karakterleri küçük harflere çevir.
	for(int i=0; kelime[i]!='\0'; ++i){
		uzunluk++;
		kelime[i];tolower(kelime[i]);
	}
	
	// Kalýnlýk Ýncelik
	bool kalin=false, ince=false;
	for(int i=0; i<uzunluk; i++){
		for(int j=0; j<4; j++){
			if(kelime[i]==unlu[j*2]){
				kalin=true;
			} else if(kelime[i]==unlu[(j+1)*2-1]){
				ince=true;
			}
		}
	}
	
	if(kalin==ince){
		cout << "Kalinlik incelij bakimindan kelime turkce degildir." << endl;
		kelime_turkce_mi=false;
		
		system("PAUSE");
		return 0;
	}
	
	// Düzlük-yuvarlaklýk
	bool duz=false, yuvarlak=false;
	for(int i=0; i<uzunluk; i++){
		for(int j=0; j<4; j++){
			if(kelime[i]==unlu[j]){
				duz=true;
			} else if(kelime[i]==unlu[j+4]){
				yuvarlak=true;
			}
		}
	}
	
	if(duz==yuvarlak){
		cout << "Duzluk yuvarlaklik bakimindan kelime turkce degildir." << endl;
		kelime_turkce_mi=false;
		
		system("PAUSE");
		return 0;
	}
	
	// Ýki ünlünün yan yana gelmesi
	for(int i=0; i<uzunluk-1; i++){
		for(int j=0; j<8; j++){
			if(kelime[i]==unlu[j]){
				for(int k=0; k<8; k++){
					if(kelime[i+1]==unlu[k]){
						cout << "Iki unlu yan yana gelemeyeceginden kelime turkce degildir." << endl;
						kelime_turkce_mi=false;
						
						system("PAUSE");
						return 0;
					}
				}
			}
		}
	}
	
	// f,j,h harfleri Türkçe kelimelerde yoktur
	for(int i=0; i<uzunluk-1; i++){
		if(kelime[i]=='f' || kelime[i]=='j' || kelime[i]=='h'){
			cout << "Turkce'de f,j,h harfleri olmadigindan kelime turkce degildir." << endl;
			kelime_turkce_mi=false;
			
			system("PAUSE");
			return 0;
		}
	}
	
	// ç,ð,l,m,n,r,v,z harfleri kelimenin baþýnda bulunmaz 
	if(kelime[0]=='c' || kelime[0]=='ð' || kelime[0]=='l' || kelime[0]=='m' || kelime[0]=='n' || kelime[0]=='r' || kelime[0]=='v' || kelime[0]=='z'){
		cout << "Turkce'de c,ð,l,m,n,r,v,z harfleri kelimelerin basinda bulunamaz." << endl;
		kelime_turkce_mi=false;
		
		system("PAUSE");
		return 0;
	}
	
	// Baþta çift sessiz bulunmaz
	for(int i=0; i<21; i++){
		for(int j=0; j<21; j++){
			if(kelime[0]==unsuz[i] && kelime[1]==unsuz[j]){
				cout << "Turkce'de basta iki unsuz harf bulunamaz." << endl;
				kelime_turkce_mi=false;
				
				system("PAUSE");
				return 0;
			}
		}
	}
	
	if(kelime_turkce_mi==true){
		cout << kelime << " kelime turkcedir." << endl;
	}

	system("PAUSE");
	return 0;
}

