/*
  cpu_map.h - CPU and pin mapping configuration file
  Part of Grbl

  Copyright (c) 2012-2015 Sungeun K. Jeon
      Updated For PSoC 2017-2018 Barton Dring buildlog.net

  Grbl is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Grbl is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with Grbl.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef cpu_map_h
#define cpu_map_h


#define F_CPU 24000000UL

// we are going to define all 6 so the PSoC Control Registed should be defined as 6 and connect only what you need to pins
#define X_STEP_BIT    0 // Mapped in hardware schematic
#define Y_STEP_BIT    1 // ...
#define Z_STEP_BIT    2 // ...
#define A_STEP_BIT    3 //
#define B_STEP_BIT    4 
#define C_STEP_BIT    5 
#define STEP_MASK 0b111111

#define X_DIRECTION_BIT   0 // Mapped in hardware schematic
#define Y_DIRECTION_BIT   1 // Mapped in hardware schematic
#define Z_DIRECTION_BIT   2 // Mapped in hardware schematic
#define A_DIRECTION_BIT   3 //
#define B_DIRECTION_BIT   4 // 
#define C_DIRECTION_BIT   5 //
#define DIRECTION_MASK 0b111111 

// we don't need anything about limits here in PSoC


#define SPINDLE_PWM_OFF_VALUE     0
#ifndef SPINDLE_PWM_MIN_VALUE
    #define SPINDLE_PWM_MIN_VALUE   1   // Must be greater than zero.
#endif
#define SPINDLE_PWM_MAX_VALUE     255
#define SPINDLE_PWM_RANGE         (SPINDLE_PWM_MAX_VALUE-SPINDLE_PWM_MIN_VALUE)


#endif

/* [] END OF FILE */
