# Numerical types (recap)

## Float (recap)

IEEE 754 single-precision defines the 32 bits floating-point representation
Bit layout: [S][EEEEEEEE][MMMMMMMMMMMMMMMMMMMMMMM]
            31 30     23 22                     0
- sign-bit (S) : 0 positive, 1 negative
- exponent (E)
- mantissa (M)

The value is calculated with formula (-1)^S * (1 + M/2^23) * 2^(E-127) with
- E being the biased exponent (exponent + 127)

# Type conversions

`std::numeric_limits` provides following values for each type
- max
- min


## Checkinf for overflow (recap)
When downcasted, a value can overflow the capacity of new type. For instance, a double > INT_MAX when casted to int.

## Checking for underflow
When downcasted, a value can loose precision. For instance a IEEE 754 double < `std::numeric_limits<float>::denorm_min()` will be a 0 in float.

# Cast

_downcasting_ is converting to a derived class or type.
_upcasting_ is converting to a more generic class or type.

a cast is
- _type safe_ if it returns a null or throws exception on failure
- _access safe_ if it respects visibility rules (private, public, protected)

|   			|c-style	|static		|dynamic	|reinterpret	|const	|implicit	|
|---			|---		|---		|---		|---			|---	|---		|
|type safe		|❌			|✅			|✅		|❌			|❌			|❕		|
|access safe	|❌			|✅			|✅		|❌			|❌			|❌		|
|downcast safe	|❌			|❌			|✅		|❌			|⛔			|❌		|
|upcast safe	|❌			|✅			|✅		|❌			|⛔			|✅		|
|check at		|compilation|compilation|runtime|compilation|compilation|compilation|

## c-style cast
- is not type safe

```c++
// compiles without warning
int i = -42;
char c = (char) i;
```

## implicit by assignment
- only allows certain casts but can lead to a loss of precision
```c++
// compiles without warning
int i = -42;
char c = i;
```

## Static cast
- the most common one, for type and access safe conversions
- if we need to modify a const value, it should be preceded by a `const_cast`.

## Dynamic cast
- used with polymorphism
- uses RTTI (runtime type information) to check actual object type, so it is downcast safe, at the price of runtime overhead. Steps are as follow :
	1. check object vtable
	2. walks inheritance hierarcy
	3. returns a valid pointer if it succeeds
- if the cast is invalid : 
	- for a pointer type : returns NULL (or nullptr after c++98)
	- for a reference type : throws a `std::bad_cast` exception, as references cannot be null

## Reinterpret cast
- does a bit reinterpretation
- for low-level operations

## Const cast
- removes or adds `const` / `volatile` qualifiers
- does NOT change the type
- to be used sparingly

# Evolutions

## c++11
- `nullptr`
- `auto` reduces need for explicit casts

## c++14/17
- `std::make_unique`, `std::make_shared` reduces need for raw pointers casts with reinterpret_cast
- `std::any` with `any_cast`
- if constexpr enables compile-time casting decisions

## c++20
- `std::bit_cast` safer than reinterpret_cast