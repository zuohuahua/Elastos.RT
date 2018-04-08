
if("$ENV{XDK_TARGET_PLATFORM}" STREQUAL "ios")
    include(openssl.cmake)
    include(icu.cmake)
elseif("$ENV{XDK_TARGET_PLATFORM}" STREQUAL "android")
    include(elacarrier.cmake)
endif()
