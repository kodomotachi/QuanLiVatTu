#pragma once
#include "graphics.h"
#pragma comment(lib, "graphics.lib")

#ifndef DEFINE_H
#define DEFINE_H

// SCREEN
#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

// BACKGROUND COLOR
#define BACKGROUND_COLOR COLOR(255, 246, 245)
#define DISABLE_COLOR COLOR(127,124,132) 

// SUBWINDOW
#define SUBWINDOW_LEFT 25
#define SUBWINDOW_TOP 100
#define SUBWINDOW_RIGHT 1255
#define SUBWINDOW_BOTTOM 680
#define SUBWINDOW_BACKGROUND COLOR(237, 242, 247)

// BUTTON
#define BUTTON_WIDTN 50
#define BUTTON_PAGE COLOR(190, 193, 196)
#define BUTTON_BACKGROUND COLOR(167, 206, 225)
#define BUTTON_TEXT_COLOR COLOR(52, 113, 235)

// BORDER
#define LEFT_BORDER 125
#define TOP_BORDER 150
#define RIGHT_BORDER 1155
#define BOTTOM_BORDER 560

// EDIT TEXT
#define EDITTEXT_WIDTH 500
#define EDITTEXT_MIN_WIDTH 70
#define EDITTEXT_HEIGHT 40
#define EDITEXT_TEXT_COLOR COLOR(0, 133, 190)
#define EDITTEXT_TITLE_COLOR COLOR(145, 84, 229)
#define EDITEXT_ON_SELECTED_COLOR COLOR(191, 207, 255)
#define EDITEXT_BACKGROUND_COLOR COLOR(227, 228, 230)
#define EDITEXT_HINT_COLOR COLOR(137, 137, 137)
#define EDITEXT_INPUT_COLOR COLOR(222, 222, 224)
#define EDITTEXT_SPACE 80

// TICKET TAB
#define TICKET_AVAI COLOR(144, 151, 155)
#define TICKET_NOT_AVAI COLOR(255, 136, 136)

// TAB
#define MAX_TAB 5
#define TAB_DEFAULT_BACKGROUND COLOR(241, 208, 215)


#endif