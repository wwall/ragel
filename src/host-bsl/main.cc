/*
 * Copyright 2001-2018 Adrian Thurston <thurston@colm.net>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include "inputdata.h"
#include "nragel.h"

extern struct colm_sections rlparseBsl;
extern struct colm_sections rlhcBsl;

/*
 * JavaScript
 */

const char *defaultOutFnBsl( const char *inputFileName )
{
	return fileNameFromStem( inputFileName, ".bsl" );
}

HostType hostTypesBSL[] =
{
	{ "s8",     0, "int8",    true,   true,  false,  SCHAR_MIN, SCHAR_MAX,  0, 0,          1 },
	{ "u8",     0, "uint8",   false,  true,  false,  0, 0,                  0, UCHAR_MAX,  1 },
	{ "s16",    0, "int16",   true,   true,  false,  SHRT_MIN,  SHRT_MAX,   0, 0,          2 },
	{ "u16",    0, "uint16",  false,  true,  false,  0, 0,                  0, USHRT_MAX,  2 },
	{ "i32",    0, "int32",   true,   true,  false,  INT_MIN,   INT_MAX,    0, 0,          4 },
	{ "u32",    0, "uint32",  false,  true,  false,  0, 0,                  0, UINT_MAX,   4 },
	{ "number", 0, "number",  true,   true,  false,  LONG_MIN,  LONG_MAX,   0, 0,          8 },
};

const HostLang hostLangBSL =
{
	hostTypesBSL,
	7,
	1,
	false,
	true, /* loopLabels */
	Translated,
	BreakFeature,
	&makeCodeGen,
	&defaultOutFnBsl,
	&genLineDirectiveTrans
};

int main( int argc, const char **argv )
{
	InputData id( &hostLangBSL, &rlparseBsl, &rlhcBsl );
	return id.rlhcMain( argc, argv );
}
