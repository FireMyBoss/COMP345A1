//
// Created by Nicholas Kamra on 3/18/24.
//

#ifndef DANDDCODE_OBSERVER_H
#define DANDDCODE_OBSERVER_H

class Observable;


class Observer {
public:
    virtual void update(Observable * observable) = 0;
};


#endif //DANDDCODE_OBSERVER_H
