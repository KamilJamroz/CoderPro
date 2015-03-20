#include<iostream>
#include<string>

using namespace std;

class Elf
{
  private:
  string imie;
  int zycie;
  int szczescie;

  int LosujLiczbe()
  {
      int losowaLiczba{};
    //kod losuj¹cy liczbê w zakresie od 0 do 100
    return losowaLiczba;
  }

  int SzansaZadaniaCiosu()
  {
    int szansa = LosujLiczbe() * szczescie;
    return szansa;
  }

public:

 Elf(string _imie, int _zycie, int _szczescie) //konstruktor
  {
    imie = _imie;
    zycie = _zycie;
    szczescie = _szczescie;
  }

  ~Elf() //destruktor
  {
      cout << "BUM!" << endl;
  }

  int Atak(int szansa)
  {
     //kod ataku
  }

  string getImie()
  {
    return imie;
  }

  void setImie(string noweImie)
  {
    imie = noweImie;
  }

  int getZycie()
  {
    return zycie;
  }

  void setZycie(int noweZycie)
  {
    zycie = noweZycie;
  }

  int getSzczescie()
  {
    return zycie;
  }

  void setSzczescie(int noweSzczescie)
  {
    szczescie = noweSzczescie;
  }
};

int main()
{
   Elf gracz1("Ignacy", 100, 12);
cout << gracz1.getImie() << endl;

    return 0;
}
