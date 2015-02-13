---
layout:     post
title:      "Więcej zmiennych i nowa pętla"
subtitle:   "Tablice i ostatnia pętla - for"
date:       2015-02-13 18:25:00
author:     "Mrozo"
header-img: "img/post-bg-03.jpg"
---

<h2 class="section-heading toph">Tablice</h2>
<p> Tablica to nic innego jak zbiór zmiennych tego samego typu. Można ją sobie wyobrazić jako pojemnik, który przechowuje zmienne od lewej do prawej strony:</p>

<a href="#">
    <img src="{{ site.baseurl }}/img/inpost/tablice1.png" alt="Tablice1.png">
</a>

<p class="lowmar">Każdy "pojemnik" to tak naprawdę komórka pamięci RAM. Każda z nich posiada własny, niepowtarzalny adres przedstawiany w postaci liczby w systemie szesnastkowym.
Tablice "rezerwują" wskazaną ilość takich komórek.
Po co? Załóżmy, że mamy 200 liczb i chcemy je gdzieś zapisać. Oznacza to, że będziemy musieli stworzyć 200 zmiennych int:</p>

<pre class="colorx"><code class="c++">int liczba1 = 10;
int liczba2 = 15;
int liczba3 = 20;
int liczba4 = 25;
int liczba5 = 30;
... //i tak do 200!</code></pre>

<p class="lowmar">Masakra. Ktoś mądry wpadł kiedyś na świetny pomysł i wymyślił tablice:</p>

<pre class="colorx"><code class="c++">int liczba[200];</code></pre>

<p class="lowmar">Właśnie stoworzyliśmy 200 zmiennych int. Mamy tablicę int o nazwie liczba, ale jak możemy dostać się do poszczególnych komórek?
Nic prostszego:</p>

<pre class="colorx nullmar">
<code class="c++">//chcę zapisać wartość w pierwszej komórce:
liczba[0] = 10;
//chcę zapisać wartość w drugiej komórce:
liczba[1] = 15;
//chcę odczytać wartość z 150 komórki:
cout << liczba[149];
//ostatnia, dwusetna komórka to:
liczba[199]</code></pre>


<table><tbody><tr><th><p class="null">Pamiętaj, że w tablicy zawsze liczymy elementy od 0!</p></th></tr><th class="red"></th></tbody></table>


<p class="lowmar">w miejsce liczby możemy wpisać zmienną lub wykonać przeróżne obliczenia:</p>

<pre class="colorx"><code class="c++">int x = 2;
liczba[x] = 10;
liczba[x+1] = 15;
cout << liczba[x];          //liczba[2]=10</code></pre>


<p>Tablice - pomysł iście wspaniały, jednak aby zdeklarować zmienne w takiej tablicy i tak musimy wypisywać wszystkie jej elementy. To samo tyczy się odczytu wartości. Z pomocą nadchodzi pętla for. </p>

<h2 class="section-heading">Pętla for</h2>
<p class="lowmar">Bardzo często potrzebowaliśmy powtórzyć jakiś fragment kodu okrśloną ilość razy. Używając pętli while można to zrobić w taki sposób:</p>

<pre class="colorx nullmar"><code class="c++">int i = 0;
while(i<10)
{
  //kod
  i++
}</code></pre>

<table><tbody><tr><th><p class="null">Skróty ułatwiające życie:</p></th></tr>
<tr><th><p class="null">i++&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="output">i=i+1</span></p></th></tr>
<tr><th><p class="null">i--&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="output">i=i-1</span></p></th></tr>
<tr><th><p class="null">liczba += 10&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="output">liczba = liczba + 10</span></p></th></tr>
<tr><th><p class="null">liczba -= 10&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="output">liczba = liczba - 10&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</span></p></th></tr>
<tr><th><p class="null">iczba *= 10&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="output">liczba = liczba * 10</span></p></th></tr>
<tr><th><p class="null">liczba /= 10&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="output">liczba = liczba / 10</span></p></pre></th></tr>
<th class="green"></th>
</tbody></table>

<p class="lowmar">Pętla for powstała po to, aby nie deklarować niepotrzebnie zmiennej, której użyjemy tylko do określenia ilości powtórzeń kodu. </p>

<pre class="colorx"><code class="c++">for(int i=0; i<10; i++)
{
  //kod
  x = x+1;
}</code></pre>

<p class="lowmar">Wszystkie pętle są do siebie bardzo podobne, ta posiada wbudowany iterator. Iterator to zmienna, która decyduje ile razy powtórzy (ziteruje) się pętla. To właśnie od niego wzięła się nazwa zmiennej "i". W miejsce i++ możemy wykonywać inne działąnia np i += 5. </p>

<p class="lowmar">Teraz możemy w pełni zautomatyzować np wpisywanie wartości do tablicy:</p>

<pre class="colorx"><code class="c++">int liczba[200];
for(int i=0; i<200; i++)
{
  cout << "Liczba" << i+1 << ":";
  cin >> liczba[i];
}</code></pre>

<p class="lowmar">Efekt końcowy:</p>

<pre class="colorx"><code class="c++">Liczba1:  //wpisujemy wartość
Liczba2:  //wpisujemy wartość
Liczba3:  //wpisujemy wartość
Liczba4:  //wpisujemy wartość
//i tak do 200 :D</code></pre>


<h2 class="section-heading">Zadania</h2>

<p class="lowmar">1. Stwórz tablicę int o rozmiarze 500. Program ma pokazywać dzielenie kolejnych liczb przez 2 zaczynając od 0. W każdej komórce ma znajdować się reszta z dzielenia numeru tablicy przez 2.<br>Przykład:</p>
<pre>1. 0/2 = 0 reszta 0       //tab[0]=0
2. 1/2 = 0 reszta 1       //tab[1]=1
3. 2/2 = 1 reszta 0       //tab[2]=0
//i tak do 500 :D</pre>

<p class="lowmar">2. Ulepsz swój kalkulator o opcję wyświetlenia ostatnich 10 wyników. Wykorzystaj do tego celu tablice i pętle for.</p>

<blockquote>Wesołych ferii ;)</blockquote>
