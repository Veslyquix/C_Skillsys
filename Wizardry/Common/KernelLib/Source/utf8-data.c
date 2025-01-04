#include <common-chax.h>
#include <kernel-lib.h>

#include "kernel-lib-internal.h"

const struct AutoNarrowFontEnt AutoNarrowFontConf[0x100] = {
	['a'] = { "\xe1\xb5\x83\0" }, 
	['b'] = { "\xe1\xb5\x87\0" }, 
	['c'] = { "\xe1\xb6\x9c\0" }, 
	['d'] = { "\xe1\xb5\x88\0" }, 
	['e'] = { "\xe1\xb5\x89\0" }, 
	['f'] = { "\xe1\xb6\xa0\0" }, 
	['g'] = { "\xe1\xb5\x8d\0" }, 
	['h'] = { "\xca\xb0\0" }, 
	['k'] = { "\xe1\xb5\x8f\0" }, 
	['n'] = { "\xe2\x81\xbf\0" }, 
	['o'] = { "\xe1\xb5\x92\0" }, 
	['p'] = { "\xe1\xb5\x96\0" }, 
	['q'] = { "\xe1\xb5\xa0\0" }, 
	['r'] = { "\xca\xb3\0" }, 
	['s'] = { "\xcb\xa2\0" }, 
	['t'] = { "\xe1\xb5\x97\0" }, 
	['u'] = { "\xe1\xb5\x98\0" }, 
	['v'] = { "\xe1\xb5\x9b\0" }, 
	['x'] = { "\xcb\xa3\0" }, 
	['y'] = { "\xca\xb8\0" }, 
	['z'] = { "\xe1\xb6\xbb\0" }, 
	['A'] = { "\xe1\xb4\x80\0" }, 
	['B'] = { "\xca\x99\0" }, 
	['C'] = { "\xe1\xb4\x84\0" }, 
	['D'] = { "\xe1\xb4\x85\0" }, 
	['E'] = { "\xe1\xb4\x87\0" }, 
	['F'] = { "\xd2\x93\0" }, 
	['G'] = { "\xc9\xa2\0" }, 
	['H'] = { "\xca\x9c\0" }, 
	['J'] = { "\xe1\xb4\x8a\0" }, 
	['K'] = { "\xe1\xb4\x8b\0" }, 
	['L'] = { "\xca\x9f\0" }, 
	['O'] = { "\xe1\xb4\x8f\0" }, 
	['P'] = { "\xe1\xb4\x98\0" }, 
	['Q'] = { "\xc7\xab\0" }, 
	['R'] = { "\xca\x80\0" }, 
	['S'] = { "\xe1\x82\xbd\0" }, 
	['U'] = { "\xe1\xb4\x9c\0" }, 
	['V'] = { "\xe1\xb4\xa0\0" }, 
	['X'] = { "\xe1\x83\xaf\0" }, 
	['Y'] = { "\xca\x8f\0" }, 
	['Z'] = { "\xe1\xb4\xa2\0" }, 
	[' '] = { "\xde\xb0\0" }, 
	['0'] = { "\xe2\x81\xb0\0" }, 
	['1'] = { "\xc2\xb9\0" }, 
	['2'] = { "\xc2\xb2\0" }, 
	['3'] = { "\xc2\xb3\0" }, 
	['4'] = { "\xe2\x81\xb4\0" }, 
	['5'] = { "\xe2\x81\xb5\0" }, 
	['6'] = { "\xe2\x81\xb6\0" }, 
	['7'] = { "\xe2\x81\xb7\0" }, 
	['8'] = { "\xe2\x81\xb8\0" }, 
	['9'] = { "\xe2\x81\xb9\0" }, 
	['.'] = { "\xde\x82\0" }, 
	[','] = { "\xde\x9b\0" }, 
	[':'] = { "\xde\x98\0" }, 
	['+'] = { "\xde\x88\0" }, 
	['-'] = { "\xde\x87\0" }, 
	['/'] = { "\xde\x8a\0" }, 
	['('] = { "\xde\x86\0" }, 
	[')'] = { "\xde\x89\0" }, 
	['\''] = { "\xde\x8b\0" }, 
	['\"'] = { "\xde\x8a\0" }
};

// generated by DumpNarrowFontsUnicode
const u32 AutoNarrowFontConfToUnicode[0x100] = {
    [' '] = 0x000007B0,
    ['\"'] = 0x0000078A,
    ['\''] = 0x0000078B,
    ['('] = 0x00000786,
    [')'] = 0x00000789,
    ['+'] = 0x00000788,
    [','] = 0x0000079B,
    ['-'] = 0x00000787,
    ['.'] = 0x00000782,
    ['/'] = 0x0000078A,
    ['0'] = 0x00002070,
    ['1'] = 0x000000B9,
    ['2'] = 0x000000B2,
    ['3'] = 0x000000B3,
    ['4'] = 0x00002074,
    ['5'] = 0x00002075,
    ['6'] = 0x00002076,
    ['7'] = 0x00002077,
    ['8'] = 0x00002078,
    ['9'] = 0x00002079,
    [':'] = 0x00000798,
    ['A'] = 0x00001D00,
    ['B'] = 0x00000299,
    ['C'] = 0x00001D04,
    ['D'] = 0x00001D05,
    ['E'] = 0x00001D07,
    ['F'] = 0x00000493,
    ['G'] = 0x00000262,
    ['H'] = 0x0000029C,
    ['J'] = 0x00001D0A,
    ['K'] = 0x00001D0B,
    ['L'] = 0x0000029F,
    ['O'] = 0x00001D0F,
    ['P'] = 0x00001D18,
    ['Q'] = 0x000001EB,
    ['R'] = 0x00000280,
    ['S'] = 0x000010BD,
    ['U'] = 0x00001D1C,
    ['V'] = 0x00001D20,
    ['X'] = 0x000010EF,
    ['Y'] = 0x0000028F,
    ['Z'] = 0x00001D22,
    ['a'] = 0x00001D43,
    ['b'] = 0x00001D47,
    ['c'] = 0x00001D9C,
    ['d'] = 0x00001D48,
    ['e'] = 0x00001D49,
    ['f'] = 0x00001DA0,
    ['g'] = 0x00001D4D,
    ['h'] = 0x000002B0,
    ['k'] = 0x00001D4F,
    ['n'] = 0x0000207F,
    ['o'] = 0x00001D52,
    ['p'] = 0x00001D56,
    ['q'] = 0x00001D60,
    ['r'] = 0x000002B3,
    ['s'] = 0x000002E2,
    ['t'] = 0x00001D57,
    ['u'] = 0x00001D58,
    ['v'] = 0x00001D5B,
    ['x'] = 0x000002E3,
    ['y'] = 0x000002B8,
    ['z'] = 0x00001DBB
};
