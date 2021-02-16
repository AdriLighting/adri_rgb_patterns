#include <adri_rgb_patterns.h>
#include <LittleFS.h>
#include <adri_logger.h>
#include <adri_tools_v2.h>
#include "adri_rgb_patterns_3.h"

programme_loop          * _programme;
playlist_management     * _playlist;
adri_toolsV2 			* _tools;

const char PROGMEM EX_pattern_1	[] = "pattern_1";
const char PROGMEM EX_pattern_2	[] = "pattern_2";
const char PROGMEM EX_pattern_3	[] = "pattern_3";
const char PROGMEM EX_pattern_4	[] = "pattern_4";
const char PROGMEM EX_pattern_5	[] = "pattern_5";
PROGMEM chooseEffectList chooseEffect [] = { 
	{EX_pattern_1},
    {EX_pattern_2},
    {EX_pattern_3},
    {EX_pattern_4},
    {EX_pattern_5},
};
uint8_t chooseEffectCnt = ARRAY_SIZE(chooseEffect);


void setup()
{
	Serial.begin(115200);
  	for(unsigned long const serialBeginTime = millis(); !Serial && (millis() - serialBeginTime > 5000); ) { }
  	Serial.println(F("\n##################################################\n\n"));	

	LittleFS.begin();
	LittleFS.remove(COMPOSTIONS_FILENAME);
	LittleFS.remove("playlist/compoName_0.txt");
	LittleFS.remove("playlist/compoName_1.txt");

	_tools = new adri_toolsV2();

	_tools->heap_print();

	_playlist       = new playlist_management(); 
	_programme      = new programme_loop(); 

	_programme->patternList_initialize(chooseEffectCnt);
	for (int j = 0; j < chooseEffectCnt; ++j) {
	    _programme->patternList_item_add(ch_toString(chooseEffect[j].name));
	}

	_programme->patternLoop_delayCurrent_set(5000);

	_playlist->list_print();

	_playlist->list_pos(0);
	_playlist->item_restore();

	_playlist->item_toArray(255, ch_toString(chooseEffect[0].name), "adding pattern 1");
	_playlist->item_toArray(255, ch_toString(chooseEffect[2].name), "adding pattern 3");
	_playlist->item_toArray(255, ch_toString(chooseEffect[1].name), "adding pattern 2");
	_playlist->item_toArray(255, ch_toString(chooseEffect[3].name), "adding pattern 4");

	_playlist->print();
	_playlist->item_print();

	_playlist->list_pos(1);
	_playlist->item_restore();

	_playlist->item_toArray(255, ch_toString(chooseEffect[1].name), "adding pattern 2");
	_playlist->item_toArray(255, ch_toString(chooseEffect[3].name), "adding pattern 4");

	_playlist->print();
	_playlist->item_print();

	_playlist->list_statu_set(true);

	 pInitHeap = ESP.getFreeHeap(); 	
	_tools->heap_print();
}
void loop()
{
	if (_programme->patternLoop_isPlaying()) patterns_loop();
}

void patterns_loop(){
	static mod_pattern_loop pat_check 	= _programme->patternLoop_statuDefault();
	static String 			pat_name 	= "";
	static boolean 			playlist;

	_programme->loop(pat_check, pat_name, playlist); 		

	if (pat_check == _programme->patternLoop_statuNext()) {

		pat_check =  _programme->patternLoop_statuDefault();

		Serial.printf_P(PSTR("\n[patterns_loop]\n%s\n"), pat_name.c_str());

		#ifdef PATHEAPSTATS
			if (heap_pass>=2) patternList_instance()->heapStats_print();
		#else

			String ret;
			heapStatsPatternLoop_print(ret);

			Serial.print(ret);
			ADRI_LOG(-1, 2, 2, "","");

		#endif

	}	
}
String ch_toString(char * c){
    String result((char*)c);
    return result;
}
String ch_toString(const char * c){
       return String((const __FlashStringHelper*) c);
}