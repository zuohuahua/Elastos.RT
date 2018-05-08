
if("$ENV{XDK_TARGET_PLATFORM}" STREQUAL "ios")
    include(openssl.cmake)
    include(icu.cmake)
endif()

if(NOT ("$ENV{XDK_TARGET_PLATFORM}" STREQUAL "linux" AND "$ENV{XDK_TARGET_CPU_ARCH}" STREQUAL "32"))
    include(elacarrier.cmake)
endif()
