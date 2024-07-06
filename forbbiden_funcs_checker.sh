#!/bin/bash
ALLOWED_FUNCS="malloc|free|write|va_start|va_arg|va_copy|va_end"
cscope -R -L -2 ".*" | awk -F ' ' '{print $2 "#" $1}' | sort | uniq | grep -v /usr | grep -vE "^$ALLOWED_FUNCS" | grep -vE "^ft"
