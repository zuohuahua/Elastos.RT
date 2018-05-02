//=========================================================================
// Copyright (C) 2018 The Elastos Open Source Project
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

#include <lube.h>
#ifndef _apple
#include <malloc.h>
#endif

const char* _JavaMethodSignature(const TypeDescriptor* pType)
{
    assert(NULL != pType);

    const char *pszType = NULL;
    switch (pType->mType) {
        case Type_Char32: {
            pszType = "C";
            break;
        }
        case Type_Int32: {
            pszType = "I";
            break;
        }
        case Type_Int64: {
            pszType = "J";
            break;
        }
        case Type_Byte: {
            pszType = "B";
            break;
        }
        case Type_Boolean: {
            pszType = "Z";
            break;
        }
        case Type_Float: {
            pszType = "F";
            break;
        }
        case Type_Double: {
            pszType = "D";
            break;
        }
        case Type_String: {
            pszType = "Ljava/lang/String;";
            break;
        }
        // case Type_ArrayOf:
        //     if (Type_String == pType->mNestedType->mType) {
        //         pszType = "ArrayOfString";
        //     }
        //     else {
        //         pszType = "CarArray";
        //     }
        //     break;

        // case Type_Array:
        //     pszType = "CarArray";
        //     break;

        // case Type_interface:
        //     pszType = "Interface";
        //     break;

        // case Type_struct:
        //     pszType = "Struct";
        //     break;
        default: {
            pszType = "Unknown";
            fprintf(stderr, "Uonsupport parameter type: [%d]\n", pType->mType);
            break;
        }
    }

    return pszType;
}

const char* GenerateJavaTypeString(const TypeDescriptor *pType)
{
    switch (pType->mType) {
        case Type_Char32: {
            return "char";
        }
        case Type_Int32: {
            return "int";
        }
        case Type_Int64: {
            return "long";
        }
        case Type_Byte: {
            return "byte";
        }
        case Type_Boolean: {
            return "boolean";
        }
        case Type_Float: {
            return "float";
        }
        case Type_Double: {
            return "double";
        }
        case Type_String: {
            return "String";
        }
        default: {
            fprintf(stderr, "Uonsupport parameter type: [%d]\n", pType->mType);
            return "Unknown";
        }
    }
}

const char* GenerateJavaJniTypeString(const TypeDescriptor *pType)
{
    switch (pType->mType) {
        case Type_Char32: {
            return "jchar";
        }
        case Type_Int32: {
            return "jint";
        }
        case Type_Int64: {
            return "jlong";
        }
        case Type_Byte: {
            return "jbyte";
        }
        case Type_Boolean: {
            return "jboolean";
        }
        case Type_Float: {
            return "jfloat";
        }
        case Type_Double: {
            return "jdouble";
        }
        case Type_String: {
            return "jstring";
        }
        default: {
            fprintf(stderr, "Uonsupport parameter type: [%d]\n", pType->mType);
            return "Unknown";
        }
    }
}

const char* GetElaTypeName(const TypeDescriptor *pType)
{
    switch (pType->mType) {
        case Type_Char32: {
            return "Char32";
        }
        case Type_Int32: {
            return "Int32";
        }
        case Type_Int64: {
            return "Int64";
        }
        case Type_Byte: {
            return "Byte";
        }
        case Type_Boolean: {
            return "Boolean";
        }
        case Type_Float: {
            return "Float";
        }
        case Type_Double: {
            return "Double";
        }
        case Type_String: {
            return "String";
        }
        default: {
            fprintf(stderr, "Uonsupport parameter type: [%d]\n", pType->mType);
            return "Unknown";
        }
    }
}

int _GenerateJavaClassImpl(PLUBECTX pCtx, PSTATEDESC pDesc, PVOID pvArg)
{
    assert(NULL != pCtx->m_pInterface && pvArg == pCtx->m_pInterface);

    InterfaceDirEntry *pItfDir = pCtx->m_pInterface;
    assert(pItfDir->mDesc != NULL);

    char szContent[128];
    for (int i = 0; i < pItfDir->mDesc->mMethodCount; i++) {
        MethodDescriptor* methodDesc = pItfDir->mDesc->mMethods[i];
        assert(methodDesc != NULL);

        const char* retType = "void";
        int outParaPos = -1;
        if (methodDesc->mParamCount > 0) {
            for (int j = 0; j < methodDesc->mParamCount; j++) {
                ParamDescriptor* paraDesc = methodDesc->mParams[j];
                assert(paraDesc != NULL);

                if (paraDesc->mAttribs & ParamAttrib_out) {
                    outParaPos = j;
                    retType = GenerateJavaTypeString(&paraDesc->mType);
                    break;
                }
            }
        }

        sprintf(szContent, "    public static %s %s(", retType, methodDesc->mName);
        pCtx->PutString(szContent);
        if (methodDesc->mParamCount > 0) {
            for (int j = 0; j < methodDesc->mParamCount; j++) {
                ParamDescriptor* paraDesc = methodDesc->mParams[j];
                assert(paraDesc != NULL);

                if (paraDesc->mAttribs & ParamAttrib_in) {
                    // Before [out] parameter print.
                    if (j == 0) {
                        pCtx->PutString("\n");
                    }

                    if (j > 0 && (outParaPos == -1 || j < outParaPos)) {
                        pCtx->PutString(",\n");
                    }

                    sprintf(szContent, "        /* [in] */ %s %s", GenerateJavaTypeString(&paraDesc->mType), paraDesc->mName);
                    pCtx->PutString(szContent);
                }
            }
        }

        pCtx->PutString(")\n");

        // Function body.
        pCtx->PutString("    {\n");
        pCtx->PutString("        //TODO: Add your code here\n");
        if (outParaPos >= 0) {
            if (!strcmp(retType, "String")) {
                sprintf(szContent, "        %s _retValue = \"NULL\";\n", retType);
            }
            else {
                sprintf(szContent, "        %s _retValue = 0;\n", retType);
            }

            pCtx->PutString(szContent);
            pCtx->PutString("        return _retValue;\n");
        }

        if ((pItfDir->mDesc->mMethodCount - 1) == i) {
            pCtx->PutString("    }");
        }
        else {
            pCtx->PutString("    }\n\n");
        }
    }

    return LUBE_OK;
}

int _GenerateJavaClassUser(PLUBECTX pCtx, PSTATEDESC pDesc, PVOID pvArg)
{
    assert(NULL != pCtx->m_pInterface && pvArg == pCtx->m_pInterface);

    InterfaceDirEntry *pItfDir = pCtx->m_pInterface;
    assert(pItfDir->mDesc != NULL);

    char szContent[128];
    static int loadLibraryFlag = 0;
    //If there are multi-interfaces, these codes is only one. the System.loadLibrary must be record once.
    if (loadLibraryFlag == 0) {
        CLSModule* module = pCtx->m_pModule;
        assert(module != NULL);
        ClassDirEntry *pClass = pCtx->m_pClass;

        pCtx->PutString("    static {\n");
        pCtx->PutString("        System.loadLibrary(\"Elastos.Runtime\");\n");
        pCtx->PutString("        System.loadLibrary(\"Elastos.CoreLibrary\");\n");

        sprintf(szContent, "        System.loadLibrary(\"%s\");\n", module->mName);
        pCtx->PutString(szContent);

        pCtx->PutString("        //TODO : Your jni so, please fill it.\n");
        pCtx->PutString("        System.loadLibrary(\"Your_Jni\");\n");
        pCtx->PutString("    }\n\n");

        loadLibraryFlag = 1;
    }

    for (int i = 0; i < pItfDir->mDesc->mMethodCount; i++) {
        MethodDescriptor* methodDesc = pItfDir->mDesc->mMethods[i];
        assert(methodDesc != NULL);

        const char* retType = "void";
        int outParaPos = -1;
        if (methodDesc->mParamCount > 0) {
            for (int j = 0; j < methodDesc->mParamCount; j++) {
                ParamDescriptor* paraDesc = methodDesc->mParams[j];
                assert(paraDesc != NULL);

                if (paraDesc->mAttribs & ParamAttrib_out) {
                    outParaPos = j;
                    retType = GenerateJavaTypeString(&paraDesc->mType);
                    break;
                }
            }
        }

        sprintf(szContent, "    public static %s %s(", retType, methodDesc->mName);
        pCtx->PutString(szContent);
        if (methodDesc->mParamCount > 0) {
            for (int j = 0; j < methodDesc->mParamCount; j++) {
                ParamDescriptor* paraDesc = methodDesc->mParams[j];
                assert(paraDesc != NULL);

                if (paraDesc->mAttribs & ParamAttrib_in) {
                    // Before [out] parameter print.
                    if (j == 0) {
                        pCtx->PutString("\n");
                    }

                    if (j > 0 && (outParaPos == -1 || j < outParaPos)) {
                        pCtx->PutString(",\n");
                    }

                    const char* paraType = GenerateJavaTypeString(&paraDesc->mType);

                    sprintf(szContent, "        /* [in] */ %s %s", paraType, paraDesc->mName);
                    pCtx->PutString(szContent);
                }
            }
        }

        pCtx->PutString(")\n");

        // Function body.
        char szNativeDefineParameters[1024] = {0};
        pCtx->PutString("    {\n");
        if (methodDesc->mParamCount == 0) {
            sprintf(szContent, "        native%s();\n", methodDesc->mName);
            pCtx->PutString(szContent);
        }
        else {
            char szParameters[1024] = {0};

            for (int j = 0; j < methodDesc->mParamCount; j++) {
                ParamDescriptor* paraDesc = methodDesc->mParams[j];
                assert(paraDesc != NULL);

                if (paraDesc->mAttribs & ParamAttrib_in) {
                    if (j > 0 && (outParaPos == -1 || j < outParaPos)) {
                        strcat(szParameters, ", ");
                        strcat(szNativeDefineParameters, ", ");
                    }

                    sprintf(szContent, "%s", paraDesc->mName);
                    strcat(szParameters, szContent);

                    sprintf(szContent, "%s %s", GenerateJavaTypeString(&paraDesc->mType), paraDesc->mName);
                    strcat(szNativeDefineParameters, szContent);
                }
            }

            //Call the method and process the return value.
            if (outParaPos >= 0) {
                if (szParameters[0] != '\0') {
                    sprintf(szContent, "        return native%s(%s);\n", methodDesc->mName, szParameters);
                }
                else {
                    sprintf(szContent, "        return native%s();\n", methodDesc->mName);
                }
            }
            else {
                sprintf(szContent, "        native%s(%s);\n", methodDesc->mName, szParameters);
            }

            pCtx->PutString(szContent);
        }

        pCtx->PutString("    }\n\n");

        //Record nativeXX function.
        if (szNativeDefineParameters[0] != '\0') {
            // sprintf(szContent, "    %s native%s(%s);\n\n", retType, methodDesc->mName, szNativeDefineParameters);
            pCtx->PutString("    private static native ");
            pCtx->PutString(retType);
            pCtx->PutString(" native");
            pCtx->PutString(methodDesc->mName);
            pCtx->PutString("(");
            pCtx->PutString(szNativeDefineParameters);
            pCtx->PutString(");\n\n");
        }
        else {
            sprintf(szContent, "    private static native %s native%s();\n\n", retType, methodDesc->mName);
            pCtx->PutString(szContent);
        }
    }

    return LUBE_OK;
}

int _GenerateJavaJniCpp(PLUBECTX pCtx, PSTATEDESC pDesc, PVOID pvArg)
{
    assert(NULL != pCtx->m_pInterface && pvArg == pCtx->m_pInterface);

    InterfaceDirEntry *pItfDir = pCtx->m_pInterface;
    assert(pItfDir->mDesc != NULL);

    char szContent[128];
    static int onceFlag = 0;
    //If there are multi-interfaces, these codes is only one. the nativeInit method must be record once.
    if (onceFlag == 0) {
        CLSModule* module = pCtx->m_pModule;
        assert(module != NULL);
        ClassDirEntry *pClass = pCtx->m_pClass;

        pCtx->PutString("#include \"");
        pCtx->PutString(module->mName);
        pCtx->PutString(".Export.h\"\n\n");

        pCtx->PutString("//TODO : Need to Modify the java class path.\n");
        sprintf(szContent, "#define JNIREG_CLASS \"elastos/org/xxx/%sUser\"\n\n", pClass->mName);
        pCtx->PutString(szContent);

        sprintf(szContent, "static AutoPtr<%s> sElaClsObj;\n", pItfDir->mName);
        pCtx->PutString(szContent);

        pCtx->PutString("static void nativeInit(\n");
        pCtx->PutString("    /* [in] */ JNIEnv* env,\n    /* [in] */ jobject jobj)\n");

        // Function body.
        pCtx->PutString("{\n");
        sprintf(szContent, "    %s::New((%s**)&sElaClsObj);\n", pClass->mName, pItfDir->mName);
        pCtx->PutString(szContent);

        pCtx->PutString("}\n\n");

        onceFlag = 1;
    }

    for (int i = 0; i < pItfDir->mDesc->mMethodCount; i++) {
        MethodDescriptor* methodDesc = pItfDir->mDesc->mMethods[i];
        assert(methodDesc != NULL);

        const TypeDescriptor *pType = NULL;
        int outParaPos = -1;
        if (methodDesc->mParamCount > 0) {
            for (int j = 0; j < methodDesc->mParamCount; j++) {
                ParamDescriptor* paraDesc = methodDesc->mParams[j];
                assert(paraDesc != NULL);

                if (paraDesc->mAttribs & ParamAttrib_out) {
                    outParaPos = j;
                    pType = &paraDesc->mType;
                    break;
                }
            }
        }

        int szParametersLen = 0;
        if (pType == NULL) {
            sprintf(szContent, "static void native%s(\n", methodDesc->mName);
        }
        else {
            sprintf(szContent, "static %s native%s(\n", GenerateJavaJniTypeString(pType), methodDesc->mName);
        }

        pCtx->PutString(szContent);
        if (methodDesc->mParamCount == 0) {
            pCtx->PutString("    /* [in] */ JNIEnv* env,\n    /* [in] */ jobject jobj)\n");
        }
        else {
            pCtx->PutString("    /* [in] */ JNIEnv* env,\n    /* [in] */ jobject jobj");
            for (int j = 0; j < methodDesc->mParamCount; j++) {
                ParamDescriptor* paraDesc = methodDesc->mParams[j];
                assert(paraDesc != NULL);

                if (paraDesc->mAttribs & ParamAttrib_in) {
                    //Get the szParametersLen
                    szParametersLen += strlen(paraDesc->mName) + 2 /*space + comma*/;

                    // Before [out] parameter print.
                    if (j == 0) {
                        pCtx->PutString(",\n");
                    }

                    if (j > 0 && (outParaPos == -1 || j < outParaPos)) {
                        pCtx->PutString(",\n");
                    }

                    sprintf(szContent, "    /* [in] */ %s j%s", GenerateJavaJniTypeString(&paraDesc->mType), paraDesc->mName);
                    pCtx->PutString(szContent);
                }
            }
            pCtx->PutString(")\n");
        }

        // Function body.
        pCtx->PutString("{\n");
        if (methodDesc->mParamCount == 0) {
            sprintf(szContent, "    sElaClsObj->%s();\n", methodDesc->mName);
            pCtx->PutString(szContent);
        }
        else {
            char* szParameters = NULL;
            if (szParametersLen > 0) {
                szParameters = (char*)malloc(szParametersLen + 1);
                memset(szParameters, 0, szParametersLen + 1);
            }

            for (int j = 0; j < methodDesc->mParamCount; j++) {
                ParamDescriptor* paraDesc = methodDesc->mParams[j];
                assert(paraDesc != NULL);

                if (paraDesc->mAttribs & ParamAttrib_in) {
                    if (j > 0 && (outParaPos == -1 || j < outParaPos)) {
                        strcat(szParameters, ", ");
                    }

                    if (!strcmp(GenerateJavaJniTypeString(&paraDesc->mType), "jstring")) {
                        sprintf(szContent, "    const char* str%d = env->GetStringUTFChars(j%s, NULL);\n", j + 1, paraDesc->mName);
                        pCtx->PutString(szContent);

                        // TODO ReleaseStringUTFChars
                        // sprintf(szContent, "    env->ReleaseStringUTFChars(j%s, str%d);", paraDesc->mName, j);
                        // pCtx->PutString(szContent);

                        sprintf(szContent, "str%d", j + 1);
                        strcat(szParameters, szContent);
                    }
                    else {
                        sprintf(szContent, "j%s", paraDesc->mName);
                        strcat(szParameters, szContent);
                    }
                }
            }

            //Call the method and process the return value.
            if (outParaPos >= 0) {
                if (!strcmp(GetElaTypeName(pType), "String")) {
                    pCtx->PutString("    String _retValue;\n");
                    if (szParameters != NULL) {
                        sprintf(szContent, "    sElaClsObj->%s(%s, &_retValue);\n", methodDesc->mName, szParameters);
                    }
                    else {
                        sprintf(szContent, "    sElaClsObj->%s(&_retValue);\n", methodDesc->mName);
                    }

                    pCtx->PutString(szContent);

                    pCtx->PutString("    return env->NewStringUTF(_retValue.string());\n");
                }
                else {
                    sprintf(szContent, "    %s _retValue = 0;\n", GetElaTypeName(pType));
                    pCtx->PutString(szContent);
                    if (szParameters != NULL) {
                        sprintf(szContent, "    sElaClsObj->%s(%s, &_retValue);\n", methodDesc->mName, szParameters);
                    }
                    else {
                        sprintf(szContent, "    sElaClsObj->%s(&_retValue);\n", methodDesc->mName);
                    }

                    pCtx->PutString(szContent);
                    pCtx->PutString("    return _retValue;\n");
                }
            }
            else {
                sprintf(szContent, "    sElaClsObj->%s(%s);\n", methodDesc->mName, szParameters);
                pCtx->PutString(szContent);
            }

            if (szParameters != NULL) free(szParameters);
        }

        if ((pItfDir->mDesc->mMethodCount - 1) == i) {
            pCtx->PutString("}\n");
        }
        else {
            pCtx->PutString("}\n\n");
        }
    }

    return LUBE_OK;
}

int _GenerateJavaJniCppJniLoad(PLUBECTX pCtx, PSTATEDESC pDesc, PVOID pvArg)
{
    assert(NULL != pCtx->m_pClass && pvArg == pCtx->m_pClass);

    pCtx->PutString("\nstatic const JNINativeMethod gMethods[] = {\n");
    ClassDirEntry *pClsDir = pCtx->m_pClass;
    char szContent[256];
    char signature[128];
    for (int i = 0; i < pClsDir->mDesc->mInterfaceCount; i++) {
        ClassInterface *pClsIntf = pClsDir->mDesc->mInterfaces[i];

        if (pClsIntf->mAttribs & ClassInterfaceAttrib_outer) {
            continue;
        }

        InterfaceDirEntry *pItfDir = pCtx->m_pModule->mInterfaceDirs[pClsIntf->mIndex];

        for (int mi = 0; mi < pItfDir->mDesc->mMethodCount; mi++) {
            MethodDescriptor* methodDesc = pItfDir->mDesc->mMethods[mi];
            assert(methodDesc != NULL);

            const TypeDescriptor *pType = NULL;
            int outParaPos = -1;
            if (methodDesc->mParamCount > 0) {
                for (int j = 0; j < methodDesc->mParamCount; j++) {
                    ParamDescriptor* paraDesc = methodDesc->mParams[j];
                    assert(paraDesc != NULL);

                    if (paraDesc->mAttribs & ParamAttrib_out) {
                        outParaPos = j;
                        pType = &paraDesc->mType;
                        break;
                    }
                }

                memset(signature, 0, 128);

                for (int j = 0; j < methodDesc->mParamCount; j++) {
                    ParamDescriptor* paraDesc = methodDesc->mParams[j];
                    assert(paraDesc != NULL);

                    if (paraDesc->mAttribs & ParamAttrib_in) {
                        strcat(signature, _JavaMethodSignature(&paraDesc->mType));
                    }
                }

                const char* retTypeSignature = "V";
                if (pType) {
                    retTypeSignature = _JavaMethodSignature(pType);
                }

                sprintf(szContent, "    {\"native%s\", \"(%s)%s\", (void*)%s},\n", methodDesc->mName, signature, retTypeSignature, methodDesc->mName);
                pCtx->PutString(szContent);
            }
            else {
                sprintf(szContent, "    {\"native%s\", \"()V\", (void*)%s},\n", methodDesc->mName, methodDesc->mName);
                pCtx->PutString(szContent);
            }
        }
    }

    pCtx->PutString("};\n\n");

    pCtx->PutString("JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* reserved){\n");
    pCtx->PutString("    JNIEnv * env;\n    jclass cls;\n");
    pCtx->PutString("    if(vm->GetEnv((void **)&env,JNI_VERSION_1_6) != JNI_OK){\n");
    pCtx->PutString("        return JNI_ERR;\n");
    pCtx->PutString("    }\n");
    pCtx->PutString("    cls = env->FindClass(JNIREG_CLASS);\n");
    pCtx->PutString("    env->RegisterNatives(cls, gMethods, sizeof(gMethods)/sizeof(JNINativeMethod));\n");
    pCtx->PutString("    return JNI_VERSION_1_6;\n");
    pCtx->PutString("};");

    return LUBE_OK;
}
