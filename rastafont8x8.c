#include "rastafont.h"

#if defined(_MSC_VER)
#elif defined(__GNUC__)
#define __forceinline inline __attribute__((always_inline))
#else 
#define __forceinline
#endif

static const unsigned rastafont8x8_bitmap[] =
{
	0xffffffff,0xffffffff,0xf3e1e1f3,0xfff3fff3,0xffc9c9c9,0xffffffff,0xc980c9c9,0xffc9c980,
	0xe1fcc1f3,0xfff3e0cf,0xe7cc9cff,0xff9c99f3,0x91e3c9e3,0xff91ccc4,0xfffcf9f9,0xffffffff,
	0xf9f9f3e7,0xffe7f3f9,0xe7e7f3f9,0xfff9f3e7,0x00c399ff,0xffff99c3,0xc0f3f3ff,0xfffff3f3,
	0xffffffff,0xf9f3f1ff,0xc0ffffff,0xffffffff,0xffffffff,0xfff3f3ff,0xf3e7cf9f,0xfffefcf9,
	0xc0c4cce1,0xffe1ccc8,0xf3f3f0f3,0xffc0f3f3,0xe3cfcce1,0xffc0ccf9,0xe3cfcce1,0xffe1cccf,
	0xccc9c3c7,0xffcfcf80,0xcfe0fcc0,0xffe1cccf,0xe0fcf9e3,0xffe1cccc,0xe7cfccc0,0xfff9f9f3,
	0xe1cccce1,0xffe1cccc,0xc1cccce1,0xfff1e7cf,0xf3f3ffff,0xfff3f3ff,0xf3f3ffff,0xf9f3f1ff,
	0xfcf9f3e7,0xffe7f3f9,0xffc0ffff,0xffffffc0,0xcfe7f3f9,0xfff9f3e7,0xe7cfcce1,0xfff3fff3,
	0x84849cc1,0xffe1fc84,0xcccce1f3,0xffccccc0,0xc19999c0,0xffc09999,0xfcfc99c3,0xffc399fc,
	0x9999c9c0,0xffc0c999,0xe1e9b980,0xff80b9e9,0xe1e9b980,0xfff0f9e9,0xfcfc99c3,0xff83998c,
	0xc0cccccc,0xffcccccc,0xf3f3f3e1,0xffe1f3f3,0xcfcfcf87,0xffe1cccc,0xe1c99998,0xff9899c9,
	0xf9f9f9f0,0xff8099b9,0x9480889c,0xff9c9c9c,0x8490989c,0xff9c9c8c,0x9c9cc9e3,0xffe3c99c,
	0xc19999c0,0xfff0f9f9,0xcccccce1,0xffc7e1c4,0xc19999c0,0xff98c9e1,0xe3f8cce1,0xffe1ccc7,
	0xf3f3d2c0,0xffe1f3f3,0xcccccccc,0xffc0cccc,0xcccccccc,0xfff3e1cc,0x949c9c9c,0xff9c8880,
	0xe3c99c9c,0xff9c9cc9,0xe1cccccc,0xffe1f3f3,0xf3e6cc80,0xff809cb9,0xf9f9f9e1,0xffe1f9f9,
	0xe7f3f9fc,0xffbf9fcf,0xe7e7e7e1,0xffe1e7e7,0x9cc9e3f7,0xffffffff,0xffffffff,0x00ffffff,
	0xffe7f3f3,0xffffffff,0xcfe1ffff,0xff91ccc1,0x99c1f9f8,0xffc29999,0xcce1ffff,0xffe1ccfc,
	0xc1cfcfc7,0xff91cccc,0xcce1ffff,0xffe1fcc0,0xf0f9c9e3,0xfff0f9f9,0xcc91ffff,0xe0cfc1cc,
	0x91c9f9f8,0xff989999,0xf3f1fff3,0xffe1f3f3,0xe7e1ffe7,0xf1e4e7e7,0xc999f9f8,0xff98c9e1,
	0xf3f3f3f1,0xffe1f3f3,0x80c8ffff,0xff9c9c94,0xcce0ffff,0xffcccccc,0xcce1ffff,0xffe1cccc,
	0x99c4ffff,0xf0f9c199,0xcc91ffff,0x87cfc1cc,0xc9e4ffff,0xfff0f9c9,0xfcc1ffff,0xffe0cfe1,
	0xf3c1f3f7,0xffe7d3f3,0xccccffff,0xff91cccc,0xccccffff,0xfff3e1cc,0x9c9cffff,0xffc98094,
	0xc99cffff,0xff9cc9e3,0xccccffff,0xe0cfc1cc,0xe6c0ffff,0xffc0d9f3,0xf8f3f3c7,0xffc7f3f3,
	0xffe7e7e7,0xffe7e7e7,0xc7f3f3f8,0xfff8f3f3,0xffffc491,0xffffffff,
};

__forceinline static unsigned rastafont8x8_select(unsigned a, unsigned b, unsigned m) { return ((b^a)&m)^b; }

__forceinline static void rastafont8x8_blit8(unsigned* output, unsigned colour, unsigned m, unsigned b)
{
	output[0] = rastafont8x8_select(output[0], colour, (int)(m<<(31-b))>>31);
	output[1] = rastafont8x8_select(output[1], colour, (int)(m<<(30-b))>>31);
	output[2] = rastafont8x8_select(output[2], colour, (int)(m<<(29-b))>>31);
	output[3] = rastafont8x8_select(output[3], colour, (int)(m<<(28-b))>>31);
	output[4] = rastafont8x8_select(output[4], colour, (int)(m<<(27-b))>>31);
	output[5] = rastafont8x8_select(output[5], colour, (int)(m<<(26-b))>>31);
	output[6] = rastafont8x8_select(output[6], colour, (int)(m<<(25-b))>>31);
	output[7] = rastafont8x8_select(output[7], colour, (int)(m<<(24-b))>>31);
}

void rastafont8x8_blit_string(unsigned* output, unsigned pitch, unsigned colour, const char* str)
{
	unsigned id, m0, m1;
	while(*str)
	{
		id = *str-' ';
		if( id <= '~'-' ' )
		{
			m0 = rastafont8x8_bitmap[id*2 + 0];
			m1 = rastafont8x8_bitmap[id*2 + 1];
			rastafont8x8_blit8(output+0*pitch/4, colour, m0, 0);
			rastafont8x8_blit8(output+1*pitch/4, colour, m0, 8);
			rastafont8x8_blit8(output+2*pitch/4, colour, m0, 16);
			rastafont8x8_blit8(output+3*pitch/4, colour, m0, 24);
			rastafont8x8_blit8(output+4*pitch/4, colour, m1, 0);
			rastafont8x8_blit8(output+5*pitch/4, colour, m1, 8);
			rastafont8x8_blit8(output+6*pitch/4, colour, m1, 16);
			rastafont8x8_blit8(output+7*pitch/4, colour, m1, 24);
		}
		str += 1;
		output += 8;
	}
}
