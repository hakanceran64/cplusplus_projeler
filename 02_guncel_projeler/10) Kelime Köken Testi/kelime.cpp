/*
 * Author: Hakan Ceran
 * Date: 15.09.2017
 * Content: Kelimelerin t�r�e olup olmad���n� test eden bir uygulama yazman�z istenmektedir.
 *			Kelimenin t�rk�e olup olmad���n� analiz etmek i�in kontrol etmeniz gereken kriterler ise �u �ekildedir:
 *			1) Kal�nl�k incelik uyumu olmal�d�r. (B�y�k �nl� uyumu)
 *			2) D�zl�k-yuvarlakl�k uyumu olmal�d�r. (K���k �nl� uyumu)
 *			3) T�rk�e dilinde iki �nl� yan yana gelemez.
 *			4) f,j,h harfleri t�rk�e kelimelerde yoktur.
 *			5) c,�,l,m,n,r,v,z harfleri kelimenin ba��nda bulunamaz.
 *			6) Ba�ta �ift sessiz harf bulunmaz.
 */

#include <iostream>

using namespace std;

int main(){
	
	char unsuz[21]={'b','c','�','d','f','g','�','h','j','k','l','m','n','p','r','s','�','t','v','y','z'};
	char unlu[8]={'a','e','�','i','o','�','u','�'};
	
	// Max 20 karakterli bir kelime olsun
	char kelime[20];
	int uzunluk=0;
	bool kelime_turkce_mi=true;
	
	cout << "Turcke olup olmadigi kontrol edilecek kelimeyi giriniz: ";
	cin >> kelime;
	
	// Kelimenin ka� karakterden olu�tu�unu hesapla ve b�t�n karakterleri k���k harflere �evir.
	for(int i=0; kelime[i]!='\0'; ++i){
		uzunluk++;
		kelime[i];tolower(kelime[i]);
	}
	
	// Kal�nl�k �ncelik
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
	
	// D�zl�k-yuvarlakl�k
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
	
	// �ki �nl�n�n yan yana gelmesi
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
	
	// f,j,h harfleri T�rk�e kelimelerde yoktur
	for(int i=0; i<uzunluk-1; i++){
		if(kelime[i]=='f' || kelime[i]=='j' || kelime[i]=='h'){
			cout << "Turkce'de f,j,h harfleri olmadigindan kelime turkce degildir." << endl;
			kelime_turkce_mi=false;
			
			system("PAUSE");
			return 0;
		}
	}
	
	// �,�,l,m,n,r,v,z harfleri kelimenin ba��nda bulunmaz 
	if(kelime[0]=='c' || kelime[0]=='�' || kelime[0]=='l' || kelime[0]=='m' || kelime[0]=='n' || kelime[0]=='r' || kelime[0]=='v' || kelime[0]=='z'){
		cout << "Turkce'de c,�,l,m,n,r,v,z harfleri kelimelerin basinda bulunamaz." << endl;
		kelime_turkce_mi=false;
		
		system("PAUSE");
		return 0;
	}
	
	// Ba�ta �ift sessiz bulunmaz
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

