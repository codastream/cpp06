# Numerical types (recap)

## Float 

IEEE 754 single-precision

# Type conversions

`std::numeric_limits` provides following values for each type
- max
- min


## Checkinf for overflow (recap)
When downcasted, a value can overflow the capacity of new type. For instance, a double > INT_MAX when casted to int.

## Checking for underflow
When downcasted, a value can loose precision. For instance a IEEE 754 double < `std::numeric_limits<float>::denorm_min()` will be a 0 in float.

## Static cast

## Dynamic cast

## Reinterpret cast

## Const cast
Should not be used
