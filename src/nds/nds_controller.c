#include "nds_include.h"

#include "lib/src/osContInternal.h"

// Global gfx pointer for joystick head
#include "nds/gfx.h"


extern u8 nds_audio_state;

s32 osContInit(UNUSED OSMesgQueue *mq, u8 *controllerBits, UNUSED OSContStatus *status) {
    *controllerBits = 1;
    return 0;
}

s32 osContStartReadData(UNUSED OSMesgQueue *mesg) {
    return 0;
}

void osContGetReadData(OSContPad *pad) {
    pad->button = 0;
    pad->stick_x = 0;
    pad->stick_y = 0;

    scanKeys();
    const u32 keys = keysHeld();

    if (keys & KEY_A) {
        pad->button |= A_BUTTON;
    }
    if (keys & KEY_B) {
        pad->button |= B_BUTTON;
    }
    if (keys & KEY_X) {
        pad->button |= U_CBUTTONS;
    }
    if (keys & KEY_Y) {
        pad->button |= D_CBUTTONS;
    }
    if (keys & KEY_START) {
        pad->button |= START_BUTTON;
    }
    if (keys & KEY_L) {
        pad->button |= R_TRIG;
    }
    if (keys & KEY_R) {
        pad->button |= Z_TRIG;
    }

    if (keys & KEY_UP) {
        pad->stick_y = 80;
    }
    if (keys & KEY_DOWN) {
        pad->stick_y = -80;
    }
    if (keys & KEY_LEFT) {
        pad->stick_x = -80;
    }
    if (keys & KEY_RIGHT) {
        pad->stick_x = 80;
    }

    if (keys & KEY_TOUCH) {
        touchPosition pos;
        touchRead(&pos);
        pad->button |= (pos.px <= 64) ? L_CBUTTONS : 0;
        pad->button |= (pos.px >= 192) ? R_CBUTTONS : 0;

        if (pos.px > 48 && pos.px < 208) {
            s16 rel_x = pos.px - 256/2;
            s16 rel_y = pos.py - 192/2;

            s32 f_x = inttof32(rel_x);
            s32 f_y = inttof32(rel_y);

            s32 f_magnitude = sqrtf32(mulf32(f_x, f_x) + mulf32(f_y, f_y));

            s32 f_scale = (inttof32(OFFSET) > f_magnitude) ? inttof32(OFFSET) : f_magnitude;

            f_x = divf32(f_x, f_scale);
            f_y = divf32(f_y, f_scale);

            pad->stick_x = f32toint(f_x * 80);
            pad->stick_y = -f32toint(f_y * 80);

            oamSet(&oamSub,
                0,
                f32toint(f_x * OFFSET) + 96, f32toint(f_y * OFFSET) + 64,
                0,
                0,
                SpriteSize_64x64,
                SpriteColorFormat_256Color,
                sprite_head_gfx,
                -1,
                false,
                false,
                false, false,
                false
              );
            oamUpdate(&oamSub);
        }
    } else {
      oamSet(&oamSub,
          0,
          96, 64,
          0,
          0,
          SpriteSize_64x64,
          SpriteColorFormat_256Color,
          sprite_head_gfx,
          -1,
          false,
          false,
          false, false,
          false
        );
      oamUpdate(&oamSub);
    }

    if (keysDown() & KEY_SELECT) {
        nds_audio_state = !nds_audio_state;
    }
}
