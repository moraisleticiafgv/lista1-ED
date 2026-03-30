#include "ReservationSystem.hpp"
#include <iostream>
using namespace std;

int show_day(std::string day);
bool comes_before(const Reservation &a, const Reservation &b);

// Aloca as estruturas internas e inicializa as salas
ReservationSystem::ReservationSystem(int room_count, int *room_capacities)
{
    this->room_count = room_count;
    this->room_capacities = new int[room_count];
    this->reservation_count = new int[room_count];
    this->reservations = new Reservation *[room_count];

    for (int i = 0; i < room_count; i++)
    {
        this->room_capacities[i] = room_capacities[i];
        this->reservation_count[i] = 0;
        this->reservations[i] = new Reservation[70];
    }
}

// Libera a memória alocada
ReservationSystem::~ReservationSystem()
{
    for (int i = 0; i < room_count; i++)
    {
        delete[] reservations[i];
    }
    delete[] reservations;
    delete[] room_capacities;
    delete[] reservation_count;
}

// Retorna true se a reserva existente conflita com a solicitação
bool ReservationSystem::timeconflict(Reservation r, ReservationRequest request)
{
    if ((r.weekday == request.getWeekday()) &&
        (!(request.getEndHour() <= r.start_hour || request.getStartHour() >= r.end_hour)))
    {
        return true;
    }
    return false;
}

// Valida a solicitação, percorre as salas e atribui a primeira disponível com capacidade suficiente
bool ReservationSystem::reserve(ReservationRequest request)
{
    // valida horário
    if (request.getEndHour() <= request.getStartHour())
        return false;
    if (request.getStartHour() < 7 || request.getEndHour() > 21)
        return false;

    for (int i = 0; i < room_count; i++)
    {
        bool has_conflict = false;

        if (room_capacities[i] >= request.getStudentCount())
        {
            // verifica conflito com cada reserva existente na sala
            for (int j = 0; j < reservation_count[i]; j++)
            {
                if (timeconflict(reservations[i][j], request))
                {
                    has_conflict = true;
                    break;
                }
            }

            if (!has_conflict)
            {
                if (reservation_count[i] >= 70)
                {
                    continue;
                }

                Reservation new_reservation;
                new_reservation.course_name = request.getCourseName();
                new_reservation.weekday = request.getWeekday();
                new_reservation.start_hour = request.getStartHour();
                new_reservation.end_hour = request.getEndHour();
                new_reservation.student_count = request.getStudentCount();

                // insere já em ordem por dia e horário inicial
                int pos = reservation_count[i];
                while (pos > 0 && comes_before(new_reservation, reservations[i][pos - 1]))
                {
                    reservations[i][pos] = reservations[i][pos - 1];
                    pos--;
                }

                reservations[i][pos] = new_reservation;
                reservation_count[i]++;
                return true;
            }
        }
    }

    return false;
}

// Localiza a reserva pelo nome da disciplina e a remove mantendo a ordem
bool ReservationSystem::cancel(std::string course_name)
{
    for (int i = 0; i < room_count; i++)
    {
        for (int j = 0; j < reservation_count[i]; j++)
        {
            if (reservations[i][j].course_name == course_name)
            {
                for (int k = j; k < reservation_count[i] - 1; k++)
                {
                    reservations[i][k] = reservations[i][k + 1];
                }

                reservation_count[i]--;
                return true;
            }
        }
    }

    return false;
}

// Converte o dia da semana para número para permitir comparação
int show_day(std::string dia)
{
    if (dia == "segunda")
        return 0;
    if (dia == "terca")
        return 1;
    if (dia == "quarta")
        return 2;
    if (dia == "quinta")
        return 3;
    if (dia == "sexta")
        return 4;
    return -1;
}

// Retorna true se a reserva a deve ficar antes da reserva b
bool comes_before(const Reservation &a, const Reservation &b)
{
    if (show_day(a.weekday) != show_day(b.weekday))
    {
        return show_day(a.weekday) < show_day(b.weekday);
    }
    return a.start_hour < b.start_hour;
}

// Exibe a grade completa de reservas organizada por sala, dia e horário
void ReservationSystem::printSchedule()
{
    for (int i = 0; i < room_count; i++)
    {
        cout << "Room " << i + 1 << ":" << endl;

        if (reservation_count[i] == 0)
        {
            cout << "No reservations" << endl
                 << endl;
            continue;
        }

        string current_day = "";

        for (int j = 0; j < reservation_count[i]; j++)
        {
            if (reservations[i][j].weekday != current_day)
            {
                if (current_day != "")
                {
                    cout << endl;
                }

                current_day = reservations[i][j].weekday;
                cout << current_day << ":" << endl;
            }

            cout << reservations[i][j].start_hour << "h~"
                 << reservations[i][j].end_hour << "h: "
                 << reservations[i][j].course_name << endl;
        }

        cout << endl;
    }
}