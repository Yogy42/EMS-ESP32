/*
 * General information about known EMS devices
 * 
 * Paul Derbyshire - https://github.com/proddy/EMS-ESP
 *
 * See ChangeLog.md for History
 * See README.md for Acknowledgments
 *
 */

#pragma once

#include "ems.h"

/*
 * Common
 */
#define EMS_TYPE_Version 0x02

/*
 * Boiler...
 */
#define EMS_TYPE_UBAMonitorFast 0x18              // is an automatic monitor broadcast
#define EMS_TYPE_UBAMonitorSlow 0x19              // is an automatic monitor broadcast
#define EMS_TYPE_UBAMonitorWWMessage 0x34         // is an automatic monitor broadcast
#define EMS_TYPE_UBAMaintenanceStatusMessage 0x1C // is an automatic monitor broadcast
#define EMS_TYPE_UBAParameterWW 0x33
#define EMS_TYPE_UBATotalUptimeMessage 0x14
#define EMS_TYPE_UBAMaintenanceSettingsMessage 0x15
#define EMS_TYPE_UBAParametersMessage 0x16
#define EMS_TYPE_UBASetPoints 0x1A
#define EMS_TYPE_UBAFunctionTest 0x1D

#define EMS_OFFSET_UBAParameterWW_wwtemp 2                  // WW Temperature
#define EMS_OFFSET_UBAParameterWW_wwactivated 1             // WW Activated
#define EMS_OFFSET_UBAParameterWW_wwComfort 9               // WW is in comfort or eco mode
#define EMS_VALUE_UBAParameterWW_wwComfort_Hot 0x00         // the value for hot
#define EMS_VALUE_UBAParameterWW_wwComfort_Eco 0xD8         // the value for eco
#define EMS_VALUE_UBAParameterWW_wwComfort_Intelligent 0xEC // the value for intelligent

#define EMS_OFFSET_UBASetPoints_flowtemp 0 // flow temp

// Other
#define EMS_TYPE_SM10Monitor 0x97    // SM10Monitor
#define EMS_TYPE_SM100Monitor 0x0262 // SM100Monitor
#define EMS_TYPE_SM100Status 0x0264  // SM100Status
#define EMS_TYPE_SM100Status2 0x026A // SM100Status2
#define EMS_TYPE_SM100Energy 0x028E  // SM100Energy
#define EMS_TYPE_HPMonitor1 0xE3     // HeatPump Monitor 1
#define EMS_TYPE_HPMonitor2 0xE5     // HeatPump Monitor 2

#define EMS_TYPE_ISM1StatusMessage 0x0003  // Solar Module Junkers ISM1 Status
#define EMS_TYPE_ISM1Set 0x0001            // for setting values of the solar module like max boiler temp
#define EMS_OFFSET_ISM1Set_MaxBoilerTemp 6 // position of max boiler temp  e.g. 50 in the following example: 90 30 FF 06 00 01 50 (CRC=2C)

/*
 * Thermostats...
 */

// Common for all thermostats
#define EMS_TYPE_RCTime 0x06               // is an automatic thermostat broadcast
#define EMS_TYPE_RCOutdoorTempMessage 0xA3 // is an automatic thermostat broadcast, outdoor external temp

// RC10 specific
#define EMS_TYPE_RC10StatusMessage 0xB1         // is an automatic thermostat broadcast giving us temps
#define EMS_TYPE_RC10Set 0xB0                   // for setting values like temp and mode
#define EMS_OFFSET_RC10Set_temp 4               // position of thermostat setpoint temperature
#define EMS_OFFSET_RC10StatusMessage_setpoint 1 // setpoint temp
#define EMS_OFFSET_RC10StatusMessage_curr 2     // current temp

// RC20 specific
#define EMS_TYPE_RC20StatusMessage 0x91         // is an automatic thermostat broadcast giving us temps
#define EMS_TYPE_RC20Set 0xA8                   // for setting values like temp and mode
#define EMS_OFFSET_RC20Set_mode 23              // position of thermostat mode
#define EMS_OFFSET_RC20Set_temp 28              // position of thermostat setpoint temperature
#define EMS_OFFSET_RC20StatusMessage_setpoint 1 // setpoint temp
#define EMS_OFFSET_RC20StatusMessage_curr 2     // current temp

// RC30 specific
#define EMS_TYPE_RC30StatusMessage 0x41         // is an automatic thermostat broadcast giving us temps
#define EMS_TYPE_RC30Set 0xA7                   // for setting values like temp and mode
#define EMS_OFFSET_RC30Set_mode 23              // position of thermostat mode
#define EMS_OFFSET_RC30Set_temp 28              // position of thermostat setpoint temperature
#define EMS_OFFSET_RC30StatusMessage_setpoint 1 // setpoint temp
#define EMS_OFFSET_RC30StatusMessage_curr 2     // current temp

// RC35 specific
#define EMS_TYPE_RC35StatusMessage_HC1 0x3E     // is an automatic thermostat broadcast giving us temps on HC1
#define EMS_TYPE_RC35StatusMessage_HC2 0x48     // is an automatic thermostat broadcast giving us temps on HC2
#define EMS_TYPE_RC35Set_HC1 0x3D               // for setting values like temp and mode (Working mode HC1)
#define EMS_TYPE_RC35Set_HC2 0x47               // for setting values like temp and mode (Working mode HC2)
#define EMS_OFFSET_RC35StatusMessage_setpoint 2 // desired temp
#define EMS_OFFSET_RC35StatusMessage_curr 3     // current temp
#define EMS_OFFSET_RC35Set_mode 7               // position of thermostat mode
#define EMS_OFFSET_RC35Set_temp_day 2           // position of thermostat setpoint temperature for day time
#define EMS_OFFSET_RC35Set_temp_night 1         // position of thermostat setpoint temperature for night time
#define EMS_OFFSET_RC35Get_mode_day 1           // position of thermostat day mode
#define EMS_OFFSET_RC35Set_temp_holiday 3       // temp during holiday 0x47
#define EMS_OFFSET_RC35Set_heatingtype 0        // floor heating = 3 0x47
#define EMS_OFFSET_RC35Set_circuitcalctemp 14   // calculated circuit temperature 0x48

// Easy specific
#define EMS_TYPE_EasyStatusMessage 0x0A          // reading values on an Easy Thermostat
#define EMS_OFFSET_EasyStatusMessage_setpoint 10 // setpoint temp
#define EMS_OFFSET_EasyStatusMessage_curr 8      // current temp

// RC1010, RC310 and RC300 specific (EMS Plus)
#define EMS_TYPE_RCPLUSStatusMessage 0x01A5       // is an automatic thermostat broadcast giving us temps
#define EMS_TYPE_RCPLUSStatusHeating 0x01B9       // heating mode
#define EMS_TYPE_RCPLUSStatusMode 0x1AF           // summer/winter mode
#define EMS_TYPE_RCPLUSSet 0x03                   // setpoint temp message
#define EMS_OFFSET_RCPLUSStatusMessage_setpoint 3 // setpoint temp
#define EMS_OFFSET_RCPLUSStatusMessage_curr 0     // current temp
#define EMS_OFFSET_RCPLUSGet_mode_day 8           // day/night mode
#define EMS_OFFSET_RCPLUSStatusMessage_mode 0x0A  // thermostat mode (auto, manual)

// Junkers FR10, FW100 (EMS Plus)
#define EMS_TYPE_JunkersStatusMessage 0x6F         // is an automatic thermostat broadcast giving us temps
#define EMS_OFFSET_JunkersStatusMessage_setpoint 2 // setpoint temp
#define EMS_OFFSET_JunkersStatusMessage_curr 4     // current temp


// Known EMS types
typedef enum {
    EMS_MODEL_NONE, // unset
    EMS_MODEL_ALL,  // common for all devices

    // heatpump
    EMS_MODEL_HP,

    // solar module
    EMS_MODEL_SM,

    // boiler
    EMS_MODEL_UBA,

    // and the thermostats
    EMS_MODEL_ES73,
    EMS_MODEL_RC10,
    EMS_MODEL_RC20,
    EMS_MODEL_RC20F,
    EMS_MODEL_RC30,
    EMS_MODEL_RC35,
    EMS_MODEL_EASY,
    EMS_MODEL_RC300,
    EMS_MODEL_CW100,
    EMS_MODEL_1010,
    EMS_MODEL_OT,
    EMS_MODEL_FW100,
    EMS_MODEL_FR10,
    EMS_MODEL_FR100,
    EMS_MODEL_FR110,
    EMS_MODEL_FW120

} _EMS_MODEL_ID;

// EMS types for known boilers. This list will be extended when new devices are recognized.
// The device_id is always 0x08
// format is PRODUCT ID, DESCRIPTION
const _Boiler_Type Boiler_Types[] = {

    {72, "MC10 Module"},
    {123, "Buderus GB172/Nefit Trendline/Junkers Cerapur"},
    {115, "Nefit Topline Compact/Buderus GB162"},
    {203, "Buderus Logamax U122/Junkers Cerapur"},
    {208, "Buderus Logamax plus/GB192"},
    {64, "Sieger BK15/Nefit Smartline/Buderus GB152"},
    {EMS_PRODUCTID_HEATRONICS, "Bosch Condens 2500/Junkers Heatronics3"},
    {122, "Nefit Proline"},
    {172, "Nefit Enviline"}

};

/*
 * Known Solar Module types
 * format is PRODUCT ID, DEVICE ID, DESCRIPTION
 */
const _SolarModule_Type SolarModule_Types[] = {

    {EMS_PRODUCTID_SM10, EMS_ID_SM, "SM10 Solar Module"},
    {EMS_PRODUCTID_SM100, EMS_ID_SM, "SM100 Solar Module"},
    {EMS_PRODUCTID_ISM1, EMS_ID_SM, "Junkers ISM1 Solar Module"}

};

// Other EMS devices which are not considered boilers, thermostats or solar modules
// format is PRODUCT ID, DEVICE ID, DESCRIPTION
const _Other_Type Other_Types[] = {

    {69, 0x21, "MM10 Mixer Module"},
    {71, 0x11, "WM10 Switch Module"},
    {160, 0x20, "MM100 Mixing Module"},
    {160, 0x21, "MM100 Mixing Module"},
    {159, 0x21, "MM50 Mixing Module"},
    {68, 0x09, "BC10/RFM20 Receiver"},
    {190, 0x09, "BC10 Base Controller"},
    {114, 0x09, "BC10 Base Controller"},
    {125, 0x09, "BC25 Base Controller"},
    {152, 0x09, "Junkers Controller"},
    {205, 0x02, "Nefit Moduline Easy Connect"},
    {206, 0x02, "Bosch Easy Connect"},
    {171, 0x02, "EMS-OT OpenTherm converter"},
    {252, EMS_ID_HP, "HeatPump Module"},
    {189, EMS_ID_GATEWAY, "Web Gateway KM200"}

};

// heatpump
// format is PRODUCT ID, DEVICE ID, DESCRIPTION
const _HeatPump_Type HeatPump_Types[] = {{252, EMS_ID_HP, "HeatPump Module"}};

/*
 * Known thermostat types and their capabilities
 * format is MODEL_ID, PRODUCT ID, DEVICE ID, DESCRIPTION
 */
const _Thermostat_Type Thermostat_Types[] = {

    // Easy devices - not currently supporting write operations
    {EMS_MODEL_EASY, 202, 0x18, "Logamatic TC100/Nefit Moduline Easy", EMS_THERMOSTAT_WRITE_NO},
    {EMS_MODEL_EASY, 203, 0x18, "Bosch EasyControl CT200", EMS_THERMOSTAT_WRITE_NO},
    {EMS_MODEL_CW100, 157, 0x18, "Bosch CW100", EMS_THERMOSTAT_WRITE_NO},

    // Buderus/Nefit
    {EMS_MODEL_RC10, 79, 0x17, "RC10/Nefit Moduline 100", EMS_THERMOSTAT_WRITE_YES},
    {EMS_MODEL_RC20, 77, 0x17, "RC20/Nefit Moduline 300", EMS_THERMOSTAT_WRITE_YES},
    {EMS_MODEL_RC20F, 93, 0x18, "RC20F", EMS_THERMOSTAT_WRITE_YES},
    {EMS_MODEL_RC30, 78, 0x10, "RC30/Nefit Moduline 400", EMS_THERMOSTAT_WRITE_YES},
    {EMS_MODEL_RC35, 86, 0x10, "RC35", EMS_THERMOSTAT_WRITE_YES},
    {EMS_MODEL_RC300, 158, 0x10, "RC300/RC310/Nefit Moduline 3000", EMS_THERMOSTAT_WRITE_NO},
    {EMS_MODEL_1010, 165, 0x18, "Nefit Moduline 1010", EMS_THERMOSTAT_WRITE_NO},

    // Sieger
    {EMS_MODEL_ES73, 76, 0x10, "Sieger ES73", EMS_THERMOSTAT_WRITE_YES},

    // Junkers
    {EMS_MODEL_FW100, 105, 0x10, "Junkers FW100", EMS_THERMOSTAT_WRITE_NO},
    {EMS_MODEL_FR10, 111, 0x18, "Junkers FR10", EMS_THERMOSTAT_WRITE_NO},
    {EMS_MODEL_FR100, 105, 0x18, "Junkers FR100", EMS_THERMOSTAT_WRITE_NO},
    {EMS_MODEL_FR110, 108, 0x18, "Junkers FR110", EMS_THERMOSTAT_WRITE_NO},
    {EMS_MODEL_FW120, 192, 0x10, "Junkers FW120", EMS_THERMOSTAT_WRITE_NO}

};