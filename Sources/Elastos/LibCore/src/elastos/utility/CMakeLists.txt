
xdk_add_subdirectories(
#    concurrent
#    jar
#    logging
    regex
#    zip
#    prefs
)


add_definitions(-DELASTOS_CORELIBRARY)

include_directories(${CMAKE_CURRENT_BINARY_DIR}/../../corelibrary)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../../inc)

set(SOURCES
    AbstractCollection.cpp
    AbstractList.cpp
    AbstractMap.cpp
    AbstractQueue.cpp
    AbstractSequentialList.cpp
    AbstractSet.cpp
    CArrayDeque.cpp
    ArrayList.cpp
    Arrays.cpp
    CBitSet.cpp
    CBitSetHelper.cpp
#    Calendar.cpp
#    CCalendarHelper.cpp
    Collections.cpp
    CCollections.cpp
#    Currency.cpp
#    CCurrencyHelper.cpp
#    Date.cpp
#    CDateHelper.cpp
#    DualPivotQuicksort.cpp
    CEnumMap.cpp
    EnumSet.cpp
    CEnumSetHelper.cpp
    EventListenerProxy.cpp
    EventObject.cpp
#    CFormatter.cpp
#    Grego.cpp
#    CGregorianCalendar.cpp
    HashMap.cpp
    HashSet.cpp
    HashTable.cpp
    HugeEnumSet.cpp
#    CIdentityHashMap.cpp
    LinkedHashMap.cpp
    CLinkedHashMap.cpp
    CLinkedHashSet.cpp
    CLinkedList.cpp
#    ListResourceBundle.cpp

#    Locale.cpp
#    CLocaleBuilder.cpp
#    CLocaleHelper.cpp

    MapEntry.cpp
    MiniEnumSet.cpp
    Observable.cpp
    CPriorityQueue.cpp
#    Properties.cpp
#    CProperties.cpp
#    PropertyPermission.cpp
#    CPropertyResourceBundle.cpp
#    Random.cpp
#    ResourceBundle.cpp
#    CScanner.cpp
#    ServiceLoader.cpp
#    CSimpleTimeZone.cpp
    CStack.cpp
    StringPool.cpp
    CStringTokenizer.cpp
#    TimeZone.cpp
#    Timer.cpp
#    TimerTask.cpp
#    TimeZoneGetter.cpp
#    CTimeZoneHelper.cpp
    CTreeMap.cpp
    CTreeSet.cpp
#    CUUID.cpp
#    CUUIDHelper.cpp
    UnsafeArrayList.cpp
    Vector.cpp
    CWeakHashMap.cpp
    utility.cpp
)

add_library(elastos_utility_min STATIC ${SOURCES})
xdk_combine_static_libraries(elastos.utility
    $<TARGET_FILE:elastos_utility_min>
    $<TARGET_FILE:elastos_utility_regex>
)
add_dependencies(elastos_utility_min elastos_core_library_car)
