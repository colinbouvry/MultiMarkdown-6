/* Generated by re2c 1.0.3 on Mon Aug  6 17:50:40 2018 */
/**

	MultiMarkdown -- Lightweight markup processor to produce HTML, LaTeX, and more.

	@file opml-lexer.c

	@brief Tokenize OPML file for parsing


	@author	Fletcher T. Penney
	@bug	

**/

/*

	Copyright © 2016 - 2018 Fletcher T. Penney.


	The `MultiMarkdown 6` project is released under the MIT License..
	
	GLibFacade.c and GLibFacade.h are from the MultiMarkdown v4 project:
	
		https://github.com/fletcher/MultiMarkdown-4/
	
	MMD 4 is released under both the MIT License and GPL.
	
	
	CuTest is released under the zlib/libpng license. See CuTest.c for the
	text of the license.
	
	uthash library:
		Copyright (c) 2005-2016, Troy D. Hanson
	
		Licensed under Revised BSD license
	
	miniz library:
		Copyright 2013-2014 RAD Game Tools and Valve Software
		Copyright 2010-2014 Rich Geldreich and Tenacious Software LLC
	
		Licensed under the MIT license
	
	argtable3 library:
		Copyright (C) 1998-2001,2003-2011,2013 Stewart Heitmann
		<sheitmann@users.sourceforge.net>
		All rights reserved.
	
		Licensed under the Revised BSD License
	
	
	## The MIT License ##
	
	Permission is hereby granted, free of charge, to any person obtaining
	a copy of this software and associated documentation files (the
	"Software"), to deal in the Software without restriction, including
	without limitation the rights to use, copy, modify, merge, publish,
	distribute, sublicense, and/or sell copies of the Software, and to
	permit persons to whom the Software is furnished to do so, subject to
	the following conditions:
	
	The above copyright notice and this permission notice shall be
	included in all copies or substantial portions of the Software.
	
	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
	EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
	MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
	IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
	CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
	TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
	SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
	
	
	## Revised BSD License ##
	
	Redistribution and use in source and binary forms, with or without
	modification, are permitted provided that the following conditions are
	met:
	    * Redistributions of source code must retain the above copyright
	      notice, this list of conditions and the following disclaimer.
	    * Redistributions in binary form must reproduce the above
	      copyright notice, this list of conditions and the following
	      disclaimer in the documentation and/or other materials provided
	      with the distribution.
	    * Neither the name of the <organization> nor the
	      names of its contributors may be used to endorse or promote
	      products derived from this software without specific prior
	      written permission.
	
	THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
	"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
	LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
	A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT
	HOLDER> BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
	EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
	PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES LOSS OF USE, DATA, OR
	PROFITS OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
	LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
	NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
	SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
	

*/

#include <stdlib.h>

#include "opml-lexer.h"
#include "opml-parser.h"


// Basic scanner struct

#define YYCTYPE		unsigned char
#define YYCURSOR	s->cur
#define YYMARKER	s->ptr
#define YYCTXMARKER	s->ctx

int opml_scan(Scanner * s, const char * stop) {

	scan:

	if (s->cur >= stop) {
		return 0;
	}

	s->start = s->cur;

	
{
	YYCTYPE yych;
	unsigned int yyaccept = 0;
	yych = *YYCURSOR;
	switch (yych) {
	case '\t':
	case '\n':
	case '\r':
	case ' ':	goto yy4;
	case '<':	goto yy7;
	default:	goto yy2;
	}
yy2:
	++YYCURSOR;
yy3:
	{ goto scan; }
yy4:
	yych = *++YYCURSOR;
	switch (yych) {
	case '\t':
	case '\n':
	case '\r':
	case ' ':	goto yy4;
	default:	goto yy6;
	}
yy6:
	{ return OPML_WSNL; }
yy7:
	yyaccept = 0;
	yych = *(YYMARKER = ++YYCURSOR);
	switch (yych) {
	case '/':	goto yy8;
	case '?':	goto yy10;
	case 'B':
	case 'b':	goto yy11;
	case 'H':
	case 'h':	goto yy12;
	case 'O':
	case 'o':	goto yy13;
	case 'T':
	case 't':	goto yy14;
	default:	goto yy3;
	}
yy8:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'B':
	case 'b':	goto yy15;
	case 'H':
	case 'h':	goto yy16;
	case 'O':
	case 'o':	goto yy17;
	case 'T':
	case 't':	goto yy18;
	default:	goto yy9;
	}
yy9:
	YYCURSOR = YYMARKER;
	switch (yyaccept) {
	case 0: 	goto yy3;
	case 1: 	goto yy89;
	default:	goto yy94;
	}
yy10:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'X':
	case 'x':	goto yy19;
	default:	goto yy9;
	}
yy11:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'O':
	case 'o':	goto yy20;
	default:	goto yy9;
	}
yy12:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'E':
	case 'e':	goto yy21;
	default:	goto yy9;
	}
yy13:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'P':
	case 'p':	goto yy22;
	case 'U':
	case 'u':	goto yy23;
	default:	goto yy9;
	}
yy14:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'I':
	case 'i':	goto yy24;
	default:	goto yy9;
	}
yy15:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'O':
	case 'o':	goto yy25;
	default:	goto yy9;
	}
yy16:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'E':
	case 'e':	goto yy26;
	default:	goto yy9;
	}
yy17:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'P':
	case 'p':	goto yy27;
	case 'U':
	case 'u':	goto yy28;
	default:	goto yy9;
	}
yy18:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'I':
	case 'i':	goto yy29;
	default:	goto yy9;
	}
yy19:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'M':
	case 'm':	goto yy30;
	default:	goto yy9;
	}
yy20:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'D':
	case 'd':	goto yy31;
	default:	goto yy9;
	}
yy21:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'A':
	case 'a':	goto yy32;
	default:	goto yy9;
	}
yy22:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'M':
	case 'm':	goto yy33;
	default:	goto yy9;
	}
yy23:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'T':
	case 't':	goto yy34;
	default:	goto yy9;
	}
yy24:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'T':
	case 't':	goto yy35;
	default:	goto yy9;
	}
yy25:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'D':
	case 'd':	goto yy36;
	default:	goto yy9;
	}
yy26:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'A':
	case 'a':	goto yy37;
	default:	goto yy9;
	}
yy27:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'M':
	case 'm':	goto yy38;
	default:	goto yy9;
	}
yy28:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'T':
	case 't':	goto yy39;
	default:	goto yy9;
	}
yy29:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'T':
	case 't':	goto yy40;
	default:	goto yy9;
	}
yy30:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'L':
	case 'l':	goto yy41;
	default:	goto yy9;
	}
yy31:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'Y':
	case 'y':	goto yy43;
	default:	goto yy9;
	}
yy32:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'D':
	case 'd':	goto yy45;
	default:	goto yy9;
	}
yy33:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'L':
	case 'l':	goto yy47;
	default:	goto yy9;
	}
yy34:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'L':
	case 'l':	goto yy49;
	default:	goto yy9;
	}
yy35:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'L':
	case 'l':	goto yy50;
	default:	goto yy9;
	}
yy36:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'Y':
	case 'y':	goto yy51;
	default:	goto yy9;
	}
yy37:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'D':
	case 'd':	goto yy52;
	default:	goto yy9;
	}
yy38:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'L':
	case 'l':	goto yy53;
	default:	goto yy9;
	}
yy39:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'L':
	case 'l':	goto yy54;
	default:	goto yy9;
	}
yy40:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'L':
	case 'l':	goto yy55;
	default:	goto yy9;
	}
yy41:
	yych = *++YYCURSOR;
	switch (yych) {
	case 0x00:	goto yy9;
	case '>':	goto yy56;
	default:	goto yy41;
	}
yy43:
	yych = *++YYCURSOR;
	switch (yych) {
	case 0x00:	goto yy9;
	case '>':	goto yy58;
	default:	goto yy43;
	}
yy45:
	yych = *++YYCURSOR;
	switch (yych) {
	case 0x00:	goto yy9;
	case '>':	goto yy60;
	default:	goto yy45;
	}
yy47:
	yych = *++YYCURSOR;
	switch (yych) {
	case 0x00:	goto yy9;
	case '>':	goto yy62;
	default:	goto yy47;
	}
yy49:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'I':
	case 'i':	goto yy64;
	default:	goto yy9;
	}
yy50:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'E':
	case 'e':	goto yy65;
	default:	goto yy9;
	}
yy51:
	yych = *++YYCURSOR;
	switch (yych) {
	case '>':	goto yy67;
	default:	goto yy9;
	}
yy52:
	yych = *++YYCURSOR;
	switch (yych) {
	case '>':	goto yy69;
	default:	goto yy9;
	}
yy53:
	yych = *++YYCURSOR;
	switch (yych) {
	case '>':	goto yy71;
	default:	goto yy9;
	}
yy54:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'I':
	case 'i':	goto yy73;
	default:	goto yy9;
	}
yy55:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'E':
	case 'e':	goto yy74;
	default:	goto yy9;
	}
yy56:
	++YYCURSOR;
	{ return OPML_XML; }
yy58:
	++YYCURSOR;
	{ return OPML_BODY_OPEN; }
yy60:
	++YYCURSOR;
	{ return OPML_HEAD_OPEN; }
yy62:
	++YYCURSOR;
	{ return OPML_OPML_OPEN; }
yy64:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'N':
	case 'n':	goto yy75;
	default:	goto yy9;
	}
yy65:
	yych = *++YYCURSOR;
	switch (yych) {
	case 0x00:	goto yy9;
	case '>':	goto yy76;
	default:	goto yy65;
	}
yy67:
	++YYCURSOR;
	{ return OPML_BODY_CLOSE; }
yy69:
	++YYCURSOR;
	{ return OPML_HEAD_CLOSE; }
yy71:
	++YYCURSOR;
	{ return OPML_OPML_CLOSE; }
yy73:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'N':
	case 'n':	goto yy78;
	default:	goto yy9;
	}
yy74:
	yych = *++YYCURSOR;
	switch (yych) {
	case '>':	goto yy79;
	default:	goto yy9;
	}
yy75:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'E':
	case 'e':	goto yy81;
	default:	goto yy9;
	}
yy76:
	++YYCURSOR;
	{ return OPML_TITLE_OPEN; }
yy78:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'E':
	case 'e':	goto yy83;
	default:	goto yy9;
	}
yy79:
	++YYCURSOR;
	{ return OPML_TITLE_CLOSE; }
yy81:
	yych = *++YYCURSOR;
	switch (yych) {
	case 0x00:	goto yy9;
	case '\t':
	case '\n':
	case '\r':
	case ' ':	goto yy81;
	case '/':	goto yy86;
	case '>':	goto yy88;
	case 'T':
	case 't':	goto yy90;
	default:	goto yy84;
	}
yy83:
	yych = *++YYCURSOR;
	switch (yych) {
	case '>':	goto yy91;
	default:	goto yy9;
	}
yy84:
	yych = *++YYCURSOR;
yy85:
	switch (yych) {
	case 0x00:	goto yy9;
	case '/':	goto yy86;
	case '>':	goto yy88;
	default:	goto yy84;
	}
yy86:
	yych = *++YYCURSOR;
	switch (yych) {
	case 0x00:	goto yy9;
	case '/':	goto yy86;
	case '>':	goto yy93;
	default:	goto yy84;
	}
yy88:
	++YYCURSOR;
yy89:
	{ return OPML_OUTLINE_OPEN; }
yy90:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'E':
	case 'e':	goto yy95;
	default:	goto yy85;
	}
yy91:
	++YYCURSOR;
	{ return OPML_OUTLINE_CLOSE; }
yy93:
	++YYCURSOR;
yy94:
	{ return OPML_OUTLINE_SELF_CLOSE; }
yy95:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'X':
	case 'x':	goto yy96;
	default:	goto yy85;
	}
yy96:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'T':
	case 't':	goto yy97;
	default:	goto yy85;
	}
yy97:
	yych = *++YYCURSOR;
	switch (yych) {
	case 0x00:	goto yy9;
	case '\t':
	case '\n':
	case '\r':
	case ' ':	goto yy97;
	case '/':	goto yy86;
	case '=':	goto yy99;
	case '>':	goto yy88;
	default:	goto yy84;
	}
yy99:
	yych = *++YYCURSOR;
	switch (yych) {
	case 0x00:	goto yy9;
	case '\t':
	case '\n':
	case '\r':
	case ' ':	goto yy99;
	case '"':	goto yy101;
	case '/':	goto yy86;
	case '>':	goto yy88;
	default:	goto yy84;
	}
yy101:
	yych = *++YYCURSOR;
	switch (yych) {
	case '(':	goto yy102;
	case 'M':
	case 'm':	goto yy103;
	default:	goto yy85;
	}
yy102:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'U':
	case 'u':	goto yy104;
	default:	goto yy85;
	}
yy103:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'E':
	case 'e':	goto yy105;
	default:	goto yy85;
	}
yy104:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'N':
	case 'n':	goto yy106;
	default:	goto yy85;
	}
yy105:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'T':
	case 't':	goto yy107;
	default:	goto yy85;
	}
yy106:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'T':
	case 't':	goto yy108;
	default:	goto yy85;
	}
yy107:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'A':
	case 'a':	goto yy109;
	default:	goto yy85;
	}
yy108:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'I':
	case 'i':	goto yy110;
	default:	goto yy85;
	}
yy109:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'D':
	case 'd':	goto yy111;
	default:	goto yy85;
	}
yy110:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'T':
	case 't':	goto yy112;
	default:	goto yy85;
	}
yy111:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'A':
	case 'a':	goto yy113;
	default:	goto yy85;
	}
yy112:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'L':
	case 'l':	goto yy114;
	default:	goto yy85;
	}
yy113:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'T':
	case 't':	goto yy115;
	default:	goto yy85;
	}
yy114:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'E':
	case 'e':	goto yy116;
	default:	goto yy85;
	}
yy115:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'A':
	case 'a':	goto yy117;
	default:	goto yy85;
	}
yy116:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'D':
	case 'd':	goto yy118;
	default:	goto yy85;
	}
yy117:
	yych = *++YYCURSOR;
	switch (yych) {
	case '"':	goto yy119;
	default:	goto yy85;
	}
yy118:
	yych = *++YYCURSOR;
	switch (yych) {
	case ' ':	goto yy121;
	default:	goto yy85;
	}
yy119:
	yych = *++YYCURSOR;
	switch (yych) {
	case 0x00:	goto yy9;
	case '\t':
	case '\n':
	case '\r':
	case ' ':	goto yy119;
	case '/':	goto yy86;
	case '>':	goto yy122;
	default:	goto yy84;
	}
yy121:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'P':
	case 'p':	goto yy124;
	default:	goto yy85;
	}
yy122:
	++YYCURSOR;
	{ return OPML_OUTLINE_METADATA; }
yy124:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'R':
	case 'r':	goto yy125;
	default:	goto yy85;
	}
yy125:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'E':
	case 'e':	goto yy126;
	default:	goto yy85;
	}
yy126:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'A':
	case 'a':	goto yy127;
	default:	goto yy85;
	}
yy127:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'M':
	case 'm':	goto yy128;
	default:	goto yy85;
	}
yy128:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'B':
	case 'b':	goto yy129;
	default:	goto yy85;
	}
yy129:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'L':
	case 'l':	goto yy130;
	default:	goto yy85;
	}
yy130:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'E':
	case 'e':	goto yy131;
	default:	goto yy85;
	}
yy131:
	yych = *++YYCURSOR;
	switch (yych) {
	case ')':	goto yy132;
	default:	goto yy85;
	}
yy132:
	yych = *++YYCURSOR;
	switch (yych) {
	case '"':	goto yy133;
	default:	goto yy85;
	}
yy133:
	yych = *++YYCURSOR;
	switch (yych) {
	case 0x00:	goto yy9;
	case '\t':
	case '\n':
	case '\r':
	case ' ':	goto yy133;
	case '/':	goto yy86;
	case '>':	goto yy88;
	case '_':	goto yy135;
	default:	goto yy84;
	}
yy135:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'N':
	case 'n':	goto yy136;
	default:	goto yy85;
	}
yy136:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'O':
	case 'o':	goto yy137;
	default:	goto yy85;
	}
yy137:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'T':
	case 't':	goto yy138;
	default:	goto yy85;
	}
yy138:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'E':
	case 'e':	goto yy139;
	default:	goto yy85;
	}
yy139:
	yych = *++YYCURSOR;
	switch (yych) {
	case 0x00:	goto yy9;
	case '\t':
	case '\n':
	case '\r':
	case ' ':	goto yy139;
	case '/':	goto yy86;
	case '=':	goto yy141;
	case '>':	goto yy88;
	default:	goto yy84;
	}
yy141:
	yych = *++YYCURSOR;
	switch (yych) {
	case 0x00:	goto yy9;
	case '\t':
	case '\n':
	case '\r':
	case ' ':	goto yy141;
	case '"':	goto yy143;
	case '/':	goto yy86;
	case '>':	goto yy88;
	default:	goto yy84;
	}
yy143:
	yych = *++YYCURSOR;
	switch (yych) {
	case 0x00:	goto yy9;
	case '"':	goto yy145;
	case '/':	goto yy147;
	case '>':	goto yy149;
	default:	goto yy143;
	}
yy145:
	yych = *++YYCURSOR;
	switch (yych) {
	case 0x00:	goto yy9;
	case '\t':
	case '\n':
	case '\r':
	case ' ':	goto yy145;
	case '/':	goto yy86;
	case '>':	goto yy150;
	default:	goto yy84;
	}
yy147:
	yych = *++YYCURSOR;
	switch (yych) {
	case 0x00:	goto yy9;
	case '"':	goto yy145;
	case '/':	goto yy147;
	case '>':	goto yy152;
	default:	goto yy143;
	}
yy149:
	yyaccept = 1;
	yych = *(YYMARKER = ++YYCURSOR);
	if (yych <= 0x00) goto yy89;
	goto yy154;
yy150:
	++YYCURSOR;
	{ return OPML_OUTLINE_PREAMBLE; }
yy152:
	yyaccept = 2;
	yych = *(YYMARKER = ++YYCURSOR);
	if (yych <= 0x00) goto yy94;
	goto yy154;
yy153:
	yych = *++YYCURSOR;
yy154:
	switch (yych) {
	case 0x00:	goto yy9;
	case '"':	goto yy155;
	default:	goto yy153;
	}
yy155:
	yych = *++YYCURSOR;
	switch (yych) {
	case '\t':
	case '\n':
	case '\r':
	case ' ':	goto yy155;
	case '>':	goto yy150;
	default:	goto yy9;
	}
}

}




/// skip through text attribute to find value
size_t scan_text(const char * c) {
	const char * marker = NULL;
	const char * start = c;


{
	unsigned char yych;
	yych = *(marker = c);
	switch (yych) {
	case '\t':
	case '\r':
	case ' ':	goto yy161;
	case '\n':	goto yy162;
	case 'T':
	case 't':	goto yy165;
	default:	goto yy160;
	}
yy159:
	{ return 0; }
yy160:
	++c;
	goto yy159;
yy161:
	yych = *(marker = ++c);
	switch (yych) {
	case '\t':
	case '\n':
	case '\r':
	case ' ':	goto yy162;
	case 'T':
	case 't':	goto yy166;
	default:	goto yy159;
	}
yy162:
	yych = *++c;
	switch (yych) {
	case '\t':
	case '\n':
	case '\r':
	case ' ':	goto yy162;
	case 'T':
	case 't':	goto yy166;
	default:	goto yy164;
	}
yy164:
	c = marker;
	goto yy159;
yy165:
	yych = *(marker = ++c);
	switch (yych) {
	case 'E':
	case 'e':	goto yy167;
	default:	goto yy159;
	}
yy166:
	yych = *++c;
	switch (yych) {
	case 'E':
	case 'e':	goto yy167;
	default:	goto yy164;
	}
yy167:
	yych = *++c;
	switch (yych) {
	case 'X':
	case 'x':	goto yy168;
	default:	goto yy164;
	}
yy168:
	yych = *++c;
	switch (yych) {
	case 'T':
	case 't':	goto yy169;
	default:	goto yy164;
	}
yy169:
	yych = *++c;
	switch (yych) {
	case '\t':
	case '\n':
	case '\r':
	case ' ':	goto yy169;
	case '=':	goto yy171;
	default:	goto yy164;
	}
yy171:
	yych = *++c;
	switch (yych) {
	case '\t':
	case '\n':
	case '\r':
	case ' ':	goto yy171;
	case '"':
		marker = c;
		goto yy173;
	default:	goto yy164;
	}
yy173:
	yych = *++c;
	switch (yych) {
	case 0x00:	goto yy164;
	case '"':	goto yy175;
	default:	goto yy173;
	}
yy175:
	++c;
	c = marker;
	{ return (size_t)( c - start ); }
}
	
}


/// skip through _note attribute to find value
size_t scan_note(const char * c) {
	const char * marker = NULL;
	const char * start = c;


{
	unsigned char yych;
	yych = *(marker = c);
	switch (yych) {
	case '\t':
	case '\r':
	case ' ':	goto yy181;
	case '\n':	goto yy182;
	case '_':	goto yy185;
	default:	goto yy180;
	}
yy179:
	{ return 0; }
yy180:
	++c;
	goto yy179;
yy181:
	yych = *(marker = ++c);
	switch (yych) {
	case '\t':
	case '\n':
	case '\r':
	case ' ':	goto yy182;
	case '_':	goto yy186;
	default:	goto yy179;
	}
yy182:
	yych = *++c;
	switch (yych) {
	case '\t':
	case '\n':
	case '\r':
	case ' ':	goto yy182;
	case '_':	goto yy186;
	default:	goto yy184;
	}
yy184:
	c = marker;
	goto yy179;
yy185:
	yych = *(marker = ++c);
	switch (yych) {
	case 'N':
	case 'n':	goto yy187;
	default:	goto yy179;
	}
yy186:
	yych = *++c;
	switch (yych) {
	case 'N':
	case 'n':	goto yy187;
	default:	goto yy184;
	}
yy187:
	yych = *++c;
	switch (yych) {
	case 'O':
	case 'o':	goto yy188;
	default:	goto yy184;
	}
yy188:
	yych = *++c;
	switch (yych) {
	case 'T':
	case 't':	goto yy189;
	default:	goto yy184;
	}
yy189:
	yych = *++c;
	switch (yych) {
	case 'E':
	case 'e':	goto yy190;
	default:	goto yy184;
	}
yy190:
	yych = *++c;
	switch (yych) {
	case '\t':
	case '\n':
	case '\r':
	case ' ':	goto yy190;
	case '=':	goto yy192;
	default:	goto yy184;
	}
yy192:
	yych = *++c;
	switch (yych) {
	case '\t':
	case '\n':
	case '\r':
	case ' ':	goto yy192;
	case '"':
		marker = c;
		goto yy194;
	default:	goto yy184;
	}
yy194:
	yych = *++c;
	switch (yych) {
	case 0x00:	goto yy184;
	case '"':	goto yy196;
	default:	goto yy194;
	}
yy196:
	++c;
	c = marker;
	{ return (size_t)( c - start ); }
}
	
}


/// find end of double quoted value
size_t scan_double_quoted(const char * c) {
	const char * marker = NULL;
	const char * start = c;


{
	unsigned char yych;
	yych = *c;
	switch (yych) {
	case '\n':	goto yy200;
	case '"':	goto yy202;
	default:	goto yy201;
	}
yy200:
	{ return 0; }
yy201:
	++c;
	goto yy200;
yy202:
	yych = *(marker = ++c);
	if (yych <= 0x00) goto yy200;
	goto yy204;
yy203:
	yych = *++c;
yy204:
	switch (yych) {
	case 0x00:	goto yy205;
	case '"':	goto yy206;
	default:	goto yy203;
	}
yy205:
	c = marker;
	goto yy200;
yy206:
	++c;
	{ return (size_t)( c - start ); }
}
	
}
