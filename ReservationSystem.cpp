#include "ReservationSystem.hpp"

ReservationSystem::ReservationSystem(int room_count, int* room_capacities) {
    this->room_count = room_count;
    this->room_capacities = new int[room_count];
    this->reservation_count = new int[room_count];
    this->reservations = new Reservation*[room_count];

    for (int i = 0; i < room_count; i++) {
        this->room_capacities[i] = room_capacities[i];
        this->reservation_count[i] = 0;

        this->reservations[i] = new Reservation[70];
    }
}

ReservationSystem::~ReservationSystem() {
    for (int i = 0; i < room_count; i++) {
        delete[] reservations[i];
    }

    delete[] reservations;
    delete[] room_capacities;
    delete[] reservation_count;
};

bool ReservationSystem::timeconflict(Reservation r, ReservationRequest request){
    if ((r.weekday == request.getWeekday()) && (!(request.getEndHour() <= r.start_hour || request.getStartHour() >= r.end_hour))){
        return true;
    }
    else{
        return false;
    }
}


bool ReservationSystem::reserve(ReservationRequest request){
    if (request.getEndHour() <= request.getStartHour()){
    return false;
}
    for(int i = 0; i < room_count; i++){
        bool has_conflict = false;
        if (room_capacities[i] >= request.getStudentCount()){
        for(int j = 0; j < reservation_count[i]; j++){
            if(timeconflict(reservations[i][j], request)){
                has_conflict = true;
                break;
            }
        }
        if (!has_conflict){

            Reservation new_reservation;
            new_reservation.course_name = request.getCourseName();
            new_reservation.weekday = request.getWeekday();
            new_reservation.start_hour = request.getStartHour();
            new_reservation.end_hour = request.getEndHour();
            new_reservation.student_count = request.getStudentCount();

            reservations[i][reservation_count[i]] = new_reservation;

            reservation_count[i]++;

            return true;
        }
        }
    }
            return false;
}
            
bool ReservationSystem::cancel(std::string course_name){
    for(int i = 0; i < room_count; i++){
        for(int j = 0; j < reservation_count[i]; j++){
            if (reservations[i][j].course_name == course_name){
                reservations[i][j] = reservations[i][reservation_count[i]-1];
                reservation_count[i]--;
                return true;
            }
        
        
        }

    }
    return false;

}