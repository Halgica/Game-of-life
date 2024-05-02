#include "game_of_life.h"

game_of_life::game_of_life()
{
    //lud default konstruktor!, zasto ga mora podcrtat svaki put pogledam sto se to zeleni
}

bool game_of_life::slucajna_vrijednost()
{
    int random = 1 + rand() % (100 - 1 + 1);
    if (random <= 25)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool game_of_life::celija_zauzeta(int i, int j)
{
    if (_generacija[i][j])
    {
        return true;
    }
    else
    {
        return false;
    }
}


void game_of_life::sljedeca_generacija()
{
    for (size_t i = 0; i < REDAKA; i++)
    {
        for (size_t j = 0; j < STUPACA; j++)
        {
            //provjera celija okolo celije i,j
            provjera_okolo(i, j);
        }
    }

    for (size_t i = 0; i < REDAKA; i++)
    {
        for (size_t j = 0; j < STUPACA; j++)
        {
            //nova generacija -> generacija
            _generacija[i][j] = _sljedeca_generacija[i][j];
        }
    }
}

void game_of_life::provjera_okolo(int i, int j)
{
    int brojacZivih = 0;
    int provjeraI = i;
    int provjeraJ = j;
    //brojac zivih oko celije
    for (size_t k = provjeraI-1; k <= provjeraI+1; k++)
    {
        for (size_t l = provjeraJ-1; l <= provjeraJ+1; l++)
        {
            if (l == j && k == i)
            {
                l++;
            }
            if (_generacija[k][l])
            {
                brojacZivih++;
            }
        }
    }
    //pravila
    pravila(brojacZivih, i, j);
}

void game_of_life::pravila(int brojacZivih, int i, int j)
{
    if (brojacZivih < 2 || brojacZivih > 3)
    {
        _sljedeca_generacija[i][j] = false;
    }
    else if (brojacZivih == 3)
    {
        _sljedeca_generacija[i][j] = true;
    }
}

void game_of_life::iscrtaj()
{
    //crtanje
    system("cls");
    for (size_t i = 0; i < REDAKA; i++)
    {
        for (size_t j = 0; j < STUPACA; j++)
        {
            if (_generacija[i][j])
            {
                cout << '#';
            }
            else
            {
                cout << '-';
            }
        }
        cout << endl;
    }
}

void game_of_life::inicijalizacija()
{
    bool celija;
    for (size_t i = 0; i < REDAKA; i++)
    {
        for (size_t j = 0; j < STUPACA; j++)
        {
            if (slucajna_vrijednost())
            {
                _generacija[i][j] = true;
            }
            else
            {
                _generacija[i][j] = false;
            }
        }
    }
}

