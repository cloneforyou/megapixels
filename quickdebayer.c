#include "quickdebayer.h"

// Fast but bad debayer method that scales and rotates by skipping source pixels and
// doesn't interpolate any values at all

int
quick_debayer_bggr8(const uint8_t *source, uint8_t *destination, int width, int height, int skip)
{
	int byteskip = 2 * skip;
	int input_size = width * height;
	int i;
	int j=0;
	int row_left = width;
	int clipped = 0;
	int above80 = 0;
	int above50 = 0;
	// B G
	// G R
	for(i=0;i<input_size;) {
		destination[j++] = source[i+width+1];
		destination[j++] = source[i+1];
		destination[j++] = source[i];
		if(source[i+1] > 250) {
			clipped++;
		}
		if(source[i+1] > 205) {
			above80++;
		}
		if(source[i+1] > 128) {
			above50++;
		}
		i = i + byteskip;
		row_left = row_left - byteskip;
		if(row_left <= 0){
			row_left = width;
			i = i+width;
			i = i + (width * 2 * (skip-1));
		}
	}
	if(clipped > 300) {
		return -10;
	}
	if(clipped > 10) {
		return -1;
	}
	if(above50 < 10) {
		return 10;
	}
	if(above80 < 10) {
		return 1;
	}
	return 0;
}
