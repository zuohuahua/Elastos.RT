build_src:
	"$(MAKEDIR)"/autogen.sh
	CFLAGS="$(shell echo $(C_FLAGS) | sed -e 's@-c@@g')" \
	LDFLAGS="$(shell echo $(DLL_FLAGS) -L$(PREBUILD_LIB) | sed -e 's@-shared\|,-fpic@@g' -e 's@@-Wl,-fPIC@@g' -e 's@-Wl,--retain-symbols[^ ]*@@g' -e 's@-Wl,--version-script[^ ]*@@g' -e 's@--nostdlib@@g')" \
	CC="$(CC)" \
	"$(MAKEDIR)"/configure \
        --host=$(patsubst %-,%,$(CROSS_COMPILE)) \
        --target=$(patsubst %-,%,$(CROSS_COMPILE)) \
	--disable-dtrace \
	--enable-shared \
	--disable-static
# Add backslash before parentheses in the Makefile to let make run
	sed -e 's@__declspec(x)@__declspec\\(x\\)@g' -i Makefile
ifeq "$(XDK_TARGET_PLATFORM)" "android"
	-ln -s $(PREBUILD_LIB)/crtbegin_so.o
	-ln -s $(PREBUILD_LIB)/crtend_so.o
endif
	make
	make DESTDIR="$(PREBUILD_PATH)" install
	$(CPDIR) $(PREBUILD_PATH)/usr/local/include $(PREBUILD_PATH)/usr
	$(CPDIR) $(PREBUILD_PATH)/usr/local/lib $(PREBUILD_PATH)/usr
	$(RMDIR) $(PREBUILD_PATH)/usr/local
	if test "$(XDK_TARGET_PLATFORM)" = "linux" && \
	 test "$(XDK_TARGET_CPU)" = "x86"; then \
	  sudo make install; \
	fi

copy_prebuilt:
	$(CP) $(PREBUILD_LIB)\$(XDK_VERSION)\libuv.dll $(XDK_TARGETS)

