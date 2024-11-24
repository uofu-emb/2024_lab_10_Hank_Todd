#include <stdio.h>
#include "FreeRTOS.h"
#include "task.h"
#include "pico/stdlib.h"
#include "pico/multicore.h"
#include "pico/cyw43_arch.h"


bool toggle = false;

#define DELAY_TIME 350
#define OUTPUT_PIN 7
#define MAIN_TASK_PRIORITY      ( tskIDLE_PRIORITY + 1UL )
#define MAIN_TASK_STACK_SIZE configMINIMAL_STACK_SIZE


void main_task(__unused void *params) {

   while(true){
    gpio_put(OUTPUT_PIN, toggle);
    toggle = !toggle;
    vTaskDelay(pdMS_TO_TICKS(DELAY_TIME ));
   }
}


int main( void )
{
    stdio_init_all();
    gpio_init(OUTPUT_PIN);
    gpio_set_dir(OUTPUT_PIN, GPIO_OUT);
    const char *rtos_name;
    rtos_name = "FreeRTOS";
    TaskHandle_t task;
    xTaskCreate(main_task, "MainThread",
                MAIN_TASK_STACK_SIZE, NULL, MAIN_TASK_PRIORITY, &task);
    vTaskStartScheduler();
    return 0;
}
