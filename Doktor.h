#pragma once
#include<iostream>
#include<string>
using namespace std;


class Doktor
{
	string name, surname, brans;
	bool randevuSlotlari[18];
public:
	Doktor(string nm="Tanimsiz", string snm="Tanimsiz", string brn="Tanimsiz");
	string getBrans() { return brans; }
	void getRandevular();
	string getDoctorname() { return name; }
	string getDoctorSurname() { return surname; }
	bool randevuAl(int slotNo);
};
