/* xsh_printready.c - xsh_printready */

#include <xinu.h>
#include <stdio.h>
#include <string.h>


/*------------------------------------------------------------
* xsh_printready - shell command to print the readylist
*------------------------------------------------------------
*/

shellcmd xsh_printready(int nargs, char *args[])
{
    pid32 readypid;
    struct procent *prptr;
	
    kprintf("\nhead <-> ");

    // walk the ready list and print pid
    readypid = firstid(readylist);
    while (readypid != queuetail(readylist))
    {
        
        kprintf("%d <-> ", readypid);

        readypid = queuetab[readypid].qnext;
    }

    kprintf("tail\n\n");
    return 0;

}