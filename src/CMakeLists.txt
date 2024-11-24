# This is the main binary. List your C files here.
add_executable(sleep
    sleep.c
    )

pico_set_program_name(sleep "test")
pico_set_program_version(sleep "0.1")

# Modify the below lines to enable/disable output over UART/USB.
# These are mutually exclusive, only set one.
pico_enable_stdio_uart(sleep 0)
pico_enable_stdio_usb(sleep 1)

# Add the libraries to the build
target_link_libraries(sleep PRIVATE
  pico_stdlib
  pico_multicore
  pico_async_context_freertos
  FreeRTOS-Kernel-Heap4

)

# The CYW43 is the Wifi/Bluetooth module. If the board is set to pico_w, this
# variable will be set and the wireless libraries added.
if(PICO_CYW43_SUPPORTED)
    # For led support on pico_w
    target_link_libraries(sleep PRIVATE
        pico_cyw43_arch_none
    )
endif()

# Another pico macro which generates the uf2 file in addition to the elf
pico_add_extra_outputs(sleep)

add_custom_target(flash_sleep picotool load -f $<TARGET_FILE:sleep> DEPENDS sleep)



# This is the main binary. List your C files here.
add_executable(blink_delay
    blink_delay.c
    )

pico_set_program_name(blink_delay "test")
pico_set_program_version(blink_delay "0.1")

# Modify the below lines to enable/disable output over UART/USB.
# These are mutually exclusive, only set one.
pico_enable_stdio_uart(blink_delay 0)
pico_enable_stdio_usb(blink_delay 1)

# Add the libraries to the build
target_link_libraries(blink_delay PRIVATE
  pico_stdlib
  pico_multicore
  pico_async_context_freertos
  FreeRTOS-Kernel-Heap4

)

# The CYW43 is the Wifi/Bluetooth module. If the board is set to pico_w, this
# variable will be set and the wireless libraries added.
if(PICO_CYW43_SUPPORTED)
    # For led support on pico_w
    target_link_libraries(blink_delay PRIVATE
        pico_cyw43_arch_none
    )
endif()

# Another pico macro which generates the uf2 file in addition to the elf
pico_add_extra_outputs(blink_delay)

add_custom_target(flash_blink_delay picotool load -f $<TARGET_FILE:blink_delay> DEPENDS blink_delay)





# This is the main binary. List your C files here.
add_executable(loop
    loop.c
    )

pico_set_program_name(loop "test")
pico_set_program_version(loop "0.1")

# Modify the below lines to enable/disable output over UART/USB.
# These are mutually exclusive, only set one.
pico_enable_stdio_uart(loop 0)
pico_enable_stdio_usb(loop 1)

# Add the libraries to the build
target_link_libraries(loop PRIVATE
  pico_stdlib
  pico_multicore
  pico_async_context_freertos
  FreeRTOS-Kernel-Heap4

)

# The CYW43 is the Wifi/Bluetooth module. If the board is set to pico_w, this
# variable will be set and the wireless libraries added.
if(PICO_CYW43_SUPPORTED)
    # For led support on pico_w
    target_link_libraries(loop PRIVATE
        pico_cyw43_arch_none
    )
endif()

# Another pico macro which generates the uf2 file in addition to the elf
pico_add_extra_outputs(loop)

add_custom_target(flash_loop picotool load -f $<TARGET_FILE:loop> DEPENDS loop)

# This is the main binary. List your C files here.
add_executable(gpio_interrupt
    gpio_interrupt.c
    )

pico_set_program_name(gpio_interrupt "test")
pico_set_program_version(gpio_interrupt "0.1")

# Modify the below lines to enable/disable output over UART/USB.
# These are mutually exclusive, only set one.
pico_enable_stdio_uart(gpio_interrupt 0)
pico_enable_stdio_usb(gpio_interrupt 1)


# Add the libraries to the build
target_link_libraries(gpio_interrupt PRIVATE
  pico_stdlib
  pico_multicore
  pico_async_context_freertos
  FreeRTOS-Kernel-Heap4
  
)

# The CYW43 is the Wifi/Bluetooth module. If the board is set to pico_w, this
# variable will be set and the wireless libraries added.
if(PICO_CYW43_SUPPORTED)
    # For led support on pico_w
    target_link_libraries(gpio_interrupt PRIVATE
        pico_cyw43_arch_none
    )
endif()

# Another pico macro which generates the uf2 file in addition to the elf
pico_add_extra_outputs(gpio_interrupt)

add_custom_target(flash_gpio_interrupt picotool load -f $<TARGET_FILE:gpio_interrupt> DEPENDS gpio_interrupt)




# This is the main binary. List your C files here.
add_executable(hello_dormant_gpio
    hello_dormant_gpio.c
    )

pico_set_program_name(hello_dormant_gpio "test")
pico_set_program_version(hello_dormant_gpio "0.1")

# Modify the below lines to enable/disable output over UART/USB.
# These are mutually exclusive, only set one.
pico_enable_stdio_uart(hello_dormant_gpio 0)
pico_enable_stdio_usb(hello_dormant_gpio 1)

# Add the libraries to the build
target_link_libraries(hello_dormant_gpio PRIVATE
  pico_stdlib
  pico_multicore
  pico_async_context_freertos
  FreeRTOS-Kernel-Heap4
  hardware_sleep
)

# The CYW43 is the Wifi/Bluetooth module. If the board is set to pico_w, this
# variable will be set and the wireless libraries added.
if(PICO_CYW43_SUPPORTED)
    # For led support on pico_w
    target_link_libraries(hello_dormant_gpio PRIVATE
        pico_cyw43_arch_none
    )
endif()

# Another pico macro which generates the uf2 file in addition to the elf
pico_add_extra_outputs(hello_dormant_gpio)

add_custom_target(flash_hello_dormant_gpio picotool load -f $<TARGET_FILE:hello_dormant_gpio> DEPENDS hello_dormant_gpio)

# This is the main binary. List your C files here.
add_executable(hello_sleep_alarm
    hello_sleep_alarm.c
    )

pico_set_program_name(hello_sleep_alarm "test")
pico_set_program_version(hello_sleep_alarm "0.1")

# Modify the below lines to enable/disable output over UART/USB.
# These are mutually exclusive, only set one.
pico_enable_stdio_uart(hello_sleep_alarm 0)
pico_enable_stdio_usb(hello_sleep_alarm 1)

# Add the libraries to the build
target_link_libraries(hello_sleep_alarm PRIVATE
  pico_stdlib
  pico_multicore
  pico_async_context_freertos
  FreeRTOS-Kernel-Heap4
  hardware_sleep
)

# The CYW43 is the Wifi/Bluetooth module. If the board is set to pico_w, this
# variable will be set and the wireless libraries added.
if(PICO_CYW43_SUPPORTED)
    # For led support on pico_w
    target_link_libraries(hello_sleep_alarm PRIVATE
        pico_cyw43_arch_none
    )
endif()

# Another pico macro which generates the uf2 file in addition to the elf
pico_add_extra_outputs(hello_sleep_alarm)

add_custom_target(flash_hello_sleep_alarm picotool load -f $<TARGET_FILE:hello_sleep_alarm> DEPENDS hello_sleep_alarm)
