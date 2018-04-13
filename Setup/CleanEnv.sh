while read I; do
    if [[ "${I%%=*}" != "HOME"
       && "${I%%=*}" != "_"
       && "${I%%=*}" != "DISPLAY"
       && "${I%%=*}" != "OS_PATH"
       && "${I%%=*}" != "PATH"
       && "${I%%=*}" != "PWD"
       && "${I%%=*}" != "XDK_BUILD_ENV"
       && "${I%%=*}" != "TERM"
       && "${I%%=*}" != "SHELL"
       && "${I%%=*}" != "XDK_ROOT"
       && "${I%%=*}" != "_ELASTOS64"
       && "${I%%=*}" != "LANG"
       && "${I%%=*}" != "LC_ALL"
       && "${I%%=*}" != "LC_CTYPE"
       && "${I%%=*}" != "ANDROID_NDK"
       ]]; then
        unset ${I%%=*} &>/dev/null || true
    fi
done < <(env)

unset I
