## Install dependencies

- install [Python 3](https://www.python.org/)
- install [CMake](https://cmake.org/)
- install the rest of the dependencies `pip install -r requirements.txt`

## Prepare the cmake cache

- Add the celero repository `conan remote add ppodsiadly https://api.bintray.com/conan/ppodsiadly/conan`
- Init the cmake cache `cmake -H. -Bbuild`


## Build

```
cmake --build build
```

## If building using visual studio

Use the `-DCONAN_DISABLE_CHECK_COMPILER=1` flag when generating the cmake cache

## Using the notebook

- Emit benchmark output `build/../bench.exe -t out.csv`
- `jupyter lab viz.ipynb`

## Reading

- [Celero](https://github.com/DigitalInBlue/Celero), the benchmarking framework used.
