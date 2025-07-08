add_executable(fusioncoreos
        main.c
        lcd_1602_i2c.c
        ssd1306_i2c.c
)

target_link_libraries(fusioncoreos pico_stdlib pico_binary_info hardware_gpio hardware_i2c freertos)
pico_add_extra_outputs(fusioncoreos)
