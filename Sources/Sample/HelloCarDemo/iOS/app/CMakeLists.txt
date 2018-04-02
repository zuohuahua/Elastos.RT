cmake_minimum_required (VERSION 3.7)

include($ENV{XDK_DEFINITIONS_CMAKE})
set(CMAKE_CXX_STANDARD 11)

set(DEVELOPMENT_PROJECT_NAME "hellocarapp")                 # <== Set to your project name, e.g. project.xcodeproj
set(DEVELOPMENT_TEAM_ID "AAAAA11111")                       # <== Set to your team ID from Apple
set(APP_NAME "HelloCarApp")                                 # <== Set To your app's name
set(APP_BUNDLE_IDENTIFIER "org.elastos.hellocarapp")        # <== Set to your app's bundle identifier
set(CODE_SIGN_IDENTITY "iPhone Developer")                  # <== Set to your preferred code sign identity, to see list:
                                                            # /usr/bin/env xcrun security find-identity -v -p codesigning
set(DEPLOYMENT_TARGET 8.0)                                  # <== Set your deployment target version of iOS
set(DEVICE_FAMILY "1")                                      # <== Set to "1" to target iPhone, set to "2" to target iPad, set to "1,2" to target both

project(${DEVELOPMENT_PROJECT_NAME})
include(BundleUtilities)
include(FindXCTest)

message(STATUS XCTestFound:${XCTest_FOUND})

set(PRODUCT_NAME ${APP_NAME})
set(EXECUTABLE_NAME ${APP_NAME})
set(MACOSX_BUNDLE_EXECUTABLE_NAME ${APP_NAME})
set(MACOSX_BUNDLE_INFO_STRING ${APP_BUNDLE_IDENTIFIER})
set(MACOSX_BUNDLE_GUI_IDENTIFIER ${APP_BUNDLE_IDENTIFIER})
set(MACOSX_BUNDLE_BUNDLE_NAME ${APP_BUNDLE_IDENTIFIER})
set(MACOSX_BUNDLE_ICON_FILE "")
set(MACOSX_BUNDLE_LONG_VERSION_STRING "1.0")
set(MACOSX_BUNDLE_SHORT_VERSION_STRING "1.0")
set(MACOSX_BUNDLE_BUNDLE_VERSION "1.0")
set(MACOSX_BUNDLE_COPYRIGHT "Copyright YOU")
set(MACOSX_DEPLOYMENT_TARGET ${DEPLOYMENT_TARGET})

set(APP_HEADER_FILES
  ./AppDelegate.h
  ./ViewController.h
  ./CppInterface.h
  ./Prefix.pch
)

set(APP_SOURCE_FILES
  ./AppDelegate.m
  ./ViewController.m
  ./CppInterface.mm
  ./main.m
)

set(RESOURCES
  ./Main.storyboard
  ./LaunchScreen.storyboard
)

add_executable(
    ${APP_NAME}
    MACOSX_BUNDLE
    ${APP_HEADER_FILES}
    ${APP_SOURCE_FILES}
    ${RESOURCES}
)

# To disable bitcode:
set_target_properties(${APP_NAME} PROPERTIES XCODE_ATTRIBUTE_ENABLE_BITCODE "NO")

target_include_directories(${APP_NAME} PUBLIC
    "$ENV{XDK_USER_INC}"
    "${CMAKE_CURRENT_BINARY_DIR}/../.."
)

# Locate system libraries on iOS
find_library(UIKIT UIKit)
find_library(FOUNDATION Foundation)
find_library(MOBILECORESERVICES MobileCoreServices)
find_library(CFNETWORK CFNetwork)
find_library(SYSTEMCONFIGURATION SystemConfiguration)

# link the frameworks located above
target_link_libraries(${APP_NAME} ${UIKIT})
target_link_libraries(${APP_NAME} ${FOUNDATION})
target_link_libraries(${APP_NAME} ${MOBILECORESERVICES})
target_link_libraries(${APP_NAME} ${CFNETWORK})
target_link_libraries(${APP_NAME} ${SYSTEMCONFIGURATION})

set(CMAKE_SHARED_LIBRARY_RUNTIME_C_FLAG "-Wl,-rpath,")
set(CMAKE_SHARED_LIBRARY_RUNTIME_C_FLAG_SEP ":")

add_library( Elastos.Runtime SHARED IMPORTED GLOBAL )
set_target_properties( Elastos.Runtime PROPERTIES IMPORTED_LOCATION $ENV{XDK_TARGETS}/Elastos.Runtime.eco )
target_link_libraries(${APP_NAME} Elastos.Runtime)

target_link_libraries(${APP_NAME}
    $ENV{XDK_USER_LIB}/libElastos.Runtime_static.a
    $ENV{XDK_USER_LIB}/libElastos.HelloCarDemo.UUIDs.a)


# Turn on ARC
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fobjc-arc")

# Create the app target
set_target_properties(${APP_NAME} PROPERTIES
                      XCODE_ATTRIBUTE_DEBUG_INFORMATION_FORMAT "dwarf-with-dsym"
                      XCODE_ATTRIBUTE_GCC_PREFIX_HEADER "${CMAKE_CURRENT_SOURCE_DIR}/Prefix.pch"
                      RESOURCE "${RESOURCES}"
                      XCODE_ATTRIBUTE_GCC_PRECOMPILE_PREFIX_HEADER "YES"
                      XCODE_ATTRIBUTE_IPHONEOS_DEPLOYMENT_TARGET ${DEPLOYMENT_TARGET}
                      XCODE_ATTRIBUTE_CODE_SIGN_IDENTITY ${CODE_SIGN_IDENTITY}
                      XCODE_ATTRIBUTE_DEVELOPMENT_TEAM ${DEVELOPMENT_TEAM_ID}
                      XCODE_ATTRIBUTE_TARGETED_DEVICE_FAMILY ${DEVICE_FAMILY}
                      MACOSX_BUNDLE_INFO_PLIST ${CMAKE_CURRENT_SOURCE_DIR}/plist.in
                      XCODE_ATTRIBUTE_CLANG_ENABLE_OBJC_ARC YES
                      XCODE_ATTRIBUTE_COMBINE_HIDPI_IMAGES NO
                      XCODE_ATTRIBUTE_INSTALL_PATH "$(LOCAL_APPS_DIR)"
                      XCODE_ATTRIBUTE_ENABLE_TESTABILITY YES
                      XCODE_ATTRIBUTE_GCC_SYMBOLS_PRIVATE_EXTERN YES
)

# Set the app's linker search path to the default location on iOS
set_target_properties(
    ${APP_NAME}
    PROPERTIES
    XCODE_ATTRIBUTE_LD_RUNPATH_SEARCH_PATHS
    "@executable_path/Frameworks"
)

# Note that commands below are indented just for readability. They will endup as
# one liners after processing and unescaped ; will disappear so \; are needed.
# First condition in each command is for normal build, second for archive.
# \&\>/dev/null makes sure that failure of one command and success of other
# is not printed and does not make Xcode complain that /bin/sh failed and build
# continued.

# Create Frameworks directory in app bundle
add_custom_command(
    TARGET
    ${APP_NAME}
    POST_BUILD COMMAND /bin/sh -c
    \"COMMAND_DONE=0 \;
    if ${CMAKE_COMMAND} -E make_directory
        ${PROJECT_BINARY_DIR}/\${CONFIGURATION}\${EFFECTIVE_PLATFORM_NAME}/${APP_NAME}.app/Frameworks
        \&\>/dev/null \; then
        COMMAND_DONE=1 \;
    fi \;
    if ${CMAKE_COMMAND} -E make_directory
        \${BUILT_PRODUCTS_DIR}/${APP_NAME}.app/Frameworks
        \&\>/dev/null \; then
        COMMAND_DONE=1 \;
    fi \;
    if [ \\$$COMMAND_DONE -eq 0 ] \; then
        echo Failed to create Frameworks directory in app bundle \;
        exit 1 \;
    fi\"
)

# Copy the framework into the app bundle
add_custom_command(
    TARGET
    ${APP_NAME}
    POST_BUILD COMMAND /bin/sh -c
    \"COMMAND_DONE=0 \;
    if ${CMAKE_COMMAND} -E copy
        $ENV{XDK_TARGETS}/Elastos.Runtime.eco
        $ENV{XDK_TARGETS}/Elastos.CoreLibrary.eco
        $ENV{XDK_TARGETS}/Elastos.HelloCarDemo.eco
        \${BUILT_PRODUCTS_DIR}/${APP_NAME}.app/Frameworks/
        \&\>/dev/null \; then
        COMMAND_DONE=1 \;
    fi \;
    if [ \\$$COMMAND_DONE -eq 0 ] \; then
        echo Failed to copy the framework into the app bundle \;
        exit 1 \;
    fi\"
)

# Codesign the framework in it's new spot
add_custom_command(
    TARGET
    ${APP_NAME}
    POST_BUILD COMMAND /bin/sh -c
    \"COMMAND_DONE=0 \;
    if codesign --force --verbose
        \${BUILT_PRODUCTS_DIR}/${APP_NAME}.app/Frameworks/Elastos.Runtime.eco
        --sign ${CODE_SIGN_IDENTITY}
        \&\>/dev/null \; then
        COMMAND_DONE=1 \;
    fi \;
    if codesign --force --verbose
        \${BUILT_PRODUCTS_DIR}/${APP_NAME}.app/Frameworks/Elastos.CoreLibrary.eco
        --sign ${CODE_SIGN_IDENTITY}
        \&\>/dev/null \; then
        COMMAND_DONE=1 \;
    fi \;
    if codesign --force --verbose
        \${BUILT_PRODUCTS_DIR}/${APP_NAME}.app/Frameworks/Elastos.HelloCarDemo.eco
        --sign ${CODE_SIGN_IDENTITY}
        \&\>/dev/null \; then
        COMMAND_DONE=1 \;
    fi \;
    if [ -n '$ENV{XDK_SKIP_CODE_SIGN}' ] \; then
        echo Framework codesign skiped \;
        exit 0 \;
    fi \;
    if [ \\$$COMMAND_DONE -eq 0 ] \; then
        echo Framework codesign failed \;
        exit 1 \;
    fi\"
)

# Add a "PlugIns" folder as a kludge fix for how the XcTest package generates paths
add_custom_command(
    TARGET
    ${APP_NAME}
    POST_BUILD COMMAND /bin/sh -c
    \"COMMAND_DONE=0 \;
    if ${CMAKE_COMMAND} -E make_directory
        ${PROJECT_BINARY_DIR}/\${CONFIGURATION}\${EFFECTIVE_PLATFORM_NAME}/PlugIns
        \&\>/dev/null \; then
        COMMAND_DONE=1 \;
    fi \;
    if [ \\$$COMMAND_DONE -eq 0 ] \; then
        echo Failed to create PlugIns directory in EFFECTIVE_PLATFORM_NAME folder. \;
        exit 1 \;
    fi\"
)
