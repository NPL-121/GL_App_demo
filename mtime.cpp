#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <iostream>

long mtime() // Функция получения момента времени
{
  struct timespec t;
  clock_gettime(CLOCK_REALTIME, &t);
  long mt = (long)t.tv_sec*1000 + t.tv_nsec/1000000;
  return mt;
}
