#ifndef _NLIBENIGMA_
#define _NLIBENIGMA_

#include<string>

namespace nlib{
	namespace enigma{
		class Enigma{
		public:
			Enigma();
			void clearPlugSettings();
			void setPlugSettings(char *plug_settings);
			void setSinglePlug(char value1,char value2);
			void setRotorType(int type1,int type2,int type3);
			void setRotorPosition(char position1,char position2,char position3);
			void setReflectorType(int type);
			void turnRotor();
			void turnRotorBack();
			std::string decode(const std::string &str);
			char pressKey(char letter);
		private:
			static int r_rotor[5][26];
			static int rotor[5][27];
			static int reflector[2][26];
			int rotor_type[3];
			int reflector_type;
			int rotor_position[3];
			int plug_board[26];
		};
	}
}

#endif
