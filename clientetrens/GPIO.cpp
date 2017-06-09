//Definições da classe
#ifndef _GPIO_
#define _GPIO_

#include <iostream>
#include <map>

#include "Port.cpp"

#define ARQUIVO_TEMP "temp.txt" //Arquivo temporário

class GPIO{
	private:

		static GPIO *instance;

		std::map<PORTNUMBER, Port> map;

		GPIO(){
			map.insert(std::pair<PORTNUMBER, Port>(PORTNUMBER::P9_01,Port(PORTNAME::DGND,NOT_PSY_ADD,TYPEPORT::GND)));
			map.insert(std::pair<PORTNUMBER, Port>(PORTNUMBER::P9_02,Port(PORTNAME::DGND,NOT_PSY_ADD,TYPEPORT::GND)));
			map.insert(std::pair<PORTNUMBER, Port>(PORTNUMBER::P9_03,Port(PORTNAME::VDD_3V3,NOT_PSY_ADD,TYPEPORT::VDD)));
			map.insert(std::pair<PORTNUMBER, Port>(PORTNUMBER::P9_04,Port(PORTNAME::VDD_3V3,NOT_PSY_ADD,TYPEPORT::VDD)));
			map.insert(std::pair<PORTNUMBER, Port>(PORTNUMBER::P9_05,Port(PORTNAME::VDD_5V,NOT_PSY_ADD,TYPEPORT::VDD)));
			map.insert(std::pair<PORTNUMBER, Port>(PORTNUMBER::P9_06,Port(PORTNAME::VDD_5V,NOT_PSY_ADD,TYPEPORT::VDD)));
			map.insert(std::pair<PORTNUMBER, Port>(PORTNUMBER::P9_07,Port(PORTNAME::SYS_5V,NOT_PSY_ADD,TYPEPORT::VDD)));
			map.insert(std::pair<PORTNUMBER, Port>(PORTNUMBER::P9_08,Port(PORTNAME::SYS_5V,NOT_PSY_ADD,TYPEPORT::VDD)));
			map.insert(std::pair<PORTNUMBER, Port>(PORTNUMBER::P9_09,Port(PORTNAME::PWR_BUT,NOT_PSY_ADD,TYPEPORT::SYSTEM)));
			map.insert(std::pair<PORTNUMBER, Port>(PORTNUMBER::P9_10,Port(PORTNAME::SYS_RESETN,NOT_PSY_ADD,TYPEPORT::SYSTEM)));
			map.insert(std::pair<PORTNUMBER, Port>(PORTNUMBER::P9_11,Port(PORTNAME::GPIO_30,"gpio30",TYPEPORT::DIGITAL)));
			map.insert(std::pair<PORTNUMBER, Port>(PORTNUMBER::P9_12,Port(PORTNAME::GPIO_60,"gpio60",TYPEPORT::DIGITAL)));
			map.insert(std::pair<PORTNUMBER, Port>(PORTNUMBER::P9_13,Port(PORTNAME::GPIO_31,"gpio31",TYPEPORT::DIGITAL)));
			map.insert(std::pair<PORTNUMBER, Port>(PORTNUMBER::P9_14,Port(PORTNAME::GPIO_50,"gpio50",TYPEPORT::DIGITAL)));
			map.insert(std::pair<PORTNUMBER, Port>(PORTNUMBER::P9_15,Port(PORTNAME::GPIO_48,"gpio48",TYPEPORT::DIGITAL)));
			map.insert(std::pair<PORTNUMBER, Port>(PORTNUMBER::P9_16,Port(PORTNAME::GPIO_51,"gpio51",TYPEPORT::DIGITAL)));
			map.insert(std::pair<PORTNUMBER, Port>(PORTNUMBER::P9_17,Port(PORTNAME::GPIO_5,"gpio5",TYPEPORT::DIGITAL)));
			map.insert(std::pair<PORTNUMBER, Port>(PORTNUMBER::P9_18,Port(PORTNAME::GPIO_4,"gpio4",TYPEPORT::DIGITAL)));
			map.insert(std::pair<PORTNUMBER, Port>(PORTNUMBER::P9_19,Port(PORTNAME::C2_SCL,NOT_PSY_ADD,TYPEPORT::SYSTEM)));
			map.insert(std::pair<PORTNUMBER, Port>(PORTNUMBER::P9_20,Port(PORTNAME::C2_SDA,NOT_PSY_ADD,TYPEPORT::SYSTEM)));
			map.insert(std::pair<PORTNUMBER, Port>(PORTNUMBER::P9_21,Port(PORTNAME::GPIO_3,"gpio3",TYPEPORT::DIGITAL)));
			map.insert(std::pair<PORTNUMBER, Port>(PORTNUMBER::P9_22,Port(PORTNAME::GPIO_2,"gpio2",TYPEPORT::DIGITAL)));
			map.insert(std::pair<PORTNUMBER, Port>(PORTNUMBER::P9_23,Port(PORTNAME::GPIO_49,"gpio49",TYPEPORT::DIGITAL)));
			map.insert(std::pair<PORTNUMBER, Port>(PORTNUMBER::P9_24,Port(PORTNAME::GPIO_15,"gpio15",TYPEPORT::DIGITAL)));
			map.insert(std::pair<PORTNUMBER, Port>(PORTNUMBER::P9_25,Port(PORTNAME::GPIO_117,"gpio117",TYPEPORT::DIGITAL)));
			map.insert(std::pair<PORTNUMBER, Port>(PORTNUMBER::P9_26,Port(PORTNAME::GPIO_14,"gpio14",TYPEPORT::DIGITAL)));
			map.insert(std::pair<PORTNUMBER, Port>(PORTNUMBER::P9_27,Port(PORTNAME::GPIO_115,"gpio115",TYPEPORT::DIGITAL)));
			map.insert(std::pair<PORTNUMBER, Port>(PORTNUMBER::P9_28,Port(PORTNAME::GPIO_113,"gpio113",TYPEPORT::DIGITAL)));
			map.insert(std::pair<PORTNUMBER, Port>(PORTNUMBER::P9_29,Port(PORTNAME::GPIO_111,"gpio111",TYPEPORT::DIGITAL)));
			map.insert(std::pair<PORTNUMBER, Port>(PORTNUMBER::P9_30,Port(PORTNAME::GPIO_112,"gpio112",TYPEPORT::DIGITAL)));
			map.insert(std::pair<PORTNUMBER, Port>(PORTNUMBER::P9_31,Port(PORTNAME::GPIO_110,"gpio110",TYPEPORT::DIGITAL)));
			map.insert(std::pair<PORTNUMBER, Port>(PORTNUMBER::P9_32,Port(PORTNAME::VDD_ADC,NOT_PSY_ADD,TYPEPORT::VDD)));
			map.insert(std::pair<PORTNUMBER, Port>(PORTNUMBER::P9_33,Port(PORTNAME::AIN4,"in_voltage4_raw",TYPEPORT::ANALOGIC)));
			map.insert(std::pair<PORTNUMBER, Port>(PORTNUMBER::P9_34,Port(PORTNAME::GNDA_ADC,NOT_PSY_ADD,TYPEPORT::GND)));
			map.insert(std::pair<PORTNUMBER, Port>(PORTNUMBER::P9_35,Port(PORTNAME::AIN6,"in_voltage6_raw",TYPEPORT::ANALOGIC)));
			map.insert(std::pair<PORTNUMBER, Port>(PORTNUMBER::P9_36,Port(PORTNAME::AIN5,"in_voltage5_raw",TYPEPORT::ANALOGIC)));
			map.insert(std::pair<PORTNUMBER, Port>(PORTNUMBER::P9_37,Port(PORTNAME::AIN2,"in_voltage2_raw",TYPEPORT::ANALOGIC)));
			map.insert(std::pair<PORTNUMBER, Port>(PORTNUMBER::P9_38,Port(PORTNAME::AIN3,"in_voltage3_raw",TYPEPORT::ANALOGIC)));
			map.insert(std::pair<PORTNUMBER, Port>(PORTNUMBER::P9_39,Port(PORTNAME::AIN0,"in_voltage0_raw",TYPEPORT::ANALOGIC)));
			map.insert(std::pair<PORTNUMBER, Port>(PORTNUMBER::P9_40,Port(PORTNAME::AIN1,"in_voltage1_raw",TYPEPORT::ANALOGIC)));
			map.insert(std::pair<PORTNUMBER, Port>(PORTNUMBER::P9_41,Port(PORTNAME::GPIO_20,"gpio20",TYPEPORT::DIGITAL)));
			map.insert(std::pair<PORTNUMBER, Port>(PORTNUMBER::P9_42,Port(PORTNAME::GPIO_7,"gpio7",TYPEPORT::DIGITAL)));
			map.insert(std::pair<PORTNUMBER, Port>(PORTNUMBER::P9_43,Port(PORTNAME::DGND,NOT_PSY_ADD,TYPEPORT::GND)));
			map.insert(std::pair<PORTNUMBER, Port>(PORTNUMBER::P9_44,Port(PORTNAME::DGND,NOT_PSY_ADD,TYPEPORT::GND)));
			map.insert(std::pair<PORTNUMBER, Port>(PORTNUMBER::P9_45,Port(PORTNAME::DGND,NOT_PSY_ADD,TYPEPORT::GND)));
			map.insert(std::pair<PORTNUMBER, Port>(PORTNUMBER::P9_46,Port(PORTNAME::DGND,NOT_PSY_ADD,TYPEPORT::GND)));

		}

		static GPIO& getInstance(){
			if(!instance) instance = new GPIO();
			return *instance;
		}

		static void errorPPort(){
			std::cerr << "this port is not allowed GPIO" << std::endl;
			exit(EXIT_FAILURE);
		}
		
		static void errorTPort(){
			std::cerr << "this type port is incorrect" << std::endl;
			exit(EXIT_FAILURE);
		}
		

		static void errorUDirection(PORTNUMBER pNumber){
			std::cerr << "Not defined direction for port " << portNumberToString(pNumber) << std::endl;
			exit(EXIT_FAILURE);
		}

		static void errorWDirection(PORTNUMBER pNumber){
			std::cerr << "Wrong direction for port " << portNumberToString(pNumber) << std::endl;
			exit(EXIT_FAILURE);
		}

		static void errorUValue(){
			std::cerr << "Value not allowed " << std::endl;
			exit(EXIT_FAILURE);
		}

		static bool actionValidation(PORTNUMBER pNumber){
			if(GPIO::getInstance().map[pNumber].getPhysicalAddress()==NOT_PSY_ADD){
				GPIO::errorPPort();
				return false;
			}else{
				if(GPIO::getInstance().map[pNumber].getDirection()==DIRECTION::NDDEF){
					errorUDirection(pNumber);
					return false;
				}else{
					return true;
				}
			}		
		}

	public:
		static DIRECTION getDirection(PORTNUMBER pNumber){

			if(actionValidation(pNumber)){
				return GPIO::getInstance().map[pNumber].getDirection();
			}else{
				return DIRECTION::NDDEF;
			}			
		}		
		
		static void setup(PORTNUMBER pNumber){
			if(GPIO::getInstance().map[pNumber].getTypePort()==TYPEPORT::ANALOGIC){
				GPIO::getInstance().map[pNumber].setDirection(DIRECTION::IN);
			}else{
				errorTPort();			
			}		
		} 

		static void setup(PORTNUMBER pNumber, DIRECTION direction){
			
			if(GPIO::getInstance().map[pNumber].getTypePort()==TYPEPORT::DIGITAL){						
						
				if(direction==DIRECTION::NDDEF){
					errorUDirection(pNumber);
				}else{
					GPIO::getInstance().map[pNumber].setDirection(direction);
				}
			}else{
				errorTPort();
			}
		}

		static int input(PORTNUMBER pNumber){
			
			if(actionValidation(pNumber)){
				
				if(GPIO::getInstance().map[pNumber].getTypePort()==TYPEPORT::DIGITAL){

					DIRECTION v = GPIO::getInstance().map[pNumber].getDirection();

					if(v != DIRECTION::NDDEF){
						if(GPIO::getInstance().map[pNumber].getDirection()==DIRECTION::OUT){
							errorWDirection(pNumber);
						}else{
							return GPIO::getInstance().map[pNumber].getValue();
						}
					}else{
						errorUDirection(pNumber);
					}
				}else{
					if(GPIO::getInstance().map[pNumber].getTypePort()==TYPEPORT::ANALOGIC){
						return GPIO::getInstance().map[pNumber].getAnalogicValue();
					}				
				}
			
			}
			
			return VALUE::NVDEF;
		}

		static void output(PORTNUMBER pNumber, VALUE value){
			if(actionValidation(pNumber) && GPIO::getInstance().map[pNumber].getTypePort()==TYPEPORT::DIGITAL){
				if(value==VALUE::NVDEF){
					errorUValue();
				}else{
					if(GPIO::getInstance().map[pNumber].getDirection()==DIRECTION::IN){
						errorWDirection(pNumber);
					}else{
						GPIO::getInstance().map[pNumber].setValue(value);
					}
				}
			}
		}
};	

//Definindo o ponteiro a ser alocado no programa principal
GPIO *GPIO::instance;

#endif
