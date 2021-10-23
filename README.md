# FFT_shift

An in place FFT shift algorithm that works in any number of dimensions.

Haven't seen this yet, so wrote it.

## Issues

Doesn't work correctly when the loop containing the two recursive calls is longer than the loop in those calls.
For example, works fine for 2 by 4 matrices, but not for 4 by 2. Unclear how to fix this, and why fundamentally this occurs.
Might be a challenge for any FFT shift algorithm.

## Usage

```C++
#include "FFT_shift.hh"
float A[30][40][50];
// ...
FFT_shift::shift(**A, 30, 40, 50);
```
