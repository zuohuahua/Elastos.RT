
if(APPLE)
    add_definitions(-DHAVE_APPLE_PTHREAD_SETNAME_NP)
else()
    add_definitions(-DHAVE_ANDROID_PTHREAD_SETNAME_NP)
endif()

add_definitions(-DHAVE_GETTID
                -DHAVE_SELINUX
                -DHAVE_ANDROID_OS
                -DHAVE_PRCTL
                -DHAVE_SYS_UIO_H
                -DHAVE_OFF64_T
                -D_INSIDE_ELASTOS_CORELIBRARY_)

xdk_add_subdirectories(
    corelibrary
    libcore
    elastos
)

