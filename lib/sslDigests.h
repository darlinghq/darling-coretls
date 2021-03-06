/*
 * Copyright (c) 1999-2001,2005-2007,2010-2012 Apple Inc. All Rights Reserved.
 *
 * @APPLE_LICENSE_HEADER_START@
 *
 * This file contains Original Code and/or Modifications of Original Code
 * as defined in and that are subject to the Apple Public Source License
 * Version 2.0 (the 'License'). You may not use this file except in
 * compliance with the License. Please obtain a copy of the License at
 * http://www.opensource.apple.com/apsl/ and read it before using this
 * file.
 *
 * The Original Code and all software distributed under the License are
 * distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR NON-INFRINGEMENT.
 * Please see the License for the specific language governing rights and
 * limitations under the License.
 *
 * @APPLE_LICENSE_HEADER_END@
 */

/*
 * sslDigests.h - HashReference declarations
 */

#ifndef	_SSL_DIGESTS_H_
#define _SSL_DIGESTS_H_	1

#include <MacTypes.h>
#include "sslMemory.h"
#include "tls_digest.h"
#include "tls_types.h"

#ifdef __cplusplus
extern "C" {
#endif

CORETLS_EXTERN int CloneHashState(
	const HashReference *ref,
	const tls_buffer *state,
	tls_buffer *newState);
CORETLS_EXTERN int ReadyHash(
	const HashReference *ref, 
	tls_buffer *state);
CORETLS_EXTERN int CloseHash(
	const HashReference *ref, 
	tls_buffer *state);

#ifdef __cplusplus
}
#endif

#endif	/* _SSL_DIGESTS_H_ */
