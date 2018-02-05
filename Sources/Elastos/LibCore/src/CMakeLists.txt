
add_definitions(-DHAVE_APPLE_PTHREAD_SETNAME_NP)

add_definitions(-DHAVE_GETTID
                -DHAVE_SELINUX
                -DHAVE_ANDROID_OS
                -DHAVE_PRCTL
                -DHAVE_SYS_UIO_H
                -DHAVE_OFF64_T)

xdk_add_subdirectories(
    corelibrary
    libcore
    elastos
    Lib
)

