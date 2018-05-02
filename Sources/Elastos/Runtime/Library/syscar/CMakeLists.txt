
set(CAR_FLAGS -e -A -k)
set(LUBE_FLAGS -e -k -z)
set(LUBE_TS -T uuidcpp)

include(ElastosCore.cmake)
xdk_export_car_headers(export_headers ${CURRENT_MIRROR_HEADERS})
xdk_compile_car(CAR_GENERATED_SOURCES ElastosCore.car ${export_headers})

