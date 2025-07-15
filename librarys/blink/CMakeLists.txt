# Definition einer statischen Bibliothek für den Blink-Treiber.
# Der Name 'blink_lib' ist das CMake-Target, mit dem andere Projekte verknüpfen.
add_library(blink_lib STATIC
    Blink.cpp
    blink_task_wrapper.cpp
)

# Setzt das aktuelle Verzeichnis als öffentliches Include-Verzeichnis.
# Das bedeutet, jedes Projekt, das 'blink_lib' verknüpft,
# findet automatisch die Header-Dateien in diesem Ordner.
target_include_directories(blink_lib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# Listet die Abhängigkeiten der Blink-Bibliothek auf.
# Dies stellt sicher, dass die benötigten Pico SDK-Komponenten kompiliert und verknüpft werden.
target_link_libraries(blink_lib
    pico_stdlib
    pico_binary_info
    hardware_i2c
    hardware_gpio
)