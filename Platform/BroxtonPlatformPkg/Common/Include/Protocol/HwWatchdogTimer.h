/** @file
  Copyright (c) 1999 - 2016, Intel Corporation. All rights reserved.<BR>

  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php.

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#ifndef __EFI_WATCHDOG_TIMER_DRIVER_PROTOCOL_H__
#define __EFI_WATCHDOG_TIMER_DRIVER_PROTOCOL_H__

#define EFI_WATCHDOG_TIMER_DRIVER_PROTOCOL_GUID \
  { 0xd5b06d16, 0x2ea1, 0x4def, 0x98, 0xd0, 0xa0, 0x5d, 0x40, 0x72, 0x84, 0x17 }

#define EFI_WATCHDOG_TIMER_NOT_SUPPORTED_PROTOCOL_GUID \
  { 0xe9e156ac, 0x3203, 0x4572, 0xac, 0xdf, 0x84, 0x4f, 0xdc, 0xdb, 0x6, 0xbf }


#include <Guid/HwWatchdogTimerHob.h>

//
// General Purpose Constants
//
#define ICH_INSTAFLUSH_GPIO      BIT16 // BIT 16 in GPIO Level 2 is GPIO 48.
#define B_INSTAFLUSH             BIT4
//
// Other Watchdog timer values
//
#define WDT_COUNTDOWN_VALUE                 0x14
#define BDS_WDT_COUNTDOWN_VALUE             0x35


//
// Prototypes for the Watchdog Timer Driver Protocol
//

typedef
EFI_STATUS
(EFIAPI *EFI_WATCHDOG_START_TIMER) (
  VOID
  );

typedef
EFI_STATUS
(EFIAPI *PEI_WATCHDOG_RESET_TIMER) (
  VOID
  );

typedef
EFI_STATUS
(EFIAPI *EFI_WATCHDOG_RESTART_TIMER) (
  VOID
  );

typedef
EFI_STATUS
(EFIAPI *EFI_WATCHDOG_STOP_TIMER) (
  VOID
  );

typedef
EFI_STATUS
(EFIAPI *EFI_WATCHDOG_CHECK_TIMEOUT) (
  OUT HW_WATCHDOG_TIMEOUT       *WatchdogTimeout
  );

typedef
EFI_STATUS
(EFIAPI *EFI_WATCHDOG_FORCE_REBOOT) (
  IN BOOLEAN                    ForceTimeout,
  IN UINT8                      ResetType
  );

typedef
EFI_STATUS
(EFIAPI *EFI_WATCHDOG_KNOWN_RESET) (
  IN BOOLEAN                    AllowReset
  );

typedef
EFI_STATUS
(EFIAPI *EFI_GET_TIMER_COUNT_DOWN_PERIOD)(
  OUT UINT32      *CountdownValue
  );

typedef
EFI_STATUS
(EFIAPI *EFI_SET_TIMER_COUNT_DOWN_PERIOD)(
  OUT UINT32      CountdownValue
  );

typedef
EFI_STATUS
(EFIAPI *PEI_WATCHDOG_CLEAR_TIMER_STATE) (
  );

typedef
EFI_STATUS
(EFIAPI *EFI_STALL_WATCHDOG_COUNTDOWN) (
  IN BOOLEAN Stall
  );

typedef struct _EFI_WATCHDOG_TIMER_DRIVER_PROTOCOL {
  EFI_WATCHDOG_START_TIMER                      StartWatchdogTimer;
  PEI_WATCHDOG_RESET_TIMER                      ResetWatchdogTimeout;
  EFI_WATCHDOG_RESTART_TIMER                    RestartWatchdogTimer;
  EFI_WATCHDOG_STOP_TIMER                       StopWatchdogTimer;
  EFI_WATCHDOG_CHECK_TIMEOUT                    CheckWatchdogTimeout;
  EFI_WATCHDOG_FORCE_REBOOT                     ForceReboot;
  EFI_WATCHDOG_KNOWN_RESET                      AllowKnownReset;
  EFI_GET_TIMER_COUNT_DOWN_PERIOD               GetCountdownPeriod;
  EFI_SET_TIMER_COUNT_DOWN_PERIOD               SetCountdownPeriod;
  PEI_WATCHDOG_CLEAR_TIMER_STATE                ClearTimerState;
  EFI_STALL_WATCHDOG_COUNTDOWN                  StallWatchdogCountdown;
} EFI_WATCHDOG_TIMER_DRIVER_PROTOCOL;

extern EFI_GUID gEfiWatchdogTimerDriverProtocolGuid;
extern EFI_GUID gEfiWatchdogTimerNotSupportedProtocolGuid;

#endif
