#include "counter2.h"
#include "eventargs.h"
#include "countereventargs.h"


Counter2::Counter2(int start, int end, int step)
{
    this->reset(start, end, step);
}

int Counter2::getCount() {
    return this->count;
}

// onCounterStart Event
void Counter2::setOnCounterStart(void (* onCounterStart)(CounterEventArgs args)) {
    this->onCounterStart = onCounterStart;
}

void Counter2::removeOnCounterStart() {
    this->onCounterStart = nullptr;
}

void Counter2::fireOnCounterStart(CounterEventArgs args) {
    if(this->onCounterStart != nullptr) {
        this->onCounterStart(args);
    }
}

// onCounterChange Event
void Counter2::setOnCounterChange(void (* onCounterChange)(CounterEventArgs args)) {
    this->onCounterChange = onCounterChange;
}

void Counter2::removeOnCounterChange() {
    this->onCounterChange = nullptr;
}

void Counter2::fireOnCounterChange(CounterEventArgs args) {
    if(this->onCounterChange != nullptr) {
        this->onCounterChange(args);
    }
}

// onCounterFinish Event
void Counter2::setOnCounterFinish(void (* onCounterFinish)(CounterEventArgs args)) {
    this->onCounterFinish = onCounterFinish;
}

void Counter2::removeOnCounterFinish() {
    this->onCounterFinish = nullptr;
}

void Counter2::fireOnCounterFinish(CounterEventArgs args) {
    if(this->onCounterFinish != nullptr) {
        this->onCounterFinish(args);
    }
}



void Counter2::run() {
    //EventArgs e(this);

    this->fireOnCounterStart(CounterEventArgs(this, & this->count));

    for(; this->count < this->end; this->count += this->step) {
        this->fireOnCounterChange(CounterEventArgs(this, & this->count));
    }

    this->fireOnCounterFinish(CounterEventArgs(this, & this->count));
}

void Counter2::reset(int start, int end, int step) {
    this->start = start;
    this->end = end;
    this->step = step;
    this->count = this->start;
}
