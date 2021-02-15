#include <adri_rgb_patterns.h>
#include <LittleFS.h>

#include "adri_rgb_patterns_2.h"

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

programme_loop          * _programme;
playlist_management     * _playlist;

const char PROGMEM settingPatternLoop_pos			[] = "pos";
const char PROGMEM settingPatternLoop_posMin		[] = "posMin";
const char PROGMEM settingPatternLoop_posMax		[] = "posMax";
const char PROGMEM settingPatternLoop_delay			[] = "delay";
const char PROGMEM settingPatternLoop_delayCurrent 	[] = "delayCurrent";
const char PROGMEM settingPatternLoop_delayManual	[] = "delayManual";
const char PROGMEM settingPatternLoop_play			[] = "play";
const char PROGMEM settingPatternLoop_playRnd		[] = "random";
const char PROGMEM settingPatternLoop_currentName 	[] = "currentName";
void setting_patternLoop_pos_get 			(String & ret){uint8_t 	value;programmeLoop_instance()->patternLoop_pos_get(value);			ret = String(value);}
void setting_patternLoop_posMin_get 		(String & ret){uint8_t 	value;programmeLoop_instance()->patternLoop_posMin_get(value);		ret = String(value);}
void setting_patternLoop_posMax_get 		(String & ret){uint8_t	value;programmeLoop_instance()->patternLoop_posMax_get(value);		ret = String(value);}
void setting_patternLoop_delay_get 			(String & ret){uint32_t value;programmeLoop_instance()->patternLoop_delay_get(value);		ret = String(value);}
void setting_patternLoop_delayCurrent_get 	(String & ret){uint32_t value;programmeLoop_instance()->patternLoop_delayCurrent_get(value);ret = String(value);}
void setting_patternLoop_delayManual_get 	(String & ret){boolean 	value;programmeLoop_instance()->patternLoop_delayManual_get(value);	ret = String(value);}
void setting_patternLoop_isPlaying 			(String & ret){boolean 	value = programmeLoop_instance()->patternLoop_isPlaying();			ret = String(value);}
void setting_patternLoop_isRndPlaying 		(String & ret){boolean 	value = programmeLoop_instance()->patternLoop_isRndPlaying();		ret = String(value);}
void setting_patternLoop_currentName 		(String & ret){
	uint8_t value;
	programmeLoop_instance()->patternLoop_pos_get(value);
	programmeLoop_instance()->patternList_item_getName(ret, value);
}

PROGMEM programmSettingList  patternloopSettingList [] = { 
	{settingPatternLoop_pos, setting_patternLoop_pos_get}, 			
	{settingPatternLoop_posMin, setting_patternLoop_posMin_get}, 		
	{settingPatternLoop_posMax, setting_patternLoop_posMax_get}, 		
	{settingPatternLoop_delay, setting_patternLoop_delay_get}, 			
	{settingPatternLoop_delayCurrent, setting_patternLoop_delayCurrent_get}, 	
	{settingPatternLoop_delayManual, setting_patternLoop_delayManual_get}, 	
	{settingPatternLoop_play, setting_patternLoop_isPlaying}, 			
	{settingPatternLoop_playRnd, setting_patternLoop_isRndPlaying},		
	{settingPatternLoop_currentName, setting_patternLoop_currentName},		
};
uint8_t patternloopSettingListCount = ARRAY_SIZE(patternloopSettingList);


void setup()
{
	Serial.begin(115200);
	
	LittleFS.begin();

	_playlist       = new playlist_management(); 
	_programme      = new programme_loop(); 
	_programme->patternList_initialize(chooseEffectCnt);
	for (int j = 0; j < chooseEffectCnt; ++j) {
	    _programme->patternList_item_add(ch_toString(chooseEffect[j].name));
	}

	Serial.print(F("\n[programmSetting::patternLoopValue_print]\n"));
    for (int i = 0; i < patternloopSettingListCount; ++i)
    {
    	String value = "";
    	patternloopSettingList[i].getValue(value);
    	Serial.printf_P(PSTR("[%5d][%-20s][%-10s]\n"), i, patternloopSettingList[i].name, value.c_str());
    }	

    pInitHeap = ESP.getFreeHeap(); 	
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