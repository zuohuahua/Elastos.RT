

set(SOURCES
# ifeq "$(XDK_TARGET_CPU)" "arm"
# ifneq "$(XDK_COMPILER)" "gnu"
# SOURCES = invoke_ievc.asm
# else
# SOURCES = invoke_gnuc.S
# endif
# else
# SOURCES = invoke.cpp
# endif
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

add_definitions(-D_CAR_RUNTIME)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../inc)

add_library(reflection STATIC ${SOURCES})

