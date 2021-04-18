/* xsh_movetime.c - xsh_movetime */

#include <xinu.h>
#include <stdio.h>
#include <string.h>


/*------------------------------------------------------------
* xsh_XXX - shell command to do whatever you want it to
*------------------------------------------------------------
*/

shellcmd xsh_movetime(int nargs, char *args[])
{
	char    ch;
    char    *chtime;
    int32   timepassed;
    
    // default time passed is 1 unit
    if (nargs == 1) {
        timepassed = 1;
    }
	// else, pass specified amount of time
    else if ( nargs == 2 ) {
        chtime = args[1];
        ch = *chtime++;
        timepassed = 0;
        while(ch != NULLCH) {
            if ((ch <'0') || (ch > '9')) {
                kprintf("%s: non-digit in time\n", args[1]);
                return 1;
            }
            timepassed = 10*timepassed + (ch - '0');
            ch = *chtime++;
        }

        if (timepassed < 0) {
            kprintf("%s: invalid time\n", args[1]);
            return 1;
        }
 
    }
    else {
        kprintf("Too many arguments\n");
        return 1;
    }
    // call passtime
    passtime(timepassed);
	
    return 0;

}