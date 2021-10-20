/*
 * Author: Hakan Ceran
 * Date: 29.08.2017
 * Content: Bu soruda girdi olarak verilen iki matrisin çarpýmýný bulmanýz ve ekrana yazdýrmanýz istenmektedir.
 *			- Girdi formatý þu þekilde olacaktýr: ilk satýrda sýrasý ile 2. matrisin satýr(n1) ve sütýn(m1) sayýsý ve 2. matrisin satýr(n2) ve sütun (m2) sayýsý verilecektir.
 *			  Birinci satýrý takip eden n1 satýrda her bir satýrda m1 sayý olmak üzere 1. matrisin sayýlarý verilecektir ve bu satýrlarý takip eden n2 satýrda her bir satýrda m2 sayý olmak üzere 2. matrisin sayýlarý verilecektir.
 *			  Çýktý olarak ekrana eðer bu iki matris çarpýlabiliyorsa bu iki matrisin çarpýmý, eðer çarpýlamýyorsa -1 yazdýrýlacaktýr.
 *			- Ýki matrisin çarpýlabilmesi için 1. matrisin sütun sayýsý ile 2. matrisin satýr sayýsý ayný olmalýdýr.
 */

#include <iostream>

#define MAX 101

using namespace std;

int main(){
	
	int mat1[MAX][MAX];
	int mat2[MAX][MAX];
	int carpim[MAX][MAX];
	int n1, m1, n2, m2, n3, m3;
	
	//Matris boyutlarýný al
	cout << "Matris boyutlarini giriniz(n1, m1, n2, m2): ";
	cin >> n1 >> m1 >> n2 >> m2;
	
	// Mat1 al
	cout << endl << "Matris 1i giriniz: " << endl;
	for(int i=0; i<n1; ++i){
		for(int j=0; j<m1; ++j){
			cin >> mat1[i][j];
		}
	}

	// Mat2 al
	cout << "Matris 2yi giriniz: " << endl;
	for(int i=0; i<n2; ++i){
		for(int j=0; j<m2; ++j){
			cin >> mat2[i][j];
		}
	}
	
	// Çarpýlabiliyor mu?
	if(m1!=n2){
		cout << -1 << endl;
		return 0;
	}
	
	// Çarpým hesapla
	n3=n1;
	m3=m2;
	
	for(int i=0; i<n1; ++i){
		for(int j=0; j<m2; ++j){
			int tmp=0;
			for(int k=0; k<m1; ++k){
				tmp+=mat1[i][k]*mat2[k][j];
			}
			carpim[i][j]=tmp;
		}
	}
	
	// Çarpýmý yazdýr
	cout << "Carpim: " << endl;
	for(int i=0; i<n3; ++i){
		for(int j=0; j<m3; ++j){
			cout << carpim[i][j] << " ";
		}
		cout << endl;
	}
	
	cout << endl;

	system("PAUSE");
	return 0;
}

