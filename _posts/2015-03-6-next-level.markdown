---
layout:     post
title:      "Podstawy prawie za nami"
subtitle:   "Switch case oraz łańcuchy znaków"

date:       2015-03-06 21:00:00
author:     "Mrozo"
header-img: "img/post-bg-04.jpg"
---

<h2 class="section-heading toph">Struktury</h2>

<p>Wyobraźmy sobie, że jesteśmy prawilnymi programistami i tworzymy wspaniałą grę rpg. W grze tej mamy do wyboru 10 klas postaci. Każda z klas potrafi wykonać skok, rozmawiać, zadawać obrażenia, używać przedmiotów, craftować ekwiunek. Bez używania funkcji do każdej z klas będziemy musieli po kolei wkleić wszystkie te umiejętności, co oznacza 10 razy więcej kodu! To nic. Teraz okazało się, że podczas wykonywania skoku występuje jakiś błąd. Co robimy? Poprawiamy ten sam błąd w 10 różnych miejscach! A co z rozszerzaniem, ulepszaniem naszego systemu zadawania obrażeń? Znów będziemy zmuszeni zmieniać kod w wielu miejscach. Tragedia. A gdyby dało się ucisnąć 200 linijek kodu odpowiadających za 1 czynnąść pod podaną nazwą np. "Atak" a następnie wywołać samą nazwę w wielu miejscach? Teraz moglibyśmy modyfikować kod kryjący się pod słowem "Atak" tylko 1 raz, w 1 miejscu. Tak właśnie działają funkcje. </p>

<pre class="colorx"><code class="c++">typ_zwracanej_wartości nazwa_funkcji (argumenty)
{
  // kod
}</code></pre>

<p class="lowmar">Na samej górze znajduje się nagłówek funkcji mówiący o jej nazwie, argumentach oraz typie zwracanej wartości (spokojnie, wyjaśnię wszystko po kolei), a część ograniczona nawiasami {} to ciało funkcji, w którym umieszczać będziemy nasze wypociny.</p>
<p class="lowmar">Przykładowe nagłówki funkcji:</p>

<pre class="colorx"><code class="c++">int skok(int wysokosc)
float dodaj(float x, float y)
string powitanie(string imie) // string to łańcuch znaków, czyli tekst
int f(int x) // brzmi znajomo? ;D
void helloWorld() </code></pre>

<h2 class="section-heading">Funkcja Void</h2>

<p class="midmar">Na początku zajmiemy się najprostszą funkcją, czyli taką, która nie zwraca żadnej wartości i nie posiada argumentów. Jeżeli funkcja nie zwraca wartości to co mamy wpisać w ich miejsce? Void, czyli po angielsku pustkę.</p>

<pre class="colorx"><code class="c++">void helloWorld()
{
  cout << "Hello World" << endl;
}

int main()
{
  helloWorld();
  return 0;
} </code></pre>

<h2 class="section-heading">Organizacja</h2>

<p class="midmar">Na razie brzi prosto. Fukcja helloWorld() znajduje się nad funkcją main(), ponieważ kompilator czyta kod od góry do dołu. Jeżeli moją funkcję umieściłbym pod mainem, kompilator nie wiedziałby co to jest helloWorld();, dowiedziałby się o nim dopiero potem. Jednak istnieje sposób, który pozwoli nam pisać funkcje pod funkcją main():</p>

<pre class="colorx"><code class="c++">void helloWorld();

int main()
{
  helloWorld();
  return 0;
}

void helloWorld()
{
  cout << "Hello World" << endl;
} </code></pre>


<p>Umieszczając sam nagłówek dajemy znać kompilatorowi, że dalsza jej część znajdzie się gdzieś poniżej, przez co nazwa helloWorld() w funkcji main nie jest już mu obca. Tylko po co mielibyśmy się tak męczyć i w dziwny sposób teleportować nasze ciała funkcji? Na górze nie wyglądają najgorzej. Może w tym przykładzie rzeczywiście nie jest tak źle jednak ponownie wyobraźmy sobie, że mamy tych funkcji 20 i każda z nich zawiera ze 100 linijek kodu. Plik main.cpp jak sama nazwa mówi jest po to, żeby posiadał tą najważniejszą funkcję mówiącą gdzie program się zaczyna, a gdzie kończy. Przywalanie jej 20 innymi nie ma sensu gdyż będziemy jej musieli potem szukać w tym gąszczu, co nie jest przyjemne. Oczywiście nauczymy się eksportować nasze funkcje do innych plików, jednak przy mniejszych projektach to również nie ma sensu.</p>

<h2 class="section-heading">Argumenty</h2>

<p class="lowmar">No dobrze, przyszedł czas na argumenty:</p>

<pre class="colorx midmar"><code class="c++">void powitanie(string imie);

int main()
{
 string nazwa = "Jacek";

  powitanie("Karol");
  powitanie("Marcin");
  powitanie(nazwa);
  return 0;
}

void powitanie(string imie);
{
  cout << "Witaj " << imie << "!" << endl;
} </code></pre>

<p class="midmar">Wynik programu:</p>

<pre class="colorx"><code class="c++">Witaj Karol!
Witaj Marcin!
Witaj Jacek! </code></pre>

<p>Podając różne argumentu możemy sprawić, że nasza funkcja będzie dawała inne rezultaty.
Mimo tego, wywołanie paruset linijek będzie odbywało się za pomocą tylko jednej!
Już widzimy tem wyższy poziom abstrakcji i ułatwiania. Teraz dołożymy jeszcze zwracanie wartości</p>

<h2 class="section-heading">Wartości Zwracane</h2>

<pre class="colorx"><code class="c++">bool smierc(int otrzymane_obrazenia, int pozostale_zycie);

int main()
{
  smierc(20, 35);
  smierc(48, 12);
  return 0;
}

bool smierc(int otrzymane_obrazenia, int pozostale_zycie);
{
  if (otrzymane_obrazenia > pozostale_zycie) return true; // jeżeli to return zwróci wartość, funkcja zakończy się.
  else return false;
} </code></pre>

<p class="midmar">Jeżeli ktoś jeszcze nie wie, bool to typ danych, który może zawierać albo 1 (true), albo 0 (false). Tak naprawdę to jeżeli nadamy zmiennej bool wartość np 2 to również będzie ona wynosiła true, ponieważ true to każda wartość, która jest różna od zera. Np. miejscu gdzie napisałem return false, mogłem napisać return 0, jednak dla rozpoznania, że to nie int lepiej jest napisać false. <br> Teraz przeanalizujmy co stało się w funkcji smierc. Funkcja ta sprawdza, czy postać otrzymała więcj punktów obrażeń niż wynosi jej życie. Jeżeli tak, funkcja zwróci prawdę, jeżeli nie - fałsz. Sprawdźmy wynik naszego programu: </p>

<pre class="colorx midmar"><code class="c++">

</code></pre>

<p class="midmar">Hmm, pusto. To, że funkcja zwróciła nam wartość, nie oznacze że musi ją wyświetlić! Więc co takiego możemy z tym zrobić? Albo przypisać naszą funkcję do zmiennej, albo wycoutować:
</p>

<pre class="colorx"><code class="c++">int main()
{
 string nazwa = "Jacek";

  bool czy_smierc = smierc(20, 35);
  cout << czy_smierc << endl;
  cout << smierc(48, 12) << endl;
  return 0;
}</code></pre>

<h2 class="section-heading">Zmienne lokalne i referencja</h2>

<p class = "midmar">Teraz chciałbym zająć się sprawą zmiennych lokalnych. Bo widzisz, dlaczego w funkcji void powitanie(string imie) wyraźnie jest napisane, że funkcja ta przyjmuje zmienną string o nazwie imie a ja wcześniej zrobiłem coś takiego:</p>

<pre class="colorx"><code class="c++">string nazwa = "Jacek";
powitanie("Karol");
powitanie("Marcin");</code></pre>

<p class="midmar"> Podałem funkcji zmienną nazwa a nie imie. A jednak zadziałało. Wszystkie zmienne w ciałach funkcji to zmienne lokalne, co oznacza, że TYLKO funkcja, która je przechowuje wie o ich istnieniu i nazwie. Funkcja main() jest takim szefem, a funkcja powitanie(string imie) pracownikiem. Co obchodzi maina jak sobie nazwie jej daną pracownik, który chce chce obrobić? Nic! Pracownik też ma gdzieć nazwę stringa, którego dostanie. Jego celem jest zmienienie go w określonym schemacie i zwrócenie samej WARTOŚCI szefowi, a czy po drodze jakoś sobie to nazwie na swoje potrzeby nie ma większego znaczenia. Zauważcie, że dzięki temu możemy mieć klilka zmiennych o tej samej nazwie, tyle że w innych funkcjach! Szefa obchodzi tylko wynik. Mało tego, jak zaraz się przekonamy, szef podsyła pracownikowi kopię swojej danej! A co jak pójdzie coś nie tak? Szef nie da manipulować swoją zmienną przez cały czas, dzlatego podaje tylko wartość, a jak pracownik skończy ją obrabiać i zwróci poprawnie wtedy dopiero będzie mógł ją podmienić za swoją początkową. <br> Postaram się to tutaj zobrazować: </p>

<pre class="colorx midmar"><code class="c++">void pracownik(int wyngiel, int kamulce, int zelastwo, int drywno);

int main()
{
  int wegiel = 20;
  int kamienie = 10;
  int zelazo = 50;
  int drewno = 15;
  int metal = pracownik(wegiel, kamienie, zelazo, drewno);
  return 0;
}

void pracownik(int wyngiel, int kamulce, int zelastwo, int drywno)
{
  wyngiel -= 10;        // Węgiel maina wcale nie uległ zmienie!
  wyngiel += 10;        // Zmienna wegiel u szefa nadal wynosi 20!
  moja_zaplata = kamulce + drywno; // Szef i tak ich nie stracił :D
  return zelastwo + wyngiel;
} </code></pre>

<p class="midmar">Jak widzisz zmienne lokalne są dosyć dobrze przemyślane i zaplanowane. Jednak zdarzają się sytuacje, w których szef daje pracownikowi oryginał. W informatyce jest to nazywane referencją:</p>

<pre class="colorx"><code class="c++">void randomowyOblicznik(int &liczba1);

int main()
{
  int moja_liczba = 10;
  wynik = randomowyOblicznik(moja_liczba);
  return 0;
}

void randomowyOblicznik(int &liczba1)
{
  liczba1 += 7; // W tym miejscu moja_liczba została zastąpiona nową wartością: 17!
  liczba1 += 1; // Teraz moja_liczba to już nie 17, a 18!
  int wynik = liczba1 + 15 - 4 * 8 / 2;
  return wynik + 20 * 3 / 8 - 1;
}</code></pre>

<p>Mimo, że to WYNIK został zwrócony, moja_liczba w funkcji main również uległa zmianie ponieważ naszemu randomowemu oblicznikowi wysłaliśmy ją poprzez referencję, czyli dając mu oryginał (wystarczy dodać w nagłówku tóż przy zmiennej ampersanda - "&").</p>

<h2 class="section-heading">Zmienne Globalne</h2>

<p>Czyli po prostu zmienne, które deklarujemy poza ciałami funkcji. Każda funkcja o nich wie, więc możemy ich wszędzie używać. Jednak w rzeczywistości zmienne globalne to czyste zło, którego powinno się unikać i stosować tylko gdy jest naprawdę potrzebne. Dlaczego zło? Bo wszyscy początkujący go nadużywają. Po co męczyć się z argumentami jak mogę sobie walnąć zmienną poza funkcjami i mieć do niej dostęp z każdego zakątka notatnika? Otóż zmienne takie pałętają się od począdku programu aż do jego zakończenia i zajmują miejsce w pamięci. A taka schludna funkcja gdy zostanie wywołana tworzy sobie zmnienną lokalną i niszczy ją wraz z napotkaniem słowa return, tuż po zwróceniu wartości. Oprócz tego dochodzą kwestie bezpieczeństwa, bardzo łatwo jest uzyskać dostęp do takiej zmiennej, która nie powinna zostać zmieniona przez kogoś, czy wykradziona.</p>

<h2 class="section-heading">Dopowiedzenie</h2>

<p class = "lowmar">Rozszerzmy teraz nasze choryzonty o nowe możliwości:</p>

<pre class="colorx midmar"><code class="c++">string powitanie(string imie);
string mileZdanie();
string polaczenieZdan(string zdanie1, string spojnik, string zdanie2);

int main()
{
  string imie1 = "", imie2 = "";
  cin >> imie1 >> imie2;
  cout << polaczenieZdan(powitanie(imie1), ", ", powitanie(imie2)) << endl;
  return 0;
}

string powitanie(string imie)
{
  return "witaj " + imie;
}

string mileZdanie()
{
  return "Milo mi was widziec!";
}

string polaczenieZdan(string zdanie1, string spojnik, string zdanie2)
{
  return zdanie1 + spojnik + zdanie2 + "! " + mileZdanie();
} </code></pre>

<p class="midmar">Przykładowy rezultat:</p>

<pre class="colorx midmar"><code class="c++">witaj Adam, witaj Bartek! Milo mi was widziec!</code></pre>

<p class="midmar">Mam nadzieję, że funkcje nie będą już wam się kojarzyć tylko z matematyką. Dodam jeszcze, że funkcja może zwracać jakąś wartość oraz wykonywać całkiem inny kod np:</p>

<pre class="colorx"><code class="c++">int funkcja()
{
  cout << "Jestem sobie funkcja" << endl;
  return 10;
}

int main()
{
  int liczba = funkcja(); // nasze int to teraz 10
  return 0;
}</code></pre>

<p>Zmienna liczba zostanie zainicjowana wartością 10, a na ekranie wyświetli nam się zdanie "Jestem sobie funkcja".</p>

<h2 class="section-heading">O funkcji main</h2>
<p>Mam nadzieję, że już domyślasz się jak działa ta funkcja. Wraz z jej początkiem rozpoczyna się program, a kiedy zwróci 0, będzie to informacja dla systemu, że program należy zamknąć. To wszystko, proste.</p>

<h2 class="section-heading">Zadanie</h2>

<p class="lowmar">1. Napisz kalkulator BMI (jednostki brytyjskie: stopy, cale i funty). Wzór to masa/wzrost&sup2;. Obiczanie punktów ma odbywać się w funkcji "BMI", która ma zwraca sam wynik. Po drodze, zanim "BMI" wynik zwróci powinna zostać wywołana inna funkcja: "sprawdzWynik", która wypisze nam informacje o naszej wadze (czy mamy otyłość, nadwagę, niedowagę czy może wszystko jest ok).

Co do jednostek wszystko macie pokazane na angielskich stronach, internet jest wasz.
<br>
Przykład:</p>
<pre>Podaj swój wzrost w stopach i calach: //5 12
Podaj swoją wagę w funtach: //143
Twoje BMI to 19.4, masz prawidłową wagę!</pre>

