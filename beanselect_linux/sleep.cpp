#include "sleep.h"
#ifdef unix

void Sleep(int value){
    sleep(((float)value)/1000);
}
#endif
