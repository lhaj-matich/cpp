#include <stdint.h>
#include <stdio.h>

#define SIGN(f) (((f) <= -0.0) ? 1 : 0)

#define AS_U32(f) (*(const uint32_t*)&(f))
#define FLOAT_EXPONENT_WIDTH 8
#define FLOAT_MANTISSA_WIDTH 23
#define FLOAT_BIAS ((1<<(FLOAT_EXPONENT_WIDTH-1))-1) /* 2^(e-1)-1 */
#define MASK(width)  ((1<<(width))-1) /* 2^w - 1 */
#define FLOAT_IMPLICIT_MANTISSA_BIT (1<<FLOAT_MANTISSA_WIDTH)

/* correct exponent with bias removed */
int float_exponent(float f) {
  return (int)((AS_U32(f) >> FLOAT_MANTISSA_WIDTH) & MASK(FLOAT_EXPONENT_WIDTH)) - FLOAT_BIAS;
}

/* of non-zero, normal floats only */
int float_mantissa(float f) {
  return (int)(AS_U32(f) & MASK(FLOAT_MANTISSA_WIDTH)) | FLOAT_IMPLICIT_MANTISSA_BIT;
}