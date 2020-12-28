#ifndef EVENTARGS_H
#define EVENTARGS_H


class EventArgs
{
public:
    void * sender;
    EventArgs(void * sender);
};

#endif // EVENTARGS_H
