Rastafont
=========

This library is intended for embedding simple raster font rendering into applications.
It comes with 3 sizes of Terminal font: 6x8, 8x8 and 12x8 pixels.
Characters are composited into the target 32bpp RGBA image using a 1-bit mask (not alpha blended).
Only code page 437 characters ' ' (32) to '~' (126) are supported. 
Tabs, line breaks, etc. are not handled. An empty space will be emitted for unsupported characters.
No bounds checking or other error handling is performed, so the output buffer must be big enough.

Example usage:

		const unsigned width = 5*8; // 5 characters, 8 pixels each
		const unsigned height = 12; // image  must be at least 12 pixels high
		const unsigned pitch = width*sizeof(unsigned); // size in bytes of pixel row in target image  
		unsigned pixels[width*height] = {0}; // allocate and clear a 32bpp RGBA output buffer
		rastafont8x12_blit_string(pixels, pitch, 0xFFFFFFFF, "Hello");
