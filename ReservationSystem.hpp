#ifndef RESERVATIONSYSTEM_HPP
#define RESERVATIONSYSTEM_HPP

#include <string>
#include "ReservationRequest.hpp"

// Representa uma reserva armazenada internamente no sistema
struct Reservation
{
    std::string course_name;
    std::string weekday;
    int start_hour;
    int end_hour;
    int student_count;
};

// Gerencia as reservas de salas de aula durante a semana
class ReservationSystem
{
private:
    int room_count;             // número de salas
    int *room_capacities;       // capacidade máxima de cada sala
    int *reservation_count;     // número de reservas atuais em cada sala
    Reservation **reservations; // array bidimensional de reservas por sala

public:
    ReservationSystem(int room_count, int *room_capacities);
    ~ReservationSystem();

    // Verifica se uma reserva existente conflita com a solicitação
    bool timeconflict(Reservation, ReservationRequest);

    // Tenta reservar uma sala. Retorna true se bem-sucedido
    bool reserve(ReservationRequest request);

    // Cancela a reserva da disciplina informada. Retorna true se encontrada
    bool cancel(std::string course_name);

    // Exibe a grade de reservas ordenada por sala, dia e horário
    void printSchedule();
};

#endif