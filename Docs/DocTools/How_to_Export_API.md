# how to export API document

Take the example of exporting documents in Ubuntu environment.

1. install doxygen

    * Ubuntu
        ``` shell
        sudo apt-get update
        sudo apt-get install doxygen
        ```

    * Mac
        ``` shell
        brew install doxygen
        ```

2. Take the API that generates runtime as an example

    ``` shell
    cd /Elastos.RT/Docs/DocTools/doxyfile
    doxygen elastos_SDK_doxy
    ```