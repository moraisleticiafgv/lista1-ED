#ifndef RESERVATIONSYSTEM.HPP
#define RESERVATIONSYSTEM.HPP

#include <string>
#include "ReservationRequest.hpp"

struct Reservation{
    std::string course_name;
    std::string weekday;
    int start_hour;
    int end_hour;
    int student_count;

};

class ReservationSystem {

private:
    int room_count;
    int* room_capacities;
    int* reservation_count;
    Reservation** reservations;
    
public:

    ReservationSystem(int room_count, int* room_capacities);
    ~ReservationSystem();

    bool timeconflict(Reservation, ReservationRequest);
    bool reserve(ReservationRequest request);
    bool cancel(std::string course_name);

    void printSchedule();
};


#endif