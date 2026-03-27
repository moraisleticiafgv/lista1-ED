#include "ReservationSystem.hpp"

ReservationSystem::ReservationSystem(int room_count, int* room_capacities) {
    this->room_count = room_count;

    this->room_capacities = new int[room_count];
    this->count_reservas_salas = new int[room_count];
    this->reservas_salas = new ReservationRequest*[room_count];

    for (int i = 0; i < room_count; i++) {
        this->room_capacities[i] = room_capacities[i];
        this->count_reservas_salas[i] = 0;

        this->reservas_salas[i] = new ReservationRequest[70];
    }
}

ReservationSystem::~ReservationSystem() {
    for (int i = 0; i < room_count; i++) {
        delete[] reservas_salas[i];
    }

    delete[] reservas_salas;
    delete[] room_capacities;
    delete[] count_reservas_salas;
}

bool reserve(ReservationRequest request){
    for(i = 0; i < reservas_salas[i]; i++ ){
        for(j = 0, j < count_reservas_salas[j], j++){
            if(request.getWeekday() && ){
                if(request.getStudentCount() <= room_capacities[i]){
                    reservas_salas

                }
            }
            return False
        }
    }
    return True




}
bool cancel(std::string course_name);

void printSchedule();

// Outros métodos utilitários necessários
// para auxiliar nas funções requisitadas
};