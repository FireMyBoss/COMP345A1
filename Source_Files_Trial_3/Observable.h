//
// Created by Nicholas Kamra on 3/18/24.
//

#ifndef DANDDCODE_OBSERVABLE_H
#define DANDDCODE_OBSERVABLE_H

#include <vector>
class Observer;

class Observable {
public:
    virtual ~Observable(){};
    void attach(Observer * observerToAdd);
    void detach(Observer * observerToRemove);
    void notify();
private:
    std::vector<Observer *> observerVec;
};


#endif //DANDDCODE_OBSERVABLE_H
