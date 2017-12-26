

set(SOURCES
    CClsModule.cpp
    CObjInfoList.cpp
    CEntryList.cpp
    refutil.cpp
    reflection.cpp
    CAnnotationInfo.cpp
    CArgumentList.cpp
    CCarArrayInfo.cpp
    CVariableOfCarArray.cpp
    CClassInfo.cpp
    CConstantInfo.cpp
    CConstructorInfo.cpp
    CCppVectorInfo.cpp
    CEnumInfo.cpp
    CEnumItemInfo.cpp
    CFieldInfo.cpp
    CInterfaceInfo.cpp
    CIntrinsicInfo.cpp
    CLocalPtrInfo.cpp
    CLocalTypeInfo.cpp
    CMethodInfo.cpp
    CModuleInfo.cpp
    CParamInfo.cpp
    CStructInfo.cpp
    CVariableOfStruct.cpp
    CVariableOfCppVector.cpp
    CTypeAliasInfo.cpp
)


# if("$ENV{XDK_TARGET_CPU}" STREQUAL "arm")
#     list(APPEND SOURCES invoke_gnuc.S)
# else()
    list(APPEND SOURCES invoke.cpp)
# endif()

add_definitions(-D_CAR_RUNTIME)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../inc)

add_library(reflection STATIC ${SOURCES})

