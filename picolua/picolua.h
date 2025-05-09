#ifndef PICOLUA_H
#define PICOLUA_H

/**
 * Lua test for Raspberry Pi Pico RP2350
 */

#include "pico/stdlib.h"
#include "hardware/flash.h"
#include "hardware/sync.h" // For flash
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// Include Lua headers for C
// #include "../../../lib/lua/lua-5.4.6/include/lua.h"
// #include "../../../lib/lua/lua-5.4.6/include/lauxlib.h"
// #include "../../../lib/lua/lua-5.4.6/include/lualib.h"

// Use the .hpp file for C++
#include "../../../lib/lua/lua-5.4.6/include/lua.hpp"

// System tools for pico end
#include "lua_h/pico.lua.h"
// Local the custom lua library file
#include "lua_h/tools.lua.h"
// Load our default main user script that was generated with the `convert_lua.sh` script
#include "lua_h/default.lua.h"
// Load the hander
#include "lua_h/system.lua.h"

// Right now we just use GPIO 0 for a test
#define DEFAULT_LED 0
                       
//
// UTILITY FUNCTIONS
//

// Returns the size of the flash memory used by the program
size_t pl_flash_info();

// Initialize the GPIO for the LED
void pl_pico_gpio_init(int pin);

// Turn the GPIO on or off
void pl_pico_gpio_set(int pin, bool state);

// Pico-specific functions for Lua
extern const struct luaL_Reg pl_pico_lib[];

// Initialize Lua and register Pico functions
lua_State *pl_init_lua(const struct luaL_Reg pl_app_lib[]);

#define BUFFER_SIZE_SERIAL 128

char* pl_serial_read_ln();

char* pl_serial_load_lua();

char *pl_serial_load_lua_hander();

int pl_init(const struct luaL_Reg app_lib[], int load_serial);

#endif // PICOLUA_H