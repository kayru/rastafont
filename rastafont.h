#ifndef __RASTAFONT_H__20131108__
#define __RASTAFONT_H__20131108__

#ifdef __cplusplus
extern "C" {
#endif

	void rastafont6x8_blit_string(unsigned* output, unsigned pitch, unsigned colour, const char* str);
	void rastafont8x8_blit_string(unsigned* output, unsigned pitch, unsigned colour, const char* str);
	void rastafont8x12_blit_string(unsigned* output, unsigned pitch, unsigned colour, const char* str);

#ifdef __cplusplus
};
#endif

#endif //__RASTAFONT_H__20131108__
