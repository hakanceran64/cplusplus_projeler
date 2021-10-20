/*
 * Author: Hakan Ceran
 * Date: 19.09.2017
 * Content: http://ita.ee.lbl.gov/hmtl/contrib/NASA-HTTP.html linkinden ilgili datay� indiriniz.
 *			Linkteki data �u �ekildedir:
 *				gw4.att.com [01/Jun/1995:09:32:54 -0600] "GET/~macphed/finite/fe_resources/node32.html" 200 2254
 *
 *			�rnek veride ve indirece�imiz veride 5 s�tun vard�r ve �u anlamlara gelmektedirler:
 *			1. Hostname
 *			2. Zaman
 *			3. �stek G�nderilen Link
 *			4. HTTP Cevap Kodu
 *			5. Cevap Boyutu
 *			
 *			Bu projede sizden istenen hostname ve istek g�nderilen link'i indirdi�imiz dosyadan ay�r�p, farkl� bir dosyaya yazman�zd�r.
 *			Olu�turulmas� gereken dosyan�n bir sat�r� �u �ekilde olmal�d�r:
 *			gw4.att.com /~macphed/finite/fe_resources/node32.html
 */

#include <iostream> // cin, cout vs.
#include <clocale> // T�rk�e karakterler
#include <windows.h> // Arkaplan ve yaz� rengi
#include <fstream>
#include <string>
#include <vector>
#include <string.h>
#include <stdio.h>

using namespace std; // std::

/**********************************************************************************************************************
 * Bu projede kullan�lan log dosyas�n�                                                                                *
 * http://ita.ee.lbl.gov/html/contrib/NASA-HTTP.html linkinden indirebilirsiniz.                                      *
 *                                                                                                                    *
 * char *strtok(char *str, const char *delim) fonksiyonu delimeter yard�m�yla string(str)'i par�alar.                 *
 * Vector uzunlugu olmayan bir dizi gibi �al���r.                                                                     *
 * Vector'e yeni eleman eklemek i�in push_back metodu kullan�l�r.                                                     *
 * Vector'�n i�erisinde o anda ka� eleman bulundu�unu size metodu ile ��renilebilir.                                  *
 * Vector'�n her bir eleman�na bir dizinin her bir eleman�na eri�iyor gibi [] parantezleri kullan�larak eri�ilebilir. *
 **********************************************************************************************************************/

vector<string> ayir(string satir){
	// Okunan string char'a cast ediliyor. Yani string char dizisine d�n��t�r�l�yor.
	char* cstr=const_cast<char*>(satir.c_str());
	char* ayrilmis_satir_elemani;
	vector<string> ayrilmis_satir_dizisi;
	
	// strtok ile char dizisi par�alan�yor
	ayrilmis_satir_elemani=strtok(cstr," ");
	
	while(ayrilmis_satir_elemani!=NULL){
		ayrilmis_satir_dizisi.push_back(ayrilmis_satir_elemani);
		ayrilmis_satir_elemani=strtok(NULL," ");
	}
	
	return ayrilmis_satir_dizisi;
}

int main(){
	setlocale(LC_ALL, "turkish"); // T�rk�e Karakterleri Ekliyoruz
	system("color f9"); // Arkaplan ve yaz� rengi
	
	ifstream okunacak_dosya("deneme.txt");
	ofstream sonuc_dosyasi("output.txt");
	string satir;
	vector<string> ayrilmis_satir_dizisi;
	
	while(getline(okunacak_dosya,satir)){
		// ayir fonksiyonu burada �a�r�l�yor.
		ayrilmis_satir_dizisi=ayir(satir);
		sonuc_dosyasi << ayrilmis_satir_dizisi[0] + " " + ayrilmis_satir_dizisi[6].substr(0,ayrilmis_satir_dizisi[6].size()-1) << endl;
	}
	
	okunacak_dosya.close();
	sonuc_dosyasi.close();
	
	cout << "Dosya okundu ve ba�ar�l� bir �ekilde par�aland�." << endl;

	system("PAUSE");
	return 0;
}

