project(coreTLS)

add_compile_options(
	-nostdinc
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

set(DYLIB_INSTALL_NAME "/usr/lib/system/libsystem_coretls.dylib")
add_circular(system_coretls FAT
	SOURCES
		lib/tls_cache.c
		lib/appleSession.c

		lib/tls_ciphersuites.c

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

		lib/tls_stream_parser.c

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
		system_asl
)
#set_target_properties(system_coretls PROPERTIES LINK_FLAGS
#	"-Wl,-exported_symbols_list,${CMAKE_CURRENT_SOURCE_DIR}/coretls.exp")

install(TARGETS system_coretls DESTINATION libexec/darling/usr/lib/system)
