---
layout:     post
title:      "W końcu!"
subtitle:   "Struktury, klasy, obiekty"

date:       2015-03-20 20:30:00
author:     "Mrozo"
header-img: "img/post-bg-07.jpg"
---

<h2 class="section-heading toph">Struktura</h2>

<p class="midmar">Jak dobrze wiemy, tablica pozwala nam przechować wiele zmiennych tego samego typu danych.<br />
A co jeśli chcielibyśmy ugrupować elementy różnych typów np string, float i int? <br />
Nie da się zrobić tego tablicą, ponieważ co wpiszemy w miejsce typu danych?</p>

<pre class="colorx midmar"><code class="c++">string, float, int tablica{}; //to nie zadziała :P
</code></pre>

<p class="midmar">Musimy stworzyć własny typ danych! A oto sposób jak tego dokonać:</p>

<pre class="colorx midmar"><code class="c++">struct Czlowiek
{
  string imie;
  string nazwisko;
  int wiek;
};
</code></pre>

<p class="midmar">Stworzyliśmy własny typ danych. Jak go użyć? Podobnie jak robimy to z typami int, double itd:</p>

<pre class="colorx midmar"><code class="c++">int main() {

  Czlowiek nazwa_zmiennej = { "Adam", "Kowalski", 19 };

  Czlowiek marek = {
    "Marek",
    "Nowak",
    26
  };
}</code></pre>

<p class="midmar">Udało nam się pogrupować różne typy danych w coś większego - strukturę. Ale teraz jak możemy dostać się do jej elementów? Za pomocą operatora kropki:</p>

<pre class="colorx midmar"><code class="c++">cout << "Imie: " << marek.imie << endl;
cout << "Nazwisko: " << marek.nazwisko << endl;
cout << "Wiek: " << marek.wiek << endl;

marek.wiek = 10;

cout << "Nowy wiek: " << marek.wiek << endl;</code></pre>

<pre>Imie: Marek
Nazwisko: Nowak
Wiek: 26
Nowy wiek: 10</pre>

<p>Struktury są bardzo przydatne i używa się ich naprawdę dużo w większych projektach. Musisz zauważyć jak bardzo mogą być pomocne. Używając ich zaoszczędzisz masę czasu, a twój kod będzie czytelniejszy.</p>

<h2 class="section-heading">Od innej strony - Klasy i Obiekty</h2>

<p class="midmar">Róża. Co stanęło ci przed oczami? Właściwości typu kolor, wysokość, wiek, zapach? Nie sądzę. Róża może mieś dziesiątki kolorów a my wyobrażamy sobie tylko jeden. Człowiek myśli obiektowo, to dlaczego nie miałby w taki sam sposób programować? W programowaniu obiektowym istnieją dwa podstawowe pojęcia: obiekt i klasa. <span class="blue">Klasa</span> róży to będzie zbiór wszystkich jej cech (ale nie określonych dokładnie) takich jak np zapach czy kolor. Innymi słowy klasa to taki przepis na róże, czym ona może się charakteryzować. <span class="blue">Obiekt</span> to coś, co powstało według klasy.</p>

<pre class="colorx nullmar"><code class="c++">class Wojownik
{
public:
  string imie;
  string przydomek;
  int zycie;
  int atak;
  int pancerz;

  string OkrzykBojowy()
  {
    return "AAArgh!!";
  }

  int Atak()
  {
    //kod ataku
  }
};</code></pre>

<table><tbody><tr><th><p class="null">Klasy i struktury kończy się nawiasem klamrowym i średnikiem!</p></th></tr><th class="red"></th></tbody></table>

<p class="midmar">To co widzisz powyżej to przykład klasy. To trochę taka struktura, która potrafi wykonywać funkcje i wiele, wieele innych rzeczy ;). To również nowy typ danych.</p>

<pre class="colorx midmar"><code class="c++">Wojownik gracz1;
gracz1.imie = "Adalbert";
gracz1.przydomek = "Wielki";
gracz1.zycie = 100;
gracz1.atak = 25;
gracz1.pancerz = 50;

cout << gracz1.imie << " " << gracz1.przydomek << ": "
     << gracz1.OkrzykBojwy() << endl;</code></pre>

<pre>Adalbert Wielki: AAArgh!!</pre>

<p class="nullmar">Powyżej widzimy obiekt klasy Wojownik o nazwie gracz1. Jednak parę rzeczy jeszcze nie jest do końca jasnych: co to jest public i czy da się jakoś skrócić proces nadawania wartości atrybutów obiektu gracz1. Jeżeli byłoby ich więcej stracilibyśmy sporo czasu na samym pisaniu "gracz1.atrybut =".</p>

<table><tbody><tr><th><p class="null">Zmienne w klasie noszą nazwę atrybutów<br />
Funkcje w klasie to metody</p></th></tr><th class="green"></th></tbody></table>

<h2 class="section-heading">Public i Private</h2>

<pre class="colorx midmar"><code class="c++">class Elf
{
  string imie;
  int zycie;
  int szczescie;

  int LosujLiczbe()
  {
    //kod losujący liczbę w zakresie od 0 do 100
    return losowaLiczba;
  }

  int SzansaZadaniaCiosu()
  {
    int szansa = LosujLiczbe() * szczescie;
    return szansa;
  }

  int Atak(int szansa)
  {
     //kod ataku
  }
};</code></pre>

<p class="midmar">Istnieje bardzo wiele sytuacji, w których to nie chcielibyśmy aby obiekt korzystał z danej metody czy atrybutu. Powyżej trywialny przykład - po co obiekt miałby mieć dostęp do losowania liczby i obliczania szansy zadania ciosu? <br />On potrzebuje tylko wykonać funkcje atak, reszta samoistnie nie ma sensu zostawać wywoływana. <br /><br />
Inny przykład: Piszemy program kryptograficzny, który posiada funkcję szyfrujące tajne dane. Obiekt nie może mieć dostępu (odczyt i zmiana) do atrybutów, które przechowują tajne algorytny czy sam szyfr ze względu na bezpieczeństwo:<br /></p>

<pre class="midmar">szyfr1.tajnaZmienna = 69; //Każdy ma dostęp do tajnej zmiennej!</pre>

<p class="midmar">
Jeżeli nie napiszemy ani private, ani public, wszystko w naszej klasie będzie domyślnie prywatne (Nasz obiekt nie będzie mógł nawet nazwać elfa czy wykonać metodę Atak!).
Z tego względu wszystko co ma być używane wyłącznie przez klasę piszemy pod słowem <span class="blue">private:</span>
a wszystko to do czego ma mieć również dostęp obiekt piszemy pod słowem <span class="blue">public:</span>
</p>

<pre class="colorx midmar"><code class="c++">class Elf
{
private:
  int LosujLiczbe()
  {
    //kod losujący liczbę w zakresie od 0 do 100
    return losowaLiczba;
  }

  int SzansaZadaniaCiosu()
  {
    int szansa = LosujLiczbe() * szczescie;
    return szansa;
  }

public:
  string imie;
  int zycie;
  int szczescie;

  int Atak(int szansa)
  {
     //kod ataku
  }
};</code></pre>

<p>Istnieje jeszcze typ: <span class="blue">protected</span>, jednak tym zajmiemy się przy dziedziczeniu. Teraz wszyscy są szczęśliwi. Prawie.</p>

<h2 class="section-heading">Gettery i Settery - Hermetyzacja danych</h2>

<p class="midmar">Nasze atrybuty dalej są całkowicie odsłonięte a w dodatku ktoś kto pierwszy raz widzi nasz kod nie wie czy zmienna szczecsie może być modyfikowana. Po upływie czasu wy sami nie będziecie pamiętali co w waszym programie może być ruszane przez obiekt. Dlatego znakomitym pomysłem jest zabezpieczenie zmiennych tak aby były prywatne jednocześnie dając możliwość używania ich przez obiekt. W tym celu stworzymy najprostsze w świecie funkcje:<br />
<span class="blue">Getter</span> to metoda pozwalająca pobrać wartość atrybutu.<br />
<span class="blue">Setter</span> to metoda pozwalająca zmienić wartość atrybutu.</p>

<pre class="colorx midmar"><code class="c++">class Elf
{
private:
  string imie;
  int zycie;
  int szczescie;

  int LosujLiczbe()
  {
    //kod losujący liczbę w zakresie od 0 do 100
    return losowaLiczba;
  }

  int SzansaZadaniaCiosu()
  {
    int szansa = LosujLiczbe() * szczescie;
    return szansa;
  }

public:
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
};</code></pre>

<p class="midmar">Teraz jeżeli chcemy aby coś było nieosągalne z poziomu obiektu po prostu kasujemy jego getter czy setter w zależności od sytuacji. Jednocześnie takim sposobem wyraźnie widać, które atrybuty mogą być modifikowane, które mogą pobrać wartość np do wyświetlenia jej na ekranie, a których kompletnie nie można tykać.</p>

<pre class="colorx midmar"><code class="c++">Elf gracz1;
gracz1.setImie("Legolas");
gracz1.setZycie(100);
gracz1.setSzczescie(8);
gracz1.setSzczescie(10);
cout << gracz1.getImie();</code></pre>

<p>Znów "gracz.bleble(bleble)"x100 w kodzie. Zajmijmy się tym.</p>

<h2 class="section-heading">Konstruktory i Destruktory</h2>

<p class="midmar">Praktycznie w każdym przypadku tworząc obiekt chcemy nadać jego atrybutom początkowe wartości. Do tej pory robiliśmy to linijka po linijce. Lepszym rozwiązaniem jest <span class="blue">konstruktor</span>, czyli po prostu specjalna funkcja, która wywoływana jest wraz ze stworzeniem obiektu. Konstruktor ma taką samą nazwę jak klasa i zawsze powinien być dostępny publicznie:</p>

<pre class="colorx lowmar"><code class="c++">class Elf
{
private:
  string imie;
  int zycie;
  int szczescie;

  //Metody prywatne (LosujLiczbe, SzansaZadaniaCiosu)

public:

  Elf() //<- to jest konstruktor.
  {
    cout << "Obiekt zostal stworzony!";
  }

  //Metody publiczne (Atak)

  //Gettery i Settery
};</code></pre>

<pre class="colorx midmar"><code class="c++">Elf gracz1, gracz2, gracz3;</code></pre>

<pre class="midmar">Obiekt zostal stworzony!
Obiekt zostal stworzony!
Obiekt zostal stworzony!</pre>

<p class="midmar">Jak można zauważyć, po stworzeniu każdego obiektu został automatycznie wywołany konstruktor. <br />
Teraz zajmijmy się nadawaniem wartości:</p>

<pre class="colorx minmar"><code class="c++">Elf(string _imie, int _zycie, int _szczescie)
  {
    imie = _imie;
    zycie = _zycie;
    szczescie = _szczescie;
  }</code></pre>

<pre class="colorx midmar"><code class="c++">Elf gracz1("Edgard", 100, 12);
cout << "Imie: " << gracz1.getImie() << endl;</code></pre>

<pre>Imie: Edgard</pre>

<p><span class="blue">Destruktor</span> to funkcja odwrotna do konstruktora, uruchamia się przy niszczeniu obiektu. Dzięki temu możemy oczyścić pamięć ze śmieci. Jednak tym zajmiemy się w przyszłości gdzy poznamy dynamiczne alokowanie pamięci. Na razie zapamiętaj, że destruktor również ma taką samą nazwę jak jego klasa plus przed nazwą znajduje się tylda: "~".</p>

<h2 class="section-heading">Dodatki</h2>

<p class="midmar">Hermetyzacja (enkapsulacja) – jedno z założeń programowania obiektowego. Hermetyzacja polega na ukrywaniu pewnych danych składowych lub metod obiektów danej klasy tak, aby były one dostępne tylko metodom wewnętrznym danej klasy lub funkcjom zaprzyjaźnionym.</p>

<h3>Przyczyny stosowania hermetyzacji</h3>
<ul class="longmar">
<li> uodparnia tworzony model na błędy </li>
<li> lepiej oddaje rzeczywistość </li>
<li> umożliwia rozbicie modelu na mniejsze elementy </li>
</ul>

<a href="../../../../files/lekcja7.cpp" target="_blank">Kompletny kod klasy Elf (click)</a>

<h2 class="section-heading">Zadania</h2>

<p class="lowmar">1. Pobaw się obiektowością. Zrób jakieś proste RPG z prymitywnym systmem walki, parę itemów itp.</p>

<p class="lowmar">2. Zrób kalkulator redukujący funkcje trygonometryczne <br />
Przykład:</p>
<pre>sin(160) = sin(180-20) = cos(20)</pre>



