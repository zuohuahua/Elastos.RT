# how to export API document

Take the example of exporting documents in Ubuntu environment.

1. install doxygen

```
sudo apt-get update
sudo apt-get install doxygen
```

2. Take the API that generates libcore as an example

```
cd /Elastos.RT/DevDoc/DocTools/doxyfile 
doxygen elastos_sdk_libcore_car_pdf_doxy
```