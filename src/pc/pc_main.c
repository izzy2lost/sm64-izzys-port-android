#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#ifdef TARGET_ANDROID
#include <sys/stat.h>
#include "platform.h"
#endif

#include "sm64.h"
#include "fs/fs.h" // Importing the file system header for managing file storage

#include "pc/lua/smlua.h"

#include "game/memory.h"
#include "audio/external.h"

#include "network/network.h"
#include "lua/smlua.h"

#include "audio/audio_api.h"
#include "audio/audio_sdl.h"
#include "audio/audio_null.h"

#include "pc_main.h"
#include "loading.h"
#include "cliopts.h"
#include "configfile.h"
#include "controller/controller_api.h"
#include "controller/controller_keyboard.h"
#ifdef TOUCH_CONTROLS
#include "controller/controller_touchscreen.h"
#endif

#include "game/display.h" // for gGlobalTimer
#include "game/game_init.h"
#include "game/main.h"
#include "game/rumble_init.h"

#include "pc/lua/utils/smlua_audio_utils.h"

#include "pc/network/version.h"
#include "pc/network/socket/domain_res.h"
#include "pc/network/network_player.h"
#include "pc/djui/djui.h"
#include "pc/djui/djui_unicode.h"
#include "pc/djui/djui_panel.h"
#include "pc/djui/djui_panel_modlist.h"
#include "pc/djui/djui_fps_display.h"
#include "pc/debuglog.h"
#include "pc/utils/misc.h"

#include "pc/mods/mods.h"

#include "debug_context.h"
#include "menu/intro_geo.h"

#ifdef DISCORD_SDK
#include "pc/discord/discord.h"
#endif

// Define global paths
static char base_dir[1024] = {0};
static char save_path[1024] = {0};
static char user_path[1024] = {0};

void initialize_paths(void) {
#ifdef TARGET_ANDROID
    const char *base_dir_android = get_gamedir();
    snprintf(base_dir, sizeof(base_dir), "%s/%s", base_dir_android, FS_BASEDIR);
    mkdir(base_dir, 0770); // Ensure the base directory exists
    SDL_AndroidCopyAssetFilesToDir(base_dir_android); // Copy assets from APK
#else
    snprintf(base_dir, sizeof(base_dir), "%s", FS_BASEDIR);
#endif

    // Set save and user paths
    snprintf(save_path, sizeof(save_path), "%s/save", base_dir);
    snprintf(user_path, sizeof(user_path), "%s/user", base_dir);

    mkdir(save_path, 0770);
    mkdir(user_path, 0770);
}

void load_config_file(void) {
    char config_file_path[1024] = {0};
    snprintf(config_file_path, sizeof(config_file_path), "%s/config.txt", save_path);

    if (access(config_file_path, F_OK) != -1) {
        configfile_load(config_file_path); // Load existing config
    } else {
        configfile_save(config_file_path); // Create default config
    }
}

void save_game_state(const char *state) {
    char state_file[1024] = {0};
    snprintf(state_file, sizeof(state_file), "%s/game_state.sav", save_path);

    FILE *file = fopen(state_file, "wb");
    if (file) {
        fwrite(state, sizeof(char), strlen(state), file);
        fclose(file);
    }
}

void load_game_state(char *buffer, size_t buffer_size) {
    char state_file[1024] = {0};
    snprintf(state_file, sizeof(state_file), "%s/game_state.sav", save_path);

    FILE *file = fopen(state_file, "rb");
    if (file) {
        fread(buffer, sizeof(char), buffer_size, file);
        fclose(file);
    }
}

int main(int argc, char *argv[]) {
    initialize_paths();

    printf("Base Directory: %s\n", base_dir);
    printf("Save Path: %s\n", save_path);
    printf("User Path: %s\n", user_path);

    // Load config file
    load_config_file();

    // Example of saving and loading game state
    const char *example_state = "example_game_state_data";
    save_game_state(example_state);

    char loaded_state[1024] = {0};
    load_game_state(loaded_state, sizeof(loaded_state));

    printf("Loaded State: %s\n", loaded_state);

    return 0;
}
