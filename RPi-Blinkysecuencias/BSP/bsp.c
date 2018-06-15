#include  "bsp.h"
#include  "HAL/rpi-gpio.h"
#include  "HAL/rpi-armtimer.h"
gpio_t pines[9];
uint8_t intensidades[3];
volatile uint32_t cont ;
volatile uint8_t presionadoDer = 0;
volatile uint8_t presionadoIzq = 0;

void bsp_init(){
    pines[0].func = 1;
    pines[1].func = 1;
    pines[2].func = 1;
    pines[3].func = 1;
    pines[4].func = 0;
    pines[5].func = 0;
    pines[6].func = 1;
    pines[7].func = 1;
    pines[8].func = 1;

    pines[0].num = 23;
    pines[1].num = 18;
    pines[2].num = 15;
    pines[3].num = 14;
    pines[4].num = 27; //izq
    pines[5].num = 22; //der
    pines[6].num = 2;
    pines[7].num = 3;
    pines[8].num = 4;
    gpio_init(pines[0]);
    gpio_init(pines[1]);
    gpio_init(pines[2]);
    gpio_init(pines[3]);
    gpio_init(pines[4]);
    gpio_init(pines[5]);
    gpio_init(pines[6]);
    gpio_init(pines[7]);
    gpio_init(pines[8]);

    RPI_ArmTimerInit();
}

void led_off( int pin){
    gpio_off(pines[pin]);
}
void led_on( int pin){
    gpio_on(pines[pin]);
}
int boton_read(int pin){

                if(gpio_read(pines[pin]) && pin == 4){
                presionadoIzq=1;
                return 1;
                }
                else if(gpio_read(pines[pin] ) && pin == 5){
                    presionadoDer=1;
                    return 1;
                } 
                else return 0;
              
}

int sensadoDer(){
        
        int pin = 5;
        boton_read(pin);
                if(presionadoDer==1){
                    if(!boton_read(pin)){
                    presionadoDer=0;
                    secuencia++;
                    return 1;
                    }
                    else return 0;
                }
                else return 0;      
}
int sensadoIzq(){
        int pin = 4;
        boton_read(pin);
                if(presionadoIzq==1){
                    if(!boton_read(pin)){
                    presionadoIzq=0;
                    secuencia--;
                    return 1;
                    }
                    else return 0;
                }
                else return 0;
}
   
    

void delay_ms(uint32_t ms){
    cont = ms*4;
    while(cont){
        if( sensadoDer() || sensadoIzq()){
        	pressed = 1;
            break;  
        }
    }
}

void delay_us(uint32_t us){
	cont = us;
	while(cont){
	}
	
}


