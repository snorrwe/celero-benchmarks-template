
```
conan remote add ppodsiadly https://api.bintray.com/conan/ppodsiadly/conan
mkdir build
cd build
conan install ..
```

## If building using visual studio

Use the `-DCONAN_DISABLE_CHECK_COMPILER=1` flag when generating the cmake cache

## Example output

|     Group      |   Experiment    |   Prob. Space   |     Samples     |   Iterations    |    Baseline     |  us/Iteration   | Iterations/sec  |
|:--------------:|:---------------:|:---------------:|:---------------:|:---------------:|:---------------:|:---------------:|:---------------:|
|PictureCreation | RawUninit       |            Null |             200 |             100 |         1.00000 |       152.64000 |         6551.36 |
|PictureCreation | VecUninit       |            Null |             200 |              50 |        14.47432 |      2209.36000 |          452.62 |
|PictureCreation | VecPtrUninit    |            Null |             200 |              50 |        14.48991 |      2211.74000 |          452.13 |
|PictureCreation | InitRaw         |            Null |             200 |              10 |        63.36412 |      9671.90000 |          103.39 |
|PictureCreation | InitVecPic      |            Null |             200 |              10 |        63.31237 |      9664.00000 |          103.48 |
|PictureCreation | InitVecPtr      |            Null |             200 |              10 |        63.43684 |      9683.00000 |          103.27 |
