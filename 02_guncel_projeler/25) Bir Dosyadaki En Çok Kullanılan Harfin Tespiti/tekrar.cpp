/*
 * Author: Hakan Ceran
 * Date: 23.09.2017
 * Content: Belirlenen bir texr dosyasýnda en çok kullanýlan harfi tespit eden program kodlarýný yazýnýz.
 */

#include <iostream> // cin, cout vs.
#include <clocale> // Türkçe karakterler
#include <windows.h> // Arkaplan ve yazý rengi
#include <fstream>
#include <cstring>

using namespace std; // std::

int main(){
	setlocale(LC_ALL, "turkish"); // Türkçe Karakterleri Ekliyoruz
	system("color f9"); // Arkaplan ve yazý rengi
	
	string kelime;
	int sayac[26]={0};
	ifstream in;
	
	in.open("dosya.txt");
	
	while(!in.eof()){
		in >> kelime;
		
		for(int i=0; kelime[i]!='\0'; i++){
			if('a'<=kelime[i] && kelime[i]<='z')
				sayac[kelime[i]-'a']++;
			else if('A'<=kelime[i] && kelime[i]<='Z')
				sayac[kelime[i]-'A']++;
		}
	}
		
	in.close();
	
	int maximum=0;
	
	for(int i=0; i<26; i++){
		if(sayac[i]>maximum)
			maximum=sayac[i];
	}
	
	if(maximum!=0){
		cout << "Dosyada en çok geçen harf veya harfler: ";
		
		for(int i=0; i<26; i++){
			if(sayac[i]==maximum){
				cout << (char)(i+'a') << " ";
			}
		}
		
		cout << "harf veya harfleri " << maximum << " kez dosyada geçmiþtir..." << endl << endl;
	} else{
		cout << "Dosyada herhangi bir harf karakteri bulunamadý..." << endl;
	}

	system("PAUSE");
	return 0;
}


