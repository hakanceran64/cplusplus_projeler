/*
 * Author: Hakan Ceran
 * Date: 01.09.2017
 * Content: Girdi olarak verilen n(n<=100) sayýsý boyutunda ekrana yýldýz karakteriyle baklava dilimi ve içerisinde bir kara olan þekli (aþaðýda örneði var) çiziniz.
 *			- n sayýsý 4'e bölündüðünde 2 kalanýný veren bir sayýdýr.
 * 			    **
 *			   *  *
 *			  *    *
 *			 * **** *
 *			*  *  *  *
 *			*  *  *  *
 *			 * **** *
 *			  *    *
 *			   *  *
 *			    **
 */

#include <iostream>

using namespace std;

int main(){
	
	int n, n2, n4;
	
	cout << "Bir n degeri giriniz: ";
	cin >> n;
	
	n2=n/2;
	n4=n/4;
	for(int i=0; i<n2; i++){
		for(int j=0; j<n2-1-i; ++j)
			cout << " ";
		cout << "*";
		if(i<n4+1)
			for(int j=0; j<2*i; ++j)
				cout << " ";
		else if(i==n4+1){
			cout << " ";
			for(int j=0; j<n2-1; ++j)
				cout << "*";
			cout << " ";
		} else{
			for(int j=0; j<(i-n4); ++j)
				cout << " ";
			cout << "*";
			for(int j=0; j<n2-3; ++j)
				cout << " ";
			cout << "*";
			for(int j=0; j<(i-n4); ++j)
				cout << " ";
		}
		cout << "*" << endl;
	}
	for(int i=n2-1; i>=0; --i){
		for(int j=0; j<n2-1-i; ++j)
			cout << " ";
		cout << "*";
		if(i<n4+1)
			for(int j=0; j<2*i; ++j)
				cout << " ";
		else if(i==n4+1){
			cout << " ";
			for(int j=0; j<n2-1; ++j)
				cout << "*";
			cout << " ";
		} else {
			for(int j=0; j<(i-n4); ++j)
				cout << " ";
			cout << "*";
			for(int j=0; j<n2-3; ++j)
				cout << " ";
			cout << "*";
			for(int j=0; j<(i-n4); ++j)
				cout << " ";
		}
		cout << "*" << endl;
	}

	system("PAUSE");
	return 0;
}

