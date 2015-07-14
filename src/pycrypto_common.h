/*
 *  pycrypto_compat.h: Common header file for PyCrypto
 *
 * Written in 2013 by Dwayne C. Litzenberger <dlitz@dlitz.net>
 *
 * ===================================================================
 * The contents of this file are dedicated to the public domain.  To
 * the extent that dedication to the public domain is not available,
 * everyone is granted a worldwide, perpetual, royalty-free,
 * non-exclusive license to exercise all rights associated with the
 * contents of this file for any purpose whatsoever.
 * No rights are reserved.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 * ===================================================================
 */
#ifndef PYCRYPTO_COMMON_H
#define PYCRYPTO_COMMON_H

#include "Python.h"
#include "pycrypto_compat.h"
#include "config.h"
#if HAVE_STDINT_H
# include <stdint.h>
#elif HAVE_INTTYPES_H
# include <inttypes.h>
#elif HAVE_SYS_INTTYPES_H
# include <sys/inttypes.h>
#else
# error "stdint.h and inttypes.h not found"
#endif

#endif /* PYCRYPTO_COMMON_H */

// Reference: http://stackoverflow.com/questions/1489932/how-to-concatenate-twice-with-the-c-preprocessor-and-expand-a-macro-as-in-arg
// This is not inside the PYCRYPTO_COMMON_H block as we need MODULE_NAME to be defined
#ifndef PCFN
#ifdef MODULE_NAME
#define PASTER(x,y) (x ## _ ## y)
#define EVALUATOR(x,y) PASTER(x,y)
#define PCFN(fun) EVALUATOR(fun, MODULE_NAME)
#endif
#endif
