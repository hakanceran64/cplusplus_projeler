/*
 * Author: Hakan Ceran
 * Date:14.09.2017
 * Content: Bir önceki soruda üretilen labirenti kullanarak bütün yollarý bulunuz.
 *			Labirentte # dýþ duvarlarý, + iç duvarlarý, 0 ise yollarý temsil etmektedir. Labirente soldan girilip saðdan çýkýlmalýdýr.
 *			Labirentte yol bulmak için MAZE algoritmasý kullanýlabilir.
 *
 *			Algoritma:
 *				1. Geldiðim yeri iþaretle.
 *				2. if(sola gidilmemiþse), sola git.
 *				3. else if(saða gidilmemiþse), saða git.
 *				4. else if(yukarý gidilmemiþse), yukarý git.
 *				5. else if(aþaðý gidilmemiþse), aþaðý git.
 *				6. 1. Adýma git
 *
 *			NOT: Sizden istenen çýkýþa giden yolu bulmak deðil, mümkün olan bütün yollarý bulmanýzdýr.
 */

#include <iostream>
#include <fstream>

using namespace std;

// Bu kod ile MAZE Algoritmasýna göre matriste arama yaparak matris içerisindeki bütün yollar bulunmaktadýr.
// Matris boyutlarý 20x70 olarak belirlendi.

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
	
	// Mümkün olan yollarý bul ve output dosyasýna bakýlan yollarý yaz
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
	} else if(labirent[i-1][j]!='#' && labirent[i-1][j]==' '){ // Yukarý
		i--;
		labirent[i][j]=' ';
		bul(labirent,i,j);
	} else if(labirent[i-1][j]!='#' && labirent[i+1][j]=='0'){ // Aþaðý
		i++;
		labirent[i][j]=' ';
		bul(labirent,i,j);
	} else if(labirent[i-1][j]!='#' && labirent[i][j-1]=='0'){ // Geri
		j--;
		labirent[i][j]=' ';
		bul(labirent,i,j);
	}
}
