#ifndef RESERVATIONREQUEST_HPP
#define RESERVATIONREQUEST_HPP

#include "RequestReservation.hpp"
    
class ReservationSystem {

private:
    int room_count; 
    int* room_capacities;
    ReservationRequest** reservas_salas;
    int* count_reservas_salas;

public:

    ReservationSystem(int room_count, int* room_capacities);
    ~ReservationSystem();

    bool reserve(ReservationRequest request);
    bool cancel(std::string course_name);

    void printSchedule();


};
#endif