
#ifndef COUNTER_H
#define COUNTER_H


class Counter
{
private:
    void (* onCounterStart)(Counter * sender) = nullptr;
    void (* onCounterChange)(Counter * sender) = nullptr;
    void (* onCounterFinish)(Counter * sender) = nullptr;


protected:
    int start;
    int end;
    int step;
    int count;

    void fireOnCounterStart(Counter * sender);
    void fireOnCounterChange(Counter * sender);
    void fireOnCounterFinish(Counter * sender);


public:
    Counter(int start, int end, int step);
    int getCount();
    void run();
    void reset(int start, int end, int step);

    void setOnCounterStart(void (* onCounterStart)(Counter * sender));
    void removeOnCounterStart();

    void setOnCounterChange(void (* onCounterChange)(Counter * sender));
    void removeOnCounterChange();

    void setOnCounterFinish(void (* onCounterFinish)(Counter * sender));
    void removeOnCounterFinish();


};

#endif // COUNTER_H
