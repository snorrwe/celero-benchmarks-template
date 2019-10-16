
```
conan remote add ppodsiadly https://api.bintray.com/conan/ppodsiadly/conan
cmake -H. -Bbuild 

cmake --build build
```

## If building using visual studio

Use the `-DCONAN_DISABLE_CHECK_COMPILER=1` flag when generating the cmake cache
