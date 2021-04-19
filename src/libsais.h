/*--

This file is a part of libsais, a library for linear time
suffix array and burrows wheeler transform construction.

   Copyright (c) 2021 Ilya Grebnov <ilya.grebnov@gmail.com>

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.

Please see the file LICENSE for full copyright information.

--*/

#ifndef LIBSAIS_H
#define LIBSAIS_H 1

#ifdef __cplusplus
extern "C" {
#endif

    /**
    * Creates the libsais context that allows reusing allocated memory with each libsais operation. 
    * In multi-threaded environments, use one context per thread for parallel executions.
    * @return the libsais context, NULL otherwise.
    */
    void * libsais_create_ctx(void);

#if defined(_OPENMP)
    /**
    * Creates the libsais context that allows reusing allocated memory with each parallel libsais operation using OpenMP. 
    * In multi-threaded environments, use one context per thread for parallel executions.
    * @param threads The number of OpenMP threads to use (can be 0 for OpenMP default).
    * @return the libsais context, NULL otherwise.
    */
    void * libsais_create_ctx_omp(int threads);
#endif

    /**
    * Destroys the libsass context and free previusly allocated memory.
    * @param ctx The libsais context (can be NULL).
    */
    void libsais_free_ctx(void * ctx);

    /**
    * Constructs the suffix array of a given string.
    * @param T [0..n-1] The input string.
    * @param SA [0..n-1+fs] The output array of suffixes.
    * @param n The length of the given string.
    * @param fs Extra space available at the end of SA array (can be 0).
    * @return 0 if no error occurred, -1 or -2 otherwise.
    */
    int libsais(const unsigned char * T, int * SA, int n, int fs);

    /**
    * Constructs the suffix array of a given string using libsais context.
    * @param ctx The libsais context.
    * @param T [0..n-1] The input string.
    * @param SA [0..n-1+fs] The output array of suffixes.
    * @param n The length of the given string.
    * @param fs Extra space available at the end of SA array (can be 0).
    * @return 0 if no error occurred, -1 or -2 otherwise.
    */
    int libsais_ctx(const void * ctx, const unsigned char * T, int * SA, int n, int fs);

#if defined(_OPENMP)
    /**
    * Constructs the suffix array of a given string in parallel using OpenMP.
    * @param T [0..n-1] The input string.
    * @param SA [0..n-1+fs] The output array of suffixes.
    * @param n The length of the given string.
    * @param fs Extra space available at the end of SA array (can be 0).
    * @param threads The number of OpenMP threads to use (can be 0 for OpenMP default).
    * @return 0 if no error occurred, -1 or -2 otherwise.
    */
    int libsais_omp(const unsigned char * T, int * SA, int n, int fs, int threads);
#endif

    /**
    * Constructs the burrows-wheeler transformed string of a given string.
    * @param T [0..n-1] The input string.
    * @param U [0..n-1] The output string (can be T).
    * @param A [0..n-1+fs] The temporary array.
    * @param n The length of the given string.
    * @param fs Extra space available at the end of A array (can be 0).
    * @return The primary index if no error occurred, -1 or -2 otherwise.
    */
    int libsais_bwt(const unsigned char * T, unsigned char * U, int * A, int n, int fs);

    /**
    * Constructs the burrows-wheeler transformed string of a given string using libsais context.
    * @param ctx The libsais context.
    * @param T [0..n-1] The input string.
    * @param U [0..n-1] The output string (can be T).
    * @param A [0..n-1+fs] The temporary array.
    * @param n The length of the given string.
    * @param fs Extra space available at the end of A array (can be 0).
    * @return The primary index if no error occurred, -1 or -2 otherwise.
    */
    int libsais_bwt_ctx(const void * ctx, const unsigned char * T, unsigned char * U, int * A, int n, int fs);

#if defined(_OPENMP)
    /**
    * Constructs the burrows-wheeler transformed string of a given string in parallel using OpenMP.
    * @param T [0..n-1] The input string.
    * @param U [0..n-1] The output string (can be T).
    * @param A [0..n-1+fs] The temporary array.
    * @param n The length of the given string.
    * @param fs Extra space available at the end of A array (can be 0).
    * @param threads The number of OpenMP threads to use (can be 0 for OpenMP default).
    * @return The primary index if no error occurred, -1 or -2 otherwise.
    */
    int libsais_bwt_omp(const unsigned char * T, unsigned char * U, int * A, int n, int fs, int threads);
#endif

#ifdef __cplusplus
}
#endif

#endif
