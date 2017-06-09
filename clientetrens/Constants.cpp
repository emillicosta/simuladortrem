#ifndef _Constants_
#define _Constants_

#include <stdlib.h>
#include <string>
#include <iostream>

#define NOT_PSY_ADD "nPA"

enum TYPEPORT{
	VDD,
	DIGITAL,
	ANALOGIC,
	GND,
	SYSTEM,
};

enum PORTNAME {
	DGND,
	VDD_3V3,
	VDD_5V,
	SYS_5V,
	PWR_BUT,
	SYS_RESETN,
	GPIO_30,
	GPIO_60,
	GPIO_31,
	GPIO_50,
	GPIO_48,
	GPIO_51,
	GPIO_5,
	GPIO_4,
	C2_SCL,
	C2_SDA,
	GPIO_3,
	GPIO_2,
	GPIO_49,
	GPIO_15,
	GPIO_117,
	GPIO_14,
	GPIO_115,
	GPIO_113,
	GPIO_111,
	GPIO_112,
	GPIO_110,
	VDD_ADC,
	AIN4,
	GNDA_ADC,
	AIN6,
	AIN5,
	AIN2,
	AIN3,
	AIN0,
	AIN1,
	GPIO_20,
	GPIO_7,
	GPIO_38,
	GPIO_39,
	GPIO_34,
	GPIO_35,
	GPIO_66,
	GPIO_67,
	GPIO_69,
	GPIO_68,
	GPIO_45,
	GPIO_44,
	GPIO_23,
	GPIO_26,
	GPIO_47,
	GPIO_46,
	GPIO_27,
	GPIO_65,
	GPIO_22,
	GPIO_63,
	GPIO_62,
	GPIO_37,
	GPIO_36,
	GPIO_33,
	GPIO_32,
	GPIO_61,
	GPIO_86,
	GPIO_88,
	GPIO_87,
	GPIO_89,
	GPIO_10,
	GPIO_11,
	GPIO_9,
	GPIO_81,
	GPIO_8,
	GPIO_80,
	GPIO_78,
	GPIO_79,
	GPIO_76,
	GPIO_77,
	GPIO_74,
	GPIO_75,
	GPIO_72,
	GPIO_73,
	GPIO_70,
	GPIO_71,
};

std::string portNameToString(PORTNAME pName){

	switch(pName){
		case DGND:
			return "DGND";
		break;
		case VDD_3V3:
			return "VDD_3V3";
		break;
		case VDD_5V:
			return "VDD_5V";
		break;
		case SYS_5V:
			return "SYS_5V";
		break;
		case PWR_BUT:
			return "PWR_BUT";
		break;
		case SYS_RESETN:
			return "SYS_RESETN";
		break;
		case GPIO_30:
			return "GPIO_30";
		break;
		case GPIO_60:
			return "GPIO_60";
		break;
		case GPIO_31:
			return "GPIO_31";
		break;
		case GPIO_50:
			return "GPIO_50";
		break;
		case GPIO_48:
			return "GPIO_48";
		break;
		case GPIO_51:
			return "GPIO_51";
		break;
		case GPIO_5:
			return "GPIO_5";
		break;
		case GPIO_4:
			return "GPIO_4";
		break;
		case C2_SCL:
			return "C2_SCL";
		break;
		case C2_SDA:
			return "C2_SDA";
		break;
		case GPIO_3:
			return "GPIO_3";
		break;
		case GPIO_2:
			return "CPIO_2";
		break;
		case GPIO_49:
			return "GPIO_49";
		break;
		case GPIO_15:
			return "GPIO_15";
		break;
		case GPIO_117:
			return "GPIO_117";
		break;
		case GPIO_14:
			return "GPIO_14";
		break;
		case GPIO_115:
			return "GPIO_115";
		break;
		case GPIO_113:
			return "GPIO_113";
		break;
		case GPIO_111:
			return "GPIO_111";
		break;
		case GPIO_112:
			return "GPIO_112";
		break;
		case GPIO_110:
			return "GPIO_110";
		break;
		case VDD_ADC:
			return "VDD_ADC";
		break;
		case AIN4:
			return "AIN4";
		break;
		case GNDA_ADC:
			return "GNDA_ADC";
		break;
		case AIN6:
			return "AIN6";
		break;
		case AIN5:
			return "AIN5";
		break;
		case AIN2:
			return "AIN2";
		break;
		case AIN3:
			return "AIN3";
		break;
		case AIN0:
			return "AIN0";
		break;
		case AIN1:
			return "AIN1";
		break;
		case GPIO_20:
			return "GPIO_20";
		break;
		case GPIO_7:
			return "GPIO_7";
		break;
		case GPIO_38:
			return "GPIO_38";
		break;
		case GPIO_39:
			return "GPIO_39";
		break;
		case GPIO_34:
			return "GPIO_34";
		break;
		case GPIO_35:
			return "GPIO_35";
		break;
		case GPIO_66:
			return "GPIO_66";
		break;
		case GPIO_67:
			return "GPIO_67";
		break;
		case GPIO_69:
			return "GPIO_69";
		break;
		case GPIO_68:
			return "GPIO_68";
		break;
		case GPIO_45:
			return "GPIO_45";
		break;
		case GPIO_44:
			return "GPIO_44";
		break;
		case GPIO_23:
			return "GPIO_23";
		break;
		case GPIO_26:
			return "GPIO_26";
		break;
		case GPIO_47:
			return "GPIO_47";
		break;
		case GPIO_46:
			return "GPIO_46";
		break;
		case GPIO_27:
			return "GPIO_27";
		break;
		case GPIO_65:
			return "GPIO_65";
		break;
		case GPIO_22:
			return "GPIO_22";
		break;
		case GPIO_63:
			return "GPIO_63";
		break;
		case GPIO_62:
			return "GPIO_62";
		break;
		case GPIO_37:
			return "GPIO_37";
		break;
		case GPIO_36:
			return "GPIO_36";
		break;
		case GPIO_33:
			return "GPIO_33";
		break;
		case GPIO_32:
			return "GPIO_32";
		break;
		case GPIO_61:
			return "GPIO_61";
		break;
		case GPIO_86:
			return "GPIO_86";
		break;
		case GPIO_88:
			return "GPIO_88";
		break;
		case GPIO_87:
			return "GPIO_87";
		break;
		case GPIO_89:
			return "GPIO_89";
		break;
		case GPIO_10:
			return "GPIO_10";
		break;
		case GPIO_11:
			return "GPIO_11";
		break;
		case GPIO_9:
			return "GPIO_9";
		break;
		case GPIO_81:
			return "GPIO_81";
		break;
		case GPIO_8:
			return "GPIO_8";
		break;
		case GPIO_80:
			return "GPIO_80";
		break;
		case GPIO_78:
			return "GPIO_78";
		break;
		case GPIO_79:
			return "GPIO_79";
		break;
		case GPIO_76:
			return "GPIO_76";
		break;
		case GPIO_77:
			return "GPIO_77";
		break;
		case GPIO_74:
			return "GPIO_74";
		break;
		case GPIO_75:
			return "GPIO_75";
		break;
		case GPIO_72:
			return "GPIO_72";
		break;
		case GPIO_73:
			return "GPIO_73";
		break;
		case GPIO_70:
			return "GPIO_70";
		break;
		case GPIO_71:
			return "GPIO_71";
		break;
		default :
			std::cerr << "Number of port not found" << std::endl;	
			exit(-1);
	}		
}
enum PORTNUMBER{
	//P8 ports
	P8_01,
	P8_02,
	P8_03,
	P8_04,
	P8_05,
	P8_06,
	P8_07,
	P8_08,
	P8_09,
	P8_10,
	P8_11,
	P8_12,
	P8_13,
	P8_14,
	P8_15,
	P8_16,
	P8_17,
	P8_18,
	P8_19,
	P8_20,
	P8_21,
	P8_22,
	P8_23,
	P8_24,
	P8_25,
	P8_26,
	P8_27,
	P8_28,
	P8_29,
	P8_30,
	P8_31,
	P8_32,
	P8_33,
	P8_34,
	P8_35,
	P8_36,
	P8_37,
	P8_38,
	P8_39,
	P8_40,
	P8_41,
	P8_42,
	P8_43,
	P8_44,
	P8_45,
	P8_46,
	//P9 Ports
	P9_01,
	P9_02,
	P9_03,
	P9_04,
	P9_05,
	P9_06,
	P9_07,
	P9_08,
	P9_09,
	P9_10,
	P9_11,
	P9_12,
	P9_13,
	P9_14,
	P9_15,
	P9_16,
	P9_17,
	P9_18,
	P9_19,
	P9_20,
	P9_21,
	P9_22,
	P9_23,
	P9_24,
	P9_25,
	P9_26,
	P9_27,
	P9_28,
	P9_29,
	P9_30,
	P9_31,
	P9_32,
	P9_33,
	P9_34,
	P9_35,
	P9_36,
	P9_37,
	P9_38,
	P9_39,
	P9_40,
	P9_41,
	P9_42,
	P9_43,
	P9_44,
	P9_45,
	P9_46,
};

std::string portNumberToString(PORTNUMBER pNumber){

	switch(pNumber){
		case P8_01:
			return "P9_01";
		break;
		case P8_02:
			return "P9_02";
		break;
		case P8_03:
			return "P9_03";
		break; 
		case P8_04:
			return "P9_04";
		break;
		case P8_05:
			return "P9_05";
		break;
		case P8_06:
			return "P9_06";
		break;
		case P8_07:
			return "P9_07";
		break;
		case P8_08:
			return "P9_08";
		break;
		case P8_09:
			return "P9_09";
		break;
		case P8_10:
			return "P9_10";
		break;
		case P8_11:
			return "P9_11";
		break;
		case P8_12:
			return "P9_12";
		break;
		case P8_13:
			return "P9_13";
		break;
		case P8_14:
			return "P9_14";
		break;
		case P8_15:
			return "P9_15";
		break;
		case P8_16:
			return "P9_16";
		break;
		case P8_17:
			return "P9_17";
		break;
		case P8_18:
			return "P9_18";
		break;
		case P8_19:
			return "P9_19";
		break;
		case P8_20:
			return "P9_20";
		break;
		case P8_21:
			return "P9_21";
		break;
		case P8_22:
			return "P9_22";
		break;
		case P8_23:
			return "P9_23";
		break;
		case P8_24:
			return "P9_24";
		break;
		case P8_25:
			return "P9_25";
		break;
		case P8_26:
			return "P9_26";
		break;
		case P8_27:
			return "P9_27";
		break;
		case P8_28:
			return "P9_28";
		break;
		case P8_29:
			return "P9_29";
		break;
		case P8_30:
			return "P9_30";
		break;
		case P8_31:
			return "P9_31";
		break;
		case P8_32:
			return "P9_32";
		break;
		case P8_33:
			return "P9_33";
		break;
		case P8_34:
			return "P9_34";
		break;
		case P8_35:
			return "P9_35";
		break;
		case P8_36:
			return "P9_36";
		break;
		case P8_37:
			return "P9_37";
		break;
		case P8_38:
			return "P9_38";
		break;
		case P8_39:
			return "P9_39";
		break;
		case P8_40:
			return "P9_40";
		break;
		case P8_41:
			return "P9_41";
		break;
		case P8_42:
			return "P9_42";
		break;
		case P8_43:
			return "P9_43";
		break;
		case P8_44:
			return "P9_44";
		break;
		case P8_45:
			return "P9_45";
		break;
		case P8_46:
			return "P9_46";
		break;
		//P9 ports
		case P9_01:
			return "P9_01";
		break;
		case P9_02:
			return "P9_02";
		break;
		case P9_03:
			return "P9_03";
		break; 
		case P9_04:
			return "P9_04";
		break;
		case P9_05:
			return "P9_05";
		break;
		case P9_06:
			return "P9_06";
		break;
		case P9_07:
			return "P9_07";
		break;
		case P9_08:
			return "P9_08";
		break;
		case P9_09:
			return "P9_09";
		break;
		case P9_10:
			return "P9_10";
		break;
		case P9_11:
			return "P9_11";
		break;
		case P9_12:
			return "P9_12";
		break;
		case P9_13:
			return "P9_13";
		break;
		case P9_14:
			return "P9_14";
		break;
		case P9_15:
			return "P9_15";
		break;
		case P9_16:
			return "P9_16";
		break;
		case P9_17:
			return "P9_17";
		break;
		case P9_18:
			return "P9_18";
		break;
		case P9_19:
			return "P9_19";
		break;
		case P9_20:
			return "P9_20";
		break;
		case P9_21:
			return "P9_21";
		break;
		case P9_22:
			return "P9_22";
		break;
		case P9_23:
			return "P9_23";
		break;
		case P9_24:
			return "P9_24";
		break;
		case P9_25:
			return "P9_25";
		break;
		case P9_26:
			return "P9_26";
		break;
		case P9_27:
			return "P9_27";
		break;
		case P9_28:
			return "P9_28";
		break;
		case P9_29:
			return "P9_29";
		break;
		case P9_30:
			return "P9_30";
		break;
		case P9_31:
			return "P9_31";
		break;
		case P9_32:
			return "P9_32";
		break;
		case P9_33:
			return "P9_33";
		break;
		case P9_34:
			return "P9_34";
		break;
		case P9_35:
			return "P9_35";
		break;
		case P9_36:
			return "P9_36";
		break;
		case P9_37:
			return "P9_37";
		break;
		case P9_38:
			return "P9_38";
		break;
		case P9_39:
			return "P9_39";
		break;
		case P9_40:
			return "P9_40";
		break;
		case P9_41:
			return "P9_41";
		break;
		case P9_42:
			return "P9_42";
		break;
		case P9_43:
			return "P9_43";
		break;
		case P9_44:
			return "P9_44";
		break;
		case P9_45:
			return "P9_45";
		break;
		case P9_46:
			return "P9_46";
		break;
		default:
			std::cerr << "Number of port not found" << std::endl;	
			exit(-1);
	}
}

enum VALUE
{
	LOW,
	HIGH,
	NVDEF,
};

enum DIRECTION {
	IN,
	OUT,
	NDDEF,
};

#endif