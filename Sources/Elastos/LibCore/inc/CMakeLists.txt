
set(EXPORT_HEADERS
    elastos/coredef.h
    elastos/corehash.h

    elastos/core/UniquePtr.h
    elastos/core/NativeThread.h
    elastos/core/Mutex.h
    elastos/core/Object.h
    elastos/core/AutoLock.h
    elastos/core/Singleton.h
    elastos/core/Thread.h
    elastos/core/Runnable.h
    elastos/core/Math.h
    elastos/core/StrictMath.h
    elastos/core/Character.h
    elastos/core/CaseMapper.h
    elastos/core/CoreUtils.h
    elastos/core/StringUtils.h
    elastos/core/HexStringParser.h
    elastos/core/StringToIntegral.h
    elastos/core/IntegralToString.h
    elastos/core/StringToReal.h
    elastos/core/RealToString.h
    elastos/core/AbstractStringBuilder.h
    elastos/core/StringBuilder.h
    elastos/core/StringBuffer.h
    elastos/core/ClassLoader.h

    elastos/utility/etl/Algorithm.h
    elastos/utility/etl/ConceptCheck.h
    elastos/utility/etl/etl_algo.h
    elastos/utility/etl/etl_algobase.h
    elastos/utility/etl/etl_alloc.h
    elastos/utility/etl/etl_concept_check.h
    elastos/utility/etl/etl_construct.h
    elastos/utility/etl/etl_def.h
    elastos/utility/etl/etl_exception_defines.h
    elastos/utility/etl/etl_function.h
    elastos/utility/etl/etl_function_exception.h
    elastos/utility/etl/etl_hash_fun.h
    elastos/utility/etl/etl_hashmap.h
    elastos/utility/etl/etl_hashset.h
    elastos/utility/etl/etl_hashtable.h
    elastos/utility/etl/etl_iterator.h
    elastos/utility/etl/etl_iterator_base_funcs.h
    elastos/utility/etl/etl_iterator_base_types.h
    elastos/utility/etl/etl_list.h
    elastos/utility/etl/etl_map.h
    elastos/utility/etl/etl_multimap.h
    elastos/utility/etl/etl_multiset.h
    elastos/utility/etl/etl_pair.h
    elastos/utility/etl/etl_set.h
    elastos/utility/etl/etl_tree.h
    elastos/utility/etl/etl_type_traits.h
    elastos/utility/etl/etl_uninitialized.h
    elastos/utility/etl/etl_vector.h
    elastos/utility/etl/etl_deque.h
    elastos/utility/etl/etl_stack.h
    elastos/utility/etl/etl_heap.h
    elastos/utility/etl/etl_queue.h
    elastos/utility/etl/etl_blockingqueue.h
    elastos/utility/etl/HashMap.h
    elastos/utility/LinkedHashMap.h
    elastos/utility/etl/HashSet.h
    elastos/utility/etl/HashTable.h
    elastos/utility/etl/List.h
    elastos/utility/etl/Map.h
    elastos/utility/etl/Pair.h
    elastos/utility/etl/Set.h
    elastos/utility/etl/Vector.h
    elastos/utility/etl/Stack.h
    elastos/utility/etl/Queue.h
    elastos/utility/etl/BlockingQueue.h

    elastos/utility/concurrent/FutureTask.h

    elastos/utility/logging/Logger.h
    elastos/utility/logging/Slogger.h

    elastos/utility/AbstractCollection.h
    elastos/utility/AbstractList.h
    elastos/utility/AbstractMap.h
    elastos/utility/AbstractSet.h
    elastos/utility/ArrayList.h
    elastos/utility/Arrays.h
    elastos/utility/ComparableTimSort.h
    elastos/utility/DualPivotQuicksort.h
    elastos/utility/HashMap.h
    elastos/utility/HashSet.h
    elastos/utility/HashTable.h
    elastos/utility/Objects.h
    elastos/utility/Observable.h
    elastos/utility/Properties.h
    elastos/utility/StringPool.h
    elastos/utility/TimSort.h
    elastos/utility/TimerTask.h
    elastos/utility/TimeZoneGetter.h
    elastos/utility/regex/Pattern.h

    elastos/net/ProxySelector.h
    elastos/net/ResponseCache.h
    elastos/net/Socket.h
)

xdk_export_headers(libcore_headers ${EXPORT_HEADERS})

