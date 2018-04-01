
if("$ENV{XDK_TARGET_PLATFORM}" STREQUAL "ios")
    include(openssl.cmake)
    include(icu.cmake)
endif()
