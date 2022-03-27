// Zadanie zaliczeniowe 2 - WPI MIMUW
// autor - Stanisław Durka

#include <stdio.h>
#include <stdlib.h>

#define WIERSZE 20
#define KOLUMNY 80
#define SP ' ' //spacja

void czytaj_dane(char tablica[WIERSZE][KOLUMNY]){
  //czyta dane wpisane przez użytkownika i wpisuje je do tablicy o ustalonym rozmiarze
  int w; int k;
  int znak;
  for (w = 0; w < WIERSZE; w++){
    for (k = 0; ((znak = getchar()) != '\n') && (znak != EOF) && k<KOLUMNY; k++){
      tablica[w][k] = znak;
    }
  }
}

void wypisz_tablice(char tablica[WIERSZE][KOLUMNY]){
  // wypisuje aktualny stan tablicy
  int w; int k; int kol; int nie_printuj;
  for (w=0; w<WIERSZE; w++){
    int spacje = 0;
    nie_printuj = 0;
    kol = KOLUMNY -1; char ch = 'a'; int koniec = 0;
    while (kol>=0 && (koniec == 0)){
      ch = tablica[w][kol];
      if (ch == SP) spacje ++;
      else koniec = 1;
      kol--;
    }
    if (spacje == KOLUMNY) nie_printuj = 1;

    for (k=0; k < (KOLUMNY - spacje); k++){
      printf("%c", tablica[w][k]);
    }
    if (nie_printuj == 0) printf("\n");
  }
}

void przenies_wierszami(char tablica[WIERSZE][KOLUMNY]){
  //przenosi każdy element w każdym z wierszy tablicy "na dół" (kolumnami) do momentu, aż pod spodem w kolumnie nie ma spacji
  int kol;
  int wiersz;
  char x;
  for (kol=0; kol<KOLUMNY;kol++){
    int puste = 0; // zmienna trzymająca liczbę spacji w kolumnie od WIERSZE-1 do wiersz;
    for (wiersz = WIERSZE - 1; wiersz >=0; wiersz --){ //zaczynamy od ostatniego wiersza
      x = tablica[wiersz][kol];
      if (x == SP){
        puste++;
      }
      else{
        tablica[wiersz][kol]=SP;
        tablica[wiersz+puste][kol]=x;
      }
    }
  }
}

int czy_pusta_kolumna(char tablica[WIERSZE][KOLUMNY],int kolumna){
  // zwraca 1 jeśli kolumna jest pusta(<=>wypelniona spacjami); zwraca 0 jeśli nie jest pusta
  // funkcja pomocnicza wywoływana w funkcji usun_puste_kolumny()
  int i=0; int pusta=1;
  while (i<WIERSZE && pusta){
    if (tablica[i][kolumna] != SP) pusta = 0;
    i++;
  }
  return pusta;
}

void zamien_kolumny(char tablica[WIERSZE][KOLUMNY],int k1, int k2){
  // funkcja pomocnicza wywoływana w funkcji usun_puste_kolumny()
  // zamienia znaki w tablicy "tablica" oraz dwóch kolumnach danych jako argumenty funkcji
  char z;
  for (int l=0;l<WIERSZE;l++){
    z = tablica[l][k1];
    tablica[l][k1] = tablica[l][k2];
    tablica[l][k2] = z;
  }
}

void usun_puste_kolumny(char tablica[WIERSZE][KOLUMNY]){
  int k;
  int puste = 0; // zmienna trzymająca liczbę pustych kolumn począwszy od kolumny 0 do k;
  for (k=0;k<KOLUMNY; k++){
    if (czy_pusta_kolumna(tablica,k)){
      puste ++;
    }
    else
      zamien_kolumny(tablica,(k-puste),k);
  }
}


int do_wymazania(char tablica[WIERSZE][KOLUMNY], int w, int k, char znak){
  // bierze jako argument wspolrzedne elementu tablicy, znak jaki ma wymazać
  // zwraca 0 jeśli wspólrzędne wychodzą poza tablicę lub wartość pod współrzędnymi nie jest równa zmiennej znak podanej w argumencie
  // w innym przypadku zwraca 1
  // funkcja pomocnicza do funkcji wymaz()
  if ((tablica[w][k] != SP) && (tablica[w][k] == znak) && (0<=w) && (w<WIERSZE) && (0<=k) && (k<KOLUMNY)) return 1;
  else return 0;
}

void wymaz(char tablica[WIERSZE][KOLUMNY],int w, int k){
  //zaczynając od znaku w tablicy o podanych współrzędnych, rekurencyjnie 'wymazuje' wszystkie elementy tablicy o tej samej wartości (zamieniając je na spacje)
  char znak = tablica[w][k];
  tablica[w][k]=SP;
  // for (int i=-1; i<=1; i++){
  //   for (int j=-1; j<=1; j++){
  //     if (i!=j && i!=(-j))
  //      if (do_wymazania(tablica, w+i, k+j, znak)==1) wymaz(tablica,w+i,k+j);
  // }
  if (do_wymazania(tablica, w+1, k, znak)==1) wymaz(tablica,w+1,k);
  if (do_wymazania(tablica, w-1, k, znak)==1) wymaz(tablica,w-1,k);
  if (do_wymazania(tablica, w, k+1, znak)==1) wymaz(tablica,w,k+1);
  if (do_wymazania(tablica, w, k-1, znak)==1) wymaz(tablica,w,k-1 );
}


int main(){
  // inicjalizowanie tablicy o ustalonych wymiarach:
  char tablica[WIERSZE][KOLUMNY];
  //wypelnianie tablicy spacjami:
  for (int i=0; i<WIERSZE; i++){
    for (int j=0; j< KOLUMNY; j++){
      tablica[i][j]=SP;
    }
  }

  czytaj_dane(tablica);
  przenies_wierszami(tablica);
  usun_puste_kolumny(tablica);
  wymaz(tablica, WIERSZE-1,0); // tablica[WIERSZE-1][0] to znak ktory wymazujemy
  przenies_wierszami(tablica);
  usun_puste_kolumny(tablica);
  wypisz_tablice(tablica);
}
