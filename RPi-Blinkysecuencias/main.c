#include "BSP/bsp.h"
#define maxSeg 6000.0  /*Máximos segundos que durara el ciclo de cambio de colores*/
#define factor1 12.0 /*Factor de division del tiempo maximo para obtener el tiempo que durara el primer incremento/decremento */
#define factor2 6.0  /*Factor de division del tiempo maximo para obtener el tiempo que durara el segundo incremento/decremento */
#define factor3 4.0 /*Factor de division del tiempo maximo para obtener el tiempo que durara el tercer incremento/decremento */
#define numIntensidades 10 /*Cantidad de intensidades que tendra un incremento/decremento*/
#define INTERVALOS 5
#define MAX 33

//PROTOTYPE
void secuencia1();
void secuencia2();
void secuencia3();
void secuencia4();
//
int tiempo;
int var=1;
int i;
int ledRetorno=1;
int encender = 1;
static int uno = 0;
static int dos = 1;
static int tres = 2;
static int cuatro = 3;

int notmain( void ){   
	pressed = 0;
    secuencia = 1;
    bsp_init();
    

while(1){
       
		switch(secuencia){
            case 0:
                secuencia =4;
                break;
            case 1: 
                    led_on(6);
                    led_off(7);
                    led_off(8);
                    secuencia1();
                    
                    
                break;
            case 2: 
                    led_on(7);
                    led_off(8);
                    led_off(6);
                    secuencia2();
                    

                break;
            case 3:
                    led_on(8);
                    led_off(6);
                    led_off(7);
            		secuencia3();
                break;
            case 4: led_on(8);
                    led_on(7);
                    led_on(6);
            		secuencia4();
                break;
            case 5:
                secuencia =1; 
                break;
        }

    }
    return 0;
}

void secuencia1(){
        
        switch(ledRetorno){
            case 1: 
                    led_on(uno);
                    delay_ms(500);
                    led_off(uno);
                    if(pressed){ pressed = 0; return; }
                    ledRetorno++;
                break;
            case 2: led_on(dos);
                    delay_ms(500);
                    led_off(dos);
                    if(pressed){ pressed = 0; return; }
                    ledRetorno++;
                break;
            case 3: 
                    led_on(tres);
                    delay_ms(500);
                    led_off(tres);
                    if(pressed){ pressed = 0; return; }
                    ledRetorno++;
                break;
            case 4: 
                    led_on(cuatro);
                    delay_ms(500);
                    led_off(cuatro);
                    if(pressed){ pressed = 0; return; }
                    ledRetorno=1;
                break;
        }
        
}
void secuencia2(){
	
    switch(ledRetorno){
            case 4: 
            		led_on(cuatro);
                    delay_ms(500);
                    led_off(cuatro);
                    if(pressed){ pressed = 0; return; }
                    ledRetorno--;
                break;
            case 3:
            		led_on(tres);
                    delay_ms(500);
                    led_off(tres);
                    if(pressed){ pressed = 0; return; }
                    ledRetorno--;
                break;
            case 2: 
            		led_on(dos);
                    delay_ms(500);
                    led_off(dos);
                    if(pressed){ pressed = 0; return; }
                    ledRetorno--;
                break;
            case 1: 
            		led_on(uno);
                    delay_ms(500);
                    led_off(uno);
                    if(pressed){ pressed = 0; return; }
                	ledRetorno= 4;
                break;
        }
}
void secuencia3(){

if(var==1){
switch(ledRetorno){
            case 1: 
                    led_on(uno);
                    delay_ms(500);
                    led_off(uno);
                    if(pressed){ pressed = 0; return; }
                    ledRetorno++;
                break;
            case 2: 
                    led_on(dos);
                    delay_ms(500);
                    led_off(dos);
                    if(pressed){ pressed = 0; return; }
                    ledRetorno++;
                break;
            case 3: 
                    led_on(tres);
                    delay_ms(500);
                    led_off(tres);
                    if(pressed){ pressed = 0; return; }
                    ledRetorno++;
                break;
            case 4:
                 led_on(cuatro);
                    delay_ms(500);
                    led_off(cuatro);
                    var=2;
                break;
    }
    

}else{
    switch(ledRetorno){
            case 1: led_on(uno);
                    delay_ms(500);
                    led_off(uno);
                    var=1;
                    
                break;
            case 2: led_on(dos);
                    delay_ms(500);
                    led_off(dos);
                    if(pressed){ pressed = 0; return; }
                    ledRetorno--;
                    
                break;
            case 3: 
                    led_on(tres);
                    delay_ms(500);
                    led_off(tres);
                    if(pressed){ pressed = 0; return; }
                    ledRetorno--;
                    
                break;
            case 4: 
                    led_on(cuatro);
                    delay_ms(500);
                    led_off(cuatro);
                    if(pressed){ pressed = 0; return; }
                    ledRetorno--;

                break;
    }
}
    
	

}
void secuencia4(){

	
	switch(ledRetorno){
            case 1: 
            		if(encender) led_on(uno);
                	else led_off(uno);
                    delay_ms(500);
                    if(pressed){ pressed = 0; return; }
                    ledRetorno++;
                break;
            case 2: 
            		if(encender) led_on(dos);
            		else led_off(dos);
                    delay_ms(500);
                    if(pressed){ pressed = 0; return; }
                    ledRetorno++;
                break;
            case 3: 
                    if(encender) led_on(tres);
                    else led_off(tres);
                    delay_ms(500);
                    if(pressed){ pressed = 0; return; }
                    ledRetorno++;
                break;
            case 4: 
                    if(encender) led_on(cuatro);
                    else led_off(cuatro);
                    delay_ms(500);
                    if(pressed){ pressed = 0; return; }
                    ledRetorno=1;
                    if(encender)
                    	encender = 0;
                	else
                		encender = 1;
                    
                break;
	}
}


