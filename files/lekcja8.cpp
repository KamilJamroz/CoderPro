#include<iostream>
#include<string>

using namespace std;

class Bohater
{
protected:
	string nazwa;
	int hp;
	int mp;
	int poziom;

public:
	Bohater(string _nazwa = "Bohater", int _hp = 100, int _mp = 0, int _poziom = 1)
	{
		nazwa = _nazwa;
		hp = _hp;
		mp = _mp;
		poziom = _poziom;
	}

	void OkrzykBojowy()
	{
		cout << "Argh!";
	}

	// SETTERY I GETTERY

	void setNazwa(string _nazwa)
	{
		nazwa = _nazwa;
	}

	string getNazwa()
	{
		return nazwa;
	}

	void setHp(int _hp)
	{
		hp = _hp;
	}

	int getHp()
	{
		return hp;
	}

	void setMp(int _mp)
	{
		hp = _mp;
	}

	int getMp()
	{
		return mp;
	}

	// SETTERY I GETTERY

	void setPoziom(int _poziom)
	{
		poziom = _poziom;
	}

	int getPoziom()
	{
		return poziom;
	}
};


class Wojownik : public Bohater
{
private:
	int sila;
public:
	Wojownik( string nazwa = "Wojownik", int hp = 100, int mp = 20, int poziom = 1, int _sila = 20) : Bohater(nazwa, hp, mp, poziom)
	{
		sila = _sila;
	}

	void AtakMieczem()
	{
		cout << "Brzdek!" << endl;
	}

	// SETTERY I GETTERY

	void setSila(int _sila)
	{
		sila = _sila;
	}

	int getSila()
	{
		return sila;
	}
};

class Lucznik : public Bohater
{
private:
	int zrecznosc;
public:
	Lucznik(string nazwa = "Lucznik", int hp = 80, int mp = 40, int poziom = 1, int _zrecznosc = 20) : Bohater(nazwa, hp, mp, poziom)
	{
		zrecznosc = _zrecznosc;
	}

	void AtakLukiem()
	{
		cout << "Wzium!" << endl;
	}

	// SETTERY I GETTERY

	void setZrecznosc(int _zrecznosc)
	{
		zrecznosc = _zrecznosc;
	}

	int getZrecznosc()
	{
		return zrecznosc;
	}
};

class Mag : public Bohater
{
private:
	int silaWoli;
public:
	Mag(string nazwa = "Mag", int hp = 60, int mp = 100, int poziom = 1, int _silaWoli = 20) : Bohater(nazwa, hp, mp, poziom)
	{
		silaWoli = _silaWoli;
	}

	void MagicznyAtak()
	{
		cout << "Zzip!" << endl;
	}

	void setSilaWoli(int _silaWoli)
	{
		silaWoli = _silaWoli;
	}

	int getSilaWoli()
	{
		return silaWoli;
	}
};

int main()
{
	Wojownik wojownik1;

	cout << wojownik1.getNazwa();
	cout << ": ";
	wojownik1.AtakMieczem();

	Lucznik lucznik1("Fred", 100, 30, 3, 30);

	cout << lucznik1.getNazwa();
	cout << ": ";
	lucznik1.AtakLukiem();

	Mag mag1;

	cout << mag1.getNazwa();
	cout << ": ";
	mag1.MagicznyAtak();

	return 0;
}