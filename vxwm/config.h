#pragma once

/* See LICENSE file for copyright and license details. */

/* --- 1. Appearance & Hardware Settings --- */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 0;        /* 1 means space is reserved for the bar */
static const int topbar             = 0;        /* 1 means bar is at the top */
static const char *fonts[]          = { "JetBrains Mono:size=11" };
static const char dmenufont[]       = "JetBrains Mono:size=11";

/* Transparent-ish "Ghost" colors to keep Polybar visible */
static MAYBE_CONST char normbgcolor[]           = "#000000";
static MAYBE_CONST char normbordercolor[]       = "#444444";
static MAYBE_CONST char normfgcolor[]           = "#000000";
static MAYBE_CONST char selfgcolor[]            = "#000000";
static MAYBE_CONST char selbordercolor[]        = "#bd93f9";
static MAYBE_CONST char selbgcolor[]            = "#000000";
static MAYBE_CONST char *colors[][3] = {
       [SchemeNorm] = { normfgcolor, normbgcolor, normbordercolor },
       [SchemeSel]  = { selfgcolor,  selbgcolor,  selbordercolor  },
};

#define CENTER_NEW_FLOATING_WINDOWS 1 
#define NEW_FLOATING_WINDOWS_APPEAR_UNDER_CURSOR 0 

/* --- 2. Patch-specific Variables --- */
static const unsigned int gappx = 20;   
static const int user_bh = 32;         /* Reserved height for Polybar */
static const int vertpad = 5;          
static const int sidepad = 5;          
static const int refreshrate = 60;    

/* --- 3. Tagging & Layouts --- */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
    { "Gimp",     NULL,       NULL,       0,            1,           -1 },
    { "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
};

static const float mfact     = 0.55; 
static const int nmaster     = 1;    
static const int resizehints = 1;    
static const int lockfullscreen = 1; 

static const Layout layouts[] = {
    { "[]=",      tile },    
    { "><>",      NULL },    
    { "[M]",      monocle },
};

/* --- 4. Key & Command Definitions --- */
#define MODKEY Mod4Mask  /* Win/Super Key */
#define ALTERNATE_MODKEY Mod1Mask

#define TAGKEYS(KEY,TAG) \
    { MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
    { MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* Commands */
static char dmenumon[2] = "0"; /* FIX: Re-added this variable to satisfy vxwm.c */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, NULL };
static const char *termcmd[]  = { "st", NULL };
static const char *roficmd[]  = { "rofi", "-show", "drun", NULL };

static const Key keys[] = {
    /* modifier                     key        function        argument */
    { MODKEY,                       XK_q,      spawn,          {.v = termcmd } },
    { MODKEY,                       XK_d,      spawn,          {.v = roficmd } },
    { MODKEY,                       XK_c,      killclient,     {0} },
    { MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
    { MODKEY,                       XK_b,      togglebar,      {0} },
    { MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
    { MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
    { MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
    { MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
    { MODKEY,                       XK_Return, zoom,           {0} },
    { MODKEY,                       XK_Tab,    view,           {0} },
    { MODKEY,                       XK_f,      togglefullscr,  {0} },
    { MODKEY,                       XK_space,  setlayout,      {0} },
    { MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
    { MODKEY|ShiftMask,             XK_q,      quit,           {0} },

    /* Workspace Keys */
    TAGKEYS(                        XK_1,                      0)
    TAGKEYS(                        XK_2,                      1)
    TAGKEYS(                        XK_3,                      2)
    TAGKEYS(                        XK_4,                      3)
    TAGKEYS(                        XK_5,                      4)
    TAGKEYS(                        XK_6,                      5)
    TAGKEYS(                        XK_7,                      6)
    TAGKEYS(                        XK_8,                      7)
    TAGKEYS(                        XK_9,                      8)

    /* Infinite Canvas Movement (Keyboard) */
    { MODKEY,                       XK_r,      homecanvas,     {0} },
    { MODKEY|ShiftMask,             XK_Left,   movecanvas,     {.i = 0} }, 
    { MODKEY|ShiftMask,             XK_Right,  movecanvas,     {.i = 1} }, 
    { MODKEY|ShiftMask,             XK_Up,     movecanvas,     {.i = 2} }, 
    { MODKEY|ShiftMask,             XK_Down,   movecanvas,     {.i = 3} }, 
};

/* --- 5. Mouse Definitions --- */
static const Button buttons[] = {
    /* Mod + Shift + Left Click = Fly/Pan Camera */
    { ClkRootWin,           MODKEY|ShiftMask, Button1,      movecanvasmouse, {.f = 1.5 } }, 
    { ClkClientWin,         MODKEY|ShiftMask, Button1,      movecanvasmouse, {.f = 1.5 } },

    { ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
    { ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
    { ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
    { ClkTagBar,            0,              Button1,        view,           {0} },
    { ClkTagBar,            0,              Button3,        toggleview,     {0} },
};
