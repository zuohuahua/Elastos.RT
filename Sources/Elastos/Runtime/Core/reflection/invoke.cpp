//=========================================================================
// Copyright (C) 2012 The Elastos Open Source Project
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//=========================================================================

#include <elatypes.h>

extern "C" {

#ifdef _mips
__declspec(naked)
int invoke(void* func, int* param, int size)
{
    ASM("break 0;");
}
#elif _arm
int invoke(void* func, int* param, int size)
{
    __builtin_trap();
}
#elif _MSC_VER
__declspec(naked)
int invoke(void* func, int* param, int size)
{
    __asm {
        push    ebp
        mov     ebp, esp

        mov     ecx, size
        mov     eax, param
        add     eax, ecx
        sub     eax, 4
push_param:
        test    ecx, ecx
        jz      do_call

        mov     edx, dword ptr [eax]
        push    edx
        sub     eax, 4
        sub     ecx, 4
        jmp     push_param

do_call:
        mov     ecx, func              // function pointer
        call    ecx

        mov     esp, ebp
        pop     ebp
        ret
    }
}
#else // __GNUC__

#ifdef _ELASTOS64
int invoke(void* func, int* param, int size)
{
    int rval;

    __asm__ __volatile__(
        "movq   $0, %%rcx\n"
        "movq   %2, %%rax\n"
        "movl   %3, %%ecx\n"
        "addq   %%rcx, %%rax\n"
        "subq   $8, %%rax\n"

        "test   %%ecx, %%ecx\n"
        "jz     do_call\n"

        // 1st parameter, %%RDI
        "movq   (%%rax), %%rdi\n"
        "subq   $8, %%rax\n"
        "subq   $8, %%rcx\n"
        "test   %%ecx, %%ecx\n"
        "jz     do_call\n"

        // 2nd parameter, %%RSI
        "movq   (%%rax), %%rdx\n"
        "subq   $8, %%rax\n"
        "subq   $8, %%rcx\n"
        "test   %%ecx, %%ecx\n"
        "jz     do_call\n"

        // 3rd parameter, %%RDX
        "movq   (%%rax), %%rcx\n"
        "subq   $8, %%rax\n"
        "subq   $8, %%rcx\n"
        "test   %%ecx, %%ecx\n"
        "jz     do_call\n"


        // 4th parameter, %%RDX
        "movq   (%%rax), %%rcx\n"
        "subq   $8, %%rax\n"
        "subq   $8, %%rcx\n"
        "test   %%ecx, %%ecx\n"
        "jz     do_call\n"

        // 5th parameter, %%RDX
        "movq   (%%rax), %%r8\n"
        "subq   $8, %%rax\n"
        "subq   $8, %%rcx\n"
        "test   %%ecx, %%ecx\n"
        "jz     do_call\n"

        // 6th parameter, %%RDX
        "movq   (%%rax), %%r9\n"
        "subq   $8, %%rax\n"
        "subq   $8, %%rcx\n"

        // more than 6 parameters, on stack
        "push_param:\n"
            "test   %%ecx, %%ecx\n"
            "jz     do_call\n"

            "movq   (%%rax), %%rdx\n"
            "pushq  %%rdx\n"
            "subq   $8, %%rax\n"
            "subq   $8, %%rcx\n"
            "jmp    push_param\n"
        "do_call:\n"
            "movq   %1, %%rcx\n"
            "callq  *%%rcx\n"
            "movq   %%rbp, %%rsp\n"
            // we shouldn't reset the return value, for invoke is just a bridge function
            //"movl   %%eax, %0"
        : "=r" (rval)
        : "m" (func)
        , "m" (param)
        , "m" (size)
        : "rax"
        , "rcx"
        , "rdx"
        , "rdi"
        , "rsi"
        , "rcx"
        , "r8"
        , "r9"
    );

    return rval;
}
#else
int invoke(void* func, int* param, int size)
{
    int rval;
    __asm__ (
        "movl   %2, %%eax\n"
        "movl   %3, %%ecx\n"
        "addl   %%ecx, %%eax\n"
        "subl   $4, %%eax\n"
        "push_param:\n"
            "test   %%ecx, %%ecx\n"
            "jz     do_call\n"
            "movl   (%%eax), %%edx\n"
            "pushl  %%edx\n"
            "subl   $4, %%eax\n"
            "subl   $4, %%ecx\n"
            "jmp    push_param\n"
        "do_call:\n"
            "movl   %1, %%ecx\n"
            "calll  *%%ecx\n"
            "movl   %%ebp, %%esp\n"
            "movl   %%eax, %0"
        : "=r" (rval)
        : "m" (func)
        , "m" (param)
        , "d" (size)
        : "eax"
        , "ecx"
    );

    return rval;
}
#endif
#endif // _MSC_VER

}
