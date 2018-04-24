# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)

link_directories(${CMAKE_SOURCE_DIR}/src/main/cpp/elastos/libs/armeabi-v7a/)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

add_library( Elastos.Runtime SHARED IMPORTED )

set_target_properties( Elastos.Runtime
                        PROPERTIES IMPORTED_LOCATION
                        ${CMAKE_SOURCE_DIR}/src/main/cpp/elastos/libs/armeabi-v7a/libElastos.Runtime.so)

add_library( Elastos.Runtime.Lib SHARED IMPORTED )
set_target_properties( Elastos.Runtime.Lib
                        PROPERTIES IMPORTED_LOCATION
                        ${CMAKE_SOURCE_DIR}/src/main/cpp/elastos/libs/libElastos.Runtime_static.a)

add_library( Elastos.CoreLibrary SHARED IMPORTED )
set_target_properties( Elastos.CoreLibrary
                        PROPERTIES IMPORTED_LOCATION
                        ${CMAKE_SOURCE_DIR}/src/main/cpp/elastos/libs/armeabi-v7a/libElastos.CoreLibrary.so)

add_library( Switch SHARED IMPORTED )
set_target_properties( Switch
                        PROPERTIES IMPORTED_LOCATION
                        ${CMAKE_SOURCE_DIR}/src/main/cpp/elastos/libs/armeabi-v7a/libSwitch.so)
add_library( # Sets the name of the library.
             native-lib

             # Sets the library as a shared library.
             SHARED

             # Provides a relative path to your source file(s).
             src/main/cpp/native-lib.cpp
             src/main/cpp/CCarrierListener.cpp
             src/main/cpp/CSwitchListener.cpp)

# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

find_library( # Sets the name of the path variable.
              log-lib

              # Specifies the name of the NDK library that
              # you want CMake to locate.
              log )

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries( # Specifies the target library.
                       native-lib

                       # Links the target library to the log library
                       # included in the NDK.
                       ${log-lib}
                       Elastos.Runtime
                       Elastos.Runtime.Lib
                       Elastos.CoreLibrary
                       Switch
                       elasession )

include_directories(src/main/cpp/elastos/inc)
