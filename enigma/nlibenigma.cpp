#include<string.h>
#include"nlibenigma.h"

namespace nlib{
	namespace enigma{
		int Enigma::r_rotor[5][26]={
		{20,21,22,3,-4,-2,-1,8,13,16,-9,-7,-10,-3,-2,4,-9,6,0,-8,-3,-13,-9,-7,-10,-16},
		{0,8,13,-1,21,17,11,4,-3,-8,-7,-1,2,6,10,5,0,-11,-14,-6,-13,2,-10,-15,-3,-7},
		{19,-1,4,-2,11,-3,12,-4,8,-5,10,-6,9,0,11,-8,8,-9,5,-10,2,-10,-5,-13,-10,-13},
		{7,24,20,18,-4,12,13,6,3,-3,10,4,11,3,-12,-11,-7,-5,-17,-1,-10,-18,2,-9,-16,-20},
		{16,1,22,8,19,17,-2,6,-3,10,15,3,6,-1,7,-6,4,-14,-8,-13,-12,-21,-5,-8,-17,-24}
		};

		//27 refer to notch
		int Enigma::rotor[5][27]={
		{4,9,10,2,7,1,-3,9,13,16,3,8,2,9,10,-8,7,3,0,-4,-20,-13,-21,-6,-22,-16,17},
		{0,8,1,7,14,3,11,13,15,-8,1,-4,10,6,-2,-13,0,-11,7,-6,-5,3,-17,-2,-10,-21,5},
		{1,2,3,4,5,6,-4,8,9,10,13,10,13,0,10,-11,-8,5,-12,-19,-10,-9,-2,-5,-8,-11,22},
		{4,17,12,18,11,20,3,-7,16,7,10,-3,5,-6,9,-4,-3,-12,1,-13,-10,-18,-20,-11,-2,-24,10},
		{21,24,-1,14,2,3,13,17,12,6,8,-8,1,-6,-3,8,-16,5,-6,-10,-4,-7,-17,-19,-22,-15,0}
		};

		int Enigma::reflector[2][26]={
		{24,17,20,7,16,18,11,3,15,23,13,6,14,10,12,8,4,1,5,25,2,22,21,9,0,19},
		{5,21,15,9,8,0,14,24,4,3,17,25,23,22,6,2,19,10,20,16,18,1,13,12,7,11}
		};


		Enigma::Enigma(){
			clearPlugSettings();
			setRotorType(0,1,2);
			setRotorPosition('a','a','a');
			setReflectorType(0);
		}

		void Enigma::decode(const char *str,char *dst){
			unsigned int length = strlen(str);
			int i = 0;
			for(;i<length;i++){
				dst[i] = pressKey(str[i]);
			}
			dst[i]='\0';
		}

		void Enigma::clearPlugSettings(){
			for(int i=0;i<26;i++){
				plug_board[i] = i;
			}
		}

		void Enigma::setSinglePlug(char value1,char value2){
			int v1,v2;
			v1 = value1 - 'a';
			v2 = value2 - 'a';
			if(v1==plug_board[v1]&&v2==plug_board[v2]){
				plug_board[v1]=v2;
				plug_board[v2]=v1;
			}
		}

		void Enigma::setPlugSettings(char *plug_settings){
			for(int i=0;i<26;i++){
				plug_board[i]=plug_settings[i]-'a';
			}
		}

		void Enigma::setRotorType(int type1,int type2,int type3){
			rotor_type[0]=type1;
			rotor_type[1]=type2;
			rotor_type[2]=type3;
		}

		void Enigma::setRotorPosition(char position1,char position2,char position3){
			rotor_position[0]=position1-'a';
			rotor_position[1]=position2-'a';
			rotor_position[2]=position3-'a';
		}

		void Enigma::setReflectorType(int type){
			reflector_type = type;
		}

		void Enigma::turnRotor(){
			rotor_position[2]=(rotor_position[2]+1)%26;
			if(rotor_position[2]==rotor[rotor_type[2]][26]){
				rotor_position[1]=(rotor_position[1]+1)%26;
				if(rotor_position[1]==rotor[rotor_type[1]][26]){
					rotor_position[0]=(rotor_position[0]+1)%26;
				}
			}
		}

		void Enigma::turnRotorBack(){
			if(rotor_position[1]==rotor[rotor_type[1]][26]&&rotor_position[2]==rotor[rotor_type[2]][26]){
				rotor_position[0] = (rotor_position[0]+25)%26;
			}
			if(rotor_position[2]==rotor[rotor_type[2]][26]){
				rotor_position[1] = (rotor_position[1]+25)%26;
			}
			rotor_position[2] = (rotor_position[2]+25)%26;
		}

		char Enigma::pressKey(char letter){
			int c = letter -'a';
			turnRotor();
			c = plug_board[c];
			for(int i=2;i>=0;i--){
				int index = c + rotor_position[i];
				index %= 26;
				c+=rotor[rotor_type[i]][index];
				c+=26;
				c%=26;
			}
			c = reflector[reflector_type][c];
			for(int i=0;i<3;i++){
				int index = c + rotor_position[i];
				index %= 26;
				c+=r_rotor[rotor_type[i]][index];
				c+=26;
				c%=26;
			}
			c = plug_board[c];
			char res ='a';
			res+=c;
			return res;
		}
	}
}
