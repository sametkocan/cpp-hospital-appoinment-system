#pragma once
#include<iostream>
#include<string>
#include<vector>
#include"Doktor.h"
#include"hasta.h"

using namespace std;

class hastaHane
{
	string name;
	vector<Doktor> doktorlar;
public:
	hastaHane(string nm) :name(nm){}
	void doktorEkle(Doktor d);
	string getHastahaneAdi() { return name; }
	vector<Doktor>& getDoktorlar() { return doktorlar; }
};