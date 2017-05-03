project(coreTLS)

add_compile_options(
	-nostdinc
	-Wno-visibility
)

add_definitions(
	-DCCCBC_RETURN_INT
)

include_directories(
	${CMAKE_CURRENT_SOURCE_DIR}/lib
)

set(DYLIB_COMPAT_VERSION "1.0.0")
set(DYLIB_CURRENT_VERSION "121.50.4")

set(DYLIB_INSTALL_NAME "/usr/lib/libcoretls.dylib")
add_darling_library(coretls SHARED
	dummy.c
)
target_link_libraries(coretls system)
make_fat(coretls)
install(TARGETS coretls DESTINATION libexec/darling/usr/lib)

set(coretls_ciphersuites_sources
	lib/tls_ciphersuites.c
)

set(coretls_record_sources
	lib/tls_record_crypto.c
	lib/tls_record.c
	lib/sslRc4Cipher.c
	lib/sslMemory.c
	lib/sslUtils.c
	lib/symCipherParams.c
	lib/sslNullCipher.c
	lib/symCipher.c
	lib/tls_digest.c
	lib/tls_hmac.c
	lib/sslAesGcmCipher.c
)

set(coretls_handshake_sources
	lib/sslDecode.c
	lib/sslSession.c
	lib/sslCipherSpecs.c
	lib/sslDigests.c
	lib/sslCrypto.c
	lib/sslChangeCipher.c
	lib/sslCert.c
	lib/tls_metrics.c
	lib/sslKeyExchange.c
	lib/sslAlertMessage.c
	lib/sslHandshake.c
	lib/sslHandshakeFinish.c
	lib/tls1Callouts.c
	lib/sslHandshakeHello.c
	lib/tls_handshake.c
	lib/ssl3Callouts.c
)

set(coretls_stream_parser_sources
	lib/tls_stream_parser.c
)

set(DYLIB_INSTALL_NAME "/usr/lib/system/libsystem_coretls.dylib")
add_circular(system_coretls FAT
	SOURCES
		lib/tls_cache.c
		lib/appleSession.c
		${coretls_ciphersuites_sources}
		${coretls_record_sources}
		${coretls_handshake_sources}
		${coretls_stream_parser_sources}

	SIBLINGS
		system_dyld
		compiler_rt
		system_kernel
		platform
		system_malloc
		system_c
		system_blocks
		system_pthread
		macho
		libdispatch_shared
		corecrypto
		xpc
)
make_fat(system_coretls)
install(TARGETS system_coretls DESTINATION libexec/darling/usr/lib/system)
