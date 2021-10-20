/*
 * Author: Hakan Ceran
 * Date: 23.09.2017
 * Content: �ift ki�ilik tic-tac-toe oyunu
 *			�ift ki�ilik oyananabilen bir tic-tac-toe oyunu yaz�n�z.
 *			Yaz�lacak olan program kodlar�nda dikkat etmeniz gereken hususlar a�a��da listelenmi�tir.
 *			1. Boyutunu oyuncular�n belirleyece�i bir oyun �ablonu olu�turulsun.
 *			2. Oyuncular s�ras�yla istedikleri yere X veya O girsin.
 *			3. Her bir oyuncu girdikten sonra oyunun son durumu g�sterilsin.
 *			4. E�er oyuncu oynad��� anda yan yana 3 X, 3 O varsa oyuncuya puan verilsin ve oyun bitirilsin.
 */

#include <iostream> // cin, cout vs.
#include <clocale> // T�rk�e karakterler
#include <windows.h> // Arkaplan ve yaz� rengi

using namespace std; // std::

// Kullan�c�n�n oynayaca�� kareleri belirlemek i�in, 10 boyutlu bir char dizisi belirlendi. Fakat ilki 0. kare olmad��� i�in kullan�lmad�.
char kare[10]={'0','1','2','3','4','5','6','7','8','9'};

// Kazanan� kontrol et
int kazanan_kontrol();

// Oyun �izelgesinin ekranda g�r�n�m�
void gorunum();

int main(){
	setlocale(LC_ALL, "turkish"); // T�rk�e Karakterleri Ekliyoruz
	system("color f9"); // Arkaplan ve yaz� rengi
	
	int oyuncu=1, i=-1, secim=0;
	char isaretleme;
	
	while(i==-1){
		system("cls");
		gorunum();
		
		// Oyuncunun 2'ye b�l�m�nden kalan 0 ise oyuncuya 1 atans�n de�il ise 2 atans�n
		oyuncu=(oyuncu%2) ? 1:2;
		
		cout << "Oyuncu " << oyuncu << ", bir numara giriniz: ";
		cin >> secim;
		
		isaretleme=(oyuncu==1) ? 'X' : 'O';
		
		// E�er kullan�c�n�n i�aretlemek istedi�i yer bo� ise, oras� i�aretlenerek devam edilsin.
		if(secim==1 && kare[1]=='1')
			kare[1]=isaretleme;
		else if(secim==2 && kare[2]=='2')
			kare[2]=isaretleme;
		else if(secim==3 && kare[3]=='3')
			kare[3]=isaretleme;
		else if(secim==4 && kare[4]=='4')
			kare[4]=isaretleme;
		else if(secim==5 && kare[5]=='5')
			kare[5]=isaretleme;
		else if(secim==6 && kare[6]=='6')
			kare[6]=isaretleme;
		else if(secim==7 && kare[7]=='7')
			kare[7]=isaretleme;
		else if(secim==8 && kare[8]=='8')
			kare[8]=isaretleme;
		else if(secim==9 && kare[9]=='9')
			kare[9]=isaretleme;
		else{
			cout << "Ge�ersiz Hamle ";
			oyuncu--;
		}
		i=kazanan_kontrol();
		oyuncu++;
	}
	
	system("cls");
	
	gorunum();
	
	if(i==1)
		cout << "Oyuncu " << --oyuncu << " Kazand�" << endl;
	else
		cout << "Oyun berabere bitti..." << endl;

	system("PAUSE");
	return 0;
}

/*
  Oyunun Durumlar�
   1 Kazanma durumu
   -1 Oyun devam eder
   0 Oyunun biti�i ve beraberlik
*/
int kazanan_kontrol(){
	if(kare[1]==kare[2] && kare[2]==kare[3])
		return 1;
	else if(kare[4]==kare[5] && kare[5]==kare[6])
		return 1;
	else if(kare[7]==kare[8] && kare[8]==kare[9])
		return 1;
	else if(kare[1]==kare[4] && kare[4]==kare[7])
		return 1;
	else if(kare[2]==kare[5] && kare[5]==kare[8])
		return 1;
	else if(kare[3]==kare[6] && kare[6]==kare[9])
		return 1;
	else if(kare[1]==kare[5] && kare[5]==kare[9])
		return 1;
	else if(kare[3]==kare[5] && kare[5]==kare[7])
		return 1;
	else if(kare[1]!='1' && kare[2]!='2' && kare[3]!='3' && kare[4]!='4' && kare[5]!='5' && kare[6]!='6' && kare[7]!='7' && kare[8]!='8' && kare[9]!='9')
		return 0;
	else
		return -1;
}

// Oyun �izelgesinin ekranda g�r�n�m�
void gorunum(){
	cout << endl << endl << "Tic Tac Toe" << endl << endl;
	
	cout << "Oyuncu 1(X) - Oyuncu 2(O)" << endl << endl << endl;
	cout << "   |   |   " << endl;
	
	cout << " " << kare[1] << " | " << kare[2] << " | " << kare[3] << endl;
	cout << "___|___|___" << endl;
	cout << "   |   |" << endl;

	cout << " " << kare[4] << " | " << kare[5] << " | " << kare[6] << endl;
	cout << "___|___|___" << endl;
	cout << "   |   |   " << endl;

	cout << " " << kare[7] << " | " << kare[8] << " | " << kare[9] << endl;
	cout << "   |   |   " << endl << endl;
}

