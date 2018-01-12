
set(SOURCES
    CMatcher.cpp
    CMatcherHelper.cpp
    CPatternHelper.cpp
    CSplitter.cpp
    MatchResultImpl.cpp
    Pattern.cpp
)

add_definitions(-DELASTOS_CORELIBRARY)

include_directories(${CMAKE_CURRENT_BINARY_DIR}/../../../corelibrary)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../../../inc/elastos)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../../../inc/elastos/core)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../../../inc/elastos/utility)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../../../inc/elastos/utility/regex)
# include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../../../inc/org)
# include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../../../inc/org/android_prebuilt)

add_library(regex STATIC ${SOURCES})



