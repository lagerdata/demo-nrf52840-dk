add_library (ledctrl STATIC "")
target_sources(ledctrl PRIVATE ${CMAKE_CURRENT_LIST_DIR}/ledctrl.c)
target_include_directories(ledctrl PUBLIC ${CMAKE_CURRENT_LIST_DIR}/)

set(NRF52_SRC_DIR ${PROJECT_SOURCE_DIR}/nRF5_SDK_17)
target_include_directories(ledctrl PUBLIC ${NRF52_SRC_DIR}/modules/nrfx
  ${NRF52_SRC_DIR}/modules/nrfx/soc
  ${NRF52_SRC_DIR}/modules/nrfx/mdk
  ${NRF52_SRC_DIR}/modules/nrfx/hal
  ${NRF52_SRC_DIR}/modules/nrfx/drivers
  ${NRF52_SRC_DIR}/modules/nrfx/drivers/include
  ${NRF52_SRC_DIR}/modules/nrfx/drivers/src
  ${NRF52_SRC_DIR}/modules/nrfx/drivers/src/prs
  ${NRF52_SRC_DIR}/modules/nrfx/templates
  ${NRF52_SRC_DIR}/modules/nrfx/templates/NRF52840
  ${NRF52_SRC_DIR}/modules/nrfx/helpers)

target_include_directories(ledctrl PUBLIC ${NRF52_SRC_DIR}/components/toolchain/cmsis/include
  ${NRF52_SRC_DIR}/components/libraries/delay)

target_compile_options(ledctrl PRIVATE -mcpu=cortex-m4 -mthumb -mabi=aapcs -mfloat-abi=hard -mfpu=fpv4-sp-d16)
target_compile_options(ledctrl PRIVATE $<$<COMPILE_LANGUAGE:C>:-Wall -Werror -g -gstrict-dwarf -ffunction-sections -fdata-sections -fno-strict-aliasing -fno-builtin -fshort-enums>)
target_compile_options(ledctrl PRIVATE $<$<COMPILE_LANGUAGE:ASM>:-x assembler-with-cpp>)
target_compile_options(ledctrl PUBLIC "-ffile-prefix-map=${CMAKE_SOURCE_DIR}=.")


target_compile_definitions(ledctrl PRIVATE FLOAT_ABI_HARD NRF52840_XXAA)
target_compile_definitions(ledctrl PRIVATE $<$<COMPILE_LANGUAGE:ASM>:__HEAP_SIZE=8192 __STACK_SIZE=8192>)
