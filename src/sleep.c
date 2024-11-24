#include <stdio.h>
#include <pico/stdlib.h>


#define OUTPUT_PIN 7
#define DELAY_TIME  350

bool toggle = false;

int main(void)
{
    int toggle = 0;
    stdio_init_all();
    gpio_init(OUTPUT_PIN);
    gpio_set_dir(OUTPUT_PIN, GPIO_OUT);
    gpio_put(OUTPUT_PIN, toggle);

    while (true) {
        toggle = !toggle;
        gpio_put(OUTPUT_PIN, toggle);
        sleep_ms(DELAY_TIME);
    }
}