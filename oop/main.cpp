#include <iostream>
#include <string>
#include "creature.h"
#include "counter.h"
#include "eventargs.h"
#include "counter2.h"

using namespace std;


void c_onCounterStart(Counter * sender);
void c_onCounterChange(Counter * sender);
void c_onCounterFinish(Counter * sender);



void c2_onCounterStart(EventArgs e);
void c2_onCounterChange(EventArgs e);
void c2_onCounterFinish(EventArgs e);




int main()
{
    Creature dog("Günther", 4, 80, 35);
    cout << "name: " << dog.getName() << endl;
    cout << "age: " << dog.getAge() << endl;
    cout << "height: " << dog.getHeight() << endl;
    cout << "weight: " << dog.getWeight() << endl;

    cout << "--------------------------------------------------------" << endl;


    Counter c(0, 10, 1);
    c.setOnCounterStart(& c_onCounterStart);
    //c.removeOnCounterStart();
    c.setOnCounterChange(& c_onCounterChange);
    c.setOnCounterFinish(& c_onCounterFinish);
    c.run();

    cout << "--------------------------------------------------------" << endl;

    Counter2 c2(0, 10, 1);
    c2.setOnCounterStart(& c2_onCounterStart);
    c2.setOnCounterChange(& c2_onCounterChange);
    //c2.removeOnCounterChange();
    c2.setOnCounterFinish(& c2_onCounterFinish);

    c2.run();

    return 0;
}

void c_onCounterStart(Counter * sender) {
    Counter counter = * sender;
    cout << "ON_START count: " << counter.getCount() << endl;
}

void c_onCounterChange(Counter * sender) {
    Counter counter = * sender;
    cout << "ON_CHANGE count: " << counter.getCount() << endl;
}

void c_onCounterFinish(Counter * sender) {
    Counter counter = * sender;
    cout << "ON_FINISH count: " << counter.getCount() << endl;
}




// Event Funktionen für Counter2
void c2_onCounterStart(EventArgs args) {
    Counter sender = * static_cast<Counter *>(args.sender);
    cout << "Counter2 ON_COUNTER_START count: " << sender.getCount() << endl;
}

void c2_onCounterChange(EventArgs args) {
    Counter sender = * static_cast<Counter *>(args.sender);
    cout << "Counter2 ON_COUNTER_CHANGE count: " << sender.getCount() << endl;
}

void c2_onCounterFinish(EventArgs args) {
    Counter sender = * static_cast<Counter *>(args.sender);
    cout << "Counter2 ON_COUNTER_FINISH count: " << sender.getCount() << endl;
}