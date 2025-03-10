/*
 * This file is part of anal.
 *
 * Copyright (c) 2025 ona-li-toki-e-jan-Epiphany-tawa-mi
 *
 * anal is free software: you can redistribute it and/or modify it under the
 * terms of the GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option) any later
 * version.
 *
 * anal is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
 * A PARTICULAR PURPOSE. See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * anal. If not, see <https://www.gnu.org/licenses/>.
 */

// TODO find a way to test marcos?

/*
 * Typechecks printf-like functions.
 * Works in GCC and clang.
 * format - the index (1-indexed) of the argument that has the format string.
 * va_list - the index (1-indexed) argument that has the variable argument list
 * (as-in '...').
 *
 * Contrived example:
 *
 * void PRINTF_TYPECHECK(1, 2) function(const char *const format, ...) {
 *     // Do stuff...
 * }
 */
#ifdef __GNUC__
#  define PRINTF_TYPECHECK(format, va_list) \
    __attribute__ ((__format__ (printf, format, va_list)))
#else // __GNUC__
#  define PRINTF_TYPECHECK(format, va_list)
#endif

/*
 * Checks that all pointer parameters to a function are not NULL.
 * Works in GCC and clang.
 *
 * Contrived example:
 *
 * NONNULL void function(const int *const nonnullable) {
 *     // Do stuff...
 * }
 */
#ifdef __GNUC__
#  define NONNULL __attribute__ ((nonnull))
#else // __GNUC__
#  define NONNULL
#endif

/*
 * Checks that the specified pointer parameters to a function are not NULL.
 * Works in GCC and clang.
 * ... - a list of the indicies (1-indexed) of the arguments that are to be
 * checked.
 *
 * Contrived example:
 *
 * NONNULL_ARGUMENTS(1) void function(
 *     const int *const nonnullable,
 *     const int *const nullable
 * ) {
 *     // Do stuff...
 * }
 */
 */
#ifdef __GNUC__
#  define NONNULL_ARGUMENTS(...) __attribute__ ((nonnull (__VA_ARGS__)))
#else // __GNUC__
#  define NONNULL_ARGUMENTS(...)
#endif
