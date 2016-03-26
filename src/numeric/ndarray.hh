#pragma once
#include "types.hh"
#include "support.hh"
#include "slice.hh"

namespace eScatter { namespace numeric
{
    template <typename T, unsigned D>
    class NdArray
    {
        std::vector<T> data_;
        shape_t<D> shape_;
        stride_t<D> stride_;

        public:
            NdArray(shape_t<D> const &shape):
                data_(calc_size<D>(shape)),
                shape_(shape),
                stride_(calc_stride<D>(shape))
            {}

            T &operator[](size_t i)
            {
                return data_[i];
            }

            T const &operator[](size_t i) const
            {
                return data_[i];
            }

            Slice<D> slice() const
            {
                return Slice<D>(shape_);
            }

            shape_t<D> shape() const
            {
                return shape_;
            }
    };
}}

