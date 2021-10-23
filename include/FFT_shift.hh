#pragma once
#include <cstddef>
#include <algorithm>
#include <type_traits>

namespace FFT_shift
{

template <typename T, typename Dim>
void backend(T *A, size_t a, T *B, size_t b, Dim dim) noexcept
{   for (size_t i = 0; i < dim / 2; i++)
        std::swap(A[i + a], B[i + b + dim / 2]);
}

template <typename T, typename Dim_1, typename Dim_2, typename ...Dims>
void backend(T *A, size_t a, T *B, size_t b, Dim_1 dim_1, Dim_2 dim_2, Dims... dims) noexcept
{   for (size_t i = 0; i < dim_1 / 2; i++)
    {   // backend(A, (a + i)           * dim,       B, (b + i + dim / 2) * dim, dims...);
        // backend(B, (b + i + dim / 2) * dim,       A, (a + i)           * dim, dims...);
        backend(A, (a + i)             * dim_1, B, (b + i + dim_2 / 2) * dim_1, dim_2, dims...);
        backend(B, (b + i + dim_2 / 2) * dim_1, A, (a + i)             * dim_1, dim_2, dims...);
    }
}

template <typename T, typename ...Dims, std::enable_if_t<(std::is_integral_v<Dims> && ...)>* = nullptr>
void shift(T *data, Dims... dims) noexcept
{   backend(data, 0, data, 0, dims...);
}

}
