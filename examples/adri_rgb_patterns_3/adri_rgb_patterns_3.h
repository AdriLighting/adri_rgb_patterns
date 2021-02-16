#ifndef ADRI_RGB_PATTERNS_3_H
	#define ADRI_RGB_PATTERNS_3_H

	#define ARRAY_SIZE(A) (sizeof(A) / sizeof((A)[0]))

	struct programmSettingList {
		const char * name;
		void (*getValue)(String & ret);
	};	

	struct chooseEffectList {
		const char 	* name;
	};	

	String ch_toString(char * c);
	String ch_toString(const char * c);
	
	void patterns_loop();
#endif // ADRI_RGB_PATTERNS_2_H


