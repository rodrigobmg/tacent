// tPixelFormat.cpp
//
// Pixel formats in Tacent. Not all formats are fully supported. Certainly BC 4, 5, and 7 may not have extensive HW
// support at this time.
//
// Copyright (c) 2004-2006, 2017 Tristan Grimmer.
// Permission to use, copy, modify, and/or distribute this software for any purpose with or without fee is hereby
// granted, provided that the above copyright notice and this permission notice appear in all copies.
//
// THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT,
// INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN
// AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
// PERFORMANCE OF THIS SOFTWARE.

#include <Foundation/tAssert.h>
#include "Image/tPixelFormat.h"
namespace tImage
{

	
int NormalFormat_BytesPerPixel[tPixelFormat::NumNormalFormats] =
{
	3,				// R8G8B8
	4,				// R8G8B8A8
	3,				// B8G8R8
	4,				// B8G8R8A8
	2,				// G3B5A1R5G2
	2,				// G4B4A4R4
	2,				// G3B5R5G3
	2				// L8A8
};


int BlockFormat_BytesPer4x4PixelBlock[tPixelFormat::NumBlockFormats] =
{
	8,				// BC1_DXT1
	8,				// BC1_DXT1BA
	16,				// BC2_DXT3
	16,				// BC3_DXT5
	8,				// BC4_ATI1
	16,				// BC5_ATI2
	16,				// BC6H
	16,				// BC7
};


bool tIsNormalFormat(tPixelFormat format)
{
	if ((format >= tPixelFormat::FirstNormal) && (format <= tPixelFormat::LastNormal))
		return true;

	return false;
}


bool tIsBlockFormat(tPixelFormat format)
{
	if ((format >= tPixelFormat::FirstBlock) && (format <= tPixelFormat::LastBlock))
		return true;

	return false;
}


int tGetBytesPerPixel(tPixelFormat format)
{
	if (format == tPixelFormat::Invalid)
		return -1;

	tAssert(tIsNormalFormat(format));
	int index = int(format) - int(tPixelFormat::FirstNormal);
	return NormalFormat_BytesPerPixel[index];
}


int tGetBytesPer4x4PixelBlock(tPixelFormat format)
{
	if (format == tPixelFormat::Invalid)
		return -1;

	tAssert(tIsBlockFormat(format));
	int index = int(format) - int(tPixelFormat::FirstBlock);
	return BlockFormat_BytesPer4x4PixelBlock[index];
}


}