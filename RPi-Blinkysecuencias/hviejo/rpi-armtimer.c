#include "rpi-armtimer.h"

extern void __enable_interrupts();

static rpi_arm_timer_t* rpiArmTimer = (rpi_arm_timer_t*)RPI_ARMTIMER_BASE;

rpi_arm_timer_t* RPI_GetArmTimer(void)
{
    return rpiArmTimer;
}

void RPI_ArmTimerInit(void)
{
	RPI_GetIrqController()->Enable_Basic_IRQs = RPI_BASIC_ARM_TIMER_IRQ ;

	RPI_GetArmTimer()->Load = 1000;

	RPI_GetArmTimer()->Control = RPI_ARMTIMER_CTRL_32BIT |
								 RPI_ARMTIMER_CTRL_ENABLE |
								 RPI_ARMTIMER_CTRL_PRESCALE_1|
								 RPI_ARMTIMER_CTRL_INT_ENABLE ;
	__enable_interrupts();

}
void RPI_ArmTimerClear(void)
{
	RPI_GetArmTimer()->IRQClear = 1;
}
