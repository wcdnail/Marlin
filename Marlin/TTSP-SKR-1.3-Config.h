/**********************************************************************************************************************
 * Спец-конфиг TwoTrees Sapphire Pro
 *
 */

#pragma once

#include "src/core/boards.h"

#define COREXY

#define SHOW_BOOTSCREEN
#define SHOW_CUSTOM_BOOTSCREEN
#define CUSTOM_STATUS_SCREEN_IMAGE

#define MY_CUSTOM_MACHINE_NAME  "TTSP"
#define MY_MACHINE_UUID         "521ba1fe-4e9d-4eed-9f6f-3779385f5824"
#define CUSTMOM_SPLASH_LINE1    SHORT_BUILD_VERSION "[WCD]"

#define MOTHERBOARD             BOARD_BTT_SKR_V1_3
#define SERIAL_PORT             -1
#define SERIAL_PORT_2           0
#define BAUDRATE                250000 // [2400, 9600, 19200, 38400, 57600, 115200, 250000, 500000, 1000000]
//#define BAUDRATE_2            250000
//#define SERIAL_PORT_3         1
//#define BAUDRATE_3            250000

/**********************************************************************************************************************
 * Нагреватели
 *
 */

#define MPCTEMP // ** EXPERIMENTAL **
//#define PIDTEMP
#define PIDTEMPBED

#ifdef PIDTEMP
  // TODO: настроить!!! https://reprap.org/wiki/PID_Tuning
  #define My_DEFAULT_Kp 19.94
  #define My_DEFAULT_Ki 1.66
  #define My_DEFAULT_Kd 59.96
#endif

#ifdef PIDTEMPBED
  // TODO: настроить!!!
  // M303 E-1 C8 S90
  #define My_DEFAULT_bedKp 71.82
  #define My_DEFAULT_bedKi 14.00
  #define My_DEFAULT_bedKd 245.64
#endif

#ifdef MPCTEMP
  #define MPC_EDIT_MENU                 // Add MPC editing to the "Advanced Settings" menu. (~1300 bytes of flash)
  #define MPC_AUTOTUNE_MENU             // Add MPC auto-tuning to the "Advanced Settings" menu. (~350 bytes of flash)
  #define MY_MPC_HEATER_POWER { 40.0f } // (W) Heat cartridge powers.
#endif

/**********************************************************************************************************************
 * Горячая кровать
 *
 */

// TODO: проверить!
#define BLTOUCH
#define MULTIPLE_PROBING            2
//#define AUTO_BED_LEVELING_LINEAR
#define AUTO_BED_LEVELING_UBL
//#define AUTO_BED_LEVELING_BILINEAR
//#define MESH_BED_LEVELING
#define RESTORE_LEVELING_AFTER_G28
#ifdef AUTO_BED_LEVELING_UBL
  #define MESH_EDIT_GFX_OVERLAY
#endif  
#define MESH_INSET                  20
#define GRID_MAX_POINTS_X           4
#define GRID_MAX_POINTS_Y           5

// TODO: подправить!
#define MY_NOZZLE_TO_PROBE_OFFSET   { 0, -55, 0 }                   // Координаты относительно сопла
#define MY_PROBING_MARGIN           10                              // with NOZZLE_AS_PROBE this can be negative
#define MY_XY_PROBE_FEEDRATE        (133*60)                        // mm/min
#define MY_Z_PROBE_FEEDRATE_FAST    (4*60)
#define MY_Z_PROBE_FEEDRATE_SLOW    (MY_Z_PROBE_FEEDRATE_FAST / 2)

// TODO: подправить!
#define X_BED_SIZE                  220
#define Y_BED_SIZE                  220
#define X_MIN_POS                   -2.9
#define Y_MIN_POS                   7.5
#define Z_MIN_POS                   0
#define X_MAX_POS                   (X_MIN_POS + X_BED_SIZE)
#define Y_MAX_POS                   (Y_MIN_POS + Y_BED_SIZE)
#define Z_MAX_POS                   200

/**********************************************************************************************************************
 * Драйвера:
 * 
 *   A4988,              A5984,
 * DRV8825,             LV8729,
 *  TB6560,             TB6600, 
 * TMC2100,
 * TMC2130, TMC2130_STANDALONE, 
 * TMC2160, TMC2160_STANDALONE,
 * TMC2208, TMC2208_STANDALONE,
 * TMC2209, TMC2209_STANDALONE,
 *  TMC26X,  TMC26X_STANDALONE,
 * TMC2660, TMC2660_STANDALONE,
 * TMC5130, TMC5130_STANDALONE,
 * TMC5160, TMC5160_STANDALONE
 *
 */

#define TMC_DEBUG
#define TMC_USE_SW_SPI

#define MY_X_DRIVER_TYPE                TMC2130
#define MY_Y_DRIVER_TYPE                TMC2130
#define MY_Z_DRIVER_TYPE                TMC2130
#define MY_E0_DRIVER_TYPE               TMC2130

#define HYBRID_THRESHOLD

#define MY_X_HYBRID_THRESHOLD               100   // [mm/s]
#define MY_Y_HYBRID_THRESHOLD               100
#define MY_Z_HYBRID_THRESHOLD                 3
#define MY_E0_HYBRID_THRESHOLD               30   // [linear=mm/s, rotational=°/s]

#define MY_HOLD_MULTIPLIER                  0.5   // Scales down the holding current from run current
#define MY_INTERPOLATE                     true
#define TMC_XY_MICROSTEPS                    64   // 0..256
#define TMC_Z_MICROSTEPS                     16
#define TMC_E_MICROSTEPS                     16

#define TMC_XY_CURRENT                      850
#define TMC_XY_CURRENT_HOME                 700

#define MY_X_CURRENT             TMC_XY_CURRENT   // (mA) RMS current. Multiply by 1.414 for peak current.
#define MY_X_CURRENT_HOME   TMC_XY_CURRENT_HOME   // (mA) RMS current for sensorless homing
#define MY_X_MICROSTEPS       TMC_XY_MICROSTEPS   
#define MY_X_RSENSE                        0.11
#define MY_X_CHAIN_POS                       -1   // -1..0: Not chained. 1: MCU MOSI connected. 2: Next in chain, ...
//#define MY_X_INTERPOLATE                 true   // Enable to override 'INTERPOLATE' for the X axis
//#define MY_X_HOLD_MULTIPLIER              0.5   // Enable to override 'HOLD_MULTIPLIER' for the X axis

#define MY_Y_CURRENT              TMC_XY_CURRENT
#define MY_Y_CURRENT_HOME    TMC_XY_CURRENT_HOME
#define MY_Y_MICROSTEPS        TMC_XY_MICROSTEPS
#define MY_Y_RSENSE                         0.11
#define MY_Y_CHAIN_POS                        -1
//#define MY_Y_INTERPOLATE                  true
//#define MY_Y_HOLD_MULTIPLIER               0.5

#define MY_Z_CURRENT                         950
#define MY_Z_CURRENT_HOME              Z_CURRENT
#define MY_Z_MICROSTEPS         TMC_Z_MICROSTEPS
#define MY_Z_RSENSE                         0.11
#define MY_Z_CHAIN_POS                        -1
//#define MY_Z_INTERPOLATE                  true
//#define MY_Z_HOLD_MULTIPLIER               0.5

#define MY_E0_CURRENT                        800
#define MY_E0_MICROSTEPS        TMC_E_MICROSTEPS
#define MY_E0_RSENSE                        0.11
#define MY_E0_CHAIN_POS                       -1
//#define MY_E0_INTERPOLATE                 true
//#define MY_E0_HOLD_MULTIPLIER              0.5

/**********************************************************************************************************************
 * > Домой, пора домой!
 *
 */

#define SENSORLESS_HOMING
#define MY_X_STALL_SENSITIVITY                 3   // M914 X10 Y10  ; Set X and Y stall sensitivity to 10
#define MY_Y_STALL_SENSITIVITY                 3

#define X_HOME_DIR -1
#define Y_HOME_DIR -1 // @@ SapphirePro SKR 1.3 uses MIN Y endstop on max Y=-1 (for Nano)
#define Z_HOME_DIR -1

/**********************************************************************************************************************
 * Концевики
 *
 */

#define ENDSTOPPULLUPS
//#define ENDSTOPPULLDOWNS

#define USE_XMIN_PLUG
#define USE_YMIN_PLUG
#define USE_ZMIN_PLUG
#define USE_XMAX_PLUG
#define USE_YMAX_PLUG
#define USE_ZMAX_PLUG

#define MY_X_MIN_ENDSTOP_INVERTING          true
#define MY_Y_MIN_ENDSTOP_INVERTING          true
#define MY_Z_MIN_ENDSTOP_INVERTING          true
#define MY_X_MAX_ENDSTOP_INVERTING          true
#define MY_Y_MAX_ENDSTOP_INVERTING          true
#define MY_Z_MAX_ENDSTOP_INVERTING          true
#define MY_Z_MIN_PROBE_ENDSTOP_INVERTING    false // BLTOUCH

/**********************************************************************************************************************
 * Движение, шаги на миллиметр, ускорения, рывки
 *
 */

#define INVERT_X_DIR                    true
#define INVERT_Y_DIR                    true
#define INVERT_Z_DIR                    true
#define INVERT_E0_DIR                   false

#define SPM_XY_KOEF                     (TMC_XY_MICROSTEPS/16)
#define SPM_Z_KOEF                      (TMC_Z_MICROSTEPS/16)
#define SPM_E_KOEF                      (TMC_E_MICROSTEPS/16)

#define MY_DEFAULT_AXIS_STEPS_PER_UNIT  { 80 * SPM_XY_KOEF, 80 * SPM_XY_KOEF, 1600 * SPM_Z_KOEF, 403.44 * SPM_E_KOEF }

#define MY_DEFAULT_MAX_FEEDRATE         { 200, 200, 4, 75 }
#define MY_DEFAULT_MAX_ACCELERATION     { 2000, 2000, 100, 1000 }
#define MY_DEFAULT_ACCELERATION          1500   // M204 P - X, Y, Z & E
#define MY_DEFAULT_RETRACT_ACCELERATION  1000   // M204 R - E acceleration for retracts
#define MY_DEFAULT_TRAVEL_ACCELERATION   2000   // M204 T - X, Y, Z acceleration for travel (non printing) moves
#define MY_DEFAULT_EJERK                 1.5    // May be used by Linear Advance @lowered to keep extruder from rattling
#define MY_JUNCTION_DEVIATION_MM         0.025  // (mm) Distance from real junction edge
#define JD_HANDLE_SMALL_SEGMENTS                // Use curvature estimation instead of just the junction angle
                                                // for small segments (< 1mm) with large junction angles (> 135°).
#define S_CURVE_ACCELERATION                    // https://github.com/synthetos/TinyG/wiki/Jerk-Controlled-Motion-Explained

