/*
 * Author: Hakan Ceran
 * Date: 02.09.2017
 * Content: Girdi olarak verilen n(n<=100) sayýsý boyutunda ekrana yýldýz karakterleriyle aþaðýdaki þekli çizen programý yazýnýz.
 *			            *
 *			          * *
 *			        *   *
 *			      *     *
 *			    * * *   *
 *			  *   *  *  *
 *			*     *     *
 *			  *   *  *  *
 *			    * * *   *
 *			      *     *
 *			        *   *
 *			          * *
 *			            *
 */

#include <iostream>

using namespace std;

int main(){
	
	int n;
	
	cout << "Bir n degeri giriniz: ";
	cin >> n;
	
	for(int i=0; i<2*n-1; ++i){
		for(int j=0; j<n; ++j)
			if(j==n-1)
				cout << "* ";
			else if(i+j==n-1)
				cout << "* ";
			else if(i-n+1==j)
				cout << "* ";
			else if(i>=n/2 && i<3*n/2 && j==n/2)
				cout << "* ";
			else if(i>=n/2 && i<3*n/2 && i==j)
				cout << "* ";
			else if(i>=n/2 && i<3*n/2 && i+j==2*n-2)
				cout << "* ";
			else
				cout << "  ";
		cout << endl;
	}

	system("PAUSE");
	return 0;
}

