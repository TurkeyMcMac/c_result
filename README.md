# c_result
A macro for error handling in C, inspired by the `Result` type in Rust.

C doesn't have generic types, but it is possible to write macros to mimic them to
some extent.

## Usage
Create a result type like this: `make_result_type(<name>, <ok type>, <error type>)`.
To see what the macro generates, look in `result.c`. To see an example of usage,
look in `example.c`.
