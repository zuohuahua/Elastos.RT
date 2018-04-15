# how to export API document

Take the example of exporting documents in Ubuntu environment.

1. install doxygen

* Ubuntu
```
sudo apt-get update
sudo apt-get install doxygen
```

* Mac
```
brew install doxygen
```

2. Take the API that generates runtime as an example

```
cd /Elastos.RT/DocTools/doxyfile
doxygen elastos_sdk_runtime_car_pdf_doxy
```