
package org.elastos.Elastos.AutoGenerateJavaCodes;

//this java interface define the elastos interface.
public interface ITestCar {

    public void SetInt(
        /* [in] */ int value);

    public int GetInt();

    public void SetString(
        /* [in] */ String value);

    public String GetString();

    public void Normal();

    public void Test1(
        /* [in] */ int value1,
        /* [in] */ boolean value2,
        /* [in] */ float value3,
        /* [in] */ double value4,
        /* [in] */ long value5,
        /* [in] */ byte value6,
        /* [in] */ char value7,
        /* [in] */ String value8);

    public int Test2(
        /* [in] */ int value1,
        /* [in] */ boolean value2,
        /* [in] */ float value3,
        /* [in] */ double value4,
        /* [in] */ long value5,
        /* [in] */ byte value6,
        /* [in] */ char value7,
        /* [in] */ String value8,
        /* [in] */ String value9,
        /* [in] */ String value10);

}

