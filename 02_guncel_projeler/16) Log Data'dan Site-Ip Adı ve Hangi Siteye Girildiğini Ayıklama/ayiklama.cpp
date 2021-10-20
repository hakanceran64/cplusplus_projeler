/*
 * Author: Hakan Ceran
 * Date: 19.09.2017
 * Content: http://ita.ee.lbl.gov/hmtl/contrib/NASA-HTTP.html linkinden ilgili datayý indiriniz.
 *			Linkteki data þu þekildedir:
 *				gw4.att.com [01/Jun/1995:09:32:54 -0600] "GET/~macphed/finite/fe_resources/node32.html" 200 2254
 *
 *			Örnek veride ve indireceðimiz veride 5 sütun vardýr ve þu anlamlara gelmektedirler:
 *			1. Hostname
 *			2. Zaman
 *			3. Ýstek Gönderilen Link
 *			4. HTTP Cevap Kodu
 *			5. Cevap Boyutu
 *			
 *			Bu projede sizden istenen hostname ve istek gönderilen link'i indirdiðimiz dosyadan ayýrýp, farklý bir dosyaya yazmanýzdýr.
 *			Oluþturulmasý gereken dosyanýn bir satýrý þu þekilde olmalýdýr:
 *			gw4.att.com /~macphed/finite/fe_resources/node32.html
 */

#include <iostream> // cin, cout vs.
#include <clocale> // Türkçe karakterler
#include <windows.h> // Arkaplan ve yazý rengi
#include <fstream>
#include <string>
#include <vector>
#include <string.h>
#include <stdio.h>

using namespace std; // std::

/**********************************************************************************************************************
 * Bu projede kullanýlan log dosyasýný                                                                                *
 * http://ita.ee.lbl.gov/html/contrib/NASA-HTTP.html linkinden indirebilirsiniz.                                      *
 *                                                                                                                    *
 * char *strtok(char *str, const char *delim) fonksiyonu delimeter yardýmýyla string(str)'i parçalar.                 *
 * Vector uzunlugu olmayan bir dizi gibi çalýþýr.                                                                     *
 * Vector'e yeni eleman eklemek için push_back metodu kullanýlýr.                                                     *
 * Vector'ün içerisinde o anda kaç eleman bulunduðunu size metodu ile öðrenilebilir.                                  *
 * Vector'ün her bir elemanýna bir dizinin her bir elemanýna eriþiyor gibi [] parantezleri kullanýlarak eriþilebilir. *
 **********************************************************************************************************************/

vector<string> ayir(string satir){
	// Okunan string char'a cast ediliyor. Yani string char dizisine dönüþtürülüyor.
	char* cstr=const_cast<char*>(satir.c_str());
	char* ayrilmis_satir_elemani;
	vector<string> ayrilmis_satir_dizisi;
	
	// strtok ile char dizisi parçalanýyor
	ayrilmis_satir_elemani=strtok(cstr," ");
	
	while(ayrilmis_satir_elemani!=NULL){
		ayrilmis_satir_dizisi.push_back(ayrilmis_satir_elemani);
		ayrilmis_satir_elemani=strtok(NULL," ");
	}
	
	return ayrilmis_satir_dizisi;
}

int main(){
	setlocale(LC_ALL, "turkish"); // Türkçe Karakterleri Ekliyoruz
	system("color f9"); // Arkaplan ve yazý rengi
	
	ifstream okunacak_dosya("deneme.txt");
	ofstream sonuc_dosyasi("output.txt");
	string satir;
	vector<string> ayrilmis_satir_dizisi;
	
	while(getline(okunacak_dosya,satir)){
		// ayir fonksiyonu burada çaðrýlýyor.
		ayrilmis_satir_dizisi=ayir(satir);
		sonuc_dosyasi << ayrilmis_satir_dizisi[0] + " " + ayrilmis_satir_dizisi[6].substr(0,ayrilmis_satir_dizisi[6].size()-1) << endl;
	}
	
	okunacak_dosya.close();
	sonuc_dosyasi.close();
	
	cout << "Dosya okundu ve baþarýlý bir þekilde parçalandý." << endl;

	system("PAUSE");
	return 0;
}

