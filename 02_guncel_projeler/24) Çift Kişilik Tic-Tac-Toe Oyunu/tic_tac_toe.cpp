/*
 * Author: Hakan Ceran
 * Date: 23.09.2017
 * Content: Çift kiþilik tic-tac-toe oyunu
 *			Çift kiþilik oyananabilen bir tic-tac-toe oyunu yazýnýz.
 *			Yazýlacak olan program kodlarýnda dikkat etmeniz gereken hususlar aþaðýda listelenmiþtir.
 *			1. Boyutunu oyuncularýn belirleyeceði bir oyun þablonu oluþturulsun.
 *			2. Oyuncular sýrasýyla istedikleri yere X veya O girsin.
 *			3. Her bir oyuncu girdikten sonra oyunun son durumu gösterilsin.
 *			4. Eðer oyuncu oynadýðý anda yan yana 3 X, 3 O varsa oyuncuya puan verilsin ve oyun bitirilsin.
 */

#include <iostream> // cin, cout vs.
#include <clocale> // Türkçe karakterler
#include <windows.h> // Arkaplan ve yazý rengi

using namespace std; // std::

// Kullanýcýnýn oynayacaðý kareleri belirlemek için, 10 boyutlu bir char dizisi belirlendi. Fakat ilki 0. kare olmadýðý için kullanýlmadý.
char kare[10]={'0','1','2','3','4','5','6','7','8','9'};

// Kazananý kontrol et
int kazanan_kontrol();

// Oyun çizelgesinin ekranda görünümü
void gorunum();

int main(){
	setlocale(LC_ALL, "turkish"); // Türkçe Karakterleri Ekliyoruz
	system("color f9"); // Arkaplan ve yazý rengi
	
	int oyuncu=1, i=-1, secim=0;
	char isaretleme;
	
	while(i==-1){
		system("cls");
		gorunum();
		
		// Oyuncunun 2'ye bölümünden kalan 0 ise oyuncuya 1 atansýn deðil ise 2 atansýn
		oyuncu=(oyuncu%2) ? 1:2;
		
		cout << "Oyuncu " << oyuncu << ", bir numara giriniz: ";
		cin >> secim;
		
		isaretleme=(oyuncu==1) ? 'X' : 'O';
		
		// Eðer kullanýcýnýn iþaretlemek istediði yer boþ ise, orasý iþaretlenerek devam edilsin.
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
			cout << "Geçersiz Hamle ";
			oyuncu--;
		}
		i=kazanan_kontrol();
		oyuncu++;
	}
	
	system("cls");
	
	gorunum();
	
	if(i==1)
		cout << "Oyuncu " << --oyuncu << " Kazandý" << endl;
	else
		cout << "Oyun berabere bitti..." << endl;

	system("PAUSE");
	return 0;
}

/*
  Oyunun Durumlarý
   1 Kazanma durumu
   -1 Oyun devam eder
   0 Oyunun bitiþi ve beraberlik
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

// Oyun çizelgesinin ekranda görünümü
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

