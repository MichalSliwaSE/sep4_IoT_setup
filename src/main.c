// #include "includes.h"
// #include "periodic_task.h"
// #include "pc_comm.h"
// #include "display.h"
// #include "leds.h"
// #include "servo.h"
// #include "tone.h"
// #include "light.h"
// #include "pir.h"


// void func_a(){
// //static uint16_t i = -10;
// //display_int(i++);

// pc_comm_send_string_blocking("!!!!!!!!!!!!!!!!!!!!!");
// }

// void func_b(){
//     static uint8_t state = 0;
//     if (state==0)
//     {
//         servo(50);
//         state = 1;
//     }
//     else {
//         servo(100);
//         state = 0;
//     }
    

// }

// void func_c(){

// sei();
// pc_comm_send_string_blocking("   _______________                        |*\\_/*|________\n"
// "  |  ___________  |     .-.     .-.      ||_/-\\_|______  |\n"
// "  | |           | |    .****. .****.     | |           | |\n"
// "  | |   0   0   | |    .*****.*****.     | |   0   0   | |\n"
// "  | |     -     | |     .*********.      | |     -     | |\n"
// "  | |   \\___/   | |      .*******.       | |   \\___/   | |\n"
// "  | |___     ___| |       .*****.        | |___________| |\n"
// "  |_____|\\_/|_____|        .***.         |_______________|\n"
// "    _|__|/ \\|_|_.............*.............._|________|_\n"
// "   / ********** \\                          / ********** \\\n"
// " /  ************  \\                      /  ************  \\\n"
// "--------------------                    --------------------\n");

// }
// int16_t globalcounter=0;
// void func2(){
//     globalcounter++;
    

// }
// int main(void)
// {

//     display_init();     
//     //light_init();
//     pir_init(func2);

 

// while (1)
// {
//     display_int(globalcounter);
//     _delay_ms(500);
   
// }

   


//     return 0;
// }


#include "wifi.h"
#include <util/delay.h>
#include <stdlib.h>
#include "display.h"
#include "buttons.h"
#include "dht11.h"
#include "light.h"
#include <avr/interrupt.h>
#include "tone.h"
#include "adxl345.h"
#include "hc_sr04.h"

uint8_t humidity_integer, humidity_decimal, temperature_integer, temperature_decimal;

int main(){
    wifi_init();
    display_init();
    buttons_init();
    dht11_init();
    light_init();
    adxl345_init(); // Initialize the ADXL345 accelerometer
    tone_init();
    hc_sr04_init();


    // wifi_command_join_AP(char *ssid, char *password);
    // wifi_command_create_TCP_connection(char *IP, uint16_t port, WIFI_TCP_Callback_t callback_when_message_received, data buffer(we decide) );
    // wifi_command_join_AP("Badabimbadabum","zhGK1299");
    // wifi_command_create_TCP_connection("172.20.10.2", 23, NULL, NULL);

        //Read humidity and temperature from DHT11 sensor
        cli();
        dht11_get(&humidity_integer, &humidity_decimal, &temperature_integer, &temperature_decimal);
        sei();
        play_song();
   
    while(1){
        // wifi_command_TCP_transmit(uint8_t *data, uint16_t length);
        // wifi_command_TCP_transmit("Hi", 2);

    
        // Display humidity and temperature on the LCD WORKING
        _delay_ms(2000);
        display_int((humidity_integer * 10) + humidity_decimal);
        _delay_ms(2000);
        display_int((temperature_integer * 10) + temperature_decimal);
        _delay_ms(2000); // Delay to avoid rapid display updates

        // uint16_t light_intensity = light_read();
        // display_int(light_intensity);
        // _delay_ms(2000);
        

        // int16_t x_acceleration, y_acceleration, z_acceleration;
        // adxl345_read_xyz(&x_acceleration, &y_acceleration, &z_acceleration); //divide by 834
        // _delay_ms(2000);
        // display_int(x_acceleration);
        // _delay_ms(2000);
        // display_int(y_acceleration);
        // _delay_ms(2000);
        // display_int(z_acceleration);
        // _delay_ms(2000);

        // uint16_t distance =  hc_sr04_takeMeasurement();
        // _delay_ms(2000);    
        //  display_int(distance);
        // _delay_ms(2000);



}}