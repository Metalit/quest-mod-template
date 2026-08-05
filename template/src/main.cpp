// Include our main header file, containing the logger
#include "main.hpp"

// Include dependency headers
#include "scotland2/shared/modloader.h"

// Store the mod ID and version, so it can be sent to the modloader at startup
static modloader::ModInfo modInfo{MOD_ID, VERSION, 0};

// Called in the early stages of game loading
// (see https://github.com/sc2ad/scotland2?tab=readme-ov-file#installationusage)
// Often used to initialize and load configs, in addition to its contents here
extern "C" void setup(CModInfo* info) noexcept {
    *info = modInfo.to_c();

    // Register our logger so that all its messages are stored in a file
    Paper::Logger::RegisterFileContextId(MOD_ID);

    logger.info("Completed setup!");
}

// Called later on in the game loading, after all mods have been opened
// Often used to install hooks and use the APIs of other mods or libraries
extern "C" void late_load() noexcept {
    logger.info("Completed load!");
}
