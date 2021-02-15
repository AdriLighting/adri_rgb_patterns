# adri_rgb_patterns

Gestion de playlists et patterns.
Initialement prévu pour fonctionner avec une lampe Rgb.

<pre>
Librairies
<details>
adri_rgb_patterns               = https://github.com/AdriLighting/adri_rgb_patterns
adri_timer                      = https://github.com/AdriLighting/adri_timer

ArduinoJson                     = https://github.com/bblanchon/ArduinoJson

framework                       = https://github.com/esp8266/Arduino/tree/master/libraries
LittleFS(esp8266)               = 

</details>
Dependency Graph
<details>
|-- [adri_rgb_patterns] 1.0.0
|   |-- [adri_timer] 1.0.0
|   |-- [ArduinoJson] 6.17.1
|   |-- [LittleFS(esp8266)] 0.1.0</details>
</pre>

<hr>

#### examples

adri_rgb_patterns_2
<details>
<pre>
platformio.ini
<details>
[env:nodemcuv2]
platform=espressif8266
board=nodemcuv2
framework=arduino
board_build.filesystem=littlefs
board_build.ldscript=eagle.flash.4m3m.ld
lib_extra_dirs= ${env.lib_extra_dirs}
upload_speed=921600
[platformio]
src_dir= ${env.src_dir}

</details>
</pre>
<pre>
Librairies
<details>
adri_rgb_patterns               = https://github.com/AdriLighting/adri_rgb_patterns
adri_timer                      = https://github.com/AdriLighting/adri_timer

ArduinoJson                     = https://github.com/bblanchon/ArduinoJson

framework                       = https://github.com/esp8266/Arduino/tree/master/libraries
LittleFS(esp8266)               = 

</details>
Dependency Graph
<details>
|-- [adri_rgb_patterns] 1.0.0
|   |-- [adri_timer] 1.0.0
|   |-- [ArduinoJson] 6.17.1
|   |-- [LittleFS(esp8266)] 0.1.0
|-- [LittleFS(esp8266)] 0.1.0</details>
</pre>

</details>
<hr>