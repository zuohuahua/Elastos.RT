build_src:
	"$(MAKEDIR)"/autogen.sh
	CFLAGS="$(shell echo $(C_FLAGS) | sed -e 's@-c@@g')" \
	LDFLAGS="$(shell echo $(DLL_FLAGS) -L$(XDK_TARGETS) | sed -e 's@-shared\|,-fpic@@g' -e 's@@-Wl,-fPIC@@g' -e 's@-Wl,--retain-symbols[^ ]*@@g' -e 's@-Wl,--version-script[^ ]*@@g' -e 's@--nostdlib@@g')" \
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
	make DESTDIR="$(XDK_TARGETS)" install
	$(CPDIR) $(XDK_TARGETS)/usr/local/lib/* $(XDK_TARGETS)
	$(RMDIR) $(XDK_TARGETS)/usr
	if test "$(XDK_TARGET_PLATFORM)" = "linux" && \
	 test "$(XDK_TARGET_CPU)" = "x86"; then \
	  sudo make install; \
	fi
	touch $@

android_build_src:
	$(shell echo source) $(MAKEDIR)/elastos-android-configure $(MAKEDIR)/gyp_uv.py -Dtarget_arch=arm -DOS=android && \
	make -C $(MAKEDIR) -C $(MAKEDIR)/out
	touch $@

copy_prebuilt:
	$(CP) $(PREBUILD_LIB)\$(XDK_VERSION)\libuv.dll $(XDK_TARGETS)
	touch $@

