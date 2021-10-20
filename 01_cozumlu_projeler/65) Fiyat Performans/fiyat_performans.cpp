/*
 * Author: Hakan Ceran
 * Date: 07.09.2017
 * Content: Girdi olarak verilen n (mak. 1000) tane cep telefonu bilgilerinden cep telefonlarýnýn fiyat performans notunu hesaplayan ve cep telefonlarýný bu fiyat performansa göre büyükten küçüge doðru sýralayan programý istenilen yapý ve fonksiyonlarý kodalayarak çözünüz.
 *			cep_telefonu yapýsý: Bir cep telefonunun bilgilerini saklayabilen bir yapýdýr. Cep telefonunun bütün özellikleri maksimum 10 karekterlidir.
 *			puan_hesapla(): Parametre olarka gelen cep telefonu  dizisini ve bu dizinin uzunluðunu kullanarak her bir cep telefonunun fiyat performansýný hesaplayan fonksiyondur.
 *							Hesaplama yapýlýrken kullanýlacak tablo aþaðýda verilmiþtir.
 *
 *							=================================================================
 *							= Özellik/Puan			0		1		2		3		4		=
 *							= Ýþletim Sistemi(ÝS)	Windows	Android	IOS						=
 *							= Dahili Bellek(DB)		<16		>=16	>=32	>=64	>=128	=
 *							= Ýþlemci Hýzý(ÝH)		<1.5	>=1.5	>=1.8	>=2.0	>=2.3	=
 *							= Kalite(KA)			Kötü	Orta	Ýyi		Çok iyi			=
 *							= Tasarim(TA)			Kötü	Orta 	Ýyi		Çok iyi			=
 *							=================================================================
 *
 *			K = Fiyat/5;
 *			A = (K*ÝS/2)+(K*DB/4)+(K*ÝH/4)+(K*KA/3)+(K*TA/3)
 *			Puan = A*100/Fiyat
 *
 *			puana_gore_sirala(): Parametre olarak gelen cep telefonu dizisini ve bu dizinin uzunlugunu kullanarak bu diziyi cep telefonlarýnýn fiyat performans deðerine göre büyükten küçüðe doðru sýralayan fonksiyondur.
 *
 *			NOT=Sýralama yaparken ayný deðerleri yer deðiþtirmeyiniz.
 */

#include <iostream>
#include <iomanip>
#include <cstring>

#define MAX 1000

using namespace std;

struct cep_telefonu{
	char marka[10];
	char model[10];
	char isletim_sistemi[10];
	double dahili_bellek;
	double islemci_hizi;
	char kalite[10];
	char tasarim[10];
	int fiyat;
	double puan;
};

void puan_hesapla(struct cep_telefonu *telefonlar, int n){
	double k, a, is, db, ih, ka, ta;
	
	for(int i=0; i<n; ++i){
		k=telefonlar[i].fiyat/5.0;
		
		// Ýþletim Sistemleri
		if(strncmp(telefonlar[i].isletim_sistemi,"Windows",10)==0)
			is=0;
		else if(strncmp(telefonlar[i].isletim_sistemi,"Android",10)==0)
			is=1;
		else if(strncmp(telefonlar[i].isletim_sistemi,"IOS",10)==0)
			is=2;
		
		// Dahili Bellek
		if(telefonlar[i].dahili_bellek>=128)
			db=4;
		else if(telefonlar[i].dahili_bellek>=64)
			db=3;
		else if(telefonlar[i].dahili_bellek>=32)
			db=2;
		else if(telefonlar[i].dahili_bellek>=16)
			db=1;
		else
			db=0;
		
		// Ýþlemci Hýzý
		if(telefonlar[i].islemci_hizi>=2.3)
			ih=4;
		else if(telefonlar[i].islemci_hizi>=2.0)
			ih=3;
		else if(telefonlar[i].islemci_hizi>=1.8)
			ih=2;
		else if(telefonlar[i].islemci_hizi>=1.5)
			ih=1;
		else
			ih=0;
		
		// Kalite
		if(strncmp(telefonlar[i].kalite,"Kotu",10)==0)
			ka=0;
		else if(strncmp(telefonlar[i].kalite,"Orta",10)==0)
			ka=1;
		else if(strncmp(telefonlar[i].kalite,"Iyi",10)==0)
			ka=2;
		else if(strncmp(telefonlar[i].kalite,"CokIyi",10)==0)
			ka=3;
		
		// Tasarým
		if(strncmp(telefonlar[i].tasarim,"Kotu",10)==0)
			ta=0;
		else if(strncmp(telefonlar[i].tasarim,"Orta",10)==0)
			ta=1;
		else if(strncmp(telefonlar[i].tasarim,"Iyi",10)==0)
			ta=2;
		else if(strncmp(telefonlar[i].tasarim,"CokIyi",10)==0)
			ta=3;
		
		a = k*is/2 + k*db/4 + k*ih/4 + k*ka/3 + k*ta/3;
		telefonlar[i].puan=a*100/telefonlar[i].fiyat;
	}
}

void puana_gore_sirala(struct cep_telefonu *telefonlar, int n){
	struct cep_telefonu tmp;
	int puan1, puan2;
	
	for(int i=n-1; i>0; --i)
		for(int j=0; j<i; ++j){
			puan1=telefonlar[j].puan*100;
			puan2=telefonlar[j+1].puan*100;
			
			if(puan1<puan2){
				tmp=telefonlar[j];
				telefonlar[j]=telefonlar[j+1];
				telefonlar[j+1]=tmp;
			}
		}
}

int main(){
	
	struct cep_telefonu cepler[MAX];
	int n;
	
	cout << "Bir n degeri giriniz: ";
	cin >> n;
	
	cout << endl << "Marka\tModel\tIsletim sistemi\tDahile Bellek\tIslemci Hizi\tKalite\tTasarim\tFiyat" << endl;
	for(int i=0; i<n; ++i)
		cin >> cepler[i].marka >> cepler[i].model >> cepler[i].isletim_sistemi >> cepler[i].dahili_bellek >> cepler[i].islemci_hizi >> cepler[i].kalite >> cepler[i].tasarim >> cepler[i].fiyat;
	
	puan_hesapla(cepler,n);
	puana_gore_sirala(cepler,n);
	
	cout << endl << "Telefonlar: " << endl;
	cout << fixed << setprecision(2);
	
	for(int i=0; i<n; ++i)
		cout << cepler[i].puan << " " << cepler[i].marka << " " << cepler[i].model << endl << endl;

	system("PAUSE");
	return 0;
}

