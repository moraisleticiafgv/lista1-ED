#include <iostream>
using namespace std;

#include "ReservationSystem.hpp"
#include "ReservationRequest.hpp"

int main(){
    int capacities[3] = {30, 50, 80};
    ReservationSystem system(3, capacities);

    ReservationRequest r1("calculo", "terca", 9, 11, 80);

    if(system.reserve(r1)){
        cout << "Reserva realizada!" << endl;
    } else {
        cout << "Não foi possível realizar a reserva" << endl;
    }

    ReservationRequest r2("algebra", "quinta", 9, 10, 70);

    if(system.reserve(r2)){
        cout << "Reserva realizada!" << endl;
    } else {
        cout << "Não foi possível realizar a reserva" << endl;
    }

    // if(system.cancel("calculo")){
    // cout << "Cancelado com sucesso!" << endl;
    // } 
    // else {
    // cout << "Disciplina não encontrada!" << endl;
    //  }

    // if(system.cancel("computacao")){
    // cout << "Cancelado com sucesso!" << endl;
    // } 
    // else {
    // cout << "Disciplina não encontrada!" << endl;
    //  }

    system.printSchedule();

    return 0;
};