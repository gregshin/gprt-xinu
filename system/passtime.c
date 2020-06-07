#include <xinu.h>
#include <stdio.h>

// function walks the ready list and adjusts time
void passtime(int32 time)
{
    struct procent *prptr;
    pid32 readypid;

    readypid = firstid(readylist);

    // walk the ready list and adjust time
    while(readypid != queuetail(readylist))
    {
        prptr = &proctab[readypid];

        if (prptr->prdl > 0)
        {
            int32 newdl = prptr->prdl - time;

            prptr->prdl = newdl;

            if (newdl <= 0)
            {
                rtprio(readypid);
            }
        }
        readypid = queuetab[readypid].qnext;
    }

    return OK;
}