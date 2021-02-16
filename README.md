# adri_rgb_patterns

Gestion de playlists et patterns.

Initialement prévu pour fonctionner avec une lampe Rgb.

## Utilisation des patterns

Création d’une liste de pattern avec la structure : « chooseEffectList » sous forme de tableau.
  ```c++
    const char PROGMEM EX_pattern_1	[] = "pattern_1";
    PROGMEM chooseEffectList chooseEffect [] = { 
      {EX_pattern_1},
    };
  ```
Création des instances pour les class : « playlist_management » et « programme_loop »
  ```c++
    _playlist       = new playlist_management(); 
    _programme      = new programme_loop(); 
  ```  
  
Initialisation de la liste.
  - indiquer la taille de la list
      - void programme_loop::patternList_initialize(uint8_t maxCnt) 
  - ajout des patterns
    -coid programme_loop::patternList_item_add(String value)
      
          ```c++
          _programme->patternList_initialize(chooseEffectCnt);
          for (int j = 0; j < chooseEffectCnt; ++j) {
              _programme->patternList_item_add(ch_toString(chooseEffect[j].name));
          }
          ```
          

          
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

adri_rgb_patterns_3
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
adri_logger                     = https://github.com/AdriLighting/adri_logger
adri_tools_v2                   = https://github.com/AdriLighting/adri_tools_v2

ArduinoJson                     = https://github.com/bblanchon/ArduinoJson

framework                       = https://github.com/esp8266/Arduino/tree/master/libraries
LittleFS(esp8266)               = 
ESP8266WiFi                     = 

</details>
Dependency Graph
<details>
|-- [adri_rgb_patterns] 1.0.0
|   |-- [adri_timer] 1.0.0
|   |-- [ArduinoJson] 6.17.1
|   |-- [LittleFS(esp8266)] 0.1.0
|   |-- [adri_logger] 1.0.0
|   |   |-- [adri_tools_v2] 1.0.0
|   |   |   |-- [ESP8266WiFi] 1.0
|   |   |   |-- [LittleFS(esp8266)] 0.1.0
|   |   |-- [ESP8266WiFi] 1.0
|   |   |-- [LittleFS(esp8266)] 0.1.0
|   |-- [adri_tools_v2] 1.0.0
|   |   |-- [ESP8266WiFi] 1.0
|   |   |-- [LittleFS(esp8266)] 0.1.0
|-- [adri_logger] 1.0.0
|   |-- [adri_tools_v2] 1.0.0
|   |   |-- [ESP8266WiFi] 1.0
|   |   |-- [LittleFS(esp8266)] 0.1.0
|   |-- [ESP8266WiFi] 1.0
|   |-- [LittleFS(esp8266)] 0.1.0
|-- [adri_tools_v2] 1.0.0
|   |-- [ESP8266WiFi] 1.0
|   |-- [LittleFS(esp8266)] 0.1.0
|-- [LittleFS(esp8266)] 0.1.0</details>
</pre>

</details>
<hr>
