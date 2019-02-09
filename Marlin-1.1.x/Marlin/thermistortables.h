/**
 * Marlin 3D Printer Firmware
 * Copyright (C) 2016 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (C) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef THERMISTORTABLES_H_
#define THERMISTORTABLES_H_

#include "Marlin.h"
#include "macros.h"

#define OVERSAMPLENR 16
#define OV(N) int16_t((N)*(OVERSAMPLENR))

#define ANY_THERMISTOR_IS(n) (THERMISTORHEATER_0 == n || THERMISTORHEATER_1 == n || THERMISTORHEATER_2 == n || THERMISTORHEATER_3 == n || THERMISTORHEATER_4 == n || THERMISTORBED == n || THERMISTORCHAMBER == n)

// Pt1000 and Pt100 handling
//
// Rt=R0*(1+a*T+b*T*T) [for T>0]
// a=3.9083E-3, b=-5.775E-7
#define PtA 3.9083E-3
#define PtB -5.775E-7
#define PtRt(T,R0) ((R0)*(1.0+(PtA)*(T)+(PtB)*(T)*(T)))
#define PtAdVal(T,R0,Rup) (short)(1024/(Rup/PtRt(T,R0)+1))
#define PtLine(T,R0,Rup) { OV(PtAdVal(T,R0,Rup)), T },

#if ANY_THERMISTOR_IS(1) // 100k bed thermistor
  #include "thermistortable_1.h"
#endif
#if ANY_THERMISTOR_IS(2) // 200k bed thermistor
  #include "thermistortable_2.h"
#endif
#if ANY_THERMISTOR_IS(3) // mendel-parts
  #include "thermistortable_3.h"
#endif
#if ANY_THERMISTOR_IS(4) // 10k thermistor
  #include "thermistortable_4.h"
#endif
#if ANY_THERMISTOR_IS(5) // 100k ParCan thermistor (104GT-2)
  #include "thermistortable_5.h"
#endif
#if ANY_THERMISTOR_IS(501) // 100k Zonestar thermistor
  #include "thermistortable_501.h"
#endif
#if ANY_THERMISTOR_IS(6) // 100k Epcos thermistor
  #include "thermistortable_6.h"
#endif
#if ANY_THERMISTOR_IS(7) // 100k Honeywell 135-104LAG-J01
  #include "thermistortable_7.h"
#endif
#if ANY_THERMISTOR_IS(71) // 100k Honeywell 135-104LAF-J01
  #include "thermistortable_71.h"
#endif
#if ANY_THERMISTOR_IS(8) // 100k 0603 SMD Vishay NTCS0603E3104FXT (4.7k pullup)
  #include "thermistortable_8.h"
#endif
#if ANY_THERMISTOR_IS(9) // 100k GE Sensing AL03006-58.2K-97-G1 (4.7k pullup)
  #include "thermistortable_9.h"
#endif
#if ANY_THERMISTOR_IS(10) // 100k RS thermistor 198-961 (4.7k pullup)
  #include "thermistortable_10.h"
#endif
#if ANY_THERMISTOR_IS(11) // QU-BD silicone bed QWG-104F-3950 thermistor
  #include "thermistortable_11.h"
#endif
#if ANY_THERMISTOR_IS(13) // Hisens thermistor B25/50 =3950 +/-1%
  #include "thermistortable_13.h"
#endif
#if ANY_THERMISTOR_IS(15) // JGAurora A5 thermistor calibration
  #include "thermistortable_15.h"
#endif
#if ANY_THERMISTOR_IS(20) // PT100 with INA826 amp on Ultimaker v2.0 electronics
  #include "thermistortable_20.h"
#endif
#if ANY_THERMISTOR_IS(51) // 100k EPCOS (WITH 1kohm RESISTOR FOR PULLUP, R9 ON SANGUINOLOLU! NOT FOR 4.7kohm PULLUP! THIS IS NOT NORMAL!)
  #include "thermistortable_51.h"
#endif
#if ANY_THERMISTOR_IS(52) // 200k ATC Semitec 204GT-2 (WITH 1kohm RESISTOR FOR PULLUP, R9 ON SANGUINOLOLU! NOT FOR 4.7kohm PULLUP! THIS IS NOT NORMAL!)
  #include "thermistortable_52.h"
#endif
#if ANY_THERMISTOR_IS(55) // 100k ATC Semitec 104GT-2 (Used on ParCan) (WITH 1kohm RESISTOR FOR PULLUP, R9 ON SANGUINOLOLU! NOT FOR 4.7kohm PULLUP! THIS IS NOT NORMAL!)
  #include "thermistortable_55.h"
#endif
#if ANY_THERMISTOR_IS(60) // Maker's Tool Works Kapton Bed Thermistor
  #include "thermistortable_60.h"
#endif
#if ANY_THERMISTOR_IS(66) // DyzeDesign 500°C Thermistor
  #include "thermistortable_66.h"
#endif
#if ANY_THERMISTOR_IS(12) // 100k 0603 SMD Vishay NTCS0603E3104FXT (4.7k pullup) (calibrated for Makibox hot bed)
  #include "thermistortable_12.h"
#endif
#if ANY_THERMISTOR_IS(70) // bqh2 stock thermistor
  #include "thermistortable_70.h"
#endif
#if ANY_THERMISTOR_IS(75) // Many of the generic silicon heat pads use the MGB18-104F39050L32 Thermistor
  #include "thermistortable_75.h"
#endif
#if ANY_THERMISTOR_IS(110) // Pt100 with 1k0 pullup
  #include "thermistortable_110.h"
#endif
#if ANY_THERMISTOR_IS(147) // Pt100 with 4k7 pullup
  #include "thermistortable_147.h"
#endif
#if ANY_THERMISTOR_IS(1010) // Pt1000 with 1k0 pullup
  #include "thermistortable_1010.h"
#endif
#if ANY_THERMISTOR_IS(1047) // Pt1000 with 4k7 pullup
  #include "thermistortable_1047.h"
#endif
#if ANY_THERMISTOR_IS(998) // User-defined table 1
  #include "thermistortable_998.h"
#endif
#if ANY_THERMISTOR_IS(999) // User-defined table 2
  #include "thermistortable_999.h"
#endif

//Thermistor lookup table copied from the original Open3DEngineering Marlin firmware for the i3 Berlin
#if (THERMISTORHEATER_0 == 57) || (THERMISTORHEATER_1 == 57) || (THERMISTORHEATER_2 == 57) || (THERMISTORBED == 57) 
// Thermistor lookup table for Marlin
// ./createTemperatureLookupMarlin.py --rp=4680 --t1=21.4:106300 --t2=187:1023 --t3=248:281 --num-temps=72
// thermistor table for  extruder
const short temptable_57[][2] PROGMEM = {
  {159, 340},
  {172, 335},
  {186, 330},
  {202, 325},
  {219, 320},
  {238, 315},
  {258, 310},
  {281, 305},
  {306, 300},
  {333, 295},
  {363, 209},
  {396, 285},
  {432, 280},
  {472, 275},
  {516, 270},
  {565, 265},
  {618, 260},
  {677, 255},
  {742, 240},
  {814, 245},
  {894, 240},
  {981, 235},
  {1078, 230},
  {1184, 225},
  {1302, 220},
  {1432, 215},
  {1574, 210},
  {1732, 205},
  {1904, 200},
  {2094, 195},
  {2302, 190},
  {2530, 185},
  {2779, 180},
  {3050, 175},
  {3344, 170},
  {3662, 165},
  {4006, 160},
  {4375, 155},
  {4770, 150},
  {5190, 145},
  {5634, 140},
  {6101, 135},
  {6589, 130},
  {7095, 125},
  {7617, 120},
  {8149, 115},
  {8689, 110},
  {9230, 105},
  {9770, 100},
  {10302, 95},
  {11810, 90},
  {12271, 85},
  {12705, 80},
  {13111, 75},
  {13487, 70},
  {13833, 65},
  {14149, 60},
  {14435, 55},
  {14693, 50},
  {14923, 45},
  {15127, 40},
  {15308, 35},
  {15466, 30},
  {15604, 25},
  {15725, 20},
  {15828, 15},
  {15918, 10},
  {15994, 5},
  {16060, 0}
};

#endif

//Thermistor lookup table copied from the original Open3DEngineering Marlin firmware for the i3 Berlin
#if (THERMISTORHEATER_0 == 58) || (THERMISTORHEATER_1 == 58) || (THERMISTORHEATER_2 == 58) || (THERMISTORBED == 58) 
// Thermistor lookup table for Marlin
// ./createTemperatureLookup.py --rp=4670 --t1=21.7:110700.0 --t2=190.0:623.0 --t3=259.0:192.0 --num-temps=72
// thermistor table for  heatbed
const short temptable_58[][2] PROGMEM = {
  {198, 350},
  {210, 345},
  {223, 340},
  {236, 335},
  {251, 330},
  {267, 325},
  {284, 320},
  {303, 315},
  {323, 310},
  {345, 305},
  {369, 300},
  {395, 295},
  {423, 290},
  {453, 285},
  {486, 280},
  {522, 275},
  {562, 270},
  {605, 265},
  {652, 260},
  {704, 255},
  {760, 250},
  {822, 245},
  {890, 240},
  {964, 235},
  {1046, 230},
  {1136, 225},
  {1235, 220},
  {1344, 215},
  {1464, 210},
  {1597, 205},
  {1743, 200},
  {1903, 195},
  {2080, 190},
  {2275, 185},
  {2489, 180},
  {2725, 175},
  {2983, 170},
  {3267, 165},
  {3576, 160},
  {3913, 155},
  {4280, 150},
  {4676, 145},
  {5104, 140},
  {5561, 135},
  {6049, 130},
  {6565, 125},
  {7108, 120},
  {7673, 115},
  {8256, 110},
  {8852, 105},
  {9455, 100},
  {10058, 95},
  {10654, 90},
  {11237, 85},
  {11799, 80},
  {12334, 75},
  {12838, 70},
  {13306, 65},
  {13734, 60},
  {14123, 55},
  {14471, 50},
  {14779, 45},
  {15048, 40},
  {15282, 35},
  {15481, 30},
  {15651, 25},
  {15793, 20},
  {15912, 15},
  {16010, 10},
  {16090, 5},
  {16154, 0}
 };

#endif

#define _TT_NAME(_N) temptable_ ## _N
#define TT_NAME(_N) _TT_NAME(_N)

#if THERMISTORHEATER_0
  #define HEATER_0_TEMPTABLE TT_NAME(THERMISTORHEATER_0)
  #define HEATER_0_TEMPTABLE_LEN COUNT(HEATER_0_TEMPTABLE)
#elif defined(HEATER_0_USES_THERMISTOR)
  #error "No heater 0 thermistor table specified"
#else
  #define HEATER_0_TEMPTABLE NULL
  #define HEATER_0_TEMPTABLE_LEN 0
#endif

#if THERMISTORHEATER_1
  #define HEATER_1_TEMPTABLE TT_NAME(THERMISTORHEATER_1)
  #define HEATER_1_TEMPTABLE_LEN COUNT(HEATER_1_TEMPTABLE)
#elif defined(HEATER_1_USES_THERMISTOR)
  #error "No heater 1 thermistor table specified"
#else
  #define HEATER_1_TEMPTABLE NULL
  #define HEATER_1_TEMPTABLE_LEN 0
#endif

#if THERMISTORHEATER_2
  #define HEATER_2_TEMPTABLE TT_NAME(THERMISTORHEATER_2)
  #define HEATER_2_TEMPTABLE_LEN COUNT(HEATER_2_TEMPTABLE)
#elif defined(HEATER_2_USES_THERMISTOR)
  #error "No heater 2 thermistor table specified"
#else
  #define HEATER_2_TEMPTABLE NULL
  #define HEATER_2_TEMPTABLE_LEN 0
#endif

#if THERMISTORHEATER_3
  #define HEATER_3_TEMPTABLE TT_NAME(THERMISTORHEATER_3)
  #define HEATER_3_TEMPTABLE_LEN COUNT(HEATER_3_TEMPTABLE)
#elif defined(HEATER_3_USES_THERMISTOR)
  #error "No heater 3 thermistor table specified"
#else
  #define HEATER_3_TEMPTABLE NULL
  #define HEATER_3_TEMPTABLE_LEN 0
#endif

#if THERMISTORHEATER_4
  #define HEATER_4_TEMPTABLE TT_NAME(THERMISTORHEATER_4)
  #define HEATER_4_TEMPTABLE_LEN COUNT(HEATER_4_TEMPTABLE)
#elif defined(HEATER_4_USES_THERMISTOR)
  #error "No heater 4 thermistor table specified"
#else
  #define HEATER_4_TEMPTABLE NULL
  #define HEATER_4_TEMPTABLE_LEN 0
#endif

#ifdef THERMISTORBED
  #define BEDTEMPTABLE TT_NAME(THERMISTORBED)
  #define BEDTEMPTABLE_LEN COUNT(BEDTEMPTABLE)
#elif defined(HEATER_BED_USES_THERMISTOR)
  #error "No bed thermistor table specified"
#else
  #define BEDTEMPTABLE_LEN 0
#endif

#ifdef THERMISTORCHAMBER
  #define CHAMBERTEMPTABLE TT_NAME(THERMISTORCHAMBER)
  #define CHAMBERTEMPTABLE_LEN COUNT(CHAMBERTEMPTABLE)
#elif defined(HEATER_CHAMBER_USES_THERMISTOR)
  #error "No chamber thermistor table specified"
#else
  #define CHAMBERTEMPTABLE_LEN 0
#endif

// The SCAN_THERMISTOR_TABLE macro needs alteration?
static_assert(HEATER_0_TEMPTABLE_LEN < 256 && HEATER_1_TEMPTABLE_LEN < 256 && HEATER_2_TEMPTABLE_LEN < 256 && HEATER_3_TEMPTABLE_LEN < 256 && HEATER_4_TEMPTABLE_LEN < 256 && BEDTEMPTABLE_LEN < 256 && CHAMBERTEMPTABLE_LEN < 256,
  "Temperature conversion tables over 255 entries need special consideration."
);

// Set the high and low raw values for the heaters
// For thermistors the highest temperature results in the lowest ADC value
// For thermocouples the highest temperature results in the highest ADC value
#ifndef HEATER_0_RAW_HI_TEMP
  #ifdef HEATER_0_USES_THERMISTOR
    #define HEATER_0_RAW_HI_TEMP 0
    #define HEATER_0_RAW_LO_TEMP 16383
  #else
    #define HEATER_0_RAW_HI_TEMP 16383
    #define HEATER_0_RAW_LO_TEMP 0
  #endif
#endif
#ifndef HEATER_1_RAW_HI_TEMP
  #ifdef HEATER_1_USES_THERMISTOR
    #define HEATER_1_RAW_HI_TEMP 0
    #define HEATER_1_RAW_LO_TEMP 16383
  #else
    #define HEATER_1_RAW_HI_TEMP 16383
    #define HEATER_1_RAW_LO_TEMP 0
  #endif
#endif
#ifndef HEATER_2_RAW_HI_TEMP
  #ifdef HEATER_2_USES_THERMISTOR
    #define HEATER_2_RAW_HI_TEMP 0
    #define HEATER_2_RAW_LO_TEMP 16383
  #else
    #define HEATER_2_RAW_HI_TEMP 16383
    #define HEATER_2_RAW_LO_TEMP 0
  #endif
#endif
#ifndef HEATER_3_RAW_HI_TEMP
  #ifdef HEATER_3_USES_THERMISTOR
    #define HEATER_3_RAW_HI_TEMP 0
    #define HEATER_3_RAW_LO_TEMP 16383
  #else
    #define HEATER_3_RAW_HI_TEMP 16383
    #define HEATER_3_RAW_LO_TEMP 0
  #endif
#endif
#ifndef HEATER_4_RAW_HI_TEMP
  #ifdef HEATER_4_USES_THERMISTOR
    #define HEATER_4_RAW_HI_TEMP 0
    #define HEATER_4_RAW_LO_TEMP 16383
  #else
    #define HEATER_4_RAW_HI_TEMP 16383
    #define HEATER_4_RAW_LO_TEMP 0
  #endif
#endif
#ifndef HEATER_BED_RAW_HI_TEMP
  #ifdef HEATER_BED_USES_THERMISTOR
    #define HEATER_BED_RAW_HI_TEMP 0
    #define HEATER_BED_RAW_LO_TEMP 16383
  #else
    #define HEATER_BED_RAW_HI_TEMP 16383
    #define HEATER_BED_RAW_LO_TEMP 0
  #endif
#endif
#ifndef HEATER_CHAMBER_RAW_HI_TEMP
  #ifdef HEATER_CHAMBER_USES_THERMISTOR
    #define HEATER_CHAMBER_RAW_HI_TEMP 0
    #define HEATER_CHAMBER_RAW_LO_TEMP 16383
  #else
    #define HEATER_CHAMBER_RAW_HI_TEMP 16383
    #define HEATER_CHAMBER_RAW_LO_TEMP 0
  #endif
#endif

#endif // THERMISTORTABLES_H_
