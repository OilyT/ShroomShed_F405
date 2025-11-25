cmake_minimum_required(VERSION 3.22)

#
# This file is generated only once,
# and is not re-generated if converter is called multiple times.
#
# User is free to modify the file as much as necessary
#

# Setup compiler settings
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)


# Define the build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif()

# Set the project name
set(CMAKE_PROJECT_NAME ShroomShed_F405)

# Enable compile command to ease indexing with e.g. clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

# Core project settings
project(${CMAKE_PROJECT_NAME})
message("Build type: " ${CMAKE_BUILD_TYPE})

# Enable CMake support for ASM and C languages
enable_language(C ASM)

# Create an executable object type
add_executable(${CMAKE_PROJECT_NAME})

# Add STM32CubeMX generated sources
add_subdirectory(cmake/stm32cubemx)

# Add LVGL library
add_subdirectory(lib/lvgl)

# Create ST7735 library
file(GLOB ST7735_SOURCES "lib/ST7735_SPI_STM32_HAL/Src/*.c")
add_library(st7735 STATIC ${ST7735_SOURCES})
target_include_directories(st7735 PUBLIC 
    lib/ST7735_SPI_STM32_HAL/Inc
)
# Link ST7735 with stm32cubemx to get access to HAL headers
target_link_libraries(st7735 PRIVATE stm32cubemx)

# Create EEZ UI library
file(GLOB EEZ_UI_SOURCES "EEZ/ShroomShed_F405/src/ui/*.c")
add_library(eez_ui STATIC ${EEZ_UI_SOURCES})
target_include_directories(eez_ui PUBLIC 
    EEZ/ShroomShed_F405/src/ui
    Core/Inc    
)
target_include_directories(eez_ui PRIVATE
    lib/lvgl
    lib/lvgl/src
)


# Link EEZ UI with LVGL and stm32cubemx
target_link_libraries(eez_ui PUBLIC lvgl PRIVATE stm32cubemx)

# Create SHT31 library
file(GLOB SHT31_SOURCES "lib/sht31/src/*.c")
add_library(sht31 STATIC ${SHT31_SOURCES})
target_include_directories(sht31 PUBLIC 
    lib/sht31/src
)
# Link SHT31 with stm32cubemx
target_link_libraries(sht31 PRIVATE stm32cubemx)

# Create USB Device library
file(GLOB USB_DEVICE_SOURCES "USB_DEVICE/App/*.c" "USB_DEVICE/Target/*.c")
add_library(usb_device STATIC ${USB_DEVICE_SOURCES})
target_include_directories(usb_device PUBLIC
    USB_DEVICE/App
    USB_DEVICE/Target
)
# Link USB Device with stm32cubemx
target_link_libraries(usb_device PRIVATE stm32cubemx)

# Add sources to executable
target_sources(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user sources here
    Core/Src/display_manager.c
    Core/Src/sensors.c
    Core/Src/vars.c
)

# Add include paths
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user defined include paths
    lib/lvgl
    lib/lvgl/src
)

# Add project symbols (macros)
target_compile_definitions(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user defined symbols
)

# Remove wrong libob.a library dependency when using cpp files
list(REMOVE_ITEM CMAKE_C_IMPLICIT_LINK_LIBRARIES ob)

# Add linked libraries
target_link_libraries(${CMAKE_PROJECT_NAME}
    stm32cubemx
    # Add user defined libraries
    lvgl
    st7735
    eez_ui
    sht31
    usb_device
)
