#include <iostream>

const char gDigitsLut[200] = {
  '0', '0', '0', '1', '0', '2', '0', '3', '0', '4', '0', '5', '0', '6', '0', '7', '0', '8', '0', '9', '1', '0', '1', '1', '1', '2', '1', '3', '1',
  '4', '1', '5', '1', '6', '1', '7', '1', '8', '1', '9', '2', '0', '2', '1', '2', '2', '2', '3', '2', '4', '2', '5', '2', '6', '2', '7', '2', '8',
  '2', '9', '3', '0', '3', '1', '3', '2', '3', '3', '3', '4', '3', '5', '3', '6', '3', '7', '3', '8', '3', '9', '4', '0', '4', '1', '4', '2', '4',
  '3', '4', '4', '4', '5', '4', '6', '4', '7', '4', '8', '4', '9', '5', '0', '5', '1', '5', '2', '5', '3', '5', '4', '5', '5', '5', '6', '5', '7',
  '5', '8', '5', '9', '6', '0', '6', '1', '6', '2', '6', '3', '6', '4', '6', '5', '6', '6', '6', '7', '6', '8', '6', '9', '7', '0', '7', '1', '7',
  '2', '7', '3', '7', '4', '7', '5', '7', '6', '7', '7', '7', '8', '7', '9', '8', '0', '8', '1', '8', '2', '8', '3', '8', '4', '8', '5', '8', '6',
  '8', '7', '8', '8', '8', '9', '9', '0', '9', '1', '9', '2', '9', '3', '9', '4', '9', '5', '9', '6', '9', '7', '9', '8', '9', '9'};
void u32toa_sse2(uint32_t value, char* buffer) {
  if (value < 10000) {
    const uint32_t d1 = (value / 100) << 1;
    const uint32_t d2 = (value % 100) << 1;

    if (value >= 1000)
      *buffer++ = gDigitsLut[d1];
    if (value >= 100)
      *buffer++ = gDigitsLut[d1 + 1];
    if (value >= 10)
      *buffer++ = gDigitsLut[d2];
    *buffer++ = gDigitsLut[d2 + 1];
    *buffer++ = '\0';
  } else if (value < 100000000) {
    // Experiment shows that this case SSE2 is slower
#if 0
        const __m128i a = Convert8DigitsSSE2(value);

        // Convert to bytes, add '0'
        const __m128i va = _mm_add_epi8(_mm_packus_epi16(a, _mm_setzero_si128()), reinterpret_cast<const __m128i*>(kAsciiZero)[0]);

        // Count number of digit
        const unsigned mask = _mm_movemask_epi8(_mm_cmpeq_epi8(va, reinterpret_cast<const __m128i*>(kAsciiZero)[0]));
        unsigned long digit;
#ifdef _MSC_VER
        _BitScanForward(&digit, ~mask | 0x8000);
#else
        digit = __builtin_ctz(~mask | 0x8000);
#endif

        // Shift digits to the beginning
        __m128i result = ShiftDigits_SSE2(va, digit);
        //__m128i result = _mm_srl_epi64(va, _mm_cvtsi32_si128(digit * 8));
        _mm_storel_epi64(reinterpret_cast<__m128i*>(buffer), result);
        buffer[8 - digit] = '\0';
#else
    // value = bbbbcccc
    const uint32_t b = value / 10000;
    const uint32_t c = value % 10000;

    const uint32_t d1 = (b / 100) << 1;
    const uint32_t d2 = (b % 100) << 1;

    const uint32_t d3 = (c / 100) << 1;
    const uint32_t d4 = (c % 100) << 1;

    if (value >= 10000000)
      *buffer++ = gDigitsLut[d1];
    if (value >= 1000000)
      *buffer++ = gDigitsLut[d1 + 1];
    if (value >= 100000)
      *buffer++ = gDigitsLut[d2];
    *buffer++ = gDigitsLut[d2 + 1];

    *buffer++ = gDigitsLut[d3];
    *buffer++ = gDigitsLut[d3 + 1];
    *buffer++ = gDigitsLut[d4];
    *buffer++ = gDigitsLut[d4 + 1];
    *buffer++ = '\0';
#endif
  } else {
    // value = aabbbbbbbb in decimal

    const uint32_t a = value / 100000000; // 1 to 42
    value %= 100000000;

    if (a >= 10) {
      const unsigned i = a << 1;
      *buffer++ = gDigitsLut[i];
      *buffer++ = gDigitsLut[i + 1];
    } else
      *buffer++ = '0' + static_cast<char>(a);

    const __m128i b = Convert8DigitsSSE2(value);
    const __m128i ba = _mm_add_epi8(_mm_packus_epi16(_mm_setzero_si128(), b), reinterpret_cast<const __m128i*>(kAsciiZero)[0]);
    const __m128i result = _mm_srli_si128(ba, 8);
    _mm_storel_epi64(reinterpret_cast<__m128i*>(buffer), result);
    buffer[8] = '\0';
  }
}
void i32toa_sse2(int32_t value, char* buffer) {
  uint32_t u = static_cast<uint32_t>(value);
  if (value < 0) {
    *buffer++ = '-';
    u = ~u + 1;
  }
  u32toa_sse2(u, buffer);
}

int main(int argc, char* argv[]) {
  char* buffer = new char(100);
  i32toa_sse2(100, buffer);
  std::cout << *buffer << std::endl;
  return 0;
}
