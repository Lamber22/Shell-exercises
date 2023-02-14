echo A shell script that prints the maximum value a process ID can be.

#!/bin/bash
echo The maximum value is:
cat /proc/sys/kernel/pid_max
