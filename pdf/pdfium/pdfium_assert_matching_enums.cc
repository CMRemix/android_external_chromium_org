// Copyright (c) 2010 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "base/basictypes.h"
#include "ppapi/c/pp_input_event.h"
#include "ppapi/c/private/ppb_pdf.h"
#include "third_party/pdfium/fpdfsdk/include/fpdf_fwlevent.h"
#include "third_party/pdfium/fpdfsdk/include/fpdf_sysfontinfo.h"
#include "ui/events/keycodes/keyboard_codes.h"

#define COMPILE_ASSERT_MATCH(np_name, pdfium_name) \
    COMPILE_ASSERT(int(np_name) == int(pdfium_name), mismatching_enums)

COMPILE_ASSERT_MATCH(PP_INPUTEVENT_MODIFIER_SHIFTKEY, FWL_EVENTFLAG_ShiftKey);
COMPILE_ASSERT_MATCH(PP_INPUTEVENT_MODIFIER_CONTROLKEY,
                     FWL_EVENTFLAG_ControlKey);
COMPILE_ASSERT_MATCH(PP_INPUTEVENT_MODIFIER_ALTKEY, FWL_EVENTFLAG_AltKey);
COMPILE_ASSERT_MATCH(PP_INPUTEVENT_MODIFIER_METAKEY, FWL_EVENTFLAG_MetaKey);
COMPILE_ASSERT_MATCH(PP_INPUTEVENT_MODIFIER_ISKEYPAD, FWL_EVENTFLAG_KeyPad);
COMPILE_ASSERT_MATCH(PP_INPUTEVENT_MODIFIER_ISAUTOREPEAT,
                     FWL_EVENTFLAG_AutoRepeat);
COMPILE_ASSERT_MATCH(PP_INPUTEVENT_MODIFIER_LEFTBUTTONDOWN,
                     FWL_EVENTFLAG_LeftButtonDown);
COMPILE_ASSERT_MATCH(PP_INPUTEVENT_MODIFIER_MIDDLEBUTTONDOWN,
                     FWL_EVENTFLAG_MiddleButtonDown);
COMPILE_ASSERT_MATCH(PP_INPUTEVENT_MODIFIER_RIGHTBUTTONDOWN,
                     FWL_EVENTFLAG_RightButtonDown);

COMPILE_ASSERT_MATCH(ui::VKEY_BACK, FWL_VKEY_Back);
COMPILE_ASSERT_MATCH(ui::VKEY_TAB, FWL_VKEY_Tab);
COMPILE_ASSERT_MATCH(ui::VKEY_CLEAR, FWL_VKEY_Clear);
COMPILE_ASSERT_MATCH(ui::VKEY_RETURN, FWL_VKEY_Return);
COMPILE_ASSERT_MATCH(ui::VKEY_SHIFT, FWL_VKEY_Shift);
COMPILE_ASSERT_MATCH(ui::VKEY_CONTROL, FWL_VKEY_Control);
COMPILE_ASSERT_MATCH(ui::VKEY_MENU, FWL_VKEY_Menu);
COMPILE_ASSERT_MATCH(ui::VKEY_PAUSE, FWL_VKEY_Pause);
COMPILE_ASSERT_MATCH(ui::VKEY_CAPITAL, FWL_VKEY_Capital);
COMPILE_ASSERT_MATCH(ui::VKEY_KANA, FWL_VKEY_Kana);
COMPILE_ASSERT_MATCH(ui::VKEY_HANGUL, FWL_VKEY_Hangul);
COMPILE_ASSERT_MATCH(ui::VKEY_JUNJA, FWL_VKEY_Junja);
COMPILE_ASSERT_MATCH(ui::VKEY_FINAL, FWL_VKEY_Final);
COMPILE_ASSERT_MATCH(ui::VKEY_HANJA, FWL_VKEY_Hanja);
COMPILE_ASSERT_MATCH(ui::VKEY_KANJI, FWL_VKEY_Kanji);
COMPILE_ASSERT_MATCH(ui::VKEY_ESCAPE, FWL_VKEY_Escape);
COMPILE_ASSERT_MATCH(ui::VKEY_CONVERT, FWL_VKEY_Convert);
COMPILE_ASSERT_MATCH(ui::VKEY_NONCONVERT, FWL_VKEY_NonConvert);
COMPILE_ASSERT_MATCH(ui::VKEY_ACCEPT, FWL_VKEY_Accept);
COMPILE_ASSERT_MATCH(ui::VKEY_MODECHANGE, FWL_VKEY_ModeChange);
COMPILE_ASSERT_MATCH(ui::VKEY_SPACE, FWL_VKEY_Space);
COMPILE_ASSERT_MATCH(ui::VKEY_PRIOR, FWL_VKEY_Prior);
COMPILE_ASSERT_MATCH(ui::VKEY_NEXT, FWL_VKEY_Next);
COMPILE_ASSERT_MATCH(ui::VKEY_END, FWL_VKEY_End);
COMPILE_ASSERT_MATCH(ui::VKEY_HOME, FWL_VKEY_Home);
COMPILE_ASSERT_MATCH(ui::VKEY_LEFT, FWL_VKEY_Left);
COMPILE_ASSERT_MATCH(ui::VKEY_UP, FWL_VKEY_Up);
COMPILE_ASSERT_MATCH(ui::VKEY_RIGHT, FWL_VKEY_Right);
COMPILE_ASSERT_MATCH(ui::VKEY_DOWN, FWL_VKEY_Down);
COMPILE_ASSERT_MATCH(ui::VKEY_SELECT, FWL_VKEY_Select);
COMPILE_ASSERT_MATCH(ui::VKEY_PRINT, FWL_VKEY_Print);
COMPILE_ASSERT_MATCH(ui::VKEY_EXECUTE, FWL_VKEY_Execute);
COMPILE_ASSERT_MATCH(ui::VKEY_SNAPSHOT, FWL_VKEY_Snapshot);
COMPILE_ASSERT_MATCH(ui::VKEY_INSERT, FWL_VKEY_Insert);
COMPILE_ASSERT_MATCH(ui::VKEY_DELETE, FWL_VKEY_Delete);
COMPILE_ASSERT_MATCH(ui::VKEY_HELP, FWL_VKEY_Help);
COMPILE_ASSERT_MATCH(ui::VKEY_0, FWL_VKEY_0);
COMPILE_ASSERT_MATCH(ui::VKEY_1, FWL_VKEY_1);
COMPILE_ASSERT_MATCH(ui::VKEY_2, FWL_VKEY_2);
COMPILE_ASSERT_MATCH(ui::VKEY_3, FWL_VKEY_3);
COMPILE_ASSERT_MATCH(ui::VKEY_4, FWL_VKEY_4);
COMPILE_ASSERT_MATCH(ui::VKEY_5, FWL_VKEY_5);
COMPILE_ASSERT_MATCH(ui::VKEY_6, FWL_VKEY_6);
COMPILE_ASSERT_MATCH(ui::VKEY_7, FWL_VKEY_7);
COMPILE_ASSERT_MATCH(ui::VKEY_8, FWL_VKEY_8);
COMPILE_ASSERT_MATCH(ui::VKEY_9, FWL_VKEY_9);
COMPILE_ASSERT_MATCH(ui::VKEY_A, FWL_VKEY_A);
COMPILE_ASSERT_MATCH(ui::VKEY_B, FWL_VKEY_B);
COMPILE_ASSERT_MATCH(ui::VKEY_C, FWL_VKEY_C);
COMPILE_ASSERT_MATCH(ui::VKEY_D, FWL_VKEY_D);
COMPILE_ASSERT_MATCH(ui::VKEY_E, FWL_VKEY_E);
COMPILE_ASSERT_MATCH(ui::VKEY_F, FWL_VKEY_F);
COMPILE_ASSERT_MATCH(ui::VKEY_G, FWL_VKEY_G);
COMPILE_ASSERT_MATCH(ui::VKEY_H, FWL_VKEY_H);
COMPILE_ASSERT_MATCH(ui::VKEY_I, FWL_VKEY_I);
COMPILE_ASSERT_MATCH(ui::VKEY_J, FWL_VKEY_J);
COMPILE_ASSERT_MATCH(ui::VKEY_K, FWL_VKEY_K);
COMPILE_ASSERT_MATCH(ui::VKEY_L, FWL_VKEY_L);
COMPILE_ASSERT_MATCH(ui::VKEY_M, FWL_VKEY_M);
COMPILE_ASSERT_MATCH(ui::VKEY_N, FWL_VKEY_N);
COMPILE_ASSERT_MATCH(ui::VKEY_O, FWL_VKEY_O);
COMPILE_ASSERT_MATCH(ui::VKEY_P, FWL_VKEY_P);
COMPILE_ASSERT_MATCH(ui::VKEY_Q, FWL_VKEY_Q);
COMPILE_ASSERT_MATCH(ui::VKEY_R, FWL_VKEY_R);
COMPILE_ASSERT_MATCH(ui::VKEY_S, FWL_VKEY_S);
COMPILE_ASSERT_MATCH(ui::VKEY_T, FWL_VKEY_T);
COMPILE_ASSERT_MATCH(ui::VKEY_U, FWL_VKEY_U);
COMPILE_ASSERT_MATCH(ui::VKEY_V, FWL_VKEY_V);
COMPILE_ASSERT_MATCH(ui::VKEY_W, FWL_VKEY_W);
COMPILE_ASSERT_MATCH(ui::VKEY_X, FWL_VKEY_X);
COMPILE_ASSERT_MATCH(ui::VKEY_Y, FWL_VKEY_Y);
COMPILE_ASSERT_MATCH(ui::VKEY_Z, FWL_VKEY_Z);
COMPILE_ASSERT_MATCH(ui::VKEY_LWIN, FWL_VKEY_LWin);
COMPILE_ASSERT_MATCH(ui::VKEY_COMMAND, FWL_VKEY_Command);
COMPILE_ASSERT_MATCH(ui::VKEY_RWIN, FWL_VKEY_RWin);
COMPILE_ASSERT_MATCH(ui::VKEY_APPS, FWL_VKEY_Apps);
COMPILE_ASSERT_MATCH(ui::VKEY_SLEEP, FWL_VKEY_Sleep);
COMPILE_ASSERT_MATCH(ui::VKEY_NUMPAD0, FWL_VKEY_NumPad0);
COMPILE_ASSERT_MATCH(ui::VKEY_NUMPAD1, FWL_VKEY_NumPad1);
COMPILE_ASSERT_MATCH(ui::VKEY_NUMPAD2, FWL_VKEY_NumPad2);
COMPILE_ASSERT_MATCH(ui::VKEY_NUMPAD3, FWL_VKEY_NumPad3);
COMPILE_ASSERT_MATCH(ui::VKEY_NUMPAD4, FWL_VKEY_NumPad4);
COMPILE_ASSERT_MATCH(ui::VKEY_NUMPAD5, FWL_VKEY_NumPad5);
COMPILE_ASSERT_MATCH(ui::VKEY_NUMPAD6, FWL_VKEY_NumPad6);
COMPILE_ASSERT_MATCH(ui::VKEY_NUMPAD7, FWL_VKEY_NumPad7);
COMPILE_ASSERT_MATCH(ui::VKEY_NUMPAD8, FWL_VKEY_NumPad8);
COMPILE_ASSERT_MATCH(ui::VKEY_NUMPAD9, FWL_VKEY_NumPad9);
COMPILE_ASSERT_MATCH(ui::VKEY_MULTIPLY, FWL_VKEY_Multiply);
COMPILE_ASSERT_MATCH(ui::VKEY_ADD, FWL_VKEY_Add);
COMPILE_ASSERT_MATCH(ui::VKEY_SEPARATOR, FWL_VKEY_Separator);
COMPILE_ASSERT_MATCH(ui::VKEY_SUBTRACT, FWL_VKEY_Subtract);
COMPILE_ASSERT_MATCH(ui::VKEY_DECIMAL, FWL_VKEY_Decimal);
COMPILE_ASSERT_MATCH(ui::VKEY_DIVIDE, FWL_VKEY_Divide);
COMPILE_ASSERT_MATCH(ui::VKEY_F1, FWL_VKEY_F1);
COMPILE_ASSERT_MATCH(ui::VKEY_F2, FWL_VKEY_F2);
COMPILE_ASSERT_MATCH(ui::VKEY_F3, FWL_VKEY_F3);
COMPILE_ASSERT_MATCH(ui::VKEY_F4, FWL_VKEY_F4);
COMPILE_ASSERT_MATCH(ui::VKEY_F5, FWL_VKEY_F5);
COMPILE_ASSERT_MATCH(ui::VKEY_F6, FWL_VKEY_F6);
COMPILE_ASSERT_MATCH(ui::VKEY_F7, FWL_VKEY_F7);
COMPILE_ASSERT_MATCH(ui::VKEY_F8, FWL_VKEY_F8);
COMPILE_ASSERT_MATCH(ui::VKEY_F9, FWL_VKEY_F9);
COMPILE_ASSERT_MATCH(ui::VKEY_F10, FWL_VKEY_F10);
COMPILE_ASSERT_MATCH(ui::VKEY_F11, FWL_VKEY_F11);
COMPILE_ASSERT_MATCH(ui::VKEY_F12, FWL_VKEY_F12);
COMPILE_ASSERT_MATCH(ui::VKEY_F13, FWL_VKEY_F13);
COMPILE_ASSERT_MATCH(ui::VKEY_F14, FWL_VKEY_F14);
COMPILE_ASSERT_MATCH(ui::VKEY_F15, FWL_VKEY_F15);
COMPILE_ASSERT_MATCH(ui::VKEY_F16, FWL_VKEY_F16);
COMPILE_ASSERT_MATCH(ui::VKEY_F17, FWL_VKEY_F17);
COMPILE_ASSERT_MATCH(ui::VKEY_F18, FWL_VKEY_F18);
COMPILE_ASSERT_MATCH(ui::VKEY_F19, FWL_VKEY_F19);
COMPILE_ASSERT_MATCH(ui::VKEY_F20, FWL_VKEY_F20);
COMPILE_ASSERT_MATCH(ui::VKEY_F21, FWL_VKEY_F21);
COMPILE_ASSERT_MATCH(ui::VKEY_F22, FWL_VKEY_F22);
COMPILE_ASSERT_MATCH(ui::VKEY_F23, FWL_VKEY_F23);
COMPILE_ASSERT_MATCH(ui::VKEY_F24, FWL_VKEY_F24);
COMPILE_ASSERT_MATCH(ui::VKEY_NUMLOCK, FWL_VKEY_NunLock);
COMPILE_ASSERT_MATCH(ui::VKEY_SCROLL, FWL_VKEY_Scroll);
COMPILE_ASSERT_MATCH(ui::VKEY_LSHIFT, FWL_VKEY_LShift);
COMPILE_ASSERT_MATCH(ui::VKEY_RSHIFT, FWL_VKEY_RShift);
COMPILE_ASSERT_MATCH(ui::VKEY_LCONTROL, FWL_VKEY_LControl);
COMPILE_ASSERT_MATCH(ui::VKEY_RCONTROL, FWL_VKEY_RControl);
COMPILE_ASSERT_MATCH(ui::VKEY_LMENU, FWL_VKEY_LMenu);
COMPILE_ASSERT_MATCH(ui::VKEY_RMENU, FWL_VKEY_RMenu);
COMPILE_ASSERT_MATCH(ui::VKEY_BROWSER_BACK, FWL_VKEY_BROWSER_Back);
COMPILE_ASSERT_MATCH(ui::VKEY_BROWSER_FORWARD, FWL_VKEY_BROWSER_Forward);
COMPILE_ASSERT_MATCH(ui::VKEY_BROWSER_REFRESH, FWL_VKEY_BROWSER_Refresh);
COMPILE_ASSERT_MATCH(ui::VKEY_BROWSER_STOP, FWL_VKEY_BROWSER_Stop);
COMPILE_ASSERT_MATCH(ui::VKEY_BROWSER_SEARCH, FWL_VKEY_BROWSER_Search);
COMPILE_ASSERT_MATCH(ui::VKEY_BROWSER_FAVORITES, FWL_VKEY_BROWSER_Favorites);
COMPILE_ASSERT_MATCH(ui::VKEY_BROWSER_HOME, FWL_VKEY_BROWSER_Home);
COMPILE_ASSERT_MATCH(ui::VKEY_VOLUME_MUTE, FWL_VKEY_VOLUME_Mute);
COMPILE_ASSERT_MATCH(ui::VKEY_VOLUME_DOWN, FWL_VKEY_VOLUME_Down);
COMPILE_ASSERT_MATCH(ui::VKEY_VOLUME_UP, FWL_VKEY_VOLUME_Up);
COMPILE_ASSERT_MATCH(ui::VKEY_MEDIA_NEXT_TRACK, FWL_VKEY_MEDIA_NEXT_Track);
COMPILE_ASSERT_MATCH(ui::VKEY_MEDIA_PREV_TRACK, FWL_VKEY_MEDIA_PREV_Track);
COMPILE_ASSERT_MATCH(ui::VKEY_MEDIA_STOP, FWL_VKEY_MEDIA_Stop);
COMPILE_ASSERT_MATCH(ui::VKEY_MEDIA_PLAY_PAUSE, FWL_VKEY_MEDIA_PLAY_Pause);
COMPILE_ASSERT_MATCH(ui::VKEY_MEDIA_LAUNCH_MAIL, FWL_VKEY_MEDIA_LAUNCH_Mail);
COMPILE_ASSERT_MATCH(ui::VKEY_MEDIA_LAUNCH_MEDIA_SELECT,
                     FWL_VKEY_MEDIA_LAUNCH_MEDIA_Select);
COMPILE_ASSERT_MATCH(ui::VKEY_MEDIA_LAUNCH_APP1, FWL_VKEY_MEDIA_LAUNCH_APP1);
COMPILE_ASSERT_MATCH(ui::VKEY_MEDIA_LAUNCH_APP2, FWL_VKEY_MEDIA_LAUNCH_APP2);
COMPILE_ASSERT_MATCH(ui::VKEY_OEM_1, FWL_VKEY_OEM_1);
COMPILE_ASSERT_MATCH(ui::VKEY_OEM_PLUS, FWL_VKEY_OEM_Plus);
COMPILE_ASSERT_MATCH(ui::VKEY_OEM_COMMA, FWL_VKEY_OEM_Comma);
COMPILE_ASSERT_MATCH(ui::VKEY_OEM_MINUS, FWL_VKEY_OEM_Minus);
COMPILE_ASSERT_MATCH(ui::VKEY_OEM_PERIOD, FWL_VKEY_OEM_Period);
COMPILE_ASSERT_MATCH(ui::VKEY_OEM_2, FWL_VKEY_OEM_2);
COMPILE_ASSERT_MATCH(ui::VKEY_OEM_3, FWL_VKEY_OEM_3);
COMPILE_ASSERT_MATCH(ui::VKEY_OEM_4, FWL_VKEY_OEM_4);
COMPILE_ASSERT_MATCH(ui::VKEY_OEM_5, FWL_VKEY_OEM_5);
COMPILE_ASSERT_MATCH(ui::VKEY_OEM_6, FWL_VKEY_OEM_6);
COMPILE_ASSERT_MATCH(ui::VKEY_OEM_7, FWL_VKEY_OEM_7);
COMPILE_ASSERT_MATCH(ui::VKEY_OEM_8, FWL_VKEY_OEM_8);
COMPILE_ASSERT_MATCH(ui::VKEY_OEM_102, FWL_VKEY_OEM_102);
COMPILE_ASSERT_MATCH(ui::VKEY_PROCESSKEY, FWL_VKEY_ProcessKey);
COMPILE_ASSERT_MATCH(ui::VKEY_PACKET, FWL_VKEY_Packet);
COMPILE_ASSERT_MATCH(ui::VKEY_ATTN, FWL_VKEY_Attn);
COMPILE_ASSERT_MATCH(ui::VKEY_CRSEL, FWL_VKEY_Crsel);
COMPILE_ASSERT_MATCH(ui::VKEY_EXSEL, FWL_VKEY_Exsel);
COMPILE_ASSERT_MATCH(ui::VKEY_EREOF, FWL_VKEY_Ereof);
COMPILE_ASSERT_MATCH(ui::VKEY_PLAY, FWL_VKEY_Play);
COMPILE_ASSERT_MATCH(ui::VKEY_ZOOM, FWL_VKEY_Zoom);
COMPILE_ASSERT_MATCH(ui::VKEY_NONAME, FWL_VKEY_NoName);
COMPILE_ASSERT_MATCH(ui::VKEY_PA1, FWL_VKEY_PA1);
COMPILE_ASSERT_MATCH(ui::VKEY_OEM_CLEAR, FWL_VKEY_OEM_Clear);
COMPILE_ASSERT_MATCH(ui::VKEY_UNKNOWN, FWL_VKEY_Unknown);

COMPILE_ASSERT_MATCH(PP_PRIVATEFONTCHARSET_ANSI, FXFONT_ANSI_CHARSET);
COMPILE_ASSERT_MATCH(PP_PRIVATEFONTCHARSET_DEFAULT, FXFONT_DEFAULT_CHARSET);
COMPILE_ASSERT_MATCH(PP_PRIVATEFONTCHARSET_SYMBOL, FXFONT_SYMBOL_CHARSET);
COMPILE_ASSERT_MATCH(PP_PRIVATEFONTCHARSET_SHIFTJIS, FXFONT_SHIFTJIS_CHARSET);
COMPILE_ASSERT_MATCH(PP_PRIVATEFONTCHARSET_HANGUL, FXFONT_HANGEUL_CHARSET);
COMPILE_ASSERT_MATCH(PP_PRIVATEFONTCHARSET_GB2312, FXFONT_GB2312_CHARSET);
COMPILE_ASSERT_MATCH(PP_PRIVATEFONTCHARSET_CHINESEBIG5,
                     FXFONT_CHINESEBIG5_CHARSET);
