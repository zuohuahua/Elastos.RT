#ifndef ___Elastos_CoreLibrary_External_h__
#define ___Elastos_CoreLibrary_External_h__

#include <Elastos.CoreLibrary.h>

EXTERN_C ELAPI _Impl_AcquireCallbackHandler(PInterface pServerObj, _ELASTOS REIID iid, PInterface *ppHandler);
EXTERN_C ELAPI _Impl_CheckClsId(PInterface pServerObj, const _ELASTOS ClassID* pClassid, PInterface *ppServerObj);

namespace Org {
namespace W3c {
namespace Dom {
CAR_INTERFACE("DEA92308-25D2-689F-C5DA-F78FD5EA0F0E")
INodeList : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(INodeList*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (INodeList*)pObj->Probe(EIID_INodeList);
    }

    static CARAPI_(INodeList*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (INodeList*)pObj->Probe(EIID_INodeList);
    }

    virtual CARAPI Item(
        /* [in] */ _ELASTOS Int32 index,
        /* [out] */ Org::W3c::Dom::INode ** node) = 0;

    virtual CARAPI GetLength(
        /* [out] */ _ELASTOS Int32 * value) = 0;

};
}
}
}
namespace Org {
namespace W3c {
namespace Dom {
CAR_INTERFACE("4594FD1B-25D2-E89F-8FD5-EA0F0EE6DFC8")
INode : public IInterface
{
    static const _ELASTOS Int16 ELEMENT_NODE = 1;
    static const _ELASTOS Int16 ATTRIBUTE_NODE = 2;
    static const _ELASTOS Int16 TEXT_NODE = 3;
    static const _ELASTOS Int16 CDATA_SECTION_NODE = 4;
    static const _ELASTOS Int16 ENTITY_REFERENCE_NODE = 5;
    static const _ELASTOS Int16 ENTITY_NODE = 6;
    static const _ELASTOS Int16 PROCESSING_INSTRUCTION_NODE = 7;
    static const _ELASTOS Int16 COMMENT_NODE = 8;
    static const _ELASTOS Int16 DOCUMENT_NODE = 9;
    static const _ELASTOS Int16 DOCUMENT_TYPE_NODE = 10;
    static const _ELASTOS Int16 DOCUMENT_FRAGMENT_NODE = 11;
    static const _ELASTOS Int16 NOTATION_NODE = 12;
    static const _ELASTOS Int16 DOCUMENT_POSITION_DISCONNECTED = 0x0001;
    static const _ELASTOS Int16 DOCUMENT_POSITION_PRECEDING = 0x0002;
    static const _ELASTOS Int16 DOCUMENT_POSITION_FOLLOWING = 0x0004;
    static const _ELASTOS Int16 DOCUMENT_POSITION_CONTAINS = 0x0008;
    static const _ELASTOS Int16 DOCUMENT_POSITION_CONTAINED_BY = 0x0010;
    static const _ELASTOS Int16 DOCUMENT_POSITION_IMPLEMENTATION_SPECIFIC = 0x0020;
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(INode*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (INode*)pObj->Probe(EIID_INode);
    }

    static CARAPI_(INode*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (INode*)pObj->Probe(EIID_INode);
    }

    virtual CARAPI GetNodeName(
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI GetNodeValue(
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI SetNodeValue(
        /* [in] */ const _ELASTOS String& nodeValue) = 0;

    virtual CARAPI GetNodeType(
        /* [out] */ _ELASTOS Int16 * value) = 0;

    virtual CARAPI GetParentNode(
        /* [out] */ Org::W3c::Dom::INode ** node) = 0;

    virtual CARAPI GetChildNodes(
        /* [out] */ Org::W3c::Dom::INodeList ** nodelist) = 0;

    virtual CARAPI GetFirstChild(
        /* [out] */ Org::W3c::Dom::INode ** node) = 0;

    virtual CARAPI GetLastChild(
        /* [out] */ Org::W3c::Dom::INode ** node) = 0;

    virtual CARAPI GetPreviousSibling(
        /* [out] */ Org::W3c::Dom::INode ** node) = 0;

    virtual CARAPI GetNextSibling(
        /* [out] */ Org::W3c::Dom::INode ** node) = 0;

    virtual CARAPI GetAttributes(
        /* [out] */ Org::W3c::Dom::INamedNodeMap ** nodemap) = 0;

    virtual CARAPI GetOwnerDocument(
        /* [out] */ Org::W3c::Dom::IDocument ** doc) = 0;

    virtual CARAPI InsertBefore(
        /* [in] */ Org::W3c::Dom::INode * newChild,
        /* [in] */ Org::W3c::Dom::INode * refChild,
        /* [out] */ Org::W3c::Dom::INode ** node) = 0;

    virtual CARAPI ReplaceChild(
        /* [in] */ Org::W3c::Dom::INode * newChild,
        /* [in] */ Org::W3c::Dom::INode * oldChild,
        /* [out] */ Org::W3c::Dom::INode ** node) = 0;

    virtual CARAPI RemoveChild(
        /* [in] */ Org::W3c::Dom::INode * oldChild,
        /* [out] */ Org::W3c::Dom::INode ** node) = 0;

    virtual CARAPI AppendChild(
        /* [in] */ Org::W3c::Dom::INode * newChild,
        /* [out] */ Org::W3c::Dom::INode ** node) = 0;

    virtual CARAPI HasChildNodes(
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI CloneNode(
        /* [in] */ _ELASTOS Boolean deep,
        /* [out] */ Org::W3c::Dom::INode ** node) = 0;

    virtual CARAPI Normalize() = 0;

    virtual CARAPI IsSupported(
        /* [in] */ const _ELASTOS String& feature,
        /* [in] */ const _ELASTOS String& ver,
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI GetNamespaceURI(
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI GetPrefix(
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI SetPrefix(
        /* [in] */ const _ELASTOS String& prefix) = 0;

    virtual CARAPI GetLocalName(
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI HasAttributes(
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI GetBaseURI(
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI CompareDocumentPosition(
        /* [in] */ Org::W3c::Dom::INode * other,
        /* [out] */ _ELASTOS Int16 * value) = 0;

    virtual CARAPI GetTextContent(
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI SetTextContent(
        /* [in] */ const _ELASTOS String& textContent) = 0;

    virtual CARAPI IsSameNode(
        /* [in] */ Org::W3c::Dom::INode * other,
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI LookupPrefix(
        /* [in] */ const _ELASTOS String& namespaceURI,
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI IsDefaultNamespace(
        /* [in] */ const _ELASTOS String& namespaceURI,
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI LookupNamespaceURI(
        /* [in] */ const _ELASTOS String& prefix,
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI IsEqualNode(
        /* [in] */ Org::W3c::Dom::INode * arg,
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI GetFeature(
        /* [in] */ const _ELASTOS String& feature,
        /* [in] */ const _ELASTOS String& ver,
        /* [out] */ IObject ** obj) = 0;

    virtual CARAPI SetUserData(
        /* [in] */ const _ELASTOS String& key,
        /* [in] */ IObject * data,
        /* [in] */ Org::W3c::Dom::IUserDataHandler * handler,
        /* [out] */ IObject ** obj) = 0;

    virtual CARAPI GetUserData(
        /* [in] */ const _ELASTOS String& key,
        /* [out] */ IObject ** obj) = 0;

};
}
}
}
namespace Org {
namespace W3c {
namespace Dom {
CAR_INTERFACE("B4C65918-7292-F5DF-8FD5-EA0F0EE6DFC8")
IAttr : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IAttr*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAttr*)pObj->Probe(EIID_IAttr);
    }

    static CARAPI_(IAttr*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAttr*)pObj->Probe(EIID_IAttr);
    }

    virtual CARAPI GetName(
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI GetSpecified(
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI GetValue(
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI SetValue(
        /* [in] */ const _ELASTOS String& value) = 0;

    virtual CARAPI GetOwnerElement(
        /* [out] */ Org::W3c::Dom::IElement ** element) = 0;

    virtual CARAPI GetSchemaTypeInfo(
        /* [out] */ Org::W3c::Dom::ITypeInfo ** info) = 0;

    virtual CARAPI IsId(
        /* [out] */ _ELASTOS Boolean * value) = 0;

};
}
}
}
namespace Org {
namespace W3c {
namespace Dom {
CAR_INTERFACE("32A6684C-90D2-2444-5E3D-6BC0E807861A")
ICharacterData : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICharacterData*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICharacterData*)pObj->Probe(EIID_ICharacterData);
    }

    static CARAPI_(ICharacterData*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICharacterData*)pObj->Probe(EIID_ICharacterData);
    }

    virtual CARAPI GetData(
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI SetData(
        /* [in] */ const _ELASTOS String& data) = 0;

    virtual CARAPI GetLength(
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI SubstringData(
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 count,
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI AppendData(
        /* [in] */ const _ELASTOS String& arg) = 0;

    virtual CARAPI InsertData(
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ const _ELASTOS String& arg) = 0;

    virtual CARAPI DeleteData(
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 count) = 0;

    virtual CARAPI ReplaceData(
        /* [in] */ _ELASTOS Int32 offset,
        /* [in] */ _ELASTOS Int32 count,
        /* [in] */ const _ELASTOS String& arg) = 0;

};
}
}
}
namespace Org {
namespace W3c {
namespace Dom {
CAR_INTERFACE("A51B5110-8752-F7EE-8FD5-EA0F0EE6DFC8")
IText : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IText*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IText*)pObj->Probe(EIID_IText);
    }

    static CARAPI_(IText*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IText*)pObj->Probe(EIID_IText);
    }

    virtual CARAPI SplitText(
        /* [in] */ _ELASTOS Int32 offset,
        /* [out] */ Org::W3c::Dom::IText ** text) = 0;

    virtual CARAPI IsElementContentWhitespace(
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI GetWholeText(
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI ReplaceWholeText(
        /* [in] */ const _ELASTOS String& content,
        /* [out] */ Org::W3c::Dom::IText ** text) = 0;

};
}
}
}
namespace Org {
namespace W3c {
namespace Dom {
CAR_INTERFACE("206D1A3B-8312-0A06-3A28-A8FC03430D15")
ICDATASection : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICDATASection*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDATASection*)pObj->Probe(EIID_ICDATASection);
    }

    static CARAPI_(ICDATASection*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDATASection*)pObj->Probe(EIID_ICDATASection);
    }

};
}
}
}
namespace Org {
namespace W3c {
namespace Dom {
CAR_INTERFACE("23CA1518-2312-30C3-1ADF-3F56AB3F3898")
IComment : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IComment*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IComment*)pObj->Probe(EIID_IComment);
    }

    static CARAPI_(IComment*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IComment*)pObj->Probe(EIID_IComment);
    }

};
}
}
}
namespace Org {
namespace W3c {
namespace Dom {
CAR_INTERFACE("E26A5652-0352-160C-8874-C377B7F30F0C")
IDOMConfiguration : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IDOMConfiguration*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDOMConfiguration*)pObj->Probe(EIID_IDOMConfiguration);
    }

    static CARAPI_(IDOMConfiguration*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDOMConfiguration*)pObj->Probe(EIID_IDOMConfiguration);
    }

    virtual CARAPI SetParameter(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ IObject * value) = 0;

    virtual CARAPI GetParameter(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ IObject ** obj) = 0;

    virtual CARAPI CanSetParameter(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ IObject * value,
        /* [out] */ _ELASTOS Boolean * reslut) = 0;

    virtual CARAPI GetParameterNames(
        /* [out] */ Org::W3c::Dom::IDOMStringList ** domlist) = 0;

};
}
}
}
namespace Org {
namespace W3c {
namespace Dom {
CAR_INTERFACE("4C085E09-8352-4E59-5DCB-F58FD5EA0F0E")
IDOMError : public IInterface
{
    static const _ELASTOS Int16 IDOMError_SEVERITY_WARNING = 1;
    static const _ELASTOS Int16 IDOMError_SEVERITY_ERROR = 2;
    static const _ELASTOS Int16 IDOMError_SEVERITY_FATAL_ERROR = 3;
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IDOMError*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDOMError*)pObj->Probe(EIID_IDOMError);
    }

    static CARAPI_(IDOMError*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDOMError*)pObj->Probe(EIID_IDOMError);
    }

    virtual CARAPI GetSeverity(
        /* [out] */ _ELASTOS Int16 * value) = 0;

    virtual CARAPI GetMessage(
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI GetType(
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI GetRelatedException(
        /* [out] */ IObject ** obj) = 0;

    virtual CARAPI GetRelatedData(
        /* [out] */ IObject ** obj) = 0;

    virtual CARAPI GetLocation(
        /* [out] */ Org::W3c::Dom::IDOMLocator ** domloc) = 0;

};
}
}
}
namespace Org {
namespace W3c {
namespace Dom {
CAR_INTERFACE("87342839-0352-160C-969D-FB81A1868A1F")
IDOMErrorHandler : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IDOMErrorHandler*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDOMErrorHandler*)pObj->Probe(EIID_IDOMErrorHandler);
    }

    static CARAPI_(IDOMErrorHandler*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDOMErrorHandler*)pObj->Probe(EIID_IDOMErrorHandler);
    }

    virtual CARAPI HandleError(
        /* [in] */ Org::W3c::Dom::IDOMError * error,
        /* [out] */ _ELASTOS Boolean * value) = 0;

};
}
}
}
namespace Org {
namespace W3c {
namespace Dom {
CAR_INTERFACE("E1845330-0352-160C-E891-80FF03430D15")
IDOMImplementation : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IDOMImplementation*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDOMImplementation*)pObj->Probe(EIID_IDOMImplementation);
    }

    static CARAPI_(IDOMImplementation*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDOMImplementation*)pObj->Probe(EIID_IDOMImplementation);
    }

    virtual CARAPI HasFeature(
        /* [in] */ const _ELASTOS String& feature,
        /* [in] */ const _ELASTOS String& ver,
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI CreateDocumentType(
        /* [in] */ const _ELASTOS String& qualifiedName,
        /* [in] */ const _ELASTOS String& publicId,
        /* [in] */ const _ELASTOS String& systemId,
        /* [out] */ Org::W3c::Dom::IDocumentType ** doc) = 0;

    virtual CARAPI CreateDocument(
        /* [in] */ const _ELASTOS String& namespaceURI,
        /* [in] */ const _ELASTOS String& qualifiedName,
        /* [in] */ Org::W3c::Dom::IDocumentType * doctype,
        /* [out] */ Org::W3c::Dom::IDocument ** doc) = 0;

    virtual CARAPI GetFeature(
        /* [in] */ const _ELASTOS String& feature,
        /* [in] */ const _ELASTOS String& ver,
        /* [out] */ IObject ** obj) = 0;

};
}
}
}
namespace Org {
namespace W3c {
namespace Dom {
CAR_INTERFACE("DF833032-0352-160C-E891-80AFF107861A")
IDOMImplementationList : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IDOMImplementationList*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDOMImplementationList*)pObj->Probe(EIID_IDOMImplementationList);
    }

    static CARAPI_(IDOMImplementationList*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDOMImplementationList*)pObj->Probe(EIID_IDOMImplementationList);
    }

    virtual CARAPI Item(
        /* [in] */ _ELASTOS Int32 index,
        /* [out] */ Org::W3c::Dom::IDOMImplementation ** dom) = 0;

    virtual CARAPI GetLength(
        /* [out] */ _ELASTOS Int32 * value) = 0;

};
}
}
}
namespace Org {
namespace W3c {
namespace Dom {
CAR_INTERFACE("1258513E-0352-160C-E891-806FFA07861A")
IDOMImplementationSource : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IDOMImplementationSource*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDOMImplementationSource*)pObj->Probe(EIID_IDOMImplementationSource);
    }

    static CARAPI_(IDOMImplementationSource*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDOMImplementationSource*)pObj->Probe(EIID_IDOMImplementationSource);
    }

    virtual CARAPI GetDOMImplementation(
        /* [in] */ const _ELASTOS String& features,
        /* [out] */ Org::W3c::Dom::IDOMImplementation ** dom) = 0;

    virtual CARAPI GetDOMImplementationList(
        /* [in] */ const _ELASTOS String& features,
        /* [out] */ Org::W3c::Dom::IDOMImplementationList ** domlist) = 0;

};
}
}
}
namespace Org {
namespace W3c {
namespace Dom {
CAR_INTERFACE("DD1A630B-8352-9559-6C92-B75CFF58ADFE")
IDOMLocator : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IDOMLocator*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDOMLocator*)pObj->Probe(EIID_IDOMLocator);
    }

    static CARAPI_(IDOMLocator*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDOMLocator*)pObj->Probe(EIID_IDOMLocator);
    }

    virtual CARAPI GetLineNumber(
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI GetColumnNumber(
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI GetByteOffset(
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI GetUtf16Offset(
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI GetRelatedNode(
        /* [out] */ Org::W3c::Dom::INode ** node) = 0;

    virtual CARAPI GetUri(
        /* [out] */ _ELASTOS String * str) = 0;

};
}
}
}
namespace Org {
namespace W3c {
namespace Dom {
CAR_INTERFACE("C8AA3029-0352-160C-606B-FC81A1868A1F")
IDOMStringList : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IDOMStringList*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDOMStringList*)pObj->Probe(EIID_IDOMStringList);
    }

    static CARAPI_(IDOMStringList*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDOMStringList*)pObj->Probe(EIID_IDOMStringList);
    }

    virtual CARAPI Item(
        /* [in] */ _ELASTOS Int32 index,
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI GetLength(
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI Contains(
        /* [in] */ const _ELASTOS String& str,
        /* [out] */ _ELASTOS Boolean * value) = 0;

};
}
}
}
namespace Org {
namespace W3c {
namespace Dom {
CAR_INTERFACE("0E0FFF2F-ACD2-181F-6AA8-F8016280891F")
IDocument : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IDocument*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDocument*)pObj->Probe(EIID_IDocument);
    }

    static CARAPI_(IDocument*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDocument*)pObj->Probe(EIID_IDocument);
    }

    virtual CARAPI GetDoctype(
        /* [out] */ Org::W3c::Dom::IDocumentType ** doctype) = 0;

    virtual CARAPI GetImplementation(
        /* [out] */ Org::W3c::Dom::IDOMImplementation ** dom) = 0;

    virtual CARAPI GetDocumentElement(
        /* [out] */ Org::W3c::Dom::IElement ** element) = 0;

    virtual CARAPI CreateElement(
        /* [in] */ const _ELASTOS String& tagName,
        /* [out] */ Org::W3c::Dom::IElement ** element) = 0;

    virtual CARAPI CreateDocumentFragment(
        /* [out] */ Org::W3c::Dom::IDocumentFragment ** docfra) = 0;

    virtual CARAPI CreateTextNode(
        /* [in] */ const _ELASTOS String& data,
        /* [out] */ Org::W3c::Dom::IText ** text) = 0;

    virtual CARAPI CreateComment(
        /* [in] */ const _ELASTOS String& data,
        /* [out] */ Org::W3c::Dom::IComment ** comment) = 0;

    virtual CARAPI CreateCDATASection(
        /* [in] */ const _ELASTOS String& data,
        /* [out] */ Org::W3c::Dom::ICDATASection ** datasection) = 0;

    virtual CARAPI CreateProcessingInstruction(
        /* [in] */ const _ELASTOS String& target,
        /* [in] */ const _ELASTOS String& data,
        /* [out] */ Org::W3c::Dom::IProcessingInstruction ** proins) = 0;

    virtual CARAPI CreateAttribute(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ Org::W3c::Dom::IAttr ** attr) = 0;

    virtual CARAPI CreateEntityReference(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ Org::W3c::Dom::IEntityReference ** entity) = 0;

    virtual CARAPI GetElementsByTagName(
        /* [in] */ const _ELASTOS String& tagname,
        /* [out] */ Org::W3c::Dom::INodeList ** nodelist) = 0;

    virtual CARAPI ImportNode(
        /* [in] */ Org::W3c::Dom::INode * importedNode,
        /* [in] */ _ELASTOS Boolean deep,
        /* [out] */ Org::W3c::Dom::INode ** node) = 0;

    virtual CARAPI CreateElementNS(
        /* [in] */ const _ELASTOS String& namespaceURI,
        /* [in] */ const _ELASTOS String& qualifiedName,
        /* [out] */ Org::W3c::Dom::IElement ** element) = 0;

    virtual CARAPI CreateAttributeNS(
        /* [in] */ const _ELASTOS String& namespaceURI,
        /* [in] */ const _ELASTOS String& qualifiedName,
        /* [out] */ Org::W3c::Dom::IAttr ** attr) = 0;

    virtual CARAPI GetElementsByTagNameNS(
        /* [in] */ const _ELASTOS String& namespaceURI,
        /* [in] */ const _ELASTOS String& localName,
        /* [out] */ Org::W3c::Dom::INodeList ** nodelist) = 0;

    virtual CARAPI GetElementById(
        /* [in] */ const _ELASTOS String& elementId,
        /* [out] */ Org::W3c::Dom::IElement ** elment) = 0;

    virtual CARAPI GetInputEncoding(
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI GetXmlEncoding(
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI GetXmlStandalone(
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI SetXmlStandalone(
        /* [in] */ _ELASTOS Boolean xmlStandalone) = 0;

    virtual CARAPI GetXmlVersion(
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI SetXmlVersion(
        /* [in] */ const _ELASTOS String& xmlVersion) = 0;

    virtual CARAPI GetStrictErrorChecking(
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI SetStrictErrorChecking(
        /* [in] */ _ELASTOS Boolean strictErrorChecking) = 0;

    virtual CARAPI GetDocumentURI(
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI SetDocumentURI(
        /* [in] */ const _ELASTOS String& documentURI) = 0;

    virtual CARAPI AdoptNode(
        /* [in] */ Org::W3c::Dom::INode * source,
        /* [out] */ Org::W3c::Dom::INode ** node) = 0;

    virtual CARAPI GetDomConfig(
        /* [out] */ Org::W3c::Dom::IDOMConfiguration ** domconfig) = 0;

    virtual CARAPI NormalizeDocument() = 0;

    virtual CARAPI RenameNode(
        /* [in] */ Org::W3c::Dom::INode * n,
        /* [in] */ const _ELASTOS String& namespaceURI,
        /* [in] */ const _ELASTOS String& qualifiedName,
        /* [out] */ Org::W3c::Dom::INode ** node) = 0;

};
}
}
}
namespace Org {
namespace W3c {
namespace Dom {
CAR_INTERFACE("28221E3B-ACD2-3507-48A8-78FF03430D15")
IDocumentFragment : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IDocumentFragment*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDocumentFragment*)pObj->Probe(EIID_IDocumentFragment);
    }

    static CARAPI_(IDocumentFragment*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDocumentFragment*)pObj->Probe(EIID_IDocumentFragment);
    }

};
}
}
}
namespace Org {
namespace W3c {
namespace Dom {
CAR_INTERFACE("09835F2D-ACD2-3FE5-30D4-50F103C40013")
IDocumentType : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IDocumentType*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDocumentType*)pObj->Probe(EIID_IDocumentType);
    }

    static CARAPI_(IDocumentType*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDocumentType*)pObj->Probe(EIID_IDocumentType);
    }

    virtual CARAPI GetName(
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI GetEntities(
        /* [out] */ Org::W3c::Dom::INamedNodeMap ** nodemap) = 0;

    virtual CARAPI GetNotations(
        /* [out] */ Org::W3c::Dom::INamedNodeMap ** nodemap) = 0;

    virtual CARAPI GetPublicId(
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI GetSystemId(
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI GetInternalSubset(
        /* [out] */ _ELASTOS String * str) = 0;

};
}
}
}
namespace Org {
namespace W3c {
namespace Dom {
CAR_INTERFACE("FFDDF40B-F392-30A2-1ADF-3F56AB3F3898")
IElement : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IElement*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IElement*)pObj->Probe(EIID_IElement);
    }

    static CARAPI_(IElement*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IElement*)pObj->Probe(EIID_IElement);
    }

    virtual CARAPI GetTagName(
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI GetAttribute(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI SetAttribute(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ const _ELASTOS String& value) = 0;

    virtual CARAPI RemoveAttribute(
        /* [in] */ const _ELASTOS String& name) = 0;

    virtual CARAPI GetAttributeNode(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ Org::W3c::Dom::IAttr ** attr) = 0;

    virtual CARAPI SetAttributeNode(
        /* [in] */ Org::W3c::Dom::IAttr * newAttr,
        /* [out] */ Org::W3c::Dom::IAttr ** attr) = 0;

    virtual CARAPI RemoveAttributeNode(
        /* [in] */ Org::W3c::Dom::IAttr * oldAttr,
        /* [out] */ Org::W3c::Dom::IAttr ** attr) = 0;

    virtual CARAPI GetElementsByTagName(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ Org::W3c::Dom::INodeList ** nodelist) = 0;

    virtual CARAPI GetAttributeNS(
        /* [in] */ const _ELASTOS String& namespaceURI,
        /* [in] */ const _ELASTOS String& localName,
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI SetAttributeNS(
        /* [in] */ const _ELASTOS String& namespaceURI,
        /* [in] */ const _ELASTOS String& qualifiedName,
        /* [in] */ const _ELASTOS String& value) = 0;

    virtual CARAPI RemoveAttributeNS(
        /* [in] */ const _ELASTOS String& namespaceURI,
        /* [in] */ const _ELASTOS String& localName) = 0;

    virtual CARAPI GetAttributeNodeNS(
        /* [in] */ const _ELASTOS String& namespaceURI,
        /* [in] */ const _ELASTOS String& localName,
        /* [out] */ Org::W3c::Dom::IAttr ** attr) = 0;

    virtual CARAPI SetAttributeNodeNS(
        /* [in] */ Org::W3c::Dom::IAttr * newAttr,
        /* [out] */ Org::W3c::Dom::IAttr ** attr) = 0;

    virtual CARAPI GetElementsByTagNameNS(
        /* [in] */ const _ELASTOS String& namespaceURI,
        /* [in] */ const _ELASTOS String& localName,
        /* [out] */ Org::W3c::Dom::INodeList ** nodelist) = 0;

    virtual CARAPI HasAttribute(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI HasAttributeNS(
        /* [in] */ const _ELASTOS String& namespaceURI,
        /* [in] */ const _ELASTOS String& localName,
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI GetSchemaTypeInfo(
        /* [out] */ Org::W3c::Dom::ITypeInfo ** info) = 0;

    virtual CARAPI SetIdAttribute(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ _ELASTOS Boolean isId) = 0;

    virtual CARAPI SetIdAttributeNS(
        /* [in] */ const _ELASTOS String& namespaceURI,
        /* [in] */ const _ELASTOS String& localName,
        /* [in] */ _ELASTOS Boolean isId) = 0;

    virtual CARAPI SetIdAttributeNode(
        /* [in] */ Org::W3c::Dom::IAttr * idAttr,
        /* [in] */ _ELASTOS Boolean isId) = 0;

};
}
}
}
namespace Org {
namespace W3c {
namespace Dom {
CAR_INTERFACE("694A6410-1392-ECDF-CDFF-58ADFEE060FE")
IEntity : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IEntity*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IEntity*)pObj->Probe(EIID_IEntity);
    }

    static CARAPI_(IEntity*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IEntity*)pObj->Probe(EIID_IEntity);
    }

    virtual CARAPI GetPublicId(
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI GetSystemId(
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI GetNotationName(
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI GetInputEncoding(
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI GetXmlEncoding(
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI GetXmlVersion(
        /* [out] */ _ELASTOS String * str) = 0;

};
}
}
}
namespace Org {
namespace W3c {
namespace Dom {
CAR_INTERFACE("81301D5A-13D2-698C-B2E1-8D01EA07861A")
IEntityReference : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IEntityReference*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IEntityReference*)pObj->Probe(EIID_IEntityReference);
    }

    static CARAPI_(IEntityReference*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IEntityReference*)pObj->Probe(EIID_IEntityReference);
    }

};
}
}
}
namespace Org {
namespace W3c {
namespace Dom {
CAR_INTERFACE("644D473B-5052-3F8D-30D4-50F103C40013")
INameList : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(INameList*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (INameList*)pObj->Probe(EIID_INameList);
    }

    static CARAPI_(INameList*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (INameList*)pObj->Probe(EIID_INameList);
    }

    virtual CARAPI GetName(
        /* [in] */ _ELASTOS Int32 index,
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI GetNamespaceURI(
        /* [in] */ _ELASTOS Int32 index,
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI GetLength(
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI Contains(
        /* [in] */ const _ELASTOS String& str,
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI ContainsNS(
        /* [in] */ const _ELASTOS String& namespaceURI,
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ _ELASTOS Boolean * value) = 0;

};
}
}
}
namespace Org {
namespace W3c {
namespace Dom {
CAR_INTERFACE("F4FB7B09-45D2-E8C2-79C9-276A91F38FD5")
INamedNodeMap : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(INamedNodeMap*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (INamedNodeMap*)pObj->Probe(EIID_INamedNodeMap);
    }

    static CARAPI_(INamedNodeMap*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (INamedNodeMap*)pObj->Probe(EIID_INamedNodeMap);
    }

    virtual CARAPI GetNamedItem(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ Org::W3c::Dom::INode ** node) = 0;

    virtual CARAPI SetNamedItem(
        /* [in] */ Org::W3c::Dom::INode * arg,
        /* [out] */ Org::W3c::Dom::INode ** node) = 0;

    virtual CARAPI RemoveNamedItem(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ Org::W3c::Dom::INode ** node) = 0;

    virtual CARAPI Item(
        /* [in] */ _ELASTOS Int32 index,
        /* [out] */ Org::W3c::Dom::INode ** node) = 0;

    virtual CARAPI GetLength(
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI GetNamedItemNS(
        /* [in] */ const _ELASTOS String& namespaceURI,
        /* [in] */ const _ELASTOS String& localName,
        /* [out] */ Org::W3c::Dom::INode ** node) = 0;

    virtual CARAPI SetNamedItemNS(
        /* [in] */ Org::W3c::Dom::INode * arg,
        /* [out] */ Org::W3c::Dom::INode ** node) = 0;

    virtual CARAPI RemoveNamedItemNS(
        /* [in] */ const _ELASTOS String& namespaceURI,
        /* [in] */ const _ELASTOS String& localName,
        /* [out] */ Org::W3c::Dom::INode ** node) = 0;

};
}
}
}
namespace Org {
namespace W3c {
namespace Dom {
CAR_INTERFACE("42AB2C46-1792-3FCA-30D4-50F103C40013")
INotation : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(INotation*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (INotation*)pObj->Probe(EIID_INotation);
    }

    static CARAPI_(INotation*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (INotation*)pObj->Probe(EIID_INotation);
    }

    virtual CARAPI GetPublicId(
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI GetSystemId(
        /* [out] */ _ELASTOS String * str) = 0;

};
}
}
}
namespace Org {
namespace W3c {
namespace Dom {
CAR_INTERFACE("CA613A23-DA12-07FA-6DDC-A881C304FC1F")
IProcessingInstruction : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IProcessingInstruction*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IProcessingInstruction*)pObj->Probe(EIID_IProcessingInstruction);
    }

    static CARAPI_(IProcessingInstruction*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IProcessingInstruction*)pObj->Probe(EIID_IProcessingInstruction);
    }

    virtual CARAPI GetTarget(
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI GetData(
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI SetData(
        /* [in] */ const _ELASTOS String& data) = 0;

};
}
}
}
namespace Org {
namespace W3c {
namespace Dom {
CAR_INTERFACE("E4F83E39-F2D2-3F7D-30D4-50F103C40013")
ITypeInfo : public IInterface
{
    static const _ELASTOS Int32 DERIVATION_RESTRICTION = 0x00000001;
    static const _ELASTOS Int32 DERIVATION_EXTENSION = 0x00000002;
    static const _ELASTOS Int32 DERIVATION_UNION = 0x00000004;
    static const _ELASTOS Int32 DERIVATION_LIST = 0x00000008;
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ITypeInfo*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ITypeInfo*)pObj->Probe(EIID_ITypeInfo);
    }

    static CARAPI_(ITypeInfo*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ITypeInfo*)pObj->Probe(EIID_ITypeInfo);
    }

    virtual CARAPI GetTypeName(
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI GetTypeNamespace(
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI IsDerivedFrom(
        /* [in] */ const _ELASTOS String& typeNamespaceArg,
        /* [in] */ const _ELASTOS String& typeNameArg,
        /* [in] */ _ELASTOS Int32 derivationMethod,
        /* [out] */ _ELASTOS Boolean * value) = 0;

};
}
}
}
namespace Org {
namespace W3c {
namespace Dom {
CAR_INTERFACE("4C4C232A-7692-E74C-7E60-A8A1E2078801")
IUserDataHandler : public IInterface
{
    static const _ELASTOS Int16 NODE_CLONED = 1;
    static const _ELASTOS Int16 NODE_IMPORTED = 2;
    static const _ELASTOS Int16 NODE_DELETED = 3;
    static const _ELASTOS Int16 NODE_RENAMED = 4;
    static const _ELASTOS Int16 NODE_ADOPTED = 5;
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IUserDataHandler*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IUserDataHandler*)pObj->Probe(EIID_IUserDataHandler);
    }

    static CARAPI_(IUserDataHandler*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IUserDataHandler*)pObj->Probe(EIID_IUserDataHandler);
    }

    virtual CARAPI Handle(
        /* [in] */ _ELASTOS Int16 operation,
        /* [in] */ const _ELASTOS String& key,
        /* [in] */ IObject * data,
        /* [in] */ Org::W3c::Dom::INode * src,
        /* [in] */ Org::W3c::Dom::INode * dst) = 0;

};
}
}
}
namespace Org {
namespace W3c {
namespace Dom {
namespace Traversal {
CAR_INTERFACE("67AC2C18-25D2-E89F-C3BE-375AFF58ADFE")
INodeFilter : public IInterface
{
    static const _ELASTOS Int16 FILTER_ACCEPT = 1;
    static const _ELASTOS Int16 FILTER_REJECT = 2;
    static const _ELASTOS Int16 FILTER_SKIP = 3;
    static const _ELASTOS Int32 SHOW_ALL = 0xffffffff;
    static const _ELASTOS Int32 SHOW_ELEMENT = 0x00000001;
    static const _ELASTOS Int32 SHOW_ATTRIBUTE = 0x00000002;
    static const _ELASTOS Int32 SHOW_TEXT = 0x00000004;
    static const _ELASTOS Int32 SHOW_CDATA_SECTION = 0x00000008;
    static const _ELASTOS Int32 SHOW_ENTITY_REFERENCE = 0x00000010;
    static const _ELASTOS Int32 SHOW_ENTITY = 0x00000020;
    static const _ELASTOS Int32 SHOW_PROCESSING_INSTRUCTION = 0x00000040;
    static const _ELASTOS Int32 SHOW_COMMENT = 0x00000080;
    static const _ELASTOS Int32 SHOW_DOCUMENT = 0x00000100;
    static const _ELASTOS Int32 SHOW_DOCUMENT_TYPE = 0x00000200;
    static const _ELASTOS Int32 SHOW_DOCUMENT_FRAGMENT = 0x00000400;
    static const _ELASTOS Int32 SHOW_NOTATION = 0x00000800;
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(INodeFilter*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (INodeFilter*)pObj->Probe(EIID_INodeFilter);
    }

    static CARAPI_(INodeFilter*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (INodeFilter*)pObj->Probe(EIID_INodeFilter);
    }

    virtual CARAPI AcceptNode(
        /* [in] */ Org::W3c::Dom::INode * n,
        /* [out] */ _ELASTOS Int16 * value) = 0;

};
}
}
}
}
namespace Org {
namespace W3c {
namespace Dom {
namespace Traversal {
CAR_INTERFACE("B581744D-9792-1259-323F-BAFA03430D15")
INodeIterator : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(INodeIterator*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (INodeIterator*)pObj->Probe(EIID_INodeIterator);
    }

    static CARAPI_(INodeIterator*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (INodeIterator*)pObj->Probe(EIID_INodeIterator);
    }

    virtual CARAPI GetRoot(
        /* [out] */ Org::W3c::Dom::INode ** node) = 0;

    virtual CARAPI GetWhatToShow(
        /* [out] */ _ELASTOS Int32 * value) = 0;

    virtual CARAPI GetFilter(
        /* [out] */ Org::W3c::Dom::Traversal::INodeFilter ** node) = 0;

    virtual CARAPI GetExpandEntityReferences(
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI NextNode(
        /* [out] */ Org::W3c::Dom::INode ** node) = 0;

    virtual CARAPI PreviousNode(
        /* [out] */ Org::W3c::Dom::INode ** node) = 0;

    virtual CARAPI Detach() = 0;

};
}
}
}
}
namespace Org {
namespace W3c {
namespace Dom {
namespace Ls {
CAR_INTERFACE("7EFF5F3D-0352-160C-E891-805F81C30F0C")
IDOMImplementationLS : public IInterface
{
    static const _ELASTOS Int16 MODE_SYNCHRONOUS = 1;
    static const _ELASTOS Int16 MODE_ASYNCHRONOUS = 2;
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IDOMImplementationLS*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDOMImplementationLS*)pObj->Probe(EIID_IDOMImplementationLS);
    }

    static CARAPI_(IDOMImplementationLS*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDOMImplementationLS*)pObj->Probe(EIID_IDOMImplementationLS);
    }

    virtual CARAPI CreateLSParser(
        /* [in] */ _ELASTOS Int16 mode,
        /* [in] */ const _ELASTOS String& schemaType,
        /* [out] */ Org::W3c::Dom::Ls::ILSParser ** lsparser) = 0;

    virtual CARAPI CreateLSSerializer(
        /* [out] */ Org::W3c::Dom::Ls::ILSSerializer ** lsserial) = 0;

    virtual CARAPI CreateLSInput(
        /* [out] */ Org::W3c::Dom::Ls::ILSInput ** lsinput) = 0;

    virtual CARAPI CreateLSOutput(
        /* [out] */ Org::W3c::Dom::Ls::ILSOutput ** lsoutput) = 0;

};
}
}
}
}
namespace Org {
namespace W3c {
namespace Dom {
namespace Ls {
CAR_INTERFACE("9EF8E609-C552-F149-8CDF-3F56AB3F3898")
ILSInput : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ILSInput*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ILSInput*)pObj->Probe(EIID_ILSInput);
    }

    static CARAPI_(ILSInput*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ILSInput*)pObj->Probe(EIID_ILSInput);
    }

    virtual CARAPI GetCharacterStream(
        /* [out] */ Elastos::IO::IReader ** reader) = 0;

    virtual CARAPI SetCharacterStream(
        /* [in] */ Elastos::IO::IReader * characterStream) = 0;

    virtual CARAPI GetByteStream(
        /* [out] */ Elastos::IO::IInputStream ** input) = 0;

    virtual CARAPI SetByteStream(
        /* [in] */ Elastos::IO::IInputStream * byteStream) = 0;

    virtual CARAPI GetStringData(
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI SetStringData(
        /* [in] */ const _ELASTOS String& stringData) = 0;

    virtual CARAPI GetSystemId(
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI SetSystemId(
        /* [in] */ const _ELASTOS String& systemId) = 0;

    virtual CARAPI GetPublicId(
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI SetPublicId(
        /* [in] */ const _ELASTOS String& publicId) = 0;

    virtual CARAPI GetBaseURI(
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI SetBaseURI(
        /* [in] */ const _ELASTOS String& baseURI) = 0;

    virtual CARAPI GetEncoding(
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI SetEncoding(
        /* [in] */ const _ELASTOS String& encoding) = 0;

    virtual CARAPI GetCertifiedText(
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI SetCertifiedText(
        /* [in] */ _ELASTOS Boolean certifiedText) = 0;

};
}
}
}
}
namespace Org {
namespace W3c {
namespace Dom {
namespace Ls {
CAR_INTERFACE("F0B3831F-C552-F861-3DE3-F78FD5EA0F0E")
ILSOutput : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ILSOutput*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ILSOutput*)pObj->Probe(EIID_ILSOutput);
    }

    static CARAPI_(ILSOutput*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ILSOutput*)pObj->Probe(EIID_ILSOutput);
    }

    virtual CARAPI GetCharacterStream(
        /* [out] */ Elastos::IO::IWriter ** writer) = 0;

    virtual CARAPI SetCharacterStream(
        /* [in] */ Elastos::IO::IWriter * characterStream) = 0;

    virtual CARAPI GetByteStream(
        /* [out] */ Elastos::IO::IOutputStream ** output) = 0;

    virtual CARAPI SetByteStream(
        /* [in] */ Elastos::IO::IOutputStream * byteStream) = 0;

    virtual CARAPI GetSystemId(
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI SetSystemId(
        /* [in] */ const _ELASTOS String& systemId) = 0;

    virtual CARAPI GetEncoding(
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI SetEncoding(
        /* [in] */ const _ELASTOS String& encoding) = 0;

};
}
}
}
}
namespace Org {
namespace W3c {
namespace Dom {
namespace Ls {
CAR_INTERFACE("66586817-C552-6465-6DA3-F58FD5EA0F0E")
ILSParser : public IInterface
{
    static const _ELASTOS Int16 ACTION_APPEND_AS_CHILDREN = 1;
    static const _ELASTOS Int16 ACTION_REPLACE_CHILDREN = 2;
    static const _ELASTOS Int16 ACTION_INSERT_BEFORE = 3;
    static const _ELASTOS Int16 ACTION_INSERT_AFTER = 4;
    static const _ELASTOS Int16 ACTION_REPLACE = 5;
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ILSParser*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ILSParser*)pObj->Probe(EIID_ILSParser);
    }

    static CARAPI_(ILSParser*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ILSParser*)pObj->Probe(EIID_ILSParser);
    }

    virtual CARAPI GetDomConfig(
        /* [out] */ Org::W3c::Dom::IDOMConfiguration ** domconfig) = 0;

    virtual CARAPI GetFilter(
        /* [out] */ Org::W3c::Dom::Ls::ILSParserFilter ** lsparse) = 0;

    virtual CARAPI SetFilter(
        /* [in] */ Org::W3c::Dom::Ls::ILSParserFilter * filter) = 0;

    virtual CARAPI GetAsync(
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI GetBusy(
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI Parse(
        /* [in] */ Org::W3c::Dom::Ls::ILSInput * input,
        /* [out] */ Org::W3c::Dom::IDocument ** doc) = 0;

    virtual CARAPI ParseURI(
        /* [in] */ const _ELASTOS String& uri,
        /* [out] */ Org::W3c::Dom::IDocument ** doc) = 0;

    virtual CARAPI ParseWithContext(
        /* [in] */ Org::W3c::Dom::Ls::ILSInput * input,
        /* [in] */ Org::W3c::Dom::INode * contextArg,
        /* [in] */ _ELASTOS Int16 action,
        /* [out] */ Org::W3c::Dom::INode ** node) = 0;

    virtual CARAPI Abort() = 0;

};
}
}
}
}
namespace Org {
namespace W3c {
namespace Dom {
namespace Ls {
CAR_INTERFACE("0F7B4208-C552-6465-6DA3-F5C3BE375AFF")
ILSParserFilter : public IInterface
{
    static const _ELASTOS Int16 FILTER_ACCEPT = 1;
    static const _ELASTOS Int16 FILTER_REJECT = 2;
    static const _ELASTOS Int16 FILTER_SKIP = 3;
    static const _ELASTOS Int16 FILTER_INTERRUPT = 4;
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ILSParserFilter*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ILSParserFilter*)pObj->Probe(EIID_ILSParserFilter);
    }

    static CARAPI_(ILSParserFilter*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ILSParserFilter*)pObj->Probe(EIID_ILSParserFilter);
    }

    virtual CARAPI StartElement(
        /* [in] */ Org::W3c::Dom::IElement * elementArg,
        /* [out] */ _ELASTOS Int16 * value) = 0;

    virtual CARAPI AcceptNode(
        /* [in] */ Org::W3c::Dom::INode * nodeArg,
        /* [out] */ _ELASTOS Int16 * value) = 0;

    virtual CARAPI GetWhatToShow(
        /* [out] */ _ELASTOS Int32 * value) = 0;

};
}
}
}
}
namespace Org {
namespace W3c {
namespace Dom {
namespace Ls {
CAR_INTERFACE("F6703239-0552-840E-37E0-97F122C7FD1F")
ILSResourceResolver : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ILSResourceResolver*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ILSResourceResolver*)pObj->Probe(EIID_ILSResourceResolver);
    }

    static CARAPI_(ILSResourceResolver*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ILSResourceResolver*)pObj->Probe(EIID_ILSResourceResolver);
    }

    virtual CARAPI ResolveResource(
        /* [in] */ const _ELASTOS String& type,
        /* [in] */ const _ELASTOS String& namespaceURI,
        /* [in] */ const _ELASTOS String& publicId,
        /* [in] */ const _ELASTOS String& systemId,
        /* [in] */ const _ELASTOS String& baseURI,
        /* [out] */ Org::W3c::Dom::Ls::ILSInput ** lsinput) = 0;

};
}
}
}
}
namespace Org {
namespace W3c {
namespace Dom {
namespace Ls {
CAR_INTERFACE("107D6B08-C552-6871-CD92-2FDBA3F58FD5")
ILSSerializer : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ILSSerializer*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ILSSerializer*)pObj->Probe(EIID_ILSSerializer);
    }

    static CARAPI_(ILSSerializer*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ILSSerializer*)pObj->Probe(EIID_ILSSerializer);
    }

    virtual CARAPI GetDomConfig(
        /* [out] */ Org::W3c::Dom::IDOMConfiguration ** dom) = 0;

    virtual CARAPI GetNewLine(
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI SetNewLine(
        /* [in] */ const _ELASTOS String& newLine) = 0;

    virtual CARAPI GetFilter(
        /* [out] */ Org::W3c::Dom::Ls::ILSSerializerFilter ** lsserial) = 0;

    virtual CARAPI SetFilter(
        /* [in] */ Org::W3c::Dom::Ls::ILSSerializerFilter * filter) = 0;

    virtual CARAPI Write(
        /* [in] */ Org::W3c::Dom::INode * nodeArg,
        /* [in] */ Org::W3c::Dom::Ls::ILSOutput * destination,
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI WriteToURI(
        /* [in] */ Org::W3c::Dom::INode * nodeArg,
        /* [in] */ const _ELASTOS String& uri,
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI WriteToString(
        /* [in] */ Org::W3c::Dom::INode * nodeArg,
        /* [out] */ _ELASTOS String * str) = 0;

};
}
}
}
}
namespace Org {
namespace W3c {
namespace Dom {
namespace Ls {
CAR_INTERFACE("7B17305E-0552-1C0E-9E05-EC58E3018B9A")
ILSSerializerFilter : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ILSSerializerFilter*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ILSSerializerFilter*)pObj->Probe(EIID_ILSSerializerFilter);
    }

    static CARAPI_(ILSSerializerFilter*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ILSSerializerFilter*)pObj->Probe(EIID_ILSSerializerFilter);
    }

    virtual CARAPI GetWhatToShow(
        /* [out] */ _ELASTOS Int32 * value) = 0;

};
}
}
}
}
namespace Org {
namespace W3c {
namespace Dom {
CAR_INTERFACE("67155E33-8312-7AE0-8CFE-C05043C50F10")
ICTextClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICTextClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICTextClassObject*)pObj->Probe(EIID_ICTextClassObject);
    }

    static CARAPI_(ICTextClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICTextClassObject*)pObj->Probe(EIID_ICTextClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Org {
namespace Xml {
namespace Sax {
CAR_INTERFACE("85A54926-1712-3F8D-30D4-50F123048C17")
IAttributeList : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IAttributeList*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAttributeList*)pObj->Probe(EIID_IAttributeList);
    }

    static CARAPI_(IAttributeList*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAttributeList*)pObj->Probe(EIID_IAttributeList);
    }

    virtual CARAPI GetLength(
        /* [out] */ _ELASTOS Int32 * length) = 0;

    virtual CARAPI GetName(
        /* [in] */ _ELASTOS Int32 i,
        /* [out] */ _ELASTOS String * name) = 0;

    virtual CARAPI GetType(
        /* [in] */ _ELASTOS Int32 i,
        /* [out] */ _ELASTOS String * type) = 0;

    virtual CARAPI GetValue(
        /* [in] */ _ELASTOS Int32 i,
        /* [out] */ _ELASTOS String * value) = 0;

    virtual CARAPI GetType(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ _ELASTOS String * type) = 0;

    virtual CARAPI GetValue(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ _ELASTOS String * value) = 0;

};
}
}
}
namespace Org {
namespace Xml {
namespace Sax {
CAR_INTERFACE("87BE7832-1712-3F1B-30D4-50F123048C17")
IAttributes : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IAttributes*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAttributes*)pObj->Probe(EIID_IAttributes);
    }

    static CARAPI_(IAttributes*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAttributes*)pObj->Probe(EIID_IAttributes);
    }

    virtual CARAPI GetLength(
        /* [out] */ _ELASTOS Int32 * length) = 0;

    virtual CARAPI GetURI(
        /* [in] */ _ELASTOS Int32 index,
        /* [out] */ _ELASTOS String * URI) = 0;

    virtual CARAPI GetLocalName(
        /* [in] */ _ELASTOS Int32 index,
        /* [out] */ _ELASTOS String * localName) = 0;

    virtual CARAPI GetQName(
        /* [in] */ _ELASTOS Int32 index,
        /* [out] */ _ELASTOS String * qName) = 0;

    virtual CARAPI GetType(
        /* [in] */ _ELASTOS Int32 index,
        /* [out] */ _ELASTOS String * type) = 0;

    virtual CARAPI GetValue(
        /* [in] */ _ELASTOS Int32 index,
        /* [out] */ _ELASTOS String * value) = 0;

    virtual CARAPI GetIndex(
        /* [in] */ const _ELASTOS String& uri,
        /* [in] */ const _ELASTOS String& localName,
        /* [out] */ _ELASTOS Int32 * index) = 0;

    virtual CARAPI GetIndex(
        /* [in] */ const _ELASTOS String& qName,
        /* [out] */ _ELASTOS Int32 * index) = 0;

    virtual CARAPI GetType(
        /* [in] */ const _ELASTOS String& uri,
        /* [in] */ const _ELASTOS String& localName,
        /* [out] */ _ELASTOS String * type) = 0;

    virtual CARAPI GetType(
        /* [in] */ const _ELASTOS String& qName,
        /* [out] */ _ELASTOS String * type) = 0;

    virtual CARAPI GetValue(
        /* [in] */ const _ELASTOS String& uri,
        /* [in] */ const _ELASTOS String& localName,
        /* [out] */ _ELASTOS String * value) = 0;

    virtual CARAPI GetValue(
        /* [in] */ const _ELASTOS String& qName,
        /* [out] */ _ELASTOS String * value) = 0;

};
}
}
}
namespace Org {
namespace Xml {
namespace Sax {
CAR_INTERFACE("DAD8BD30-0312-3119-6EA0-8871E3DC0F0C")
IContentHandler : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IContentHandler*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IContentHandler*)pObj->Probe(EIID_IContentHandler);
    }

    static CARAPI_(IContentHandler*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IContentHandler*)pObj->Probe(EIID_IContentHandler);
    }

    virtual CARAPI SetDocumentLocator(
        /* [in] */ Org::Xml::Sax::ILocator * locator) = 0;

    virtual CARAPI StartDocument() = 0;

    virtual CARAPI EndDocument() = 0;

    virtual CARAPI StartPrefixMapping(
        /* [in] */ const _ELASTOS String& prefix,
        /* [in] */ const _ELASTOS String& uri) = 0;

    virtual CARAPI EndPrefixMapping(
        /* [in] */ const _ELASTOS String& prefix) = 0;

    virtual CARAPI StartElement(
        /* [in] */ const _ELASTOS String& uri,
        /* [in] */ const _ELASTOS String& localName,
        /* [in] */ const _ELASTOS String& qName,
        /* [in] */ Org::Xml::Sax::IAttributes * atts) = 0;

    virtual CARAPI EndElement(
        /* [in] */ const _ELASTOS String& uri,
        /* [in] */ const _ELASTOS String& localName,
        /* [in] */ const _ELASTOS String& qName) = 0;

    virtual CARAPI Characters(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Char32> * ch,
        /* [in] */ _ELASTOS Int32 start,
        /* [in] */ _ELASTOS Int32 length) = 0;

    virtual CARAPI IgnorableWhitespace(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Char32> * ch,
        /* [in] */ _ELASTOS Int32 start,
        /* [in] */ _ELASTOS Int32 length) = 0;

    virtual CARAPI ProcessingInstruction(
        /* [in] */ const _ELASTOS String& target,
        /* [in] */ const _ELASTOS String& data) = 0;

    virtual CARAPI SkippedEntity(
        /* [in] */ const _ELASTOS String& name) = 0;

};
}
}
}
namespace Org {
namespace Xml {
namespace Sax {
CAR_INTERFACE("E2658F39-ACD2-3F73-30D4-50F123048C17")
IDocumentHandler : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IDocumentHandler*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDocumentHandler*)pObj->Probe(EIID_IDocumentHandler);
    }

    static CARAPI_(IDocumentHandler*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDocumentHandler*)pObj->Probe(EIID_IDocumentHandler);
    }

    virtual CARAPI SetDocumentLocator(
        /* [in] */ Org::Xml::Sax::ILocator * locator) = 0;

    virtual CARAPI StartDocument() = 0;

    virtual CARAPI EndDocument() = 0;

    virtual CARAPI StartElement(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ Org::Xml::Sax::IAttributeList * atts) = 0;

    virtual CARAPI EndElement(
        /* [in] */ const _ELASTOS String& name) = 0;

    virtual CARAPI Characters(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Char32> * ch,
        /* [in] */ _ELASTOS Int32 start,
        /* [in] */ _ELASTOS Int32 length) = 0;

    virtual CARAPI IgnorableWhitespace(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Char32> * ch,
        /* [in] */ _ELASTOS Int32 start,
        /* [in] */ _ELASTOS Int32 length) = 0;

    virtual CARAPI ProcessingInstruction(
        /* [in] */ const _ELASTOS String& target,
        /* [in] */ const _ELASTOS String& data) = 0;

};
}
}
}
namespace Org {
namespace Xml {
namespace Sax {
CAR_INTERFACE("0AC4363D-8352-0D0E-CEFD-C05043C58F10")
IDTDHandler : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IDTDHandler*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDTDHandler*)pObj->Probe(EIID_IDTDHandler);
    }

    static CARAPI_(IDTDHandler*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDTDHandler*)pObj->Probe(EIID_IDTDHandler);
    }

    virtual CARAPI NotationDecl(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ const _ELASTOS String& publicId,
        /* [in] */ const _ELASTOS String& systemId) = 0;

    virtual CARAPI UnparsedEntityDecl(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ const _ELASTOS String& publicId,
        /* [in] */ const _ELASTOS String& systemId,
        /* [in] */ const _ELASTOS String& notationName) = 0;

};
}
}
}
namespace Org {
namespace Xml {
namespace Sax {
CAR_INTERFACE("4AF1295F-13D2-698C-1EBF-F05DE307861A")
IEntityResolver : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IEntityResolver*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IEntityResolver*)pObj->Probe(EIID_IEntityResolver);
    }

    static CARAPI_(IEntityResolver*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IEntityResolver*)pObj->Probe(EIID_IEntityResolver);
    }

    virtual CARAPI ResolveEntity(
        /* [in] */ const _ELASTOS String& publicId,
        /* [in] */ const _ELASTOS String& systemId,
        /* [out] */ Org::Xml::Sax::IInputSource ** src) = 0;

};
}
}
}
namespace Org {
namespace Xml {
namespace Sax {
CAR_INTERFACE("58733031-B2D2-3F73-30D4-50F123048C17")
IErrorHandler : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IErrorHandler*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IErrorHandler*)pObj->Probe(EIID_IErrorHandler);
    }

    static CARAPI_(IErrorHandler*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IErrorHandler*)pObj->Probe(EIID_IErrorHandler);
    }

    virtual CARAPI Warning(
        /* [in] */ _ELASTOS ECode exception) = 0;

    virtual CARAPI Error(
        /* [in] */ _ELASTOS ECode exception) = 0;

    virtual CARAPI FatalError(
        /* [in] */ _ELASTOS ECode exception) = 0;

};
}
}
}
namespace Org {
namespace Xml {
namespace Sax {
CAR_INTERFACE("96EC993B-3FD2-3FD3-30D4-50F123048C17")
IInputSource : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IInputSource*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IInputSource*)pObj->Probe(EIID_IInputSource);
    }

    static CARAPI_(IInputSource*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IInputSource*)pObj->Probe(EIID_IInputSource);
    }

    virtual CARAPI SetPublicId(
        /* [in] */ const _ELASTOS String& publicId) = 0;

    virtual CARAPI GetPublicId(
        /* [out] */ _ELASTOS String * publicId) = 0;

    virtual CARAPI SetSystemId(
        /* [in] */ const _ELASTOS String& systemId) = 0;

    virtual CARAPI GetSystemId(
        /* [out] */ _ELASTOS String * systemId) = 0;

    virtual CARAPI SetByteStream(
        /* [in] */ Elastos::IO::IInputStream * byteStream) = 0;

    virtual CARAPI GetByteStream(
        /* [out] */ Elastos::IO::IInputStream ** byteStream) = 0;

    virtual CARAPI SetEncoding(
        /* [in] */ const _ELASTOS String& encoding) = 0;

    virtual CARAPI GetEncoding(
        /* [out] */ _ELASTOS String * encoding) = 0;

    virtual CARAPI SetCharacterStream(
        /* [in] */ Elastos::IO::IReader * characterStream) = 0;

    virtual CARAPI GetCharacterStream(
        /* [out] */ Elastos::IO::IReader ** characterStream) = 0;

};
}
}
}
namespace Org {
namespace Xml {
namespace Sax {
CAR_INTERFACE("F80A470B-2552-E49B-2DD7-3F56AB7F08BF")
ILocator : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ILocator*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ILocator*)pObj->Probe(EIID_ILocator);
    }

    static CARAPI_(ILocator*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ILocator*)pObj->Probe(EIID_ILocator);
    }

    virtual CARAPI GetPublicId(
        /* [out] */ _ELASTOS String * id) = 0;

    virtual CARAPI GetSystemId(
        /* [out] */ _ELASTOS String * id) = 0;

    virtual CARAPI GetLineNumber(
        /* [out] */ _ELASTOS Int32 * lineNumber) = 0;

    virtual CARAPI GetColumnNumber(
        /* [out] */ _ELASTOS Int32 * columnNumber) = 0;

};
}
}
}
namespace Org {
namespace Xml {
namespace Sax {
CAR_INTERFACE("7C176613-4652-36D6-5AFF-58ADFE21FCFE")
IParser : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IParser*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IParser*)pObj->Probe(EIID_IParser);
    }

    static CARAPI_(IParser*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IParser*)pObj->Probe(EIID_IParser);
    }

    virtual CARAPI SetLocale(
        /* [in] */ Elastos::Utility::ILocale * locale) = 0;

    virtual CARAPI SetEntityResolver(
        /* [in] */ Org::Xml::Sax::IEntityResolver * resolver) = 0;

    virtual CARAPI SetDTDHandler(
        /* [in] */ Org::Xml::Sax::IDTDHandler * handler) = 0;

    virtual CARAPI SetDocumentHandler(
        /* [in] */ Org::Xml::Sax::IDocumentHandler * handler) = 0;

    virtual CARAPI SetErrorHandler(
        /* [in] */ Org::Xml::Sax::IErrorHandler * handler) = 0;

    virtual CARAPI Parse(
        /* [in] */ Org::Xml::Sax::IInputSource * source) = 0;

    virtual CARAPI Parse(
        /* [in] */ const _ELASTOS String& systemId) = 0;

};
}
}
}
namespace Org {
namespace Xml {
namespace Sax {
CAR_INTERFACE("3EF3C72C-FA52-3FB8-30D4-50F123048C17")
IXMLReader : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IXMLReader*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IXMLReader*)pObj->Probe(EIID_IXMLReader);
    }

    static CARAPI_(IXMLReader*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IXMLReader*)pObj->Probe(EIID_IXMLReader);
    }

    virtual CARAPI GetFeature(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ _ELASTOS Boolean * feature) = 0;

    virtual CARAPI SetFeature(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ _ELASTOS Boolean value) = 0;

    virtual CARAPI GetProperty(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ IInterface ** value) = 0;

    virtual CARAPI SetProperty(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ IInterface * value) = 0;

    virtual CARAPI SetEntityResolver(
        /* [in] */ Org::Xml::Sax::IEntityResolver * resolver) = 0;

    virtual CARAPI GetEntityResolver(
        /* [out] */ Org::Xml::Sax::IEntityResolver ** resolver) = 0;

    virtual CARAPI SetDTDHandler(
        /* [in] */ Org::Xml::Sax::IDTDHandler * handler) = 0;

    virtual CARAPI GetDTDHandler(
        /* [out] */ Org::Xml::Sax::IDTDHandler ** handler) = 0;

    virtual CARAPI SetContentHandler(
        /* [in] */ Org::Xml::Sax::IContentHandler * handler) = 0;

    virtual CARAPI GetContentHandler(
        /* [out] */ Org::Xml::Sax::IContentHandler ** handler) = 0;

    virtual CARAPI SetErrorHandler(
        /* [in] */ Org::Xml::Sax::IErrorHandler * handler) = 0;

    virtual CARAPI GetErrorHandler(
        /* [out] */ Org::Xml::Sax::IErrorHandler ** handler) = 0;

    virtual CARAPI Parse(
        /* [in] */ Org::Xml::Sax::IInputSource * input) = 0;

    virtual CARAPI Parse(
        /* [in] */ const _ELASTOS String& systemId) = 0;

};
}
}
}
namespace Org {
namespace Xml {
namespace Sax {
CAR_INTERFACE("B73A290B-6852-0F55-FBDE-68FD63B5FA87")
IXMLFilter : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IXMLFilter*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IXMLFilter*)pObj->Probe(EIID_IXMLFilter);
    }

    static CARAPI_(IXMLFilter*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IXMLFilter*)pObj->Probe(EIID_IXMLFilter);
    }

    virtual CARAPI SetParent(
        /* [in] */ Org::Xml::Sax::IXMLReader * parent) = 0;

    virtual CARAPI GetParent(
        /* [out] */ Org::Xml::Sax::IXMLReader ** parent) = 0;

};
}
}
}
namespace Org {
namespace Xml {
namespace Sax {
namespace Helpers {
CAR_INTERFACE("61CF5722-1712-F58D-7E60-A8A1E2470818")
IAttributeListImpl : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IAttributeListImpl*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAttributeListImpl*)pObj->Probe(EIID_IAttributeListImpl);
    }

    static CARAPI_(IAttributeListImpl*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAttributeListImpl*)pObj->Probe(EIID_IAttributeListImpl);
    }

    virtual CARAPI SetAttributeList(
        /* [in] */ Org::Xml::Sax::IAttributeList * atts) = 0;

    virtual CARAPI AddAttribute(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ const _ELASTOS String& type,
        /* [in] */ const _ELASTOS String& value) = 0;

    virtual CARAPI RemoveAttribute(
        /* [in] */ const _ELASTOS String& name) = 0;

    virtual CARAPI Clear() = 0;

};
}
}
}
}
namespace Org {
namespace Xml {
namespace Sax {
namespace Helpers {
CAR_INTERFACE("36B18623-1712-F51B-7E60-A8A1E2470818")
IAttributesImpl : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IAttributesImpl*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAttributesImpl*)pObj->Probe(EIID_IAttributesImpl);
    }

    static CARAPI_(IAttributesImpl*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAttributesImpl*)pObj->Probe(EIID_IAttributesImpl);
    }

    virtual CARAPI Clear() = 0;

    virtual CARAPI SetAttributes(
        /* [in] */ Org::Xml::Sax::IAttributes * atts) = 0;

    virtual CARAPI AddAttribute(
        /* [in] */ const _ELASTOS String& uri,
        /* [in] */ const _ELASTOS String& localName,
        /* [in] */ const _ELASTOS String& qName,
        /* [in] */ const _ELASTOS String& type,
        /* [in] */ const _ELASTOS String& value) = 0;

    virtual CARAPI SetAttribute(
        /* [in] */ _ELASTOS Int32 index,
        /* [in] */ const _ELASTOS String& uri,
        /* [in] */ const _ELASTOS String& localName,
        /* [in] */ const _ELASTOS String& qName,
        /* [in] */ const _ELASTOS String& type,
        /* [in] */ const _ELASTOS String& value) = 0;

    virtual CARAPI RemoveAttribute(
        /* [in] */ _ELASTOS Int32 index) = 0;

    virtual CARAPI SetURI(
        /* [in] */ _ELASTOS Int32 index,
        /* [in] */ const _ELASTOS String& uri) = 0;

    virtual CARAPI SetLocalName(
        /* [in] */ _ELASTOS Int32 index,
        /* [in] */ const _ELASTOS String& localName) = 0;

    virtual CARAPI SetQName(
        /* [in] */ _ELASTOS Int32 index,
        /* [in] */ const _ELASTOS String& qName) = 0;

    virtual CARAPI SetType(
        /* [in] */ _ELASTOS Int32 index,
        /* [in] */ const _ELASTOS String& type) = 0;

    virtual CARAPI SetValue(
        /* [in] */ _ELASTOS Int32 index,
        /* [in] */ const _ELASTOS String& value) = 0;

};
}
}
}
}
namespace Org {
namespace Xml {
namespace Sax {
namespace Helpers {
CAR_INTERFACE("78C25301-2552-E49B-2DD7-123CBF3F56AB")
ILocatorImpl : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ILocatorImpl*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ILocatorImpl*)pObj->Probe(EIID_ILocatorImpl);
    }

    static CARAPI_(ILocatorImpl*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ILocatorImpl*)pObj->Probe(EIID_ILocatorImpl);
    }

    virtual CARAPI SetPublicId(
        /* [in] */ const _ELASTOS String& publicId) = 0;

    virtual CARAPI SetSystemId(
        /* [in] */ const _ELASTOS String& systemId) = 0;

    virtual CARAPI SetLineNumber(
        /* [in] */ _ELASTOS Int32 lineNumber) = 0;

    virtual CARAPI SetColumnNumber(
        /* [in] */ _ELASTOS Int32 columnNumber) = 0;

};
}
}
}
}
namespace Org {
namespace Xml {
namespace Sax {
namespace Helpers {
CAR_INTERFACE("5E11B74E-9752-369D-C082-E2A0FBACDF1F")
INamespaceSupport : public IInterface
{
    static const _ELASTOS String XMLNS;
    static const _ELASTOS String NSDECL;
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(INamespaceSupport*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (INamespaceSupport*)pObj->Probe(EIID_INamespaceSupport);
    }

    static CARAPI_(INamespaceSupport*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (INamespaceSupport*)pObj->Probe(EIID_INamespaceSupport);
    }

    virtual CARAPI Reset() = 0;

    virtual CARAPI PushContext() = 0;

    virtual CARAPI PopContext() = 0;

    virtual CARAPI DeclarePrefix(
        /* [in] */ const _ELASTOS String& prefix,
        /* [in] */ const _ELASTOS String& uri,
        /* [out] */ _ELASTOS Boolean * isPrefixLegal) = 0;

    virtual CARAPI ProcessName(
        /* [in] */ const _ELASTOS String& qName,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS String> * parts,
        /* [in] */ _ELASTOS Boolean isAttribute,
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS String> ** name) = 0;

    virtual CARAPI GetURI(
        /* [in] */ const _ELASTOS String& prefix,
        /* [out] */ _ELASTOS String * URI) = 0;

    virtual CARAPI GetPrefixes(
        /* [out] */ Elastos::Utility::IEnumeration ** prefixes) = 0;

    virtual CARAPI GetPrefix(
        /* [in] */ const _ELASTOS String& uri,
        /* [out] */ _ELASTOS String * prefix) = 0;

    virtual CARAPI GetPrefixes(
        /* [in] */ const _ELASTOS String& uri,
        /* [out] */ Elastos::Utility::IEnumeration ** prefixes) = 0;

    virtual CARAPI GetDeclaredPrefixes(
        /* [out] */ Elastos::Utility::IEnumeration ** prefixes) = 0;

    virtual CARAPI SetNamespaceDeclUris(
        /* [in] */ _ELASTOS Boolean value) = 0;

    virtual CARAPI IsNamespaceDeclUris(
        /* [out] */ _ELASTOS Boolean * value) = 0;

};
}
}
}
}
namespace Org {
namespace Xml {
namespace Sax {
namespace Helpers {
CAR_INTERFACE("3D0A3732-0652-3512-6CDC-87F603430D15")
IParserFactory : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IParserFactory*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IParserFactory*)pObj->Probe(EIID_IParserFactory);
    }

    static CARAPI_(IParserFactory*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IParserFactory*)pObj->Probe(EIID_IParserFactory);
    }

    virtual CARAPI MakeParser(
        /* [out] */ Org::Xml::Sax::IParser ** parser) = 0;

    virtual CARAPI MakeParser(
        /* [in] */ const _ELASTOS String& className,
        /* [out] */ Org::Xml::Sax::IParser ** parser) = 0;

};
}
}
}
}
namespace Org {
namespace Xml {
namespace Sax {
namespace Helpers {
CAR_INTERFACE("C64B4437-FA52-D0B8-7E60-A8A1E2470818")
IXMLReaderFactory : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IXMLReaderFactory*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IXMLReaderFactory*)pObj->Probe(EIID_IXMLReaderFactory);
    }

    static CARAPI_(IXMLReaderFactory*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IXMLReaderFactory*)pObj->Probe(EIID_IXMLReaderFactory);
    }

    virtual CARAPI CreateXMLReader(
        /* [out] */ Org::Xml::Sax::IXMLReader ** reader) = 0;

    virtual CARAPI CreateXMLReader(
        /* [in] */ const _ELASTOS String& className,
        /* [out] */ Org::Xml::Sax::IXMLReader ** reader) = 0;

};
}
}
}
}
namespace Org {
namespace Xml {
namespace Sax {
namespace Ext {
CAR_INTERFACE("25305C23-1712-021B-7E60-A8A1E2470818")
IAttributes2 : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IAttributes2*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAttributes2*)pObj->Probe(EIID_IAttributes2);
    }

    static CARAPI_(IAttributes2*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAttributes2*)pObj->Probe(EIID_IAttributes2);
    }

    virtual CARAPI IsDeclared(
        /* [in] */ _ELASTOS Int32 index,
        /* [out] */ _ELASTOS Boolean * isDeclared) = 0;

    virtual CARAPI IsDeclared(
        /* [in] */ const _ELASTOS String& uri,
        /* [in] */ const _ELASTOS String& localName,
        /* [out] */ _ELASTOS Boolean * isDeclared) = 0;

    virtual CARAPI IsDeclared(
        /* [in] */ const _ELASTOS String& qName,
        /* [out] */ _ELASTOS Boolean * isDeclared) = 0;

    virtual CARAPI IsSpecified(
        /* [in] */ _ELASTOS Int32 index,
        /* [out] */ _ELASTOS Boolean * isSpecified) = 0;

    virtual CARAPI IsSpecified(
        /* [in] */ const _ELASTOS String& uri,
        /* [in] */ const _ELASTOS String& localName,
        /* [out] */ _ELASTOS Boolean * isSpecified) = 0;

    virtual CARAPI IsSpecified(
        /* [in] */ const _ELASTOS String& qName,
        /* [out] */ _ELASTOS Boolean * isSpecified) = 0;

};
}
}
}
}
namespace Org {
namespace Xml {
namespace Sax {
namespace Ext {
CAR_INTERFACE("33ED3837-1712-021B-EAFD-C05043C58F10")
IAttributes2Impl : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IAttributes2Impl*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAttributes2Impl*)pObj->Probe(EIID_IAttributes2Impl);
    }

    static CARAPI_(IAttributes2Impl*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IAttributes2Impl*)pObj->Probe(EIID_IAttributes2Impl);
    }

    virtual CARAPI SetDeclared(
        /* [in] */ _ELASTOS Int32 index,
        /* [in] */ _ELASTOS Boolean value) = 0;

    virtual CARAPI SetSpecified(
        /* [in] */ _ELASTOS Int32 index,
        /* [in] */ _ELASTOS Boolean value) = 0;

};
}
}
}
}
namespace Org {
namespace Xml {
namespace Sax {
namespace Ext {
CAR_INTERFACE("CF19592E-A792-3F73-30D4-50F123048C17")
IDeclHandler : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IDeclHandler*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDeclHandler*)pObj->Probe(EIID_IDeclHandler);
    }

    static CARAPI_(IDeclHandler*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IDeclHandler*)pObj->Probe(EIID_IDeclHandler);
    }

    virtual CARAPI ElementDecl(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ const _ELASTOS String& model) = 0;

    virtual CARAPI AttributeDecl(
        /* [in] */ const _ELASTOS String& eName,
        /* [in] */ const _ELASTOS String& aName,
        /* [in] */ const _ELASTOS String& type,
        /* [in] */ const _ELASTOS String& mode,
        /* [in] */ const _ELASTOS String& value) = 0;

    virtual CARAPI InternalEntityDecl(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ const _ELASTOS String& value) = 0;

    virtual CARAPI ExternalEntityDecl(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ const _ELASTOS String& publicId,
        /* [in] */ const _ELASTOS String& systemId) = 0;

};
}
}
}
}
namespace Org {
namespace Xml {
namespace Sax {
namespace Ext {
CAR_INTERFACE("43863F57-13D2-698C-1EBF-F05D43C00F0C")
IEntityResolver2 : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IEntityResolver2*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IEntityResolver2*)pObj->Probe(EIID_IEntityResolver2);
    }

    static CARAPI_(IEntityResolver2*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IEntityResolver2*)pObj->Probe(EIID_IEntityResolver2);
    }

    virtual CARAPI GetExternalSubset(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ const _ELASTOS String& baseURI,
        /* [out] */ Org::Xml::Sax::IInputSource ** src) = 0;

    virtual CARAPI ResolveEntity(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ const _ELASTOS String& publicId,
        /* [in] */ const _ELASTOS String& baseURI,
        /* [in] */ const _ELASTOS String& systemId,
        /* [out] */ Org::Xml::Sax::IInputSource ** src) = 0;

};
}
}
}
}
namespace Org {
namespace Xml {
namespace Sax {
namespace Ext {
CAR_INTERFACE("86435B24-0552-3B14-5898-20F1E2DC0F0C")
ILexicalHandler : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ILexicalHandler*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ILexicalHandler*)pObj->Probe(EIID_ILexicalHandler);
    }

    static CARAPI_(ILexicalHandler*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ILexicalHandler*)pObj->Probe(EIID_ILexicalHandler);
    }

    virtual CARAPI StartDTD(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ const _ELASTOS String& publicId,
        /* [in] */ const _ELASTOS String& systemId) = 0;

    virtual CARAPI EndDTD() = 0;

    virtual CARAPI StartEntity(
        /* [in] */ const _ELASTOS String& name) = 0;

    virtual CARAPI EndEntity(
        /* [in] */ const _ELASTOS String& name) = 0;

    virtual CARAPI StartCDATA() = 0;

    virtual CARAPI EndCDATA() = 0;

    virtual CARAPI Comment(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Char32> * ch,
        /* [in] */ _ELASTOS Int32 start,
        /* [in] */ _ELASTOS Int32 length) = 0;

};
}
}
}
}
namespace Org {
namespace Xml {
namespace Sax {
namespace Ext {
CAR_INTERFACE("09B9321F-2552-E49B-2DD7-C28FD5EA1FC2")
ILocator2 : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ILocator2*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ILocator2*)pObj->Probe(EIID_ILocator2);
    }

    static CARAPI_(ILocator2*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ILocator2*)pObj->Probe(EIID_ILocator2);
    }

    virtual CARAPI GetXMLVersion(
        /* [out] */ _ELASTOS String * xmlVersion) = 0;

    virtual CARAPI GetEncoding(
        /* [out] */ _ELASTOS String * encording) = 0;

};
}
}
}
}
namespace Org {
namespace Xml {
namespace Sax {
namespace Ext {
CAR_INTERFACE("43D3361B-2552-E49B-2DD7-8204CFEF8FD5")
ILocator2Impl : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ILocator2Impl*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ILocator2Impl*)pObj->Probe(EIID_ILocator2Impl);
    }

    static CARAPI_(ILocator2Impl*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ILocator2Impl*)pObj->Probe(EIID_ILocator2Impl);
    }

    virtual CARAPI SetXMLVersion(
        /* [in] */ const _ELASTOS String& xmlVersion) = 0;

    virtual CARAPI SetEncoding(
        /* [in] */ const _ELASTOS String& encoding) = 0;

};
}
}
}
}
namespace Org {
namespace Xml {
namespace Sax {
CAR_INTERFACE("85CFA922-8312-A67F-F518-FD81A1868A1F")
ICInputSourceClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICInputSourceClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICInputSourceClassObject*)pObj->Probe(EIID_ICInputSourceClassObject);
    }

    static CARAPI_(ICInputSourceClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICInputSourceClassObject*)pObj->Probe(EIID_ICInputSourceClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithStr(
        /* [in] */ const _ELASTOS String& str,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithInputStream(
        /* [in] */ Elastos::IO::IInputStream * inputStream,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithReader(
        /* [in] */ Elastos::IO::IReader * reader,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Org {
namespace Xml {
namespace Sax {
CAR_INTERFACE("6F266524-8312-6173-F418-FD81A1868A1F")
ICHandlerBaseClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICHandlerBaseClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICHandlerBaseClassObject*)pObj->Probe(EIID_ICHandlerBaseClassObject);
    }

    static CARAPI_(ICHandlerBaseClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICHandlerBaseClassObject*)pObj->Probe(EIID_ICHandlerBaseClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Org {
namespace Xml {
namespace Sax {
namespace Helpers {
CAR_INTERFACE("5C9E873E-0312-1A2E-EBE9-31FA03430D15")
ICAttributeListImplClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICAttributeListImplClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICAttributeListImplClassObject*)pObj->Probe(EIID_ICAttributeListImplClassObject);
    }

    static CARAPI_(ICAttributeListImplClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICAttributeListImplClassObject*)pObj->Probe(EIID_ICAttributeListImplClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithAtts(
        /* [in] */ Org::Xml::Sax::IAttributeList * atts,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
}
namespace Org {
namespace Xml {
namespace Sax {
namespace Helpers {
CAR_INTERFACE("D74D842A-0312-362E-EAE9-31FA03430D15")
ICAttributesImplClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICAttributesImplClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICAttributesImplClassObject*)pObj->Probe(EIID_ICAttributesImplClassObject);
    }

    static CARAPI_(ICAttributesImplClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICAttributesImplClassObject*)pObj->Probe(EIID_ICAttributesImplClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithAtts(
        /* [in] */ Org::Xml::Sax::IAttributes * atts,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
}
namespace Org {
namespace Xml {
namespace Sax {
namespace Helpers {
CAR_INTERFACE("10308428-8312-320A-4C90-B891BF9E1EA3")
ICLocatorImplClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICLocatorImplClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICLocatorImplClassObject*)pObj->Probe(EIID_ICLocatorImplClassObject);
    }

    static CARAPI_(ICLocatorImplClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICLocatorImplClassObject*)pObj->Probe(EIID_ICLocatorImplClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithLocator(
        /* [in] */ Org::Xml::Sax::ILocator * locator,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
}
namespace Org {
namespace Xml {
namespace Sax {
namespace Helpers {
CAR_INTERFACE("5BE27253-8312-3B2E-6D80-05C541F759BF")
ICNamespaceSupportClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICNamespaceSupportClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICNamespaceSupportClassObject*)pObj->Probe(EIID_ICNamespaceSupportClassObject);
    }

    static CARAPI_(ICNamespaceSupportClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICNamespaceSupportClassObject*)pObj->Probe(EIID_ICNamespaceSupportClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
}
namespace Org {
namespace Xml {
namespace Sax {
namespace Helpers {
CAR_INTERFACE("33516F24-8312-240C-6AD8-B80F4D8FD11F")
ICParserFactoryClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICParserFactoryClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICParserFactoryClassObject*)pObj->Probe(EIID_ICParserFactoryClassObject);
    }

    static CARAPI_(ICParserFactoryClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICParserFactoryClassObject*)pObj->Probe(EIID_ICParserFactoryClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
}
namespace Org {
namespace Xml {
namespace Sax {
namespace Helpers {
CAR_INTERFACE("A507722A-8312-71F4-A1E9-31FA03430D15")
ICXMLReaderFactoryClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICXMLReaderFactoryClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICXMLReaderFactoryClassObject*)pObj->Probe(EIID_ICXMLReaderFactoryClassObject);
    }

    static CARAPI_(ICXMLReaderFactoryClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICXMLReaderFactoryClassObject*)pObj->Probe(EIID_ICXMLReaderFactoryClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
}
namespace Org {
namespace Xml {
namespace Sax {
namespace Helpers {
CAR_INTERFACE("D570703B-8312-E751-F418-FD81A1868A1F")
ICDefaultHandlerClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICDefaultHandlerClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDefaultHandlerClassObject*)pObj->Probe(EIID_ICDefaultHandlerClassObject);
    }

    static CARAPI_(ICDefaultHandlerClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDefaultHandlerClassObject*)pObj->Probe(EIID_ICDefaultHandlerClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
}
namespace Org {
namespace Xml {
namespace Sax {
namespace Helpers {
CAR_INTERFACE("D8168B27-8312-71F4-159C-2031E3C67D3D")
ICXMLReaderAdapterClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICXMLReaderAdapterClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICXMLReaderAdapterClassObject*)pObj->Probe(EIID_ICXMLReaderAdapterClassObject);
    }

    static CARAPI_(ICXMLReaderAdapterClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICXMLReaderAdapterClassObject*)pObj->Probe(EIID_ICXMLReaderAdapterClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithXmlReader(
        /* [in] */ Org::Xml::Sax::IXMLReader * xmlReader,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
}
namespace Org {
namespace Xml {
namespace Sax {
namespace Helpers {
CAR_INTERFACE("21068539-8312-0FF4-58BC-B871BF9E1EA3")
ICXMLFilterImplClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICXMLFilterImplClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICXMLFilterImplClassObject*)pObj->Probe(EIID_ICXMLFilterImplClassObject);
    }

    static CARAPI_(ICXMLFilterImplClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICXMLFilterImplClassObject*)pObj->Probe(EIID_ICXMLFilterImplClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithParent(
        /* [in] */ Org::Xml::Sax::IXMLReader * parent,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
}
namespace Org {
namespace Xml {
namespace Sax {
namespace Helpers {
CAR_INTERFACE("BF228505-9312-B591-8DD6-CA49CE375A33")
ICParserAdapterClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICParserAdapterClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICParserAdapterClassObject*)pObj->Probe(EIID_ICParserAdapterClassObject);
    }

    static CARAPI_(ICParserAdapterClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICParserAdapterClassObject*)pObj->Probe(EIID_ICParserAdapterClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithParent(
        /* [in] */ Org::Xml::Sax::IParser * parent,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
}
namespace Org {
namespace Xml {
namespace Sax {
namespace Ext {
CAR_INTERFACE("B5FB8138-8312-320A-4C90-B8915F403D3D")
ICLocator2ImplClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICLocator2ImplClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICLocator2ImplClassObject*)pObj->Probe(EIID_ICLocator2ImplClassObject);
    }

    static CARAPI_(ICLocator2ImplClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICLocator2ImplClassObject*)pObj->Probe(EIID_ICLocator2ImplClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithLocator(
        /* [in] */ Org::Xml::Sax::ILocator * locator,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
}
namespace Org {
namespace Xml {
namespace Sax {
namespace Ext {
CAR_INTERFACE("7D198123-0312-362E-04D4-D363F407861A")
ICAttributes2ImplClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICAttributes2ImplClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICAttributes2ImplClassObject*)pObj->Probe(EIID_ICAttributes2ImplClassObject);
    }

    static CARAPI_(ICAttributes2ImplClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICAttributes2ImplClassObject*)pObj->Probe(EIID_ICAttributes2ImplClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithAtts(
        /* [in] */ Org::Xml::Sax::IAttributes * atts,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
}
namespace Org {
namespace Xml {
namespace Sax {
namespace Ext {
CAR_INTERFACE("CDE96D34-8312-E751-04E8-31FA03430D15")
ICDefaultHandler2ClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICDefaultHandler2ClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDefaultHandler2ClassObject*)pObj->Probe(EIID_ICDefaultHandler2ClassObject);
    }

    static CARAPI_(ICDefaultHandler2ClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDefaultHandler2ClassObject*)pObj->Probe(EIID_ICDefaultHandler2ClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
}
namespace Org {
namespace Xmlpull {
namespace V1 {
CAR_INTERFACE("B2F7FB0C-0852-19BF-FEBE-1959DB68FD63")
IXmlPullParser : public IInterface
{
    static const _ELASTOS String NO_NAMESPACE;
    static const _ELASTOS Int32 START_DOCUMENT = 0;
    static const _ELASTOS Int32 END_DOCUMENT = 1;
    static const _ELASTOS Int32 START_TAG = 2;
    static const _ELASTOS Int32 END_TAG = 3;
    static const _ELASTOS Int32 TEXT = 4;
    static const _ELASTOS Int32 CDSECT = 5;
    static const _ELASTOS Int32 ENTITY_REF = 6;
    static const _ELASTOS Int32 IGNORABLE_WHITESPACE = 7;
    static const _ELASTOS Int32 PROCESSING_INSTRUCTION = 8;
    static const _ELASTOS Int32 COMMENT = 9;
    static const _ELASTOS Int32 DOCDECL = 10;
    static const _ELASTOS String FEATURE_PROCESS_NAMESPACES;
    static const _ELASTOS String FEATURE_REPORT_NAMESPACE_ATTRIBUTES;
    static const _ELASTOS String FEATURE_PROCESS_DOCDECL;
    static const _ELASTOS String FEATURE_VALIDATION;
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IXmlPullParser*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IXmlPullParser*)pObj->Probe(EIID_IXmlPullParser);
    }

    static CARAPI_(IXmlPullParser*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IXmlPullParser*)pObj->Probe(EIID_IXmlPullParser);
    }

    virtual CARAPI SetFeature(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ _ELASTOS Boolean state) = 0;

    virtual CARAPI GetFeature(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI SetProperty(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ IInterface * value) = 0;

    virtual CARAPI GetProperty(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ IInterface ** value) = 0;

    virtual CARAPI SetInput(
        /* [in] */ Elastos::IO::IReader * input) = 0;

    virtual CARAPI SetInput(
        /* [in] */ Elastos::IO::IInputStream * inputStream,
        /* [in] */ const _ELASTOS String& inputEncoding) = 0;

    virtual CARAPI GetInputEncoding(
        /* [out] */ _ELASTOS String * inputEncoding) = 0;

    virtual CARAPI DefineEntityReplacementText(
        /* [in] */ const _ELASTOS String& entityName,
        /* [in] */ const _ELASTOS String& replacementText) = 0;

    virtual CARAPI GetNamespaceCount(
        /* [in] */ _ELASTOS Int32 depth,
        /* [out] */ _ELASTOS Int32 * count) = 0;

    virtual CARAPI GetNamespacePrefix(
        /* [in] */ _ELASTOS Int32 pos,
        /* [out] */ _ELASTOS String * nspPrefix) = 0;

    virtual CARAPI GetNamespaceUri(
        /* [in] */ _ELASTOS Int32 pos,
        /* [out] */ _ELASTOS String * nspUri) = 0;

    virtual CARAPI GetNamespace(
        /* [in] */ const _ELASTOS String& prefix,
        /* [out] */ _ELASTOS String * nsp) = 0;

    virtual CARAPI GetDepth(
        /* [out] */ _ELASTOS Int32 * depth) = 0;

    virtual CARAPI GetPositionDescription(
        /* [out] */ _ELASTOS String * posDesc) = 0;

    virtual CARAPI GetLineNumber(
        /* [out] */ _ELASTOS Int32 * lineNum) = 0;

    virtual CARAPI GetColumnNumber(
        /* [out] */ _ELASTOS Int32 * columnNum) = 0;

    virtual CARAPI IsWhitespace(
        /* [out] */ _ELASTOS Boolean * isWhitespace) = 0;

    virtual CARAPI GetText(
        /* [out] */ _ELASTOS String * text) = 0;

    virtual CARAPI GetTextCharacters(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Int32> * holderForStartAndLength,
        /* [out, callee] */ _ELASTOS ArrayOf<_ELASTOS Char32> ** textChar) = 0;

    virtual CARAPI GetNamespace(
        /* [out] */ _ELASTOS String * nsp) = 0;

    virtual CARAPI GetName(
        /* [out] */ _ELASTOS String * name) = 0;

    virtual CARAPI GetPrefix(
        /* [out] */ _ELASTOS String * prefix) = 0;

    virtual CARAPI IsEmptyElementTag(
        /* [out] */ _ELASTOS Boolean * isEmptyElmTag) = 0;

    virtual CARAPI GetAttributeCount(
        /* [out] */ _ELASTOS Int32 * count) = 0;

    virtual CARAPI GetAttributeNamespace(
        /* [in] */ _ELASTOS Int32 index,
        /* [out] */ _ELASTOS String * attriNsp) = 0;

    virtual CARAPI GetAttributeName(
        /* [in] */ _ELASTOS Int32 index,
        /* [out] */ _ELASTOS String * attriName) = 0;

    virtual CARAPI GetAttributePrefix(
        /* [in] */ _ELASTOS Int32 index,
        /* [out] */ _ELASTOS String * attriPrefix) = 0;

    virtual CARAPI GetAttributeType(
        /* [in] */ _ELASTOS Int32 index,
        /* [out] */ _ELASTOS String * attriType) = 0;

    virtual CARAPI IsAttributeDefault(
        /* [in] */ _ELASTOS Int32 index,
        /* [out] */ _ELASTOS Boolean * isAttriDefault) = 0;

    virtual CARAPI GetAttributeValue(
        /* [in] */ _ELASTOS Int32 index,
        /* [out] */ _ELASTOS String * attriValue) = 0;

    virtual CARAPI GetAttributeValue(
        /* [in] */ const _ELASTOS String& ns,
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ _ELASTOS String * attriValue) = 0;

    virtual CARAPI GetEventType(
        /* [out] */ _ELASTOS Int32 * eventType) = 0;

    virtual CARAPI Next(
        /* [out] */ _ELASTOS Int32 * next) = 0;

    virtual CARAPI NextToken(
        /* [out] */ _ELASTOS Int32 * nextToken) = 0;

    virtual CARAPI Require(
        /* [in] */ _ELASTOS Int32 type,
        /* [in] */ const _ELASTOS String& ns,
        /* [in] */ const _ELASTOS String& name) = 0;

    virtual CARAPI NextText(
        /* [out] */ _ELASTOS String * nextText) = 0;

    virtual CARAPI NextTag(
        /* [out] */ _ELASTOS Int32 * nextTag) = 0;

};
}
}
}
namespace Org {
namespace Xmlpull {
namespace V1 {
CAR_INTERFACE("34B58D0D-0852-19BF-FEBE-1959DB68FD90")
IXmlPullParserFactory : public IInterface
{
    static const _ELASTOS String PROPERTY_NAME;
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IXmlPullParserFactory*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IXmlPullParserFactory*)pObj->Probe(EIID_IXmlPullParserFactory);
    }

    static CARAPI_(IXmlPullParserFactory*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IXmlPullParserFactory*)pObj->Probe(EIID_IXmlPullParserFactory);
    }

    virtual CARAPI SetFeature(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ _ELASTOS Boolean state) = 0;

    virtual CARAPI GetFeature(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ _ELASTOS Boolean * isGot) = 0;

    virtual CARAPI SetNamespaceAware(
        /* [in] */ _ELASTOS Boolean awareness) = 0;

    virtual CARAPI IsNamespaceAware(
        /* [out] */ _ELASTOS Boolean * isNspAware) = 0;

    virtual CARAPI SetValidating(
        /* [in] */ _ELASTOS Boolean validating) = 0;

    virtual CARAPI IsValidating(
        /* [out] */ _ELASTOS Boolean * isValidating) = 0;

    virtual CARAPI NewPullParser(
        /* [out] */ Org::Xmlpull::V1::IXmlPullParser ** pullParser) = 0;

    virtual CARAPI NewSerializer(
        /* [out] */ Org::Xmlpull::V1::IXmlSerializer ** serial) = 0;

};
}
}
}
namespace Org {
namespace Xmlpull {
namespace V1 {
CAR_INTERFACE("6DA8410C-0852-19BF-FEBE-1959DB68FD90")
IXmlPullParserFactoryHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IXmlPullParserFactoryHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IXmlPullParserFactoryHelper*)pObj->Probe(EIID_IXmlPullParserFactoryHelper);
    }

    static CARAPI_(IXmlPullParserFactoryHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IXmlPullParserFactoryHelper*)pObj->Probe(EIID_IXmlPullParserFactoryHelper);
    }

    virtual CARAPI NewInstance(
        /* [out] */ Org::Xmlpull::V1::IXmlPullParserFactory ** xmlPullParserFac) = 0;

    virtual CARAPI NewInstance(
        /* [in] */ const _ELASTOS String& classNames,
        /* [out] */ Org::Xmlpull::V1::IXmlPullParserFactory ** xmlPullParserFac) = 0;

};
}
}
}
namespace Org {
namespace Xmlpull {
namespace V1 {
CAR_INTERFACE("316AF01A-0852-1CBF-5AB3-E4CBF668FD63")
IXmlSerializer : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IXmlSerializer*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IXmlSerializer*)pObj->Probe(EIID_IXmlSerializer);
    }

    static CARAPI_(IXmlSerializer*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IXmlSerializer*)pObj->Probe(EIID_IXmlSerializer);
    }

    virtual CARAPI SetFeature(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ _ELASTOS Boolean state) = 0;

    virtual CARAPI GetFeature(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ _ELASTOS Boolean * value) = 0;

    virtual CARAPI SetProperty(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ IInterface * value) = 0;

    virtual CARAPI GetProperty(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ IInterface ** value) = 0;

    virtual CARAPI SetOutput(
        /* [in] */ Elastos::IO::IOutputStream * os,
        /* [in] */ const _ELASTOS String& encoding) = 0;

    virtual CARAPI SetOutput(
        /* [in] */ Elastos::IO::IWriter * writer) = 0;

    virtual CARAPI StartDocument(
        /* [in] */ const _ELASTOS String& encoding,
        /* [in] */ _ELASTOS Boolean standalone) = 0;

    virtual CARAPI EndDocument() = 0;

    virtual CARAPI SetPrefix(
        /* [in] */ const _ELASTOS String& prefix,
        /* [in] */ const _ELASTOS String& ns) = 0;

    virtual CARAPI GetPrefix(
        /* [in] */ const _ELASTOS String& ns,
        /* [in] */ _ELASTOS Boolean generatePrefix,
        /* [out] */ _ELASTOS String * prefix) = 0;

    virtual CARAPI GetDepth(
        /* [out] */ _ELASTOS Int32 * depth) = 0;

    virtual CARAPI GetNamespace(
        /* [out] */ _ELASTOS String * nsp) = 0;

    virtual CARAPI GetName(
        /* [out] */ _ELASTOS String * name) = 0;

    virtual CARAPI WriteStartTag(
        /* [in] */ const _ELASTOS String& ns,
        /* [in] */ const _ELASTOS String& name) = 0;

    virtual CARAPI WriteAttribute(
        /* [in] */ const _ELASTOS String& ns,
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ const _ELASTOS String& value) = 0;

    virtual CARAPI WriteEndTag(
        /* [in] */ const _ELASTOS String& ns,
        /* [in] */ const _ELASTOS String& name) = 0;

    virtual CARAPI WriteText(
        /* [in] */ const _ELASTOS String& text) = 0;

    virtual CARAPI WriteText(
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS Char32> * buf,
        /* [in] */ _ELASTOS Int32 start,
        /* [in] */ _ELASTOS Int32 len) = 0;

    virtual CARAPI WriteCdSect(
        /* [in] */ const _ELASTOS String& text) = 0;

    virtual CARAPI WriteEntityRef(
        /* [in] */ const _ELASTOS String& text) = 0;

    virtual CARAPI WriteProcessingInstruction(
        /* [in] */ const _ELASTOS String& text) = 0;

    virtual CARAPI WriteComment(
        /* [in] */ const _ELASTOS String& text) = 0;

    virtual CARAPI WriteDocDecl(
        /* [in] */ const _ELASTOS String& text) = 0;

    virtual CARAPI WriteIgnorableWhitespace(
        /* [in] */ const _ELASTOS String& text) = 0;

    virtual CARAPI Flush() = 0;

};
}
}
}
namespace Org {
namespace Xmlpull {
namespace V1 {
CAR_INTERFACE("8F0F711F-1312-6FC2-86BF-6F46D6365A3F")
ICXmlPullParserFactoryClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICXmlPullParserFactoryClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICXmlPullParserFactoryClassObject*)pObj->Probe(EIID_ICXmlPullParserFactoryClassObject);
    }

    static CARAPI_(ICXmlPullParserFactoryClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICXmlPullParserFactoryClassObject*)pObj->Probe(EIID_ICXmlPullParserFactoryClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Org {
namespace Xmlpull {
namespace V1 {
CAR_INTERFACE("46F5771A-1312-6FC2-86BF-6F46D6365A3F")
ICXmlPullParserFactoryHelperClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICXmlPullParserFactoryHelperClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICXmlPullParserFactoryHelperClassObject*)pObj->Probe(EIID_ICXmlPullParserFactoryHelperClassObject);
    }

    static CARAPI_(ICXmlPullParserFactoryHelperClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICXmlPullParserFactoryHelperClassObject*)pObj->Probe(EIID_ICXmlPullParserFactoryHelperClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Org {
namespace Xmlpull {
namespace V1 {
namespace Sax2 {
CAR_INTERFACE("EAC47A3C-8312-3506-58E4-B8AFC7E80F0C")
ICDriverClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICDriverClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDriverClassObject*)pObj->Probe(EIID_ICDriverClassObject);
    }

    static CARAPI_(ICDriverClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICDriverClassObject*)pObj->Probe(EIID_ICDriverClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithPp(
        /* [in] */ Org::Xmlpull::V1::IXmlPullParser * pp,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
}
namespace Org {
namespace Kxml2 {
namespace IO {
CAR_INTERFACE("623C5802-1512-6FC2-46D6-365AFF58ADFE")
IKXmlParser : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IKXmlParser*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IKXmlParser*)pObj->Probe(EIID_IKXmlParser);
    }

    static CARAPI_(IKXmlParser*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IKXmlParser*)pObj->Probe(EIID_IKXmlParser);
    }

    virtual CARAPI KeepNamespaceAttributes() = 0;

    virtual CARAPI GetRootElementName(
        /* [out] */ _ELASTOS String * name) = 0;

    virtual CARAPI GetSystemId(
        /* [out] */ _ELASTOS String * id) = 0;

    virtual CARAPI GetPublicId(
        /* [out] */ _ELASTOS String * id) = 0;

};
}
}
}
namespace Org {
namespace Kxml2 {
namespace IO {
CAR_INTERFACE("B02C6514-4312-F085-9B91-B58DD6CC4BDA")
ICKXmlParserClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICKXmlParserClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICKXmlParserClassObject*)pObj->Probe(EIID_ICKXmlParserClassObject);
    }

    static CARAPI_(ICKXmlParserClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICKXmlParserClassObject*)pObj->Probe(EIID_ICKXmlParserClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Org {
namespace Kxml2 {
namespace IO {
CAR_INTERFACE("CF5E6914-4312-F085-CBA1-354BBE6C8FD6")
ICKXmlSerializerClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICKXmlSerializerClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICKXmlSerializerClassObject*)pObj->Probe(EIID_ICKXmlSerializerClassObject);
    }

    static CARAPI_(ICKXmlSerializerClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICKXmlSerializerClassObject*)pObj->Probe(EIID_ICKXmlSerializerClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
}
namespace Org {
namespace Json {
CAR_INTERFACE("7E47F60F-C4D2-9761-52D7-24FF63B5FA4F")
IJSONArray : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IJSONArray*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IJSONArray*)pObj->Probe(EIID_IJSONArray);
    }

    static CARAPI_(IJSONArray*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IJSONArray*)pObj->Probe(EIID_IJSONArray);
    }

    virtual CARAPI GetLength(
        /* [out] */ _ELASTOS Int32 * len) = 0;

    virtual CARAPI Put(
        /* [in] */ _ELASTOS Boolean value) = 0;

    virtual CARAPI Put(
        /* [in] */ _ELASTOS Double value) = 0;

    virtual CARAPI Put(
        /* [in] */ _ELASTOS Int32 value) = 0;

    virtual CARAPI Put(
        /* [in] */ _ELASTOS Int64 value) = 0;

    virtual CARAPI Put(
        /* [in] */ IInterface * value) = 0;

    virtual CARAPI Put(
        /* [in] */ _ELASTOS Int32 index,
        /* [in] */ _ELASTOS Boolean value) = 0;

    virtual CARAPI Put(
        /* [in] */ _ELASTOS Int32 index,
        /* [in] */ _ELASTOS Double value) = 0;

    virtual CARAPI Put(
        /* [in] */ _ELASTOS Int32 index,
        /* [in] */ _ELASTOS Int32 value) = 0;

    virtual CARAPI Put(
        /* [in] */ _ELASTOS Int32 index,
        /* [in] */ _ELASTOS Int64 value) = 0;

    virtual CARAPI Put(
        /* [in] */ _ELASTOS Int32 index,
        /* [in] */ IInterface * value) = 0;

    virtual CARAPI IsNull(
        /* [in] */ _ELASTOS Int32 index,
        /* [out] */ _ELASTOS Boolean * res) = 0;

    virtual CARAPI Get(
        /* [in] */ _ELASTOS Int32 index,
        /* [out] */ IInterface ** obj) = 0;

    virtual CARAPI Opt(
        /* [in] */ _ELASTOS Int32 index,
        /* [out] */ IInterface ** obj) = 0;

    virtual CARAPI Remove(
        /* [in] */ _ELASTOS Int32 index,
        /* [out] */ IInterface ** obj) = 0;

    virtual CARAPI GetBoolean(
        /* [in] */ _ELASTOS Int32 index,
        /* [out] */ _ELASTOS Boolean * res) = 0;

    virtual CARAPI OptBoolean(
        /* [in] */ _ELASTOS Int32 index,
        /* [out] */ _ELASTOS Boolean * res) = 0;

    virtual CARAPI OptBoolean(
        /* [in] */ _ELASTOS Int32 index,
        /* [in] */ _ELASTOS Boolean fallback,
        /* [out] */ _ELASTOS Boolean * res) = 0;

    virtual CARAPI GetDouble(
        /* [in] */ _ELASTOS Int32 index,
        /* [out] */ _ELASTOS Double * data) = 0;

    virtual CARAPI OptDouble(
        /* [in] */ _ELASTOS Int32 index,
        /* [out] */ _ELASTOS Double * data) = 0;

    virtual CARAPI OptDouble(
        /* [in] */ _ELASTOS Int32 index,
        /* [in] */ _ELASTOS Double fallback,
        /* [out] */ _ELASTOS Double * data) = 0;

    virtual CARAPI GetInt32(
        /* [in] */ _ELASTOS Int32 index,
        /* [out] */ _ELASTOS Int32 * data) = 0;

    virtual CARAPI OptInt32(
        /* [in] */ _ELASTOS Int32 index,
        /* [out] */ _ELASTOS Int32 * data) = 0;

    virtual CARAPI OptInt32(
        /* [in] */ _ELASTOS Int32 index,
        /* [in] */ _ELASTOS Int32 fallback,
        /* [out] */ _ELASTOS Int32 * data) = 0;

    virtual CARAPI GetInt64(
        /* [in] */ _ELASTOS Int32 index,
        /* [out] */ _ELASTOS Int64 * data) = 0;

    virtual CARAPI OptInt64(
        /* [in] */ _ELASTOS Int32 index,
        /* [out] */ _ELASTOS Int64 * data) = 0;

    virtual CARAPI OptInt64(
        /* [in] */ _ELASTOS Int32 index,
        /* [in] */ _ELASTOS Int64 fallback,
        /* [out] */ _ELASTOS Int64 * data) = 0;

    virtual CARAPI GetString(
        /* [in] */ _ELASTOS Int32 index,
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI OptString(
        /* [in] */ _ELASTOS Int32 index,
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI OptString(
        /* [in] */ _ELASTOS Int32 index,
        /* [in] */ const _ELASTOS String& fallback,
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI GetJSONArray(
        /* [in] */ _ELASTOS Int32 index,
        /* [out] */ Org::Json::IJSONArray ** jsonArray) = 0;

    virtual CARAPI OptJSONArray(
        /* [in] */ _ELASTOS Int32 index,
        /* [out] */ Org::Json::IJSONArray ** jsonArray) = 0;

    virtual CARAPI GetJSONObject(
        /* [in] */ _ELASTOS Int32 index,
        /* [out] */ Org::Json::IJSONObject ** jsonObject) = 0;

    virtual CARAPI OptJSONObject(
        /* [in] */ _ELASTOS Int32 index,
        /* [out] */ Org::Json::IJSONObject ** jsonObject) = 0;

    virtual CARAPI ToJSONObject(
        /* [in] */ Org::Json::IJSONArray * names,
        /* [out] */ Org::Json::IJSONObject ** jsonObject) = 0;

    virtual CARAPI Join(
        /* [in] */ const _ELASTOS String& separator,
        /* [out] */ _ELASTOS String * res) = 0;

    virtual CARAPI ToString(
        /* [in] */ _ELASTOS Int32 indentSpaces,
        /* [out] */ _ELASTOS String * str) = 0;

};
}
}
namespace Org {
namespace Json {
CAR_INTERFACE("F562F415-C4D2-1761-56B6-A879FF58ADFE")
IJSONObject : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IJSONObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IJSONObject*)pObj->Probe(EIID_IJSONObject);
    }

    static CARAPI_(IJSONObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IJSONObject*)pObj->Probe(EIID_IJSONObject);
    }

    virtual CARAPI GetLength(
        /* [out] */ _ELASTOS Int32 * len) = 0;

    virtual CARAPI Put(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ _ELASTOS Boolean value) = 0;

    virtual CARAPI Put(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ _ELASTOS Double value) = 0;

    virtual CARAPI Put(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ _ELASTOS Int32 value) = 0;

    virtual CARAPI Put(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ _ELASTOS Int64 value) = 0;

    virtual CARAPI Put(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ IInterface * value) = 0;

    virtual CARAPI PutOpt(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ IInterface * value) = 0;

    virtual CARAPI Accumulate(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ IInterface * value) = 0;

    virtual CARAPI Append(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ IInterface * value) = 0;

    virtual CARAPI Remove(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ IInterface ** value) = 0;

    virtual CARAPI IsNull(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ _ELASTOS Boolean * res) = 0;

    virtual CARAPI Has(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ _ELASTOS Boolean * res) = 0;

    virtual CARAPI Get(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ IInterface ** obj) = 0;

    virtual CARAPI Opt(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ IInterface ** obj) = 0;

    virtual CARAPI GetBoolean(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ _ELASTOS Boolean * res) = 0;

    virtual CARAPI OptBoolean(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ _ELASTOS Boolean * res) = 0;

    virtual CARAPI OptBoolean(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ _ELASTOS Boolean fallback,
        /* [out] */ _ELASTOS Boolean * res) = 0;

    virtual CARAPI GetDouble(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ _ELASTOS Double * data) = 0;

    virtual CARAPI OptDouble(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ _ELASTOS Double * data) = 0;

    virtual CARAPI OptDouble(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ _ELASTOS Double fallback,
        /* [out] */ _ELASTOS Double * data) = 0;

    virtual CARAPI GetInt32(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ _ELASTOS Int32 * data) = 0;

    virtual CARAPI OptInt32(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ _ELASTOS Int32 * data) = 0;

    virtual CARAPI OptInt32(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ _ELASTOS Int32 fallback,
        /* [out] */ _ELASTOS Int32 * data) = 0;

    virtual CARAPI GetInt64(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ _ELASTOS Int64 * data) = 0;

    virtual CARAPI OptInt64(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ _ELASTOS Int64 * data) = 0;

    virtual CARAPI OptInt64(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ _ELASTOS Int64 fallback,
        /* [out] */ _ELASTOS Int64 * data) = 0;

    virtual CARAPI GetString(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI OptString(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI OptString(
        /* [in] */ const _ELASTOS String& name,
        /* [in] */ const _ELASTOS String& fallback,
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI GetJSONArray(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ Org::Json::IJSONArray ** jsonArray) = 0;

    virtual CARAPI OptJSONArray(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ Org::Json::IJSONArray ** jsonArray) = 0;

    virtual CARAPI GetJSONObject(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ Org::Json::IJSONObject ** jsonObject) = 0;

    virtual CARAPI OptJSONObject(
        /* [in] */ const _ELASTOS String& name,
        /* [out] */ Org::Json::IJSONObject ** jsonObject) = 0;

    virtual CARAPI ToJSONArray(
        /* [in] */ Org::Json::IJSONArray * names,
        /* [out] */ Org::Json::IJSONArray ** jsonArray) = 0;

    virtual CARAPI GetKeys(
        /* [out] */ Elastos::Utility::IIterator ** iterator) = 0;

    virtual CARAPI GetKeySet(
        /* [out] */ Elastos::Utility::ISet ** set) = 0;

    virtual CARAPI GetNames(
        /* [out] */ Org::Json::IJSONArray ** jsonArray) = 0;

    virtual CARAPI ToString(
        /* [in] */ _ELASTOS Int32 indentSpaces,
        /* [out] */ _ELASTOS String * str) = 0;

};
}
}
namespace Org {
namespace Json {
CAR_INTERFACE("7E3E3939-04D2-180E-2E18-8D80E2C58CFB")
IJSONObjectHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IJSONObjectHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IJSONObjectHelper*)pObj->Probe(EIID_IJSONObjectHelper);
    }

    static CARAPI_(IJSONObjectHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IJSONObjectHelper*)pObj->Probe(EIID_IJSONObjectHelper);
    }

    virtual CARAPI NumberToString(
        /* [in] */ Elastos::Core::INumber * number,
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI Quote(
        /* [in] */ const _ELASTOS String& data,
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI Wrap(
        /* [in] */ IInterface * o,
        /* [out] */ IInterface ** obj) = 0;

    virtual CARAPI GetNULL(
        /* [out] */ IInterface ** obj) = 0;

};
}
}
namespace Org {
namespace Json {
CAR_INTERFACE("E1605334-04D2-180E-2EC0-BEFF03430D15")
IJSONStringer : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IJSONStringer*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IJSONStringer*)pObj->Probe(EIID_IJSONStringer);
    }

    static CARAPI_(IJSONStringer*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IJSONStringer*)pObj->Probe(EIID_IJSONStringer);
    }

    virtual CARAPI Array() = 0;

    virtual CARAPI EndArray() = 0;

    virtual CARAPI Object() = 0;

    virtual CARAPI EndObject() = 0;

    virtual CARAPI Open(
        /* [in] */ Org::Json::JSONStringerScope empty,
        /* [in] */ const _ELASTOS String& openBracket) = 0;

    virtual CARAPI Close(
        /* [in] */ Org::Json::JSONStringerScope empty,
        /* [in] */ Org::Json::JSONStringerScope nonempty,
        /* [in] */ const _ELASTOS String& closeBracket) = 0;

    virtual CARAPI Value(
        /* [in] */ IInterface * value) = 0;

    virtual CARAPI Value(
        /* [in] */ _ELASTOS Boolean value) = 0;

    virtual CARAPI Value(
        /* [in] */ _ELASTOS Double value) = 0;

    virtual CARAPI Value(
        /* [in] */ _ELASTOS Int64 value) = 0;

    virtual CARAPI Key(
        /* [in] */ const _ELASTOS String& name) = 0;

};
}
}
namespace Org {
namespace Json {
CAR_INTERFACE("5CDD6B0A-C4D2-5761-27BB-688CD63F56AB")
IJSONTokener : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IJSONTokener*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IJSONTokener*)pObj->Probe(EIID_IJSONTokener);
    }

    static CARAPI_(IJSONTokener*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IJSONTokener*)pObj->Probe(EIID_IJSONTokener);
    }

    virtual CARAPI NextValue(
        /* [out] */ IInterface ** obj) = 0;

    virtual CARAPI NextString(
        /* [in] */ _ELASTOS Char32 quote,
        /* [out] */ _ELASTOS String * result) = 0;

    virtual CARAPI SyntaxError(
        /* [in] */ const _ELASTOS String& message) = 0;

    virtual CARAPI More(
        /* [out] */ _ELASTOS Boolean * result) = 0;

    virtual CARAPI Next(
        /* [out] */ _ELASTOS Char32 * ca) = 0;

    virtual CARAPI Next(
        /* [in] */ _ELASTOS Char32 c,
        /* [out] */ _ELASTOS Char32 * ca) = 0;

    virtual CARAPI NextClean(
        /* [out] */ _ELASTOS Char32 * ca) = 0;

    virtual CARAPI Next(
        /* [in] */ _ELASTOS Int32 length,
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI NextTo(
        /* [in] */ const _ELASTOS String& excluded,
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI NextTo(
        /* [in] */ _ELASTOS Char32 excluded,
        /* [out] */ _ELASTOS String * str) = 0;

    virtual CARAPI SkipPast(
        /* [in] */ const _ELASTOS String& thru) = 0;

    virtual CARAPI SkipTo(
        /* [in] */ _ELASTOS Char32 to,
        /* [out] */ _ELASTOS Char32 * ca) = 0;

    virtual CARAPI Back() = 0;

};
}
}
namespace Org {
namespace Json {
CAR_INTERFACE("DC802512-C4D2-5761-27BB-688CD611FACE")
IJSONTokenerHelper : public IInterface
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(IJSONTokenerHelper*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (IJSONTokenerHelper*)pObj->Probe(EIID_IJSONTokenerHelper);
    }

    static CARAPI_(IJSONTokenerHelper*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (IJSONTokenerHelper*)pObj->Probe(EIID_IJSONTokenerHelper);
    }

    virtual CARAPI Dehexchar(
        /* [in] */ _ELASTOS Char32 hex,
        /* [out] */ _ELASTOS Int32 * result) = 0;

};
}
}
namespace Org {
namespace Json {
CAR_INTERFACE("026FB92C-8312-1C09-305C-C0A2C7E80F0C")
ICJSONArrayClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICJSONArrayClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICJSONArrayClassObject*)pObj->Probe(EIID_ICJSONArrayClassObject);
    }

    static CARAPI_(ICJSONArrayClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICJSONArrayClassObject*)pObj->Probe(EIID_ICJSONArrayClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithCopyFrom(
        /* [in] */ Elastos::Utility::ICollection * copyFrom,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithReadFrom(
        /* [in] */ Org::Json::IJSONTokener * readFrom,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithJson(
        /* [in] */ const _ELASTOS String& json,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithArray(
        /* [in] */ IInterface * array,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Org {
namespace Json {
CAR_INTERFACE("2EC3C23C-8312-1C09-305C-30AAC7E80F0C")
ICJSONObjectClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICJSONObjectClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICJSONObjectClassObject*)pObj->Probe(EIID_ICJSONObjectClassObject);
    }

    static CARAPI_(ICJSONObjectClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICJSONObjectClassObject*)pObj->Probe(EIID_ICJSONObjectClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithCopyFrom(
        /* [in] */ Elastos::Utility::IMap * copyFrom,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithReadFrom(
        /* [in] */ Org::Json::IJSONTokener * readFrom,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithJson(
        /* [in] */ const _ELASTOS String& json,
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithCopyFromNames(
        /* [in] */ Org::Json::IJSONObject * copyFrom,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS String> * names,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Org {
namespace Json {
CAR_INTERFACE("16B7675D-8312-1C09-305C-F81201C58BB0")
ICJSONObjectHelperClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICJSONObjectHelperClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICJSONObjectHelperClassObject*)pObj->Probe(EIID_ICJSONObjectHelperClassObject);
    }

    static CARAPI_(ICJSONObjectHelperClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICJSONObjectHelperClassObject*)pObj->Probe(EIID_ICJSONObjectHelperClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Org {
namespace Json {
CAR_INTERFACE("0D187F39-8312-1C09-305C-807D5F8FD11F")
ICJSONStringerClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICJSONStringerClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICJSONStringerClassObject*)pObj->Probe(EIID_ICJSONStringerClassObject);
    }

    static CARAPI_(ICJSONStringerClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICJSONStringerClassObject*)pObj->Probe(EIID_ICJSONStringerClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

    virtual CARAPI CreateObjectWithIndentSpaces(
        /* [in] */ _ELASTOS Int32 indentSpaces,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Org {
namespace Json {
CAR_INTERFACE("B0255A08-3312-D871-D5C9-2E1AA335F392")
ICJSONTokenerClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICJSONTokenerClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICJSONTokenerClassObject*)pObj->Probe(EIID_ICJSONTokenerClassObject);
    }

    static CARAPI_(ICJSONTokenerClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICJSONTokenerClassObject*)pObj->Probe(EIID_ICJSONTokenerClassObject);
    }

    virtual CARAPI CreateObjectWithStr(
        /* [in] */ const _ELASTOS String& str,
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Org {
namespace Json {
CAR_INTERFACE("24286818-3312-D871-D5C9-2E1AA37584BE")
ICJSONTokenerHelperClassObject : public IClassObject
{
    virtual CARAPI_(PInterface) Probe(
        /* [in] */ _ELASTOS REIID riid) = 0;

    static CARAPI_(ICJSONTokenerHelperClassObject*) Probe(PInterface pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICJSONTokenerHelperClassObject*)pObj->Probe(EIID_ICJSONTokenerHelperClassObject);
    }

    static CARAPI_(ICJSONTokenerHelperClassObject*) Probe(IObject* pObj)
    {
        if (pObj == NULL) return NULL;
        return (ICJSONTokenerHelperClassObject*)pObj->Probe(EIID_ICJSONTokenerHelperClassObject);
    }

    virtual CARAPI CreateObjectWithDefaultCtor(
        /* [out] */ IInterface ** newObj) = 0;

};
}
}
namespace Org {
namespace W3c {
namespace Dom {
class CText
{
public:
    static _ELASTOS ECode New(
        /* [out] */ Org::W3c::Dom::IText** __object)
    {
        return _CObject_CreateInstance(ECLSID_CText, RGM_SAME_DOMAIN, Org::W3c::Dom::EIID_IText, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CText, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CText, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CText, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
}
namespace Org {
namespace Xml {
namespace Sax {
class CInputSource
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& str,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICInputSourceClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CInputSource, RGM_SAME_DOMAIN,
                EIID_ICInputSourceClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithStr(str, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IInputStream * inputStream,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICInputSourceClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CInputSource, RGM_SAME_DOMAIN,
                EIID_ICInputSourceClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithInputStream(inputStream, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Elastos::IO::IReader * reader,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICInputSourceClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CInputSource, RGM_SAME_DOMAIN,
                EIID_ICInputSourceClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithReader(reader, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [out] */ Org::Xml::Sax::IInputSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CInputSource, RGM_SAME_DOMAIN, Org::Xml::Sax::EIID_IInputSource, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CInputSource, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CInputSource, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CInputSource, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& str,
        /* [out] */ Org::Xml::Sax::IInputSource** __IInputSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(str, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IInputSource = (Org::Xml::Sax::IInputSource*)__pNewObj->Probe(Org::Xml::Sax::EIID_IInputSource);
        if (*__IInputSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& str,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(str, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& str,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(str, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& str,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(str, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * inputStream,
        /* [out] */ Org::Xml::Sax::IInputSource** __IInputSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(inputStream, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IInputSource = (Org::Xml::Sax::IInputSource*)__pNewObj->Probe(Org::Xml::Sax::EIID_IInputSource);
        if (*__IInputSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * inputStream,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(inputStream, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * inputStream,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(inputStream, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IInputStream * inputStream,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(inputStream, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IReader * reader,
        /* [out] */ Org::Xml::Sax::IInputSource** __IInputSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(reader, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IInputSource = (Org::Xml::Sax::IInputSource*)__pNewObj->Probe(Org::Xml::Sax::EIID_IInputSource);
        if (*__IInputSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IReader * reader,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(reader, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IReader * reader,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(reader, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::IO::IReader * reader,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(reader, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

};
}
}
}
namespace Org {
namespace Xml {
namespace Sax {
class CHandlerBase
{
public:
    static _ELASTOS ECode New(
        /* [out] */ Org::Xml::Sax::IEntityResolver** __object)
    {
        return _CObject_CreateInstance(ECLSID_CHandlerBase, RGM_SAME_DOMAIN, Org::Xml::Sax::EIID_IEntityResolver, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Org::Xml::Sax::IDTDHandler** __object)
    {
        return _CObject_CreateInstance(ECLSID_CHandlerBase, RGM_SAME_DOMAIN, Org::Xml::Sax::EIID_IDTDHandler, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Org::Xml::Sax::IDocumentHandler** __object)
    {
        return _CObject_CreateInstance(ECLSID_CHandlerBase, RGM_SAME_DOMAIN, Org::Xml::Sax::EIID_IDocumentHandler, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Org::Xml::Sax::IErrorHandler** __object)
    {
        return _CObject_CreateInstance(ECLSID_CHandlerBase, RGM_SAME_DOMAIN, Org::Xml::Sax::EIID_IErrorHandler, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CHandlerBase, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CHandlerBase, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CHandlerBase, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
}
namespace Org {
namespace Xml {
namespace Sax {
namespace Helpers {
class CAttributeListImpl
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Org::Xml::Sax::IAttributeList * atts,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICAttributeListImplClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CAttributeListImpl, RGM_SAME_DOMAIN,
                EIID_ICAttributeListImplClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithAtts(atts, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [out] */ Org::Xml::Sax::IAttributeList** __object)
    {
        return _CObject_CreateInstance(ECLSID_CAttributeListImpl, RGM_SAME_DOMAIN, Org::Xml::Sax::EIID_IAttributeList, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Org::Xml::Sax::Helpers::IAttributeListImpl** __object)
    {
        return _CObject_CreateInstance(ECLSID_CAttributeListImpl, RGM_SAME_DOMAIN, Org::Xml::Sax::Helpers::EIID_IAttributeListImpl, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CAttributeListImpl, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CAttributeListImpl, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CAttributeListImpl, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::Xml::Sax::IAttributeList * atts,
        /* [out] */ Org::Xml::Sax::IAttributeList** __IAttributeList)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(atts, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IAttributeList = (Org::Xml::Sax::IAttributeList*)__pNewObj->Probe(Org::Xml::Sax::EIID_IAttributeList);
        if (*__IAttributeList) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::Xml::Sax::IAttributeList * atts,
        /* [out] */ Org::Xml::Sax::Helpers::IAttributeListImpl** __IAttributeListImpl)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(atts, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IAttributeListImpl = (Org::Xml::Sax::Helpers::IAttributeListImpl*)__pNewObj->Probe(Org::Xml::Sax::Helpers::EIID_IAttributeListImpl);
        if (*__IAttributeListImpl) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::Xml::Sax::IAttributeList * atts,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(atts, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::Xml::Sax::IAttributeList * atts,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(atts, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::Xml::Sax::IAttributeList * atts,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(atts, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

};
}
}
}
}
namespace Org {
namespace Xml {
namespace Sax {
namespace Helpers {
class CAttributesImpl
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Org::Xml::Sax::IAttributes * atts,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICAttributesImplClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CAttributesImpl, RGM_SAME_DOMAIN,
                EIID_ICAttributesImplClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithAtts(atts, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [out] */ Org::Xml::Sax::IAttributes** __object)
    {
        return _CObject_CreateInstance(ECLSID_CAttributesImpl, RGM_SAME_DOMAIN, Org::Xml::Sax::EIID_IAttributes, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Org::Xml::Sax::Helpers::IAttributesImpl** __object)
    {
        return _CObject_CreateInstance(ECLSID_CAttributesImpl, RGM_SAME_DOMAIN, Org::Xml::Sax::Helpers::EIID_IAttributesImpl, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CAttributesImpl, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CAttributesImpl, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CAttributesImpl, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::Xml::Sax::IAttributes * atts,
        /* [out] */ Org::Xml::Sax::IAttributes** __IAttributes)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(atts, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IAttributes = (Org::Xml::Sax::IAttributes*)__pNewObj->Probe(Org::Xml::Sax::EIID_IAttributes);
        if (*__IAttributes) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::Xml::Sax::IAttributes * atts,
        /* [out] */ Org::Xml::Sax::Helpers::IAttributesImpl** __IAttributesImpl)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(atts, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IAttributesImpl = (Org::Xml::Sax::Helpers::IAttributesImpl*)__pNewObj->Probe(Org::Xml::Sax::Helpers::EIID_IAttributesImpl);
        if (*__IAttributesImpl) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::Xml::Sax::IAttributes * atts,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(atts, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::Xml::Sax::IAttributes * atts,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(atts, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::Xml::Sax::IAttributes * atts,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(atts, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

};
}
}
}
}
namespace Org {
namespace Xml {
namespace Sax {
namespace Helpers {
class CLocatorImpl
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Org::Xml::Sax::ILocator * locator,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICLocatorImplClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CLocatorImpl, RGM_SAME_DOMAIN,
                EIID_ICLocatorImplClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithLocator(locator, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [out] */ Org::Xml::Sax::ILocator** __object)
    {
        return _CObject_CreateInstance(ECLSID_CLocatorImpl, RGM_SAME_DOMAIN, Org::Xml::Sax::EIID_ILocator, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Org::Xml::Sax::Helpers::ILocatorImpl** __object)
    {
        return _CObject_CreateInstance(ECLSID_CLocatorImpl, RGM_SAME_DOMAIN, Org::Xml::Sax::Helpers::EIID_ILocatorImpl, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CLocatorImpl, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CLocatorImpl, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CLocatorImpl, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::Xml::Sax::ILocator * locator,
        /* [out] */ Org::Xml::Sax::ILocator** __ILocator)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(locator, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ILocator = (Org::Xml::Sax::ILocator*)__pNewObj->Probe(Org::Xml::Sax::EIID_ILocator);
        if (*__ILocator) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::Xml::Sax::ILocator * locator,
        /* [out] */ Org::Xml::Sax::Helpers::ILocatorImpl** __ILocatorImpl)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(locator, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ILocatorImpl = (Org::Xml::Sax::Helpers::ILocatorImpl*)__pNewObj->Probe(Org::Xml::Sax::Helpers::EIID_ILocatorImpl);
        if (*__ILocatorImpl) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::Xml::Sax::ILocator * locator,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(locator, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::Xml::Sax::ILocator * locator,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(locator, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::Xml::Sax::ILocator * locator,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(locator, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

};
}
}
}
}
namespace Org {
namespace Xml {
namespace Sax {
namespace Helpers {
class CNamespaceSupport
{
public:
    static _ELASTOS ECode New(
        /* [out] */ Org::Xml::Sax::Helpers::INamespaceSupport** __object)
    {
        return _CObject_CreateInstance(ECLSID_CNamespaceSupport, RGM_SAME_DOMAIN, Org::Xml::Sax::Helpers::EIID_INamespaceSupport, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CNamespaceSupport, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CNamespaceSupport, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CNamespaceSupport, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
}
}
namespace Org {
namespace Xml {
namespace Sax {
namespace Helpers {
class CParserFactory
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Org::Xml::Sax::Helpers::IParserFactory** __object)
    {
        return _CObject_CreateInstance(ECLSID_CParserFactory, RGM_SAME_DOMAIN, Org::Xml::Sax::Helpers::EIID_IParserFactory, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CParserFactory, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CParserFactory, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CParserFactory, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
}
}
namespace Org {
namespace Xml {
namespace Sax {
namespace Helpers {
class CXMLReaderFactory
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Org::Xml::Sax::Helpers::IXMLReaderFactory** __object)
    {
        return _CObject_CreateInstance(ECLSID_CXMLReaderFactory, RGM_SAME_DOMAIN, Org::Xml::Sax::Helpers::EIID_IXMLReaderFactory, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CXMLReaderFactory, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CXMLReaderFactory, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CXMLReaderFactory, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
}
}
namespace Org {
namespace Xml {
namespace Sax {
namespace Helpers {
class CDefaultHandler
{
public:
    static _ELASTOS ECode New(
        /* [out] */ Org::Xml::Sax::IEntityResolver** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDefaultHandler, RGM_SAME_DOMAIN, Org::Xml::Sax::EIID_IEntityResolver, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Org::Xml::Sax::IDTDHandler** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDefaultHandler, RGM_SAME_DOMAIN, Org::Xml::Sax::EIID_IDTDHandler, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Org::Xml::Sax::IContentHandler** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDefaultHandler, RGM_SAME_DOMAIN, Org::Xml::Sax::EIID_IContentHandler, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Org::Xml::Sax::IErrorHandler** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDefaultHandler, RGM_SAME_DOMAIN, Org::Xml::Sax::EIID_IErrorHandler, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDefaultHandler, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDefaultHandler, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDefaultHandler, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
}
}
namespace Org {
namespace Xml {
namespace Sax {
namespace Helpers {
class CXMLReaderAdapter
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Org::Xml::Sax::IXMLReader * xmlReader,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICXMLReaderAdapterClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CXMLReaderAdapter, RGM_SAME_DOMAIN,
                EIID_ICXMLReaderAdapterClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithXmlReader(xmlReader, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [out] */ Org::Xml::Sax::IParser** __object)
    {
        return _CObject_CreateInstance(ECLSID_CXMLReaderAdapter, RGM_SAME_DOMAIN, Org::Xml::Sax::EIID_IParser, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Org::Xml::Sax::IContentHandler** __object)
    {
        return _CObject_CreateInstance(ECLSID_CXMLReaderAdapter, RGM_SAME_DOMAIN, Org::Xml::Sax::EIID_IContentHandler, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CXMLReaderAdapter, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CXMLReaderAdapter, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CXMLReaderAdapter, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::Xml::Sax::IXMLReader * xmlReader,
        /* [out] */ Org::Xml::Sax::IParser** __IParser)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(xmlReader, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IParser = (Org::Xml::Sax::IParser*)__pNewObj->Probe(Org::Xml::Sax::EIID_IParser);
        if (*__IParser) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::Xml::Sax::IXMLReader * xmlReader,
        /* [out] */ Org::Xml::Sax::IContentHandler** __IContentHandler)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(xmlReader, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IContentHandler = (Org::Xml::Sax::IContentHandler*)__pNewObj->Probe(Org::Xml::Sax::EIID_IContentHandler);
        if (*__IContentHandler) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::Xml::Sax::IXMLReader * xmlReader,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(xmlReader, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::Xml::Sax::IXMLReader * xmlReader,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(xmlReader, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::Xml::Sax::IXMLReader * xmlReader,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(xmlReader, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

};
}
}
}
}
namespace Org {
namespace Xml {
namespace Sax {
namespace Helpers {
class CXMLFilterImpl
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Org::Xml::Sax::IXMLReader * parent,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICXMLFilterImplClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CXMLFilterImpl, RGM_SAME_DOMAIN,
                EIID_ICXMLFilterImplClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithParent(parent, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [out] */ Org::Xml::Sax::IXMLReader** __object)
    {
        return _CObject_CreateInstance(ECLSID_CXMLFilterImpl, RGM_SAME_DOMAIN, Org::Xml::Sax::EIID_IXMLReader, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Org::Xml::Sax::IXMLFilter** __object)
    {
        return _CObject_CreateInstance(ECLSID_CXMLFilterImpl, RGM_SAME_DOMAIN, Org::Xml::Sax::EIID_IXMLFilter, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Org::Xml::Sax::IEntityResolver** __object)
    {
        return _CObject_CreateInstance(ECLSID_CXMLFilterImpl, RGM_SAME_DOMAIN, Org::Xml::Sax::EIID_IEntityResolver, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Org::Xml::Sax::IDTDHandler** __object)
    {
        return _CObject_CreateInstance(ECLSID_CXMLFilterImpl, RGM_SAME_DOMAIN, Org::Xml::Sax::EIID_IDTDHandler, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Org::Xml::Sax::IContentHandler** __object)
    {
        return _CObject_CreateInstance(ECLSID_CXMLFilterImpl, RGM_SAME_DOMAIN, Org::Xml::Sax::EIID_IContentHandler, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Org::Xml::Sax::IErrorHandler** __object)
    {
        return _CObject_CreateInstance(ECLSID_CXMLFilterImpl, RGM_SAME_DOMAIN, Org::Xml::Sax::EIID_IErrorHandler, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CXMLFilterImpl, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CXMLFilterImpl, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CXMLFilterImpl, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::Xml::Sax::IXMLReader * parent,
        /* [out] */ Org::Xml::Sax::IXMLReader** __IXMLReader)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(parent, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IXMLReader = (Org::Xml::Sax::IXMLReader*)__pNewObj->Probe(Org::Xml::Sax::EIID_IXMLReader);
        if (*__IXMLReader) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::Xml::Sax::IXMLReader * parent,
        /* [out] */ Org::Xml::Sax::IXMLFilter** __IXMLFilter)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(parent, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IXMLFilter = (Org::Xml::Sax::IXMLFilter*)__pNewObj->Probe(Org::Xml::Sax::EIID_IXMLFilter);
        if (*__IXMLFilter) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::Xml::Sax::IXMLReader * parent,
        /* [out] */ Org::Xml::Sax::IEntityResolver** __IEntityResolver)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(parent, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IEntityResolver = (Org::Xml::Sax::IEntityResolver*)__pNewObj->Probe(Org::Xml::Sax::EIID_IEntityResolver);
        if (*__IEntityResolver) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::Xml::Sax::IXMLReader * parent,
        /* [out] */ Org::Xml::Sax::IDTDHandler** __IDTDHandler)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(parent, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IDTDHandler = (Org::Xml::Sax::IDTDHandler*)__pNewObj->Probe(Org::Xml::Sax::EIID_IDTDHandler);
        if (*__IDTDHandler) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::Xml::Sax::IXMLReader * parent,
        /* [out] */ Org::Xml::Sax::IContentHandler** __IContentHandler)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(parent, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IContentHandler = (Org::Xml::Sax::IContentHandler*)__pNewObj->Probe(Org::Xml::Sax::EIID_IContentHandler);
        if (*__IContentHandler) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::Xml::Sax::IXMLReader * parent,
        /* [out] */ Org::Xml::Sax::IErrorHandler** __IErrorHandler)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(parent, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IErrorHandler = (Org::Xml::Sax::IErrorHandler*)__pNewObj->Probe(Org::Xml::Sax::EIID_IErrorHandler);
        if (*__IErrorHandler) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::Xml::Sax::IXMLReader * parent,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(parent, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::Xml::Sax::IXMLReader * parent,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(parent, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::Xml::Sax::IXMLReader * parent,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(parent, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

};
}
}
}
}
namespace Org {
namespace Xml {
namespace Sax {
namespace Helpers {
class CParserAdapter
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Org::Xml::Sax::IParser * parent,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICParserAdapterClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CParserAdapter, RGM_SAME_DOMAIN,
                EIID_ICParserAdapterClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithParent(parent, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [out] */ Org::Xml::Sax::IXMLReader** __object)
    {
        return _CObject_CreateInstance(ECLSID_CParserAdapter, RGM_SAME_DOMAIN, Org::Xml::Sax::EIID_IXMLReader, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Org::Xml::Sax::IDocumentHandler** __object)
    {
        return _CObject_CreateInstance(ECLSID_CParserAdapter, RGM_SAME_DOMAIN, Org::Xml::Sax::EIID_IDocumentHandler, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CParserAdapter, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CParserAdapter, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CParserAdapter, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::Xml::Sax::IParser * parent,
        /* [out] */ Org::Xml::Sax::IXMLReader** __IXMLReader)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(parent, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IXMLReader = (Org::Xml::Sax::IXMLReader*)__pNewObj->Probe(Org::Xml::Sax::EIID_IXMLReader);
        if (*__IXMLReader) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::Xml::Sax::IParser * parent,
        /* [out] */ Org::Xml::Sax::IDocumentHandler** __IDocumentHandler)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(parent, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IDocumentHandler = (Org::Xml::Sax::IDocumentHandler*)__pNewObj->Probe(Org::Xml::Sax::EIID_IDocumentHandler);
        if (*__IDocumentHandler) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::Xml::Sax::IParser * parent,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(parent, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::Xml::Sax::IParser * parent,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(parent, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::Xml::Sax::IParser * parent,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(parent, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

};
}
}
}
}
namespace Org {
namespace Xml {
namespace Sax {
namespace Ext {
class CLocator2Impl
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Org::Xml::Sax::ILocator * locator,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICLocator2ImplClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CLocator2Impl, RGM_SAME_DOMAIN,
                EIID_ICLocator2ImplClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithLocator(locator, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [out] */ Org::Xml::Sax::ILocator** __object)
    {
        return _CObject_CreateInstance(ECLSID_CLocator2Impl, RGM_SAME_DOMAIN, Org::Xml::Sax::EIID_ILocator, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Org::Xml::Sax::Ext::ILocator2** __object)
    {
        return _CObject_CreateInstance(ECLSID_CLocator2Impl, RGM_SAME_DOMAIN, Org::Xml::Sax::Ext::EIID_ILocator2, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Org::Xml::Sax::Ext::ILocator2Impl** __object)
    {
        return _CObject_CreateInstance(ECLSID_CLocator2Impl, RGM_SAME_DOMAIN, Org::Xml::Sax::Ext::EIID_ILocator2Impl, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CLocator2Impl, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CLocator2Impl, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CLocator2Impl, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::Xml::Sax::ILocator * locator,
        /* [out] */ Org::Xml::Sax::ILocator** __ILocator)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(locator, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ILocator = (Org::Xml::Sax::ILocator*)__pNewObj->Probe(Org::Xml::Sax::EIID_ILocator);
        if (*__ILocator) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::Xml::Sax::ILocator * locator,
        /* [out] */ Org::Xml::Sax::Ext::ILocator2** __ILocator2)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(locator, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ILocator2 = (Org::Xml::Sax::Ext::ILocator2*)__pNewObj->Probe(Org::Xml::Sax::Ext::EIID_ILocator2);
        if (*__ILocator2) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::Xml::Sax::ILocator * locator,
        /* [out] */ Org::Xml::Sax::Ext::ILocator2Impl** __ILocator2Impl)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(locator, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ILocator2Impl = (Org::Xml::Sax::Ext::ILocator2Impl*)__pNewObj->Probe(Org::Xml::Sax::Ext::EIID_ILocator2Impl);
        if (*__ILocator2Impl) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::Xml::Sax::ILocator * locator,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(locator, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::Xml::Sax::ILocator * locator,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(locator, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::Xml::Sax::ILocator * locator,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(locator, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

};
}
}
}
}
namespace Org {
namespace Xml {
namespace Sax {
namespace Ext {
class CAttributes2Impl
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Org::Xml::Sax::IAttributes * atts,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICAttributes2ImplClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CAttributes2Impl, RGM_SAME_DOMAIN,
                EIID_ICAttributes2ImplClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithAtts(atts, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [out] */ Org::Xml::Sax::IAttributes** __object)
    {
        return _CObject_CreateInstance(ECLSID_CAttributes2Impl, RGM_SAME_DOMAIN, Org::Xml::Sax::EIID_IAttributes, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Org::Xml::Sax::Ext::IAttributes2** __object)
    {
        return _CObject_CreateInstance(ECLSID_CAttributes2Impl, RGM_SAME_DOMAIN, Org::Xml::Sax::Ext::EIID_IAttributes2, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Org::Xml::Sax::Ext::IAttributes2Impl** __object)
    {
        return _CObject_CreateInstance(ECLSID_CAttributes2Impl, RGM_SAME_DOMAIN, Org::Xml::Sax::Ext::EIID_IAttributes2Impl, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CAttributes2Impl, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CAttributes2Impl, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CAttributes2Impl, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::Xml::Sax::IAttributes * atts,
        /* [out] */ Org::Xml::Sax::IAttributes** __IAttributes)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(atts, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IAttributes = (Org::Xml::Sax::IAttributes*)__pNewObj->Probe(Org::Xml::Sax::EIID_IAttributes);
        if (*__IAttributes) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::Xml::Sax::IAttributes * atts,
        /* [out] */ Org::Xml::Sax::Ext::IAttributes2** __IAttributes2)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(atts, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IAttributes2 = (Org::Xml::Sax::Ext::IAttributes2*)__pNewObj->Probe(Org::Xml::Sax::Ext::EIID_IAttributes2);
        if (*__IAttributes2) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::Xml::Sax::IAttributes * atts,
        /* [out] */ Org::Xml::Sax::Ext::IAttributes2Impl** __IAttributes2Impl)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(atts, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IAttributes2Impl = (Org::Xml::Sax::Ext::IAttributes2Impl*)__pNewObj->Probe(Org::Xml::Sax::Ext::EIID_IAttributes2Impl);
        if (*__IAttributes2Impl) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::Xml::Sax::IAttributes * atts,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(atts, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::Xml::Sax::IAttributes * atts,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(atts, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::Xml::Sax::IAttributes * atts,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(atts, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

};
}
}
}
}
namespace Org {
namespace Xml {
namespace Sax {
namespace Ext {
class CDefaultHandler2
{
public:
    static _ELASTOS ECode New(
        /* [out] */ Org::Xml::Sax::IDTDHandler** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDefaultHandler2, RGM_SAME_DOMAIN, Org::Xml::Sax::EIID_IDTDHandler, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Org::Xml::Sax::IContentHandler** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDefaultHandler2, RGM_SAME_DOMAIN, Org::Xml::Sax::EIID_IContentHandler, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Org::Xml::Sax::IErrorHandler** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDefaultHandler2, RGM_SAME_DOMAIN, Org::Xml::Sax::EIID_IErrorHandler, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Org::Xml::Sax::Ext::ILexicalHandler** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDefaultHandler2, RGM_SAME_DOMAIN, Org::Xml::Sax::Ext::EIID_ILexicalHandler, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Org::Xml::Sax::Ext::IDeclHandler** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDefaultHandler2, RGM_SAME_DOMAIN, Org::Xml::Sax::Ext::EIID_IDeclHandler, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Org::Xml::Sax::IEntityResolver** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDefaultHandler2, RGM_SAME_DOMAIN, Org::Xml::Sax::EIID_IEntityResolver, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Org::Xml::Sax::Ext::IEntityResolver2** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDefaultHandler2, RGM_SAME_DOMAIN, Org::Xml::Sax::Ext::EIID_IEntityResolver2, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDefaultHandler2, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDefaultHandler2, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDefaultHandler2, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
}
}
namespace Org {
namespace Xmlpull {
namespace V1 {
class CXmlPullParserFactory
{
public:
    static _ELASTOS ECode New(
        /* [out] */ Org::Xmlpull::V1::IXmlPullParserFactory** __object)
    {
        return _CObject_CreateInstance(ECLSID_CXmlPullParserFactory, RGM_SAME_DOMAIN, Org::Xmlpull::V1::EIID_IXmlPullParserFactory, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CXmlPullParserFactory, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CXmlPullParserFactory, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CXmlPullParserFactory, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
}
namespace Org {
namespace Xmlpull {
namespace V1 {
class CXmlPullParserFactoryHelper
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Org::Xmlpull::V1::IXmlPullParserFactoryHelper** __object)
    {
        return _CObject_CreateInstance(ECLSID_CXmlPullParserFactoryHelper, RGM_SAME_DOMAIN, Org::Xmlpull::V1::EIID_IXmlPullParserFactoryHelper, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CXmlPullParserFactoryHelper, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CXmlPullParserFactoryHelper, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CXmlPullParserFactoryHelper, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
}
namespace Org {
namespace Xmlpull {
namespace V1 {
namespace Sax2 {
class CDriver
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Org::Xmlpull::V1::IXmlPullParser * pp,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICDriverClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CDriver, RGM_SAME_DOMAIN,
                EIID_ICDriverClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithPp(pp, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [out] */ Org::Xml::Sax::ILocator** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDriver, RGM_SAME_DOMAIN, Org::Xml::Sax::EIID_ILocator, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Org::Xml::Sax::IXMLReader** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDriver, RGM_SAME_DOMAIN, Org::Xml::Sax::EIID_IXMLReader, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Org::Xml::Sax::IAttributes** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDriver, RGM_SAME_DOMAIN, Org::Xml::Sax::EIID_IAttributes, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDriver, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDriver, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CDriver, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::Xmlpull::V1::IXmlPullParser * pp,
        /* [out] */ Org::Xml::Sax::ILocator** __ILocator)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pp, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ILocator = (Org::Xml::Sax::ILocator*)__pNewObj->Probe(Org::Xml::Sax::EIID_ILocator);
        if (*__ILocator) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::Xmlpull::V1::IXmlPullParser * pp,
        /* [out] */ Org::Xml::Sax::IXMLReader** __IXMLReader)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pp, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IXMLReader = (Org::Xml::Sax::IXMLReader*)__pNewObj->Probe(Org::Xml::Sax::EIID_IXMLReader);
        if (*__IXMLReader) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::Xmlpull::V1::IXmlPullParser * pp,
        /* [out] */ Org::Xml::Sax::IAttributes** __IAttributes)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pp, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IAttributes = (Org::Xml::Sax::IAttributes*)__pNewObj->Probe(Org::Xml::Sax::EIID_IAttributes);
        if (*__IAttributes) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::Xmlpull::V1::IXmlPullParser * pp,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pp, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::Xmlpull::V1::IXmlPullParser * pp,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pp, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::Xmlpull::V1::IXmlPullParser * pp,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(pp, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

};
}
}
}
}
namespace Org {
namespace Kxml2 {
namespace IO {
class CKXmlParser
{
public:
    static _ELASTOS ECode New(
        /* [out] */ Org::Kxml2::IO::IKXmlParser** __object)
    {
        return _CObject_CreateInstance(ECLSID_CKXmlParser, RGM_SAME_DOMAIN, Org::Kxml2::IO::EIID_IKXmlParser, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Org::Xmlpull::V1::IXmlPullParser** __object)
    {
        return _CObject_CreateInstance(ECLSID_CKXmlParser, RGM_SAME_DOMAIN, Org::Xmlpull::V1::EIID_IXmlPullParser, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::IO::ICloseable** __object)
    {
        return _CObject_CreateInstance(ECLSID_CKXmlParser, RGM_SAME_DOMAIN, Elastos::IO::EIID_ICloseable, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CKXmlParser, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CKXmlParser, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CKXmlParser, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
}
namespace Org {
namespace Kxml2 {
namespace IO {
class CKXmlSerializer
{
public:
    static _ELASTOS ECode New(
        /* [out] */ Org::Xmlpull::V1::IXmlSerializer** __object)
    {
        return _CObject_CreateInstance(ECLSID_CKXmlSerializer, RGM_SAME_DOMAIN, Org::Xmlpull::V1::EIID_IXmlSerializer, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CKXmlSerializer, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CKXmlSerializer, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CKXmlSerializer, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
}
namespace Org {
namespace Json {
class CJSONArray
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Utility::ICollection * copyFrom,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICJSONArrayClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CJSONArray, RGM_SAME_DOMAIN,
                EIID_ICJSONArrayClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithCopyFrom(copyFrom, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Org::Json::IJSONTokener * readFrom,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICJSONArrayClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CJSONArray, RGM_SAME_DOMAIN,
                EIID_ICJSONArrayClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithReadFrom(readFrom, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& json,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICJSONArrayClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CJSONArray, RGM_SAME_DOMAIN,
                EIID_ICJSONArrayClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithJson(json, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ IInterface * array,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICJSONArrayClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CJSONArray, RGM_SAME_DOMAIN,
                EIID_ICJSONArrayClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithArray(array, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [out] */ Org::Json::IJSONArray** __object)
    {
        return _CObject_CreateInstance(ECLSID_CJSONArray, RGM_SAME_DOMAIN, Org::Json::EIID_IJSONArray, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CJSONArray, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CJSONArray, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CJSONArray, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * copyFrom,
        /* [out] */ Org::Json::IJSONArray** __IJSONArray)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(copyFrom, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IJSONArray = (Org::Json::IJSONArray*)__pNewObj->Probe(Org::Json::EIID_IJSONArray);
        if (*__IJSONArray) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * copyFrom,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(copyFrom, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * copyFrom,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(copyFrom, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::ICollection * copyFrom,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(copyFrom, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::Json::IJSONTokener * readFrom,
        /* [out] */ Org::Json::IJSONArray** __IJSONArray)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(readFrom, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IJSONArray = (Org::Json::IJSONArray*)__pNewObj->Probe(Org::Json::EIID_IJSONArray);
        if (*__IJSONArray) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::Json::IJSONTokener * readFrom,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(readFrom, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::Json::IJSONTokener * readFrom,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(readFrom, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::Json::IJSONTokener * readFrom,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(readFrom, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& json,
        /* [out] */ Org::Json::IJSONArray** __IJSONArray)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(json, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IJSONArray = (Org::Json::IJSONArray*)__pNewObj->Probe(Org::Json::EIID_IJSONArray);
        if (*__IJSONArray) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& json,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(json, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& json,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(json, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& json,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(json, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ IInterface * array,
        /* [out] */ Org::Json::IJSONArray** __IJSONArray)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(array, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IJSONArray = (Org::Json::IJSONArray*)__pNewObj->Probe(Org::Json::EIID_IJSONArray);
        if (*__IJSONArray) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ IInterface * array,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(array, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ IInterface * array,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(array, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ IInterface * array,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(array, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

};
}
}
namespace Org {
namespace Json {
class CJSONObject
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ Elastos::Utility::IMap * copyFrom,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICJSONObjectClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CJSONObject, RGM_SAME_DOMAIN,
                EIID_ICJSONObjectClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithCopyFrom(copyFrom, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Org::Json::IJSONTokener * readFrom,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICJSONObjectClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CJSONObject, RGM_SAME_DOMAIN,
                EIID_ICJSONObjectClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithReadFrom(readFrom, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& json,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICJSONObjectClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CJSONObject, RGM_SAME_DOMAIN,
                EIID_ICJSONObjectClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithJson(json, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode _New(
        /* [in] */ Org::Json::IJSONObject * copyFrom,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS String> * names,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICJSONObjectClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CJSONObject, RGM_SAME_DOMAIN,
                EIID_ICJSONObjectClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithCopyFromNames(copyFrom, names, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [out] */ Org::Json::IJSONObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CJSONObject, RGM_SAME_DOMAIN, Org::Json::EIID_IJSONObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CJSONObject, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CJSONObject, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CJSONObject, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IMap * copyFrom,
        /* [out] */ Org::Json::IJSONObject** __IJSONObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(copyFrom, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IJSONObject = (Org::Json::IJSONObject*)__pNewObj->Probe(Org::Json::EIID_IJSONObject);
        if (*__IJSONObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IMap * copyFrom,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(copyFrom, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IMap * copyFrom,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(copyFrom, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Elastos::Utility::IMap * copyFrom,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(copyFrom, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::Json::IJSONTokener * readFrom,
        /* [out] */ Org::Json::IJSONObject** __IJSONObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(readFrom, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IJSONObject = (Org::Json::IJSONObject*)__pNewObj->Probe(Org::Json::EIID_IJSONObject);
        if (*__IJSONObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::Json::IJSONTokener * readFrom,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(readFrom, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::Json::IJSONTokener * readFrom,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(readFrom, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::Json::IJSONTokener * readFrom,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(readFrom, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& json,
        /* [out] */ Org::Json::IJSONObject** __IJSONObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(json, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IJSONObject = (Org::Json::IJSONObject*)__pNewObj->Probe(Org::Json::EIID_IJSONObject);
        if (*__IJSONObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& json,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(json, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& json,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(json, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& json,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(json, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::Json::IJSONObject * copyFrom,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS String> * names,
        /* [out] */ Org::Json::IJSONObject** __IJSONObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(copyFrom, names, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IJSONObject = (Org::Json::IJSONObject*)__pNewObj->Probe(Org::Json::EIID_IJSONObject);
        if (*__IJSONObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::Json::IJSONObject * copyFrom,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS String> * names,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(copyFrom, names, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::Json::IJSONObject * copyFrom,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS String> * names,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(copyFrom, names, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ Org::Json::IJSONObject * copyFrom,
        /* [in] */ _ELASTOS ArrayOf<_ELASTOS String> * names,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(copyFrom, names, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

};
}
}
namespace Org {
namespace Json {
class CJSONObjectHelper
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Org::Json::IJSONObjectHelper** __object)
    {
        return _CObject_CreateInstance(ECLSID_CJSONObjectHelper, RGM_SAME_DOMAIN, Org::Json::EIID_IJSONObjectHelper, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CJSONObjectHelper, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CJSONObjectHelper, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CJSONObjectHelper, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}
namespace Org {
namespace Json {
class CJSONStringer
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ _ELASTOS Int32 indentSpaces,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICJSONStringerClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CJSONStringer, RGM_SAME_DOMAIN,
                EIID_ICJSONStringerClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithIndentSpaces(indentSpaces, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [out] */ Org::Json::IJSONStringer** __object)
    {
        return _CObject_CreateInstance(ECLSID_CJSONStringer, RGM_SAME_DOMAIN, Org::Json::EIID_IJSONStringer, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CJSONStringer, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CJSONStringer, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CJSONStringer, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 indentSpaces,
        /* [out] */ Org::Json::IJSONStringer** __IJSONStringer)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(indentSpaces, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IJSONStringer = (Org::Json::IJSONStringer*)__pNewObj->Probe(Org::Json::EIID_IJSONStringer);
        if (*__IJSONStringer) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 indentSpaces,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(indentSpaces, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 indentSpaces,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(indentSpaces, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ _ELASTOS Int32 indentSpaces,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(indentSpaces, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

};
}
}
namespace Org {
namespace Json {
class CJSONTokener
{
public:
    static _ELASTOS ECode _New(
        /* [in] */ const _ELASTOS String& str,
        /* [out] */ IInterface** __object)
    {
        _ELASTOS ECode ec;
        ICJSONTokenerClassObject* pClassObject;
        PInterface pObject = NULL;

        ec = _CObject_AcquireClassFactory(ECLSID_CJSONTokener, RGM_SAME_DOMAIN,
                EIID_ICJSONTokenerClassObject, (IInterface**)&pClassObject);
        if (FAILED(ec)) return ec;

        ec = pClassObject->CreateObjectWithStr(str, &pObject);

        *__object = pObject;

        pClassObject->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& str,
        /* [out] */ Org::Json::IJSONTokener** __IJSONTokener)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(str, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IJSONTokener = (Org::Json::IJSONTokener*)__pNewObj->Probe(Org::Json::EIID_IJSONTokener);
        if (*__IJSONTokener) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& str,
        /* [out] */ IObject** __IObject)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(str, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IObject = (IObject*)__pNewObj->Probe(EIID_IObject);
        if (*__IObject) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& str,
        /* [out] */ Elastos::Core::ISynchronize** __ISynchronize)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(str, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__ISynchronize = (Elastos::Core::ISynchronize*)__pNewObj->Probe(Elastos::Core::EIID_ISynchronize);
        if (*__ISynchronize) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

    static _ELASTOS ECode New(
        /* [in] */ const _ELASTOS String& str,
        /* [out] */ IWeakReferenceSource** __IWeakReferenceSource)
    {
        IInterface* __pNewObj = NULL;

        _ELASTOS ECode ec = _New(str, &__pNewObj);
        if (FAILED(ec)) return ec;

        *__IWeakReferenceSource = (IWeakReferenceSource*)__pNewObj->Probe(EIID_IWeakReferenceSource);
        if (*__IWeakReferenceSource) __pNewObj->AddRef();
        else ec = E_NO_INTERFACE;
        __pNewObj->Release();

        return ec;
    }

};
}
}
namespace Org {
namespace Json {
class CJSONTokenerHelper
{
public:
    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Org::Json::IJSONTokenerHelper** __object)
    {
        return _CObject_CreateInstance(ECLSID_CJSONTokenerHelper, RGM_SAME_DOMAIN, Org::Json::EIID_IJSONTokenerHelper, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IObject** __object)
    {
        return _CObject_CreateInstance(ECLSID_CJSONTokenerHelper, RGM_SAME_DOMAIN, EIID_IObject, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ Elastos::Core::ISynchronize** __object)
    {
        return _CObject_CreateInstance(ECLSID_CJSONTokenerHelper, RGM_SAME_DOMAIN, Elastos::Core::EIID_ISynchronize, (PInterface*)__object);
    }

    static _ELASTOS ECode AcquireSingleton(
        /* [out] */ IWeakReferenceSource** __object)
    {
        return _CObject_CreateInstance(ECLSID_CJSONTokenerHelper, RGM_SAME_DOMAIN, EIID_IWeakReferenceSource, (PInterface*)__object);
    }

};
}
}

#endif // __Elastos_CoreLibrary_External_h__
