
add_custom_command(
    COMMENT "Compiling lube.lub..."
    OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/lube.lbo"
           "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/lube.lbo"
    COMMAND ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/lubc -I${CMAKE_CURRENT_SOURCE_DIR} -o lube.lbo ${CMAKE_CURRENT_SOURCE_DIR}/lube.lub
    COMMAND ${CMAKE_COMMAND} -E copy lube.lbo "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/lube.lbo"
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    DEPENDS
        ${CMAKE_CURRENT_SOURCE_DIR}/background/backcpp.lub
        ${CMAKE_CURRENT_SOURCE_DIR}/background/background.lub
        ${CMAKE_CURRENT_SOURCE_DIR}/background/backh.lub
        ${CMAKE_CURRENT_SOURCE_DIR}/background/nakedbackh.lub
        ${CMAKE_CURRENT_SOURCE_DIR}/background/nakedbackcpp.lub
        ${CMAKE_CURRENT_SOURCE_DIR}/background/clsobjh.lub
        ${CMAKE_CURRENT_SOURCE_DIR}/background/clsobjcpp.lub
        ${CMAKE_CURRENT_SOURCE_DIR}/background/declaspect.lub
        ${CMAKE_CURRENT_SOURCE_DIR}/background/declbase.lub
        ${CMAKE_CURRENT_SOURCE_DIR}/background/declcallback.lub
        ${CMAKE_CURRENT_SOURCE_DIR}/background/declfilter.lub
        ${CMAKE_CURRENT_SOURCE_DIR}/background/declregime.lub
        ${CMAKE_CURRENT_SOURCE_DIR}/background/declsync.lub
        ${CMAKE_CURRENT_SOURCE_DIR}/background/implaspect.lub
        ${CMAKE_CURRENT_SOURCE_DIR}/background/implbase.lub
        ${CMAKE_CURRENT_SOURCE_DIR}/background/implcallback.lub
        ${CMAKE_CURRENT_SOURCE_DIR}/background/implfilter.lub
        ${CMAKE_CURRENT_SOURCE_DIR}/background/implregime.lub
        ${CMAKE_CURRENT_SOURCE_DIR}/background/implsync.lub
        ${CMAKE_CURRENT_SOURCE_DIR}/background/modpub.lub
        ${CMAKE_CURRENT_SOURCE_DIR}/background/callbacksinkcpp.lub
        ${CMAKE_CURRENT_SOURCE_DIR}/background/callbacksinkh.lub
        ${CMAKE_CURRENT_SOURCE_DIR}/background/sinkcpp.lub
        ${CMAKE_CURRENT_SOURCE_DIR}/background/sinkh.lub
        ${CMAKE_CURRENT_SOURCE_DIR}/background/aspectintf.lub
        ${CMAKE_CURRENT_SOURCE_DIR}/background/superh.lub
        ${CMAKE_CURRENT_SOURCE_DIR}/background/genericnew.lub
        ${CMAKE_CURRENT_SOURCE_DIR}/background/makefile.lub
        ${CMAKE_CURRENT_SOURCE_DIR}/carusage/carusage.lub
        ${CMAKE_CURRENT_SOURCE_DIR}/carusage/methodusage.lub
        ${CMAKE_CURRENT_SOURCE_DIR}/carusage/interfaceusage.lub
        ${CMAKE_CURRENT_SOURCE_DIR}/carusage/classusage.lub
        ${CMAKE_CURRENT_SOURCE_DIR}/carusage/objectusage.lub
        ${CMAKE_CURRENT_SOURCE_DIR}/carusage/callbackusage.lub
        ${CMAKE_CURRENT_SOURCE_DIR}/carusage/genericusage.lub
        ${CMAKE_CURRENT_SOURCE_DIR}/carusage/aspectusage.lub
        ${CMAKE_CURRENT_SOURCE_DIR}/carusage/regimeusage.lub
        ${CMAKE_CURRENT_SOURCE_DIR}/carusage/enumusage.lub
        ${CMAKE_CURRENT_SOURCE_DIR}/carusage/constusage.lub
        ${CMAKE_CURRENT_SOURCE_DIR}/carusage/structusage.lub
        ${CMAKE_CURRENT_SOURCE_DIR}/foreground/forecpp.lub
        ${CMAKE_CURRENT_SOURCE_DIR}/foreground/forecpph.lub
        ${CMAKE_CURRENT_SOURCE_DIR}/foreground/foregeneric.lub
        ${CMAKE_CURRENT_SOURCE_DIR}/foreground/foreground.lub
        ${CMAKE_CURRENT_SOURCE_DIR}/foreground/foreh.lub
        ${CMAKE_CURRENT_SOURCE_DIR}/foreground/nakedforeh.lub
        ${CMAKE_CURRENT_SOURCE_DIR}/foreground/nakedforecpp.lub
        ${CMAKE_CURRENT_SOURCE_DIR}/foreground/sources.lub
        ${CMAKE_CURRENT_SOURCE_DIR}/header/baseh.lub
        ${CMAKE_CURRENT_SOURCE_DIR}/header/trigger.lub
        ${CMAKE_CURRENT_SOURCE_DIR}/header/classobj.lub
        ${CMAKE_CURRENT_SOURCE_DIR}/header/basenew.lub
        ${CMAKE_CURRENT_SOURCE_DIR}/header/nakedbasenew.lub
        ${CMAKE_CURRENT_SOURCE_DIR}/header/supernew.lub
        ${CMAKE_CURRENT_SOURCE_DIR}/header/classnew.lub
        ${CMAKE_CURRENT_SOURCE_DIR}/header/nakedclassnew.lub
        ${CMAKE_CURRENT_SOURCE_DIR}/header/supercallback.lub
        ${CMAKE_CURRENT_SOURCE_DIR}/header/clientcallback.lub
        ${CMAKE_CURRENT_SOURCE_DIR}/header/cstyleh.lub
        ${CMAKE_CURRENT_SOURCE_DIR}/header/decltype.lub
        ${CMAKE_CURRENT_SOURCE_DIR}/header/decluuid.lub
        ${CMAKE_CURRENT_SOURCE_DIR}/header/header.lub
        ${CMAKE_CURRENT_SOURCE_DIR}/header/header2.lub
        ${CMAKE_CURRENT_SOURCE_DIR}/header/clienth.lub
        ${CMAKE_CURRENT_SOURCE_DIR}/header/serverh.lub
        ${CMAKE_CURRENT_SOURCE_DIR}/header/genericcallback.lub
        ${CMAKE_CURRENT_SOURCE_DIR}/headercpp/headercpp.lub
        ${CMAKE_CURRENT_SOURCE_DIR}/headercpp/basecpp.lub
        ${CMAKE_CURRENT_SOURCE_DIR}/public/cls2abrg.lub
        ${CMAKE_CURRENT_SOURCE_DIR}/public/cls2car.lub
        ${CMAKE_CURRENT_SOURCE_DIR}/public/public.lub
        ${CMAKE_CURRENT_SOURCE_DIR}/public/uuidcpp.lub
        ${CMAKE_CURRENT_SOURCE_DIR}/public/uuidh.lub
)

add_custom_target(lube_templates ALL DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/lube.lbo)

