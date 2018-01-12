
xdk_combine_static_libraries(Elastos.Runtime_static
    $<TARGET_FILE:lib4car>
    $<TARGET_FILE:elstring>
    $<TARGET_FILE:elrefbase>
    $<TARGET_FILE:elcontainer>
)

