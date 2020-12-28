#include "counter.h"

#include <iostream>
using namespace std;

Counter::Counter(int start, int end, int step)
{
    this->reset(start, end, step);
}

int Counter::getCount() {
    return this->count;
}

// onCounterStart Event
void Counter::setOnCounterStart(void (*onCounterStart)(Counter * sender)) {
    this->onCounterStart = onCounterStart;
}

void Counter::removeOnCounterStart() {
    this->onCounterStart = nullptr;
}

void Counter::fireOnCounterStart(Counter * sender) {
    if(this->onCounterStart != nullptr) {
        this->onCounterStart(sender);
    }
}

// onCounterChange Event
void Counter::setOnCounterChange(void (*onCounterChange)(Counter *)) {
    this->onCounterChange = onCounterChange;
}

void Counter::removeOnCounterChange() {
    this->onCounterChange = nullptr;
}

void Counter::fireOnCounterChange(Counter * sender) {
    if(this->onCounterChange != nullptr) {
        this->onCounterChange(sender);
    }
}

// onCounterFinish Event
void Counter::setOnCounterFinish(void (*onCounterFinish)(Counter *)) {
    this->onCounterFinish = onCounterFinish;
}

void Counter::removeOnCounterFinish() {
    this->onCounterFinish = nullptr;
}

void Counter::fireOnCounterFinish(Counter *sender) {
    if(this->onCounterFinish != nullptr) {
        this->onCounterFinish(sender);
    }
}


void Counter::run() {
    //cout << "START" << endl;
    this->fireOnCounterStart(this);

    for(; this->count < this->end; this->count += this->step) {
        //cout << "CHANGE: " << this->count << endl;
        this->fireOnCounterChange(this);
    }

    //cout << "FINISH" << endl;
    this->fireOnCounterFinish(this);
}

void Counter::reset(int start, int end, int step) {
    this->start = start;
    this->end = end;
    this->step = step;
    this->count = this->start;
}
