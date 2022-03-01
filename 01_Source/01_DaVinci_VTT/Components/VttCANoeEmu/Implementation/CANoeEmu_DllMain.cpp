/*-----------------------------------------------------------------------------
Module: CANoeEmu - AUTOSAR platform emulator for CANoe and VTT
-------------------------------------------------------------------------------
This source file provides the DllMain function for a VTT SUT DLL.

The main purpose is to initialize the CANoeEmu-Library with the DLL instance 
handle and the activation of the memory leak detection feature of the 
C Runtime from Visual Studio.
-------------------------------------------------------------------------------
Copyright (c) Vector Informatik GmbH. All rights reserved.
-----------------------------------------------------------------------------*/


#pragma warning( disable : 4820 )
#pragma warning( disable : 4514 )
#pragma warning( disable : 4668 )

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <crtdbg.h>

#include "CANoeApi.h"


BOOL WINAPI DllMain( HINSTANCE hInstance, DWORD dwReason, LPVOID)
{
  if ( dwReason == DLL_PROCESS_ATTACH)
  {
    // Example for setting a breakpoint when reaching the given allocation number
    //
    //   _CrtSetBreakAlloc(161);
    //
    
    // Perform automatic leak checking when DLL is unloaded.
    // _CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF | _CRTDBG_ALLOC_MEM_DF);
    
    // Example for a memory leak. Uncomment the next line to see memory leak checking in action.
    //
    //   int* a = new int;
    // 

    // Initialize the CANoe Emulation Library
    CANoeAPI_SetDllInstanceHandle(hInstance);
  }

  if ( dwReason == DLL_PROCESS_DETACH)
  {
    // We can do an explicit dump for memory leaks here for easier debugging, but normally it is better doing it later, 
    // because the destructor functions of global C++ variables are not call yet.
    // For an explicit dump do the following:  _CrtDumpMemoryLeaks();
  }

  return TRUE;
}