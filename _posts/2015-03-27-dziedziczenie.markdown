---
layout:     post
title:      "Dziedziczenie"
subtitle:   "Dokładnie"

date:       2015-03-27 17:00:00
author:     "Mrozo"
header-img: "img/post-bg-08.jpg"
---

<h2 class="section-heading toph">Dziedziczenie</h2>

<p class="midmar">Często w naszych programach istnieją bardzo podobne klasy, które różnią się jedynie małymi szczegółami. Dla przykładu: klasa Wojownik, Mag i Łucznik. Wszyscy będą mieli podobne atrybuty takie jak życie, poziom, nazwa itp. W ten sposób powstanie nam masa klas posiadających w wielu miejscach dokładnie taki sam kod, czege byśmy nie chcieli. </p>

<pre class="colorx"><code class="c++">class Wojownik
{
private:
    string nazwa;
    int hp;
    int mp;
    int poziom;
    int sila;

public:
    void OkrzykBojowy()
    {
        cout << "Argh!";
    }

    void AtakMieczem()
    {
        //kod
    }

    //gettery i settery
};

class Lucznik
{
private:
    string nazwa;
    int hp;
    int mp;
    int poziom;
    int zrecznosc;

public:
    void OkrzykBojowy()
    {
        cout << "Argh!";
    }

    void AtakLukiem()
    {
        //kod
    }

    //gettery i settery
};

class Mag
{
private:
    string nazwa;
    int hp;
    int mp;
    int poziom;
    int silaWoli;

public:
    void OkrzykBojowy()
    {
        cout << "Argh!";
    }

    void MagicznyAtak()
    {
        //kod
    }

    //gettery i settery
};</code></pre>

<p>Nie wygląda to imponująco, nie pisałem getterów, setterów i konstruktora a i tak kod wygląda na zbyt powtórzony i bezsensowny. Aby rozwiązać ten problem będziemy dziedziczyć klasę z innej klasy:</p>

<pre class="colorx"><code class="c++">class Bohater
{
protected:
    string nazwa;
    int hp;
    int mp;
    int poziom;
public:
    void OkrzykBojowy()
    {
        cout << "Argh!";
    }

    //gettery i settery
};


class Wojownik : public Bohater
{
private:
    int sila;
public:
    void AtakMieczem()
    {
        //kod
    }
};

class Lucznik : public Bohater
{
private:
    int zrecznosc;
public:
    void AtakLukiem()
    {
        //kod
    }
};

class Mag : public Bohater
{
private:
    int silaWoli;
public:
    void MagicznyAtak()
    {
        //kod
    }
};</code></pre>

<p>Operatorem dwukropka informujemy, że nasza nowa klasa po prawej stronie ma odziedziczyć cechy po tej z prawej strony. Public po dwukropku to typ dziedziczenia o czym za chwilę napiszę. Jeżeli w klasie pochodnej chcielibyśmy nieco zmodyfikować  odziedziczoną metodę, piszemy ją na nowo a ona sama zostanie nadpisana. </p>

<h2 class="section-heading">Określanie dostępu do składników w klasie podstawowej</h2>

<p class="midmar"><span class="blue">private:</span><br>zostaną odziedziczone, w klasi pochodnej dalej będą prywatne.
<br><br>
<span class="blue">public i protected:</span><br>są bezpośrednio dostępne w klasie pochodnej. Protected znaczy, że dla wszystkich potomków tej klasy będzie on jak public, a dla reszty niedostępny czyli jak private. </p>

<h2 class="section-heading">Rodzaje dziedziczenia</h2>

<p class="midmar"><span class="blue">public:</span><br>składniki public z klasy podstawowej mają w klasie pochodnej również public, protected również zostaną protected (nic się nie zmienia)
<br><br>
<span class="blue">protected:</span><br>
składniki public i protected są w klasie pochodnej zabezpieczone jako protected
<br><br>
<span class="blue">private:</span><br>
składniki public oraz protected są w klasie pochodnej od teraz private</p>

<h2 class="section-heading">Co nie jest dziedziczone</h2>

<ul class="longmar">
<li> Konstruktor </li>
<li> Destruktor </li>
<li> Operator przypisania (=)</li>
</ul>

<pre class="colorx midmar"><code class="c++">int x = 10;
int *wsk; // deklaracja zmiennej wskaźnikowej
wsk = &x; // przypisanie zmiennej adresu komórki, w której mieści się x
cout << *wsk; // Jaka jest zawartość komórki o adresie &x? Oczywiście 10</code></pre>

<h2 class="section-heading">Konstruktor w klasie pochodnej</h2>

<p>Konstruktor musimy napisać sami, ponieważ każda klasa pochodna różni się między sobą. Aby nie przepisywać od nowa atrybutów klasy podstawowej robimy coś takiego:</p>

<pre class="colorx"><code class="c++">Bohater(string _nazwa, int _hp, int _mp, int _poziom) //konstruktor w klasie Bohater
    {
        nazwa = _nazwa;
        hp = _hp;
        mp = _mp;
        poziom = _poziom;
    }

Wojownik( string nazwa, int hp, int mp, int poziom, int _sila) : Bohater(nazwa, hp, mp, poziom) //konstruktor w klasie Wojownik
    {
        sila = _sila;
    }
</code></pre>

<p>Dodatkowo możemy ustawić wartości domyśle, które przyjmą się jeżeli sami nie wprowadzimy naszych podczas tworzenia obiektu: (tak można robić z każdym konstruktorem, w klasie podstawowej również)</p>

Wojownik(int _sila = 10) : Bohater(nazwa = "nazwa", hp = 100, mp = 20, poziom = 1) //konstruktor w klasie Wojownik
    {
        sila = _sila;
    }

h2 class="section-heading">Dodatki</h2>

<p class="midmar">Do zaprezentowania dziedziczenia konstruktora w klasie pochodnej użyłem preambuły konstruktora, prościej listy inicjalizacyjnej.</p>

<a href="../../../../files/lekcja8.cpp" target="_blank">Kompletny kod pliku main.cpp (click)</a>

