#include <iostream>
using namespace std;

#include "ReservationSystem.hpp"
#include "ReservationRequest.hpp"

int main()
{
    int capacities[3] = {30, 50, 80};
    ReservationSystem system(3, capacities);

    // reserva que entra na sala 1
    ReservationRequest r1("calculo", "segunda", 7, 9, 25);
    if (system.reserve(r1))
    {
        cout << "Reserva realizada!" << endl;
    }
    else
    {
        cout << "Não foi possível realizar a reserva" << endl;
    }

    // mesma hora, vai para sala 2
    ReservationRequest r2("algebra", "segunda", 7, 9, 25);
    if (system.reserve(r2))
    {
        cout << "Reserva realizada!" << endl;
    }
    else
    {
        cout << "Não foi possível realizar a reserva" << endl;
    }

    // mesma hora, vai para sala 3
    ReservationRequest r3("fisica", "segunda", 7, 9, 25);
    if (system.reserve(r3))
    {
        cout << "Reserva realizada!" << endl;
    }
    else
    {
        cout << "Não foi possível realizar a reserva" << endl;
    }

    // mesma hora, falha por indisponibilidade
    ReservationRequest r4("historia", "segunda", 7, 9, 25);
    if (system.reserve(r4))
    {
        cout << "Reserva realizada!" << endl;
    }
    else
    {
        cout << "Não foi possível realizar a reserva" << endl;
    }

    // 7-9 seguido de 9-11, sem conflito
    ReservationRequest r5("quimica", "terca", 7, 9, 25);
    if (system.reserve(r5))
    {
        cout << "Reserva realizada!" << endl;
    }
    else
    {
        cout << "Não foi possível realizar a reserva" << endl;
    }

    ReservationRequest r6("filosofia", "terca", 9, 11, 25);
    if (system.reserve(r6))
    {
        cout << "Reserva realizada!" << endl;
    }
    else
    {
        cout << "Não foi possível realizar a reserva" << endl;
    }

    // horário inválido: 10-8
    ReservationRequest r7("economia", "quarta", 10, 8, 25);
    if (system.reserve(r7))
    {
        cout << "Reserva realizada!" << endl;
    }
    else
    {
        cout << "Não foi possível realizar a reserva" << endl;
    }

    // horário fora da faixa: 2-4
    ReservationRequest r8("sociologia", "quarta", 2, 4, 25);
    if (system.reserve(r8))
    {
        cout << "Reserva realizada!" << endl;
    }
    else
    {
        cout << "Não foi possível realizar a reserva" << endl;
    }

    system.printSchedule();

    // cancelamento bem-sucedido
    if (system.cancel("calculo"))
    {
        cout << "Cancelado com sucesso!" << endl;
    }
    else
    {
        cout << "Disciplina não encontrada!" << endl;
    }

    // cancelamento de disciplina inexistente
    if (system.cancel("computacao"))
    {
        cout << "Cancelado com sucesso!" << endl;
    }
    else
    {
        cout << "Disciplina não encontrada!" << endl;
    }

    // calendario pos cancelamento
    system.printSchedule();

    return 0;
}