// Global pointer to sprite vram
extern int sprite_head_gfx;

// How far out should the joystick be allowed to move
#define OFFSET 24 

//{{BLOCK(bottom_screen)

//======================================================================
//
//	bottom_screen, 256x192@8, 
//	+ palette 200 entries, lz77 compressed
//	+ 47 tiles (t|f reduced) lz77 compressed
//	+ regular map (flat), lz77 compressed, 32x24 
//	Total size: 400 + 1416 + 300 = 2116
//
//	Time-stamp: 2023-12-16, 15:01:15
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_BOTTOM_SCREEN_H
#define GRIT_BOTTOM_SCREEN_H

#define bottom_screenTilesLen 1416
extern const unsigned int bottom_screenTiles[354];

#define bottom_screenMapLen 300
extern const unsigned short bottom_screenMap[150];

#define bottom_screenPalLen 400
extern const unsigned short bottom_screenPal[200];

#endif // GRIT_BOTTOM_SCREEN_H

//}}BLOCK(bottom_screen)

//{{BLOCK(joysticks)

//======================================================================
//
//	joysticks, 64x128@8, 
//	+ palette 256 entries, not compressed
//	+ 128 tiles not compressed
//	Total size: 512 + 8192 = 8704
//
//	Time-stamp: 2023-12-16, 14:52:21
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_JOYSTICKS_H
#define GRIT_JOYSTICKS_H

#define joysticksTilesLen 8192
extern const unsigned int joysticksTiles[2048];

#define joysticksPalLen 512
extern const unsigned short joysticksPal[256];

#endif // GRIT_JOYSTICKS_H

//}}BLOCK(joysticks)
