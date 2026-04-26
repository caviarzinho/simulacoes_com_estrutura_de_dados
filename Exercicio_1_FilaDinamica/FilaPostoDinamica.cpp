#include <iostream>
#include <ctime>
#include <cstdlib>
#include "FilaDinamicaGenerica.h"

using namespace std;

int main()
{
    srand(time(NULL)); // Semente para números aleatórios

    FilaDinamicaGenerica<int> filaCarro;
    FilaDinamicaGenerica<int> filaTanque;
    cria(filaCarro);
    cria(filaTanque);
    clock_t inicio = clock();

    const int tempoMax = 240; // Simulação de 240 minutos (4 horas)
    int totalCarrosAtendidos = 0;
    for (int i = 0; i < tempoMax; i++)
    {
        if (i % 60 == 0 and i != 0) // verificar as 09:00 a fila de espera do posto
        {
            {
                cout << "Carros na fila de espera: ";
                mostra(filaCarro);
            }
        }
        if (i < 151)
        {
            if (i % 7 == 0)
            {
                int quantcarro = rand() % 5; // Gera carros no posto entre 0 e 4
                for (int j = 0; j < quantcarro; j++)
                {
                    insere(filaCarro, 1);
                }
            }
        }
        else
        {
            if (i % 180 == 0 and i != 0) // verificar as 11:00 a fila de espera do posto
            {
                {
                    cout << "Carros na fila de espera: ";
                    mostra(filaCarro);
                }
            }
            if (i % 4 == 0) // a cada 4 minutos, novos carros chegam ao posto
            {
                int quantcarro = rand() % 3; // Gera carros no posto entre 0 e 2
                for (int j = 0; j < quantcarro; j++)
                {
                    insere(filaCarro, 1);
                }
                if (quantcarro % 2 == 0 && quantcarro > 0)
                {
                    cout << "Carros na fila de espera: ";
                    mostra(filaCarro);
                }
            }
        }

        if (i % 2 == 0)
        {                                  // Frentista atende um carro a cada 2 minutos
            int quanttanque = rand() % 41; // Gera quantidade de gasolina inserida entre 0 e 40
            if (!ehVazia(filaCarro))
            {
                retira(filaCarro); // Carro sai do posto
                insere(filaTanque, quanttanque);
                totalCarrosAtendidos++;
            }
        }
    }
    clock_t fim = clock();
    for (int i = 0; i < totalCarrosAtendidos; i++)
    {
        if (!ehVazia(filaTanque))
        {
            cout << "Quantidade de gasolina inserida no tanque: " << primeiro(filaTanque) << " litros" << endl;
            retira(filaTanque);
        }
    }
    return 0;
}