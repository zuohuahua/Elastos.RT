
set(SOURCES
    # BasicLruCache.cpp
    # CBasicLruCache.cpp
    EmptyArray.cpp
    # CZoneInfoDB.cpp
    # CCollectionUtils.cpp
    # ZoneInfo.cpp
    # CZoneInfoWallTime.cpp
    # COffsetIntervalHelper.cpp
    # CZoneInfoHelper.cpp
)

add_definitions(-DELASTOS_CORELIBRARY)

include_directories(${CMAKE_CURRENT_BINARY_DIR}/../../corelibrary)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../../inc)

add_library(libcore.utility STATIC ${SOURCES})
add_dependencies(libcore.utility Elastos.CoreLibrary.car)


