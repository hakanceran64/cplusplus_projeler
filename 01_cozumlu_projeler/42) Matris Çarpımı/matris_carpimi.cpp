/*
 * Author: Hakan Ceran
 * Date: 29.08.2017
 * Content: Bu soruda girdi olarak verilen iki matrisin �arp�m�n� bulman�z ve ekrana yazd�rman�z istenmektedir.
 *			- Girdi format� �u �ekilde olacakt�r: ilk sat�rda s�ras� ile 2. matrisin sat�r(n1) ve s�t�n(m1) say�s� ve 2. matrisin sat�r(n2) ve s�tun (m2) say�s� verilecektir.
 *			  Birinci sat�r� takip eden n1 sat�rda her bir sat�rda m1 say� olmak �zere 1. matrisin say�lar� verilecektir ve bu sat�rlar� takip eden n2 sat�rda her bir sat�rda m2 say� olmak �zere 2. matrisin say�lar� verilecektir.
 *			  ��kt� olarak ekrana e�er bu iki matris �arp�labiliyorsa bu iki matrisin �arp�m�, e�er �arp�lam�yorsa -1 yazd�r�lacakt�r.
 *			- �ki matrisin �arp�labilmesi i�in 1. matrisin s�tun say�s� ile 2. matrisin sat�r say�s� ayn� olmal�d�r.
 */

#include <iostream>

#define MAX 101

using namespace std;

int main(){
	
	int mat1[MAX][MAX];
	int mat2[MAX][MAX];
	int carpim[MAX][MAX];
	int n1, m1, n2, m2, n3, m3;
	
	//Matris boyutlar�n� al
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
	
	// �arp�labiliyor mu?
	if(m1!=n2){
		cout << -1 << endl;
		return 0;
	}
	
	// �arp�m hesapla
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
	
	// �arp�m� yazd�r
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

