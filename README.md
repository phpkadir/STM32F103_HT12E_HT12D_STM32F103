
This library (with examples) is designed to be integrated in projects using HT12E/HT12D (315MHz and 433MHz) remote controllers or equivalent system.
You need 
2x stm32f103c8t6 bluepill
a st-link v2/ mini usb progrmmer on arduino ide..
HT12E rf encoder module with 433mhz or 315mhz or 868mhz ask transmitter module
HT12D rf encoder module with 433mhz or 315mhz or 868mhz ask receiver module
25 meters of rf remote capability with low power rf modules.
## How to connect your wireless remote receiver to your Stm32f103c8t6

|Wireless Remote (HT12D/HT12E)         |STM32  receiver                             |
|--------                              |--------                                    |
|VCC                                   |5V                                          |
|GND                                   |GND                                         |
|VT/TE                                 |PA8 (or any other interruptable digital pin)|
|D0                                    |PB12 (or any other digital pin)             |
|D1                                    |PB13 (or any other digital pin)             |
|D2                                    |PB14 (or any other digital pin)             |
|D3                                    |PB15 (or any other digital pin)             |

1. add arduino stm32duino by using file-> settings-->additional cards url>https://dan.drown.org/stm32duino/package_STM32duino_index.json click ok
2. click tools-->Card->Card menager->STM32F1xx/GD32F1xx boards install
3. compile and program your stm32 with RemoteControlWithInterrupt.ino 

