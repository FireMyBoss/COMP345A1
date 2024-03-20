//
// Created by Nicholas Kamra on 3/18/24.
//

#include "Observable.h"
#include "Observer.h"

void Observable::attach(Observer * observerToAdd){
    this->observerVec.push_back(observerToAdd);
}
void Observable::detach(Observer * observerToRemove){
    if(this->observerVec.empty())
        return;

    auto indexToRemove = std::find(this->observerVec.begin(), this->observerVec.end(), observerToRemove);
    this->observerVec.erase(indexToRemove);
}
void Observable::notify(){
    if(this->observerVec.empty())
        return;

    for(auto & i : this->observerVec)
        i->update(this);
}
