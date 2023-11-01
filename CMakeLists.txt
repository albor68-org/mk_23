<<<<<<< HEAD
cmake_minimum_required(VERSION 3.20)
set(CMAKE_TOOLCHAIN_FILE  arm-none-eabi-gcc.cmake )




project(mk_23 LANGUAGE C CXX ASM)
set(DEVICE stm32f303vc)

include(libopencm3)
add_executable($PROJECT_NAME 
   src/main.cpp 
   )
target_link_libraries(${PROJECT_NAME}
     libopencm3 )

set_target_properties(${PROJECT_NAME }
          PROPITIES 
          CXX_STANDARD 17
          CXX_STANDARD_REQUIRED YES 
          CXX_EXTENSIONS NO
 

)


=======
#================================================================================
cmake_minimum_required(VERSION 3.20)
set(CMAKE_TOOLCHAIN_FILE cmake/arm-none-eabi-gcc.cmake)


#================================================================================
project(mk_23 LANGUAGES CXX C ASM)
set(DEVICE stm32f303vc)

include(libopencm3)


#================================================================================
add_executable(${PROJECT_NAME}
     src/main.cpp
)

target_link_libraries(${PROJECT_NAME}
     PRIVATE libopencm3
)

set_target_properties(${PROJECT_NAME}
     PROPERTIES
     CXX_STANDARD 17
     CXX_STANDARD_REQUIRED YES
     CXX_EXTENSIONS NO
)


#================================================================================
>>>>>>> edf094cbded313720a30ffb72c3ba40f1f0a0d84
set(PROG stlink)
string(CONCAT PROG_TARGET ${LOCM3_DEVICE_SERIE} x)

include(oocd_flash_script)

<<<<<<< HEAD
install(CODE ${OOCD_FLASH_SCRIPT})
=======
install(CODE ${OOCD_FLASH_SCRIPT})

>>>>>>> edf094cbded313720a30ffb72c3ba40f1f0a0d84
