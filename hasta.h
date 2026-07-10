#pragma once
#include<iostream>
#include<string>
using namespace std;

class dogumTarihi
{
	int gun, ay, yil;
public:
	dogumTarihi(int day=0, int month=0, int year=0) :gun(day), ay(month), yil(year) {}
	int getYil() { return yil; }
	int getAy() { return ay; }
	int getGun() { return gun; }

};

class Hasta
{
	int yas;
	string TC,password,name,surname;
	dogumTarihi birthday;
public:
	void yasHesapla();
	Hasta(string id, string pswrd, string nm, string snm, dogumTarihi bd);
	int getYas() { return yas; }
	string getTC() { return TC; }
	string getPassword() { return password; }
	string getName() { return name; }
	string getSurname() { return surname; }
	dogumTarihi getBirthday() { return birthday; }
};

