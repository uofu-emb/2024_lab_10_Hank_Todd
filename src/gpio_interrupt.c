/**
 * Copyright (c) 2022 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>

#include "pico/stdlib.h"
#include "pico/multicore.h"
#include "pico/cyw43_arch.h"

#define INPUT_PIN 6
#define OUTPUT_PIN 7

void irq_callback(uint gpio, uint32_t event_mask)
{
    if (gpio != INPUT_PIN) return;
    if (event_mask & GPIO_IRQ_EDGE_RISE) {
        gpio_put(OUTPUT_PIN, true);
    } else if (event_mask & GPIO_IRQ_EDGE_FALL) {
        gpio_put(OUTPUT_PIN, false);
    }
}

int main(void)
{
    stdio_init_all();

    gpio_init(INPUT_PIN);
    gpio_set_dir(INPUT_PIN, GPIO_IN);
    gpio_pull_down(INPUT_PIN);
    gpio_init(OUTPUT_PIN);
    gpio_set_dir(OUTPUT_PIN, GPIO_OUT);
    gpio_put(OUTPUT_PIN, false);

    gpio_set_irq_enabled_with_callback(INPUT_PIN, GPIO_IRQ_EDGE_RISE | GPIO_IRQ_EDGE_FALL , true, irq_callback);
    while(1) __wfi();
    return 0;
}
