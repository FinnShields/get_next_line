# get_next_line
get_next_line project from Hive Helsinki.

This is the third project I've finished at Hive. It was much more challenging than previous projects, though without
introducing any fundamentally new concepts besides static variables.

The purpose of this project is to create a function which returns the next line of a given file.
In the event of a failure or if it's already returned all the lines, it returns NULL.
My function works by first checking if the static buffer contains any valid new lines (which may be the case as the buffer could be of any size)
and then returning the first one. If none are found, it reads the file and then checks the buffer again - the process is then repeated.
