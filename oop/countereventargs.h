#ifndef COUNTEREVENTARGS_H
#define COUNTEREVENTARGS_H

#include "eventargs.h"

class CounterEventArgs : public EventArgs
{
public:
    CounterEventArgs(void * sender);
};

#endif // COUNTEREVENTARGS_H
