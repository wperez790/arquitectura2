#include "rpi-armtimer.h"
#include "rpi-interrupts.h"

extern void __enable_interrupts();

static rpi_arm_timer_t* rpiArmTimer = (rpi_arm_timer_t*)RPI_ARMTIMER_BASE;

rpi_arm_timer_t* RPI_GetArmTimer(void)
{
    return rpiArmTimer;
}

void RPI_ArmTimerInit(void)
{
	RPI_GetIrqController()->Enable_Basic_IRQs = RPI_BASIC_ARM_TIMER_IRQ ;
	__enable_interrupts();
	RPI_GetArmTimer()->Load = 250;
	RPI_GetArmTimer()->Reload = 250;
	

	RPI_GetArmTimer()->Control = RPI_ARMTIMER_CTRL_32BIT |
								 RPI_ARMTIMER_CTRL_ENABLE |
								 RPI_ARMTIMER_CTRL_PRESCALE_1|
								 RPI_ARMTIMER_CTRL_INT_ENABLE ;
	

}
void RPI_ArmTimerClear(void)
{
	RPI_GetArmTimer()->IRQClear = 1;
}
