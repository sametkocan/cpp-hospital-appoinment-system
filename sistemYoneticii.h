#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<memory> //smart pointer kullanýmý icin
#include <cctype> // isdigit fonksiyonu için gerekli.
#include"Hastahane.h"

class sistemYonetici
{
	vector<hastaHane>hastaHaneler;
	vector<Hasta>hastalar;
public:
	void sistemiBaslat();
	void hastaKaydet(Hasta h);
	bool hastaGirisYap(string tc, string sifre);
	void hastahaneyeGoreRandevuAl();
	void poliklinigeGoreRandevuAl();
	int hataAyiklamaliSayiAl(int min, int max);
	bool sadeceRakamMi(string str);
};
