#pragma once
#ifndef SUBJECT_H
#define SUBJECT_H

#include "observer.h"
#include <vector>

class Subject {
public:
    void addObserver(Observer* observer);
    void removeObserver(Observer* observer);
    void notifyObservers();

private:
    std::vector<Observer*> observers;
};

#endif // SUBJECT_H
