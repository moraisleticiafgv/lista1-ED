# Room Reservation System

## Descrição
O projeto consiste em um sistema de gerenciamento de reservas de salas de aula. O sistema possui um conjunto de salas, cada uma com capacidade fixa de alunos. É possível reservar uma sala para uma disciplina em um determinado dia e horário, o sistema atribui automaticamente a primeira sala disponível que comporte o número de alunos solicitado. O sistema também permite cancelar reservas existentes e exibir o calendário completo de reservas organizado por sala.

## Compilação
Para compilar, usa-se o comando: ```g++ main.cpp ReservationSystem.cpp ReservationRequest.cpp -o reservation_system```

## Execução
Após a compilação, o programa pode ser executado pelo comando  ```./reservation_system```

## Organização interna dos dados
O sistema armazena as reservas em um array de duas dimensões, onde cada posição representa uma sala, e cada sala aponta para um array de reservas. Cada reserva é representada por uma struct ```Reservation``` contendo o nome da disciplina, dia da semana, horário de início, horário de fim e número de alunos.
  
