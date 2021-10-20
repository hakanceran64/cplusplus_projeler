/*
 * Author: Hakan Ceran
 * Date:14.09.2017
 * Content: Bir �nceki soruda �retilen labirenti kullanarak b�t�n yollar� bulunuz.
 *			Labirentte # d�� duvarlar�, + i� duvarlar�, 0 ise yollar� temsil etmektedir. Labirente soldan girilip sa�dan ��k�lmal�d�r.
 *			Labirentte yol bulmak i�in MAZE algoritmas� kullan�labilir.
 *
 *			Algoritma:
 *				1. Geldi�im yeri i�aretle.
 *				2. if(sola gidilmemi�se), sola git.
 *				3. else if(sa�a gidilmemi�se), sa�a git.
 *				4. else if(yukar� gidilmemi�se), yukar� git.
 *				5. else if(a�a�� gidilmemi�se), a�a�� git.
 *				6. 1. Ad�ma git
 *
 *			NOT: Sizden istenen ��k��a giden yolu bulmak de�il, m�mk�n olan b�t�n yollar� bulman�zd�r.
 */

#include <iostream>
#include <fstream>

using namespace std;

// Bu kod ile MAZE Algoritmas�na g�re matriste arama yaparak matris i�erisindeki b�t�n yollar bulunmaktad�r.
// Matris boyutlar� 20x70 olarak belirlendi.

#define labirentX 20
#define labirentY 70

void bul(char labirent[labirentX][labirentY],int i, int j);

ofstream output;

int main(){
	char labirent[labirentX][labirentY];
	
	ifstream myfile("LabirentUret/labirent.txt");
	
	if(!myfile){
		cout << "Labirent Dosyasi Bulunamadi." << endl;
		
		system("PAUSE");
		return -1;
	}
	
	// Labirent'i dosyadan oku ve iki boyutlu diziye yaz.
	for(int i=0; i<labirentX; ++i)
		for(int j=0; j<labirentY; j++)
			myfile >> labirent[i][j];
	myfile.close();
	
	// iki boyutlu diziyi ekrana yaz.
	cout << "Okunan Labirent:" << endl;
	for(int i=0; i<labirentX; ++i){
		for(int j=0; j<labirentY; j++)
			cout << labirent[i][j];
		cout << endl;
	}
	cout << endl;
	
	// M�mk�n olan yollar� bul ve output dosyas�na bak�lan yollar� yaz
	output.open("output.txt");
	for(int i=0; i<labirentX; ++i)
		for(int j=0; j<labirentY; j++)
			bul(labirent,i,j);
	output.close();
	
	// Sonucu Ekrana yazdir.
	cout << "Bulunan Labirent:" << endl;
	for(int i=0; i<labirentX; ++i){
		for(int j=0; j<labirentY; j++)
			cout << labirent[i][j];
		cout << endl;
	}
	
	system("PAUSE");
	return 0;
}

void bul(char labirent[labirentX][labirentY],int i, int j){
	output << "Labirent[" << i << "][" << j << "]'e bakiliyor." << endl;
	
	for(int k=0; k<100; k++)
		for(int l=0; l<100; l++)
	
	if(labirent[i][j+1]!='#' && labirent[i][j+1]=='0'){
		j++;
		labirent[i][j]=' ';
		bul(labirent,i,j);
	} else if(labirent[i-1][j]!='#' && labirent[i-1][j]==' '){ // Yukar�
		i--;
		labirent[i][j]=' ';
		bul(labirent,i,j);
	} else if(labirent[i-1][j]!='#' && labirent[i+1][j]=='0'){ // A�a��
		i++;
		labirent[i][j]=' ';
		bul(labirent,i,j);
	} else if(labirent[i-1][j]!='#' && labirent[i][j-1]=='0'){ // Geri
		j--;
		labirent[i][j]=' ';
		bul(labirent,i,j);
	}
}
