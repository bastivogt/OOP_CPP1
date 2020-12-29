#include "eventargs.h"
#include "countereventargs.h"

#ifndef COUNTER2_H
#define COUNTER2_H


class Counter2
{
private:
    int start;
    int end;
    int step;
    int count;

    void (* onCounterStart)(CounterEventArgs args) = nullptr;
    void (* onCounterChange)(CounterEventArgs args) = nullptr;
    void (* onCounterFinish)(CounterEventArgs args) = nullptr;



protected:
    void fireOnCounterStart(CounterEventArgs args);
    void fireOnCounterChange(CounterEventArgs args);
    void fireOnCounterFinish(CounterEventArgs args);

public:
    Counter2(int start, int end, int step);
    int getCount();
    void run();
    void reset(int start, int end, int step);

    void setOnCounterStart(void (* onCounterStart)(CounterEventArgs args));
    void removeOnCounterStart();

    void setOnCounterChange(void (* onCounterChange)(CounterEventArgs args));
    void removeOnCounterChange();

    void setOnCounterFinish(void (* onCounterFinish)(CounterEventArgs args));
    void removeOnCounterFinish();


};

#endif // COUNTER_H
