//
//  main.cpp
//  task2
//
//  Created by Виктор Задябин on 12/09/2019.
//  Copyright © 2019 Виктор Задябин. All rights reserved.
//

#include "enums.hpp"
#include "event/event.hpp"
#include "request/request.hpp"
#include "calendar/calendar.hpp"

int main(int argc, char **argv )
{
//    Calendar calendar;
//    Queue queue;
//    float curr_time = 0;
//    Event *curr_ev;
//    float dt;
//    int cpu_state = IDLE;
//    float run_begin; //
//    srand(2019);
//    // начальное событие и инициализация календаря
//    curr_ev = new Event(curr_time, EV_INIT, 0);
//    calendar.put( curr_ev );
//    // цикл по событиям
//
//    while((curr_ev = calendar.get()) != NULL )
//    {
//        cout << "time " << curr_ev->time << " type " << curr_ev->type << endl;
//        curr_time = curr_ev->time; // продвигаем время
//        // обработка события
//        if( curr_time >= LIMIT )break; // типичное дополнительное условие останова моделирования
//        switch(curr_ev->type)
//        {
//            case EV_INIT:  // запускаем генераторы запросов
//                calendar.put(new Event(curr_time, EV_REQ, 1));
//                calendar.put(new Event(curr_time, EV_REQ, 2));
//                break;
//            case EV_REQ:
//                // планируем событие окончания обработки, если процессор свободен, иначе ставим в очередь
//                dt = get_req_time(curr_ev->attr);
//                cout << "dt " << dt << " num " << curr_ev->attr << endl;
//                if(cpu_state == IDLE)
//                {
//                    cpu_state = RUN;
//                    calendar.put(new Event(curr_time+dt, EV_FIN, curr_ev->attr));
//                    run_begin = curr_time;
//                }
//                else
//                    queue.push_back(new Request(dt, curr_ev->attr));
//                // планируем событие генерации следующего задания
//                calendar.put(new Event(curr_time+get_pause_time(curr_ev->attr), EV_REQ, curr_ev->attr));
//                break;
//            case EV_FIN:
//                // объявляем процессор свободным и размещаем задание из очереди, если таковое есть
//                cpu_state=IDLE;
//                // выводим запись о рабочем интервале
//                cout << "Работа с " << run_begin << " по " << curr_time << " длит. " << (curr_time-run_begin) << endl;
//
//                if (!queue.empty())
//                {
//                    Request *rq = queue.front();
//                    queue.pop_front();
//                    calendar.put(new Event(curr_time+rq->time, EV_FIN, rq->source_num));
//                    run_begin = curr_time;
//                    delete rq;
//                } break;
//        } // switch
//        delete curr_ev;
//    } // while
} // main

//int rc = 0; int pc = 0;
//float get_req_time(int source_num)
//{
//    // Для демонстрационных целей - выдаётся случайное значение
//    // при детализации модели функцию можно доработать
//    double r = ((double)rand())/RAND_MAX;
//    cout << "req " << rc << endl; rc++;
//    if(source_num == 1) return r*10; else return r*20;
//}
//
//float get_pause_time(int source_num) // длительность паузы между заданиями
//{
//    // см. комментарий выше
//    double p = ((double)rand())/RAND_MAX;
//    cout << "pause " << pc << endl; pc++;
//    if(source_num == 1) return p*20; else return p*10;
//}
