#!/bin/sh

gcc hello_page.c -lfcgi
spawn-fcgi -p 8080 ./a.out
service nginx start
tail -f /dev/null
