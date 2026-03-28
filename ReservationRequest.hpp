#ifndef RESERVATIONREQUEST_HPP
#define RESERVATIONREQUEST_HPP

#include <string>

// Representa uma solicitação de reserva de sala feita pelo usuário
class ReservationRequest
{

private:
    std::string course_name; // nome da disciplina
    std::string weekday;     // dia da semana
    int start_hour;          // hora de início
    int end_hour;            // hora de término
    int student_count;       // número de alunos

public:
    ReservationRequest(std::string course_name, std::string weekday, int start_hour, int end_hour, int student_count);
    ~ReservationRequest();

    int getStartHour();
    int getEndHour();
    std::string getCourseName();
    std::string getWeekday();
    int getStudentCount();
};

#endif