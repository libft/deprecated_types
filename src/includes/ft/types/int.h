/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fake_file_name (file name is useless too)          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 42header-remover <whatever@example.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by VCS handles       #+#    #+#             */
/*   Updated: 1970/01/01 00:00:00 by file history     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft/types/int.h
 * @brief type definitions for int types
 *
 * if FT_PEDANTIC is defined, any of optionals will not defined unless required
 * to require optionals explicitly, define FT_REQUIRE_* before include this file
 * supported:
 *	t_i0, t_i1, t_i2, t_i3 (signed integer types for 2^n bytes)
 *	t_u0, t_u1, t_u2, t_u3 (unsigned integer types for 2^n bytes)
 */

#ifndef INT_H
# define INT_H

# ifndef __STDC__
#  error C standard required
# endif
# if __STDC_VERSION__ < 199901L
#  error C11 or later required
# endif

/* allow re-include to optionally make some optional types required */
# undef INT_H

# include <stdint.h>
# include <limits.h>
# include <sys/types.h>

/* normal signed int types */
typedef signed char			t_ic;
typedef short				t_is;
typedef int					t_i;
typedef long				t_il;
typedef long long			t_ill;
typedef intmax_t			t_im;
# ifndef INTMAX_WIDTH
#  if !defined(FT_PEDANTIC) && defined(FT_REQUIRE_INTMAX_WIDTH)
/*  don't define INTMAX_WIDTH unless required if FT_PEDANTIC is on */
#  elif INTMAX_MIN == -9223372036854775807LL-1 \
	&& INTMAX_MAX == 9223372036854775807LL
#   define INTMAX_WIDTH 64
#  elif defined(FT_REQUIRE_INTMAX_WIDTH)
#   error Failed to determine INTMAX_WIDTH
#  endif
# endif
/* end normal signed int types */

/* normal unsigned int types */
typedef unsigned char		t_uc;
typedef unsigned short		t_us;
typedef unsigned int		t_u;
typedef unsigned long		t_ul;
typedef unsigned long long	t_ull;
typedef uintmax_t			t_um;
# ifndef UINTMAX_WIDTH
#  if !defined(FT_PEDANTIC) && defined(FT_REQUIRE_UINTMAX_WIDTH)
/*  don't define UINTMAX_WIDTH unless required if FT_PEDANTIC is on */
#  elif UINTMAX_MAX == 18446744073709551615UL
#   define UINTMAX_WIDTH 64
#  elif defined(FT_REQUIRE_UINTMAX_WIDTH)
#   error Failed to determine UINTMAX_WIDTH
#  endif
# endif
/* end normal unsigned int types */

/* required fixed-width signed int types */
typedef int_fast8_t			t_if0;
typedef int_fast16_t		t_if1;
typedef int_fast32_t		t_if2;
typedef int_fast64_t		t_if3;
typedef int_least8_t		t_il0;
typedef int_least16_t		t_il1;
typedef int_least32_t		t_il2;
typedef int_least64_t		t_il3;
# ifndef INT_FAST8_WIDTH
#  if !defined(FT_PEDANTIC) && defined(FT_REQUIRE_INT_FAST8_WIDTH)
/*  don't define INT_FAST8_WIDTH unless required if FT_PEDANTIC is on */
#  elif INT_FAST8_MIN == -128 && INT_FAST8_MAX == 127
#   define INT_FAST8_WIDTH 8
#  elif INT_FAST8_MIN == -32768 && INT_FAST8_MAX == 32767
#   define INT_FAST8_WIDTH 16
#  elif INT_FAST8_MIN == -2147483648 && INT_FAST8_MAX == 2147483647
#   define INT_FAST8_WIDTH 32
#  elif INT_FAST8_MIN == -9223372036854775807LL-1 \
	&& INT_FAST8_MAX == 9223372036854775807LL
#   define INT_FAST8_WIDTH 64
#  elif defined(FT_REQUIRE_INT_FAST8_WIDTH)
#   error Failed to determine INT_FAST8_WIDTH
#  endif
# endif
# ifndef INT_FAST16_WIDTH
#  if !defined(FT_PEDANTIC) && defined(FT_REQUIRE_INT_FAST16_WIDTH)
/*  don't define INT_FAST16_WIDTH unless required if FT_PEDANTIC is on */
#  elif INT_FAST16_MIN == -32768 && INT_FAST16_MAX == 32767
#   define INT_FAST16_WIDTH 16
#  elif INT_FAST16_MIN == -2147483648 && INT_FAST16_MAX == 2147483647
#   define INT_FAST16_WIDTH 32
#  elif INT_FAST16_MIN == -9223372036854775807LL-1 \
	&& INT_FAST16_MAX == 9223372036854775807LL
#   define INT_FAST16_WIDTH 64
#  elif defined(FT_REQUIRE_INT_FAST16_WIDTH)
#   error Failed to determine INT_FAST16_WIDTH
#  endif
# endif
# ifndef INT_FAST32_WIDTH
#  if !defined(FT_PEDANTIC) && defined(FT_REQUIRE_INT_FAST32_WIDTH)
/*  don't define INT_FAST32_WIDTH unless required if FT_PEDANTIC is on */
#  elif INT_FAST32_MIN == -2147483648 && INT_FAST32_MAX == 2147483647
#   define INT_FAST32_WIDTH 32
#  elif INT_FAST32_MIN == -9223372036854775807LL-1 \
	&& INT_FAST32_MAX == 9223372036854775807LL
#   define INT_FAST32_WIDTH 64
#  elif defined(FT_REQUIRE_INT_FAST32_WIDTH)
#   error Failed to determine INT_FAST32_WIDTH
#  endif
# endif
# ifndef INT_FAST64_WIDTH
#  if !defined(FT_PEDANTIC) && defined(FT_REQUIRE_INT_FAST64_WIDTH)
/*  don't define INT_FAST64_WIDTH unless required if FT_PEDANTIC is on */
#  elif INT_FAST64_MIN == -9223372036854775807LL-1 \
	&& INT_FAST64_MAX == 9223372036854775807LL
#   define INT_FAST64_WIDTH 64
#  elif defined(FT_REQUIRE_INT_FAST64_WIDTH)
#   error Failed to determine INT_FAST64_WIDTH
#  endif
# endif
# ifndef INT_LEAST8_WIDTH
#  if !defined(FT_PEDANTIC) && defined(FT_REQUIRE_INT_LEAST8_WIDTH)
/*  don't define INT_LEAST8_WIDTH unless required if FT_PEDANTIC is on */
#  elif INT_LEAST8_MIN == -128 && INT_LEAST8_MAX == 127
#   define INT_LEAST8_WIDTH 8
#  elif INT_LEAST8_MIN == -32768 && INT_LEAST8_MAX == 32767
#   define INT_LEAST8_WIDTH 16
#  elif INT_LEAST8_MIN == -2147483648 && INT_LEAST8_MAX == 2147483647
#   define INT_LEAST8_WIDTH 32
#  elif INT_LEAST8_MIN == -9223372036854775807LL-1 \
	&& INT_LEAST8_MAX == 9223372036854775807LL
#   define INT_LEAST8_WIDTH 64
#  elif defined(FT_REQUIRE_INT_LEAST8_WIDTH)
#   error Failed to determine INT_LEAST8_WIDTH
#  endif
# endif
# ifndef INT_LEAST16_WIDTH
#  if !defined(FT_PEDANTIC) && defined(FT_REQUIRE_INT_LEAST16_WIDTH)
/*  don't define INT_LEAST16_WIDTH unless required if FT_PEDANTIC is on */
#  elif INT_LEAST16_MIN == -32768 && INT_LEAST16_MAX == 32767
#   define INT_LEAST16_WIDTH 16
#  elif INT_LEAST16_MIN == -2147483648 && INT_LEAST16_MAX == 2147483647
#   define INT_LEAST16_WIDTH 32
#  elif INT_LEAST16_MIN == -9223372036854775807LL-1 \
	&& INT_LEAST16_MAX == 9223372036854775807LL
#   define INT_LEAST16_WIDTH 64
#  elif defined(FT_REQUIRE_INT_LEAST16_WIDTH)
#   error Failed to determine INT_LEAST16_WIDTH
#  endif
# endif
# ifndef INT_LEAST32_WIDTH
#  if !defined(FT_PEDANTIC) && defined(FT_REQUIRE_INT_LEAST32_WIDTH)
/*  don't define INT_LEAST32_WIDTH unless required if FT_PEDANTIC is on */
#  elif INT_LEAST32_MIN == -2147483648 && INT_LEAST32_MAX == 2147483647
#   define INT_LEAST32_WIDTH 32
#  elif INT_LEAST32_MIN == -9223372036854775807LL-1 \
	&& INT_LEAST32_MAX == 9223372036854775807LL
#   define INT_LEAST32_WIDTH 64
#  elif defined(FT_REQUIRE_INT_LEAST32_WIDTH)
#   error Failed to determine INT_LEAST32_WIDTH
#  endif
# endif
# ifndef INT_LEAST64_WIDTH
#  if !defined(FT_PEDANTIC) && defined(FT_REQUIRE_INT_LEAST64_WIDTH)
/*  don't define INT_LEAST64_WIDTH unless required if FT_PEDANTIC is on */
#  elif INT_LEAST64_MIN == -9223372036854775807LL-1 \
	&& INT_LEAST64_MAX == 9223372036854775807LL
#   define INT_LEAST64_WIDTH 64
#  elif defined(FT_REQUIRE_INT_LEAST64_WIDTH)
#   error Failed to determine INT_LEAST64_WIDTH
#  endif
# endif
/* end required fixed-width signed int types */

/* required fixed-width unsigned int types */
typedef uint_fast8_t		t_uf0;
# ifndef UINT_FAST8_WIDTH
#  if UINT_FAST8_MAX == 255
#   define UINT_FAST8_WIDTH 8
#  elif UINT_FAST8_MAX == 65535
#   define UINT_FAST8_WIDTH 16
#  elif UINT_FAST8_MAX == 4294967295U
#   define UINT_FAST8_WIDTH 32
#  elif UINT_FAST8_MAX == 18446744073709551615ULL
#   define UINT_FAST8_WIDTH 64
#  elif defined(FT_REQUIRE_UINT_FAST8_WIDTH)
#   error Failed to determine UINT_FAST8_WIDTH
#  endif
# endif

typedef uint_fast16_t		t_uf1;
# ifndef UINT_FAST16_WIDTH
#  if UINT_FAST16_MAX == 65535
#   define UINT_FAST16_WIDTH 16
#  elif UINT_FAST16_MAX == 4294967295U
#   define UINT_FAST16_WIDTH 32
#  elif UINT_FAST16_MAX == 18446744073709551615ULL
#   define UINT_FAST16_WIDTH 64
#  elif defined(FT_REQUIRE_UINT_FAST16_WIDTH)
#   error Failed to determine UINT_FAST16_WIDTH
#  endif
# endif

typedef uint_fast32_t		t_uf2;
# ifndef UINT_FAST32_WIDTH
#  if UINT_FAST32_MAX == 4294967295U
#   define UINT_FAST32_WIDTH 32
#  elif UINT_FAST32_MAX == 18446744073709551615ULL
#   define UINT_FAST32_WIDTH 64
#  elif defined(FT_REQUIRE_UINT_FAST32_WIDTH)
#   error Failed to determine UINT_FAST32_WIDTH
#  endif
# endif

typedef uint_fast64_t		t_uf3;
# ifndef UINT_FAST64_WIDTH
#  if UINT_FAST64_MAX == 18446744073709551615ULL
#   define UINT_FAST64_WIDTH 64
#  elif defined(FT_REQUIRE_UINT_FAST64_WIDTH)
#   error Failed to determine UINT_FAST64_WIDTH
#  endif
# endif

typedef uint_least8_t		t_ul0;
# ifndef UINT_LEAST8_WIDTH
#  if UINT_LEAST8_MAX == 255
#   define UINT_LEAST8_WIDTH 8
#  elif UINT_LEAST8_MAX == 65535
#   define UINT_LEAST8_WIDTH 16
#  elif UINT_LEAST8_MAX == 4294967295U
#   define UINT_LEAST8_WIDTH 32
#  elif UINT_LEAST8_MAX == 18446744073709551615ULL
#   define UINT_LEAST8_WIDTH 64
#  elif defined(FT_REQUIRE_UINT_LEAST8_WIDTH)
#   error Failed to determine UINT_LEAST8_WIDTH
#  endif
# endif

typedef uint_least16_t		t_ul1;
# ifndef UINT_LEAST16_WIDTH
#  if UINT_LEAST16_MAX == 65535
#   define UINT_LEAST16_WIDTH 16
#  elif UINT_LEAST16_MAX == 4294967295U
#   define UINT_LEAST16_WIDTH 32
#  elif UINT_LEAST16_MAX == 18446744073709551615ULL
#   define UINT_LEAST16_WIDTH 64
#  elif defined(FT_REQUIRE_UINT_LEAST16_WIDTH)
#   error Failed to determine UINT_LEAST16_WIDTH
#  endif
# endif

typedef uint_least32_t		t_ul2;
# ifndef UINT_LEAST32_WIDTH
#  if UINT_LEAST32_MAX == 4294967295U
#   define UINT_LEAST32_WIDTH 32
#  elif UINT_LEAST32_MAX == 18446744073709551615ULL
#   define UINT_LEAST32_WIDTH 64
#  elif defined(FT_REQUIRE_UINT_LEAST32_WIDTH)
#   error Failed to determine UINT_LEAST32_WIDTH
#  endif
# endif

typedef uint_least64_t		t_ul3;
# ifndef UINT_LEAST64_WIDTH
#  if UINT_LEAST64_MAX == 18446744073709551615ULL
#   define UINT_LEAST64_WIDTH 64
#  elif defined(FT_REQUIRE_UINT_LEAST64_WIDTH)
#   error Failed to determine UINT_LEAST64_WIDTH
#  endif
# endif
/* end required fixed-width signed int types */

/* optional fixed-width signed int types */

# if !defined(FT_PEDANTIC) && defined(FT_REQUIRE_T_I0)
/*  don't define t_i0 unless required if FT_PEDANTIC is on */
# endif
# if defined(INT8_MAX) && defined(INT8_MIN)

typedef int8_t				t_i0;

# else
/*  as C spec states, sizeof(char) is always 1 */
typedef signed char			t_i0;
# endif

# if defined(INT16_MAX) && defined(INT16_MIN)

typedef int16_t				t_i1;

# else
#  ifdef FT_REQUIRE_T_I0
#   if INT_FAST8_MIN == -128

typedef int_least8_t		t_i0;

#   elif INT_FAST8_WIDTH == 8

typedef int_fast8_t			t_i0;

#   else
#    error No t_i1 compatible type found
#   endif

#  endif
# endif

# error "not implemented"

typedef int16_t				t_i2;
typedef int32_t				t_i3;
typedef int64_t				t_i4;

#endif
