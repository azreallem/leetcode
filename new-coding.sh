#!/bin/bash

START_TIME=`date +%s`

# do something 
output=`find . -name "*.cpp" -type f -printf '%Ts %p\n' | sort -nr | head -1`
file_name=${output#*\ }
echo "${file_name}"
vim $file_name

# end do something
END_TIME=`date +%s`
EXECUTING_TIME=`expr $END_TIME - $START_TIME`
echo "${EXECUTING_TIME}s"
