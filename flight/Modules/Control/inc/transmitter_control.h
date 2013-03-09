/**
 ******************************************************************************
 * @addtogroup Modules Tau Labs Modules
 * @{
 * @addtogroup Control Control Module
 * @{
 *
 * @file       transmitter_control.h
 * @author     Tau Labs, http://github.org/TauLabs Copyright (C) 2013.
 * @brief      Process transmitter inputs and use as control source
 *
 * @see        The GNU Public License (GPL) Version 3
 *
 *****************************************************************************/
/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 * for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#ifndef TRANSMITTER_CONTROL_H
#define TRANSMITTER_CONTROL_H

#include "stdint.h"
#include "control.h"
#include "manualcontrolcommand.h"

typedef enum {FLIGHTMODE_UNDEFINED = 0, FLIGHTMODE_MANUAL = 1, FLIGHTMODE_STABILIZED = 2, FLIGHTMODE_GUIDANCE = 3, FLIGHTMODE_TUNING = 4} flightmode_path;

#define PARSE_FLIGHT_MODE(x) ( \
	(x == FLIGHTSTATUS_FLIGHTMODE_MANUAL)          ? FLIGHTMODE_MANUAL : \
	(x == FLIGHTSTATUS_FLIGHTMODE_STABILIZED1)     ? FLIGHTMODE_STABILIZED : \
	(x == FLIGHTSTATUS_FLIGHTMODE_STABILIZED2)     ? FLIGHTMODE_STABILIZED : \
	(x == FLIGHTSTATUS_FLIGHTMODE_STABILIZED3)     ? FLIGHTMODE_STABILIZED : \
	(x == FLIGHTSTATUS_FLIGHTMODE_ALTITUDEHOLD)    ? FLIGHTMODE_GUIDANCE : \
	(x == FLIGHTSTATUS_FLIGHTMODE_VELOCITYCONTROL) ? FLIGHTMODE_GUIDANCE : \
	(x == FLIGHTSTATUS_FLIGHTMODE_POSITIONHOLD)    ? FLIGHTMODE_GUIDANCE : \
	(x == FLIGHTSTATUS_FLIGHTMODE_RETURNTOHOME)    ? FLIGHTMODE_GUIDANCE : \
	(x == FLIGHTSTATUS_FLIGHTMODE_PATHPLANNER)     ? FLIGHTMODE_GUIDANCE : \
	(x == FLIGHTSTATUS_FLIGHTMODE_AUTOTUNE)        ? FLIGHTMODE_TUNING : FLIGHTMODE_UNDEFINED \
	)

int32_t ControlInitialize();

/*
 * These are assumptions we make in the flight code about the order of settings and their consistency between
 * objects.  Please keep this synchronized to the UAVObjects
 */
#define assumptions1 ( \
((int)MANUALCONTROLSETTINGS_STABILIZATION1SETTINGS_NONE      == (int)STABILIZATIONDESIRED_STABILIZATIONMODE_NONE)       && \
((int)MANUALCONTROLSETTINGS_STABILIZATION1SETTINGS_RATE      == (int)STABILIZATIONDESIRED_STABILIZATIONMODE_RATE)       && \
((int)MANUALCONTROLSETTINGS_STABILIZATION1SETTINGS_AXISLOCK  == (int)STABILIZATIONDESIRED_STABILIZATIONMODE_AXISLOCK)       && \
((int)MANUALCONTROLSETTINGS_STABILIZATION1SETTINGS_WEAKLEVELING      == (int)STABILIZATIONDESIRED_STABILIZATIONMODE_WEAKLEVELING)       && \
((int)MANUALCONTROLSETTINGS_STABILIZATION1SETTINGS_ATTITUDE  == (int)STABILIZATIONDESIRED_STABILIZATIONMODE_ATTITUDE)      \
)

#define assumptions3 ( \
((int)MANUALCONTROLSETTINGS_STABILIZATION2SETTINGS_NONE      == (int)STABILIZATIONDESIRED_STABILIZATIONMODE_NONE)      && \
((int)MANUALCONTROLSETTINGS_STABILIZATION2SETTINGS_RATE      == (int)STABILIZATIONDESIRED_STABILIZATIONMODE_RATE)      && \
((int)MANUALCONTROLSETTINGS_STABILIZATION2SETTINGS_AXISLOCK  == (int)STABILIZATIONDESIRED_STABILIZATIONMODE_AXISLOCK)       && \
((int)MANUALCONTROLSETTINGS_STABILIZATION2SETTINGS_WEAKLEVELING      == (int)STABILIZATIONDESIRED_STABILIZATIONMODE_WEAKLEVELING)       && \
((int)MANUALCONTROLSETTINGS_STABILIZATION2SETTINGS_ATTITUDE  == (int)STABILIZATIONDESIRED_STABILIZATIONMODE_ATTITUDE)     \
)

#define assumptions5 ( \
((int)MANUALCONTROLSETTINGS_STABILIZATION3SETTINGS_NONE      == (int)STABILIZATIONDESIRED_STABILIZATIONMODE_NONE)      && \
((int)MANUALCONTROLSETTINGS_STABILIZATION3SETTINGS_RATE      == (int)STABILIZATIONDESIRED_STABILIZATIONMODE_RATE)      && \
((int)MANUALCONTROLSETTINGS_STABILIZATION3SETTINGS_AXISLOCK  == (int)STABILIZATIONDESIRED_STABILIZATIONMODE_AXISLOCK)       && \
((int)MANUALCONTROLSETTINGS_STABILIZATION3SETTINGS_WEAKLEVELING      == (int)STABILIZATIONDESIRED_STABILIZATIONMODE_WEAKLEVELING)       && \
((int)MANUALCONTROLSETTINGS_STABILIZATION3SETTINGS_ATTITUDE  == (int)STABILIZATIONDESIRED_STABILIZATIONMODE_ATTITUDE)     \
)

#define ARMING_CHANNEL_ROLL     0
#define ARMING_CHANNEL_PITCH    1
#define ARMING_CHANNEL_YAW      2

#define assumptions7 ( \
( ((int)MANUALCONTROLSETTINGS_ARMING_ROLLLEFT           -(int)MANUALCONTROLSETTINGS_ARMING_ROLLLEFT)/2 	== ARMING_CHANNEL_ROLL) 	&& \
( ((int)MANUALCONTROLSETTINGS_ARMING_ROLLRIGHT          -(int)MANUALCONTROLSETTINGS_ARMING_ROLLLEFT)/2 	== ARMING_CHANNEL_ROLL) 	&& \
( ((int)MANUALCONTROLSETTINGS_ARMING_PITCHFORWARD       -(int)MANUALCONTROLSETTINGS_ARMING_ROLLLEFT)/2 	== ARMING_CHANNEL_PITCH) 	&& \
( ((int)MANUALCONTROLSETTINGS_ARMING_PITCHAFT           -(int)MANUALCONTROLSETTINGS_ARMING_ROLLLEFT)/2 	== ARMING_CHANNEL_PITCH) 	&& \
( ((int)MANUALCONTROLSETTINGS_ARMING_YAWLEFT            -(int)MANUALCONTROLSETTINGS_ARMING_ROLLLEFT)/2 	== ARMING_CHANNEL_YAW) 		&& \
( ((int)MANUALCONTROLSETTINGS_ARMING_YAWRIGHT           -(int)MANUALCONTROLSETTINGS_ARMING_ROLLLEFT)/2 	== ARMING_CHANNEL_YAW)		\
)

#define assumptions8 ( \
( ((int)MANUALCONTROLSETTINGS_ARMING_ROLLLEFT           -(int)MANUALCONTROLSETTINGS_ARMING_ROLLLEFT)%2 	== 0) 	&& \
( ((int)MANUALCONTROLSETTINGS_ARMING_ROLLRIGHT          -(int)MANUALCONTROLSETTINGS_ARMING_ROLLLEFT)%2 	!= 0) 	&& \
( ((int)MANUALCONTROLSETTINGS_ARMING_PITCHFORWARD       -(int)MANUALCONTROLSETTINGS_ARMING_ROLLLEFT)%2 	== 0) 	&& \
( ((int)MANUALCONTROLSETTINGS_ARMING_PITCHAFT           -(int)MANUALCONTROLSETTINGS_ARMING_ROLLLEFT)%2 	!= 0) 	&& \
( ((int)MANUALCONTROLSETTINGS_ARMING_YAWLEFT            -(int)MANUALCONTROLSETTINGS_ARMING_ROLLLEFT)%2 	== 0)	&& \
( ((int)MANUALCONTROLSETTINGS_ARMING_YAWRIGHT           -(int)MANUALCONTROLSETTINGS_ARMING_ROLLLEFT)%2 	!= 0)	\
)

#define assumptions_flightmode ( \
( (int)MANUALCONTROLSETTINGS_FLIGHTMODEPOSITION_MANUAL == (int) FLIGHTSTATUS_FLIGHTMODE_MANUAL) && \
( (int)MANUALCONTROLSETTINGS_FLIGHTMODEPOSITION_STABILIZED1 == (int) FLIGHTSTATUS_FLIGHTMODE_STABILIZED1) && \
( (int)MANUALCONTROLSETTINGS_FLIGHTMODEPOSITION_STABILIZED2 == (int) FLIGHTSTATUS_FLIGHTMODE_STABILIZED2) && \
( (int)MANUALCONTROLSETTINGS_FLIGHTMODEPOSITION_STABILIZED3 == (int) FLIGHTSTATUS_FLIGHTMODE_STABILIZED3) && \
( (int)MANUALCONTROLSETTINGS_FLIGHTMODEPOSITION_VELOCITYCONTROL == (int) FLIGHTSTATUS_FLIGHTMODE_VELOCITYCONTROL) && \
( (int)MANUALCONTROLSETTINGS_FLIGHTMODEPOSITION_POSITIONHOLD == (int) FLIGHTSTATUS_FLIGHTMODE_POSITIONHOLD) && \
( (int)MANUALCONTROLSETTINGS_FLIGHTMODEPOSITION_RETURNTOHOME == (int) FLIGHTSTATUS_FLIGHTMODE_RETURNTOHOME) \
)

#define assumptions_channelcount ( \
( (int)MANUALCONTROLCOMMAND_CHANNEL_NUMELEM == (int)MANUALCONTROLSETTINGS_CHANNELGROUPS_NUMELEM ) && \
( (int)MANUALCONTROLCOMMAND_CHANNEL_NUMELEM == (int)MANUALCONTROLSETTINGS_CHANNELNUMBER_NUMELEM ) && \
( (int)MANUALCONTROLCOMMAND_CHANNEL_NUMELEM == (int)MANUALCONTROLSETTINGS_CHANNELMIN_NUMELEM ) && \
( (int)MANUALCONTROLCOMMAND_CHANNEL_NUMELEM == (int)MANUALCONTROLSETTINGS_CHANNELMAX_NUMELEM ) && \
( (int)MANUALCONTROLCOMMAND_CHANNEL_NUMELEM == (int)MANUALCONTROLSETTINGS_CHANNELNEUTRAL_NUMELEM ) )

//! Initialize the transmitter control mode
int32_t transmitter_control_initialize();

//! Process inputs and arming
int32_t transmitter_control_update();

//! Select and use transmitter control
int32_t transmitter_control_select();

//! Choose the control source based on transmitter status
enum control_selection transmitter_control_selected_controller();

 #endif /* TRANSMITTER_CONTROL_H */
