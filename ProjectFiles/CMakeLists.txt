# Dies ist die CMakeLists.txt für Ihren Anwendungs-Code (main.c etc.).

# Erstellt das ausführbare Programm namens 'fusioncoreos'.
# Listet NUR die Quelldateien auf, die DIREKT zu Ihrer HAUPTANWENDUNG gehören.
# KEINE Quelldateien von Bibliotheken wie lcd_1602_i2c.c oder ssd1306_i2c.c hier auflisten!
add_executable(fusioncoreos
    main.c
    src/cpp/Blink.cpp
    src/cpp/blink_task_wrapper.cpp
    # Fügen Sie hier weitere .c/.cpp-Dateien hinzu, die Sie selbst für Ihre Anwendung geschrieben haben
    # Beispiel: my_app_logic.c
)
target_include_directories(fusioncoreos PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/cpp
)


# Verknüpfen Sie Ihr ausführbares Programm mit allen benötigten Bibliotheken.
target_link_libraries(fusioncoreos
    pico_stdlib           # Standard-Bibliothek des Pico SDK
    pico_binary_info      # Wichtig für die Board-Informationen und das Booten
    hardware_gpio         # Grundlegende GPIO-Funktionen
    hardware_i2c          # I2C-Hardware-Schnittstelle (wird von Ihren Treibern benötigt)
    freertos              # Das FreeRTOS-Kernel-Target (aus freertos/CMakeLists.txt)

    # Ihre benutzerdefinierten Treiber-Bibliotheken:
    # Verknüpfen Sie die von Ihnen definierten Bibliotheks-Targets.
    lcd_1602_i2c_lib      # Der Name des Targets aus librarys/lcd_1602_i2c/CMakeLists.txt
    ssd1306_i2c_lib       # Der Name des Targets aus librarys/ssd1306_i2c/CMakeLists.txt
    # Fügen Sie hier weitere von Ihnen erstellte Bibliotheks-Targets hinzu
)

# Diese Funktion des Pico SDK ist essentiell, um die notwendigen Ausgabedateien
# (wie .uf2) für den Raspberry Pi Pico zu generieren.
pico_add_extra_outputs(fusioncoreos)