// Copied from Numpy
#ifndef _fp_h
#define _fp_h

static unsigned half2float(unsigned short h);
unsigned short float2half(unsigned f);
void floattofp16(unsigned char *dst, float *src, unsigned nelem);
void fp16tofloat(float *dst, unsigned char *src, unsigned nelem);

#endif
