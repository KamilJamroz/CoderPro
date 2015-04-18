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
    Bohater(string _nazwa, int _hp, int _mp, int _poziom)
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
    Wojownik(int _sila = 10, string nazwa = "kk", int hp = 3, int mp= 3, int poziom =3) : Bohater(nazwa, hp, mp, poziom)
    {
        sila = _sila;
    }

    void AtakMieczem()
    {
        //kod
    }

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
    Lucznik(int _zrecznosc = 10) : Bohater(nazwa = "Lucznik", hp = 80, mp = 40, poziom = 1)
    {
        zrecznosc = _zrecznosc;
    }

    void AtakLukiem()
    {
        //kod
    }

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
    Mag(int _silaWoli = 10) : Bohater(nazwa = "Mag", hp = 70, mp = 80, poziom = 1)
    {
        silaWoli = _silaWoli;
    }

    void MagicznyAtak()
    {
        //kod
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

    Wojownik mag1;
    mag1.setNazwa("Kamil");
    cout << mag1.getNazwa() << endl;



    return 0;
}
