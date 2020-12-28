#include "eventargs.h"

#ifndef COUNTER2_H
#define COUNTER2_H


class Counter2
{
private:
    int start;
    int end;
    int step;
    int count;

    void (* onCounterStart)(EventArgs args) = nullptr;
    void (* onCounterChange)(EventArgs args) = nullptr;
    void (* onCounterFinish)(EventArgs args) = nullptr;

protected:
    void fireOnCounterStart(EventArgs args);
    void fireOnCounterChange(EventArgs args);
    void fireOnCounterFinish(EventArgs args);

public:
    Counter2(int start, int end, int step);
    int getCount();
    void run();
    void reset(int start, int end, int step);

    void setOnCounterStart(void (* onCounterStart)(EventArgs args));
    void removeOnCounterStart();

    void setOnCounterChange(void (* onCounterChange)(EventArgs args));
    void removeOnCounterChange();

    void setOnCounterFinish(void (* onCounterFinish)(EventArgs args));
    void removeOnCounterFinish();


};

#endif // COUNTER_H
