/* xsh_create.c - xsh_create */

#include <xinu.h>
#include <stdio.h>
#include <string.h>


/*------------------------------------------------------------
* xsh_createdl - shell command to create a real-time task
*------------------------------------------------------------
*/

shellcmd xsh_createdl(int nargs, char *args[])
{
    uint16 deadline;
    pri16   priority;
	char    ch;
    char    *chdl;
	pid32   pid;
    
    // default deadline is 10
    if (nargs == 1) {
        deadline = 10;
    }
	// if # of args is 2, then that number is converted to be deadline
    else if ( nargs == 2 ) {
        chdl = args[1];
        ch = *chdl++;
        deadline = 0;
        while(ch != NULLCH) {
            if ((ch <'0') || (ch > '9')) {
                kprintf("%s: non-digit in deadline\n", args[1]);
                return 1;
            }
            deadline = 10*deadline + (ch - '0');
            ch = *chdl++;
        }
        // error catch negative deadline
        if (deadline < (uint16)MINKEY) {
            kprintf("%s: invalid deadline\n", args[1]);
            return 1;
        }
 
    }

    else {
        kprintf("Too many arguments\n");
        return 1;
    }

    pid = createdl(announce, 1024, deadline, "Real Time", 0);
	
    resume(pid);
	
    return 0;

}