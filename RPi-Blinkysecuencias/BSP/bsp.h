#include <stdint.h>
 /*typedef enum {
     led_1,
     led_2,
     led_3,
     led_4
 } leds_t;
 typedef enum {
     bot_1,
     bot_2
 } boton_t;
*/
 volatile int secuencia;
 volatile int pressed;
 void bsp_init();
 void led_off( int pin);
 void led_on( int pin);
 int boton_read(int pin);
 int sensadoDer();
 int sensadoIzq();
 void led_intensity(int pin, uint8_t intensidad);
 void delay_ms(uint32_t ms);
