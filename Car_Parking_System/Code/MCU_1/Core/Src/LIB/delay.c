/* delay source file */
#include "delay.h"

/* delay n milliseconds (16 MHz CPU clock) */
void _delay_ms(u32 time){
	for(u32 i = 0; i < time; i++){
		for(u32 j = 0; j<2000; j++){
		}
	}
}
