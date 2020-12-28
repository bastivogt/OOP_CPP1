#include "counter2.h"
#include "eventargs.h";

#include <iostream>
using namespace std;

Counter2::Counter2(int start, int end, int step)
{
    this->reset(start, end, step);
}

int Counter2::getCount() {
    return this->count;
}

// onCounterStart Event
void Counter2::setOnCounterStart(void (*onCounterStart)(EventArgs args)) {
    this->onCounterStart = onCounterStart;
}

void Counter2::removeOnCounterStart() {
    this->onCounterStart = nullptr;
}

void Counter2::fireOnCounterStart(EventArgs args) {
    if(this->onCounterStart != nullptr) {
        this->onCounterStart(args);
    }
}

// onCounterChange Event
void Counter2::setOnCounterChange(void (*onCounterChange)(EventArgs args)) {
    this->onCounterChange = onCounterChange;
}

void Counter2::removeOnCounterChange() {
    this->onCounterChange = nullptr;
}

void Counter2::fireOnCounterChange(EventArgs args) {
    if(this->onCounterChange != nullptr) {
        this->onCounterChange(args);
    }
}

// onCounterFinish Event
void Counter2::setOnCounterFinish(void (* onCounterFinish)(EventArgs args)) {
    this->onCounterFinish = onCounterFinish;
}

void Counter2::removeOnCounterFinish() {
    this->onCounterFinish = nullptr;
}

void Counter2::fireOnCounterFinish(EventArgs args) {
    if(this->onCounterFinish != nullptr) {
        this->onCounterFinish(args);
    }
}



void Counter2::run() {
    //cout << "START" << endl;
    EventArgs e(this);
    this->fireOnCounterStart(e);

    for(; this->count < this->end; this->count += this->step) {
        //cout << "CHANGE: " << this->count << endl;
        this->fireOnCounterChange(e);
    }

    //cout << "FINISH" << endl;
    this->fireOnCounterFinish(e);
}

void Counter2::reset(int start, int end, int step) {
    this->start = start;
    this->end = end;
    this->step = step;
    this->count = this->start;
}
