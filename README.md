# AREA.old-boards-firmware


Repository containing all the repository for the different board in the AREA.old robot. All boards runs on STM32F042 MCU using HAL library, all documentation can be found easily on internet or in the header of each c file. Datasheet can be found here : https://www.st.com/resource/en/datasheet/stm32f042k6.pdf

To devellop on this board you need :
* **STM32CubeMX** : to create a project and generate code. (cf. to section Create a project)
* **Makefile** project generated by STM32CubeMX
* **VSCode** with C/C++, **stm-helper** extensions
* Open the folder where youre project is, then click on "UpdateWorspace" on the bottom left hand corner.
* Currently I didn't achieved to flash the board in VSCode, so I use **STM32CubeProgrammer** to flash the .bin file.

## Create a project
* Open **STM32CubeMX**, initialize the clock for 8MHz HSE and 48MHz clock speed. Initialise other IO and com (CANBus 1Mbps :look on other .mx file for time quantum)
* In Project manager in *Toolchain/IDE* choose Makefile, in code generator activate *Generate peripheral initialization as a pair of '.c/.h' files per peripheral*
