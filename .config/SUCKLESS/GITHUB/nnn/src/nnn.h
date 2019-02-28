/*
 * BSD 2-Clause License
 *
 * Copyright (C) 2014-2016, Lazaros Koromilas <lostd@2f30.org>
 * Copyright (C) 2014-2016, Dimitris Papastamos <sin@2f30.org>
 * Copyright (C) 2016-2019, Arun Prakash Jana <engineerarun@gmail.com>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 *
 * * Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#pragma once

#include <curses.h>

#define CONTROL(c) ((c) ^ 0x40)

/* Supported actions */
enum action {
	SEL_BACK = 1,
	SEL_GOIN,
	SEL_NAV_IN,
	SEL_NEXT,
	SEL_PREV,
	SEL_PGDN,
	SEL_PGUP,
	SEL_HOME,
	SEL_END,
	SEL_CDHOME,
	SEL_CDBEGIN,
	SEL_CDLAST,
	SEL_VISIT,
	SEL_LEADER,
	SEL_CYCLE,
	SEL_CTX1,
	SEL_CTX2,
	SEL_CTX3,
	SEL_CTX4,
	SEL_PIN,
	SEL_FLTR,
	SEL_MFLTR,
	SEL_TOGGLEDOT,
	SEL_DETAIL,
	SEL_STATS,
	SEL_MEDIA,
	SEL_FMEDIA,
	SEL_ARCHIVE,
	SEL_ARCHIVELS,
	SEL_EXTRACT,
	SEL_FSIZE,  /* file size */
	SEL_ASIZE,  /* apparent size */
	SEL_BSIZE,  /* block size */
	SEL_MTIME,
	SEL_REDRAW,
	SEL_COPY,
	SEL_COPYMUL,
	SEL_COPYALL,
	SEL_COPYLIST,
	SEL_CP,
	SEL_MV,
	SEL_RMMUL,
	SEL_RM,
	SEL_OPENWITH,
	SEL_NEW,
	SEL_RENAME,
	SEL_RENAMEALL,
	SEL_HELP,
	SEL_EXEC,
	SEL_SHELL,
	SEL_SCRIPT,
	SEL_RUNCMD,
	SEL_RUNEDIT,
	SEL_RUNPAGE,
	SEL_NOTE,
	SEL_LOCK,
	SEL_QUITCTX,
	SEL_QUITCD,
	SEL_QUIT,
};

/* Associate a pressed key to an action */
struct key {
	int sym;         /* Key pressed */
	enum action act; /* Action */
};

static struct key bindings[] = {
	/* Back */
	{ KEY_LEFT,       SEL_BACK },
	{ 'h',            SEL_BACK },
	/* Inside or select */
	{ KEY_ENTER,      SEL_GOIN },
	{ '\r',           SEL_GOIN },
	/* Pure navigate inside */
	{ KEY_RIGHT,      SEL_NAV_IN },
	{ 'l',            SEL_NAV_IN },
	/* Next */
	{ 'j',            SEL_NEXT },
	{ KEY_DOWN,       SEL_NEXT },
	/* Previous */
	{ 'k',            SEL_PREV },
	{ KEY_UP,         SEL_PREV },
	/* Page down */
	{ KEY_NPAGE,      SEL_PGDN },
	{ CONTROL('D'),   SEL_PGDN },
	/* Page up */
	{ KEY_PPAGE,      SEL_PGUP },
	{ CONTROL('U'),   SEL_PGUP },
	/* First entry */
	{ KEY_HOME,       SEL_HOME },
	{ 'g',            SEL_HOME },
	{ CONTROL('A'),   SEL_HOME },
	/* Last entry */
	{ KEY_END,        SEL_END },
	{ 'G',            SEL_END },
	{ CONTROL('E'),   SEL_END },
	/* HOME */
	{ '~',            SEL_CDHOME },
	/* Initial directory */
	{ '&',            SEL_CDBEGIN },
	/* Last visited dir */
	{ '-',            SEL_CDLAST },
	/* Visit marked directory */
	{ CONTROL('B'),   SEL_VISIT },
	/* Leader key */
	{ CONTROL('_'),   SEL_LEADER },
	{ ',',            SEL_LEADER },
	/* Cycle contexts in forward direction */
	{ '\t',           SEL_CYCLE },
	{ CONTROL('I'),   SEL_CYCLE },
	/* Go to/create context N */
	{ '1',            SEL_CTX1 },
	{ '2',            SEL_CTX2 },
	{ '3',            SEL_CTX3 },
	{ '4',            SEL_CTX4 },
	/* Mark a path to visit later */
	{ 'b',            SEL_PIN },
	/* Filter */
	{ '/',            SEL_FLTR },
	/* Toggle filter mode */
	{ KEY_IC,         SEL_MFLTR },
	{ CONTROL('T'),   SEL_MFLTR },
	/* Toggle hide .dot files */
	{ '.',            SEL_TOGGLEDOT },
	/* Detailed listing */
	{ 'd',            SEL_DETAIL },
	/* File details */
	{ 'D',            SEL_STATS },
	/* Show media info short, run is hacked */
	{ 'm',            SEL_MEDIA },
	/* Show media info full, run is hacked */
	{ 'M',            SEL_FMEDIA },
	/* Create archive */
	{ 'f',            SEL_ARCHIVE },
	/* List archive */
	{ 'F',            SEL_ARCHIVELS },
	/* Extract archive */
	{ CONTROL('F'),   SEL_EXTRACT },
	/* Toggle sort by size */
	{ 's',            SEL_FSIZE },
	/* Sort by apparent size including dir contents */
	{ 'S',            SEL_ASIZE },
	/* Sort by total block count including dir contents */
	{ CONTROL('J'),   SEL_BSIZE },
	/* Toggle sort by time */
	{ 't',            SEL_MTIME },
	/* Redraw window */
	{ CONTROL('L'),   SEL_REDRAW },
	/* Copy currently selected file path */
	{ CONTROL('K'),   SEL_COPY },
	{ ' ',            SEL_COPY },
	/* Toggle copy multiple file paths */
	{ 'K',            SEL_COPYMUL },
	{ CONTROL('Y'),   SEL_COPYMUL },
	/* Select all files in current dir */
	{ 'Y',            SEL_COPYALL },
	/* Show list of copied files */
	{ 'y',            SEL_COPYLIST },
	/* Copy from copy buffer */
	{ 'P',            SEL_CP },
	/* Move from copy buffer */
	{ 'V',            SEL_MV },
	/* Delete from copy buffer */
	{ 'X',            SEL_RMMUL },
	/* Delete currently selected */
	{ CONTROL('X'),   SEL_RM },
	/* Open in a custom application */
	{ CONTROL('O'),   SEL_OPENWITH },
	/* Create a new file */
	{ 'n',            SEL_NEW },
	/* Show rename prompt */
	{ CONTROL('R'),   SEL_RENAME },
	/* Rename contents of current dir */
	{ 'r',            SEL_RENAMEALL },
	/* Show help */
	{ '?',            SEL_HELP },
	/* Execute file */
	{ 'C',            SEL_EXEC },
	/* Run command */
	{ '!',            SEL_SHELL },
	{ CONTROL(']'),   SEL_SHELL },
	/* Run a custom script */
	{ 'R',            SEL_SCRIPT },
	{ CONTROL('V'),   SEL_SCRIPT },
	/* Run a command */
	{ CONTROL('P'),   SEL_RUNCMD },
	/* Open in EDITOR or PAGER */
	{ 'e',            SEL_RUNEDIT },
	{ 'p',            SEL_RUNPAGE },
	/* Open notes file */
	{ CONTROL('N'),   SEL_NOTE },
	/* Lock screen */
	{ 'L',            SEL_LOCK },
	/* Quit a context */
	{ 'q',            SEL_QUITCTX },
	/* Change dir on quit */
	{ CONTROL('G'),   SEL_QUITCD },
	/* Quit */
	{ 'Q',            SEL_QUIT },
	{ CONTROL('Q'),   SEL_QUIT },
};
