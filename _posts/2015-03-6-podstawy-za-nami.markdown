---
layout:     post
title:      "Podstawy prawie za nami"
subtitle:   "Switch Case oraz łańcuchy znaków"

date:       2015-03-06 20:30:00
author:     "Mrozo"
header-img: "img/post-bg-05.jpg"
---

<h2 class="section-heading toph">Switch Case</h2>

<p class="midmar">Jeżeli ogarniasz pętle i if else to switch case nie będzie dla ciebie żadnym problemem. W istocie jest on bardzo podobny do warunku if:</p>

<pre class="colorx midmar"><code class="c++">char litera;
cin >> litera;

if (litera == 'a')
{
  cout << "Ten kod wykona się po wprowadzeniu litery a." << endl;
  cout << "Tekst 2!";
}
else if (litera == 'b')
  cout << <span class="orange">"Ten kod wykona się po wprowadzeniu litery b."</span> << endl;
else if (litera == 'x')
  cout << <span class="orange">"Ten kod wykona się po wprowadzeniu litery x."</span> << endl;
else cout << "Ten kod wykona się po wprowadzeniu litery innej niż jest to zaplanowane powyżej.";
}</code></pre>

<p class="midmar">To samo w przypadku switcha:</p>

<pre class="colorx midmar"><code class="c++">char litera;
cin >> litera;

switch (litera)
{
  case 'a':
    cout << "Ten kod wykona się po wprowadzeniu litery a." << endl;
    cout << "Wcale nie musimy używać nawiasów, mimo że mamy parę linijek kodu!";
    break;
  case 'b':
    cout << "Ten kod wykona się po wprowadzeniu litery b." << endl;
    break;
  case 'x':
    cout << "Ten kod wykona się po wprowadzeniu litery x." << endl;
    break;
  default:
    cout << "Ten kod wykona się po wprowadzeniu litery innej niż jest to zaplanowane powyżej."; << endl;
}</code></pre>

<p class="lowmar">Na samym początku tuż po słowie switch mówimy czego on wogóle dotyczy, następnie podajemy przypadki (cases) i definiujemy co ma się stać w sytuacji ich wskazania.
Słowo break powoduje opuszczenie switcha, jeżeli nie wpisalibyśmy go tuż po każdym z przypadków, kod wykonywałby się od danego case (jeżeli podamy b to od case 'b':) aż do końca całego switcha, czyli do zamykającego nawiasu klamrowego. Dlatego nie ma potrzeby pisania break po default ponieważ on i tak już jest na końcu i nic po nim się nie wykona.</p>

<p class="lowmar">Przykładowe switche:</p>

<pre class="colorx nullmar"><code class="c++">int liczba;
cin >> liczba;

switch (liczba)
{
  case 0:
    //kod
    break;
  case 1:
    //kod
    break;
  default:
    //kod
}

/*-----------------------------------*/

string napis;
cin >> napis;

switch (napis)
{
  case "Tak":
    //kod
    break;
  case "Nie":
    //kod
    break;
  default:
    //kod
}</code></pre>

<table><tbody><tr><th><p class="null">Pamiętaj, że podając case znaku podajemy go w pojedyńczych cudzysłowiach, a tekstu w podwójnych!</p></th></tr><th class="red"></th></tbody></table>

<h2 class="section-heading">C++11 i Tablice:</h2>
<p class="midmar">Jeżeli jeszcze nie wiesz, C++ ma aktualnie bardzo dużo standardów. W tych nowszych wprowadzane są porawki języka oraz rozszerzenia jego funkcjonalności. Obecny standard nosi nazwę C++14, jest to parę ulepszeń standardu C++11, który wprowadził bardzo wiele zmian i jest stosunkowo nowy (2012 rok). Teraz pokażę wam jak możemy deklarować zmienne w C++11:</p>

<pre class="colorx"><code class="c++">int zmienna{20}; //zamiast int zmienna = 20;
int zmienna2{}; //zamiast int zmienna2 = 0;
string tekst{"napis"}; //zamiast int tekst = "napis";
string tekst2{}; //zamiast int tekst2 = "";
double tablica[3] { 10.3, 9.2, 0.0 }; //zamiast double tablica[3] = { 10.3, 9.2, 0.0 };
double tablica2[100] {}; //zamiast double tablica2[100] = {0} // to ustawi nam wszystkie wartości w tablicy na 0!
int tablica3[] { 1, 2 , 3, 4 }; //zamiast int tablica3[] = { 1, 2 , 3, 4 }; // kompilator sam wyliczy nam wielkość!</code></pre>

<p>Taka deklaracja pozwoli nam na ochronę przed nieprawidłową konwersją typów (więcej o tym w przyszłych lekcjach) oraz mamy pewność, że nasza zmienna zostanie zadeklarowana (puste klamry zadeklarują zmienną wartością 0). Lepiej deklarować zmienne 0 niż potem dziwić się dlaczego nasz program nie odpala się. Pamiętaj, że nie każdy kompilator jest zgodny z tym standardem, jeżeli będziem miał błędy przy takiej deklaracji wystarczy, że pobierzesz nowszy. Visual Studio posiada własny standard (tylko część C++11), dlatego należy poszukać pluginów, które potrafiłyby zinterpretować taką deklarację i przy okazji parę innych funkcji.</p>

<h2 class="section-heading">Łańcuchy Znaków</h2>
A co to takiego jest łańcuch? Jest to po prostu tablica znaków. Tak, każdy tekst to tak naprawdę tablica zawierająca w sobie ułożone po kolei znaki. Jednak istnieje jeszcze jedna bardzo ważna kwestia w takich łańcuchach. Wszystkie muszą kończyć się tym znakiem: '\0'.
Jest to tak zwany NULL, czyli nic, zero ;D.

<a href="#">
    <img src="{{ site.baseurl }}/img/inpost/tablice2.png" alt="Tablice2.png">
</a>

<p class="midmar">Ale po co stosować tego NULLa? Jeżeli by go tam nie było, tablica zostałaby dalej odczytywana, poza tekstem, a nawet poza samą sobą! To mogłoby powodować spore zmieszanie dlatego musimy jej powiedzieć gdzie nasz tekst ma się zakończyć. Oczywiście można zrobić to automatycznie:</p>

<pre class="colorx midmar"><code class="c++">char pies[5] {'p', 'i', 'e', 's', '\0'};
char pies[] {'p', 'i', 'e', 's', '\0'};
//ale jak zrobić to automatycznie?
char pies[5] "Pies"; // robimy 5 miejsce na NULL!
char pies[] "Pies"; // miejsce samo się wyliczy</code></pre>

<p class="midmar">Już widzisz różnicę pomiędzy pojedynczymi i podwójnymi cudzysłowiami? Podwójne same dodają NULL na końcu. Dlatego teraz wiesz, że pisząc: case "a": będzie błędem. W rzeczywistości będzie to tablica 2 znaków: { 'a', '\0' }! </p>


<pre class="colorx midmar"><code class="c++">char litera {'X'} // OK
char litera {"X"} //Błąd! Litera to nie tablica!</code></pre>

<h2 class="section-heading">Łączenie literałów napisowych</h2>
<p>Wut? Po prostu łączymy napisy ;D. Czasami w jednej linii wyglądają brzydko ze względu na gługość. Jeśli tylko dwa łańcuchy znakowe rozdzielane są jedynie białymi znakami (spacja, tab, znaki nowego wiersza), są automatycznie łączone w całość:</p>

<pre class="colorx midmar"><code class="c++">cout << "To jest jedno " "zdanie" << endl;
cout << "To też jest"
"jedno zdanie!" << endl;</code></pre>


