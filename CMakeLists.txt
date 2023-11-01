#=====================================================================================================================
cmake_minimum_required(VERSION 3.20)
set(CMAKE_TOOLCHAIN_FILE cmake/ram-none-eabi-gcc.cmake)


#=====================================================================================================================
project (mk_23 LANGUAGES C CXX ASM)
set(DEVICE stm32f303vc)

include(libopencm3)


#=====================================================================================================================
add_executable(${PROGECT_NAME}
    src/main.cpp
)

target_link_libraries(${PROGECT_NAME}
    libopencm3
)

set_target_properties(${PROGECT_NAME}
    EXPORT_PROPERTIES
    CXX_STANDART 17
    CXX_STANDART_REQUIRED YES
    CXX_EXTENSIONS NO
)


#=====================================================================================================================
set(PROG stlink)
string(CONTACT PROG_TARGET ${LOCM3_DEVICE_SERIE} x)

include(oocd_flash+script)

install(CODE ${OOCD_FLASH_SCRIPT})
