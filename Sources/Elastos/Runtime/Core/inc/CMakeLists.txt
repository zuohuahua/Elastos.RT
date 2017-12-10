
set(EXPORT_HEADERS
    elapi.h
    elasysapi.h
    elastos.h
    spinlock.h
)

xdk_export_headers(runtime_core_headers ${EXPORT_HEADERS})
