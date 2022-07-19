/* See LICENSE file for copyright and license details. */

/* appearance */
static const int attachbelow = 1;               /* 1 means attach at the end */
static       unsigned int border 	= 0;
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int snap      = 10;       /* snap pixel */
static const unsigned int gappih    = 4;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 4;       /* vert inner gap between windows */
static const unsigned int gappoh    = 4;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 60;       /* vert outer gap between windows and screen edge */
static       int smartgaps          = 0;        /* 1 means no outer gap when there is only one window */
static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayonleft = 0;   	/* 0: systray in the right corner, >0: systray on left of status text */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray        = 1;        /* 0 means no systray */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 0;        /* 0 means bottom bar */
/* static const char *fonts[]          = { "Source Code Pro:style=Regular:size=9", "JoyPixels:style=Regular:size=8:antialias=true:autohint=true", "DejaVu Sans" }; */
static const char *fonts[]          = { "Victor Mono:style=SemiBold:size=9", "JoyPixels:style=Regular:size=8:antialias=true:autohint=true", "DejaVu Sans" };
static const char dmenufont[]          = "Victor Mono:style=SemiBold:size=9";
/* static const char dmenufont[]       = "DejaVuSansMono Nerd Font:style=Regular:size=9"; */
static const char col_gray1[]       = "#000000";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#cccccc";
static const char col_gray4[]       = "#eeeeee";
static const char col_gray5[]       = "#111111";
static const char col_darkmagenta[] = "#8B008B";
static const char col1[]            = "#bb0000";
static const char col2[]            = "#00ff00";
static const char col3[]            = "#0000ff";
static const char col4[]            = "#ffff00";
static const char col5[]            = "#ffff00";
static const char col6[]            = "#ffff00";

enum { SchemeNorm, SchemeCol1, SchemeCol2, SchemeCol3, SchemeCol4,
       SchemeCol5, SchemeCol6, SchemeSel, SchemeTitle }; /* color schemes */

static const char *colors[][3]      = {
	/*               fg         bg         border   */
	/* [SchemeNorm] = { col_gray3, col_gray1, col_gray2 }, */
	[SchemeSel]  = { col_gray4, col_darkmagenta,  col_darkmagenta  },
	[SchemeNorm]  = { col_gray3, col_gray1, col_gray1 },
	[SchemeCol1]  = { col1,      col_gray1, col_gray2 },
	[SchemeCol2]  = { col2,      col_gray1, col_gray2 },
	[SchemeCol3]  = { col3,      col_gray1, col_gray2 },
	[SchemeCol4]  = { col4,      col_gray1, col_gray2 },
	[SchemeCol5]  = { col5,      col_gray1, col_gray2 },
	[SchemeCol6]  = { col6,      col_gray1, col_gray2 },
	[SchemeSel]   = { col_gray4, col_darkmagenta,  "#535353"  },
	[SchemeTitle]  = { col_gray4, "#222222",  col_darkmagenta  },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "0" };
static const int initlayouts[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2 };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
/*  class                instance         title    tags mask    isfloating    monitor    float x,y,w,h    floatborderpx*/
    { "Gimp",            NULL,            NULL,    1<<6,        0,            -1,        50,50,500,500,   0 },
    { "calculator",      NULL,            NULL,    0,           1,            -1,        80,50,680,592,   0 },
    { "floating",        NULL,            NULL,    0,           1,            -1,        80,50,800,600,   0 },
    { "scratchpad",      NULL,            NULL,    0,           1,            -1,        80,50,1280,900,  0 },
    { "qBittorrent",     "qbittorrent",   NULL,    1<<7,        0,            -1,        80,50,800,600,   0 },
    { "discord",         NULL,            NULL,    1<<8,        0,            -1,        80,50,800,600,   0 },
    { "easyeffects",     NULL,            NULL,    1<<9,        0,            -1,        80,50,800,600,   0 },
    { "TelegramDesktop", NULL,            NULL,    1<<8,        0,            -1,        80,50,800,600,   0 },
    { "telegram-desktop",NULL,            NULL,    1<<8,        0,            -1,        80,50,800,600,   0 },
};

/* layout(s) */
static const float mfact     = 0.5; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

#define FORCE_VSPLIT 1  /* nrowgrid layout: force two clients to always split vertically */
#include "vanitygaps.c"

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
	/* { "[@]",      spiral }, */
	/* { "[\\]",     dwindle }, */
	{ "H[]",      deck },
	{ "TTT",      bstack },
	{ "===",      bstackhoriz },
	{ "HHH",      grid },
	{ "###",      nrowgrid },
	{ "---",      horizgrid },
	{ ":::",      gaplessgrid },
	{ "|M|",      centeredmaster },
	{ ">M>",      centeredfloatingmaster },
	{ NULL,       NULL },
};

/* key definitions */
#define MODKEY Mod4Mask
#define MOD2KEY Mod1Mask	/* MOD2KEY to altkey	*/

#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
/* static const char *dmenucmd[] = { "dmenu_run_history", "-h", "16", "-b", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_darkmagenta, "-sf", col_gray4, NULL }; */
static const char *dmenucmd[] = { "dmenu_centered", NULL };
static const char *termcmd[]  = { "kitty", NULL };
static const char *webcmd[]  = { "firefox", NULL };
static const char *ftermcmd[]  = { "kitty", "--class", "floating", NULL };
static const char *filescmd[]  = { "alacritty", "-e", "ranger", NULL };
static const char *gfilescmd[]  = { "dolphin", NULL };
static const char *bookscmd[] = { "openbook", "-nb", col_gray1, "-nf", col_gray3, "-sb", col_darkmagenta, "-sf", col_gray4, NULL };
static const char *spotifycmd[]  = { "spotify", NULL };
static const char *virtualboxcmd[]  = { "virtualbox", NULL };
static const char *calccmd[]  = { "gnome-calculator", NULL };
static const char *lutriscmd[]  = { "lutris", NULL };
static const char *switchkblayout[]  = { "switchkblayout", NULL };
static const char *lockscreen[]  = { "lockscreen", NULL };

/* static const char scratchpadname[] = "scratchpad"; */
/* static const char *scratchpadcmd[] = { "st", "-t", scratchpadname, "-g", "120x34", NULL }; */

static const char scratchpadname[] = "scratchpad";
static const char *scratchpadcmd[] = { "kitty", "--title", scratchpadname, "--class", "scratchpad", "--session", "/home/mk/.config/kitty/sessions/scratchpad", NULL };
/* tatic const char *scratchpadcmd[] = { "kitty", "--title", scratchpadname, "--class", "scratchpad", NULL }; */

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_d,      spawn,          {.v = dmenucmd } },
	{ MODKEY,		                XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY|ShiftMask,	            XK_Return, spawn,          {.v = ftermcmd } },
	{ MODKEY,		                XK_w,	   spawn,          {.v = webcmd } },
	{ MODKEY,		                XK_e,	   spawn,          {.v = gfilescmd } },
	{ MODKEY,		                XK_z,	   spawn,          {.v = lutriscmd } },
	{ MODKEY|ShiftMask,		        XK_e,	   spawn,          {.v = filescmd } },
	{ MODKEY,		                XK_v,	   spawn,          {.v = virtualboxcmd } },
	{ MODKEY,		                XK_b,	   spawn,          {.v = bookscmd } },
	{ MODKEY,		                XK_s,	   spawn,          {.v = spotifycmd } },
	{ MODKEY,		                XK_c,	   spawn,          {.v = calccmd } },
	{ MODKEY|MOD2KEY,		        XK_l,	   spawn,          {.v = switchkblayout } },
	{ MODKEY,				        XK_x,	   spawn,          {.v = lockscreen } },
	{ MODKEY,                       XK_grave,  togglescratch,  {.v = scratchpadcmd } },
	{ MODKEY|ShiftMask,             XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_j,      zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY,			            XK_q,      killclient,     {0} },

	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY|ShiftMask,             XK_m,      setlayout,      {.v = &layouts[3]} },
	{ MODKEY|ControlMask,           XK_y,      setlayout,      {.v = &layouts[4]} },
	{ MODKEY|ControlMask,           XK_u,      setlayout,      {.v = &layouts[5]} },
	{ MODKEY|ControlMask,           XK_i,      setlayout,      {.v = &layouts[6]} },
	{ MODKEY|ControlMask,           XK_o,      setlayout,      {.v = &layouts[7]} },
	{ MODKEY|ControlMask,           XK_p,      setlayout,      {.v = &layouts[8]} },

	{ MODKEY|ShiftMask|ControlMask, XK_y,      setlayout,      {.v = &layouts[9]} },
	{ MODKEY|ShiftMask|ControlMask, XK_u,      setlayout,      {.v = &layouts[10]} },
	{ MODKEY|ShiftMask|ControlMask, XK_i,      setlayout,      {.v = &layouts[11]} },

	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	/* { MODKEY,                       XK_0,      view,           {.ui = ~0 } }, */
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },

	/* gaps control */
	{ MODKEY|MOD2KEY,               XK_3,      incrgaps,       {.i = +1 } },
	{ MODKEY|MOD2KEY|ShiftMask,     XK_3,      incrgaps,       {.i = -1 } },
	{ MODKEY|MOD2KEY,               XK_4,      incrigaps,      {.i = +1 } },
	{ MODKEY|MOD2KEY|ShiftMask,     XK_4,      incrigaps,      {.i = -1 } },
	{ MODKEY|MOD2KEY,               XK_5,      incrogaps,      {.i = +1 } },
	{ MODKEY|MOD2KEY|ShiftMask,     XK_5,      incrogaps,      {.i = -1 } },
	{ MODKEY|MOD2KEY,               XK_6,      incrihgaps,     {.i = +1 } },
	{ MODKEY|MOD2KEY|ShiftMask,     XK_6,      incrihgaps,     {.i = -1 } },
	{ MODKEY|MOD2KEY,               XK_7,      incrivgaps,     {.i = +1 } },
	{ MODKEY|MOD2KEY|ShiftMask,     XK_7,      incrivgaps,     {.i = -1 } },
	{ MODKEY|MOD2KEY,               XK_8,      incrohgaps,     {.i = +1 } },
	{ MODKEY|MOD2KEY|ShiftMask,     XK_8,      incrohgaps,     {.i = -1 } },
	{ MODKEY|MOD2KEY,               XK_9,      incrovgaps,     {.i = +1 } },
	{ MODKEY|MOD2KEY|ShiftMask,     XK_9,      incrovgaps,     {.i = -1 } },
	{ MODKEY|MOD2KEY,               XK_0,      togglegaps,     {0} },
	{ MODKEY|MOD2KEY,               XK_m,      toggle_border,  {0} },
	{ MODKEY,                       XK_equal,  defaultgaps,    {0} },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	TAGKEYS(                        XK_0,                      9)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button1,        sigdwmblocks,   {.i = 1} },
	{ ClkStatusText,        0,              Button2,        sigdwmblocks,   {.i = 2} },
	{ ClkStatusText,        0,              Button3,        sigdwmblocks,   {.i = 3} },
	{ ClkStatusText,        0,              Button4,        sigdwmblocks,   {.i = 4} },
	{ ClkStatusText,        0,              Button5,        sigdwmblocks,   {.i = 5} },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
