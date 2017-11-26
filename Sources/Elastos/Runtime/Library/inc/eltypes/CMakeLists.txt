
set(EXPORT_HEADERS
    eltypes.h
    elsharedbuf.h
    elstring.h
    elrefbase.h
    elautoptr.h
    elquintettype.h
    elquintet.h
    elalloc.h
    elcontainer.h
    eldebugdef.h
)

xdk_export_headers(eltypes_headers ${EXPORT_HEADERS})
