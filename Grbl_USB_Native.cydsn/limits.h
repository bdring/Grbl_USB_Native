/*
  limits.h - code pertaining to limit-switches and performing the homing cycle
  Part of Grbl

  Copyright (c) 2012-2015 Sungeun K. Jeon  
  Copyright (c) 2009-2011 Simen Svale Skogsrud
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
#ifndef limits_h
#define limits_h
    
#include <stdint.h>
  
void limit_isr_handler(); // PSoc Interrupt handler  
void limits_init();
void limits_disable();
uint8_t limits_get_state();
void limits_go_home(uint8_t cycle_mask);
void limits_soft_check(float *target);
#endif